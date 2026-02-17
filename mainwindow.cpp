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
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize({1280,720});
    mode=false;

    QPixmap logo("logo.png");//logo stuff!
    ui->loginLogo->setPixmap(logo);
    ui->pic->setPixmap(logo);//logo stuff!


    //ui->stackedWidget->setCurrentIndex(3);
    toggleDarkMode();

    QPixmap userPic("user.png"); //temporary until user gets an actual db
    ui->userPic->setPixmap(userPic);

    QPixmap chartt("pie_chart.png");
    ui->chart->setPixmap(chartt);
    QPixmap bar("bar.png");
    ui->bar->setPixmap(bar);
    QPixmap post("gallary.png");
    ui->postPicture->setPixmap(post);
    QPixmap drop("drop.png");
    ui->dropPlace->setPixmap(drop);


    //actual charts for review
    QPieSeries *series = new QPieSeries();
    series->append("Review A", 40);
    series->append("Review B", 30);
    series->append("Review C", 20);
    series->append("Review D", 10);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Research Distribution");
    chart->legend()->setAlignment(Qt::AlignRight);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(100, 100);
    chartView->setMaximumSize(250, 250);

    QWidget *tabPage = ui->tabWidget->widget(0);

    QVBoxLayout *layout = new QVBoxLayout(tabPage);
    layout->setContentsMargins(30, 20, 30, 20);
    layout->setAlignment(Qt::AlignBottom);
    layout->addWidget(chartView);
    tabPage->setLayout(layout);



}

MainWindow::~MainWindow()
{
    delete ui;
}

//********************REVIEW START**************************************************//

void MainWindow::loadReviews(bool ascending, QString searchFilter)
{
    // Get or create layout on widget_2
    QVBoxLayout* reviewLayout = qobject_cast<QVBoxLayout*>(ui->widget_2->layout());
    if (!reviewLayout) {
        reviewLayout = new QVBoxLayout(ui->widget_2);
        ui->widget_2->setLayout(reviewLayout);
    }

    // Clear
    QLayoutItem* reviewItem;
    while ((reviewItem = reviewLayout->takeAt(0)) != nullptr) {
        delete reviewItem->widget();
        delete reviewItem;
    }

    // Query
    QString reviewQueryStr = "SELECT IDREVIEW, REVIEWER_NAME, REVIEW_DATE, SUBMISSION_ID, PUBLICATION_ID, COMMENTREVIEW FROM REVIEW";
    if (!searchFilter.trimmed().isEmpty())
        reviewQueryStr += " WHERE UPPER(REVIEWER_NAME) LIKE UPPER(:search)";
    reviewQueryStr += ascending ? " ORDER BY REVIEW_DATE ASC" : " ORDER BY REVIEW_DATE DESC";

    QSqlQuery reviewQuery;
    reviewQuery.prepare(reviewQueryStr);
    if (!searchFilter.trimmed().isEmpty())
        reviewQuery.bindValue(":search", "%" + searchFilter.trimmed() + "%");
    reviewQuery.exec();

    bool reviewsFound = false;

    while (reviewQuery.next()) {
        reviewsFound = true;
        int reviewId         = reviewQuery.value(0).toInt();
        QString reviewerName = reviewQuery.value(1).toString();
        QDate reviewDate     = reviewQuery.value(2).toDate();
        int submissionId     = reviewQuery.value(3).toInt();
        int publicationId    = reviewQuery.value(4).toInt();
        QString comment      = reviewQuery.value(5).toString();

        QFrame* reviewCard = new QFrame();
        reviewCard->setFrameShape(QFrame::StyledPanel);
        reviewCard->setMinimumHeight(120);

        QVBoxLayout* reviewCardLayout = new QVBoxLayout(reviewCard);

        QLabel* reviewerLabel   = new QLabel("<b>" + reviewerName + "</b>");
        QLabel* reviewInfoLabel = new QLabel(
            "Date: " + reviewDate.toString("dd/MM/yyyy") +
            " | Submission ID: " + QString::number(submissionId) +
            " | Publication ID: " + QString::number(publicationId)
            );
        QLabel* commentLabel = new QLabel("Comment: " + comment);
        commentLabel->setWordWrap(true);

        QHBoxLayout* reviewBtnLayout = new QHBoxLayout();
        QPushButton* editReviewBtn   = new QPushButton("Edit");
        QPushButton* deleteReviewBtn = new QPushButton("Delete");
        QPushButton* pdfReviewBtn    = new QPushButton("Export PDF");

        reviewBtnLayout->addWidget(editReviewBtn);
        reviewBtnLayout->addWidget(deleteReviewBtn);
        reviewBtnLayout->addWidget(pdfReviewBtn);

        reviewCardLayout->addWidget(reviewerLabel);
        reviewCardLayout->addWidget(reviewInfoLabel);
        reviewCardLayout->addWidget(commentLabel);
        reviewCardLayout->addLayout(reviewBtnLayout);

        reviewLayout->addWidget(reviewCard);

        // Delete
        connect(deleteReviewBtn, &QPushButton::clicked, this, [=]() {
            QSqlQuery deleteReviewQuery;
            deleteReviewQuery.prepare("DELETE FROM REVIEW WHERE IDREVIEW = ?");
            deleteReviewQuery.addBindValue(reviewId);
            deleteReviewQuery.exec();
            loadReviews(ascending, searchFilter);
        });

        // Edit
        connect(editReviewBtn, &QPushButton::clicked, this, [=]() {
            QSqlQuery fetchReviewQuery;
            fetchReviewQuery.prepare("SELECT REVIEWER_NAME, REVIEW_DATE, SUBMISSION_ID, PUBLICATION_ID, COMMENTREVIEW FROM REVIEW WHERE IDREVIEW=:id");
            fetchReviewQuery.bindValue(":id", reviewId);
            fetchReviewQuery.exec();
            if (!fetchReviewQuery.next()) return;

            QDialog* editDialog = new QDialog(this);
            editDialog->setWindowTitle("Edit Review");
            editDialog->setMinimumWidth(400);

            QFormLayout* formLayout = new QFormLayout(editDialog);

            QLineEdit* nameInput    = new QLineEdit(fetchReviewQuery.value(0).toString());
            QDateEdit* dateInput    = new QDateEdit(fetchReviewQuery.value(1).toDate());
            dateInput->setCalendarPopup(true);
            QSpinBox*  subIdInput   = new QSpinBox();
            subIdInput->setMaximum(999999);
            subIdInput->setValue(fetchReviewQuery.value(2).toInt());
            QSpinBox*  pubIdInput   = new QSpinBox();
            pubIdInput->setMaximum(999999);
            pubIdInput->setValue(fetchReviewQuery.value(3).toInt());
            QTextEdit* commentInput = new QTextEdit(fetchReviewQuery.value(4).toString());
            commentInput->setFixedHeight(80);

            formLayout->addRow("Reviewer Name:",  nameInput);
            formLayout->addRow("Review Date:",    dateInput);
            formLayout->addRow("Submission ID:",  subIdInput);
            formLayout->addRow("Publication ID:", pubIdInput);
            formLayout->addRow("Comment:",        commentInput);

            QHBoxLayout* dialogBtnLayout = new QHBoxLayout();
            QPushButton* saveBtn         = new QPushButton("Save");
            QPushButton* cancelBtn       = new QPushButton("Cancel");
            dialogBtnLayout->addWidget(saveBtn);
            dialogBtnLayout->addWidget(cancelBtn);
            formLayout->addRow(dialogBtnLayout);

            connect(cancelBtn, &QPushButton::clicked, editDialog, &QDialog::reject);

            connect(saveBtn, &QPushButton::clicked, this, [=]() {
                QSqlQuery updateQuery;
                updateQuery.prepare("UPDATE REVIEW SET REVIEWER_NAME=:name, REVIEW_DATE=:date, SUBMISSION_ID=:sid, PUBLICATION_ID=:pid, COMMENTREVIEW=:comment WHERE IDREVIEW=:id");
                updateQuery.bindValue(":name",    nameInput->text());
                updateQuery.bindValue(":date",    dateInput->date());
                updateQuery.bindValue(":sid",     subIdInput->value());
                updateQuery.bindValue(":pid",     pubIdInput->value());
                updateQuery.bindValue(":comment", commentInput->toPlainText());
                updateQuery.bindValue(":id",      reviewId);
                if (updateQuery.exec()) {
                    editDialog->accept();
                    loadReviews(ascending, searchFilter);
                }
            });

            editDialog->exec();
        });

        // PDF
        connect(pdfReviewBtn, &QPushButton::clicked, this, [=]() {
            QSqlQuery pdfReviewQuery;
            pdfReviewQuery.prepare("SELECT REVIEWER_NAME, REVIEW_DATE, SUBMISSION_ID, PUBLICATION_ID, COMMENTREVIEW FROM REVIEW WHERE IDREVIEW=:id");
            pdfReviewQuery.bindValue(":id", reviewId);
            pdfReviewQuery.exec();

        });
    }

    if (!reviewsFound) {
        QLabel* noReviewsLabel = new QLabel("No reviews found.");
        noReviewsLabel->setAlignment(Qt::AlignCenter);
        reviewLayout->addWidget(noReviewsLabel);
    }

    reviewLayout->addStretch();
}
//********************REVIEW END**************************************************//

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
    //Dark mode compatible
    const bool dark = !mode;

    //Backgrounds
    const QString bgPage         = dark ? "#2a3142" : "#f6f8fc";
    const QString bgCard         = dark ? "#343d52" : "#ffffff";
    const QString bgScrollbar    = dark ? "#2a3142" : "#f6f8fc";
    const QString bgScrollHandle = dark ? "#545e73" : "#c0d0e8";
    const QString bgTrack        = dark ? "#3e4859" : "#f1f5f9";

    //Borders
    const QString border         = dark ? "#4a5568" : "#e2e8f0";
    const QString divColor       = dark ? "#3e4859" : "#e2e8f0";

    //Text
    const QString txtPrimary     = dark ? "#e0e7f1" : "#1f2937";
    const QString txtSub         = dark ? "#8892a4" : "#9ca3af";
    const QString txtSection     = dark ? "#8892a4" : "#9ca3af";

    //Button
    const QString btnBg          = dark ? "#3e4859" : "#ffffff";
    const QString btnTxt         = dark ? "#e0e7f1" : "#1f2937";
    const QString btnHover       = dark ? "#4a5568" : "#f1f5f9";
    const QString btnPressed     = dark ? "#545e73" : "#e2e8f0";

    //QPainter colors
    const QColor cWhite   (0xff, 0xff, 0xff);
    const QColor cTeal    (0x30, 0xb9, 0xbf);
    const QColor cIndigo  (0x63, 0x66, 0xf1);
    const QColor cAmber   (0xf5, 0x9e, 0x0b);
    const QColor cRed     (0xdc, 0x26, 0x26);
    const QColor cGreen   (0x16, 0xa3, 0x4a);
    const QColor cPink    (0xec, 0x48, 0x99);
    const QColor cPurple  (0x8b, 0x5c, 0xf6);
    const QColor cShadow  (0x00, 0x00, 0x00, 18);

    //Painter colors
    const QColor cGray    = dark ? QColor(0xa0, 0xae, 0xc0) : QColor(0x6b, 0x72, 0x80);
    const QColor cLightBg = dark ? QColor(0x3e, 0x48, 0x59) : QColor(0xf1, 0xf5, 0xf9);
    const QColor cText    = dark ? QColor(0xe0, 0xe7, 0xf1) : QColor(0x1f, 0x29, 0x37);
    const QColor cSubText = dark ? QColor(0x88, 0x92, 0xa4) : QColor(0x9c, 0xa3, 0xaf);
    const QColor cHoleBg  = dark ? QColor(0x34, 0x3d, 0x52) : QColor(0xff, 0xff, 0xff);
    const QColor cValueTxt= dark ? QColor(0xe0, 0xe7, 0xf1) : QColor(0x1f, 0x29, 0x37);

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
    scrollContent->setStyleSheet(
        QString("QWidget { background-color: %1; border: none; }").arg(bgPage)
        );

    QVBoxLayout* mainLayout = new QVBoxLayout(scrollContent);
    mainLayout->setContentsMargins(24, 20, 24, 16);
    mainLayout->setSpacing(14);

    QScrollArea* scroll = new QScrollArea(dialog);
    scroll->setWidget(scrollContent);
    scroll->setWidgetResizable(true);
    scroll->setFrameShape(QFrame::NoFrame);
    scroll->setStyleSheet(QString(
                              "QScrollArea { background-color: %1; border: none; }"
                              "QScrollBar:vertical { background: %1; width: 6px; border-radius: 3px; }"
                              "QScrollBar::handle:vertical { background: %2; border-radius: 3px; }"
                              "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height: 0px; }"
                              ).arg(bgScrollbar, bgScrollHandle));

    QVBoxLayout* dialogLayout = new QVBoxLayout(dialog);
    dialogLayout->setContentsMargins(0, 0, 0, 0);
    dialogLayout->setSpacing(0);
    dialogLayout->addWidget(scroll);

    //Header
    QLabel* titleLabel = new QLabel("Conference Statistics");
    titleLabel->setStyleSheet(QString(
                                  "font-size: 16px; font-weight: bold; color: %1; background: transparent;"
                                  ).arg(txtPrimary));

    QLabel* subLabel = new QLabel(
        QString::number(totalConferences) + " total  ·  " +
        QString::number(upcoming) + " upcoming  ·  " +
        QString::number(past) + " past  ·  Top location: " + topLocation
        );
    subLabel->setStyleSheet(QString(
                                "font-size: 10px; color: %1; background: transparent;"
                                ).arg(txtSub));

    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(subLabel);

    QFrame* div = new QFrame();
    div->setFrameShape(QFrame::HLine);
    div->setFixedHeight(1);
    div->setStyleSheet(QString("background-color: %1; border: none;").arg(divColor));
    mainLayout->addWidget(div);

    //Section label helper
    auto makeSection = [&](const QString& text) -> QLabel* {
        QLabel* sec = new QLabel(text.toUpper());
        sec->setStyleSheet(QString(
                               "font-size: 9px; font-weight: bold; color: %1;"
                               "background: transparent; letter-spacing: 1px; border: none;"
                               ).arg(txtSection));
        return sec;
    };

    //Bar chart helper
    auto makeBarChart = [&](const QList<QPair<QString,int>>& data,
                            const QColor& barColor,
                            int fixedHeight) -> QWidget*
    {
        QWidget* chart = new QWidget();
        chart->setFixedHeight(fixedHeight);
        chart->setAttribute(Qt::WA_StyledBackground, true);
        chart->setStyleSheet(QString(
                                 "QWidget { background-color: %1; border: 1px solid %2; border-radius: 10px; }"
                                 ).arg(bgCard, border));

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

            painter.setPen(barW > 30 ? cWhite : cValueTxt);
            painter.setFont(QFont("Arial", 9, QFont::Bold));
            painter.drawText(QRect(padLeft + 6, y, qMax(barW - 4, 40), barH),
                             Qt::AlignLeft | Qt::AlignVCenter,
                             QString::number(data[i].second));
        }

        painter.end();
        canvas->setPixmap(pixmap);
        return chart;
    };

    //Donut pie chart helper
    auto makePieChart = [&](const QList<QPair<QString,int>>& data,
                            int size) -> QWidget*
    {
        QWidget* container = new QWidget();
        container->setFixedHeight(size + 20);
        container->setAttribute(Qt::WA_StyledBackground, true);
        container->setStyleSheet(QString(
                                     "QWidget { background-color: %1; border: 1px solid %2; border-radius: 10px; }"
                                     ).arg(bgCard, border));

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

            painter.setPen(QPen(dark ? QColor(0x34,0x3d,0x52) : cWhite, 2));
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
        painter.setBrush(cHoleBg);
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

    //Stat pill helper
    auto makePill = [&](const QString& label,
                        const QString& value,
                        const QString& accentColor) -> QFrame*
    {
        QFrame* pill = new QFrame();
        pill->setAttribute(Qt::WA_StyledBackground, true);
        pill->setStyleSheet(QString(
                                "QFrame { background-color: %1; border: 1px solid %2; border-radius: 10px; }"
                                ).arg(bgCard, border));
        pill->setFixedHeight(64);

        QVBoxLayout* pl = new QVBoxLayout(pill);
        pl->setContentsMargins(14, 8, 14, 8);
        pl->setSpacing(2);

        QLabel* vl = new QLabel(value);
        vl->setStyleSheet(QString(
                              "font-size: 15px; font-weight: bold; color: %1;"
                              "background: transparent; border: none;"
                              ).arg(accentColor));

        QLabel* ll = new QLabel(label);
        ll->setStyleSheet(QString(
                              "font-size: 9px; color: %1; background: transparent; border: none;"
                              ).arg(txtSub));

        pl->addWidget(vl);
        pl->addWidget(ll);
        return pill;
    };

    // BUILD LAYOUT

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
        nextCard->setStyleSheet(QString(
                                    "QFrame { background-color: %1; border: 1px solid %2; border-radius: 10px; }"
                                    ).arg(bgCard, border));

        QHBoxLayout* nl = new QHBoxLayout(nextCard);
        nl->setContentsMargins(16, 0, 16, 0);

        QLabel* nt = new QLabel("📌  " + nextTitle);
        nt->setStyleSheet(QString(
                              "font-size: 10pt; font-weight: bold; color: %1;"
                              "background: transparent; border: none;"
                              ).arg(txtPrimary));

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

    //Close button
    QPushButton* closeBtn = new QPushButton("Close");
    closeBtn->setFixedWidth(100);
    closeBtn->setFixedHeight(36);
    closeBtn->setStyleSheet(QString(
                                "QPushButton { background-color: %1; color: %2;"
                                "border: 1px solid %3; border-radius: 8px;"
                                "font-size: 10pt; padding: 6px 20px; }"
                                "QPushButton:hover   { background-color: %4; }"
                                "QPushButton:pressed { background-color: %5; }"
                                ).arg(btnBg, btnTxt, border, btnHover, btnPressed));

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
    //Dark mode compatibility
    const bool dark = !mode;

    //Backgrounds
    const QString bgPage    = dark ? "#2a3142" : "#f6f8fc";
    const QString bgCard    = dark ? "#343d52" : "#ffffff";
    const QString bgNavBar  = dark ? "#2a3142" : "#f6f8fc";
    const QString bgInput   = dark ? "#343d52" : "#ffffff";
    const QString bgScrollbar= dark ? "#2a3142" : "#f6f8fc";
    const QString bgScrollHandle = dark ? "#545e73" : "#c0d0e8";
    const QString bgEventHit= dark ? "#0a3d3f" : "#e0f7f7";
    const QString bgFooter  = dark ? "#2a3142" : "#f6f8fc";
    const QString bgLightBg = dark ? "#3e4859" : "#f1f5f9";

    //Borders
    const QString border    = dark ? "#4a5568" : "#e2e8f0";
    const QString borderHit = "#30b9bf";

    //Text
    const QString txtPrimary = dark ? "#e0e7f1" : "#1f2937";
    const QString txtSub     = dark ? "#8892a4" : "#9ca3af";
    const QString txtSection = dark ? "#8892a4" : "#9ca3af";
    const QString txtLegend  = dark ? "#a0aec0" : "#4b5563";
    const QString txtEventHit= dark ? "#7ee8ec" : "#0a5a5f";
    const QString txtDisabled= dark ? "#4a5568" : "#d1d5db";
    const QString divColor   = dark ? "#3e4859" : "#e2e8f0";

    //Button
    const QString btnBg      = dark ? "#3e4859" : "#ffffff";
    const QString btnTxt     = dark ? "#e0e7f1" : "#1f2937";
    const QString btnHover   = dark ? "#4a5568" : "#f1f5f9";
    const QString btnPressed = dark ? "#545e73" : "#e2e8f0";

    //QColor for date formats
    const QColor cTeal    (0x30, 0xb9, 0xbf);
    const QColor cAmber   (0xfe, 0xf3, 0xc7);
    const QColor cAmberTx (0x92, 0x40, 0x0e);
    const QColor cDarkTeal(0x0a, 0x5a, 0x5f);
    const QColor cWhite   (0xff, 0xff, 0xff);
    //Dark mode variants for date highlights
    const QColor cAmberBgDk(0x45, 0x37, 0x10);

    //Fetch data
    QMap<QDate, QStringList> conferenceDates;
    QSqlQuery query("SELECT TITLE, CONF_DATE FROM CONFERENCE ORDER BY CONF_DATE");
    while (query.next())
        conferenceDates[query.value(1).toDate()].append(query.value(0).toString());

    //Dialog
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("Conference Calendar");
    dialog->setFixedSize(520, 520);
    dialog->setAttribute(Qt::WA_StyledBackground, true);

    //Scroll stuff
    QWidget* scrollContent = new QWidget();
    scrollContent->setAttribute(Qt::WA_StyledBackground, true);
    scrollContent->setStyleSheet(
        QString("QWidget { background-color: %1; border: none; }").arg(bgPage)
        );

    QVBoxLayout* mainLayout = new QVBoxLayout(scrollContent);
    mainLayout->setContentsMargins(24, 20, 24, 16);
    mainLayout->setSpacing(14);

    QScrollArea* scroll = new QScrollArea(dialog);
    scroll->setWidget(scrollContent);
    scroll->setWidgetResizable(true);
    scroll->setFrameShape(QFrame::NoFrame);
    scroll->setStyleSheet(QString(
                              "QScrollArea { background-color: %1; border: none; }"
                              "QScrollBar:vertical { background: %1; width: 6px; border-radius: 3px; }"
                              "QScrollBar::handle:vertical { background: %2; border-radius: 3px; }"
                              "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height: 0px; }"
                              ).arg(bgScrollbar, bgScrollHandle));

    QVBoxLayout* dialogLayout = new QVBoxLayout(dialog);
    dialogLayout->setContentsMargins(0, 0, 0, 0);
    dialogLayout->setSpacing(0);
    dialogLayout->addWidget(scroll);

    //Header
    QLabel* titleLabel = new QLabel("Conference Calendar");
    titleLabel->setStyleSheet(QString(
                                  "font-size: 16px; font-weight: bold; color: %1; background: transparent;"
                                  ).arg(txtPrimary));

    QLabel* subLabel = new QLabel(
        QString::number(conferenceDates.size()) + " scheduled conference(s)"
        );
    subLabel->setStyleSheet(QString(
                                "font-size: 10px; color: %1; background: transparent;"
                                ).arg(txtSub));

    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(subLabel);

    QFrame* div = new QFrame();
    div->setFrameShape(QFrame::HLine);
    div->setFixedHeight(1);
    div->setStyleSheet(QString("background-color: %1; border: none;").arg(divColor));
    mainLayout->addWidget(div);

    //Section helper
    auto makeSection = [&](const QString& text) -> QLabel* {
        QLabel* sec = new QLabel(text.toUpper());
        sec->setStyleSheet(QString(
                               "font-size: 9px; font-weight: bold; color: %1;"
                               "background: transparent; letter-spacing: 1px; border: none;"
                               ).arg(txtSection));
        return sec;
    };

    //Calendar card
    QFrame* calCard = new QFrame();
    calCard->setAttribute(Qt::WA_StyledBackground, true);
    calCard->setStyleSheet(QString(
                               "QFrame { background-color: %1; border: 1px solid %2; border-radius: 10px; }"
                               ).arg(bgCard, border));

    QVBoxLayout* calCardLayout = new QVBoxLayout(calCard);
    calCardLayout->setContentsMargins(8, 8, 8, 8);

    QCalendarWidget* calendar = new QCalendarWidget();
    calendar->setGridVisible(false);
    calendar->setNavigationBarVisible(true);
    calendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    calendar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    calendar->setStyleSheet(QString(R"(
        QCalendarWidget QWidget {
            background-color: %1;
            color: %2;
        }
        QCalendarWidget QWidget#qt_calendar_navigationbar {
            background-color: %3;
            border-bottom: 1px solid %4;
            padding: 4px 8px;
            border-radius: 8px 8px 0 0;
        }
        QCalendarWidget QToolButton {
            color: %2;
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
            background-color: %1;
            border: 1px solid %4;
            color: %2;
        }
        QCalendarWidget QSpinBox {
            color: %2;
            background-color: %5;
            border: 1px solid %4;
            border-radius: 4px;
            padding: 2px 4px;
            font-weight: bold;
        }
        QCalendarWidget QSpinBox::up-button,
        QCalendarWidget QSpinBox::down-button {
            background-color: %6;
            border: none;
        }
        QCalendarWidget QAbstractItemView {
            background-color: %1;
            color: %2;
            selection-background-color: #30b9bf;
            selection-color: #ffffff;
            outline: none;
            font-size: 10pt;
        }
        QCalendarWidget QAbstractItemView:disabled {
            color: %7;
        }
    )")
                                .arg(bgCard,
                                     txtPrimary,
                                     bgNavBar,
                                     border,
                                     bgInput,
                                     bgLightBg,
                                     txtDisabled
                                     ));

    //Date highlights
    QTextCharFormat conferenceFormat;
    conferenceFormat.setBackground(cTeal);
    conferenceFormat.setForeground(cWhite);
    conferenceFormat.setFontWeight(QFont::Bold);

    QTextCharFormat todayFormat;
    if (dark) {
        todayFormat.setBackground(cAmberBgDk);
        todayFormat.setForeground(QColor(0xfb, 0xbf, 0x24));
    } else {
        todayFormat.setBackground(cAmber);
        todayFormat.setForeground(cAmberTx);
    }
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

    //Event card
    mainLayout->addWidget(makeSection("Selected Date"));

    QFrame* eventCard = new QFrame();
    eventCard->setAttribute(Qt::WA_StyledBackground, true);
    eventCard->setFixedHeight(44);
    eventCard->setStyleSheet(QString(
                                 "QFrame { background-color: %1; border: 1px solid %2; border-radius: 8px; }"
                                 ).arg(bgCard, border));

    QHBoxLayout* eventLayout = new QHBoxLayout(eventCard);
    eventLayout->setContentsMargins(14, 0, 14, 0);

    QLabel* eventLabel = new QLabel("Click a highlighted date to see conferences.");
    eventLabel->setWordWrap(true);
    eventLabel->setAlignment(Qt::AlignVCenter);
    eventLabel->setStyleSheet(QString(
                                  "font-size: 10px; color: %1; background: transparent; border: none;"
                                  ).arg(txtSub));
    eventLayout->addWidget(eventLabel);
    mainLayout->addWidget(eventCard);

    //Legend card
    mainLayout->addWidget(makeSection("Legend"));

    QFrame* legendCard = new QFrame();
    legendCard->setAttribute(Qt::WA_StyledBackground, true);
    legendCard->setStyleSheet(QString(
                                  "QFrame { background-color: %1; border: 1px solid %2; border-radius: 8px; }"
                                  ).arg(bgCard, border));

    QHBoxLayout* legendLayout = new QHBoxLayout(legendCard);
    legendLayout->setContentsMargins(14, 10, 14, 10);
    legendLayout->setSpacing(20);

    auto makeLegendItem = [&](const QColor& bg, const QString& label) -> QWidget* {
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
        lbl->setStyleSheet(QString(
                               "font-size: 9px; color: %1; background: transparent; border: none;"
                               ).arg(txtLegend));

        il->addWidget(dot);
        il->addWidget(lbl);
        return item;
    };

    legendLayout->addWidget(makeLegendItem(cTeal,     "Conference"));
    legendLayout->addWidget(makeLegendItem(
        dark ? QColor(0x45, 0x37, 0x10) : cAmber, "Today"));
    legendLayout->addWidget(makeLegendItem(cDarkTeal, "Conference today"));
    legendLayout->addStretch();
    mainLayout->addWidget(legendCard);

    mainLayout->addStretch();

    //Date click handler
    connect(calendar, &QCalendarWidget::clicked, dialog, [=](const QDate& date) {
        if (conferenceDates.contains(date)) {
            eventLabel->setText("📌  " + conferenceDates[date].join("   •   "));
            eventCard->setStyleSheet(QString(
                                         "QFrame { background-color: %1; border: 1px solid #30b9bf; border-radius: 8px; }"
                                         ).arg(bgEventHit));
            eventLabel->setStyleSheet(QString(
                                          "font-size: 10px; color: %1; background: transparent; border: none;"
                                          ).arg(txtEventHit));
        } else {
            eventLabel->setText("No conferences on this day.");
            eventCard->setStyleSheet(QString(
                                         "QFrame { background-color: %1; border: 1px solid %2; border-radius: 8px; }"
                                         ).arg(bgCard, border));
            eventLabel->setStyleSheet(QString(
                                          "font-size: 10px; color: %1; background: transparent; border: none;"
                                          ).arg(txtSub));
        }
    });

    //Close button
    QPushButton* closeBtn = new QPushButton("Close");
    closeBtn->setFixedWidth(100);
    closeBtn->setFixedHeight(36);
    closeBtn->setStyleSheet(QString(
                                "QPushButton { background-color: %1; color: %2;"
                                "border: 1px solid %3; border-radius: 8px;"
                                "font-size: 10pt; padding: 6px 20px; }"
                                "QPushButton:hover   { background-color: %4; }"
                                "QPushButton:pressed { background-color: %5; }"
                                ).arg(btnBg, btnTxt, border, btnHover, btnPressed));

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
    //Dark mode compatible
    const bool dark = !mode;

    const QString bgPage     = dark ? "#2a3142" : "#f6f8fc";
    const QString txtPrimary = dark ? "#e0e7f1" : "#1f2937";
    const QString txtSub     = dark ? "#8892a4" : "#9ca3af";

    //Loading dialog
    QDialog* loadingDialog = new QDialog(this);
    loadingDialog->setWindowTitle("Loading Map...");
    loadingDialog->setFixedSize(320, 100);
    loadingDialog->setAttribute(Qt::WA_StyledBackground, true);
    loadingDialog->setStyleSheet(QString(
                                     "QDialog { background-color: %1; border: none; }"
                                     ).arg(bgPage));

    QVBoxLayout* ll = new QVBoxLayout(loadingDialog);
    ll->setContentsMargins(20, 16, 20, 16);
    ll->setSpacing(8);

    QLabel* loadingLabel = new QLabel("🌍  Geocoding location...");
    loadingLabel->setAlignment(Qt::AlignCenter);
    loadingLabel->setStyleSheet(QString(
                                    "font-size: 11px; font-weight: bold; color: %1; background: transparent;"
                                    ).arg(txtPrimary));

    QLabel* locLabel = new QLabel(location);
    locLabel->setAlignment(Qt::AlignCenter);
    locLabel->setStyleSheet(QString(
                                "font-size: 9px; color: %1; background: transparent;"
                                ).arg(txtSub));
    locLabel->setWordWrap(true);

    ll->addWidget(loadingLabel);
    ll->addWidget(locLabel);

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
        loadingDialog->deleteLater();

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

        //Tile layer based on mode
        QString tileLayer = dark
                                ? "https://{s}.basemaps.cartocdn.com/dark_all/{z}/{x}/{y}{r}.png"
                                : "https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png";
        QString tileAttrib = dark
                                 ? "© OpenStreetMap contributors © CARTO"
                                 : "© OpenStreetMap contributors";

        QString notFoundCss = found ? "" :
                                  "#notfound { position:fixed; top:60px; left:50%;"
                                  "transform:translateX(-50%);"
                                  "background:rgba(220,38,38,0.85);"
                                  "color:white; padding:8px 18px;"
                                  "border-radius:20px; font-size:12px; z-index:9999; }";

        QString notFoundHtml = found ? "" :
                                   "<div id='notfound'>⚠️ Location not found — showing approximate area</div>";

        QString latStr = QString::number(lat, 'f', 6);
        QString lonStr = QString::number(lon, 'f', 6);
        QString pinStyle =
            "width:22px;height:22px;"
            "background:#30b9bf;"
            "border:3px solid white;"
            "border-radius:50% 50% 50% 0;"
            "transform:rotate(-45deg);"
            "box-shadow:0 2px 8px rgba(0,0,0,0.35);";

        //Build HTML
        QString html =
            "<!DOCTYPE html><html><head>"
            "<meta charset='utf-8'/>"
            "<meta name='viewport' content='width=device-width,initial-scale=1.0'>"
            "<title>" + title.toHtmlEscaped() + "</title>"
                                      "<link rel='stylesheet' href='https://unpkg.com/leaflet@1.9.4/dist/leaflet.css'/>"
                                      "<script src='https://unpkg.com/leaflet@1.9.4/dist/leaflet.js'></script>"
                                      "<style>"
                                      "* { margin:0; padding:0; box-sizing:border-box; }"
                                      "body { font-family:Arial,sans-serif; }"
                                      "#topbar { background:#30b9bf; color:white; padding:10px 20px; height:48px;"
                                      "  display:flex; align-items:center; justify-content:space-between;"
                                      "  font-size:14px; font-weight:bold; }"
                                      "#topbar span { font-size:11px; opacity:0.85; font-weight:normal; }"
                                      "#map { height:calc(100vh - 48px); width:100%; }"
            + notFoundCss +
            "</style></head><body>"
            "<div id='topbar'>"
            "  <div>📍 " + title.toHtmlEscaped() + "</div>"
                                      "  <span>" + location.toHtmlEscaped() + "</span>"
                                         "</div>"
            + notFoundHtml +
            "<div id='map'></div>"
            "<script>"
            "var map = L.map('map',{zoomControl:true,scrollWheelZoom:true})"
            ".setView([" + latStr + "," + lonStr + "],14);"
                                      "L.tileLayer('" + tileLayer + "',{"
                          "  maxZoom:19, attribution:'" + tileAttrib + "'"
                           "}).addTo(map);"
                           "var icon=L.divIcon({"
                           "  html:'<div style=\"" + pinStyle + "\"></div>',"
                         "  iconSize:[22,22],iconAnchor:[11,22],className:''"
                         "});"
                         "L.marker([" + latStr + "," + lonStr + "],{icon:icon})"
                                      ".addTo(map)"
                                      ".bindPopup("
                                      "  '<div style=\"font-family:Arial;min-width:160px;\">"
                                      "  <b style=\"color:#30b9bf;font-size:14px;\">" + title.toHtmlEscaped() + "</b><br>"
                                      "  <span style=\"color:#6b7280;font-size:12px;\">📍 " + location.toHtmlEscaped() + "</span>"
                                         "  </div>',"
                                         "  {maxWidth:250}"
                                         ").openPopup();"
                                         "</script></body></html>";

        //Write to temp file and open in browser
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

//********************CONFERENCE END*************************************************************************************************************//

//********************Review Start*************************************//

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

void MainWindow::on_backHome_clicked(){   ui->stackedWidget->setCurrentIndex(0);}

void MainWindow::on_review_clicked(){ ui->stackedWidget->setCurrentIndex(1);}

void MainWindow::on_collab_clicked(){ ui->stackedWidget->setCurrentIndex(2);}

void MainWindow::on_profile_clicked(){ui->stackedWidget->setCurrentIndex(3);}

void MainWindow::on_reviewSub_clicked(){ui->stackedWidget->setCurrentIndex(5);}

void MainWindow::on_login_clicked()
{
    ui->sideBarStack->setCurrentIndex(0); //sideBar Toggle!!!
    ui->sideBarStack->show();
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_cancelBtnReg_clicked()
{
    ui->sideBarStack->setCurrentIndex(0); //sideBar Toggle!!!
    ui->sideBarStack->show();
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_cancelBtnFor_clicked()
{
    ui->sideBarStack->setCurrentIndex(0); //sideBar Toggle!!!
    ui->sideBarStack->show();
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_userSearchBackBTN_clicked()
{
    ui->sideBarStack->setCurrentIndex(0); //sideBar Toggle!!!
    ui->sideBarStack->show();
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_publication_clicked(){ ui->stackedWidget->setCurrentIndex(6);}

void MainWindow::on_Research_clicked(){ ui->stackedWidget->setCurrentIndex(7);}

void MainWindow::on_temp_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_temp2_clicked()
{
    ui->sideBarStack->setCurrentIndex(1);
    ui->sideBarStack->hide();
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_mkUser_clicked()
{
    ui->sideBarStack->setCurrentIndex(1);
    ui->sideBarStack->hide();
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_linkFor_linkActivated(){ui->stackedWidget->setCurrentIndex(10);}

void MainWindow::on_searchUserBTN_clicked()
{
    ui->sideBarStack->setCurrentIndex(1);
    ui->sideBarStack->hide();
    ui->stackedWidget->setCurrentIndex(11);
}


//New StyleSheet
void MainWindow::toggleDarkMode(){
    mode = !mode;

    if (mode)
        ui->modeSwitch->setIcon(QIcon("icons/sun.svg"));
    else
        ui->modeSwitch->setIcon(QIcon("icons/moon.svg"));

    if(mode){
        // ===== LIGHT MODE =====

        // Set palette for light mode
        QPalette lightPalette;
        lightPalette.setColor(QPalette::WindowText, QColor(0x1e, 0x29, 0x3b));
        lightPalette.setColor(QPalette::Text, QColor(0x0f, 0x17, 0x2a));
        this->setPalette(lightPalette);

        this->setStyleSheet(
            "* { font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, 'Helvetica Neue', Arial, sans-serif; }"

            "QMainWindow { background-color: #f6f8fc; }"

            "#sidebar { "
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "        stop:0 #ffffff, stop:1 #fafbfd);"
            "    border-right: 1px solid #e2e8f0;"
            "}"

            "#appTitle { "
            "    color: #30b9bf; font-size: 20pt; font-weight: 700;"
            "    padding: 20px 16px 12px 16px; background-color: transparent;"
            "    letter-spacing: -0.5px;"
            "}"

            "#homeNavButton, #myPageNavButton, #quitb {"
            "    text-align: left; padding: 12px 16px; margin: 4px 8px;"
            "    border-radius: 10px; background-color: transparent;"
            "    color: #475569; font-size: 11pt; font-weight: 500;"
            "    border: none;"
            "}"
            "#homeNavButton:hover, #myPageNavButton:hover {"
            "    background-color: #e0f7f8; color: #0f766e;"
            "}"
            "#homeNavButton:pressed, #myPageNavButton:pressed {"
            "    background-color: #b2f0f2;"
            "}"
            "#quitb { color: #64748b; margin-top: 12px; }"
            "#quitb:hover { background-color: #fee2e2; color: #dc2626; }"

            "#homeTopBar, #myPageTopBar { "
            "    background-color: #ffffff; padding: 20px 28px;"
            "    border-bottom: 1px solid #e2e8f0;"
            "}"
            "#homeTitle, #myPageTitle { "
            "    color: #0f172a; font-size: 22pt; font-weight: 700;"
            "    background-color: transparent; letter-spacing: -0.5px;"
            "}"

            "QPushButton { "
            "    background-color: #e0efff; color: #1e3a8a;"
            "    border: 1px solid #bfdbfe; border-radius: 10px;"
            "    padding: 10px 18px; font-size: 10pt; font-weight: 600;"
            "    min-height: 20px;"
            "}"
            "QPushButton:hover { "
            "    background-color: #dbeafe; border-color: #93c5fd;"
            "    color: #1e293b;"
            "}"
            "QPushButton:pressed { background-color: #bfdbfe; }"
            "QPushButton:disabled { "
            "    background-color: #f1f5f9; color: #cbd5e1;"
            "    border-color: #e2e8f0;"
            "}"

            "#Browse { "
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "        stop:0 #3dd4db, stop:1 #30b9bf);"
            "    color: white; border: none; border-radius: 12px;"
            "    padding: 12px 24px; font-weight: 700; font-size: 10pt;"
            "}"
            "#Browse:hover { background-color: #22d3dd; }"
            "#Browse:pressed { background-color: #26a0a6; }"

            "#secondaryButton { "
            "    background-color: rgba(48,185,191,0.08);"
            "    border: 1.5px solid #30b9bf; color: #0d9488;"
            "    border-radius: 10px; padding: 8px 18px;"
            "    font-size: 10pt; font-weight: 600;"
            "}"
            "#secondaryButton:hover { "
            "    background-color: #30b9bf; color: white;"
            "}"
            "#secondaryButton:pressed { background-color: #0f766e; }"

            "QLabel { color: #1e293b; background-color: transparent; }"
            "#sidebar QLabel { color: #475569; }"
            "#cardTitle { color: #0f172a; font-size: 14pt; font-weight: 700; background-color: transparent; }"
            "#cardAuthors { color: #64748b; font-size: 10pt; font-weight: 500; background-color: transparent; }"
            "#cardDate { color: #94a3b8; font-size: 9pt; background-color: transparent; }"

            "QLineEdit { "
            "    background-color: #ffffff !important; border: 1.5px solid #e2e8f0;"
            "    border-radius: 8px; padding: 10px 14px; color: #0f172a;"
            "    selection-background-color: #30b9bf; selection-color: white;"
            "    font-size: 10pt;"
            "}"
            "QLineEdit:focus { "
            "    border: 2px solid #30b9bf; padding: 9px 13px;"
            "    background-color: #fafbfc !important;"
            "}"
            "QLineEdit:hover { border-color: #cbd5e1; }"

            "QLineEdit#searchBar { "
            "    background-color: #f8fafc !important;"
            "    border: 1.5px solid #e2e8f0; border-radius: 24px;"
            "    padding: 12px 20px; color: #334155; font-size: 10pt;"
            "}"
            "QLineEdit#searchBar:focus { "
            "    border: 2px solid #30b9bf; padding: 11px 19px;"
            "    background-color: #ffffff !important;"
            "}"
            "QLineEdit#searchBar:hover { border-color: #cbd5e1; }"

            "QTextEdit, QPlainTextEdit { "
            "    background-color: #ffffff !important; border: 1.5px solid #e2e8f0;"
            "    border-radius: 8px; padding: 12px 14px; color: #0f172a;"
            "    selection-background-color: #30b9bf; selection-color: white;"
            "    font-size: 10pt; line-height: 1.6;"
            "}"
            "QTextEdit:focus, QPlainTextEdit:focus { "
            "    border: 2px solid #30b9bf; padding: 11px 13px;"
            "}"

            "QDateEdit, QSpinBox, QDoubleSpinBox { "
            "    background-color: #ffffff !important; border: 1.5px solid #e2e8f0;"
            "    border-radius: 8px; padding: 10px 14px; color: #0f172a;"
            "    font-size: 10pt;"
            "}"
            "QDateEdit:focus, QSpinBox:focus, QDoubleSpinBox:focus { "
            "    border: 2px solid #30b9bf; padding: 9px 13px;"
            "}"

            "QComboBox { "
            "    background-color: #ffffff !important; border: 1.5px solid #e2e8f0;"
            "    border-radius: 8px; padding: 10px 14px; color: #0f172a;"
            "    min-width: 100px; font-size: 10pt;"
            "}"
            "QComboBox:hover { border-color: #cbd5e1; }"
            "QComboBox:focus { border: 2px solid #30b9bf; padding: 9px 13px; }"
            "QComboBox::drop-down { "
            "    border: none; width: 30px; subcontrol-origin: padding;"
            "    subcontrol-position: right center; margin-right: 8px;"
            "}"
            "QComboBox::down-arrow { "
            "    image: none; width: 0; height: 0;"
            "    border-left: 5px solid transparent;"
            "    border-right: 5px solid transparent;"
            "    border-top: 6px solid #64748b;"
            "}"
            "QComboBox QAbstractItemView { "
            "    background-color: #ffffff; border: 1px solid #e2e8f0;"
            "    border-radius: 8px; padding: 6px;"
            "    selection-background-color: #30b9bf; selection-color: white;"
            "    outline: none; color: #0f172a;"
            "}"

            "QScrollArea QWidget {"
            "    background-color: #f6f8fc;"
            "}"

            "QScrollArea { background-color: #f6f8fc; border: none; }"
            "QScrollArea > QWidget { background-color: #f6f8fc; }"

            "QScrollBar:vertical { "
            "    background: transparent; width: 8px; margin: 4px;"
            "}"
            "QScrollBar::handle:vertical { "
            "    background: #cbd5e1; min-height: 30px; border-radius: 4px;"
            "}"
            "QScrollBar::handle:vertical:hover { background: #30b9bf; }"
            "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height: 0px; }"

            "QScrollBar:horizontal { "
            "    background: transparent; height: 8px; margin: 4px;"
            "}"
            "QScrollBar::handle:horizontal { "
            "    background: #cbd5e1; min-width: 30px; border-radius: 4px;"
            "}"
            "QScrollBar::handle:horizontal:hover { background: #30b9bf; }"
            "QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal { width: 0px; }"

            "QFrame { "
            "    background-color: #ffffff; border: 1px solid #e2e8f0;"
            "    border-radius: 12px;"
            "}"

            "QGroupBox { "
            "    background-color: #ffffff; border: 1.5px solid #e2e8f0;"
            "    border-radius: 12px; margin-top: 10px;"
            "    padding: 16px 16px 16px 16px;"
            "    color: #0f172a; font-weight: 600; font-size: 10pt;"
            "}"
            "QGroupBox::title { "
            "    subcontrol-origin: margin; subcontrol-position: top left;"
            "    padding: 4px 10px; background-color: #ffffff;"
            "    color: #30b9bf; font-weight: 700; font-size: 10pt;"
            "    border: 1.5px solid #e2e8f0; border-radius: 6px;"
            "    left: 10px; margin-top: 2px;"
            "}"

            "QGroupBox#FeatsGroup, QGroupBox#pubInfoGroup,"
            "QGroupBox#frame_4, QGroupBox#groupBox_3,"
            "QGroupBox#frame_6, QGroupBox#collaborationCreationFrame,"
            "QGroupBox#groupBox { "
            "    background-color: #ffffff; border: 1.5px solid #e2e8f0;"
            "    border-radius: 12px; margin-top: 10px;"
            "    padding: 16px;"
            "}"
            "QGroupBox#FeatsGroup::title, QGroupBox#pubInfoGroup::title,"
            "QGroupBox#frame_4::title, QGroupBox#groupBox_3::title,"
            "QGroupBox#frame_6::title, QGroupBox#collaborationCreationFrame::title,"
            "QGroupBox#groupBox::title { "
            "    subcontrol-origin: margin; subcontrol-position: top left;"
            "    padding: 4px 10px; background-color: #ffffff;"
            "    color: #30b9bf; font-weight: 700; font-size: 10pt;"
            "    border: 1.5px solid #e2e8f0; border-radius: 6px;"
            "    left: 10px; margin-top: 2px;"
            "}"
            "QGroupBox#FeatsGroup QLabel, QGroupBox#pubInfoGroup QLabel,"
            "QGroupBox#frame_4 QLabel, QGroupBox#groupBox_3 QLabel,"
            "QGroupBox#frame_6 QLabel, QGroupBox#collaborationCreationFrame QLabel {"
            "    color: #334155;"
            "}"

            "QTabWidget::pane { "
            "    border: 1px solid #e2e8f0; background-color: #ffffff;"
            "    border-radius: 12px; margin-top: -1px;"
            "}"
            "QTabBar::tab { "
            "    background-color: transparent; color: #64748b;"
            "    border: none; border-bottom: 3px solid transparent;"
            "    padding: 14px 24px; font-weight: 600; font-size: 10pt;"
            "    margin-right: 4px;"
            "}"
            "QTabBar::tab:selected { "
            "    color: #0f172a; border-bottom: 3px solid #30b9bf;"
            "}"
            "QTabBar::tab:hover { color: #30b9bf; }"

            "#publicationCard { "
            "    background-color: #ffffff; border-radius: 12px;"
            "    border: 1px solid #e2e8f0;"
            "}"
            "#publicationCard:hover { "
            "    border: 1px solid #30b9bf; background-color: #fafcfd;"
            "}"

            "QCheckBox, QRadioButton { spacing: 10px; color: #334155; font-size: 10pt; }"
            "QCheckBox::indicator, QRadioButton::indicator { "
            "    width: 20px; height: 20px; border: 2px solid #cbd5e1;"
            "    border-radius: 6px; background-color: #ffffff;"
            "}"
            "QCheckBox::indicator:checked { "
            "    background-color: #30b9bf; border: 2px solid #30b9bf;"
            "}"
            "QCheckBox::indicator:hover, QRadioButton::indicator:hover { "
            "    border: 2px solid #30b9bf;"
            "}"
            "QRadioButton::indicator { border-radius: 11px; }"
            "QRadioButton::indicator:checked { "
            "    background-color: #ffffff; border: 6px solid #30b9bf;"
            "}"

            "QProgressBar { "
            "    border: none; border-radius: 8px; text-align: center;"
            "    background-color: #e2e8f0; color: #64748b;"
            "    font-weight: 600; height: 8px;"
            "}"
            "QProgressBar::chunk { "
            "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
            "        stop:0 #30b9bf, stop:1 #14b8a6);"
            "    border-radius: 8px;"
            "}"

            "QTableView, QListView, QTreeView { "
            "    background-color: #ffffff; border: 1px solid #e2e8f0;"
            "    border-radius: 12px; gridline-color: #f1f5f9;"
            "    selection-background-color: #30b9bf; selection-color: white;"
            "    color: #334155; outline: none; font-size: 10pt;"
            "    alternate-background-color: #fafbfc;"
            "}"
            "QTableView::item:hover, QListView::item:hover, QTreeView::item:hover { "
            "    background-color: #f0fafa;"
            "}"
            "QHeaderView::section { "
            "    background-color: #f8fafc; padding: 12px; border: none;"
            "    border-right: 1px solid #e2e8f0; border-bottom: 1px solid #e2e8f0;"
            "    color: #475569; font-weight: 700; font-size: 9pt;"
            "    text-transform: uppercase; letter-spacing: 0.5px;"
            "}"

            "QMenuBar { "
            "    background-color: #ffffff; border-bottom: 1px solid #e2e8f0;"
            "    color: #334155; padding: 4px;"
            "}"
            "QMenuBar::item { padding: 8px 16px; border-radius: 6px; }"
            "QMenuBar::item:selected { background-color: #f1f5f9; }"
            "QMenu { "
            "    background-color: #ffffff; border: 1px solid #e2e8f0;"
            "    border-radius: 10px; padding: 6px; color: #334155;"
            "}"
            "QMenu::item { "
            "    padding: 10px 24px; border-radius: 6px; margin: 2px;"
            "}"
            "QMenu::item:selected { "
            "    background-color: #30b9bf; color: white;"
            "}"

            "QStatusBar { "
            "    background-color: #ffffff; border-top: 1px solid #e2e8f0;"
            "    color: #64748b; font-size: 9pt;"
            "}"

            "QToolTip { "
            "    background-color: #0f172a; color: #f8fafc;"
            "    border: 1px solid #30b9bf; padding: 8px 12px;"
            "    border-radius: 8px; font-size: 9pt;"
            "}"

            ".statusAccepted { "
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "        stop:0 #d1fae5, stop:1 #a7f3d0);"
            "    color: #065f46; border: 1.5px solid #86efac;"
            "    border-radius: 14px; padding: 6px 14px;"
            "    font-size: 9pt; font-weight: 700;"
            "}"
            ".statusReview { "
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "        stop:0 #fef3c7, stop:1 #fde68a);"
            "    color: #92400e; border: 1.5px solid #fcd34d;"
            "    border-radius: 14px; padding: 6px 14px;"
            "    font-size: 9pt; font-weight: 700;"
            "}"
            ".statusRejected { "
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "        stop:0 #fee2e2, stop:1 #fecaca);"
            "    color: #991b1b; border: 1.5px solid #fca5a5;"
            "    border-radius: 14px; padding: 6px 14px;"
            "    font-size: 9pt; font-weight: 700;"
            "}"
            );

    } else {
        // ===== DARK MODE =====

        //Set palette for dark mode
        QPalette darkPalette;
        darkPalette.setColor(QPalette::WindowText, QColor(0xe2, 0xe8, 0xf0));
        darkPalette.setColor(QPalette::Text, QColor(0xf1, 0xf5, 0xf9));
        darkPalette.setColor(QPalette::ButtonText, QColor(0xcb, 0xd5, 0xe1));
        this->setPalette(darkPalette);

        this->setStyleSheet(
            "* { font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, 'Helvetica Neue', Arial, sans-serif; }"

            "QMainWindow { background-color: #1a1f2e; }"

            "#sidebar { "
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "        stop:0 #252b3d, stop:1 #1e2433);"
            "    border-right: 1px solid #2d3548;"
            "}"

            "#appTitle { "
            "    color: #30b9bf; font-size: 20pt; font-weight: 700;"
            "    padding: 20px 16px 12px 16px; background-color: transparent;"
            "    letter-spacing: -0.5px;"
            "}"

            "#homeNavButton, #myPageNavButton, #quitb {"
            "    text-align: left; padding: 12px 16px; margin: 4px 8px;"
            "    border-radius: 10px; background-color: transparent;"
            "    color: #a0aec0; font-size: 11pt; font-weight: 500;"
            "    border: none;"
            "}"
            "#homeNavButton:hover, #myPageNavButton:hover {"
            "    background-color: rgba(48,185,191,0.15); color: #7ee8ec;"
            "}"
            "#homeNavButton:pressed, #myPageNavButton:pressed {"
            "    background-color: rgba(48,185,191,0.25);"
            "}"
            "#quitb { color: #8892a4; margin-top: 12px; }"
            "#quitb:hover { background-color: rgba(239,68,68,0.15); color: #f87171; }"

            "#homeTopBar, #myPageTopBar { "
            "    background-color: #1e2433; padding: 20px 28px;"
            "    border-bottom: 1px solid #2d3548;"
            "}"
            "#homeTitle, #myPageTitle { "
            "    color: #f1f5f9; font-size: 22pt; font-weight: 700;"
            "    background-color: transparent; letter-spacing: -0.5px;"
            "}"

            "QPushButton { "
            "    background-color: #2a3142; color: #cbd5e1;"
            "    border: 1px solid #3e4859; border-radius: 10px;"
            "    padding: 10px 18px; font-size: 10pt; font-weight: 600;"
            "    min-height: 20px;"
            "}"
            "QPushButton:hover { "
            "    background-color: #343d52; border-color: #4a5568;"
            "    color: #f1f5f9;"
            "}"
            "QPushButton:pressed { background-color: #3e4859; }"
            "QPushButton:disabled { "
            "    background-color: #1e2433; color: #475569;"
            "    border-color: #2d3548;"
            "}"

            "#Browse { "
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "        stop:0 #3dd4db, stop:1 #30b9bf);"
            "    color: white; border: none; border-radius: 12px;"
            "    padding: 12px 24px; font-weight: 700; font-size: 10pt;"
            "}"
            "#Browse:hover { background-color: #22d3dd; }"
            "#Browse:pressed { background-color: #26a0a6; }"

            "#secondaryButton { "
            "    background-color: rgba(48,185,191,0.1);"
            "    border: 1.5px solid #30b9bf; color: #5eead4;"
            "    border-radius: 10px; padding: 8px 18px;"
            "    font-size: 10pt; font-weight: 600;"
            "}"
            "#secondaryButton:hover { "
            "    background-color: #30b9bf; color: white;"
            "}"
            "#secondaryButton:pressed { background-color: #0f766e; }"

            "QLabel { color: #e2e8f0; background-color: transparent; }"
            "#sidebar QLabel { color: #a0aec0; }"
            "#cardTitle { color: #f1f5f9; font-size: 14pt; font-weight: 700; background-color: transparent; }"
            "#cardAuthors { color: #94a3b8; font-size: 10pt; font-weight: 500; background-color: transparent; }"
            "#cardDate { color: #64748b; font-size: 9pt; background-color: transparent; }"

            "QLineEdit { "
            "    background-color: #252b3d !important; border: 1.5px solid #3e4859;"
            "    border-radius: 8px; padding: 10px 14px; color: #f1f5f9;"
            "    selection-background-color: #30b9bf; selection-color: white;"
            "    font-size: 10pt;"
            "}"
            "QLineEdit:focus { "
            "    border: 2px solid #30b9bf; padding: 9px 13px;"
            "    background-color: #2a3142 !important;"
            "}"
            "QLineEdit:hover { border-color: #4a5568; }"

            "QLineEdit#searchBar { "
            "    background-color: #1e2433 !important;"
            "    border: 1.5px solid #3e4859; border-radius: 24px;"
            "    padding: 12px 20px; color: #cbd5e1; font-size: 10pt;"
            "}"
            "QLineEdit#searchBar:focus { "
            "    border: 2px solid #30b9bf; padding: 11px 19px;"
            "    background-color: #252b3d !important;"
            "}"
            "QLineEdit#searchBar:hover { border-color: #4a5568; }"

            "QTextEdit, QPlainTextEdit { "
            "    background-color: #252b3d !important; border: 1.5px solid #3e4859;"
            "    border-radius: 8px; padding: 12px 14px; color: #f1f5f9;"
            "    selection-background-color: #30b9bf; selection-color: white;"
            "    font-size: 10pt; line-height: 1.6;"
            "}"
            "QTextEdit:focus, QPlainTextEdit:focus { "
            "    border: 2px solid #30b9bf; padding: 11px 13px;"
            "}"

            "QDateEdit, QSpinBox, QDoubleSpinBox { "
            "    background-color: #252b3d !important; border: 1.5px solid #3e4859;"
            "    border-radius: 8px; padding: 10px 14px; color: #f1f5f9;"
            "    font-size: 10pt;"
            "}"
            "QDateEdit:focus, QSpinBox:focus, QDoubleSpinBox:focus { "
            "    border: 2px solid #30b9bf; padding: 9px 13px;"
            "}"

            "QComboBox { "
            "    background-color: #252b3d !important; border: 1.5px solid #3e4859;"
            "    border-radius: 8px; padding: 10px 14px; color: #f1f5f9;"
            "    min-width: 100px; font-size: 10pt;"
            "}"
            "QComboBox:hover { border-color: #4a5568; }"
            "QComboBox:focus { border: 2px solid #30b9bf; padding: 9px 13px; }"
            "QComboBox::drop-down { "
            "    border: none; width: 30px; subcontrol-origin: padding;"
            "    subcontrol-position: right center; margin-right: 8px;"
            "}"
            "QComboBox::down-arrow { "
            "    image: none; width: 0; height: 0;"
            "    border-left: 5px solid transparent;"
            "    border-right: 5px solid transparent;"
            "    border-top: 6px solid #8892a4;"
            "}"
            "QComboBox QAbstractItemView { "
            "    background-color: #252b3d; border: 1px solid #3e4859;"
            "    border-radius: 8px; padding: 6px;"
            "    selection-background-color: #30b9bf; selection-color: white;"
            "    outline: none; color: #f1f5f9;"
            "}"

            "QScrollArea { background-color: #1a1f2e; border: none; }"
            "QScrollArea > QWidget { background-color: #1a1f2e; }"

            "QScrollBar:vertical { "
            "    background: transparent; width: 8px; margin: 4px;"
            "}"
            "QScrollBar::handle:vertical { "
            "    background: #3e4859; min-height: 30px; border-radius: 4px;"
            "}"
            "QScrollBar::handle:vertical:hover { background: #30b9bf; }"
            "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height: 0px; }"

            "QScrollBar:horizontal { "
            "    background: transparent; height: 8px; margin: 4px;"
            "}"
            "QScrollBar::handle:horizontal { "
            "    background: #3e4859; min-width: 30px; border-radius: 4px;"
            "}"
            "QScrollBar::handle:horizontal:hover { background: #30b9bf; }"
            "QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal { width: 0px; }"

            "QFrame { "
            "    background-color: #252b3d; border: 1px solid #3e4859;"
            "    border-radius: 12px;"
            "}"

            "QGroupBox { "
            "    background-color: #252b3d; border: 1.5px solid #3e4859;"
            "    border-radius: 12px; margin-top: 10px;"
            "    padding: 16px 16px 16px 16px;"
            "    color: #f1f5f9; font-weight: 600; font-size: 10pt;"
            "}"
            "QGroupBox::title { "
            "    subcontrol-origin: margin; subcontrol-position: top left;"
            "    padding: 4px 10px; background-color: #252b3d;"
            "    color: #30b9bf; font-weight: 700; font-size: 10pt;"
            "    border: 1.5px solid #3e4859; border-radius: 6px;"
            "    left: 10px; margin-top: 2px;"
            "}"

            "QGroupBox#FeatsGroup, QGroupBox#pubInfoGroup,"
            "QGroupBox#frame_4, QGroupBox#groupBox_3,"
            "QGroupBox#frame_6, QGroupBox#collaborationCreationFrame,"
            "QGroupBox#groupBox { "
            "    background-color: #252b3d; border: 1.5px solid #3e4859;"
            "    border-radius: 12px; margin-top: 10px;"
            "    padding: 16px;"
            "}"
            "QGroupBox#FeatsGroup::title, QGroupBox#pubInfoGroup::title,"
            "QGroupBox#frame_4::title, QGroupBox#groupBox_3::title,"
            "QGroupBox#frame_6::title, QGroupBox#collaborationCreationFrame::title,"
            "QGroupBox#groupBox::title { "
            "    subcontrol-origin: margin; subcontrol-position: top left;"
            "    padding: 4px 10px; background-color: #252b3d;"
            "    color: #30b9bf; font-weight: 700; font-size: 10pt;"
            "    border: 1.5px solid #3e4859; border-radius: 6px;"
            "    left: 10px; margin-top: 2px;"
            "}"
            "QGroupBox#FeatsGroup QLabel, QGroupBox#pubInfoGroup QLabel,"
            "QGroupBox#frame_4 QLabel, QGroupBox#groupBox_3 QLabel,"
            "QGroupBox#frame_6 QLabel, QGroupBox#collaborationCreationFrame QLabel {"
            "    color: #cbd5e1;"
            "}"

            "QScrollArea QWidget {"
            "    background-color: #1a1f2e;"
            "}"

            "QTabWidget::pane { "
            "    border: 1px solid #3e4859; background-color: #252b3d;"
            "    border-radius: 12px; margin-top: -1px;"
            "}"
            "QTabBar::tab { "
            "    background-color: transparent; color: #64748b;"
            "    border: none; border-bottom: 3px solid transparent;"
            "    padding: 14px 24px; font-weight: 600; font-size: 10pt;"
            "    margin-right: 4px;"
            "}"
            "QTabBar::tab:selected { "
            "    color: #f1f5f9; border-bottom: 3px solid #30b9bf;"
            "}"
            "QTabBar::tab:hover { color: #7ee8ec; }"

            "#publicationCard { "
            "    background-color: #252b3d; border-radius: 12px;"
            "    border: 1px solid #3e4859;"
            "}"
            "#publicationCard:hover { "
            "    border: 1px solid #30b9bf; background-color: #2a3142;"
            "}"

            "QCheckBox, QRadioButton { spacing: 10px; color: #cbd5e1; font-size: 10pt; }"
            "QCheckBox::indicator, QRadioButton::indicator { "
            "    width: 20px; height: 20px; border: 2px solid #4a5568;"
            "    border-radius: 6px; background-color: #252b3d;"
            "}"
            "QCheckBox::indicator:checked { "
            "    background-color: #30b9bf; border: 2px solid #30b9bf;"
            "}"
            "QCheckBox::indicator:hover, QRadioButton::indicator:hover { "
            "    border: 2px solid #30b9bf;"
            "}"
            "QRadioButton::indicator { border-radius: 11px; }"
            "QRadioButton::indicator:checked { "
            "    background-color: #252b3d; border: 6px solid #30b9bf;"
            "}"

            "QProgressBar { "
            "    border: none; border-radius: 8px; text-align: center;"
            "    background-color: #3e4859; color: #8892a4;"
            "    font-weight: 600; height: 8px;"
            "}"
            "QProgressBar::chunk { "
            "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
            "        stop:0 #30b9bf, stop:1 #14b8a6);"
            "    border-radius: 8px;"
            "}"

            "QTableView, QListView, QTreeView { "
            "    background-color: #252b3d; border: 1px solid #3e4859;"
            "    border-radius: 12px; gridline-color: #2a3142;"
            "    selection-background-color: #30b9bf; selection-color: white;"
            "    color: #cbd5e1; outline: none; font-size: 10pt;"
            "    alternate-background-color: #1e2433;"
            "}"
            "QTableView::item:hover, QListView::item:hover, QTreeView::item:hover { "
            "    background-color: #2a3142;"
            "}"
            "QHeaderView::section { "
            "    background-color: #1e2433; padding: 12px; border: none;"
            "    border-right: 1px solid #3e4859; border-bottom: 1px solid #3e4859;"
            "    color: #94a3b8; font-weight: 700; font-size: 9pt;"
            "    text-transform: uppercase; letter-spacing: 0.5px;"
            "}"

            "QMenuBar { "
            "    background-color: #1e2433; border-bottom: 1px solid #2d3548;"
            "    color: #cbd5e1; padding: 4px;"
            "}"
            "QMenuBar::item { padding: 8px 16px; border-radius: 6px; }"
            "QMenuBar::item:selected { background-color: #2a3142; }"
            "QMenu { "
            "    background-color: #252b3d; border: 1px solid #3e4859;"
            "    border-radius: 10px; padding: 6px; color: #cbd5e1;"
            "}"
            "QMenu::item { "
            "    padding: 10px 24px; border-radius: 6px; margin: 2px;"
            "}"
            "QMenu::item:selected { "
            "    background-color: #30b9bf; color: white;"
            "}"

            "QStatusBar { "
            "    background-color: #1e2433; border-top: 1px solid #2d3548;"
            "    color: #8892a4; font-size: 9pt;"
            "}"

            "QToolTip { "
            "    background-color: #0f172a; color: #f8fafc;"
            "    border: 1px solid #30b9bf; padding: 8px 12px;"
            "    border-radius: 8px; font-size: 9pt;"
            "}"

            ".statusAccepted { "
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "        stop:0 #065f46, stop:1 #064e3b);"
            "    color: #6ee7b7; border: 1.5px solid #047857;"
            "    border-radius: 14px; padding: 6px 14px;"
            "    font-size: 9pt; font-weight: 700;"
            "}"
            ".statusReview { "
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "        stop:0 #92400e, stop:1 #78350f);"
            "    color: #fcd34d; border: 1.5px solid #b45309;"
            "    border-radius: 14px; padding: 6px 14px;"
            "    font-size: 9pt; font-weight: 700;"
            "}"
            ".statusRejected { "
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "        stop:0 #991b1b, stop:1 #7f1d1d);"
            "    color: #fca5a5; border: 1.5px solid #b91c1c;"
            "    border-radius: 14px; padding: 6px 14px;"
            "    font-size: 9pt; font-weight: 700;"
            "}"
            );
    }
}
