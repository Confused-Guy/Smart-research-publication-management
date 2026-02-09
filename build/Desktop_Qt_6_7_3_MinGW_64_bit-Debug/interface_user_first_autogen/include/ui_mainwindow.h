/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stack;
    QWidget *verifyPassworPage;
    QGroupBox *groupBox_4;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_7;
    QPushButton *verifyBTNCode;
    QPushButton *CancelBTNCode;
    QFrame *frame_3;
    QWidget *forgePage;
    QFrame *frame_4;
    QGroupBox *groupBox_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *verifyBtnForgot;
    QPushButton *cancelFogotBTN;
    QLineEdit *lineEdit_14;
    QWidget *loginPage;
    QFrame *frame;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_3;
    QWidget *page;
    QFrame *frame_5;
    QGroupBox *groupBox_5;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;
    QPushButton *pushButton_3;
    QPushButton *cancelBTNRegister;
    QLabel *label_2;
    QMenuBar *menubar;
    QMenu *menuuser_register;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1041, 795);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush);
        QBrush brush1(QColor(0, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        MainWindow->setPalette(palette);
        MainWindow->setStyleSheet(QString::fromUtf8("QBackgroundUserRegister\n"
"{\n"
"\n"
"background-color:rgb(255, 170, 127)\n"
"\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stack = new QStackedWidget(centralwidget);
        stack->setObjectName("stack");
        stack->setGeometry(QRect(150, 60, 721, 661));
        verifyPassworPage = new QWidget();
        verifyPassworPage->setObjectName("verifyPassworPage");
        groupBox_4 = new QGroupBox(verifyPassworPage);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(150, 160, 411, 331));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(50, 10, 301, 141));
        QFont font;
        font.setPointSize(19);
        label_6->setFont(font);
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(60, 160, 191, 16));
        QFont font1;
        font1.setPointSize(12);
        label_7->setFont(font1);
        lineEdit_7 = new QLineEdit(groupBox_4);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(60, 200, 231, 41));
        verifyBTNCode = new QPushButton(groupBox_4);
        verifyBTNCode->setObjectName("verifyBTNCode");
        verifyBTNCode->setGeometry(QRect(230, 260, 141, 44));
        verifyBTNCode->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db;\n"
"    border-radius: 20px;\n"
"    border: 2px solid #3498db;\n"
"    min-height: 40px;\n"
"    color: white;\n"
"}\n"
""));
        CancelBTNCode = new QPushButton(groupBox_4);
        CancelBTNCode->setObjectName("CancelBTNCode");
        CancelBTNCode->setGeometry(QRect(50, 260, 141, 44));
        CancelBTNCode->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db;\n"
"    border-radius: 20px;\n"
"    border: 2px solid #3498db;\n"
"    min-height: 40px;\n"
"    color: white;\n"
"}\n"
""));
        frame_3 = new QFrame(verifyPassworPage);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(70, 70, 561, 511));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        stack->addWidget(verifyPassworPage);
        frame_3->raise();
        groupBox_4->raise();
        forgePage = new QWidget();
        forgePage->setObjectName("forgePage");
        frame_4 = new QFrame(forgePage);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(70, 70, 561, 511));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        groupBox_3 = new QGroupBox(frame_4);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(80, 90, 411, 331));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 10, 301, 141));
        label_4->setFont(font);
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(60, 160, 191, 16));
        label_5->setFont(font1);
        verifyBtnForgot = new QPushButton(groupBox_3);
        verifyBtnForgot->setObjectName("verifyBtnForgot");
        verifyBtnForgot->setGeometry(QRect(230, 260, 141, 44));
        verifyBtnForgot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db;\n"
"    border-radius: 20px;\n"
"    border: 2px solid #3498db;\n"
"    min-height: 40px;\n"
"    color: white;\n"
"}\n"
""));
        cancelFogotBTN = new QPushButton(groupBox_3);
        cancelFogotBTN->setObjectName("cancelFogotBTN");
        cancelFogotBTN->setGeometry(QRect(50, 260, 141, 44));
        cancelFogotBTN->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db;\n"
"    border-radius: 20px;\n"
"    border: 2px solid #3498db;\n"
"    min-height: 40px;\n"
"    color: white;\n"
"}\n"
""));
        lineEdit_14 = new QLineEdit(groupBox_3);
        lineEdit_14->setObjectName("lineEdit_14");
        lineEdit_14->setGeometry(QRect(60, 200, 231, 41));
        stack->addWidget(forgePage);
        loginPage = new QWidget();
        loginPage->setObjectName("loginPage");
        frame = new QFrame(loginPage);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(70, 70, 561, 511));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(50, 40, 471, 431));
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(130, 210, 211, 24));
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(130, 280, 211, 24));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(290, 340, 131, 44));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db;\n"
"    border-radius: 20px;\n"
"    border: 2px solid #3498db;\n"
"    min-height: 40px;\n"
"    color: white;\n"
"}\n"
""));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 40, 181, 151));
        label->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/Study documents/qt/download.png")));
        label->setScaledContents(true);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(130, 320, 131, 16));
        label_3->setTextFormat(Qt::TextFormat::RichText);
        stack->addWidget(loginPage);
        page = new QWidget();
        page->setObjectName("page");
        frame_5 = new QFrame(page);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(70, 70, 561, 511));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        groupBox_5 = new QGroupBox(frame_5);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(30, 30, 511, 431));
        lineEdit_10 = new QLineEdit(groupBox_5);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(30, 100, 211, 31));
        lineEdit_11 = new QLineEdit(groupBox_5);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(270, 100, 211, 31));
        lineEdit_12 = new QLineEdit(groupBox_5);
        lineEdit_12->setObjectName("lineEdit_12");
        lineEdit_12->setGeometry(QRect(30, 190, 211, 31));
        lineEdit_13 = new QLineEdit(groupBox_5);
        lineEdit_13->setObjectName("lineEdit_13");
        lineEdit_13->setGeometry(QRect(270, 190, 211, 31));
        pushButton_3 = new QPushButton(groupBox_5);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(90, 270, 321, 44));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db;\n"
"    border-radius: 20px;\n"
"    border: 2px solid #3498db;\n"
"    min-height: 40px;\n"
"    color: white;\n"
"}\n"
""));
        cancelBTNRegister = new QPushButton(groupBox_5);
        cancelBTNRegister->setObjectName("cancelBTNRegister");
        cancelBTNRegister->setGeometry(QRect(90, 340, 321, 44));
        cancelBTNRegister->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db;\n"
"    border-radius: 20px;\n"
"    border: 2px solid #3498db;\n"
"    min-height: 40px;\n"
"    color: white;\n"
"}\n"
""));
        lineEdit_10->raise();
        lineEdit_11->raise();
        lineEdit_12->raise();
        lineEdit_13->raise();
        cancelBTNRegister->raise();
        pushButton_3->raise();
        stack->addWidget(page);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(-70, 20, 1231, 711));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/Study documents/qt/researchBgLogin.png")));
        label_2->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        label_2->raise();
        stack->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1041, 21));
        menuuser_register = new QMenu(menubar);
        menuuser_register->setObjectName("menuuser_register");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuuser_register->menuAction());

        retranslateUi(MainWindow);

        stack->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_4->setTitle(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "Check Your Email!", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Enter the code:", nullptr));
        verifyBTNCode->setText(QCoreApplication::translate("MainWindow", "Verify", nullptr));
        CancelBTNCode->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        groupBox_3->setTitle(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Forgot your password?", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Enter your email:", nullptr));
        verifyBtnForgot->setText(QCoreApplication::translate("MainWindow", "Verify", nullptr));
        cancelFogotBTN->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        groupBox->setTitle(QString());
        lineEdit_5->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "login", nullptr));
        label->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "<a href=\"go\">forgot your password?</a>", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "User Rigester", nullptr));
        lineEdit_10->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        lineEdit_11->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        lineEdit_12->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        lineEdit_13->setText(QCoreApplication::translate("MainWindow", "Speciality ", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Create User", nullptr));
        cancelBTNRegister->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        label_2->setText(QString());
        menuuser_register->setTitle(QCoreApplication::translate("MainWindow", "user login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
