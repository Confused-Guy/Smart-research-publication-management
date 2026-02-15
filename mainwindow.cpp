#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "conference.h"
#include <QSqlQuery>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QTextDocument>
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QCalendarWidget>
#include <QTextCharFormat>
#include <QScrollArea>
#include <QMap>
#include <QPainter>
#include <QMessageBox>
#include <QPrinter>
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QtCore/QUrlQuery>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonArray>
#include <QtCore/QJsonObject>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize({1280,720});
    mode=true;

    QPixmap logo("logo.png");//logo stuff!
    ui->loginLogo->setPixmap(logo);
    ui->pic->setPixmap(logo);
    ui->pic_2->setPixmap(logo);
    ui->pic_3->setPixmap(logo);
    ui->pic_4->setPixmap(logo);
    ui->pic_5->setPixmap(logo);
    ui->pic_6->setPixmap(logo);
    ui->pic_7->setPixmap(logo);//logo stuff!

    ui->stackedWidget->setCurrentIndex(3);

    QPixmap userPic("user.png"); //temporary until user gets an actual db
    ui->userPic->setPixmap(userPic);

    QPixmap chart("pie_chart.png");
    ui->chart->setPixmap(chart);
    QPixmap bar("bar.png");
    ui->bar->setPixmap(bar);
    QPixmap post("gallary.png");
    ui->postPicture->setPixmap(post);
    QPixmap drop("drop.png");
    ui->dropPlace->setPixmap(drop);



}

MainWindow::~MainWindow()
{
    delete ui;
}


//********************CONFERENCE START***********************************************************************************************************//

//1 LOAD
void MainWindow::loadConferences(bool ascending, QString searchFilter)
{
    // Clear
    QLayoutItem* item;
    while ((item = ui->conferenceLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    //Query
    QString queryStr = "SELECT ID, TITLE, CONF_DATE, LOCATION, PRICE FROM CONFERENCE";

    if (!searchFilter.trimmed().isEmpty())
        queryStr += " WHERE UPPER(TITLE) LIKE UPPER(:search)";

    queryStr += ascending ? " ORDER BY PRICE ASC" : " ORDER BY PRICE DESC";

    QSqlQuery query;
    query.prepare(queryStr);

    if (!searchFilter.trimmed().isEmpty())
        query.bindValue(":search", "%" + searchFilter.trimmed() + "%");

    query.exec();

    bool anyResults = false;

    //Display
    while (query.next()) {
        anyResults = true;
        int id = query.value(0).toInt();
        QString title = query.value(1).toString();
        QDate date = query.value(2).toDate();
        QString location = query.value(3).toString();
        double price = query.value(4).toDouble();

        QFrame* card = new QFrame();
        card->setFrameShape(QFrame::StyledPanel);
        card->setMinimumHeight(120);

        QVBoxLayout* cardLayout = new QVBoxLayout(card);
        QLabel* titleLabel = new QLabel("<b>" + title + "</b>");
        QLabel* infoLabel = new QLabel(
            "Date: " + date.toString("dd/MM/yyyy") +
            " | Location: " + location +
            " | Price: " + QString::number(price)
            );

        QHBoxLayout* btnLayout = new QHBoxLayout();
        QPushButton* editBtn   = new QPushButton("Edit");
        QPushButton* deleteBtn = new QPushButton("Delete");
        QPushButton* mapBtn    = new QPushButton("Map");
        QPushButton* pdfBtn    = new QPushButton("Export PDF");

        btnLayout->addWidget(editBtn);
        btnLayout->addWidget(deleteBtn);
        btnLayout->addWidget(mapBtn);
        btnLayout->addWidget(pdfBtn);

        cardLayout->addWidget(titleLabel);
        cardLayout->addWidget(infoLabel);
        cardLayout->addLayout(btnLayout);

        ui->conferenceLayout->addWidget(card);

        // Delete
        connect(deleteBtn, &QPushButton::clicked, this, [=]() {
            QSqlQuery del;
            del.prepare("DELETE FROM CONFERENCE WHERE ID = ?");
            del.addBindValue(id);
            del.exec();
            loadConferences(sortAscending, ui->searchConfEdit->text());
        });

        // Edit
        connect(editBtn, &QPushButton::clicked, this, [=]() {
            QSqlQuery q;
            q.prepare("SELECT TITLE, TOPIC_ID, CONF_DATE, LOCATION, PRICE FROM CONFERENCE WHERE ID=:id");
            q.bindValue(":id", id);
            q.exec();
            if (q.next()) {
                editingConferenceId = id;
                ui->cTitleEdit->setText(q.value(0).toString());
                ui->dateEdit->setDate(q.value(2).toDate());
                ui->locationEdit->setText(q.value(3).toString());
                ui->priceSpin->setValue(q.value(4).toDouble());
                ui->stackedWidget->setCurrentIndex(5);
            }
        });

        //MAP
        connect(mapBtn, &QPushButton::clicked, this, [=]() {
            showConferenceMap(location, title);
        });

        //PDF
        connect(pdfBtn, &QPushButton::clicked, this, [=]() {
            QSqlQuery q;
            q.prepare("SELECT TITLE, CONF_DATE, LOCATION, PRICE FROM CONFERENCE WHERE ID=:id");
            q.bindValue(":id", id);
            q.exec();

            if (q.next()) {
                exportConferencePDF(
                    id,
                    q.value(0).toString(),
                    q.value(1).toDate(),
                    q.value(2).toString(),
                    q.value(3).toDouble());
            }
        });
    }

    // "no results" if search returns nothing
    if (!anyResults) {
        QLabel* noResults = new QLabel("No conferences found.");
        noResults->setAlignment(Qt::AlignCenter);
        ui->conferenceLayout->addWidget(noResults);
    }

    ui->conferenceLayout->addStretch();
}

//2 ADD EDIT
void MainWindow::on_cancelConfBtn_clicked() {
    editingConferenceId = -1;
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_addConferenceBtn_clicked() {
    editingConferenceId = -1;
    ui->cTitleEdit->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->locationEdit->clear();
    ui->priceSpin->setValue(0);
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_saveConfBtn_clicked()
{
    Conference c(
        editingConferenceId,
        ui->cTitleEdit->text(),
        1,
        ui->dateEdit->date(),
        ui->locationEdit->text(),
        ui->priceSpin->value()
        );

    bool success = false;

    if (editingConferenceId == -1)
        success = c.add();
    else
        success = c.update();

    if (success) {
        qDebug() << (editingConferenceId == -1 ? "Conference added" : "Conference updated");
        editingConferenceId = -1;
        loadConferences(sortAscending, "");
        ui->stackedWidget->setCurrentIndex(4);
    } else {
        qDebug() << "Conference failed";
    }
}

//3 STATS
void MainWindow::on_confStatsBtn_clicked()
{
    showConferenceStats();
}

void MainWindow::showConferenceStats()
{
    //clazy-qcolor-from-literal warnings FIX
    const QColor cTeal    (0x30, 0xb9, 0xbf);
    const QColor cIndigo  (0x63, 0x66, 0xf1);
    const QColor cAmber   (0xf5, 0x9e, 0x0b);
    const QColor cRed     (0xdc, 0x26, 0x26);
    const QColor cGreen   (0x16, 0xa3, 0x4a);
    const QColor cPink    (0xec, 0x48, 0x99);
    const QColor cPurple  (0x8b, 0x5c, 0xf6);
    const QColor cWhite   (0xff, 0xff, 0xff);
    const QColor cGray    (0x6b, 0x72, 0x80);
    const QColor cLightBg (0xf1, 0xf5, 0xf9);
    const QColor cText    (0x1f, 0x29, 0x37);
    const QColor cSubText (0x9c, 0xa3, 0xaf);
    const QColor cShadow  (0x00, 0x00, 0x00, 18);

    //Queries
    QSqlQuery query;
    query.exec("SELECT COUNT(*), AVG(PRICE), MIN(PRICE), MAX(PRICE) FROM CONFERENCE");
    int totalConferences = 0;
    double avgPrice = 0, minPrice = 0, maxPrice = 0;
    if (query.next()) {
        totalConferences = query.value(0).toInt();
        avgPrice         = query.value(1).toDouble();
        minPrice         = query.value(2).toDouble();
        maxPrice         = query.value(3).toDouble();
    }

    QSqlQuery upcomingQuery;
    upcomingQuery.exec(
        "SELECT COUNT(*) FROM CONFERENCE WHERE CONF_DATE >= TRUNC(SYSDATE)"
        );
    int upcoming = 0;
    if (upcomingQuery.next())
        upcoming = upcomingQuery.value(0).toInt();
    int past = totalConferences - upcoming;

    QSqlQuery monthQuery;
    monthQuery.exec(
        "SELECT TO_CHAR(CONF_DATE, 'Mon'), COUNT(*) FROM CONFERENCE "
        "WHERE CONF_DATE >= ADD_MONTHS(SYSDATE, -6) "
        "GROUP BY TO_CHAR(CONF_DATE, 'Mon'), TO_CHAR(CONF_DATE, 'MM') "
        "ORDER BY TO_CHAR(CONF_DATE, 'MM')"
        );
    QList<QPair<QString,int>> monthData;
    while (monthQuery.next())
        monthData.append({monthQuery.value(0).toString(),
                          monthQuery.value(1).toInt()});

    QSqlQuery priceQuery;
    priceQuery.exec(
        "SELECT "
        "  SUM(CASE WHEN PRICE < 100  THEN 1 ELSE 0 END), "
        "  SUM(CASE WHEN PRICE >= 100 AND PRICE < 500  THEN 1 ELSE 0 END), "
        "  SUM(CASE WHEN PRICE >= 500 AND PRICE < 1000 THEN 1 ELSE 0 END), "
        "  SUM(CASE WHEN PRICE >= 1000 THEN 1 ELSE 0 END) "
        "FROM CONFERENCE"
        );
    QList<QPair<QString,int>> priceData;
    if (priceQuery.next()) {
        priceData = {
            {"<$100",     priceQuery.value(0).toInt()},
            {"$100-500",  priceQuery.value(1).toInt()},
            {"$500-1000", priceQuery.value(2).toInt()},
            {">$1000",    priceQuery.value(3).toInt()}
        };
    }

    QSqlQuery locQuery;
    locQuery.exec(
        "SELECT LOCATION, COUNT(*) as cnt FROM CONFERENCE "
        "GROUP BY LOCATION ORDER BY cnt DESC FETCH FIRST 1 ROWS ONLY"
        );
    QString topLocation = "N/A";
    if (locQuery.next())
        topLocation = locQuery.value(0).toString();

    QSqlQuery nextQuery;
    nextQuery.exec(
        "SELECT TITLE, CONF_DATE FROM CONFERENCE "
        "WHERE CONF_DATE >= TRUNC(SYSDATE) ORDER BY CONF_DATE ASC FETCH FIRST 1 ROWS ONLY"
        );
    QString nextTitle = "None";
    QString nextDate  = "";
    if (nextQuery.next()) {
        nextTitle = nextQuery.value(0).toString();
        nextDate  = nextQuery.value(1).toDate().toString("MMM dd, yyyy");
    }

    //Dialog
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("Conference Statistics");
    dialog->setFixedSize(600, 640);
    dialog->setAttribute(Qt::WA_StyledBackground, true);

    //Scroll area
    QWidget* scrollContent = new QWidget();
    scrollContent->setAttribute(Qt::WA_StyledBackground, true);
    scrollContent->setStyleSheet("QWidget { background-color: #f6f8fc; border: none; }");

    QVBoxLayout* mainLayout = new QVBoxLayout(scrollContent);
    mainLayout->setContentsMargins(24, 20, 24, 16);
    mainLayout->setSpacing(14);

    QScrollArea* scroll = new QScrollArea(dialog);
    scroll->setWidget(scrollContent);
    scroll->setWidgetResizable(true);
    scroll->setFrameShape(QFrame::NoFrame);
    scroll->setStyleSheet(
        "QScrollArea { background-color: #f6f8fc; border: none; }"
        "QScrollBar:vertical { background: #f6f8fc; width: 6px; border-radius: 3px; }"
        "QScrollBar::handle:vertical { background: #c0d0e8; border-radius: 3px; }"
        "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height: 0px; }"
        );

    QVBoxLayout* dialogLayout = new QVBoxLayout(dialog);
    dialogLayout->setContentsMargins(0, 0, 0, 0);
    dialogLayout->setSpacing(0);
    dialogLayout->addWidget(scroll);

    //Header
    QLabel* titleLabel = new QLabel("Conference Statistics");
    titleLabel->setStyleSheet(
        "font-size: 16px; font-weight: bold; color: #1f2937; background: transparent;"
        );
    QLabel* subLabel = new QLabel(
        QString::number(totalConferences) + " total  ·  " +
        QString::number(upcoming) + " upcoming  ·  " +
        QString::number(past) + " past  ·  Top location: " + topLocation
        );
    subLabel->setStyleSheet("font-size: 10px; color: #9ca3af; background: transparent;");
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(subLabel);

    QFrame* div = new QFrame();
    div->setFrameShape(QFrame::HLine);
    div->setFixedHeight(1);
    div->setStyleSheet("background-color: #e2e8f0; border: none;");
    mainLayout->addWidget(div);

    //section label
    auto makeSection = [&](const QString& text) -> QLabel* {
        QLabel* sec = new QLabel(text.toUpper());
        sec->setStyleSheet(
            "font-size: 9px; font-weight: bold; color: #9ca3af;"
            "background: transparent; letter-spacing: 1px; border: none;"
            );
        return sec;
    };

    //bar chart
    auto makeBarChart = [&](const QList<QPair<QString,int>>& data,
                            const QColor& barColor,
                            int fixedHeight) -> QWidget*
    {
        QWidget* chart = new QWidget();
        chart->setFixedHeight(fixedHeight);
        chart->setAttribute(Qt::WA_StyledBackground, true);
        chart->setStyleSheet(
            "QWidget { background-color: #ffffff;"
            "border: 1px solid #e2e8f0; border-radius: 10px; }"
            );

        QLabel* canvas = new QLabel(chart);
        canvas->setGeometry(0, 0, 552, fixedHeight);
        canvas->setAttribute(Qt::WA_StyledBackground, false);
        canvas->setStyleSheet("background: transparent; border: none;");

        int maxVal = 1;
        for (const auto& d : data)
            if (d.second > maxVal) maxVal = d.second;

        QPixmap pixmap(552, fixedHeight);
        pixmap.fill(Qt::transparent);
        QPainter painter(&pixmap);
        painter.setRenderHint(QPainter::Antialiasing);

        int n        = data.size();
        int padLeft  = 72;
        int padRight = 20;
        int padTop   = 16;
        int padBot   = 16;
        int barAreaW = pixmap.width() - padLeft - padRight;
        int totalH   = pixmap.height() - padTop - padBot;
        int barH     = qMax(18, (totalH / qMax(n,1)) - 10);
        int gap      = qMax(6, (totalH - barH * n) / (n + 1));

        for (int i = 0; i < n; ++i) {
            int y    = padTop + gap + i * (barH + gap);
            int barW = data[i].second == 0 ? 0
                                           : (int)((double)data[i].second / maxVal * barAreaW);

            painter.setPen(cGray);
            painter.setFont(QFont("Arial", 9));
            painter.drawText(QRect(0, y, padLeft - 8, barH),
                             Qt::AlignRight | Qt::AlignVCenter,
                             data[i].first);

            painter.setPen(Qt::NoPen);
            painter.setBrush(cLightBg);
            painter.drawRoundedRect(padLeft, y, barAreaW, barH, 5, 5);

            if (barW > 0) {
                painter.setBrush(barColor);
                painter.drawRoundedRect(padLeft, y, barW, barH, 5, 5);
            }

            painter.setPen(barW > 30 ? cWhite : cText);
            painter.setFont(QFont("Arial", 9, QFont::Bold));
            painter.drawText(QRect(padLeft + 6, y, qMax(barW - 4, 40), barH),
                             Qt::AlignLeft | Qt::AlignVCenter,
                             QString::number(data[i].second));
        }

        painter.end();
        canvas->setPixmap(pixmap);
        return chart;
    };

    //donut pie chart
    auto makePieChart = [&](const QList<QPair<QString,int>>& data,
                            int size) -> QWidget*
    {
        QWidget* container = new QWidget();
        container->setFixedHeight(size + 20);
        container->setAttribute(Qt::WA_StyledBackground, true);
        container->setStyleSheet(
            "QWidget { background-color: #ffffff;"
            "border: 1px solid #e2e8f0; border-radius: 10px; }"
            );

        QLabel* canvas = new QLabel(container);
        canvas->setGeometry(0, 0, 552, size + 20);
        canvas->setAttribute(Qt::WA_StyledBackground, false);
        canvas->setStyleSheet("background: transparent; border: none;");

        const QList<QColor> colors = {
            cTeal, cIndigo, cAmber, cRed, cGreen, cPink, cPurple
        };

        int total = 0;
        for (const auto& d : data) total += d.second;

        QPixmap pixmap(552, size + 20);
        pixmap.fill(Qt::transparent);
        QPainter painter(&pixmap);
        painter.setRenderHint(QPainter::Antialiasing);

        if (total == 0) {
            painter.setPen(cSubText);
            painter.setFont(QFont("Arial", 10));
            painter.drawText(pixmap.rect(), Qt::AlignCenter, "No data available");
            painter.end();
            canvas->setPixmap(pixmap);
            return container;
        }

        int pieSize = size - 20;
        int pieX    = 20;
        int pieY    = 20;
        QRect pieRect(pieX, pieY, pieSize, pieSize);

        //Shadow
        painter.setPen(Qt::NoPen);
        painter.setBrush(cShadow);
        painter.drawEllipse(pieRect.adjusted(4, 4, 4, 4));

        //Slices
        double startAngle = 90.0;
        for (int i = 0; i < data.size(); ++i) {
            if (data[i].second == 0) continue;
            double sweepAngle = (double)data[i].second / total * 360.0;

            painter.setPen(Qt::NoPen);
            painter.setBrush(colors[i % colors.size()]);
            painter.drawPie(pieRect,
                            (int)(startAngle * 16),
                            (int)(sweepAngle * 16));

            painter.setPen(QPen(cWhite, 2));
            painter.setBrush(Qt::NoBrush);
            painter.drawPie(pieRect,
                            (int)(startAngle * 16),
                            (int)(sweepAngle * 16));

            startAngle += sweepAngle;
        }

        //Center hole
        int holeSize = pieSize / 2;
        int holeX    = pieX + (pieSize - holeSize) / 2;
        int holeY    = pieY + (pieSize - holeSize) / 2;
        painter.setPen(Qt::NoPen);
        painter.setBrush(cWhite);
        painter.drawEllipse(holeX, holeY, holeSize, holeSize);

        //Center text
        painter.setPen(cText);
        painter.setFont(QFont("Arial", 13, QFont::Bold));
        painter.drawText(QRect(holeX, holeY, holeSize, holeSize / 2 + 4),
                         Qt::AlignCenter, QString::number(total));
        painter.setPen(cSubText);
        painter.setFont(QFont("Arial", 8));
        painter.drawText(QRect(holeX, holeY + holeSize / 2 - 4, holeSize, holeSize / 2),
                         Qt::AlignCenter, "total");

        //Legend
        int legendX     = pieX + pieSize + 24;
        int legendY     = pieY + 10;
        int legendItemH = (pieSize - 10) / qMax(data.size(), 1);

        for (int i = 0; i < data.size(); ++i) {
            if (data[i].second == 0) continue;
            int ly = legendY + i * legendItemH;

            painter.setPen(Qt::NoPen);
            painter.setBrush(colors[i % colors.size()]);
            painter.drawEllipse(legendX, ly + 4, 11, 11);

            painter.setPen(cGray);
            painter.setFont(QFont("Arial", 9));
            painter.drawText(legendX + 18, ly, 180, 20,
                             Qt::AlignLeft | Qt::AlignVCenter,
                             data[i].first);

            double pct = (double)data[i].second / total * 100.0;
            painter.setPen(cText);
            painter.setFont(QFont("Arial", 9, QFont::Bold));
            painter.drawText(legendX + 18, ly + 16, 180, 18,
                             Qt::AlignLeft | Qt::AlignVCenter,
                             QString::number(data[i].second) +
                                 "  (" + QString::number(pct, 'f', 1) + "%)");
        }

        painter.end();
        canvas->setPixmap(pixmap);
        return container;
    };

    //Stat pills
    auto makePill = [&](const QString& label,
                        const QString& value,
                        const QString& color) -> QFrame*
    {
        QFrame* pill = new QFrame();
        pill->setAttribute(Qt::WA_StyledBackground, true);
        pill->setStyleSheet(
            "QFrame { background-color: #ffffff;"
            "border: 1px solid #e2e8f0; border-radius: 10px; }"
            );
        pill->setFixedHeight(64);

        QVBoxLayout* pl = new QVBoxLayout(pill);
        pl->setContentsMargins(14, 8, 14, 8);
        pl->setSpacing(2);

        QLabel* vl = new QLabel(value);
        vl->setStyleSheet(
            "font-size: 15px; font-weight: bold; color: " + color + ";"
                                                                    "background: transparent; border: none;"
            );
        QLabel* ll = new QLabel(label);
        ll->setStyleSheet(
            "font-size: 9px; color: #9ca3af;"
            "background: transparent; border: none;"
            );
        pl->addWidget(vl);
        pl->addWidget(ll);
        return pill;
    };

    //LAYOUT
    mainLayout->addWidget(makeSection("Overview"));
    mainLayout->addWidget(makeBarChart(
        {{"Upcoming", upcoming}, {"Past", past}},
        cTeal, 90
        ));

    mainLayout->addWidget(makeSection("Upcoming vs Past"));
    mainLayout->addWidget(makePieChart(
        {{"Upcoming", upcoming}, {"Past", past}},
        180
        ));

    if (!monthData.isEmpty()) {
        mainLayout->addWidget(makeSection("Activity — Last 6 Months"));
        mainLayout->addWidget(makeBarChart(
            monthData, cIndigo,
            qMax(90, monthData.size() * 36 + 32)
            ));
    }

    mainLayout->addWidget(makeSection("Price Distribution"));
    mainLayout->addWidget(makeBarChart(priceData, cAmber, 150));

    mainLayout->addWidget(makeSection("Price Breakdown"));
    mainLayout->addWidget(makePieChart(priceData, 200));

    mainLayout->addWidget(makeSection("Pricing Summary"));
    QHBoxLayout* pillRow = new QHBoxLayout();
    pillRow->setSpacing(10);
    pillRow->addWidget(makePill("Avg Price", "$" + QString::number(avgPrice,'f',0), "#30b9bf"));
    pillRow->addWidget(makePill("Min Price", "$" + QString::number(minPrice,'f',0), "#16a34a"));
    pillRow->addWidget(makePill("Max Price", "$" + QString::number(maxPrice,'f',0), "#dc2626"));
    pillRow->addWidget(makePill("Total",     QString::number(totalConferences),     "#6366f1"));
    mainLayout->addLayout(pillRow);

    if (!nextTitle.isEmpty() && nextTitle != "None") {
        mainLayout->addWidget(makeSection("Next Upcoming"));
        QFrame* nextCard = new QFrame();
        nextCard->setAttribute(Qt::WA_StyledBackground, true);
        nextCard->setFixedHeight(56);
        nextCard->setStyleSheet(
            "QFrame { background-color: #ffffff;"
            "border: 1px solid #e2e8f0; border-radius: 10px; }"
            );
        QHBoxLayout* nl = new QHBoxLayout(nextCard);
        nl->setContentsMargins(16, 0, 16, 0);
        QLabel* nt = new QLabel("📌  " + nextTitle);
        nt->setStyleSheet(
            "font-size: 10pt; font-weight: bold; color: #1f2937;"
            "background: transparent; border: none;"
            );
        QLabel* nd = new QLabel(nextDate);
        nd->setStyleSheet(
            "font-size: 10pt; color: #16a34a;"
            "background: transparent; border: none;"
            );
        nd->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        nl->addWidget(nt);
        nl->addStretch();
        nl->addWidget(nd);
        mainLayout->addWidget(nextCard);
    }

    mainLayout->addStretch();

    //Close
    QPushButton* closeBtn = new QPushButton("Close");
    closeBtn->setFixedWidth(100);
    closeBtn->setFixedHeight(36);
    closeBtn->setStyleSheet(
        "QPushButton {"
        "    background-color: #ffffff; color: #1f2937;"
        "    border: 1px solid #e2e8f0; border-radius: 8px;"
        "    font-size: 10pt; padding: 6px 20px;"
        "}"
        "QPushButton:hover   { background-color: #f1f5f9; }"
        "QPushButton:pressed { background-color: #e2e8f0; }"
        );
    connect(closeBtn, &QPushButton::clicked, dialog, &QDialog::close,
            Qt::QueuedConnection);

    QHBoxLayout* footer = new QHBoxLayout();
    footer->setContentsMargins(16, 8, 16, 8);
    footer->addStretch();
    footer->addWidget(closeBtn);
    dialogLayout->addLayout(footer);

    dialog->exec();
}

//4 CALENDAR
void MainWindow::on_viewCalendarBtn_clicked()
{
    showConferenceCalendar();
}

void MainWindow::showConferenceCalendar()
{
    //Pre-declared colors (Warning fix)
    const QColor cTeal    (0x30, 0xb9, 0xbf);
    const QColor cAmber   (0xfe, 0xf3, 0xc7);
    const QColor cAmberTx (0x92, 0x40, 0x0e);
    const QColor cDarkTeal(0x0a, 0x5a, 0x5f);
    const QColor cWhite   (0xff, 0xff, 0xff);

    //Dtae query
    QMap<QDate, QStringList> conferenceDates;
    QSqlQuery query("SELECT TITLE, CONF_DATE FROM CONFERENCE ORDER BY CONF_DATE");
    while (query.next())
        conferenceDates[query.value(1).toDate()].append(query.value(0).toString());

    //Dialog
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("Conference Calendar");
    dialog->setFixedSize(520, 520);
    dialog->setAttribute(Qt::WA_StyledBackground, true);

    //Scroll
    QWidget* scrollContent = new QWidget();
    scrollContent->setAttribute(Qt::WA_StyledBackground, true);
    scrollContent->setStyleSheet("QWidget { background-color: #f6f8fc; border: none; }");

    QVBoxLayout* mainLayout = new QVBoxLayout(scrollContent);
    mainLayout->setContentsMargins(24, 20, 24, 16);
    mainLayout->setSpacing(14);

    QScrollArea* scroll = new QScrollArea(dialog);
    scroll->setWidget(scrollContent);
    scroll->setWidgetResizable(true);
    scroll->setFrameShape(QFrame::NoFrame);
    scroll->setStyleSheet(
        "QScrollArea { background-color: #f6f8fc; border: none; }"
        "QScrollBar:vertical { background: #f6f8fc; width: 6px; border-radius: 3px; }"
        "QScrollBar::handle:vertical { background: #c0d0e8; border-radius: 3px; }"
        "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height: 0px; }"
        );

    QVBoxLayout* dialogLayout = new QVBoxLayout(dialog);
    dialogLayout->setContentsMargins(0, 0, 0, 0);
    dialogLayout->setSpacing(0);
    dialogLayout->addWidget(scroll);

    //Header
    QLabel* titleLabel = new QLabel("Conference Calendar");
    titleLabel->setStyleSheet(
        "font-size: 16px; font-weight: bold; color: #1f2937; background: transparent;"
        );
    QLabel* subLabel = new QLabel(
        QString::number(conferenceDates.size()) + " scheduled conference(s)"
        );
    subLabel->setStyleSheet("font-size: 10px; color: #9ca3af; background: transparent;");
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(subLabel);

    QFrame* div = new QFrame();
    div->setFrameShape(QFrame::HLine);
    div->setFixedHeight(1);
    div->setStyleSheet("background-color: #e2e8f0; border: none;");
    mainLayout->addWidget(div);

    auto makeSection = [&](const QString& text) -> QLabel* {
        QLabel* sec = new QLabel(text.toUpper());
        sec->setStyleSheet(
            "font-size: 9px; font-weight: bold; color: #9ca3af;"
            "background: transparent; letter-spacing: 1px; border: none;"
            );
        return sec;
    };

    //Calendar style
    QFrame* calCard = new QFrame();
    calCard->setAttribute(Qt::WA_StyledBackground, true);
    calCard->setStyleSheet(
        "QFrame { background-color: #ffffff;"
        "border: 1px solid #e2e8f0; border-radius: 10px; }"
        );
    QVBoxLayout* calCardLayout = new QVBoxLayout(calCard);
    calCardLayout->setContentsMargins(8, 8, 8, 8);

    QCalendarWidget* calendar = new QCalendarWidget();
    calendar->setGridVisible(false);
    calendar->setNavigationBarVisible(true);
    calendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    calendar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    calendar->setStyleSheet(R"(
        QCalendarWidget QWidget {
            background-color: #ffffff;
            color: #1f2937;
        }
        QCalendarWidget QWidget#qt_calendar_navigationbar {
            background-color: #f6f8fc;
            border-bottom: 1px solid #e2e8f0;
            padding: 4px 8px;
            border-radius: 8px 8px 0 0;
        }
        QCalendarWidget QToolButton {
            color: #1f2937;
            background: transparent;
            border: none;
            border-radius: 6px;
            padding: 4px 8px;
            font-weight: bold;
            font-size: 11pt;
        }
        QCalendarWidget QToolButton:hover {
            color: #30b9bf;
            background-color: transparent;
        }
        QCalendarWidget QMenu {
            background-color: #ffffff;
            border: 1px solid #e2e8f0;
            color: #1f2937;
        }
        QCalendarWidget QSpinBox {
            color: #1f2937;
            background-color: #ffffff;
            border: 1px solid #e2e8f0;
            border-radius: 4px;
            padding: 2px 4px;
            font-weight: bold;
        }
        QCalendarWidget QSpinBox::up-button,
        QCalendarWidget QSpinBox::down-button {
            background-color: #f1f5f9;
            border: none;
        }
        QCalendarWidget QAbstractItemView {
            background-color: #ffffff;
            color: #1f2937;
            selection-background-color: #30b9bf;
            selection-color: #ffffff;
            outline: none;
            font-size: 10pt;
        }
        QCalendarWidget QAbstractItemView:disabled {
            color: #d1d5db;
        }
    )");

    //Highlight conference dates
    QTextCharFormat conferenceFormat;
    conferenceFormat.setBackground(cTeal);
    conferenceFormat.setForeground(cWhite);
    conferenceFormat.setFontWeight(QFont::Bold);

    QTextCharFormat todayFormat;
    todayFormat.setBackground(cAmber);
    todayFormat.setForeground(cAmberTx);
    todayFormat.setFontWeight(QFont::Bold);
    calendar->setDateTextFormat(QDate::currentDate(), todayFormat);

    for (auto it = conferenceDates.begin(); it != conferenceDates.end(); ++it) {
        if (it.key() == QDate::currentDate()) {
            QTextCharFormat bothFormat;
            bothFormat.setBackground(cDarkTeal);
            bothFormat.setForeground(cWhite);
            bothFormat.setFontWeight(QFont::Bold);
            calendar->setDateTextFormat(it.key(), bothFormat);
        } else {
            calendar->setDateTextFormat(it.key(), conferenceFormat);
        }
    }

    calCardLayout->addWidget(calendar);
    mainLayout->addWidget(makeSection("Calendar"));
    mainLayout->addWidget(calCard);

    mainLayout->addWidget(makeSection("Selected Date"));

    QFrame* eventCard = new QFrame();
    eventCard->setAttribute(Qt::WA_StyledBackground, true);
    eventCard->setFixedHeight(44);
    eventCard->setStyleSheet(
        "QFrame { background-color: #ffffff;"
        "border: 1px solid #e2e8f0; border-radius: 8px; }"
        );
    QHBoxLayout* eventLayout = new QHBoxLayout(eventCard);
    eventLayout->setContentsMargins(14, 0, 14, 0);

    QLabel* eventLabel = new QLabel("Click a highlighted date to see conferences.");
    eventLabel->setWordWrap(true);
    eventLabel->setAlignment(Qt::AlignVCenter);
    eventLabel->setStyleSheet(
        "font-size: 10px; color: #9ca3af;"
        "background: transparent; border: none;"
        );
    eventLayout->addWidget(eventLabel);
    mainLayout->addWidget(eventCard);

    mainLayout->addWidget(makeSection("Legend"));

    QFrame* legendCard = new QFrame();
    legendCard->setAttribute(Qt::WA_StyledBackground, true);
    legendCard->setStyleSheet(
        "QFrame { background-color: #ffffff;"
        "border: 1px solid #e2e8f0; border-radius: 8px; }"
        );
    QHBoxLayout* legendLayout = new QHBoxLayout(legendCard);
    legendLayout->setContentsMargins(14, 10, 14, 10);
    legendLayout->setSpacing(20);

    auto makeLegendItem = [&](const QColor& bg, const QColor& fg,
                              const QString& label) -> QWidget*
    {
        QWidget* item = new QWidget();
        item->setAttribute(Qt::WA_StyledBackground, false);
        QHBoxLayout* il = new QHBoxLayout(item);
        il->setContentsMargins(0, 0, 0, 0);
        il->setSpacing(6);

        QLabel* dot = new QLabel();
        dot->setFixedSize(14, 14);
        dot->setStyleSheet(QString(
                               "background-color: rgb(%1,%2,%3);"
                               "border-radius: 7px; border: none;"
                               ).arg(bg.red()).arg(bg.green()).arg(bg.blue()));

        QLabel* lbl = new QLabel(label);
        lbl->setStyleSheet(
            "font-size: 9px; color: #4b5563;"
            "background: transparent; border: none;"
            );
        Q_UNUSED(fg);
        il->addWidget(dot);
        il->addWidget(lbl);
        return item;
    };

    legendLayout->addWidget(makeLegendItem(cTeal,     cWhite,   "Conference"));
    legendLayout->addWidget(makeLegendItem(cAmber,    cAmberTx, "Today"));
    legendLayout->addWidget(makeLegendItem(cDarkTeal, cWhite,   "Conference today"));
    legendLayout->addStretch();
    mainLayout->addWidget(legendCard);

    mainLayout->addStretch();

    //Update event label on date click
    connect(calendar, &QCalendarWidget::clicked, dialog, [=](const QDate& date) {
        if (conferenceDates.contains(date)) {
            eventLabel->setText("📌  " + conferenceDates[date].join("   •   "));
            eventCard->setStyleSheet(
                "QFrame { background-color: #e0f7f7;"
                "border: 1px solid #30b9bf; border-radius: 8px; }"
                );
            eventLabel->setStyleSheet(
                "font-size: 10px; color: #0a5a5f;"
                "background: transparent; border: none;"
                );
        } else {
            eventLabel->setText("No conferences on this day.");
            eventCard->setStyleSheet(
                "QFrame { background-color: #ffffff;"
                "border: 1px solid #e2e8f0; border-radius: 8px; }"
                );
            eventLabel->setStyleSheet(
                "font-size: 10px; color: #9ca3af;"
                "background: transparent; border: none;"
                );
        }
    });

    //Close button
    QPushButton* closeBtn = new QPushButton("Close");
    closeBtn->setFixedWidth(100);
    closeBtn->setFixedHeight(36);
    closeBtn->setStyleSheet(
        "QPushButton {"
        "    background-color: #ffffff; color: #1f2937;"
        "    border: 1px solid #e2e8f0; border-radius: 8px;"
        "    font-size: 10pt; padding: 6px 20px;"
        "}"
        "QPushButton:hover   { background-color: #f1f5f9; }"
        "QPushButton:pressed { background-color: #e2e8f0; }"
        );
    connect(closeBtn, &QPushButton::clicked, dialog, &QDialog::close,
            Qt::QueuedConnection);

    QHBoxLayout* footer = new QHBoxLayout();
    footer->setContentsMargins(16, 8, 16, 8);
    footer->addStretch();
    footer->addWidget(closeBtn);
    dialogLayout->addLayout(footer);

    dialog->exec();
}

//5 MAP
void MainWindow::showConferenceMap(const QString& location, const QString& title)
{
    //Loading
    QDialog* loadingDialog = new QDialog(this);
    loadingDialog->setWindowTitle("Loading Map...");
    loadingDialog->setFixedSize(300, 80);
    loadingDialog->setAttribute(Qt::WA_StyledBackground, true);
    loadingDialog->setStyleSheet("QDialog { background-color: #f6f8fc; }");

    QVBoxLayout* ll = new QVBoxLayout(loadingDialog);
    QLabel* loadingLabel = new QLabel("🌍  Geocoding location...");
    loadingLabel->setAlignment(Qt::AlignCenter);
    loadingLabel->setStyleSheet("font-size: 11px; color: #1f2937; background: transparent;");
    ll->addWidget(loadingLabel);

    //Geocode
    auto* geocoder = new QNetworkAccessManager(this);
    QString encoded = QString::fromUtf8(QUrl::toPercentEncoding(location));
    QNetworkRequest geoReq(
        QUrl("https://nominatim.openstreetmap.org/search?q="
             + encoded + "&format=json&limit=1")
        );
    geoReq.setRawHeader("User-Agent", "PeerlyResearchApp/1.0");
    QNetworkReply* geoReply = geocoder->get(geoReq);

    QObject::connect(geoReply, &QNetworkReply::finished, this, [=]() {
        geoReply->deleteLater();
        geocoder->deleteLater();
        loadingDialog->close();

        double lat = 48.8566, lon = 2.3522;
        bool found = false;

        if (geoReply->error() == QNetworkReply::NoError) {
            QJsonDocument doc = QJsonDocument::fromJson(geoReply->readAll());
            QJsonArray arr = doc.array();
            if (!arr.isEmpty()) {
                QJsonObject obj = arr[0].toObject();
                lat   = obj["lat"].toString().toDouble();
                lon   = obj["lon"].toString().toDouble();
                found = true;
            }
        }

        QString html = QString(R"(
            <!DOCTYPE html>
            <html>
            <head>
                <meta charset="utf-8"/>
                <meta name="viewport" content="width=device-width, initial-scale=1.0">
                <title>%1</title>
                <link rel="stylesheet"
                      href="https://unpkg.com/leaflet@1.9.4/dist/leaflet.css"/>
                <script src="https://unpkg.com/leaflet@1.9.4/dist/leaflet.js"></script>
                <style>
                    * { margin:0; padding:0; box-sizing:border-box; }
                    body { font-family: Arial, sans-serif; background: #f6f8fc; }
                    #topbar {
                        background: #30b9bf;
                        color: white;
                        padding: 12px 20px;
                        font-size: 15px;
                        font-weight: bold;
                        display: flex;
                        align-items: center;
                        justify-content: space-between;
                    }
                    #topbar span {
                        font-size: 11px;
                        opacity: 0.85;
                        font-weight: normal;
                    }
                    #map {
                        height: calc(100vh - 48px);
                        width: 100%;
                    }
                    %3
                </style>
            </head>
            <body>
                <div id="topbar">
                    <div>📍 %1</div>
                    <span>%2</span>
                </div>
                <div id="map"></div>
                <script>
                    var map = L.map('map', {
                        zoomControl: true,
                        scrollWheelZoom: true
                    }).setView([%4, %5], 14);

                    L.tileLayer(
                        'https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png',
                        { maxZoom: 19,
                          attribution: '© <a href="https://openstreetmap.org">OpenStreetMap</a> contributors'
                        }
                    ).addTo(map);

                    var icon = L.divIcon({
                        html: '<div style="'
                            + 'width:22px;height:22px;'
                            + 'background:#30b9bf;'
                            + 'border:3px solid white;'
                            + 'border-radius:50%% 50%% 50%% 0;'
                            + 'transform:rotate(-45deg);'
                            + 'box-shadow:0 2px 8px rgba(0,0,0,0.35);'
                            + '"></div>',
                        iconSize:   [22, 22],
                        iconAnchor: [11, 22],
                        className:  ''
                    });

                    L.marker([%4, %5], { icon: icon })
                     .addTo(map)
                     .bindPopup(
                         '<div style="font-family:Arial;min-width:160px;">'
                         + '<b style="color:#30b9bf;font-size:14px;">%1</b><br>'
                         + '<span style="color:#555;font-size:12px;">📍 %2</span>'
                         + '</div>',
                         { maxWidth: 250 }
                     )
                     .openPopup();
                </script>
            </body>
            </html>
        )")
                           .arg(title.toHtmlEscaped(),
                                location.toHtmlEscaped(),
                                found ? "" : R"(
                 #notfound {
                     position:fixed; top:60px; left:50%;
                     transform:translateX(-50%);
                     background:rgba(220,38,38,0.85);
                     color:white; padding:8px 18px;
                     border-radius:20px; font-size:12px;
                     z-index:9999;
                 }
             )",
                                QString::number(lat, 'f', 6),
                                QString::number(lon, 'f', 6));

        //Write to temp file
        QString tmpPath = QDir::tempPath() + "/peerly_map_"
                          + QString::number(QDateTime::currentMSecsSinceEpoch())
                          + ".html";

        QFile file(tmpPath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            stream << html;
            file.close();
            QDesktopServices::openUrl(QUrl::fromLocalFile(tmpPath));
        }
    });

    loadingDialog->show();
}

//6 PDF
void MainWindow::exportConferencePDF(int id, const QString& title, const QDate& date,
                                     const QString& location, double price)
{
    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Export Conference PDF",
        QDir::homePath() + "/" + title + ".pdf",
        "PDF Files (*.pdf)"
        );

    if (filePath.isEmpty())
        return;

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setPageLayout(QPageLayout(
        QPageSize(QPageSize::A4),
        QPageLayout::Portrait,
        QMarginsF(15, 15, 15, 15),
        QPageLayout::Millimeter
        ));

    QString generatedDate = QDate::currentDate().toString("MMMM dd, yyyy");
    QString confDate      = date.toString("MMMM dd, yyyy");
    QString priceStr      = QString::number(price, 'f', 2);

    QString html = QString(R"(
        <html>
        <head>
            <style>
                body {
                    font-family: Arial, sans-serif;
                    color: #1a1a2e;
                    margin: 0;
                    padding: 0;
                    font-size: 48px;
                }
                .header {
                    background-color: #30b9bf;
                    color: white;
                    padding: 60px 80px;
                }
                .header h1 {
                    margin: 0 0 16px 0;
                    font-size: 72px;
                    font-weight: bold;
                }
                .header p {
                    margin: 0;
                    font-size: 40px;
                    opacity: 0.9;
                }
                .section {
                    padding: 60px 80px;
                }
                .section h2 {
                    color: #30b9bf;
                    font-size: 44px;
                    text-transform: uppercase;
                    letter-spacing: 4px;
                    border-bottom: 4px solid #30b9bf;
                    padding-bottom: 16px;
                    margin-bottom: 40px;
                }
                .info-grid {
                    width: 100%;
                    border-collapse: collapse;
                    margin-bottom: 40px;
                }
                .info-grid td {
                    padding: 28px 32px;
                    font-size: 44px;
                    vertical-align: top;
                }
                .info-grid tr:nth-child(odd) td {
                    background-color: #f0f9fa;
                }
                .label {
                    font-weight: bold;
                    color: #555555;
                    width: 30%;
                }
                .value {
                    color: #1a1a2e;
                }
                .footer {
                    margin-top: 80px;
                    padding: 40px 80px;
                    border-top: 3px solid #e2e8f0;
                    font-size: 36px;
                    color: #9ca3af;
                    text-align: center;
                }
            </style>
        </head>
        <body>
            <div class="header">
                <h1>%1</h1>
                <p>Conference ID: #%2 &nbsp;&bull;&nbsp; Generated on %3</p>
            </div>
            <div class="section">
                <h2>Conference Details</h2>
                <table class="info-grid">
                    <tr>
                        <td class="label">Date</td>
                        <td class="value">%4</td>
                    </tr>
                    <tr>
                        <td class="label">Location</td>
                        <td class="value">%5</td>
                    </tr>
                    <tr>
                        <td class="label">Price</td>
                        <td class="value">$%6</td>
                    </tr>
                </table>
            </div>
            <div class="footer">
                Peerly Research Platform &bull; Exported %3
            </div>
        </body>
        </html>
    )")
                       .arg(title.toHtmlEscaped(),
                            QString::number(id),
                            generatedDate,
                            confDate,
                            location.toHtmlEscaped(),
                            priceStr);

    QTextDocument doc;
    doc.setHtml(html);
    doc.setDefaultFont(QFont("Arial", 24));

    QSizeF paperSize = printer.pageLayout().paintRectPixels(printer.resolution()).size();
    doc.setPageSize(paperSize);

    doc.print(&printer);

    QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
}

//7 SORT SEARCH
void MainWindow::on_sortConfBtn_clicked()
{
    sortAscending = !sortAscending;

    ui->sortConfBtn->setText(sortAscending ? "Price ↑" : "Price ↓");

    loadConferences(sortAscending, ui->searchConfEdit->text());
}

void MainWindow::on_searchConfBtn_clicked()
{
    loadConferences(sortAscending, ui->searchConfEdit->text());
}

//LINKING BUTTONS
void MainWindow::on_conf_clicked(){ ui->stackedWidget->setCurrentIndex(4); loadConferences(sortAscending, "");}
void MainWindow::on_conf2_clicked(){ui->stackedWidget->setCurrentIndex(4); loadConferences(sortAscending, "");}
void MainWindow::on_conf3_clicked(){ui->stackedWidget->setCurrentIndex(4); loadConferences(sortAscending, "");}
void MainWindow::on_conf4_clicked(){ui->stackedWidget->setCurrentIndex(4); loadConferences(sortAscending, "");}
void MainWindow::on_conf5_clicked(){ui->stackedWidget->setCurrentIndex(4); loadConferences(sortAscending, "");}
void MainWindow::on_conf6_clicked(){ui->stackedWidget->setCurrentIndex(4); loadConferences(sortAscending, "");}
void MainWindow::on_conf7_clicked(){ui->stackedWidget->setCurrentIndex(4); loadConferences(sortAscending, "");}

//********************CONFERENCE END*************************************************************************************************************//

//********************Reveiw Start*************************************//

void MainWindow::on_exportPDF_clicked()
{
    QString fileNam = QFileDialog::getSaveFileName(
        this,
        tr("Export to PDF"),
        QDir::homePath() + "/export.pdf",
        tr("PDF Files (*.pdf)")
        );
    // Check
    if (fileNam.isEmpty()) {
        return;
    }
    if (!fileNam.endsWith(".pdf", Qt::CaseInsensitive)) {
        fileNam += ".pdf";
    }
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileNam);
    printer.setPageSize(QPageSize::A4);

    // Create QPainter and begin painting
    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::warning(this, tr("Export Failed"),
                             tr("Could not create PDF file."));
        return;
    }

    // For now, just placeholder text
    painter.setFont(QFont("Arial", 12));
    painter.drawText(100, 100, "PDF Export - Data will be added here");
    painter.end();
}

//***************Reveiw End*********************************//

void MainWindow::on_Browse_pressed()
{
    QString filePath = QFileDialog::getOpenFileName(
        this,
        "Browse Files",
        "",  // Starting directory
        "All Files (*)"  // File filter
        );

    if (!filePath.isEmpty()) {
        qDebug() << "Selected file:" << filePath;}
}

void MainWindow::on_homeButton_clicked(){ ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_homeButton2_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_homeButton3_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_homeButton4_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_homeButton5_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_homeButton6_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_homeButton7_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_backHome_clicked(){   ui->stackedWidget->setCurrentIndex(0);}



void MainWindow::on_reveiw_clicked(){ ui->stackedWidget->setCurrentIndex(1);}
void MainWindow::on_reveiw2_clicked(){ui->stackedWidget->setCurrentIndex(1);}
void MainWindow::on_reveiw3_clicked(){ui->stackedWidget->setCurrentIndex(1);}
void MainWindow::on_reveiw4_clicked(){ui->stackedWidget->setCurrentIndex(1);}
void MainWindow::on_reveiw5_clicked(){ui->stackedWidget->setCurrentIndex(1);}
void MainWindow::on_reveiw6_clicked(){ui->stackedWidget->setCurrentIndex(1);}
void MainWindow::on_reveiw7_clicked(){ui->stackedWidget->setCurrentIndex(1);}



void MainWindow::on_collab_clicked(){ ui->stackedWidget->setCurrentIndex(2);}
void MainWindow::on_collab2_clicked(){ui->stackedWidget->setCurrentIndex(2);}
void MainWindow::on_collab3_clicked(){ui->stackedWidget->setCurrentIndex(2);}
void MainWindow::on_collab4_clicked(){ui->stackedWidget->setCurrentIndex(2);}
void MainWindow::on_collab5_clicked(){ui->stackedWidget->setCurrentIndex(2);}
void MainWindow::on_collab6_clicked(){ui->stackedWidget->setCurrentIndex(2);}
void MainWindow::on_collab7_clicked(){ui->stackedWidget->setCurrentIndex(2);}



void MainWindow::on_profile_clicked(){           ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_profile2_clicked(){          ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_profile3_clicked(){          ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_profile4_clicked(){          ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_profile5_clicked(){          ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_profile6_clicked(){          ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_profile7_clicked(){          ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_login_clicked(){             ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_cancelBtnReg_clicked(){      ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_cancelBtnFor_clicked(){      ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_userSearchBackBTN_clicked(){ ui->stackedWidget->setCurrentIndex(3);}



void MainWindow::on_publication_clicked(){ ui->stackedWidget->setCurrentIndex(6);}
void MainWindow::on_publication2_clicked(){ui->stackedWidget->setCurrentIndex(6);}
void MainWindow::on_publication3_clicked(){ui->stackedWidget->setCurrentIndex(6);}
void MainWindow::on_publication4_clicked(){ui->stackedWidget->setCurrentIndex(6);}
void MainWindow::on_publication5_clicked(){ui->stackedWidget->setCurrentIndex(6);}
void MainWindow::on_publication6_clicked(){ui->stackedWidget->setCurrentIndex(6);}
void MainWindow::on_publication7_clicked(){ui->stackedWidget->setCurrentIndex(6);}



void MainWindow::on_Research_clicked(){ ui->stackedWidget->setCurrentIndex(7);}
void MainWindow::on_Research2_clicked(){ui->stackedWidget->setCurrentIndex(7);}
void MainWindow::on_Research3_clicked(){ui->stackedWidget->setCurrentIndex(7);}
void MainWindow::on_Research4_clicked(){ui->stackedWidget->setCurrentIndex(7);}
void MainWindow::on_Research5_clicked(){ui->stackedWidget->setCurrentIndex(7);}
void MainWindow::on_Research6_clicked(){ui->stackedWidget->setCurrentIndex(7);}
void MainWindow::on_Research7_clicked(){ui->stackedWidget->setCurrentIndex(7);}



void MainWindow::on_temp_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_temp2_clicked(){ui->stackedWidget->setCurrentIndex(8);}



void MainWindow::on_mkUser_clicked(){ui->stackedWidget->setCurrentIndex(9);}



void MainWindow::on_linkFor_linkActivated(){ui->stackedWidget->setCurrentIndex(10);}



void MainWindow::on_searchUserBTN_clicked(){ui->stackedWidget->setCurrentIndex(11);}



//don't go down, too much text for a single function
void MainWindow::toggleDarkMode(){
    mode = !mode;

    if (mode)
        ui->modeSwitch->setIcon(QIcon("icons/sun.svg"));
    else
        ui->modeSwitch->setIcon(QIcon("icons/moon.svg"));

    if(mode){
        this->setStyleSheet(
            "/* Research Publication App Stylesheet - LIGHT MODE */"
            ""
            "* {"
            "    font-family: -apple-system, BlinkMacSystemFont, \"Segoe UI\", Roboto, Arial, sans-serif;"
            "}"
            ""
            "QMainWindow {"
            "    background-color: #f6f8fc;"
            "}"
            ""
            "#sidebar {"
            "    background-color: #ffffff;"
            "    border-right: 1px solid #d8e0f0;"
            "}"
            ""
            "/* For QDateEdit */"
            "QDateEdit {"
            "    background-color: #ffffff !important;"
            "    border: 1px solid #c0d0e8;"
            "    border-radius: 6px;"
            "    padding: 8px 12px;"
            "    color: #1f2937;"
            "}"
            "/* Tabs */"
            "QTabWidget::pane {"
            "    border: 1px solid #d8e0f0;"
            "    background-color: #ffffff;"
            "    border-radius: 8px;"
            "}"
            ""
            "QTabBar::tab {"
            "    background-color: #f8fafc;"
            "    color: #64748b;"
            "    border: none;"
            "    border-bottom: 3px solid transparent;"
            "    padding: 12px 20px;"
            "    font-weight: 500;"
            "    margin-right: 2px;"
            "}"
            ""
            "QTabBar::tab:selected {"
            "    color: #1f2937;"
            "    background-color: #ffffff;"
            "    border-bottom: 3px solid #30b9bf;"
            "}"
            ""
            "QTabBar::tab:hover {"
            "    color: #1f2937;"
            "    background-color: #f1f5f9;"
            "}"
            ""
            "/* Specific Group Boxes */"
            "QGroupBox#FeatsGroup,"
            "QGroupBox#pubInfoGroup,"
            "QGroupBox#frame_4,"
            "QGroupBox#groupBox_3 {"
            " background-color: #ffffff;"
            " border: 1px solid #d8e0f0;"
            " border-radius: 8px;"
            " margin-top: 12px;"
            " padding: 16px;"
            " color: #1f2937;"
            " font-weight: bold;"
            "}"
            ""
            "QGroupBox#FeatsGroup::title,"
            "QGroupBox#pubInfoGroup::title,"
            "QGroupBox#frame_4::title,"
            "QGroupBox#groupBox_3::title {"
            " subcontrol-origin: margin;"
            " subcontrol-position: top left;"
            " padding: 0 8px;"
            " background-color: transparent;"
            " color: #1a7a7f;"
            "}"
            ""
            "QTabBar::close-button {"
            "    image: none;"
            "    subcontrol-position: right;"
            "    width: 14px;"
            "    height: 14px;"
            "}"
            ""
            "/* Scroll Areas */"
            "QScrollArea {"
            "    background-color: #f6f8fc;"
            "    border: none;"
            "}"
            ""
            "QScrollArea > QWidget {"
            "    background-color: #f6f8fc;"
            "}"
            ""
            ""
            "/* For QSpinBox / QDoubleSpinBox */"
            "QSpinBox, QDoubleSpinBox {"
            "    background-color: #ffffff !important;"
            "    border: 1px solid #c0d0e8;"
            "    border-radius: 6px;"
            "    padding: 8px 12px;"
            "    color: #1f2937;"
            "}"
            ""
            "#appTitle {"
            "    color: #1a7a7f;"
            "    font-size: 20pt;"
            "    font-weight: bold;"
            "    padding: 16px;"
            "    background-color: transparent;"
            "}"
            ""
            "/* Navigation Buttons */"
            "#homeNavButton, #myPageNavButton, #quitb {"
            "    text-align: left;"
            "    padding: 12px 16px;"
            "    border-radius: 8px;"
            "    background-color: transparent;"
            "    color: #2d3748;"
            "    font-size: 11pt;"
            "    border: none;"
            "}"
            ""
            "#homeNavButton:hover, #myPageNavButton:hover {"
            "    background-color: rgba(48, 185, 191, 0.08);"
            "}"
            ""
            "#homeNavButton:pressed, #myPageNavButton:pressed {"
            "    background-color: rgba(48, 185, 191, 0.15);"
            "}"
            ""
            "#quitb {"
            "    color: #2d3748;"
            "    margin-top: 8px;"
            "}"
            ""
            "#quitb:hover {"
            "    background-color: rgba(200, 30, 30, 0.08);"
            "    color: #c62828;"
            "}"
            ""
            "/* Top Bars */"
            "#homeTopBar, #myPageTopBar {"
            "    background-color: #f6f8fc;"
            "    padding: 16px 24px;"
            "}"
            ""
            "#homeTitle, #myPageTitle {"
            "    color: #1f2937;"
            "    font-size: 18pt;"
            "    font-weight: bold;"
            "    background-color: transparent;"
            "}"
            ""
            "/* Search Bar */"
            "QLineEdit#searchBar {"
            "    background-color: #ffffff !important;"
            "    border: 1px solid #c0d0e8;"
            "    border-radius: 20px;"
            "    padding: 10px 16px;"
            "    color: #1f2937;"
            "    font-size: 10pt;"
            "}"
            ""
            "QLineEdit#searchBar:focus {"
            "    border: 2px solid #30b9bf;"
            "    background-color: #ffffff !important;"
            "}"
            ""
            "QLineEdit#searchBar:hover {"
            "    border: 1px solid #30b9bf;"
            "}"
            ""
            "/* Scroll Areas */"
            "#homeScrollArea, #myScrollArea {"
            "    background-color: #f6f8fc;"
            "    border: none;"
            "}"
            ""
            "#homeScrollArea > QWidget, #myScrollArea > QWidget {"
            "    background-color: #f6f8fc;"
            "}"
            ""
            "/* Publication Cards */"
            "#publicationCard {"
            "    background-color: #ffffff;"
            "    border-radius: 10px;"
            "    border: 1px solid #e2e8f0;"
            "}"
            ""
            "#publicationCard:hover {"
            "    border: 1px solid #30b9bf;"
            "    background-color: #f8fcff;"
            "}"
            ""
            "#cardTitle {"
            "    color: #1f2937;"
            "    font-size: 14pt;"
            "    font-weight: bold;"
            "    background-color: transparent;"
            "}"
            ""
            "#cardAuthors {"
            "    color: #4b5563;"
            "    font-size: 10pt;"
            "    background-color: transparent;"
            "}"
            ""
            "#cardDate {"
            "    color: #6b7280;"
            "    font-size: 9pt;"
            "    background-color: transparent;"
            "}"
            ""
            "/* Primary Button (Upload/Browse) */"
            "#Browse {"
            "    background-color: #30b9bf;"
            "    color: white;"
            "    border: none;"
            "    border-radius: 20px;"
            "    padding: 10px 20px;"
            "    font-weight: bold;"
            "    font-size: 10pt;"
            "}"
            ""
            "#Browse:hover {"
            "    background-color: #3dd4db;"
            "}"
            ""
            "#Browse:pressed {"
            "    background-color: #26a0a6;"
            "}"
            ""
            "/* Secondary Buttons (View, Download) */"
            "#secondaryButton {"
            "    background-color: transparent;"
            "    border: 1px solid #30b9bf;"
            "    color: #30b9bf;"
            "    border-radius: 16px;"
            "    padding: 6px 16px;"
            "    font-size: 9pt;"
            "    font-weight: 600;"
            "}"
            ""
            "#secondaryButton:hover {"
            "    background-color: #30b9bf;"
            "    color: white;"
            "}"
            ""
            "#secondaryButton:pressed {"
            "    background-color: #26a0a6;"
            "    color: white;"
            "}"
            ""
            "/* Default QPushButton */"
            "QPushButton {"
            "    background-color: #e2efff;"
            "    color: #1e40af;"
            "    border: 1px solid #bfdbfe;"
            "    border-radius: 8px;"
            "    padding: 8px 16px;"
            "    font-size: 10pt;"
            "}"
            ""
            "QPushButton:hover {"
            "    background-color: #dbeafe;"
            "    border-color: #93c5fd;"
            "}"
            ""
            "QPushButton:pressed {"
            "    background-color: #bfdbfe;"
            "    border-color: #60a5fa;"
            "}"
            ""
            "/* ALL QLabel */"
            "QLabel {"
            "    color: #1f2937;"
            "    background-color: transparent;"
            "}"
            ""
            "#sidebar QLabel {"
            "    color: #1f2937;"
            "}"
            ""
            "/* Status Badges */"
            ".statusAccepted {"
            "    background-color: #dcfce7;"
            "    color: #166534;"
            "    border: 1px solid #86efac;"
            "    border-radius: 12px;"
            "    padding: 4px 12px;"
            "    font-size: 9pt;"
            "    font-weight: bold;"
            "}"
            ""
            ".statusReview {"
            "    background-color: #fef3c7;"
            "    color: #92400e;"
            "    border: 1px solid #fcd34d;"
            "    border-radius: 12px;"
            "    padding: 4px 12px;"
            "    font-size: 9pt;"
            "    font-weight: bold;"
            "}"
            ""
            ".statusRejected {"
            "    background-color: #fee2e2;"
            "    color: #991b1b;"
            "    border: 1px solid #fca5a5;"
            "    border-radius: 12px;"
            "    padding: 4px 12px;"
            "    font-size: 9pt;"
            "    font-weight: bold;"
            "}"
            ""
            "/* Scrollbars */"
            "QScrollBar:vertical {"
            "    background: #f6f8fc;"
            "    width: 10px;"
            "    border-radius: 5px;"
            "}"
            ""
            "QScrollBar::handle:vertical {"
            "    background: #c0d0e8;"
            "    min-height: 30px;"
            "    border-radius: 5px;"
            "}"
            ""
            "QScrollBar::handle:vertical:hover {"
            "    background: #30b9bf;"
            "}"
            ""
            "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {"
            "    height: 0px;"
            "}"
            ""
            "QScrollBar:horizontal {"
            "    background: #f6f8fc;"
            "    height: 10px;"
            "    border-radius: 5px;"
            "}"
            ""
            "QScrollBar::handle:horizontal {"
            "    background: #c0d0e8;"
            "    min-width: 30px;"
            "    border-radius: 5px;"
            "}"
            ""
            "QScrollBar::handle:horizontal:hover {"
            "    background: #30b9bf;"
            "}"
            ""
            "QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {"
            "    width: 0px;"
            "}"
            ""
            "/* ALL Input Fields */"
            "QLineEdit {"
            "    background-color: #ffffff !important;"
            "    border: 1px solid #c0d0e8;"
            "    border-radius: 6px;"
            "    padding: 8px 12px;"
            "    color: #1f2937;"
            "    selection-background-color: #30b9bf;"
            "    selection-color: white;"
            "}"
            ""
            "QLineEdit:focus {"
            "    border: 2px solid #30b9bf;"
            "}"
            ""
            "QLineEdit:hover {"
            "    border: 1px solid #30b9bf;"
            "}"
            ""
            "QTextEdit, QPlainTextEdit {"
            "    background-color: #ffffff !important;"
            "    border: 1px solid #c0d0e8;"
            "    border-radius: 6px;"
            "    padding: 8px 12px;"
            "    color: #1f2937;"
            "    selection-background-color: #30b9bf;"
            "    selection-color: white;"
            "}"
            ""
            "QTextEdit:focus, QPlainTextEdit:focus {"
            "    border: 2px solid #30b9bf;"
            "}"
            ""
            "QTextEdit:hover, QPlainTextEdit:hover {"
            "    border: 1px solid #30b9bf;"
            "}"
            ""
            "/* Combo Boxes */"
            "QComboBox {"
            "    background-color: #ffffff !important;"
            "    border: 1px solid #c0d0e8;"
            "    border-radius: 6px;"
            "    padding: 8px 12px;"
            "    color: #1f2937;"
            "    min-width: 100px;"
            "}"
            ""
            "QComboBox:hover {"
            "    border: 1px solid #30b9bf;"
            "}"
            ""
            "QComboBox:focus {"
            "    border: 2px solid #30b9bf;"
            "}"
            ""
            "QComboBox::drop-down {"
            "    border: none;"
            "    width: 20px;"
            "}"
            ""
            "QComboBox::down-arrow {"
            "    width: 0;"
            "    height: 0;"
            "    border-left: 5px solid transparent;"
            "    border-right: 5px solid transparent;"
            "    border-top: 5px solid #6b7280;"
            "}"
            ""
            "QComboBox QAbstractItemView {"
            "    background-color: #ffffff;"
            "    border: 1px solid #c0d0e8;"
            "    selection-background-color: #30b9bf;"
            "    selection-color: white;"
            "    outline: none;"
            "}"
            ""
            "/* Checkboxes & Radio */"
            "QCheckBox, QRadioButton {"
            "    spacing: 8px;"
            "    color: #1f2937;"
            "}"
            ""
            "QCheckBox::indicator, QRadioButton::indicator {"
            "    width: 18px;"
            "    height: 18px;"
            "    border: 1px solid #c0d0e8;"
            "    border-radius: 4px;"
            "    background-color: #ffffff;"
            "}"
            ""
            "QCheckBox::indicator:checked {"
            "    background-color: #30b9bf;"
            "    border: 1px solid #30b9bf;"
            "}"
            ""
            "QRadioButton::indicator {"
            "    border-radius: 10px;"
            "}"
            ""
            "QRadioButton::indicator:checked {"
            "    background-color: #ffffff;"
            "    border: 5px solid #30b9bf;"
            "}"
            ""
            "QCheckBox::indicator:hover, QRadioButton::indicator:hover {"
            "    border: 1px solid #30b9bf;"
            "}"
            ""
            "/* Progress Bar */"
            "QProgressBar {"
            "    border: 1px solid #c0d0e8;"
            "    border-radius: 6px;"
            "    text-align: center;"
            "    background-color: #f1f5f9;"
            "    color: #1f2937;"
            "    font-weight: bold;"
            "}"
            ""
            "QProgressBar::chunk {"
            "    background-color: #30b9bf;"
            "    border-radius: 4px;"
            "}"
            ""
            "/* Tooltips */"
            "QToolTip {"
            "    background-color: #1e293b;"
            "    color: #f1f5f9;"
            "    border: 1px solid #30b9bf;"
            "    padding: 6px 8px;"
            "    border-radius: 4px;"
            "}"
            ""
            "/* Tables / List / Tree */"
            "QTableView, QListView, QTreeView {"
            "    background-color: #ffffff;"
            "    border: 1px solid #e2e8f0;"
            "    border-radius: 8px;"
            "    gridline-color: #e2e8f0;"
            "    selection-background-color: #30b9bf;"
            "    selection-color: white;"
            "    color: #1f2937;"
            "    outline: none;"
            "}"
            ""
            "QTableView::item:hover, QListView::item:hover, QTreeView::item:hover {"
            "    background-color: #f0f9ff;"
            "}"
            ""
            "QHeaderView::section {"
            "    background-color: #f1f5f9;"
            "    padding: 8px;"
            "    border: none;"
            "    border-right: 1px solid #e2e8f0;"
            "    border-bottom: 1px solid #e2e8f0;"
            "    color: #1f2937;"
            "    font-weight: bold;"
            "    font-size: 9pt;"
            "}"
            ""
            "/* Menu Bar */"
            "QMenuBar {"
            "    background-color: #ffffff;"
            "    border-bottom: 1px solid #d8e0f0;"
            "    color: #1f2937;"
            "}"
            ""
            "QMenuBar::item:selected {"
            "    background-color: #e2efff;"
            "}"
            ""
            "QMenu {"
            "    background-color: #ffffff;"
            "    border: 1px solid #d8e0f0;"
            "    color: #1f2937;"
            "}"
            ""
            "QMenu::item:selected {"
            "    background-color: #30b9bf;"
            "    color: white;"
            "}"
            ""
            "/* Status Bar */"
            "QStatusBar {"
            "    background-color: #f1f5f9;"
            "    border-top: 1px solid #d8e0f0;"
            "    color: #4b5563;"
            "}"
            ""
            "/* Group Box */"
            "QGroupBox {"
            "    background-color: #c5d0e2;"
            "    border: 1px solid #d8e0f0;"
            "    border-radius: 8px;"
            "    margin-top: 12px;"
            "    padding-top: 12px;"
            "    color: #1f2937;"
            "    font-weight: bold;"
            "}"
            ""
            "QGroupBox::title {"
            "    subcontrol-origin: margin;"
            "    subcontrol-position: top left;"
            "    padding: 0 8px;"
            "    color: #1a7a7f;"
            "}"
            ""
            "/* Tabs */"
            "QTabWidget::pane {"
            "    border: 1px solid #d8e0f0;"
            "    background-color: #ffffff;"
            "    border-radius: 8px;"
            "}"
            ""
            "QTabBar::tab {"
            "    background-color: #f8fafc;"
            "    color: #64748b;"
            "    border: none;"
            "    border-bottom: 3px solid transparent;"
            "    padding: 12px 20px;"
            "    font-weight: 500;"
            "}"
            ""
            "QTabBar::tab:selected {"
            "    color: #1f2937;"
            "    background-color: #ffffff;"
            "    border-bottom: 3px solid #30b9bf;"
            "}"
            ""
            "QTabBar::tab:hover {"
            "    color: #1f2937;"
            "    background-color: #f1f5f9;"
            "}"
            "QFrame {"
            "    background-color: #ffffff;"
            "    border: 1px solid #d8e0f0;"
            "    border-radius: 8px;"
            "}"
            );} else{
        this->setStyleSheet(
            "/* Research Publication App Stylesheet - PREMIUM MUTED DARK */"
            ""
            "* {"
            "    font-family: -apple-system, BlinkMacSystemFont, \"Segoe UI\", Roboto, Arial, sans-serif;"
            "}"
            ""
            "QMainWindow {"
            "    background-color: #2a3142;"
            "}"
            ""
            "#sidebar {"
            "    background-color: #343d52;"
            "    border-right: 1px solid #1f2530;"
            "}"
            ""
            "/* For QDateEdit */"
            "QDateEdit {"
            "    background-color: #d4dce8 !important;"
            "    border: 1px solid #a8b5c9;"
            "    border-radius: 6px;"
            "    padding: 8px 12px;"
            "    color: #1a1f2e;"
            "}"
            ""
            "/* For QSpinBox / QDoubleSpinBox */"
            "QSpinBox, QDoubleSpinBox {"
            "    background-color: #d4dce8 !important;"
            "    border: 1px solid #a8b5c9;"
            "    border-radius: 6px;"
            "    padding: 8px 12px;"
            "    color: #1a1f2e;"
            "}"
            ""
            "#appTitle {"
            "    color: #1a1f2e;"
            "    font-size: 20pt;"
            "    font-weight: bold;"
            "    padding: 16px;"
            "    background-color: transparent;"
            "}"
            ""
            "/* Navigation Buttons */"
            "#homeNavButton, #myPageNavButton, #quitb {"
            "    text-align: left;"
            "    padding: 12px 16px;"
            "    border-radius: 8px;"
            "    background-color: transparent;"
            "    color: #0d1117;"
            "    font-size: 11pt;"
            "    border: none;"
            "}"
            ""
            "/* Tabs */"
            "QTabWidget::pane {"
            "    border: 1px solid #a8b5c9;"
            "    background-color: #c5d0e2;"
            "    border-radius: 8px;"
            "}"
            ""
            "QTabBar::tab {"
            "    background-color: #343d52;"
            "    color: #4a5568;"
            "    border: none;"
            "    border-bottom: 3px solid transparent;"
            "    padding: 12px 20px;"
            "    font-weight: 500;"
            "    margin-right: 2px;"
            "}"
            ""
            "QTabBar::tab:selected {"
            "    color: #0d1117;"
            "    background-color: #c5d0e2;"
            "    border-bottom: 3px solid #30b9bf;"
            "}"
            ""
            "QTabBar::tab:hover {"
            "    color: #1a1f2e;"
            "    background-color: #545e73;"
            "}"
            ""
            "QTabBar::close-button {"
            "    image: none;"
            "    subcontrol-position: right;"
            "    width: 14px;"
            "    height: 14px;"
            "}"
            ""
            "/* Scroll Areas */"
            "QScrollArea {"
            "    background-color: #2a3142;"
            "    border: none;"
            "}"
            ""
            "QScrollArea > QWidget {"
            "    background-color: #2a3142;"
            "}"
            ""
            "#homeNavButton:hover, #myPageNavButton:hover {"
            "    background-color: rgba(48, 185, 191, 0.2);"
            "}"
            ""
            "#homeNavButton:pressed, #myPageNavButton:pressed {"
            "    background-color: rgba(48, 185, 191, 0.3);"
            "}"
            ""
            "#quitb {"
            "    color: #0d1117;"
            "    margin-top: 8px;"
            "}"
            ""
            "/* Specific Group Boxes */"
            "QGroupBox#FeatsGroup,"
            "QGroupBox#pubInfoGroup,"
            "QGroupBox#frame_4,"
            "QGroupBox#groupBox_3 {"
            " background-color: #c5d0e2;"
            " border: 1px solid #a8b5c9;"
            " border-radius: 8px;"
            " margin-top: 12px;"
            " padding: 16px;"
            " color: #0d1117;"
            " font-weight: bold;"
            "}"
            ""
            "QGroupBox#FeatsGroup::title,"
            "QGroupBox#pubInfoGroup::title,"
            "QGroupBox#frame_4::title,"
            "QGroupBox#groupBox_3::title {"
            " subcontrol-origin: margin;"
            " subcontrol-position: top left;"
            " padding: 0 8px;"
            " background-color: transparent;"
            " color: #0a5a5f;"
            "}"
            ""
            "QGroupBox#FeatsGroup QLabel,"
            "QGroupBox#pubInfoGroup QLabel,"
            "QGroupBox#frame_4 QLabel,"
            "QGroupBox#groupBox_3 QLabel {"
            " color: #0d1117 !important;"
            "}"
            ""
            "/* Additional Specific Frames */"
            "QGroupBox#frame_6,"
            "QGroupBox#collaborationCreationFrame {"
            " background-color: #c5d0e2;"
            " border: 1px solid #a8b5c9;"
            " border-radius: 8px;"
            " margin-top: 12px;"
            " padding: 16px;"
            " color: #0d1117;"
            " font-weight: bold;"
            "}"
            ""
            "QGroupBox#frame_6 QLabel,"
            "QGroupBox#collaborationCreationFrame QLabel {"
            " color: #0d1117 !important;"
            "}"
            ""
            "QGroupBox#frame_6::title,"
            "QGroupBox#collaborationCreationFrame::title {"
            " subcontrol-origin: margin;"
            " subcontrol-position: top left;"
            " padding: 0 8px;"
            " background-color: transparent;"
            " color: #0a5a5f;"
            "}"
            ""
            "#quitb:hover {"
            "    background-color: rgba(220, 38, 38, 0.2);"
            "    color: #b91c1c;"
            "}"
            ""
            "/* Top Bars */"
            "#homeTopBar, #myPageTopBar {"
            "    background-color: #2a3142;"
            "    padding: 16px 24px;"
            "}"
            ""
            "#homeTitle, #myPageTitle {"
            "    color: #0d1117;"
            "    font-size: 18pt;"
            "    font-weight: bold;"
            "    background-color: transparent;"
            "}"
            ""
            "/* Search Bar */"
            "QLineEdit#searchBar {"
            "    background-color: #d4dce8 !important;"
            "    border: 1px solid #a8b5c9;"
            "    border-radius: 20px;"
            "    padding: 10px 16px;"
            "    color: #1a1f2e;"
            "    font-size: 10pt;"
            "}"
            ""
            "QLineEdit#searchBar:focus {"
            "    border: 2px solid #30b9bf;"
            "    background-color: #e0e7f1 !important;"
            "}"
            ""
            "QLineEdit#searchBar:hover {"
            "    border: 1px solid #30b9bf;"
            "    background-color: #dce4f0 !important;"
            "}"
            ""
            "/* Scroll Areas */"
            "#homeScrollArea, #myScrollArea {"
            "    background-color: #2a3142;"
            "    border: none;"
            "}"
            ""
            "#homeScrollArea > QWidget, #myScrollArea > QWidget {"
            "    background-color: #2a3142;"
            "}"
            ""
            "/* Publication Cards */"
            "#publicationCard {"
            "    background-color: #c5d0e2;"
            "    border-radius: 10px;"
            "    border: 1px solid #a8b5c9;"
            "}"
            ""
            "#publicationCard:hover {"
            "    border: 1px solid #30b9bf;"
            "    background-color: #d0dae9;"
            "    box-shadow: 0 4px 12px rgba(48, 185, 191, 0.15);"
            "}"
            ""
            "#cardTitle {"
            "    color: #0d1117;"
            "    font-size: 14pt;"
            "    font-weight: bold;"
            "    background-color: transparent;"
            "}"
            ""
            "#cardAuthors {"
            "    color: #2d3748;"
            "    font-size: 10pt;"
            "    background-color: transparent;"
            "}"
            ""
            "#cardDate {"
            "    color: #4a5568;"
            "    font-size: 9pt;"
            "    background-color: transparent;"
            "}"
            ""
            "/* Primary Button (Upload/Browse) */"
            "#Browse {"
            "    background-color: #30b9bf;"
            "    color: white;"
            "    border: none;"
            "    border-radius: 20px;"
            "    padding: 10px 20px;"
            "    font-weight: bold;"
            "    font-size: 10pt;"
            "}"
            ""
            "#Browse:hover {"
            "    background-color: #3dd4db;"
            "}"
            ""
            "#Browse:pressed {"
            "    background-color: #26a0a6;"
            "}"
            ""
            "/* Secondary Buttons (View, Download) */"
            "#secondaryButton {"
            "    background-color: transparent;"
            "    border: 1px solid #30b9bf;"
            "    color: #0c7a7f;"
            "    border-radius: 16px;"
            "    padding: 6px 16px;"
            "    font-size: 9pt;"
            "    font-weight: 600;"
            "}"
            ""
            "#secondaryButton:hover {"
            "    background-color: #30b9bf;"
            "    color: white;"
            "}"
            ""
            "#secondaryButton:pressed {"
            "    background-color: #26a0a6;"
            "    color: white;"
            "}"
            ""
            "/* Default QPushButton */"
            "QPushButton {"
            "    background-color: #b8c5d9;"
            "    color: #0d1117;"
            "    border: 1px solid #98a8c0;"
            "    border-radius: 8px;"
            "    padding: 8px 16px;"
            "    font-size: 10pt;"
            "    font-weight: 500;"
            "}"
            ""
            "QPushButton:hover {"
            "    background-color: #c8d4e5;"
            "    border-color: #a8b5c9;"
            "}"
            ""
            "QPushButton:pressed {"
            "    background-color: #a8b5c9;"
            "    border-color: #8898b0;"
            "}"
            ""
            "/* ALL QLabel */"
            "QLabel {"
            "    color: #0d1117;"
            "    background-color: transparent;"
            "}"
            ""
            "#sidebar QLabel {"
            "    color: #1a1f2e;"
            "}"
            ""
            "/* Status Badges */"
            ".statusAccepted {"
            "    background-color: #a7f3d0;"
            "    color: #064e3b;"
            "    border: 1px solid #6ee7b7;"
            "    border-radius: 12px;"
            "    padding: 4px 12px;"
            "    font-size: 9pt;"
            "    font-weight: bold;"
            "}"
            ""
            ".statusReview {"
            "    background-color: #fde68a;"
            "    color: #78350f;"
            "    border: 1px solid #fcd34d;"
            "    border-radius: 12px;"
            "    padding: 4px 12px;"
            "    font-size: 9pt;"
            "    font-weight: bold;"
            "}"
            ""
            ".statusRejected {"
            "    background-color: #fecaca;"
            "    color: #7f1d1d;"
            "    border: 1px solid #fca5a5;"
            "    border-radius: 12px;"
            "    padding: 4px 12px;"
            "    font-size: 9pt;"
            "    font-weight: bold;"
            "}"
            ""
            "/* Scrollbars */"
            "QScrollBar:vertical {"
            "    background: #2a3142;"
            "    width: 10px;"
            "    border-radius: 5px;"
            "}"
            ""
            "QScrollBar::handle:vertical {"
            "    background: #545e73;"
            "    min-height: 30px;"
            "    border-radius: 5px;"
            "}"
            ""
            "QScrollBar::handle:vertical:hover {"
            "    background: #30b9bf;"
            "}"
            ""
            "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {"
            "    height: 0px;"
            "}"
            ""
            "QScrollBar:horizontal {"
            "    background: #2a3142;"
            "    height: 10px;"
            "    border-radius: 5px;"
            "}"
            ""
            "QScrollBar::handle:horizontal {"
            "    background: #545e73;"
            "    min-width: 30px;"
            "    border-radius: 5px;"
            "}"
            ""
            "QScrollBar::handle:horizontal:hover {"
            "    background: #30b9bf;"
            "}"
            ""
            "QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {"
            "    width: 0px;"
            "}"
            ""
            "/* ALL Input Fields */"
            "QLineEdit {"
            "    background-color: #d4dce8 !important;"
            "    border: 1px solid #a8b5c9;"
            "    border-radius: 6px;"
            "    padding: 8px 12px;"
            "    color: #1a1f2e;"
            "    selection-background-color: #30b9bf;"
            "    selection-color: white;"
            "}"
            ""
            "QLineEdit:focus {"
            "    border: 2px solid #30b9bf;"
            "    background-color: #e0e7f1 !important;"
            "}"
            ""
            "QLineEdit:hover {"
            "    border: 1px solid #30b9bf;"
            "    background-color: #dce4f0 !important;"
            "}"
            ""
            "QTextEdit, QPlainTextEdit {"
            "    background-color: #d4dce8 !important;"
            "    border: 1px solid #a8b5c9;"
            "    border-radius: 6px;"
            "    padding: 8px 12px;"
            "    color: #1a1f2e;"
            "    selection-background-color: #30b9bf;"
            "    selection-color: white;"
            "}"
            ""
            "QTextEdit:focus, QPlainTextEdit:focus {"
            "    border: 2px solid #30b9bf;"
            "    background-color: #e0e7f1 !important;"
            "}"
            ""
            "QTextEdit:hover, QPlainTextEdit:hover {"
            "    border: 1px solid #30b9bf;"
            "    background-color: #dce4f0 !important;"
            "}"
            ""
            "/* Combo Boxes */"
            "QComboBox {"
            "    background-color: #d4dce8 !important;"
            "    border: 1px solid #a8b5c9;"
            "    border-radius: 6px;"
            "    padding: 8px 12px;"
            "    color: #1a1f2e;"
            "    min-width: 100px;"
            "}"
            ""
            "QComboBox:hover {"
            "    border: 1px solid #30b9bf;"
            "    background-color: #dce4f0 !important;"
            "}"
            ""
            "QComboBox:focus {"
            "    border: 2px solid #30b9bf;"
            "    background-color: #e0e7f1 !important;"
            "}"
            ""
            "QComboBox::drop-down {"
            "    border: none;"
            "    width: 20px;"
            "}"
            ""
            "QComboBox::down-arrow {"
            "    width: 0;"
            "    height: 0;"
            "    border-left: 5px solid transparent;"
            "    border-right: 5px solid transparent;"
            "    border-top: 5px solid #2d3748;"
            "}"
            ""
            "QComboBox QAbstractItemView {"
            "    background-color: #d4dce8;"
            "    border: 1px solid #a8b5c9;"
            "    selection-background-color: #30b9bf;"
            "    selection-color: white;"
            "    outline: none;"
            "    color: #1a1f2e;"
            "}"
            ""
            "/* Checkboxes & Radio */"
            "QCheckBox, QRadioButton {"
            "    spacing: 8px;"
            "    color: #0d1117;"
            "}"
            ""
            "QCheckBox::indicator, QRadioButton::indicator {"
            "    width: 18px;"
            "    height: 18px;"
            "    border: 2px solid #6b7a91;"
            "    border-radius: 4px;"
            "    background-color: #d4dce8;"
            "}"
            ""
            "QCheckBox::indicator:checked {"
            "    background-color: #30b9bf;"
            "    border: 2px solid #30b9bf;"
            "}"
            ""
            "QRadioButton::indicator {"
            "    border-radius: 10px;"
            "}"
            ""
            "QRadioButton::indicator:checked {"
            "    background-color: #d4dce8;"
            "    border: 5px solid #30b9bf;"
            "}"
            ""
            "QCheckBox::indicator:hover, QRadioButton::indicator:hover {"
            "    border: 2px solid #30b9bf;"
            "}"
            ""
            "/* Progress Bar */"
            "QProgressBar {"
            "    border: 1px solid #a8b5c9;"
            "    border-radius: 6px;"
            "    text-align: center;"
            "    background-color: #c5d0e2;"
            "    color: #0d1117;"
            "    font-weight: bold;"
            "}"
            ""
            "QProgressBar::chunk {"
            "    background-color: #30b9bf;"
            "    border-radius: 4px;"
            "}"
            ""
            "/* Tooltips */"
            "QToolTip {"
            "    background-color: #1a1f2e;"
            "    color: #e0e7f1;"
            "    border: 1px solid #30b9bf;"
            "    padding: 6px 8px;"
            "    border-radius: 4px;"
            "}"
            ""
            "/* Tables / List / Tree */"
            "QTableView, QListView, QTreeView {"
            "    background-color: #c5d0e2;"
            "    border: 1px solid #a8b5c9;"
            "    border-radius: 8px;"
            "    gridline-color: #98a8c0;"
            "    selection-background-color: #30b9bf;"
            "    selection-color: white;"
            "    color: #0d1117;"
            "    outline: none;"
            "}"
            ""
            "QTableView::item:hover, QListView::item:hover, QTreeView::item:hover {"
            "    background-color: #d0dae9;"
            "}"
            ""
            "QHeaderView::section {"
            "    background-color: #b8c5d9;"
            "    padding: 8px;"
            "    border: none;"
            "    border-right: 1px solid #98a8c0;"
            "    border-bottom: 1px solid #98a8c0;"
            "    color: #0d1117;"
            "    font-weight: bold;"
            "    font-size: 9pt;"
            "}"
            ""
            "/* Menu Bar */"
            "QMenuBar {"
            "    background-color: #343d52;"
            "    border-bottom: 1px solid #1f2530;"
            "    color: #0d1117;"
            "}"
            ""
            "QMenuBar::item:selected {"
            "    background-color: #3e4859;"
            "}"
            ""
            "QMenu {"
            "    background-color: #c5d0e2;"
            "    border: 1px solid #a8b5c9;"
            "    color: #0d1117;"
            "}"
            ""
            "QMenu::item:selected {"
            "    background-color: #30b9bf;"
            "    color: white;"
            "}"
            ""
            "/* Status Bar */"
            "QStatusBar {"
            "    background-color: #343d52;"
            "    border-top: 1px solid #1f2530;"
            "    color: #2d3748;"
            "}"
            ""
            "/* Group Box */"
            "QGroupBox {"
            "    border: 1px solid #a8b5c9;"
            "    border-radius: 8px;"
            "    margin-top: 12px;"
            "    padding-top: 12px;"
            "    color: #0d1117;"
            "    font-weight: bold;"
            "}"
            ""
            "QGroupBox::title {"
            "    subcontrol-origin: margin;"
            "    subcontrol-position: top left;"
            "    padding: 0 8px;"
            "    color: #0a5a5f;"
            "}"
            ""
            "/* Tabs */"
            "QTabWidget::pane {"
            "    border: 1px solid #a8b5c9;"
            "    background-color: #c5d0e2;"
            "    border-radius: 8px;"
            "}"
            ""
            "QTabBar::tab {"
            "    background-color: #343d52;"
            "    color: #4a5568;"
            "    border: none;"
            "    border-bottom: 3px solid transparent;"
            "    padding: 12px 20px;"
            "    font-weight: 500;"
            "}"
            ""
            "QTabBar::tab:selected {"
            "    color: #0d1117;"
            "    background-color: #c5d0e2;"
            "    border-bottom: 3px solid #30b9bf;"
            "}"
            "/* Group Box */"
            "QGroupBox {"
            "    border: 1px solid #a8b5c9;"
            "    border-radius: 8px;"
            "    margin-top: 12px;"
            "    padding-top: 12px;"
            "    color: #0d1117;"
            "    font-weight: bold;"
            "}"
            ""
            "QGroupBox::title {"
            "    subcontrol-origin: margin;"
            "    subcontrol-position: top left;"
            "    padding: 0 8px;"
            "    color: #0a5a5f;"
            "}"
            ""
            "/* Specific groupBox styling */"
            "QGroupBox#groupBox {"
            "    background-color: #c5d0e2;"
            "    border: 1px solid #a8b5c9;"
            "    border-radius: 8px;"
            "    margin-top: 12px;"
            "    padding: 16px;"
            "    color: #0d1117;"
            "    font-weight: bold;"
            "}"
            ""
            "QGroupBox#groupBox::title {"
            "    subcontrol-origin: margin;"
            "    subcontrol-position: top left;"
            "    padding: 0 8px;"
            "    background-color: transparent;"
            "    color: #0a5a5f;"
            "}"
            ""
            "QTabBar::tab:hover {"
            "    color: #1a1f2e;"
            "    background-color: #545e73;"
            "}"
            "QFrame {"
            "    background-color: #c5d0e2;"
            "    border: 1px solid #a8b5c9;"
            "    border-radius: 8px;"
            "}"
            );
    }
//end
}






