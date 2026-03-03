#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "conference.h"
#include "collaboration.h"
#include "publication.h"
#include "user.h"
#include "submission.h"

// SQL
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

// Printing & PDF
#include <QPrinter>
#include <QTextDocument>
#include <QPageLayout>

// File operations
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDesktopServices>
#include <QUrl>

// Layouts
#include <QVBoxLayout>
#include <QHBoxLayout>

// Widgets
#include <QLabel>
#include <QPushButton>
#include <QDialog>
#include <QCalendarWidget>
#include <QScrollArea>
#include <QMessageBox>
#include <QLineEdit>
#include <QDateEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QTextEdit>
#include <QComboBox>
#include <QFrame>
#include <QTableWidget>
#include <QInputDialog>

// Drawing
#include <QPainter>
#include <QPixmap>
#include <QTextCharFormat>
#include <QColor>

// Charts (Statistics)
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>

// Network (for geocoding - Conference Map)
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

// JSON (for geocoding API response - Conference Map)
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

// Other
#include <QMap>
#include <QDateTime>
#include <QPalette>

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


    //StyleSheet and default index
    ui->stackedWidget->setCurrentIndex(3);
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

    QWidget *tabPage = ui->tabWidget->widget(0);


    connect(ui->tabWidget, &QTabWidget::currentChanged, this, [=](int index) {
        if (ui->tabWidget->widget(index) == ui->ReviewT)
            loadReviewsReadOnly();
    });

}


MainWindow::~MainWindow()
{
    delete ui;
}



/*********************************************************** USER START ***********************************************************************************/

void MainWindow::on_deleteUser_2_clicked()/*DELETE USER*/{
    User u;
    u.readSavedID();
    if(u.delete_user()){

        qDebug() << "deleted succefully";

        ui->displayUsername_2->setText("Username");
        ui->displaySpecialty_2->setText("Specialty");

        ui->sideBarStack->setCurrentIndex(0);
        ui->sideBarStack->show();
        ui->stackedWidget->setCurrentIndex(3);


    }
    else         qDebug() << "delete unsuccefully";


}
void MainWindow::on_addUser_clicked/* ADD USER*/(){

    QString email = ui->email_reg->text();
    QString password = ui->password_reg->text();
    QString role = ui->role_reg->text();
    QString username = ui->username_reg->text();
    QString specialty = ui->specialty_reg->text();

    User u(0, email, password, username, role, specialty);


    if(u.create_user())
    {
        qDebug() << "User Created";
        ui->sideBarStack->setCurrentIndex(0);
        ui->sideBarStack->show();
        ui->stackedWidget->setCurrentIndex(8);

    }
    else
    {
        qDebug() << "User not created ";
    }

}

void MainWindow::on_login_clicked()
{


    User u;

    QString email = ui->emailLogin_2->text();
    QString password = ui->passwordLogin_2->text();

    if (u.login(email,password)){

        ui->sideBarStack->setCurrentIndex(0);
        ui->sideBarStack->show();
        ui->stackedWidget->setCurrentIndex(3);

        ui->displayUsername_2->setText(u.getUsername());
        ui->displaySpecialty_2->setText(u.getSpecialty());
    }

}
void MainWindow::on_editUser_2_clicked(){

    User u;
    u.readSavedID();
    qDebug() << u.getId();



    QString email = ui->email_edit_2->text();
    QString password = ui->password_edit_2->text();
    QString role = ui->role_edit_2->text();
    QString username = ui->username_edit_2->text();
    QString specialty = ui->specialty_edit_2->text();

    u.setEmail(email);
    u.setPassword(password);
    u.setRole(role);
    u.setUsername(username);
    u.setSpecialty(specialty);

    if(u.update_user())
    {
        qDebug() <<"user updated";

        ui->displayUsername_2->setText(u.getUsername());
        ui->displaySpecialty_2->setText(u.getSpecialty());

        ui->sideBarStack->setCurrentIndex(0);
        ui->sideBarStack->show();
        ui->stackedWidget->setCurrentIndex(3);

    }
    else qDebug() <<"user didnt get updated";

}

void MainWindow::on_searchUserBTN_clicked()
{
    User u;

    ui->sideBarStack->setCurrentIndex(1);
    ui->sideBarStack->hide();
    ui->stackedWidget->setCurrentIndex(11);
    ui->userListView_2->setModel(u.display());
    ui->userListView_3->setModel(u.loadUserStatistics());
    ui->userListView_3->verticalHeader()->setDefaultSectionSize(30);
    ui->userListView_3->verticalHeader()->setVisible(true);


}

void MainWindow::on_editUserPage_clicked()
{
    ui->sideBarStack->setCurrentIndex(1);
    ui->sideBarStack->hide();
    ui->stackedWidget->setCurrentIndex(13);
}



void MainWindow::on_cancelBtnReg_clicked()
{
    ui->sideBarStack->setCurrentIndex(0);
    ui->sideBarStack->show();
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_cancelBtnFor_clicked()
{
    ui->sideBarStack->setCurrentIndex(0);
    ui->sideBarStack->show();
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_userSearchBackBTN_2_clicked()
{
    ui->sideBarStack->setCurrentIndex(0);
    ui->sideBarStack->show();
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_cancelEditBTN_2_clicked()
{
    ui->sideBarStack->setCurrentIndex(0);
    ui->sideBarStack->show();
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_backLoginBTN_2_clicked()
{
    ui->sideBarStack->setCurrentIndex(0);
    ui->sideBarStack->show();
    ui->stackedWidget->setCurrentIndex(3);
}


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

void MainWindow::on_searchString_clicked(){
    User u;
    QString string = ui->enterString->text();
   ui->userListView_2->setModel(u.search(string));
}
void MainWindow::on_Viewer_checkStateChanged(const Qt::CheckState &state)
{
    User u;

    if (state == Qt::Checked)
    {


        ui->userListView_2->setModel(u.filter(1));

    }
    else if (state == Qt::Unchecked)
    {
       ui->userListView_2->setModel(u.filter(0));

        }
}
void MainWindow::on_Reviewer_checkStateChanged(const Qt::CheckState &state)
{
    User u;


    if (state == Qt::Checked)
    {


        ui->userListView_2->setModel(u.filter2(1));

    }
    else if (state == Qt::Unchecked)
    {
        ui->userListView_2->setModel(u.filter2(0));

    }
}
void MainWindow::on_Researcher_checkStateChanged(const Qt::CheckState &state)
{
    User u;

    if (state == Qt::Checked)
    {


        ui->userListView_2->setModel(u.filter3(1));

    }
    else if (state == Qt::Unchecked)
    {
        ui->userListView_2->setModel(u.filter3(0));

    }
}


void MainWindow::exportTableToPDF(const QString &fileName)
{
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QString html = "<table border='1'><tr>";


    QAbstractItemModel *model = ui->userListView_2->model();
    for (int col = 0; col < model->columnCount(); ++col)
        html += "<th>" + model->headerData(col, Qt::Horizontal).toString() + "</th>";
    html += "</tr>";


    for (int row = 0; row < model->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < model->columnCount(); ++col)
            html += "<td>" + model->data(model->index(row, col)).toString() + "</td>";
        html += "</tr>";
    }
    html += "</table>";

    doc.setHtml(html);
    doc.print(&printer);

}


void MainWindow::on_exportUserPDF_clicked(){

    exportTableToPDF("C:/Users/Mounib/Documents/users.pdf");

}


void MainWindow::on_linkFor_linkActivated(){ui->stackedWidget->setCurrentIndex(10);}


/********************************************************** USER END *************************************************************************************/

//********************REVIEW START*********************************************************************************************************************//


void MainWindow::loadReviews(bool ascending, QString searchFilter)
{
    QVBoxLayout* reviewLayout = qobject_cast<QVBoxLayout*>(ui->widget_2->layout());
    if (!reviewLayout) {
        reviewLayout = new QVBoxLayout(ui->widget_2);
        ui->widget_2->setLayout(reviewLayout);
    }

    QLayoutItem* reviewItem;
    while ((reviewItem = reviewLayout->takeAt(0)) != nullptr) {
        delete reviewItem->widget();
        delete reviewItem;
    }

    QString reviewQueryStr = "SELECT IDREVIEW, REVIEWER_NAME, REVIEW_DATE, SUBMISSION_ID, PUBLICATION_ID, COMMENTREVIEW, STATUS FROM REVIEW";
    if (!searchFilter.trimmed().isEmpty())
        reviewQueryStr += " WHERE UPPER(REVIEWER_NAME) LIKE UPPER(:search)";
    reviewQueryStr += ascending ? " ORDER BY REVIEW_DATE ASC" : " ORDER BY REVIEW_DATE DESC";

    QSqlQuery reviewQuery;
    reviewQuery.prepare(reviewQueryStr);
    if (!searchFilter.trimmed().isEmpty())
        reviewQuery.bindValue(":search", "%" + searchFilter.trimmed() + "%");

    if (!reviewQuery.exec()) {
        qDebug() << "FULL QUERY:" << reviewQueryStr;
        qDebug() << "ERROR:" << reviewQuery.lastError().text();
        qDebug() << "DRIVER ERROR:" << reviewQuery.lastError().driverText();
        qDebug() << "DB ERROR:" << reviewQuery.lastError().databaseText();
        QLabel* errorLabel = new QLabel("Error loading reviews: " + reviewQuery.lastError().text());
        errorLabel->setAlignment(Qt::AlignCenter);
        reviewLayout->addWidget(errorLabel);
        return;
    }

    bool reviewsFound = false;

    while (reviewQuery.next()) {
        reviewsFound = true;

        int reviewId         = reviewQuery.value(0).toInt();
        QString reviewerName = reviewQuery.value(1).toString();
        QDate reviewDate     = reviewQuery.value(2).toDate();
        int submissionId     = reviewQuery.value(3).toInt();
        int publicationId    = reviewQuery.value(4).toInt();
        QString comment      = reviewQuery.value(5).toString();
        QString status       = reviewQuery.value(6).toString();

        QFrame* reviewCard = new QFrame();
        reviewCard->setFrameShape(QFrame::StyledPanel);
        reviewCard->setMinimumHeight(120);

        QVBoxLayout* reviewCardLayout = new QVBoxLayout(reviewCard);

        QString statusColor, statusBg;
        if (status == "Approved") {
            statusColor = "#15803d"; statusBg = "#dcfce7";
        } else if (status == "Rejected") {
            statusColor = "#b91c1c"; statusBg = "#fee2e2";
        } else if (status == "In Review") {
            statusColor = "#b45309"; statusBg = "#fef3c7";
        } else {
            statusColor = "#1d4ed8"; statusBg = "#dbeafe";
        }

        QHBoxLayout* topRowLayout = new QHBoxLayout();
        QLabel* reviewerLabel = new QLabel("<b>" + reviewerName + "</b>");

        QLabel* statusBadge = new QLabel(status.isEmpty() ? "Pending" : status);
        statusBadge->setAlignment(Qt::AlignCenter);
        statusBadge->setFixedHeight(24);
        statusBadge->setContentsMargins(10, 2, 10, 2);
        statusBadge->setStyleSheet(QString(
                                       "QLabel { background-color: %1; color: %2; border-radius: 10px; font-size: 9pt; font-weight: 700; padding: 2px 10px; }"
                                       ).arg(statusBg, statusColor));

        topRowLayout->addWidget(reviewerLabel);
        topRowLayout->addStretch();
        topRowLayout->addWidget(statusBadge);

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

        reviewCardLayout->addLayout(topRowLayout);
        reviewCardLayout->addWidget(reviewInfoLabel);
        reviewCardLayout->addWidget(commentLabel);
        reviewCardLayout->addLayout(reviewBtnLayout);

        reviewLayout->addWidget(reviewCard);

        connect(deleteReviewBtn, &QPushButton::clicked, this, [=]() {
            QSqlQuery deleteReviewQuery;
            deleteReviewQuery.prepare("DELETE FROM REVIEW WHERE IDREVIEW = ?");
            deleteReviewQuery.addBindValue(reviewId);
            deleteReviewQuery.exec();
            loadReviews(reviewSortAscending, ui->searchReviewEdit->text());
        });

        connect(editReviewBtn, &QPushButton::clicked, this, [=]() {
            showReviewDialog(reviewId);
        });

        connect(pdfReviewBtn, &QPushButton::clicked, this, [=]() {
            exportReviewPDF(reviewId, reviewerName, reviewDate, submissionId, publicationId, comment, status);
        });
    }

    if (!reviewsFound) {
        QLabel* noReviewsLabel = new QLabel("No reviews found.");
        noReviewsLabel->setAlignment(Qt::AlignCenter);
        reviewLayout->addWidget(noReviewsLabel);
    }

    reviewLayout->addStretch();
}


void MainWindow::buildCreateReviewUI()
{
    QWidget* page = ui->stackedWidget->widget(1);
    if (!page) return;

    // Wipe old layout
    QLayout* old = page->layout();
    if (old) {
        QLayoutItem* item;
        while ((item = old->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete old;
    }

    // Theme
    const bool dark          = !mode;
    const QString bgPage     = dark ? "#1a1f2e" : "#f0f4f8";
    const QString bgCard     = dark ? "#252b3d" : "#ffffff";
    const QString border     = dark ? "#3e4859" : "#e2e8f0";
    const QString txtPrimary = dark ? "#f1f5f9" : "#0f172a";
    const QString txtSub     = dark ? "#8892a4" : "#64748b";
    const QString accent     = "#30b9bf";

    page->setStyleSheet(QString("background-color: %1;").arg(bgPage));

    // top margin small, left space, horizontal split
    QVBoxLayout* rootLayout = new QVBoxLayout(page);
    rootLayout->setContentsMargins(36, 17, 24, 24);
    rootLayout->setSpacing(0);

    // Page title row
    QLabel* pageTitle = new QLabel("Send Submission to Review");
    pageTitle->setStyleSheet(QString(
                                 "font-size: 20pt; font-weight: 700; color: %1; background: transparent;"
                                 ).arg(txtPrimary));
    rootLayout->addWidget(pageTitle);

    QLabel* pageSub = new QLabel("Fill in the details below and select a submission to send for peer review.");
    pageSub->setStyleSheet(QString(
                               "font-size: 10pt; color: %1; background: transparent; margin-bottom: 6px;"
                               ).arg(txtSub));
    rootLayout->addWidget(pageSub);
    rootLayout->addSpacing(14);

    // Stats Panel
    QHBoxLayout* hSplit = new QHBoxLayout();
    hSplit->setSpacing(24);
    hSplit->setContentsMargins(0, 0, 0, 0);

    //frame for window
    QFrame* card = new QFrame();
    card->setMaximumWidth(680);
    card->setMinimumWidth(420);
    card->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    card->setStyleSheet(QString(
                            "QFrame { background-color: %1; border: 1.5px solid %2; border-radius: 14px; }"
                            ).arg(bgCard, border));

    QVBoxLayout* cardLayout = new QVBoxLayout(card);
    cardLayout->setContentsMargins(32, 28, 32, 28);
    cardLayout->setSpacing(20);

    QString inputStyle = QString(
                             "background-color: %1; border: 1.5px solid %2; "
                             "border-radius: 8px; padding: 12px 14px; color: %3; font-size: 10pt;"
                             ).arg(dark ? "#1e2433" : "#ffffff", border, txtPrimary);

    QString focusStyle = QString("border: 2px solid %1; padding: 11px 13px;").arg(accent);

    auto makeFieldLabel = [&](const QString& text) -> QLabel* {
        QLabel* lbl = new QLabel(text);
        lbl->setStyleSheet(QString(
                               "font-size: 10pt; font-weight: 600; color: %1; background: transparent;"
                               ).arg(txtSub));
        return lbl;
    };

    // Reviewer Name
    QLineEdit* nameInput = new QLineEdit();
    nameInput->setPlaceholderText("Enter reviewer name");
    nameInput->setFixedHeight(44);
    nameInput->setStyleSheet(QString("QLineEdit { %1 } QLineEdit:focus { %2 }").arg(inputStyle, focusStyle));
    QVBoxLayout* nameGroup = new QVBoxLayout();
    nameGroup->setSpacing(6);
    nameGroup->addWidget(makeFieldLabel("Reviewer Name"));
    nameGroup->addWidget(nameInput);
    cardLayout->addLayout(nameGroup);

    // Review Date
    QDateEdit* dateInput = new QDateEdit(QDate::currentDate());
    dateInput->setCalendarPopup(true);
    dateInput->setDisplayFormat("dd/MM/yyyy");
    dateInput->setFixedHeight(44);
    dateInput->setStyleSheet(QString(
                                 "QDateEdit { %1 } QDateEdit:focus { %2 } QDateEdit::drop-down { border: none; width: 30px; }"
                                 ).arg(inputStyle, focusStyle));
    QVBoxLayout* dateGroup = new QVBoxLayout();
    dateGroup->setSpacing(6);
    dateGroup->addWidget(makeFieldLabel("Review Date"));
    dateGroup->addWidget(dateInput);
    cardLayout->addLayout(dateGroup);

    // Submission Picker
    QComboBox* submissionCombo = new QComboBox();
    submissionCombo->setFixedHeight(44);
    submissionCombo->setStyleSheet(QString(
                                       "QComboBox { %1 }"
                                       "QComboBox:focus { %2 }"
                                       "QComboBox::drop-down { border: none; width: 30px; }"
                                       "QComboBox::down-arrow { width: 12px; height: 12px; }"
                                       "QComboBox QAbstractItemView { background-color: %3; color: %4; "
                                       "border: 1.5px solid %5; selection-background-color: %6; selection-color: white; outline: none; }"
                                       ).arg(inputStyle, focusStyle, dark ? "#252b3d" : "#ffffff", txtPrimary, border, accent));

    QList<QPair<int,int>> submissionData;
    QSqlQuery subQuery;
    subQuery.prepare("SELECT SubmissionID, Title, TopicID FROM Submission ORDER BY CreatedAt DESC");
    if (subQuery.exec()) {
        while (subQuery.next()) {
            submissionCombo->addItem(subQuery.value(1).toString());
            submissionData.append({subQuery.value(0).toInt(), subQuery.value(2).toInt()});
        }
    }
    if (submissionCombo->count() == 0) {
        submissionCombo->addItem("No submissions found");
        submissionCombo->setEnabled(false);
    }
    QVBoxLayout* subGroup = new QVBoxLayout();
    subGroup->setSpacing(6);
    subGroup->addWidget(makeFieldLabel("Select Submission"));
    subGroup->addWidget(submissionCombo);
    cardLayout->addLayout(subGroup);

    // Comment
    QTextEdit* commentInput = new QTextEdit();
    commentInput->setPlaceholderText("Write your review comments here...");
    commentInput->setFixedHeight(110);
    commentInput->setStyleSheet(QString("QTextEdit { %1 } QTextEdit:focus { %2 }").arg(inputStyle, focusStyle));
    QVBoxLayout* commentGroup = new QVBoxLayout();
    commentGroup->setSpacing(6);
    commentGroup->addWidget(makeFieldLabel("Comment"));
    commentGroup->addWidget(commentInput);
    cardLayout->addLayout(commentGroup);

    cardLayout->addSpacing(4);

    // Buttons
    QHBoxLayout* btnRow = new QHBoxLayout();
    btnRow->setSpacing(12);

    QPushButton* clearBtn = new QPushButton("Clear");
    clearBtn->setFixedHeight(44);
    clearBtn->setMinimumWidth(100);
    clearBtn->setCursor(Qt::PointingHandCursor);
    clearBtn->setStyleSheet(QString(
                                "QPushButton { background-color: %1; color: %2; border: 1.5px solid %3; "
                                "border-radius: 10px; padding: 10px 24px; font-size: 10pt; font-weight: 600; }"
                                "QPushButton:hover { background-color: %4; }"
                                ).arg(bgCard, txtPrimary, border, dark ? "#343d52" : "#f1f5f9"));

    QPushButton* saveReviewBtn = new QPushButton("Send to Review");
    saveReviewBtn->setFixedHeight(44);
    saveReviewBtn->setMinimumWidth(160);
    saveReviewBtn->setCursor(Qt::PointingHandCursor);
    saveReviewBtn->setStyleSheet(
        "QPushButton { background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
        "stop:0 #3dd4db, stop:1 #30b9bf); color: white; border: none; "
        "border-radius: 10px; padding: 10px 24px; font-size: 10pt; font-weight: 700; }"
        "QPushButton:hover { background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
        "stop:0 #5de0e6, stop:1 #3acfd6); }"
        "QPushButton:pressed { background-color: #27a7ac; }"
        );

    btnRow->addStretch();
    btnRow->addWidget(clearBtn);
    btnRow->addWidget(saveReviewBtn);
    cardLayout->addLayout(btnRow);

    hSplit->addWidget(card, 0, Qt::AlignTop);

    // Query status counts
    int cntPending = 0, cntInReview = 0, cntApproved = 0, cntRejected = 0;
    QSqlQuery statQ;
    statQ.prepare("SELECT STATUS, COUNT(*) FROM REVIEW GROUP BY STATUS");
    if (statQ.exec()) {
        while (statQ.next()) {
            QString s = statQ.value(0).toString();
            int     n = statQ.value(1).toInt();
            if (s == "Approved")  cntApproved  = n;
            else if (s == "Rejected")  cntRejected  = n;
            else if (s == "In Review") cntInReview  = n;
            else                       cntPending   += n; // catches "Pending" and empty
        }
    }
    int totalReviews = cntPending + cntInReview + cntApproved + cntRejected;

    // Also count submissions
    int totalSubmissions = 0;
    QSqlQuery subCntQ;
    subCntQ.prepare("SELECT COUNT(*) FROM Submission");
    if (subCntQ.exec() && subCntQ.next())
        totalSubmissions = subCntQ.value(0).toInt();

    QFrame* statsPanel = new QFrame();
    statsPanel->setFixedWidth(260);
    statsPanel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    statsPanel->setStyleSheet(QString(
                                  "QFrame { background-color: %1; border: 1.5px solid %2; border-radius: 14px; }"
                                  ).arg(bgCard, border));

    QVBoxLayout* statsLayout = new QVBoxLayout(statsPanel);
    statsLayout->setContentsMargins(20, 20, 20, 20);
    statsLayout->setSpacing(14);

    QLabel* statsTitle = new QLabel("Review Statistics");
    statsTitle->setStyleSheet(QString(
                                  "font-size: 11pt; font-weight: 700; color: %1; background: transparent; border: none;"
                                  ).arg(txtPrimary));
    statsLayout->addWidget(statsTitle);

    QLabel* statsSub = new QLabel(QString("Total reviews: %1").arg(totalReviews));
    statsSub->setStyleSheet(QString(
                                "font-size: 9pt; color: %1; background: transparent; border: none;"
                                ).arg(txtSub));
    statsLayout->addWidget(statsSub);

    // ── Donut chart widget ─────────────────────────────────────────────────
    struct SliceData {
        int    value;
        QColor color;
        QString label;
    };
    QVector<SliceData> slices = {
        { cntPending,  QColor("#3b82f6"), "Pending"   },
        { cntInReview, QColor("#f59e0b"), "In Review" },
        { cntApproved, QColor("#22c55e"), "Approved"  },
        { cntRejected, QColor("#ef4444"), "Rejected"  }
    };

    QWidget* donutWidget = new QWidget();
    donutWidget->setFixedSize(220, 180);
    donutWidget->setStyleSheet("background: transparent;");

    // Capture by value for the paint lambda
    int capturedTotal = totalReviews;
    QVector<SliceData> capturedSlices = slices;
    bool capturedDark = dark;
    QString capturedTxtPrimary = txtPrimary;

    donutWidget->installEventFilter(this);

    struct DonutPainter : public QObject {
        QVector<SliceData> slices;
        int total;
        bool dark;
        QString txtPrimary;

        bool eventFilter(QObject* obj, QEvent* ev) override {
            if (ev->type() == QEvent::Paint) {
                QWidget* w = qobject_cast<QWidget*>(obj);
                if (!w) return false;
                QPainter p(w);
                p.setRenderHint(QPainter::Antialiasing);

                int cx = w->width() / 2;
                int cy = w->height() / 2 - 10;
                int outerR = 72;
                int innerR = 44;

                QRectF outerRect(cx - outerR, cy - outerR, outerR * 2, outerR * 2);
                QRectF innerRect(cx - innerR, cy - innerR, innerR * 2, innerR * 2);

                if (total == 0) {
                    // Empty ring
                    p.setPen(Qt::NoPen);
                    p.setBrush(QColor(dark ? "#3e4859" : "#e2e8f0"));
                    p.drawEllipse(outerRect);
                    p.setBrush(QColor(dark ? "#252b3d" : "#ffffff"));
                    p.drawEllipse(innerRect);
                    p.setPen(QColor(dark ? "#8892a4" : "#94a3b8"));
                    p.setFont(QFont("Arial", 8));
                    p.drawText(outerRect, Qt::AlignCenter, "No data");
                    return true;
                }

                // Draw slices
                double startAngle = -90.0;
                for (auto& sl : slices) {
                    if (sl.value == 0) continue;
                    double spanAngle = (sl.value / (double)total) * 360.0;
                    p.setPen(Qt::NoPen);
                    p.setBrush(sl.color);
                    // Draw as pie then punch hole
                    QPainterPath path;
                    path.moveTo(cx, cy);
                    path.arcTo(outerRect, startAngle, spanAngle);
                    path.closeSubpath();
                    p.drawPath(path);
                    startAngle += spanAngle;
                }

                // Punch the donut hole
                p.setPen(Qt::NoPen);
                p.setBrush(QColor(dark ? "#252b3d" : "#ffffff"));
                p.drawEllipse(innerRect);

                // Centre label: total
                p.setPen(QColor(txtPrimary));
                QFont f("Arial", 12, QFont::Bold);
                p.setFont(f);
                p.drawText(innerRect, Qt::AlignCenter, QString::number(total));

                return true;
            }
            return false;
        }
    };

    DonutPainter* dp = new DonutPainter();
    dp->slices      = capturedSlices;
    dp->total       = capturedTotal;
    dp->dark        = dark;
    dp->txtPrimary  = txtPrimary;
    donutWidget->installEventFilter(dp);
    // Keep dp alive as child of donutWidget
    dp->setParent(donutWidget);

    statsLayout->addWidget(donutWidget, 0, Qt::AlignHCenter);

    // Legend
    QGridLayout* legend = new QGridLayout();
    legend->setSpacing(6);
    legend->setContentsMargins(0, 0, 0, 0);

    struct LegendEntry { QString label; QColor color; int value; };
    QVector<LegendEntry> legendEntries = {
                                          { "Pending",   QColor("#3b82f6"), cntPending   },
                                          { "In Review", QColor("#f59e0b"), cntInReview  },
                                          { "Approved",  QColor("#22c55e"), cntApproved  },
                                          { "Rejected",  QColor("#ef4444"), cntRejected  },
                                          };

    for (int i = 0; i < legendEntries.size(); ++i) {
        auto& e = legendEntries[i];

        // Colour dot
        QLabel* dot = new QLabel();
        dot->setFixedSize(10, 10);
        dot->setStyleSheet(QString(
                               "QLabel { background-color: %1; border-radius: 5px; border: none; }"
                               ).arg(e.color.name()));

        // Label
        QLabel* lbl = new QLabel(e.label);
        lbl->setStyleSheet(QString(
                               "font-size: 9pt; color: %1; background: transparent; border: none;"
                               ).arg(txtSub));

        // Count
        QLabel* cnt = new QLabel(QString::number(e.value));
        cnt->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        cnt->setStyleSheet(QString(
                               "font-size: 9pt; font-weight: 700; color: %1; background: transparent; border: none;"
                               ).arg(txtPrimary));

        legend->addWidget(dot, i, 0, Qt::AlignCenter);
        legend->addWidget(lbl, i, 1);
        legend->addWidget(cnt, i, 2);
    }
    statsLayout->addLayout(legend);

    //Divider
    QFrame* divider = new QFrame();
    divider->setFrameShape(QFrame::HLine);
    divider->setStyleSheet(QString("background-color: %1; border: none; max-height: 1px;").arg(border));
    statsLayout->addWidget(divider);

    // Submissions count tile
    QFrame* subTile = new QFrame();
    subTile->setStyleSheet(QString(
                               "QFrame { background-color: %1; border-radius: 10px; border: 1px solid %2; }"
                               ).arg(dark ? "#1e2433" : "#f8fafc", border));

    QHBoxLayout* subTileLayout = new QHBoxLayout(subTile);
    subTileLayout->setContentsMargins(14, 10, 14, 10);

    QLabel* subIcon = new QLabel("📄");
    subIcon->setStyleSheet("font-size: 16pt; background: transparent; border: none;");
    QVBoxLayout* subTextCol = new QVBoxLayout();
    subTextCol->setSpacing(1);

    QLabel* subCountLabel = new QLabel(QString::number(totalSubmissions));
    subCountLabel->setStyleSheet(QString(
                                     "font-size: 14pt; font-weight: 700; color: %1; background: transparent; border: none;"
                                     ).arg(txtPrimary));

    QLabel* subDescLabel = new QLabel("Submissions");
    subDescLabel->setStyleSheet(QString(
                                    "font-size: 8pt; color: %1; background: transparent; border: none;"
                                    ).arg(txtSub));

    subTextCol->addWidget(subCountLabel);
    subTextCol->addWidget(subDescLabel);
    subTileLayout->addWidget(subIcon);
    subTileLayout->addLayout(subTextCol);
    subTileLayout->addStretch();
    statsLayout->addWidget(subTile);

    statsLayout->addStretch();

    hSplit->addWidget(statsPanel, 0, Qt::AlignTop);
    hSplit->addStretch();   // push both left if window is wide

    rootLayout->addLayout(hSplit);
    rootLayout->addStretch();

    // Clear
    connect(clearBtn, &QPushButton::clicked, this, [=]() {
        nameInput->clear();
        dateInput->setDate(QDate::currentDate());
        if (submissionCombo->isEnabled()) submissionCombo->setCurrentIndex(0);
        commentInput->clear();
    });

    // Save
    connect(saveReviewBtn, &QPushButton::clicked, this, [=]() {
        if (nameInput->text().trimmed().isEmpty()) {
            QMessageBox::warning(page, "Validation Error", "Please enter a reviewer name.");
            return;
        }
        if (!submissionCombo->isEnabled()) {
            QMessageBox::warning(page, "Validation Error", "No submissions available to send for review.");
            return;
        }
        if (commentInput->toPlainText().trimmed().isEmpty()) {
            QMessageBox::warning(page, "Validation Error", "Please enter a comment.");
            return;
        }

        int comboIdx = submissionCombo->currentIndex();
        int sid      = submissionData[comboIdx].first;
        int pid      = submissionData[comboIdx].second;

        QSqlQuery query;
        query.prepare(
            "INSERT INTO REVIEW "
            "  (IDREVIEW, REVIEWER_NAME, REVIEW_DATE, SUBMISSION_ID, PUBLICATION_ID, COMMENTREVIEW, STATUS) "
            "VALUES "
            "  (REVIEW_SEQ.NEXTVAL, :name, :date, :sid, :pid, :comment, 'Pending')"
            );
        query.bindValue(":name",    nameInput->text().trimmed());
        query.bindValue(":date",    dateInput->date());
        query.bindValue(":sid",     sid);
        query.bindValue(":pid",     pid);
        query.bindValue(":comment", commentInput->toPlainText().trimmed());

        if (query.exec()) {
            QMessageBox::information(page, "Success", "Submission sent to review successfully.");
            nameInput->clear();
            dateInput->setDate(QDate::currentDate());
            submissionCombo->setCurrentIndex(0);
            commentInput->clear();
            // Rebuild to refresh stats
            buildCreateReviewUI();
        } else {
            QMessageBox::critical(page, "Error",
                                  "Failed to submit for review:\n" + query.lastError().text());
        }
    });
}

//  showReviewDialog  —  EDIT mode only

void MainWindow::showReviewDialog(int reviewId)
{
    bool isEditing = (reviewId != -1);

    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle(isEditing ? "Edit Review" : "Send to Review");
    dialog->setFixedSize(520, isEditing ? 640 : 660);
    dialog->setAttribute(Qt::WA_StyledBackground, true);

    const bool dark          = !mode;
    const QString bgPage     = dark ? "#1a1f2e" : "#f6f8fc";
    const QString bgCard     = dark ? "#252b3d" : "#ffffff";
    const QString border     = dark ? "#3e4859" : "#e2e8f0";
    const QString txtPrimary = dark ? "#f1f5f9" : "#0f172a";
    const QString txtSub     = dark ? "#8892a4" : "#64748b";

    dialog->setStyleSheet(QString("QDialog { background-color: %1; }").arg(bgPage));

    QVBoxLayout* mainLayout = new QVBoxLayout(dialog);
    mainLayout->setContentsMargins(24, 24, 24, 24);
    mainLayout->setSpacing(19);

    QLabel* titleLabel = new QLabel(isEditing ? "Edit Review" : "Send to Review");
    titleLabel->setStyleSheet(QString(
                                  "font-size: 18pt; font-weight: 700; color: %1; background: transparent;"
                                  ).arg(txtPrimary));
    mainLayout->addWidget(titleLabel);

    QFrame* formCard = new QFrame();
    formCard->setStyleSheet(QString(
                                "QFrame { background-color: %1; border: 1.5px solid %2; border-radius: 12px; }"
                                ).arg(bgCard, border));

    QVBoxLayout* formLayout = new QVBoxLayout(formCard);
    formLayout->setSpacing(19);
    formLayout->setContentsMargins(24, 24, 24, 24);

    QString inputStyle = QString(
                             "background-color: %1; border: 1.5px solid %2; "
                             "border-radius: 8px; padding: 12px 14px; color: %3; font-size: 10pt;"
                             ).arg(dark ? "#1e2433" : "#ffffff", border, txtPrimary);

    auto makeLabel = [&](const QString& text) -> QLabel* {
        QLabel* lbl = new QLabel(text);
        lbl->setStyleSheet(QString(
                               "font-size: 10pt; font-weight: 600; color: %1; background: transparent;"
                               ).arg(txtSub));
        lbl->setFixedHeight(15);
        return lbl;
    };

    auto addField = [&](const QString& labelText, QWidget* widget) {
        QVBoxLayout* fieldGroup = new QVBoxLayout();
        fieldGroup->setSpacing(6);
        fieldGroup->setContentsMargins(0, 0, 0, 0);
        fieldGroup->addWidget(makeLabel(labelText));
        widget->setFixedHeight(44);
        fieldGroup->addWidget(widget);
        formLayout->addLayout(fieldGroup);
    };

    QLineEdit* nameInput = new QLineEdit();
    nameInput->setPlaceholderText("Reviewer Name");
    nameInput->setStyleSheet(QString(
                                 "QLineEdit { %1 } QLineEdit:focus { border: 2px solid #30b9bf; padding: 11px 13px; }"
                                 ).arg(inputStyle));

    QDateEdit* dateInput = new QDateEdit(QDate::currentDate());
    dateInput->setCalendarPopup(true);
    dateInput->setDisplayFormat("dd/MM/yyyy");
    dateInput->setStyleSheet(QString(
                                 "QDateEdit { %1 } QDateEdit:focus { border: 2px solid #30b9bf; padding: 11px 13px; }"
                                 ).arg(inputStyle));

    addField("Reviewer Name", nameInput);
    addField("Review Date",   dateInput);

    QComboBox* submissionCombo = nullptr;
    QList<QPair<int,int>> submissionData;

    if (!isEditing) {
        submissionCombo = new QComboBox();
        submissionCombo->setStyleSheet(QString(
                                           "QComboBox { %1 }"
                                           "QComboBox:focus { border: 2px solid #30b9bf; padding: 11px 13px; }"
                                           "QComboBox::drop-down { border: none; width: 30px; }"
                                           "QComboBox QAbstractItemView { background-color: %2; color: %3; "
                                           "border: 1.5px solid %4; selection-background-color: #30b9bf; }"
                                           ).arg(inputStyle, dark ? "#252b3d" : "#ffffff", txtPrimary, border));

        QSqlQuery subQuery;
        subQuery.prepare("SELECT SubmissionID, Title, TopicID FROM Submission ORDER BY CreatedAt DESC");
        if (subQuery.exec()) {
            while (subQuery.next()) {
                submissionCombo->addItem(subQuery.value(1).toString());
                submissionData.append({subQuery.value(0).toInt(), subQuery.value(2).toInt()});
            }
        }
        if (submissionCombo->count() == 0) {
            submissionCombo->addItem("No submissions found");
            submissionCombo->setEnabled(false);
        }
        addField("Select Submission", submissionCombo);
    }

    QComboBox* statusInput = nullptr;
    if (isEditing) {
        statusInput = new QComboBox();
        statusInput->addItems({"Pending", "In Review", "Approved", "Rejected"});
        statusInput->setStyleSheet(QString(
                                       "QComboBox { %1 }"
                                       "QComboBox:focus { border: 2px solid #30b9bf; padding: 11px 13px; }"
                                       "QComboBox::drop-down { border: none; width: 30px; }"
                                       "QComboBox QAbstractItemView { background-color: %2; color: %3; "
                                       "border: 1.5px solid %4; selection-background-color: #30b9bf; }"
                                       ).arg(inputStyle, dark ? "#252b3d" : "#ffffff", txtPrimary, border));
        addField("Status", statusInput);
    }

    QTextEdit* commentInput = new QTextEdit();
    commentInput->setPlaceholderText("Review comments...");
    commentInput->setFixedHeight(100);
    commentInput->setStyleSheet(QString(
                                    "QTextEdit { %1 } QTextEdit:focus { border: 2px solid #30b9bf; padding: 11px 13px; }"
                                    ).arg(inputStyle));
    formLayout->addWidget(makeLabel("Comment"));
    formLayout->addWidget(commentInput);

    mainLayout->addWidget(formCard);

    if (isEditing) {
        QSqlQuery q;
        q.prepare("SELECT REVIEWER_NAME, REVIEW_DATE, COMMENTREVIEW, STATUS FROM REVIEW WHERE IDREVIEW = ?");
        q.addBindValue(reviewId);
        if (q.exec() && q.next()) {
            nameInput->setText(q.value(0).toString());
            dateInput->setDate(q.value(1).toDate());
            commentInput->setPlainText(q.value(2).toString());
            int idx = statusInput->findText(q.value(3).toString());
            if (idx >= 0) statusInput->setCurrentIndex(idx);
        }
    }

    mainLayout->addStretch();

    QHBoxLayout* btnLayout = new QHBoxLayout();
    btnLayout->setSpacing(12);

    QPushButton* cancelBtn = new QPushButton("Cancel");
    cancelBtn->setFixedHeight(44);
    cancelBtn->setMinimumWidth(100);
    cancelBtn->setCursor(Qt::PointingHandCursor);
    cancelBtn->setStyleSheet(QString(
                                 "QPushButton { background-color: %1; color: %2; border: 1px solid %3; "
                                 "border-radius: 10px; padding: 10px 24px; font-size: 10pt; font-weight: 600; }"
                                 "QPushButton:hover { background-color: %4; }"
                                 ).arg(bgCard, txtPrimary, border, dark ? "#343d52" : "#f8fafc"));

    QPushButton* saveReviewBtn = new QPushButton(isEditing ? "Update" : "Send to Review");
    saveReviewBtn->setFixedHeight(44);
    saveReviewBtn->setMinimumWidth(150);
    saveReviewBtn->setCursor(Qt::PointingHandCursor);
    saveReviewBtn->setStyleSheet(
        "QPushButton { background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
        "stop:0 #3dd4db, stop:1 #30b9bf); color: white; border: none; "
        "border-radius: 10px; padding: 10px 24px; font-size: 10pt; font-weight: 700; }"
        "QPushButton:hover { background-color: #22d3dd; }"
        );

    btnLayout->addStretch();
    btnLayout->addWidget(cancelBtn);
    btnLayout->addWidget(saveReviewBtn);
    mainLayout->addLayout(btnLayout);

    connect(cancelBtn, &QPushButton::clicked, dialog, &QDialog::reject);

    connect(saveReviewBtn, &QPushButton::clicked, this, [=]() {
        if (nameInput->text().trimmed().isEmpty()) {
            QMessageBox::warning(dialog, "Validation Error", "Please enter a reviewer name.");
            return;
        }
        if (commentInput->toPlainText().trimmed().isEmpty()) {
            QMessageBox::warning(dialog, "Validation Error", "Please enter a comment.");
            return;
        }
        if (!isEditing && submissionCombo && !submissionCombo->isEnabled()) {
            QMessageBox::warning(dialog, "Validation Error", "No submissions available to send for review.");
            return;
        }

        QSqlQuery query;

        if (isEditing) {
            query.prepare(
                "UPDATE REVIEW SET "
                "  REVIEWER_NAME = :name, "
                "  REVIEW_DATE   = :date, "
                "  COMMENTREVIEW = :comment, "
                "  STATUS        = :status "
                "WHERE IDREVIEW  = :id"
                );
            query.bindValue(":name",    nameInput->text().trimmed());
            query.bindValue(":date",    dateInput->date());
            query.bindValue(":comment", commentInput->toPlainText().trimmed());
            query.bindValue(":status",  statusInput->currentText());
            query.bindValue(":id",      reviewId);
        } else {
            int comboIdx = submissionCombo->currentIndex();
            int sid      = submissionData[comboIdx].first;
            int pid      = submissionData[comboIdx].second;
            query.prepare(
                "INSERT INTO REVIEW "
                "  (IDREVIEW, REVIEWER_NAME, REVIEW_DATE, SUBMISSION_ID, PUBLICATION_ID, COMMENTREVIEW, STATUS) "
                "VALUES "
                "  (REVIEW_SEQ.NEXTVAL, :name, :date, :sid, :pid, :comment, 'Pending')"
                );
            query.bindValue(":name",    nameInput->text().trimmed());
            query.bindValue(":date",    dateInput->date());
            query.bindValue(":sid",     sid);
            query.bindValue(":pid",     pid);
            query.bindValue(":comment", commentInput->toPlainText().trimmed());
        }

        if (query.exec()) {
            loadReviews(reviewSortAscending, ui->searchReviewEdit->text());
            dialog->accept();
        } else {
            QMessageBox::critical(dialog, "Error",
                                  "Failed to save review:\n" + query.lastError().text());
        }
    });

    dialog->exec();
}

void MainWindow::exportReviewPDF(int reviewId, const QString& reviewerName, const QDate& reviewDate,
                                 int submissionId, int publicationId, const QString& comment,
                                 const QString& status)
{
    QString fileName = reviewerName;
    fileName.replace(" ", "_");

    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Export Review PDF",
        QDir::homePath() + "/" + fileName + "_Review.pdf",
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
    QString reviewDateStr = reviewDate.toString("MMMM dd, yyyy");

    QString statusColor, statusBg;
    if (status == "Approved") {
        statusColor = "#15803d"; statusBg = "#dcfce7";
    } else if (status == "Rejected") {
        statusColor = "#b91c1c"; statusBg = "#fee2e2";
    } else if (status == "In Review") {
        statusColor = "#b45309"; statusBg = "#fef3c7";
    } else {
        statusColor = "#1d4ed8"; statusBg = "#dbeafe";
    }

    QString html = QString(R"(
        <html>
        <head>
            <style>
                body { font-family: Arial, sans-serif; color: #1a1a2e; margin: 0; padding: 0; font-size: 48px; }
                .header { background-color: #30b9bf; color: white; padding: 60px 80px; }
                .header h1 { margin: 0 0 16px 0; font-size: 72px; font-weight: bold; }
                .header p  { margin: 0; font-size: 40px; opacity: 0.9; }
                .section   { padding: 60px 80px; }
                .section h2 { color: #30b9bf; font-size: 44px; text-transform: uppercase; letter-spacing: 4px;
                    border-bottom: 4px solid #30b9bf; padding-bottom: 16px; margin-bottom: 40px; }
                .info-grid { width: 100%; border-collapse: collapse; margin-bottom: 40px; }
                .info-grid td { padding: 28px 32px; font-size: 44px; vertical-align: top; }
                .info-grid tr:nth-child(odd) td { background-color: #f0f9fa; }
                .label { font-weight: bold; color: #555555; width: 30%; }
                .value { color: #1a1a2e; }
                .status-badge { display: inline-block; background-color: %8; color: %9;
                    border-radius: 20px; padding: 6px 24px; font-size: 38px; font-weight: 700; }
                .comment-box { background-color: #f8fcfc; border-left: 8px solid #30b9bf;
                    padding: 40px; margin: 40px 0; font-size: 40px; line-height: 1.6; color: #333; }
                .footer { margin-top: 80px; padding: 40px 80px; border-top: 3px solid #e2e8f0;
                    font-size: 36px; color: #9ca3af; text-align: center; }
            </style>
        </head>
        <body>
            <div class="header">
                <h1>Review Report</h1>
                <p>Review ID: #%1 &nbsp;&bull;&nbsp; Generated on %2</p>
            </div>
            <div class="section">
                <h2>Review Details</h2>
                <table class="info-grid">
                    <tr><td class="label">Reviewer</td><td class="value">%3</td></tr>
                    <tr><td class="label">Review Date</td><td class="value">%4</td></tr>
                    <tr><td class="label">Submission ID</td><td class="value">%5</td></tr>
                    <tr><td class="label">Publication ID</td><td class="value">%6</td></tr>
                    <tr><td class="label">Status</td><td class="value"><span class="status-badge">%7</span></td></tr>
                </table>
                <h2>Comments</h2>
                <div class="comment-box">%10</div>
            </div>
            <div class="footer">Peerly Research Platform &bull; Exported %2</div>
        </body>
        </html>
    )")
                       .arg(QString::number(reviewId), generatedDate, reviewerName.toHtmlEscaped(), reviewDateStr,
                            QString::number(submissionId), QString::number(publicationId),
                            status.isEmpty() ? "Pending" : status.toHtmlEscaped(),
                            statusBg, statusColor,
                            comment.toHtmlEscaped().replace("\n", "<br>"));

    QTextDocument doc;
    doc.setHtml(html);
    doc.setDefaultFont(QFont("Arial", 24));
    QSizeF paperSize = printer.pageLayout().paintRectPixels(printer.resolution()).size();
    doc.setPageSize(paperSize);
    doc.print(&printer);
    QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
}

void MainWindow::on_sortReviewBtn_clicked()
{
    reviewSortAscending = !reviewSortAscending;
    ui->sortReviewBtn->setText(reviewSortAscending ? "Date ↑" : "Date ↓");
    loadReviews(reviewSortAscending, ui->searchReviewEdit->text());
}

void MainWindow::on_searchReviewBtn_clicked()
{
    loadReviews(reviewSortAscending, ui->searchReviewEdit->text());
}

//Linking Buttons
void MainWindow::on_reviewSub_clicked(){ ui->stackedWidget->setCurrentIndex(5); loadReviews(true, ""); }

void MainWindow::on_review_clicked()
{
    buildCreateReviewUI();
    ui->stackedWidget->setCurrentIndex(1);
}

// Review tab

void MainWindow::loadReviewsReadOnly()
{
    QVBoxLayout* reviewLayout = qobject_cast<QVBoxLayout*>(ui->ReviewT->layout());
    if (!reviewLayout) {
        reviewLayout = new QVBoxLayout(ui->ReviewT);
        ui->ReviewT->setLayout(reviewLayout);
    }

    QLayoutItem* item;
    while ((item = reviewLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    QSqlQuery reviewQuery;
    reviewQuery.prepare("SELECT IDREVIEW, REVIEWER_NAME, REVIEW_DATE, SUBMISSION_ID, PUBLICATION_ID, COMMENTREVIEW, STATUS FROM REVIEW ORDER BY REVIEW_DATE DESC");

    if (!reviewQuery.exec()) {
        QLabel* errorLabel = new QLabel("Error loading reviews: " + reviewQuery.lastError().text());
        errorLabel->setAlignment(Qt::AlignCenter);
        reviewLayout->addWidget(errorLabel);
        return;
    }

    bool found = false;

    while (reviewQuery.next()) {
        found = true;

        int reviewId         = reviewQuery.value(0).toInt();
        QString reviewerName = reviewQuery.value(1).toString();
        QDate reviewDate     = reviewQuery.value(2).toDate();
        int submissionId     = reviewQuery.value(3).toInt();
        int publicationId    = reviewQuery.value(4).toInt();
        QString comment      = reviewQuery.value(5).toString();
        QString status       = reviewQuery.value(6).toString();

        QString statusColor, statusBg;
        if (status == "Approved") {
            statusColor = "#15803d"; statusBg = "#dcfce7";
        } else if (status == "Rejected") {
            statusColor = "#b91c1c"; statusBg = "#fee2e2";
        } else if (status == "In Review") {
            statusColor = "#b45309"; statusBg = "#fef3c7";
        } else {
            statusColor = "#1d4ed8"; statusBg = "#dbeafe";
        }

        QFrame* card = new QFrame();
        card->setFrameShape(QFrame::StyledPanel);
        card->setMinimumHeight(130);

        QHBoxLayout* cardLayout = new QHBoxLayout(card);
        cardLayout->setContentsMargins(16, 16, 16, 16);
        cardLayout->setSpacing(16);

        QVBoxLayout* infoLayout = new QVBoxLayout();
        infoLayout->setSpacing(6);

        QHBoxLayout* nameRow = new QHBoxLayout();
        QLabel* nameLabel = new QLabel("<b>" + reviewerName + "</b>");
        nameLabel->setStyleSheet("font-size: 11pt;");

        QLabel* statusBadge = new QLabel(status.isEmpty() ? "Pending" : status);
        statusBadge->setAlignment(Qt::AlignCenter);
        statusBadge->setFixedHeight(22);
        statusBadge->setContentsMargins(10, 2, 10, 2);
        statusBadge->setStyleSheet(QString(
                                       "QLabel { background-color: %1; color: %2; border-radius: 10px; "
                                       "font-size: 9pt; font-weight: 700; padding: 2px 10px; }"
                                       ).arg(statusBg, statusColor));

        nameRow->addWidget(nameLabel);
        nameRow->addWidget(statusBadge);
        nameRow->addStretch();

        QLabel* metaLabel = new QLabel(
            "Date: " + reviewDate.toString("dd/MM/yyyy") +
            "  |  Submission ID: " + QString::number(submissionId) +
            "  |  Publication ID: " + QString::number(publicationId)
            );
        metaLabel->setStyleSheet("color: #64748b; font-size: 9pt;");

        QLabel* commentLabel = new QLabel("Comment: " + comment);
        commentLabel->setWordWrap(true);
        commentLabel->setStyleSheet("font-size: 9pt;");

        infoLayout->addLayout(nameRow);
        infoLayout->addWidget(metaLabel);
        infoLayout->addWidget(commentLabel);

        QFrame* aiBox = new QFrame();
        aiBox->setFixedSize(110, 90);
        aiBox->setStyleSheet("QFrame { border: 2px dashed #cbd5e1; border-radius: 10px; background-color: #f8fafc; }");
        QVBoxLayout* aiLayout = new QVBoxLayout(aiBox);
        aiLayout->setAlignment(Qt::AlignCenter);
        QLabel* aiLabel = new QLabel("AI Score");
        aiLabel->setAlignment(Qt::AlignCenter);
        aiLabel->setStyleSheet("font-size: 8pt; color: #94a3b8; font-weight: 600; border: none;");
        QLabel* aiValue = new QLabel("— %");
        aiValue->setAlignment(Qt::AlignCenter);
        aiValue->setStyleSheet("font-size: 11pt; font-weight: 700; color: #cbd5e1; border: none;");
        aiLayout->addWidget(aiLabel);
        aiLayout->addWidget(aiValue);

        QPushButton* pdfBtn = new QPushButton("Export PDF");
        pdfBtn->setFixedSize(100, 36);
        pdfBtn->setCursor(Qt::PointingHandCursor);
        pdfBtn->setStyleSheet(
            "QPushButton { background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
            "stop:0 #3dd4db, stop:1 #30b9bf); color: white; border: none; "
            "border-radius: 8px; font-size: 9pt; font-weight: 700; }"
            "QPushButton:hover { background-color: #22d3dd; }"
            );

        QVBoxLayout* rightLayout = new QVBoxLayout();
        rightLayout->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
        rightLayout->addWidget(pdfBtn);

        cardLayout->addLayout(infoLayout, 1);
        cardLayout->addWidget(aiBox);
        cardLayout->addLayout(rightLayout);

        reviewLayout->addWidget(card);

        connect(pdfBtn, &QPushButton::clicked, this, [=]() {
            exportReviewPDF(reviewId, reviewerName, reviewDate, submissionId, publicationId, comment, status);
        });
    }

    if (!found) {
        QLabel* emptyLabel = new QLabel("No reviews found.");
        emptyLabel->setAlignment(Qt::AlignCenter);
        emptyLabel->setStyleSheet("color: #94a3b8; font-size: 10pt;");
        reviewLayout->addWidget(emptyLabel);
    }

    reviewLayout->addStretch();
}

//********************REVIEW END****************************************************************************************************************************************//
//**********************************************************************************************************************************************************************//

//**********************************************************************************************************************************************************************//
//********************CONFERENCE START**********************************************************************************************************************************//

//1 LOAD
void MainWindow::loadConferences(bool ascending, QString searchFilter)
{
    //Clear
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

        //Delete
        connect(deleteBtn, &QPushButton::clicked, this, [=]() {
            QSqlQuery del;
            del.prepare("DELETE FROM CONFERENCE WHERE ID = ?");
            del.addBindValue(id);
            del.exec();
            loadConferences(sortAscending, ui->searchConfEdit->text());
        });

        //Edit
        connect(editBtn, &QPushButton::clicked, this, [=]() {
            showConferenceDialog(id);
        });

        //MAP
        connect(mapBtn, &QPushButton::clicked, this, [=]() {
            showConferenceMap(location, title);
        });

        //PDF
        connect(pdfBtn, &QPushButton::clicked, this, [=]() {
            QSqlQuery q;
            q.prepare("SELECT TITLE, CONF_DATE, LOCATION, PRICE FROM CONFERENCE WHERE ID = ?");
            q.addBindValue(id);
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

//2 ADD/EDIT DIALOG
void MainWindow::on_addConferenceBtn_clicked() {
    showConferenceDialog();
}

void MainWindow::showConferenceDialog(int conferenceId)
{
    //Determine if adding or editing
    bool isEditing = (conferenceId != -1);

    //Create dialog
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle(isEditing ? "Edit Conference" : "Add Conference");
    dialog->setFixedSize(600, 650);
    dialog->setAttribute(Qt::WA_StyledBackground, true);

    //Dark mode
    const bool dark = !mode;
    const QString bgPage = dark ? "#1a1f2e" : "#f6f8fc";
    const QString bgCard = dark ? "#252b3d" : "#ffffff";
    const QString border = dark ? "#3e4859" : "#e2e8f0";
    const QString txtPrimary = dark ? "#f1f5f9" : "#0f172a";
    const QString txtSub = dark ? "#8892a4" : "#64748b";

    dialog->setStyleSheet(QString("QDialog { background-color: %1; }").arg(bgPage));

    QVBoxLayout* mainLayout = new QVBoxLayout(dialog);
    mainLayout->setContentsMargins(28, 28, 28, 28);
    mainLayout->setSpacing(24);

    //Header
    QLabel* titleLabel = new QLabel(isEditing ? "Edit Conference" : "Add New Conference");
    titleLabel->setStyleSheet(QString(
                                  "font-size: 20pt; font-weight: 700; color: %1; background: transparent;"
                                  ).arg(txtPrimary));
    mainLayout->addWidget(titleLabel);

    //Form card
    QFrame* formCard = new QFrame();
    formCard->setStyleSheet(QString(
                                "QFrame { background-color: %1; border: 1.5px solid %2; border-radius: 12px; }"
                                ).arg(bgCard, border));

    QVBoxLayout* formLayout = new QVBoxLayout(formCard);
    formLayout->setSpacing(20);
    formLayout->setContentsMargins(28, 28, 28, 28);

    //Helper function to create label
    auto makeLabel = [&](const QString& text) -> QLabel* {
        QLabel* lbl = new QLabel(text);
        lbl->setStyleSheet(QString(
                               "font-size: 11pt; font-weight: 600; color: %1; background: transparent;"
                               ).arg(txtSub));
        lbl->setFixedHeight(22);
        return lbl;
    };

    //Helper function to create field group
    auto addField = [&](const QString& labelText, QWidget* widget) {
        QVBoxLayout* fieldGroup = new QVBoxLayout();
        fieldGroup->setSpacing(8);
        fieldGroup->setContentsMargins(0, 0, 0, 0);

        QLabel* label = makeLabel(labelText);
        widget->setFixedHeight(48);

        fieldGroup->addWidget(label);
        fieldGroup->addWidget(widget);

        formLayout->addLayout(fieldGroup);
    };

    //Create input fields
    QLineEdit* titleEdit = new QLineEdit();
    titleEdit->setPlaceholderText("Conference Title");
    titleEdit->setStyleSheet(QString(
                                 "QLineEdit { "
                                 "   background-color: %1; border: 1.5px solid %2; "
                                 "   border-radius: 8px; padding: 14px 16px; color: %3; font-size: 10pt; "
                                 "}"
                                 "QLineEdit:focus { border: 2px solid #30b9bf; padding: 13px 15px; }"
                                 ).arg(dark ? "#1e2433" : "#ffffff", border, txtPrimary));

    QDateEdit* dateEdit = new QDateEdit(QDate::currentDate());
    dateEdit->setCalendarPopup(true);
    dateEdit->setDisplayFormat("dd/MM/yyyy");
    //dateEdit->setMinimumDate(QDate::currentDate()); This can be placed instead of the validation
    dateEdit->setStyleSheet(QString(
                                "QDateEdit { "
                                "   background-color: %1; border: 1.5px solid %2; "
                                "   border-radius: 8px; padding: 14px 16px; color: %3; font-size: 10pt; "
                                "}"
                                "QDateEdit:focus { border: 2px solid #30b9bf; padding: 13px 15px; }"
                                "QDateEdit::drop-down { border: none; width: 24px; }"
                                ).arg(dark ? "#1e2433" : "#ffffff", border, txtPrimary));

    QLineEdit* locationEdit = new QLineEdit();
    locationEdit->setPlaceholderText("Location");
    locationEdit->setStyleSheet(QString(
                                    "QLineEdit { "
                                    "   background-color: %1; border: 1.5px solid %2; "
                                    "   border-radius: 8px; padding: 14px 16px; color: %3; font-size: 10pt; "
                                    "}"
                                    "QLineEdit:focus { border: 2px solid #30b9bf; padding: 13px 15px; }"
                                    ).arg(dark ? "#1e2433" : "#ffffff", border, txtPrimary));

    QDoubleSpinBox* priceSpin = new QDoubleSpinBox();
    priceSpin->setRange(0, 999999);
    priceSpin->setDecimals(3);
    priceSpin->setPrefix("TND ");
    priceSpin->setStyleSheet(QString(
                                 "QDoubleSpinBox { "
                                 "   background-color: %1; border: 1.5px solid %2; "
                                 "   border-radius: 8px; padding: 14px 16px; color: %3; font-size: 10pt; "
                                 "}"
                                 "QDoubleSpinBox:focus { border: 2px solid #30b9bf; padding: 13px 15px; }"
                                 "QDoubleSpinBox::up-button, QDoubleSpinBox::down-button { "
                                 "   width: 24px; border: none; background: transparent; "
                                 "}"
                                 ).arg(dark ? "#1e2433" : "#ffffff", border, txtPrimary));

    QComboBox* publicationCombo = new QComboBox();
    publicationCombo->setStyleSheet(QString(
                                        "QComboBox { "
                                        "   background-color: %1; border: 1.5px solid %2; "
                                        "   border-radius: 8px; padding: 14px 16px; color: %3; font-size: 10pt; "
                                        "}"
                                        "QComboBox:focus { border: 2px solid #30b9bf; padding: 13px 15px; }"
                                        "QComboBox::drop-down { border: none; width: 30px; }"
                                        "QComboBox::down-arrow { "
                                        "    image: none; width: 0; height: 0;"
                                        "    border-left: 5px solid transparent;"
                                        "    border-right: 5px solid transparent;"
                                        "    border-top: 6px solid %4;"
                                        "}"
                                        "QComboBox QAbstractItemView { "
                                        "    background-color: %1; border: 1.5px solid %2;"
                                        "    border-radius: 8px; padding: 6px;"
                                        "    selection-background-color: #30b9bf; selection-color: white;"
                                        "    outline: none;"
                                        "}"
                                        ).arg(dark ? "#1e2433" : "#ffffff", border, txtPrimary, dark ? "#8892a4" : "#64748b"));

    //Add all fields
    addField("Title", titleEdit);
    addField("Date", dateEdit);
    addField("Location", locationEdit);
    addField("Price (TND)", priceSpin);
    addField("Linked Publication", publicationCombo);

    //Loading the publications
    QSqlQuery pubQuery;
    pubQuery.prepare("SELECT PublicationID, DESCRIPTION FROM PUBLICATIONS");
    pubQuery.exec();

    while (pubQuery.next()) {
        int pubId = pubQuery.value(0).toInt();
        QString desc = pubQuery.value(1).toString();

        publicationCombo->addItem(
            QString("ID %1 - %2").arg(pubId).arg(desc),
            pubId
            );
    }

    mainLayout->addWidget(formCard);

    //If editing, load existing data
    if (isEditing) {
        QSqlQuery q;
        q.prepare("SELECT TITLE, CONF_DATE, LOCATION, PRICE, PUBLICATIONID FROM CONFERENCE WHERE ID = ?");
        q.addBindValue(conferenceId);
        q.exec();
        if (q.next()) {
            titleEdit->setText(q.value(0).toString());
            dateEdit->setDate(q.value(1).toDate());
            locationEdit->setText(q.value(2).toString());
            priceSpin->setValue(q.value(3).toDouble());

            int selectedPubId = q.value(4).toInt();

            for (int i = 0; i < publicationCombo->count(); ++i) {
                if (publicationCombo->itemData(i).toInt() == selectedPubId) {
                    publicationCombo->setCurrentIndex(i);
                    break;
                }
            }
        }
    }

    mainLayout->addStretch();

    //Button row
    QHBoxLayout* btnLayout = new QHBoxLayout();
    btnLayout->setSpacing(16);

    QPushButton* cancelBtn = new QPushButton("Cancel");
    cancelBtn->setFixedHeight(48);
    cancelBtn->setMinimumWidth(120);
    cancelBtn->setCursor(Qt::PointingHandCursor);
    cancelBtn->setStyleSheet(QString(
                                 "QPushButton { "
                                 "   background-color: %1; color: %2; border: 1px solid %3; "
                                 "   border-radius: 10px; padding: 12px 28px; font-size: 11pt; font-weight: 600; "
                                 "}"
                                 "QPushButton:hover { background-color: %4; }"
                                 "QPushButton:pressed { background-color: %5; }"
                                 ).arg(bgCard, txtPrimary, border, dark ? "#343d52" : "#f8fafc", dark ? "#3e4859" : "#e2e8f0"));

    QPushButton* saveBtn = new QPushButton(isEditing ? "Update" : "Add Conference");
    saveBtn->setFixedHeight(48);
    saveBtn->setMinimumWidth(160);
    saveBtn->setCursor(Qt::PointingHandCursor);
    saveBtn->setStyleSheet(
        "QPushButton { "
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
        "   stop:0 #3dd4db, stop:1 #30b9bf); color: white; border: none; "
        "   border-radius: 10px; padding: 12px 28px; font-size: 11pt; font-weight: 700; "
        "}"
        "QPushButton:hover { background-color: #22d3dd; }"
        "QPushButton:pressed { background-color: #26a0a6; }"
        );

    btnLayout->addStretch();
    btnLayout->addWidget(cancelBtn);
    btnLayout->addWidget(saveBtn);

    mainLayout->addLayout(btnLayout);

    //Connect buttons
    connect(cancelBtn, &QPushButton::clicked, dialog, &QDialog::reject);

    connect(saveBtn, &QPushButton::clicked, dialog, [=]() {
        //Validation

        // 1. Validate title (not empty)
        if (titleEdit->text().trimmed().isEmpty()) {
            QMessageBox::warning(dialog, "Validation Error",
                                 "Please enter a conference title.");
            titleEdit->setFocus();
            return;
        }

        // 2. Validate date (not before today) - only for new conferences
        if (!isEditing && dateEdit->date() < QDate::currentDate()) {
            QMessageBox::warning(dialog, "Validation Error",
                                 "Conference date cannot be in the past.");
            dateEdit->setFocus();
            return;
        }

        // 3. Validate location (not empty)
        if (locationEdit->text().trimmed().isEmpty()) {
            QMessageBox::warning(dialog, "Validation Error",
                                 "Please enter a location.");
            locationEdit->setFocus();
            return;
        }

        // 4. Validate price (cannot be negative)
        if (priceSpin->value() < 0) {
            QMessageBox::warning(dialog, "Validation Error",
                                 "Price cannot be negative.");
            priceSpin->setFocus();
            return;
        }

        // 5. Validate publication selection
        if (publicationCombo->count() == 0) {
            QMessageBox::critical(dialog, "Error",
                                  "No publications available. Please create a publication first.");
            return;
        }

        if (!publicationCombo->currentData().isValid()) {
            QMessageBox::critical(dialog, "Error",
                                  "Please select a valid publication.");
            publicationCombo->setFocus();
            return;
        }

        //Create conference object
        Conference c(
            conferenceId,
            titleEdit->text().trimmed(),
            publicationCombo->currentData().toInt(),
            dateEdit->date(),
            locationEdit->text().trimmed(),
            priceSpin->value()
            );

        //Save
        bool success = isEditing ? c.update() : c.add();

        if (success) {
            qDebug() << (isEditing ? "Conference updated" : "Conference added");
            loadConferences(sortAscending, ui->searchConfEdit->text());
            dialog->accept();
        } else {
            QMessageBox::critical(dialog, "Error",
                                  "Failed to " + QString(isEditing ? "update" : "add") + " conference.");
        }
    });

    dialog->exec();
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
        "  SUM(CASE WHEN PRICE < 10  THEN 1 ELSE 0 END), "
        "  SUM(CASE WHEN PRICE >= 10 AND PRICE < 50  THEN 1 ELSE 0 END), "
        "  SUM(CASE WHEN PRICE >= 50 AND PRICE < 100 THEN 1 ELSE 0 END), "
        "  SUM(CASE WHEN PRICE >= 100 THEN 1 ELSE 0 END) "
        "FROM CONFERENCE"
        );
    QList<QPair<QString,int>> priceData;
    if (priceQuery.next()) {
        priceData = {
            {"<10TND",     priceQuery.value(0).toInt()},
            {"10-50TND",  priceQuery.value(1).toInt()},
            {"50-100TND", priceQuery.value(2).toInt()},
            {">100TND",    priceQuery.value(3).toInt()}
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
    pillRow->addWidget(makePill("Avg Price", "TND" + QString::number(avgPrice,'f',0), "#30b9bf"));
    pillRow->addWidget(makePill("Min Price", "TND" + QString::number(minPrice,'f',0), "#16a34a"));
    pillRow->addWidget(makePill("Max Price", "TND" + QString::number(maxPrice,'f',0), "#dc2626"));
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
                        <td class="value">TND%6</td>
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

//********************CONFERENCE END*************************************************************************************************************************//
//***********************************************************************************************************************************************************//
//***********************************************************************************************************************************************************//

//**********Collabs Start**********//
int userIdForCollabs = 0; //for testing
bool MainWindow::loadCollabs()
{
    ui->collabsList->clear();
    ui->collabsDescription->clear();
    ui->collabsDescription->setEnabled(false);
    collaborations.clear();
    ui->collaborationCreationCollaborationDescriptionEdit->setEnabled(false);
    ui->collaborationCreationCollaborationTitileEdit->setEnabled(false);
    ui->collaborationCreationCollaborationDescriptionEdit->clear();
    ui->collaborationCreationCollaborationTitileEdit->clear();
    ui->collaborationCreationCancelButton->setEnabled(false);
    ui->collabsGroupChatButton->hide();

    QSqlQuery query;

    QString queryString = "SELECT * FROM collaboration WHERE authorId = ?";
    if (!ui->collabsSearchBox->toPlainText().isEmpty())
        queryString += " AND title LIKE ? ";

    if (ui->collaborationCreationSortSwitch->checkState() == Qt::CheckState::Checked)
    {
        queryString += " ORDER BY TITLE ";

        if (ui->collaborationCreationDescSwitch->checkState() == Qt::CheckState::Checked)
            queryString += " DESC ";

    }

    query.prepare(queryString);

    query.addBindValue(userIdForCollabs);

    if (!ui->collabsSearchBox->toPlainText().isEmpty())
        query.addBindValue(ui->collabsSearchBox->toPlainText().trimmed());

    if (!query.exec())
        return false;

    while (query.next()) {
        Collaboration collab(query.value(0).toInt(),
                             query.value(1).toString(),
                             query.value(2).toString(),
                             query.value(3).toInt(),
                             query.value(4).toInt());

        ui->collabsList->addItem(collab.getTitle());
        collaborations.push_back(collab);
    }

    if (collaborations.empty())
    {
        ui->collaborationCreationSortSwitch->hide();
        ui->collaborationCreationDescSwitch->hide();
    }
    else
    {
        ui->collaborationCreationSortSwitch->show();
        ui->collaborationCreationDescSwitch->show();
    }

    return true;
}

void MainWindow::on_collaborationCreationSortSwitch_clicked()
{
    if (ui->collaborationCreationSortSwitch->checkState() == Qt::CheckState::Checked) {
        ui->collaborationCreationDescSwitch->setEnabled(true);
        ui->collaborationCreationDescSwitch->show();
        qDebug() << "Sorting";
    }

    else if (ui->collaborationCreationSortSwitch->checkState() == Qt::CheckState::Unchecked) {
        ui->collaborationCreationDescSwitch->setEnabled(false);
        ui->collaborationCreationDescSwitch->hide();
        ui->collaborationCreationDescSwitch->setCheckState(Qt::CheckState::Unchecked);
    }

    loadCollabs();
}

void MainWindow::on_collaborationCreationDescSwitch_clicked()
{
    loadCollabs();
}

void MainWindow::on_collabsList_clicked()
{
    const int i = ui->collabsList->currentRow();
    ui->collaborationCreationCollaborationDescriptionEdit->setText(
        collaborations[i].getDescription());
    ui->collaborationCreationCollaborationTitileEdit->setPlainText(collaborations[i].getTitle());

    ui->collaborationCreationCollaborationDescriptionEdit->setEnabled(true);
    ui->collaborationCreationCollaborationTitileEdit->setEnabled(true);

    ui->collabsDeleteButton->setEnabled(true);
    ui->collabsGroupChatButton->setEnabled(true);
    ui->collabsExportButton->setEnabled(true);
    ui->collabsStatsButton->setEnabled(true);

    ui->collabsEditButton->setEnabled(true);

    int _ = ui->collabsList->currentRow();
    ui->collabsDescription->setText(collaborations[_].getDescription());
}

void MainWindow::on_collab_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    loadCollabs();
}

void MainWindow::on_collabsSearchBox_textChanged()
{
    loadCollabs();
}

void MainWindow::on_collaborationCreationNewButton_clicked()
{
    ui->collabsList->setCurrentRow(-1);
    ui->collaborationCreationCollaborationDescriptionEdit->clear();
    ui->collaborationCreationCollaborationTitileEdit->clear();
    ui->collaborationCreationNewButton->setEnabled(false);

    ui->collaborationCreationCollaborationDescriptionEdit->setEnabled(true);
    ui->collaborationCreationCollaborationTitileEdit->setEnabled(true);

    ui->collabsDeleteButton->setEnabled(false);
    ui->collabsGroupChatButton->setEnabled(false);
    ui->collabsExportButton->setEnabled(false);
    ui->collabsStatsButton->setEnabled(false);

    ui->collaborationCreationCancelButton->setEnabled(true);

    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_collabsEditButton_clicked()
{
    //ui->collabsList->setCurrentRow(-1);
    ui->collaborationCreationNewButton->setEnabled(false);

    ui->collaborationCreationCollaborationDescriptionEdit->setEnabled(true);
    ui->collaborationCreationCollaborationTitileEdit->setEnabled(true);

    ui->collabsDeleteButton->setEnabled(false);
    ui->collabsGroupChatButton->setEnabled(false);
    ui->collabsExportButton->setEnabled(false);
    ui->collabsStatsButton->setEnabled(false);

    ui->collaborationCreationCancelButton->setEnabled(true);

    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_collaborationCreationCancelButton_clicked()
{
    if (ui->collabsList->currentRow() >= 0) {
        const int i = ui->collabsList->currentRow();
        ui->collaborationCreationCollaborationDescriptionEdit->setText(
            collaborations[i].getDescription());
        ui->collaborationCreationCollaborationTitileEdit->setPlainText(collaborations[i].getTitle());
    } else {
        ui->collaborationCreationCollaborationDescriptionEdit->clear();
        ui->collaborationCreationCollaborationTitileEdit->clear();
        ui->collabsDeleteButton->setEnabled(false);
        ui->collabsGroupChatButton->setEnabled(false);
        ui->collabsExportButton->setEnabled(false);
        ui->collabsStatsButton->setEnabled(false);
        ui->collaborationCreationCollaborationDescriptionEdit->setEnabled(false);
        ui->collaborationCreationCollaborationDescriptionEdit->clear();
        ui->collaborationCreationCollaborationTitileEdit->setEnabled(false);
        ui->collaborationCreationCollaborationTitileEdit->clear();
    }

    ui->collaborationCreationCancelButton->setEnabled(false);
    ui->collaborationCreationNewButton->setEnabled(true);

    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_collaborationCreationConfirmButton_clicked()
{
    QString title = ui->collaborationCreationCollaborationTitileEdit->toPlainText();
    QString description = ui->collaborationCreationCollaborationDescriptionEdit->toPlainText();

    if (title.isEmpty() || description.isEmpty())
    {
        ui->collaborationCreationCollaborationTitileEdit->setPlaceholderText("Title Can't Be Blank");
        ui->collaborationCreationCollaborationDescriptionEdit->setPlaceholderText("Description Can't Be Blank");
        return;
    }

    ui->collaborationCreationCollaborationTitileEdit->setPlaceholderText("Title of The Collaboration");
    ui->collaborationCreationCollaborationDescriptionEdit->setPlaceholderText("The Description of The Collaboration");

    if (ui->collabsList->currentRow() < 0) {
        int publicationId = 0;
        Collaboration collab(0, title, description, userIdForCollabs, publicationId);
        collab.create();
    } else {
        Collaboration collab = collaborations[ui->collabsList->currentRow()];
        collab.setTitle(title);
        collab.setDescription(description);
        collab.update();
    }

    ui->collaborationCreationCancelButton->setEnabled(false);

    ui->collaborationCreationCollaborationDescriptionEdit->setEnabled(false);
    ui->collaborationCreationCollaborationDescriptionEdit->clear();
    ui->collaborationCreationCollaborationTitileEdit->setEnabled(false);
    ui->collaborationCreationCollaborationTitileEdit->clear();
    ui->collaborationCreationNewButton->setEnabled(true);

    ui->collabsDeleteButton->setEnabled(false);
    ui->collabsGroupChatButton->setEnabled(false);
    ui->collabsExportButton->setEnabled(false);
    ui->collabsStatsButton->setEnabled(false);

    loadCollabs();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_collabsDeleteButton_clicked()
{
    if (ui->collabsList->currentRow() < 0)
        return;

    const int i = ui->collabsList->currentRow();
    Collaboration collab = collaborations[i];
    collab.Delete();

    ui->collaborationCreationCollaborationDescriptionEdit->setEnabled(false);
    ui->collaborationCreationCollaborationDescriptionEdit->clear();
    ui->collaborationCreationCollaborationTitileEdit->setEnabled(false);
    ui->collaborationCreationCollaborationTitileEdit->clear();

    ui->collabsDeleteButton->setEnabled(false);
    ui->collabsGroupChatButton->setEnabled(false);
    ui->collabsExportButton->setEnabled(false);
    ui->collabsStatsButton->setEnabled(false);
    ui->collabsEditButton->setEnabled(false);
    ui->collaborationCreationCancelButton->setEnabled(false);

    loadCollabs();
}

void MainWindow::on_collaborationCreationCollaborationDescriptionEdit_textChanged()
{
    ui->collaborationCreationCancelButton->setEnabled(true);
}
void MainWindow::on_collaborationCreationCollaborationTitileEdit_textChanged()
{
    ui->collaborationCreationCancelButton->setEnabled(true);
}

//**********Collabs End**********//
//********************PUBLICATION START**********************************************************************************************************************//
// loadPublications()
void MainWindow::loadPublications(const QString &searchFilter)
{
    QLayout *oldLayout = ui->publicationListGroup->layout();
    if (oldLayout) {
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
    } else {
        ui->publicationListGroup->setLayout(new QVBoxLayout());
    }
    QVBoxLayout *listLayout = qobject_cast<QVBoxLayout *>(ui->publicationListGroup->layout());
    QList<Publication> list = searchFilter.trimmed().isEmpty()
                                  ? pubTmp.read()
                                  : pubTmp.search(searchFilter.trimmed());

    if (list.isEmpty()) {
        QLabel *empty = new QLabel("No publications found.");
        empty->setAlignment(Qt::AlignCenter);
        listLayout->addWidget(empty);
        listLayout->addStretch();
        return;
    }
    QList<Publication>::const_iterator it;
    for (it = list.begin(); it != list.end(); ++it) {

        QFrame *card = new QFrame(ui->publicationListGroup);
        card->setFrameShape(QFrame::StyledPanel);
        card->setObjectName("publicationCard");
        card->setMinimumHeight(110);

        QVBoxLayout *cardLayout = new QVBoxLayout(card);
        cardLayout->setSpacing(4);
        QLabel *metaLbl = new QLabel(
            "<b>ID:</b> "                   + QString::number(it->getPublicationID()) +
                " &nbsp;|&nbsp; <b>Author:</b> " + QString::number(it->getAuthorID())      +
                " &nbsp;|&nbsp; <b>Submission:</b> " + QString::number(it->getSubmissionID()) +
                " &nbsp;|&nbsp; <b>Field:</b> "  + it->getField()                          +
                " &nbsp;|&nbsp; <b>Date:</b> "   + it->getCreatedDate().toString("dd/MM/yyyy"),
            card);
        metaLbl->setWordWrap(true);

        QLabel *descLbl = new QLabel(it->getDescription(), card);
        descLbl->setWordWrap(true);
        QHBoxLayout *btnRow = new QHBoxLayout();
        QPushButton *editBtn    = new QPushButton("✏ Edit");
        QPushButton *deleteBtn  = new QPushButton("🗑 Delete");
        QPushButton *pdfBtn     = new QPushButton("📄 Summary PDF");
        QPushButton *mailBtn    = new QPushButton("✉ Email");
        btnRow->addWidget(editBtn);
        btnRow->addWidget(deleteBtn);
        btnRow->addWidget(pdfBtn);
        btnRow->addWidget(mailBtn);
        btnRow->addStretch();

        cardLayout->addWidget(metaLbl);
        cardLayout->addWidget(descLbl);
        cardLayout->addLayout(btnRow);
        listLayout->addWidget(card);
        const int     pubId   = it->getPublicationID();
        const int     authId  = it->getAuthorID();
        const int     subId   = it->getSubmissionID();
        const QString desc    = it->getDescription();
        const QDate   cDate   = it->getCreatedDate();
        const QString fld     = it->getField();

        // ── DELETE
        connect(deleteBtn, &QPushButton::clicked, this, [=]() {
            int confirm = QMessageBox::question(
                this, "Confirm Delete",
                "Delete publication ID " + QString::number(pubId) + "?",
                QMessageBox::Yes | QMessageBox::No);
            if (confirm == QMessageBox::Yes) {
                pubTmp.setPublicationID(pubId);
                if (pubTmp.deletePublication()) {
                    ui->statusLabel_2->setText("✔ Publication " + QString::number(pubId) + " deleted.");
                    loadPublications(ui->lineEdit_23->text());
                } else {
                    QMessageBox::critical(this, "Error", "Failed to delete publication.");
                }
            }
        });

        // ── EDIT
        connect(editBtn, &QPushButton::clicked, this, [=]() {
            showPublicationDialog(pubId, authId, subId, desc, cDate, fld);
        });

        // ── SUMMARY PDF
        connect(pdfBtn, &QPushButton::clicked, this, [=]() {
            exportPublicationPDF(pubId, authId, subId, desc, cDate, fld);
        });

        // ── EMAIL ─
        connect(mailBtn, &QPushButton::clicked, this, [=]() {
            const QString subject = "Publication #" + QString::number(pubId) + " – " + fld;
            const QString body    = "Publication ID: " + QString::number(pubId)
                                 + "\nField: "       + fld
                                 + "\nAuthor ID: "   + QString::number(authId)
                                 + "\nDescription: " + desc
                                 + "\nCreated: "     + cDate.toString("dd/MM/yyyy");
            QDesktopServices::openUrl(
                QUrl("mailto:?subject=" + QUrl::toPercentEncoding(subject)
                     + "&body="         + QUrl::toPercentEncoding(body)));
        });
    }

    listLayout->addStretch();
}

// showPublicationDialog()

void MainWindow::showPublicationDialog(int pubId, int authId, int subId,
                                       const QString &desc, const QDate &date,
                                       const QString &field)
{
    bool isEditing = (pubId != -1);

    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle(isEditing ? "Edit Publication" : "Add Publication");
    dialog->setFixedSize(520, 500);
    dialog->setAttribute(Qt::WA_StyledBackground, true);

    // ── Theme colours─
    const bool    dark       = !mode;
    const QString bgPage     = dark ? "#1a1f2e" : "#f6f8fc";
    const QString bgCard     = dark ? "#252b3d" : "#ffffff";
    const QString border     = dark ? "#3e4859" : "#e2e8f0";
    const QString txtPrimary = dark ? "#f1f5f9" : "#0f172a";
    const QString txtSub     = dark ? "#8892a4" : "#64748b";
    const QString inputBg    = dark ? "#1e2433" : "#ffffff";

    dialog->setStyleSheet(QString("QDialog { background-color: %1; }").arg(bgPage));

    QVBoxLayout *mainLayout = new QVBoxLayout(dialog);
    mainLayout->setContentsMargins(24, 24, 24, 24);
    mainLayout->setSpacing(16);

    // Title
    QLabel *titleLbl = new QLabel(isEditing ? "Edit Publication" : "Add New Publication");
    titleLbl->setStyleSheet(QString(
                                "font-size: 18pt; font-weight: 700; color: %1; background: transparent;"
                                ).arg(txtPrimary));
    mainLayout->addWidget(titleLbl);

    // Form card
    QFrame *formCard = new QFrame();
    formCard->setStyleSheet(QString(
                                "QFrame { background-color: %1; border: 1.5px solid %2; border-radius: 12px; }"
                                ).arg(bgCard, border));
    QVBoxLayout *formLayout = new QVBoxLayout(formCard);
    formLayout->setSpacing(12);
    formLayout->setContentsMargins(20, 20, 20, 20);

    const QString inputStyle = QString(
                                   "QLineEdit, QTextEdit, QSpinBox, QComboBox { "
                                   "  background-color: %1; border: 1.5px solid %2; "
                                   "  border-radius: 8px; padding: 10px 12px; color: %3; font-size: 10pt; }"
                                   "QLineEdit:focus, QTextEdit:focus, QSpinBox:focus, QComboBox:focus "
                                   "  { border: 2px solid #30b9bf; }"
                                   ).arg(inputBg, border, txtPrimary);

    auto makeLabel = [&](const QString &text) -> QLabel * {
        QLabel *lbl = new QLabel(text);
        lbl->setStyleSheet(QString(
                               "font-size: 10pt; font-weight: 600; color: %1; background: transparent;"
                               ).arg(txtSub));
        return lbl;
    };

    // Author ID
    QSpinBox *authSpin = new QSpinBox();
    authSpin->setRange(1, 999999);
    authSpin->setValue(isEditing ? authId : 1);
    authSpin->setStyleSheet(inputStyle);
    formLayout->addWidget(makeLabel("Author ID"));
    formLayout->addWidget(authSpin);

    // Submission ID
    QSpinBox *subSpin = new QSpinBox();
    subSpin->setRange(1, 999999);
    subSpin->setValue(isEditing ? subId : 1);
    subSpin->setStyleSheet(inputStyle);
    formLayout->addWidget(makeLabel("Submission ID"));
    formLayout->addWidget(subSpin);

    // Field
    QComboBox *fieldCombo = new QComboBox();
    fieldCombo->addItems({"Computer Science", "Mathematics", "Physics",
                          "Biology", "Chemistry", "Medicine", "Engineering", "Other"});
    if (isEditing) {
        int idx = fieldCombo->findText(field);
        if (idx >= 0) fieldCombo->setCurrentIndex(idx);
    }
    fieldCombo->setStyleSheet(inputStyle);
    formLayout->addWidget(makeLabel("Field / Category"));
    formLayout->addWidget(fieldCombo);

    // Description
    QTextEdit *descEdit = new QTextEdit();
    descEdit->setPlaceholderText("Enter publication description (max 300 characters)…");
    descEdit->setFixedHeight(90);
    descEdit->setStyleSheet(inputStyle);
    if (isEditing) descEdit->setPlainText(desc);
    formLayout->addWidget(makeLabel("Description"));
    formLayout->addWidget(descEdit);

    mainLayout->addWidget(formCard);
    mainLayout->addStretch();

    // ── Button row
    QHBoxLayout *btnRow = new QHBoxLayout();

    QPushButton *cancelBtn = new QPushButton("Cancel");
    cancelBtn->setFixedHeight(44);
    cancelBtn->setStyleSheet(QString(
                                 "QPushButton { background-color: %1; color: %2; border: 1px solid %3; "
                                 "border-radius: 10px; padding: 10px 24px; font-size: 10pt; font-weight: 600; }"
                                 "QPushButton:hover { background-color: %4; }"
                                 ).arg(bgCard, txtPrimary, border, dark ? "#343d52" : "#f8fafc"));

    QPushButton *saveBtn = new QPushButton(isEditing ? "Update" : "Add Publication");
    saveBtn->setFixedHeight(44);
    saveBtn->setStyleSheet(
        "QPushButton { background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
        "stop:0 #3dd4db, stop:1 #30b9bf); color: white; border: none; "
        "border-radius: 10px; padding: 10px 24px; font-size: 10pt; font-weight: 700; }"
        "QPushButton:hover { background-color: #22d3dd; }"
        );

    btnRow->addStretch();
    btnRow->addWidget(cancelBtn);
    btnRow->addWidget(saveBtn);
    mainLayout->addLayout(btnRow);

    connect(cancelBtn, &QPushButton::clicked, dialog, &QDialog::reject);

    connect(saveBtn, &QPushButton::clicked, this, [=]() {

        // ── Input validation
        if (descEdit->toPlainText().trimmed().isEmpty()) {
            QMessageBox::warning(dialog, "Validation Error", "Description cannot be empty.");
            return;
        }
        if (descEdit->toPlainText().trimmed().length() > 300) {
            QMessageBox::warning(dialog, "Validation Error",
                                 "Description must not exceed 300 characters.");
            return;
        }

        if (isEditing) pubTmp.setPublicationID(pubId);
        pubTmp.setAuthorID    (authSpin->value());
        pubTmp.setSubmissionID(subSpin->value());
        pubTmp.setDescription (descEdit->toPlainText().trimmed());
        pubTmp.setCreatedDate (QDate::currentDate());
        pubTmp.setField       (fieldCombo->currentText());

        bool ok = isEditing ? pubTmp.update() : pubTmp.create();

        if (ok) {
            ui->statusLabel_2->setText(
                isEditing ? "✔ Publication updated successfully."
                          : "✔ Publication added successfully.");
            loadPublications(ui->lineEdit_23->text());
            dialog->accept();
        } else {
            QMessageBox::critical(dialog, "Database Error",
                                  QString("Failed to %1 publication. Check the DB connection.")
                                      .arg(isEditing ? "update" : "add"));
        }
    });

    dialog->exec();
}
// exportPublicationPDF()
void MainWindow::exportPublicationPDF(int pubId, int authId, int subId,
                                      const QString &desc, const QDate &date,
                                      const QString &field)
{
    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Export Publication PDF",
        QDir::homePath() + "/Publication_" + QString::number(pubId) + ".pdf",
        "PDF Files (*.pdf)"
        );
    if (filePath.isEmpty()) return;

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setPageLayout(QPageLayout(
        QPageSize(QPageSize::A4),
        QPageLayout::Portrait,
        QMarginsF(15, 15, 15, 15),
        QPageLayout::Millimeter
        ));

    const QString generatedDate = QDate::currentDate().toString("MMMM dd, yyyy");
    const QString createdStr    = date.toString("MMMM dd, yyyy");

    QString html = QString(R"(
        <html><head><style>
            body       { font-family: Arial, sans-serif; color: #1a1a2e;
                         margin: 0; padding: 0; font-size: 48px; }
            .header    { background-color: #30b9bf; color: white; padding: 60px 80px; }
            .header h1 { margin: 0 0 16px 0; font-size: 72px; font-weight: bold; }
            .header p  { margin: 0; font-size: 40px; opacity: 0.9; }
            .section   { padding: 60px 80px; }
            .section h2 { color: #30b9bf; font-size: 44px; text-transform: uppercase;
                          letter-spacing: 4px; border-bottom: 4px solid #30b9bf;
                          padding-bottom: 16px; margin-bottom: 40px; }
            .info-grid { width: 100%; border-collapse: collapse; margin-bottom: 40px; }
            .info-grid td        { padding: 28px 32px; font-size: 44px; vertical-align: top; }
            .info-grid tr:nth-child(odd) td { background-color: #f0f9fa; }
            .label     { font-weight: bold; color: #555555; width: 30%; }
            .value     { color: #1a1a2e; }
            .desc-box  { background-color: #f8fcfc; border-left: 8px solid #30b9bf;
                         padding: 40px; margin: 40px 0; font-size: 40px;
                         line-height: 1.6; color: #333; }
            .footer    { margin-top: 80px; padding: 40px 80px;
                         border-top: 3px solid #e2e8f0; font-size: 36px;
                         color: #9ca3af; text-align: center; }
        </style></head><body>
            <div class="header">
                <h1>Publication Report</h1>
                <p>Publication ID: #%1 &nbsp;&bull;&nbsp; Generated on %2</p>
            </div>
            <div class="section">
                <h2>Publication Details</h2>
                <table class="info-grid">
                    <tr><td class="label">Publication ID</td><td class="value">%1</td></tr>
                    <tr><td class="label">Author ID</td>     <td class="value">%3</td></tr>
                    <tr><td class="label">Submission ID</td> <td class="value">%4</td></tr>
                    <tr><td class="label">Field</td>         <td class="value">%5</td></tr>
                    <tr><td class="label">Created Date</td>  <td class="value">%6</td></tr>
                </table>
                <h2>Description</h2>
                <div class="desc-box">%7</div>
            </div>
            <div class="footer">Peerly Research Platform &bull; Exported %2</div>
        </body></html>
    )")
                       .arg(QString::number(pubId),
                            generatedDate,
                            QString::number(authId),
                            QString::number(subId),
                            field.toHtmlEscaped(),
                            createdStr,
                            desc.toHtmlEscaped().replace("\n", "<br>"));

    QTextDocument doc;
    doc.setHtml(html);
    doc.setDefaultFont(QFont("Arial", 24));
    doc.setPageSize(printer.pageLayout().paintRectPixels(printer.resolution()).size());
    doc.print(&printer);

    QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
}
// BUTTON SLOTS
// ADD
void MainWindow::on_addButton_clicked()
{
    //Input validation
    if (ui->titleEdit->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a publication title / description.");
        return;
    }
    if (ui->descriptionEdit->toPlainText().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Description cannot be empty.");
        return;
    }
    pubTmp.setAuthorID(1);
    pubTmp.setSubmissionID(1);
    pubTmp.setDescription(ui->descriptionEdit->toPlainText().trimmed());
    pubTmp.setCreatedDate(QDate::currentDate());
    pubTmp.setField(ui->categoryCombo->currentText());

    //CREATE
    if (pubTmp.create()) {
        ui->statusLabel_2->setText("Publication added successfully.");
        ui->titleEdit->clear();
        ui->descriptionEdit->clear();
        ui->categoryCombo->setCurrentIndex(0);
        loadPublications(ui->lineEdit_23->text());
    } else {
        QMessageBox::critical(this, "Database Error",
                              "Failed to add publication. Check the DB connection.");
    }
}

// DELETE
void MainWindow::on_deleteButton_clicked()
{
    bool ok;
    int id = ui->titleEdit->text().trimmed().toInt(&ok);

    if (!ok || id <= 0) {
        QMessageBox::warning(this, "Input Error",
                             "Enter a valid numeric Publication ID in the title field to delete.");
        return;
    }

    int confirm = QMessageBox::question(
        this, "Confirm Delete",
        "Delete publication with ID " + QString::number(id) + "?",
        QMessageBox::Yes | QMessageBox::No);

    if (confirm == QMessageBox::Yes) {
        pubTmp.setPublicationID(id);
        if (pubTmp.deletePublication()) {
            ui->statusLabel_2->setText("Publication " + QString::number(id) + " deleted.");
            ui->titleEdit->clear();
            loadPublications(ui->lineEdit_23->text());
        } else {
            QMessageBox::critical(this, "Database Error", "Failed to delete publication.");
        }
    }
}

// SEARCH
void MainWindow::on_searchbt_clicked()
{
    loadPublications(ui->lineEdit_23->text());
}

//SUMMARY
void MainWindow::on_summaryButton_clicked()
{
    bool ok;
    int id = ui->titleEdit->text().trimmed().toInt(&ok);
    if (!ok || id <= 0) {
        ui->statusLabel_2->setText("Enter a Publication ID in the title field, then click Summary.");
        return;
    }

    QList<Publication> list = pubTmp.read();
    QList<Publication>::const_iterator it;
    for (it = list.begin(); it != list.end(); ++it) {
        if (it->getPublicationID() == id) {
            exportPublicationPDF(it->getPublicationID(), it->getAuthorID(),
                                 it->getSubmissionID(),  it->getDescription(),
                                 it->getCreatedDate(),   it->getField());
            return;
        }
    }
    ui->statusLabel_2->setText("Publication ID not found.");
}

//EMAIL
void MainWindow::on_emailButton_clicked()
{
    bool ok;
    int id = ui->titleEdit->text().trimmed().toInt(&ok);
    if (!ok || id <= 0) {
        ui->statusLabel_2->setText("Enter a Publication ID in the title field, then click Email.");
        return;
    }
    QList<Publication> list = pubTmp.read();
    QList<Publication>::const_iterator it;
    for (it = list.begin(); it != list.end(); ++it) {
        if (it->getPublicationID() == id) {
            const QString subject = "Publication #" + QString::number(id) + " – " + it->getField();
            const QString body    = "Publication ID: " + QString::number(id)
                                 + "\nField: "       + it->getField()
                                 + "\nAuthor ID: "   + QString::number(it->getAuthorID())
                                 + "\nDescription: " + it->getDescription()
                                 + "\nCreated: "     + it->getCreatedDate().toString("dd/MM/yyyy");
            QDesktopServices::openUrl(
                QUrl("mailto:?subject=" + QUrl::toPercentEncoding(subject)
                     + "&body="         + QUrl::toPercentEncoding(body)));
            return;
        }
    }
    ui->statusLabel_2->setText("Publication ID not found.");
}

// NAVIGATION
void MainWindow::on_publication_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    loadPublications("");
}
//STATS BUTTON
void MainWindow::on_pubStatsBtn_clicked()
{
    showPublicationStats();
}

void MainWindow::showPublicationStats()
{
    const bool dark = !mode;

    //Theme 
    const QString bgPage         = dark ? "#2a3142" : "#f6f8fc";
    const QString bgCard         = dark ? "#343d52" : "#ffffff";
    const QString bgScrollbar    = dark ? "#2a3142" : "#f6f8fc";
    const QString bgScrollHandle = dark ? "#545e73" : "#c0d0e8";

    const QString border         = dark ? "#4a5568" : "#e2e8f0";
    const QString divColor       = dark ? "#3e4859" : "#e2e8f0";

    const QString txtPrimary     = dark ? "#e0e7f1" : "#1f2937";
    const QString txtSub         = dark ? "#8892a4" : "#9ca3af";
    const QString txtSection     = dark ? "#8892a4" : "#9ca3af";

    const QString btnBg          = dark ? "#3e4859" : "#ffffff";
    const QString btnTxt         = dark ? "#e0e7f1" : "#1f2937";
    const QString btnHover       = dark ? "#4a5568" : "#f1f5f9";
    const QString btnPressed     = dark ? "#545e73" : "#e2e8f0";

    // QPainter colours
    const QColor cWhite  (0xff, 0xff, 0xff);
    const QColor cTeal   (0x30, 0xb9, 0xbf);
    const QColor cIndigo (0x63, 0x66, 0xf1);
    const QColor cAmber  (0xf5, 0x9e, 0x0b);
    const QColor cRed    (0xdc, 0x26, 0x26);
    const QColor cGreen  (0x16, 0xa3, 0x4a);
    const QColor cPink   (0xec, 0x48, 0x99);
    const QColor cPurple (0x8b, 0x5c, 0xf6);
    const QColor cShadow (0x00, 0x00, 0x00, 18);

    const QColor cGray     = dark ? QColor(0xa0,0xae,0xc0) : QColor(0x6b,0x72,0x80);
    const QColor cLightBg  = dark ? QColor(0x3e,0x48,0x59) : QColor(0xf1,0xf5,0xf9);
    const QColor cText     = dark ? QColor(0xe0,0xe7,0xf1) : QColor(0x1f,0x29,0x37);
    const QColor cSubText  = dark ? QColor(0x88,0x92,0xa4) : QColor(0x9c,0xa3,0xaf);
    const QColor cHoleBg   = dark ? QColor(0x34,0x3d,0x52) : QColor(0xff,0xff,0xff);
    const QColor cValueTxt = dark ? QColor(0xe0,0xe7,0xf1) : QColor(0x1f,0x29,0x37);

    // ── DB Queries ─────
    //Total count
    QSqlQuery totalQ;
    totalQ.exec("SELECT COUNT(*) FROM PUBLICATIONS");
    int total = 0;
    if (totalQ.next()) total = totalQ.value(0).toInt();

    //Publications per field (for bar + pie chart)
    QSqlQuery fieldQ;
    fieldQ.exec(
        "SELECT FIELD, COUNT(*) AS cnt "
        "FROM PUBLICATIONS "
        "GROUP BY FIELD "
        "ORDER BY cnt DESC"
        );
    QList<QPair<QString,int>> fieldData;
    while (fieldQ.next())
        fieldData.append({fieldQ.value(0).toString(), fieldQ.value(1).toInt()});

    //Publications per month – last 6 months
    QSqlQuery monthQ;
    monthQ.exec(
        "SELECT TO_CHAR(CREATEDDATE, 'Mon'), COUNT(*) "
        "FROM PUBLICATIONS "
        "WHERE CREATEDDATE >= ADD_MONTHS(SYSDATE, -6) "
        "GROUP BY TO_CHAR(CREATEDDATE, 'Mon'), TO_CHAR(CREATEDDATE, 'MM') "
        "ORDER BY TO_CHAR(CREATEDDATE, 'MM')"
        );
    QList<QPair<QString,int>> monthData;
    while (monthQ.next())
        monthData.append({monthQ.value(0).toString(), monthQ.value(1).toInt()});

    //Top author
    QSqlQuery topAuthorQ;
    topAuthorQ.exec(
        "SELECT AUTHORID, COUNT(*) AS cnt "
        "FROM PUBLICATIONS "
        "GROUP BY AUTHORID "
        "ORDER BY cnt DESC "
        "FETCH FIRST 1 ROWS ONLY"
        );
    QString topAuthor = "N/A";
    int topAuthorCount = 0;
    if (topAuthorQ.next()) {
        topAuthor      = "ID " + topAuthorQ.value(0).toString();
        topAuthorCount = topAuthorQ.value(1).toInt();
    }

    //Most recent publication
    QSqlQuery recentQ;
    recentQ.exec(
        "SELECT PUBLICATIONID, FIELD, CREATEDDATE "
        "FROM PUBLICATIONS "
        "ORDER BY CREATEDDATE DESC "
        "FETCH FIRST 1 ROWS ONLY"
        );
    QString recentField = "";
    QString recentDate  = "";
    int     recentId    = -1;
    if (recentQ.next()) {
        recentId    = recentQ.value(0).toInt();
        recentField = recentQ.value(1).toString();
        recentDate  = recentQ.value(2).toDate().toString("MMM dd, yyyy");
    }

    //Dialog + scroll area 
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("Publication Statistics");
    dialog->setFixedSize(600, 640);
    dialog->setAttribute(Qt::WA_StyledBackground, true);

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

    // Header
    QLabel* titleLabel = new QLabel("Publication Statistics");
    titleLabel->setStyleSheet(QString(
                                  "font-size: 16px; font-weight: bold; color: %1; background: transparent;"
                                  ).arg(txtPrimary));

    QLabel* subLabel = new QLabel(
        QString::number(total) + " total publications  ·  " +
        QString::number(fieldData.size()) + " fields  ·  Top author: " + topAuthor
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
        int padLeft  = 100;   
        int padRight = 20;
        int padTop   = 16;
        int padBot   = 16;
        int barAreaW = pixmap.width() - padLeft - padRight;
        int totalH   = pixmap.height() - padTop - padBot;
        int barH     = qMax(18, (totalH / qMax(n,1)) - 10);
        int gap      = qMax(6,  (totalH - barH * n) / (n + 1));

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

    // ── Donut pie chart helper
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

        int tot = 0;
        for (const auto& d : data) tot += d.second;

        QPixmap pixmap(552, size + 20);
        pixmap.fill(Qt::transparent);
        QPainter painter(&pixmap);
        painter.setRenderHint(QPainter::Antialiasing);

        if (tot == 0) {
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

        painter.setPen(Qt::NoPen);
        painter.setBrush(cShadow);
        painter.drawEllipse(pieRect.adjusted(4, 4, 4, 4));

        double startAngle = 90.0;
        for (int i = 0; i < data.size(); ++i) {
            if (data[i].second == 0) continue;
            double sweepAngle = (double)data[i].second / tot * 360.0;

            painter.setPen(Qt::NoPen);
            painter.setBrush(colors[i % colors.size()]);
            painter.drawPie(pieRect, (int)(startAngle * 16), (int)(sweepAngle * 16));

            painter.setPen(QPen(dark ? QColor(0x34,0x3d,0x52) : cWhite, 2));
            painter.setBrush(Qt::NoBrush);
            painter.drawPie(pieRect, (int)(startAngle * 16), (int)(sweepAngle * 16));

            startAngle += sweepAngle;
        }

        int holeSize = pieSize / 2;
        int holeX    = pieX + (pieSize - holeSize) / 2;
        int holeY    = pieY + (pieSize - holeSize) / 2;
        painter.setPen(Qt::NoPen);
        painter.setBrush(cHoleBg);
        painter.drawEllipse(holeX, holeY, holeSize, holeSize);

        painter.setPen(cText);
        painter.setFont(QFont("Arial", 13, QFont::Bold));
        painter.drawText(QRect(holeX, holeY, holeSize, holeSize / 2 + 4),
                         Qt::AlignCenter, QString::number(tot));
        painter.setPen(cSubText);
        painter.setFont(QFont("Arial", 8));
        painter.drawText(QRect(holeX, holeY + holeSize / 2 - 4, holeSize, holeSize / 2),
                         Qt::AlignCenter, "total");

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

            double pct = (double)data[i].second / tot * 100.0;
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

    // ── Stat pill helper 
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

    // ── BUILD LAYOUT ──────────────────────────────────────────────────────

    // Overview pills
    mainLayout->addWidget(makeSection("Overview"));
    QHBoxLayout* overviewRow = new QHBoxLayout();
    overviewRow->setSpacing(10);
    overviewRow->addWidget(makePill("Total Publications", QString::number(total),           "#30b9bf"));
    overviewRow->addWidget(makePill("Fields Covered",     QString::number(fieldData.size()),"#6366f1"));
    overviewRow->addWidget(makePill("Top Author",         topAuthor,                        "#f59e0b"));
    overviewRow->addWidget(makePill("Author's Pubs",      QString::number(topAuthorCount),  "#16a34a"));
    mainLayout->addLayout(overviewRow);

    // Publications by field 
    if (!fieldData.isEmpty()) {
        mainLayout->addWidget(makeSection("Publications by Field"));
        int barH = qMax(100, fieldData.size() * 38 + 32);
        mainLayout->addWidget(makeBarChart(fieldData, cTeal, barH));
    }
    if (!fieldData.isEmpty()) {
        mainLayout->addWidget(makeSection("Field Distribution"));
        mainLayout->addWidget(makePieChart(fieldData, 200));
    }

    // Monthly activity – last 6 months
    if (!monthData.isEmpty()) {
        mainLayout->addWidget(makeSection("Activity — Last 6 Months"));
        mainLayout->addWidget(makeBarChart(
            monthData, cIndigo,
            qMax(90, monthData.size() * 36 + 32)
            ));
    }

    // Most recent publication card
    if (recentId != -1) {
        mainLayout->addWidget(makeSection("Most Recent Publication"));

        QFrame* recentCard = new QFrame();
        recentCard->setAttribute(Qt::WA_StyledBackground, true);
        recentCard->setFixedHeight(56);
        recentCard->setStyleSheet(QString(
                                      "QFrame { background-color: %1; border: 1px solid %2; border-radius: 10px; }"
                                      ).arg(bgCard, border));

        QHBoxLayout* rl = new QHBoxLayout(recentCard);
        rl->setContentsMargins(16, 0, 16, 0);

        QLabel* rt = new QLabel("📄  #" + QString::number(recentId) + "  —  " + recentField);
        rt->setStyleSheet(QString(
                              "font-size: 10pt; font-weight: bold; color: %1;"
                              "background: transparent; border: none;"
                              ).arg(txtPrimary));

        QLabel* rd = new QLabel(recentDate);
        rd->setStyleSheet(
            "font-size: 10pt; color: #16a34a;"
            "background: transparent; border: none;"
            );
        rd->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

        rl->addWidget(rt);
        rl->addStretch();
        rl->addWidget(rd);
        mainLayout->addWidget(recentCard);
    }

    mainLayout->addStretch();

    // ── Close button ──────────────────────────────────────────────────────
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


//********************PUBLICATION END************************************************************************************************************************//


void MainWindow::on_homeButton_clicked(){ ui->stackedWidget->setCurrentIndex(0);}


void MainWindow::on_profile_clicked(){ui->stackedWidget->setCurrentIndex(3);}






void MainWindow::on_Research_clicked(){ ui->stackedWidget->setCurrentIndex(7);}

void MainWindow::on_temp_clicked(){ui->stackedWidget->setCurrentIndex(0);}





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

//************SUBMISSION START***************************//

void MainWindow::on_addSubmissionBtn_clicked()
{
    editingSubmissionId = -1;
    showSubmissionDialog();
}

void MainWindow::on_deleteSubmissionBtn_clicked()
{
    if (editingSubmissionId == -1) {
        QMessageBox::warning(this, "Warning", "Please select a submission to delete");
        return;
    }

    int response = QMessageBox::question(this, "Confirm Delete", 
        "Are you sure you want to delete this submission?",
        QMessageBox::Yes | QMessageBox::No);

    if (response == QMessageBox::Yes) {
        Submission sub;
        sub.setSubmissionID(editingSubmissionId);
        if (sub.deleteSubmission()) {
            QMessageBox::information(this, "Success", "Submission deleted successfully");
            editingSubmissionId = -1;
            loadSubmissions();
            clearSubmissionForm();
        } else {
            QMessageBox::critical(this, "Error", "Failed to delete submission");
        }
    }
}

void MainWindow::on_searchSubmissionBtn_clicked()
{
    bool ok;
    QString searchText = QInputDialog::getText(this, "Search Submissions",
                                               "Enter submission title to search:",
                                               QLineEdit::Normal, "", &ok);
    if (ok && !searchText.isEmpty()) {
        loadSubmissions(searchText);
    } else if (ok && searchText.isEmpty()) {
        loadSubmissions(); // Load all if empty search
    }
}

void MainWindow::on_refreshSubmissionBtn_clicked()
{
    loadSubmissions();
    clearSubmissionForm();
}

void MainWindow::on_editSubmissionBtn_clicked()
{
    if (editingSubmissionId == -1) {
        QMessageBox::warning(this, "Warning", "Please select a submission to edit");
        return;
    }

    Submission sub;
    QList<Submission> subs = sub.read();
    
    for (const Submission &s : subs) {
        if (s.getSubmissionID() == editingSubmissionId) {
            showSubmissionDialog(
                s.getSubmissionID(),
                s.getTitle(),
                s.getStatus(),
                s.getSourcesCitation(),
                s.getAuthorID(),
                s.getTopicID(),
                s.getManuscript()
            );
            break;
        }
    }
}

void MainWindow::on_submissionStatusChanged(const QString &newStatus)
{
    if (editingSubmissionId != -1) {
        Submission sub;
        QList<Submission> subs = sub.read();
        
        for (Submission &s : subs) {
            if (s.getSubmissionID() == editingSubmissionId) {
                s.setStatus(newStatus);
                if (s.update()) {
                    QMessageBox::information(this, "Success", "Submission status updated");
                    loadSubmissions();
                } else {
                    QMessageBox::critical(this, "Error", "Failed to update status");
                }
                break;
            }
        }
    }
}

void MainWindow::loadSubmissions(const QString &searchFilter)
{
    // Get the table widget from UI
    if (!submissionTableWidget) {
        submissionTableWidget = findChild<QTableWidget *>("submissionTableWidget");
        if (!submissionTableWidget) {
            qDebug() << "ERROR: submissionTableWidget not found in UI!";
            return;
        }
        
        // Setup table columns
        submissionTableWidget->setColumnCount(5);
        QStringList headers = {"ID", "Title", "Status", "Author ID", "Created Date"};
        submissionTableWidget->setHorizontalHeaderLabels(headers);
        submissionTableWidget->horizontalHeader()->setStretchLastSection(true);
        submissionTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        submissionTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        
        // Connect table selection to populate form (only once)
        connect(submissionTableWidget, &QTableWidget::itemSelectionChanged, this, [this]() {
            if (submissionTableWidget->selectedItems().count() > 0) {
                int selectedRow = submissionTableWidget->currentRow();
                if (selectedRow >= 0) {
                    QString idStr = submissionTableWidget->item(selectedRow, 0)->text();
                    editingSubmissionId = idStr.toInt();
                    qDebug() << "Selected submission ID:" << editingSubmissionId;
                }
            }
        });
    }

    // Clear existing rows
    submissionTableWidget->setRowCount(0);

    // Load submissions from database
    Submission sub;
    QList<Submission> submissions;
    
    if (!searchFilter.isEmpty()) {
        submissions = sub.searchByTitle(searchFilter);
    } else {
        submissions = sub.read();
    }

    // Populate table
    int row = 0;
    for (const Submission &s : submissions) {
        submissionTableWidget->insertRow(row);
        
        // ID
        QTableWidgetItem *idItem = new QTableWidgetItem(QString::number(s.getSubmissionID()));
        idItem->setFlags(idItem->flags() & ~Qt::ItemIsEditable);
        submissionTableWidget->setItem(row, 0, idItem);
        
        // Title
        QTableWidgetItem *titleItem = new QTableWidgetItem(s.getTitle());
        titleItem->setFlags(titleItem->flags() & ~Qt::ItemIsEditable);
        submissionTableWidget->setItem(row, 1, titleItem);
        
        // Status
        QTableWidgetItem *statusItem = new QTableWidgetItem(s.getStatus());
        statusItem->setFlags(statusItem->flags() & ~Qt::ItemIsEditable);
        submissionTableWidget->setItem(row, 2, statusItem);
        
        // Author ID
        QTableWidgetItem *authorItem = new QTableWidgetItem(QString::number(s.getAuthorID()));
        authorItem->setFlags(authorItem->flags() & ~Qt::ItemIsEditable);
        submissionTableWidget->setItem(row, 3, authorItem);
        
        // Created Date
        QTableWidgetItem *dateItem = new QTableWidgetItem(s.getCreatedAt().toString("yyyy-MM-dd"));
        dateItem->setFlags(dateItem->flags() & ~Qt::ItemIsEditable);
        submissionTableWidget->setItem(row, 4, dateItem);
        
        row++;
    }

    qDebug() << "Loaded" << submissions.count() << "submissions into table";
}

void MainWindow::showSubmissionDialog(int submissionId,
                                       const QString &title,
                                       const QString &status,
                                       const QString &citation,
                                       int authorID,
                                       int topicID,
                                       const QString &manuscript)
{
    editingSubmissionId = submissionId;

    QDialog dialog(this);
    dialog.setWindowTitle(submissionId == -1 ? "New Submission" : "Edit Submission");
    dialog.setGeometry(100, 100, 600, 600);

    QVBoxLayout *layout = new QVBoxLayout(&dialog);

    // Title
    QHBoxLayout *titleLayout = new QHBoxLayout();
    QLabel *titleLabel = new QLabel("Title:");
    QLineEdit *titleEdit = new QLineEdit();
    titleEdit->setText(title);
    titleEdit->setPlaceholderText("Enter submission title");
    titleLayout->addWidget(titleLabel);
    titleLayout->addWidget(titleEdit);
    layout->addLayout(titleLayout);

    // Status
    QHBoxLayout *statusLayout = new QHBoxLayout();
    QLabel *statusLabel = new QLabel("Status:");
    QComboBox *statusCombo = new QComboBox();
    statusCombo->addItems({"Draft", "Submitted", "Under Review", "Revision Required", "Accepted", "Rejected"});
    statusCombo->setCurrentText(status.isEmpty() ? "Draft" : status);
    statusLayout->addWidget(statusLabel);
    statusLayout->addWidget(statusCombo);
    layout->addLayout(statusLayout);

    // Author ID
    QHBoxLayout *authorLayout = new QHBoxLayout();
    QLabel *authorLabel = new QLabel("Author ID:");
    QSpinBox *authorSpinBox = new QSpinBox();
    authorSpinBox->setValue(authorID);
    authorSpinBox->setMinimum(1);
    authorLayout->addWidget(authorLabel);
    authorLayout->addWidget(authorSpinBox);
    layout->addLayout(authorLayout);

    // Topic ID
    QHBoxLayout *topicLayout = new QHBoxLayout();
    QLabel *topicLabel = new QLabel("Topic ID:");
    QSpinBox *topicSpinBox = new QSpinBox();
    topicSpinBox->setValue(topicID);
    topicSpinBox->setMinimum(1);
    topicLayout->addWidget(topicLabel);
    topicLayout->addWidget(topicSpinBox);
    layout->addLayout(topicLayout);

    // Citation File Dialog
    QHBoxLayout *citationLayout = new QHBoxLayout();
    QLabel *citationLabel = new QLabel("Sources Citation:");
    QLineEdit *citationEdit = new QLineEdit();
    citationEdit->setText(citation);
    citationEdit->setPlaceholderText("No file selected");
    citationEdit->setReadOnly(true);
    QPushButton *citationBtn = new QPushButton("Browse...");
    citationLayout->addWidget(citationLabel);
    citationLayout->addWidget(citationEdit);
    citationLayout->addWidget(citationBtn);
    layout->addLayout(citationLayout);

    // File path storage
    selectedCitationPath = citation;
    selectedManuscriptPath = manuscript;

    connect(citationBtn, &QPushButton::clicked, [this, &dialog, citationEdit]() {
        QString fileName = QFileDialog::getOpenFileName(&dialog, "Select Citation File", "", 
                                                         "Text Files (*.txt);;PDF Files (*.pdf);;All Files (*)");
        if (!fileName.isEmpty()) {
            selectedCitationPath = fileName;
            citationEdit->setText(fileName.split('/').last());
        }
    });

    // Manuscript File Dialog
    QHBoxLayout *manuscriptLayout = new QHBoxLayout();
    QLabel *manuscriptLabel = new QLabel("Manuscript:");
    QLineEdit *manuscriptEdit = new QLineEdit();
    manuscriptEdit->setText(manuscript);
    manuscriptEdit->setPlaceholderText("No file selected");
    manuscriptEdit->setReadOnly(true);
    QPushButton *manuscriptBtn = new QPushButton("Browse...");
    manuscriptLayout->addWidget(manuscriptLabel);
    manuscriptLayout->addWidget(manuscriptEdit);
    manuscriptLayout->addWidget(manuscriptBtn);
    layout->addLayout(manuscriptLayout);

    connect(manuscriptBtn, &QPushButton::clicked, [this, &dialog, manuscriptEdit]() {
        QString fileName = QFileDialog::getOpenFileName(&dialog, "Select Manuscript File", "", 
                                                         "Text Files (*.txt);;PDF Files (*.pdf);;Word Files (*.docx);;All Files (*)");
        if (!fileName.isEmpty()) {
            selectedManuscriptPath = fileName;
            manuscriptEdit->setText(fileName.split('/').last());
        }
    });

    // Buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *saveBtn = new QPushButton("Save");
    QPushButton *cancelBtn = new QPushButton("Cancel");
    buttonLayout->addWidget(saveBtn);
    buttonLayout->addWidget(cancelBtn);
    layout->addLayout(buttonLayout);

    connect(saveBtn, &QPushButton::clicked, [this, &dialog, submissionId, titleEdit, statusCombo, 
                                              authorSpinBox, topicSpinBox]() {
        // Validation
        if (titleEdit->text().isEmpty()) {
            QMessageBox::warning(&dialog, "Validation Error", "Please enter a submission title");
            return;
        }
        if (authorSpinBox->value() <= 0) {
            QMessageBox::warning(&dialog, "Validation Error", "Please enter a valid Author ID");
            return;
        }
        if (topicSpinBox->value() <= 0) {
            QMessageBox::warning(&dialog, "Validation Error", "Please enter a valid Topic ID");
            return;
        }

        Submission sub;
        sub.setTitle(titleEdit->text());
        sub.setStatus(statusCombo->currentText());
        sub.setAuthorID(authorSpinBox->value());
        sub.setTopicID(topicSpinBox->value());
        sub.setSourcesCitation(selectedCitationPath);
        sub.setManuscript(selectedManuscriptPath);

        bool success = false;
        QString errorMsg;

        if (submissionId == -1) {
            // Create new submission
            success = sub.create();
            if (!success) {
                errorMsg = "Failed to create submission. Please ensure Author ID and Topic ID are valid.";
            }
        } else {
            // Update existing submission
            sub.setSubmissionID(submissionId);
            success = sub.update();
            if (!success) {
                errorMsg = "Failed to update submission.";
            }
        }

        if (success) {
            QMessageBox::information(&dialog, "Success", 
                submissionId == -1 ? "Submission created successfully" : "Submission updated successfully");
            loadSubmissions();
            clearSubmissionForm();
            dialog.accept();
        } else {
            QMessageBox::critical(&dialog, "Error", errorMsg);
        }
    });

    connect(cancelBtn, &QPushButton::clicked, &dialog, &QDialog::reject);

    dialog.exec();
}

void MainWindow::refreshSubmissionTable()
{
    loadSubmissions();
}

void MainWindow::clearSubmissionForm()
{
    editingSubmissionId = -1;
}

//************SUBMISSION END***************************//

