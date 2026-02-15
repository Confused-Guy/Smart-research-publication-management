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

void MainWindow::loadConferences(bool ascending, QString searchFilter)
{
    // Clear old cards
    QLayoutItem* item;
    while ((item = ui->conferenceLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

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
            del.prepare("DELETE FROM CONFERENCE WHERE ID=:id");
            del.bindValue(":id", id);
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
                ui->descriptionEdit->setPlainText(q.value(5).toString());
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
                    q.value(3).toDouble(),
                    q.value(4).toString()
                    );
            }
        });
    }

    // Show a "no results" label if search returned nothing
    if (!anyResults) {
        QLabel* noResults = new QLabel("No conferences found.");
        noResults->setAlignment(Qt::AlignCenter);
        ui->conferenceLayout->addWidget(noResults);
    }

    ui->conferenceLayout->addStretch();
}

//CALENDAR
void MainWindow::on_viewCalendarBtn_clicked()
{
    showConferenceCalendar();
}

void MainWindow::on_saveButton_clicked()
{
    Conference c(
        editingConferenceId,
        ui->cTitleEdit->text(),
        1,
        ui->dateEdit->date(),
        ui->locationEdit->text(),
        ui->priceSpin->text().toDouble(),
        ui->descriptionEdit->toPlainText()
        );

    bool success = false;

    if (editingConferenceId == -1)
        success = c.add();
    else
        success = c.update();

    if (success) {
        qDebug() << (editingConferenceId == -1 ? "Added!" : "Updated!");
        editingConferenceId = -1;
        loadConferences(sortAscending, "");
        ui->stackedWidget->setCurrentIndex(4);
    } else {
        qDebug() << "Failed!";
    }
}

void MainWindow::showConferenceCalendar()
{
    QMap<QDate, QStringList> conferenceDates;
    QSqlQuery query("SELECT TITLE, CONF_DATE FROM CONFERENCE ORDER BY CONF_DATE");
    while (query.next()) {
        conferenceDates[query.value(1).toDate()].append(query.value(0).toString());
    }

    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("Conference Calendar");
    dialog->setFixedSize(520, 480);
    dialog->setStyleSheet("background-color: #f6f8fc;");

    QVBoxLayout* mainLayout = new QVBoxLayout(dialog);
    mainLayout->setContentsMargins(20, 20, 20, 16);
    mainLayout->setSpacing(12);

    // --- Title ---
    QLabel* titleLabel = new QLabel("Conference Calendar");
    titleLabel->setStyleSheet("font-size: 15px; font-weight: bold; color: #1f2937;");

    QLabel* subLabel = new QLabel(QString::number(conferenceDates.size()) + " scheduled conference(s)");
    subLabel->setStyleSheet("font-size: 10px; color: #9ca3af;");

    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(subLabel);

    // --- Calendar ---
    QCalendarWidget* calendar = new QCalendarWidget();
    calendar->setGridVisible(false);
    calendar->setNavigationBarVisible(true);
    calendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    calendar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    calendar->setStyleSheet(R"(
        QCalendarWidget {
            border: 1px solid #e2e8f0;
            border-radius: 10px;
            background-color: #ffffff;
        }
        QCalendarWidget QWidget#qt_calendar_navigationbar {
            background-color: #ffffff;
            border-bottom: 1px solid #e2e8f0;
            padding: 4px 8px;
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
        }
        QCalendarWidget QMenu {
            background-color: #ffffff;
            border: 1px solid #e2e8f0;
            color: #1f2937;
        }
        QCalendarWidget QSpinBox {
            color: #1f2937;
            background-color: transparent;
            border: none;
            font-weight: bold;
            font-size: 11pt;
        }
        QCalendarWidget QAbstractItemView {
            background-color: #ffffff;
            color: #1f2937;
            selection-background-color: #30b9bf;
            selection-color: white;
            outline: none;
            font-size: 10pt;
        }
        QCalendarWidget QAbstractItemView:disabled {
            color: #d1d5db;
        }
    )");

    // Highlight conference dates
    QTextCharFormat conferenceFormat;
    conferenceFormat.setBackground(QColor("#30b9bf"));
    conferenceFormat.setForeground(QColor("#ffffff"));
    conferenceFormat.setFontWeight(QFont::Bold);

    // Today
    QTextCharFormat todayFormat;
    todayFormat.setBackground(QColor("#fef3c7"));
    todayFormat.setForeground(QColor("#92400e"));
    todayFormat.setFontWeight(QFont::Bold);
    calendar->setDateTextFormat(QDate::currentDate(), todayFormat);

    for (auto it = conferenceDates.begin(); it != conferenceDates.end(); ++it) {
        if (it.key() == QDate::currentDate()) {
            QTextCharFormat bothFormat;
            bothFormat.setBackground(QColor("#0a5a5f"));
            bothFormat.setForeground(QColor("#ffffff"));
            bothFormat.setFontWeight(QFont::Bold);
            calendar->setDateTextFormat(it.key(), bothFormat);
        } else {
            calendar->setDateTextFormat(it.key(), conferenceFormat);
        }
    }

    mainLayout->addWidget(calendar);

    // --- Event label shown below calendar on click ---
    QLabel* eventLabel = new QLabel("Click a highlighted date to see conferences.");
    eventLabel->setWordWrap(true);
    eventLabel->setFixedHeight(36);
    eventLabel->setAlignment(Qt::AlignCenter);
    eventLabel->setStyleSheet(
        "font-size: 10px; color: #6b7280;"
        "background: #ffffff; border: 1px solid #e2e8f0;"
        "border-radius: 8px; padding: 6px 12px;"
        );
    mainLayout->addWidget(eventLabel);

    connect(calendar, &QCalendarWidget::clicked, this, [=](const QDate& date) {
        if (conferenceDates.contains(date)) {
            QString text = "📌  " + conferenceDates[date].join("   •   ");
            eventLabel->setText(text);
            eventLabel->setStyleSheet(
                "font-size: 10px; color: #0a5a5f;"
                "background: #e0f7f7; border: 1px solid #30b9bf;"
                "border-radius: 8px; padding: 6px 12px;"
                );
        } else {
            eventLabel->setText("No conferences on this day.");
            eventLabel->setStyleSheet(
                "font-size: 10px; color: #6b7280;"
                "background: #ffffff; border: 1px solid #e2e8f0;"
                "border-radius: 8px; padding: 6px 12px;"
                );
        }
    });

    // --- Close button ---
    QPushButton* closeBtn = new QPushButton("Close");
    closeBtn->setFixedHeight(36);
    closeBtn->setStyleSheet(
        "QPushButton {"
        "    background-color: #ffffff;"
        "    color: #1f2937;"
        "    border: 1px solid #e2e8f0;"
        "    border-radius: 8px;"
        "    font-size: 10pt;"
        "    padding: 0 20px;"
        "}"
        "QPushButton:hover { background-color: #f1f5f9; }"
        "QPushButton:pressed { background-color: #e2e8f0; }"
        );

    // Use QDialog::done() directly to guarantee it closes
    connect(closeBtn, &QPushButton::clicked, dialog, [dialog]() {
        dialog->done(QDialog::Accepted);
    });

    QHBoxLayout* footerLayout = new QHBoxLayout();
    footerLayout->addStretch();
    footerLayout->addWidget(closeBtn);
    mainLayout->addLayout(footerLayout);

    dialog->exec();
}

void MainWindow::showConferenceMap(const QString& location, const QString& title)
{
    // Show a small dialog asking which map service to use
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("Open Map — " + title);
    dialog->setFixedSize(360, 200);

    QVBoxLayout* layout = new QVBoxLayout(dialog);

    QLabel* titleLabel = new QLabel("<b style='font-size:13px;'>" + title + "</b>");
    QLabel* locLabel   = new QLabel("<span style='color:#555;'>" + location + "</span>");
    QLabel* promptLabel = new QLabel("Choose a map service to open in your browser:");
    promptLabel->setWordWrap(true);

    QHBoxLayout* btnLayout = new QHBoxLayout();

    QPushButton* googleBtn = new QPushButton("Google Maps");
    QPushButton* osmBtn    = new QPushButton("OpenStreetMap");
    QPushButton* cancelBtn = new QPushButton("Cancel");

    btnLayout->addWidget(googleBtn);
    btnLayout->addWidget(osmBtn);
    btnLayout->addWidget(cancelBtn);

    layout->addWidget(titleLabel);
    layout->addWidget(locLabel);
    layout->addSpacing(8);
    layout->addWidget(promptLabel);
    layout->addLayout(btnLayout);

    // Google Maps URL
    connect(googleBtn, &QPushButton::clicked, this, [=]() {
        QString encoded = QUrl::toPercentEncoding(location);
        QUrl url("https://www.google.com/maps/search/?api=1&query=" + encoded);
        QDesktopServices::openUrl(url);
        dialog->accept();
    });

    // OpenStreetMap URL
    connect(osmBtn, &QPushButton::clicked, this, [=]() {
        QString encoded = QUrl::toPercentEncoding(location);
        QUrl url("https://www.openstreetmap.org/search?query=" + encoded);
        QDesktopServices::openUrl(url);
        dialog->accept();
    });

    connect(cancelBtn, &QPushButton::clicked, dialog, &QDialog::reject);

    dialog->exec();
}

void MainWindow::exportConferencePDF(int id, const QString& title, const QDate& date,
                                     const QString& location, double price,
                                     const QString& description)
{
    // Ask user where to save
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
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageMargins(QMarginsF(20, 20, 20, 20), QPageLayout::Millimeter);

    // Build the HTML content for the PDF
    QString html = QString(R"(
        <html>
        <head>
            <style>
                body {
                    font-family: Arial, sans-serif;
                    color: #1a1a2e;
                    margin: 0;
                    padding: 0;
                }
                .header {
                    background-color: #30b9bf;
                    color: white;
                    padding: 24px 32px;
                    border-radius: 0 0 12px 12px;
                }
                .header h1 {
                    margin: 0 0 4px 0;
                    font-size: 26px;
                }
                .header p {
                    margin: 0;
                    font-size: 13px;
                    opacity: 0.85;
                }
                .section {
                    padding: 24px 32px;
                }
                .section h2 {
                    color: #30b9bf;
                    font-size: 15px;
                    text-transform: uppercase;
                    letter-spacing: 1px;
                    border-bottom: 2px solid #30b9bf;
                    padding-bottom: 6px;
                    margin-bottom: 16px;
                }
                .info-grid {
                    width: 100%;
                    border-collapse: collapse;
                    margin-bottom: 16px;
                }
                .info-grid td {
                    padding: 10px 14px;
                    font-size: 13px;
                    vertical-align: top;
                }
                .info-grid tr:nth-child(odd) td {
                    background-color: #f0f9fa;
                }
                .label {
                    font-weight: bold;
                    color: #555;
                    width: 30%;
                }
                .value {
                    color: #1a1a2e;
                }
                .description-box {
                    background-color: #f8fbff;
                    border-left: 4px solid #30b9bf;
                    padding: 14px 18px;
                    border-radius: 4px;
                    font-size: 13px;
                    line-height: 1.6;
                    color: #2d3748;
                }
                .footer {
                    margin-top: 40px;
                    padding: 16px 32px;
                    border-top: 1px solid #e2e8f0;
                    font-size: 11px;
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

            <div class="section">
                <h2>Description</h2>
                <div class="description-box">
                    %7
                </div>
            </div>

            <div class="footer">
                Peerly Research Platform &bull; Exported %3
            </div>
        </body>
        </html>
    )")
                       .arg(title.toHtmlEscaped())
                       .arg(id)
                       .arg(QDate::currentDate().toString("MMMM dd, yyyy"))
                       .arg(date.toString("MMMM dd, yyyy"))
                       .arg(location.toHtmlEscaped())
                       .arg(QString::number(price, 'f', 2))
                       .arg(description.toHtmlEscaped().replace("\n", "<br>"));

    QTextDocument doc;
    doc.setHtml(html);
    doc.setPageSize(printer.pageRect(QPrinter::DevicePixel).size());
    doc.print(&printer);

    // Open the file automatically after export
    QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
}

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

void MainWindow::on_cancelButton_clicked() {
    editingConferenceId = -1;
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_addConferenceBtn_clicked() {
    editingConferenceId = -1;
    ui->cTitleEdit->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->locationEdit->clear();
    ui->priceSpin->setValue(0);
    ui->descriptionEdit->clear();
    ui->stackedWidget->setCurrentIndex(5);
}

//********************CONFERENCE END*************************************************************************************************************//

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


void MainWindow::on_profile_clicked(){     ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_profile2_clicked(){    ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_profile3_clicked(){    ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_profile4_clicked(){    ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_profile5_clicked(){    ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_profile6_clicked(){    ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_profile7_clicked(){    ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_login_clicked(){       ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_cancelBtnReg_clicked(){ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_cancelBtnFor_clicked(){ui->stackedWidget->setCurrentIndex(3);}


void MainWindow::on_conf_clicked(){ ui->stackedWidget->setCurrentIndex(4); loadConferences(sortAscending, "");}
void MainWindow::on_conf2_clicked(){ui->stackedWidget->setCurrentIndex(4); loadConferences(sortAscending, "");}
void MainWindow::on_conf3_clicked(){ui->stackedWidget->setCurrentIndex(4); loadConferences(sortAscending, "");}
void MainWindow::on_conf4_clicked(){ui->stackedWidget->setCurrentIndex(4); loadConferences(sortAscending, "");}
void MainWindow::on_conf5_clicked(){ui->stackedWidget->setCurrentIndex(4); loadConferences(sortAscending, "");}
void MainWindow::on_conf6_clicked(){ui->stackedWidget->setCurrentIndex(4); loadConferences(sortAscending, "");}
void MainWindow::on_conf7_clicked(){ui->stackedWidget->setCurrentIndex(4); loadConferences(sortAscending, "");}


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
