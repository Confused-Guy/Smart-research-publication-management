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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_5;
    QPushButton *reveiw4;
    QPushButton *pushButton_25;
    QPushButton *pushButton_26;
    QPushButton *homeButton4;
    QLabel *pic_4;
    QPushButton *profile4;
    QFrame *line_3;
    QPushButton *pushButton_28;
    QPushButton *pushButton_29;
    QWidget *page;
    QPushButton *quit;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QPushButton *Browse;
    QLabel *label_4;
    QTextEdit *textEdit_2;
    QPlainTextEdit *plainTextEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QPlainTextEdit *plainTextEdit_2;
    QPushButton *profile1;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *reveiw1;
    QPushButton *homeButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QFrame *line;
    QPushButton *pushButton_43;
    QLabel *pic;
    QPushButton *modeSwitch;
    QWidget *page_2;
    QFrame *line_2;
    QPushButton *profile2;
    QListWidget *listWidget;
    QPushButton *pushButton_8;
    QPushButton *reveiw2;
    QPushButton *pushButton_10;
    QPushButton *homeButton2;
    QLabel *pic_2;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QWidget *page_3;
    QLabel *label_6;
    QTextEdit *textEdit;
    QTextEdit *textEdit_3;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton_15;
    QTabWidget *tabWidget;
    QWidget *ReveiwT;
    QPushButton *temp;
    QWidget *tab_2;
    QLabel *userPic1;
    QWidget *page_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_16;
    QPushButton *editConferenceBtn;
    QPushButton *pushButton_17;
    QPushButton *profile3;
    QFrame *line_5;
    QPushButton *pushButton_18;
    QPushButton *addConferenceBtn;
    QPushButton *pushButton_23;
    QPushButton *pushButton_19;
    QPushButton *pushButton_21;
    QPushButton *homeButton3;
    QPushButton *reveiw3;
    QLabel *pic_3;
    QPushButton *pushButton_22;
    QWidget *page_9;
    QFrame *frame_3;
    QWidget *layoutWidget_3;
    QFormLayout *formLayout;
    QLabel *label_25;
    QComboBox *topicCombo;
    QLabel *label_26;
    QDateEdit *dateEdit;
    QLabel *label_27;
    QLineEdit *locationEdit;
    QLabel *label_28;
    QDoubleSpinBox *priceSpin;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(1298, 767);
        MainWindow->setMaximumSize(QSize(2000, 2000));
        QPalette palette;
        QBrush brush(QColor(181, 131, 90, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(246, 248, 252, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        MainWindow->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        MainWindow->setStyleSheet(QString::fromUtf8("/* Research Publication App Stylesheet - LIGHT MODE */\n"
"\n"
"* {\n"
"    font-family: -apple-system, BlinkMacSystemFont, \"Segoe UI\", Roboto, Arial, sans-serif;\n"
"}\n"
"\n"
"QMainWindow {\n"
"    background-color: #f6f8fc;\n"
"}\n"
"\n"
"#sidebar {\n"
"    background-color: #ffffff;\n"
"    border-right: 1px solid #d8e0f0;\n"
"}\n"
"\n"
"#appTitle {\n"
"    color: #1a7a7f;                /* darker version of your teal */\n"
"    font-size: 20pt;\n"
"    font-weight: bold;\n"
"    padding: 16px;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Navigation Buttons */\n"
"#homeNavButton, #myPageNavButton, #quitb {\n"
"    text-align: left;\n"
"    padding: 12px 16px;\n"
"    border-radius: 8px;\n"
"    background-color: transparent;\n"
"    color: #2d3748;\n"
"    font-size: 11pt;\n"
"    border: none;\n"
"}\n"
"\n"
"#homeNavButton:hover, #myPageNavButton:hover {\n"
"    background-color: rgba(48, 185, 191, 0.08);\n"
"}\n"
"\n"
"#homeNavButton:pressed, #myPageNavButton:pressed {\n"
"    background-co"
                        "lor: rgba(48, 185, 191, 0.15);\n"
"}\n"
"\n"
"#quitb {\n"
"    color: #2d3748;\n"
"    margin-top: 8px;\n"
"}\n"
"\n"
"#quitb:hover {\n"
"    background-color: rgba(200, 30, 30, 0.08);\n"
"    color: #c62828;\n"
"}\n"
"\n"
"/* Top Bars */\n"
"#homeTopBar, #myPageTopBar {\n"
"    background-color: #f6f8fc;\n"
"    padding: 16px 24px;\n"
"}\n"
"\n"
"#homeTitle, #myPageTitle {\n"
"    color: #1f2937;\n"
"    font-size: 18pt;\n"
"    font-weight: bold;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Search Bar */\n"
"QLineEdit#searchBar {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 20px;\n"
"    padding: 10px 16px;\n"
"    color: #1f2937;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QLineEdit#searchBar:focus {\n"
"    border: 2px solid #30b9bf;\n"
"    background-color: #ffffff !important;\n"
"}\n"
"\n"
"QLineEdit#searchBar:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"/* Scroll Areas */\n"
"#homeScrollArea, #myScrollArea {\n"
"    backgro"
                        "und-color: #f6f8fc;\n"
"    border: none;\n"
"}\n"
"\n"
"#homeScrollArea > QWidget, #myScrollArea > QWidget {\n"
"    background-color: #f6f8fc;\n"
"}\n"
"\n"
"/* Publication Cards */\n"
"#publicationCard {\n"
"    background-color: #ffffff;\n"
"    border-radius: 10px;\n"
"    border: 1px solid #e2e8f0;\n"
"    box-shadow: 0 1px 3px rgba(0,0,0,0.06);\n"
"}\n"
"\n"
"#publicationCard:hover {\n"
"    border: 1px solid #30b9bf;\n"
"    background-color: #f8fcff;\n"
"    box-shadow: 0 4px 12px rgba(48,185,191,0.12);\n"
"}\n"
"\n"
"#cardTitle {\n"
"    color: #1f2937;\n"
"    font-size: 14pt;\n"
"    font-weight: bold;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"#cardAuthors {\n"
"    color: #4b5563;\n"
"    font-size: 10pt;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"#cardDate {\n"
"    color: #6b7280;\n"
"    font-size: 9pt;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Primary Button (Upload/Browse) */\n"
"#Browse {\n"
"    background-color: #30b9bf;\n"
"    color: white;\n"
"    b"
                        "order: none;\n"
"    border-radius: 20px;\n"
"    padding: 10px 20px;\n"
"    font-weight: bold;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"#Browse:hover {\n"
"    background-color: #3dd4db;\n"
"}\n"
"\n"
"#Browse:pressed {\n"
"    background-color: #26a0a6;\n"
"}\n"
"\n"
"/* Secondary Buttons (View, Download) */\n"
"#secondaryButton {\n"
"    background-color: transparent;\n"
"    border: 1px solid #30b9bf;\n"
"    color: #30b9bf;\n"
"    border-radius: 16px;\n"
"    padding: 6px 16px;\n"
"    font-size: 9pt;\n"
"    font-weight: 600;\n"
"}\n"
"\n"
"#secondaryButton:hover {\n"
"    background-color: #30b9bf;\n"
"    color: white;\n"
"}\n"
"\n"
"#secondaryButton:pressed {\n"
"    background-color: #26a0a6;\n"
"    color: white;\n"
"}\n"
"\n"
"/* Default QPushButton */\n"
"QPushButton {\n"
"    background-color: #e2efff;\n"
"    color: #1e40af;\n"
"    border: 1px solid #bfdbfe;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-col"
                        "or: #dbeafe;\n"
"    border-color: #93c5fd;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #bfdbfe;\n"
"    border-color: #60a5fa;\n"
"}\n"
"\n"
"/* ALL QLabel */\n"
"QLabel {\n"
"    color: #1f2937;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"#sidebar QLabel {\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"/* Status Badges */\n"
".statusAccepted {\n"
"    background-color: #dcfce7;\n"
"    color: #166534;\n"
"    border: 1px solid #86efac;\n"
"    border-radius: 12px;\n"
"    padding: 4px 12px;\n"
"    font-size: 9pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
".statusReview {\n"
"    background-color: #fef3c7;\n"
"    color: #92400e;\n"
"    border: 1px solid #fcd34d;\n"
"    border-radius: 12px;\n"
"    padding: 4px 12px;\n"
"    font-size: 9pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
".statusRejected {\n"
"    background-color: #fee2e2;\n"
"    color: #991b1b;\n"
"    border: 1px solid #fca5a5;\n"
"    border-radius: 12px;\n"
"    padding: 4px 12px;\n"
"    font-size: 9pt;\n"
"    font-wei"
                        "ght: bold;\n"
"}\n"
"\n"
"/* Scrollbars */\n"
"QScrollBar:vertical {\n"
"    background: #f6f8fc;\n"
"    width: 10px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #c0d0e8;\n"
"    min-height: 30px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #30b9bf;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    background: #f6f8fc;\n"
"    height: 10px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #c0d0e8;\n"
"    min-width: 30px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:hover {\n"
"    background: #30b9bf;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {\n"
"    width: 0px;\n"
"}\n"
"\n"
"/* ALL Input Fields */\n"
"QLineEdit {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
" "
                        "   border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #30b9bf;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"QTextEdit, QPlainTextEdit {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QTextEdit:focus, QPlainTextEdit:focus {\n"
"    border: 2px solid #30b9bf;\n"
"}\n"
"\n"
"QTextEdit:hover, QPlainTextEdit:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"/* Combo Boxes */\n"
"QComboBox {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    bo"
                        "rder: 1px solid #30b9bf;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 2px solid #30b9bf;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 20px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-left: 5px solid transparent;\n"
"    border-right: 5px solid transparent;\n"
"    border-top: 5px solid #6b7280;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #c0d0e8;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"    outline: none;\n"
"}\n"
"\n"
"/* Checkboxes & Radio */\n"
"QCheckBox, QRadioButton {\n"
"    spacing: 8px;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"QCheckBox::indicator, QRadioButton::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 4px;     /* radio will override radius */\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #30"
                        "b9bf;\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #ffffff;\n"
"    border: 5px solid #30b9bf;\n"
"}\n"
"\n"
"QCheckBox::indicator:hover, QRadioButton::indicator:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"/* Progress Bar */\n"
"QProgressBar {\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    text-align: center;\n"
"    background-color: #f1f5f9;\n"
"    color: #1f2937;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #30b9bf;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"/* Tooltips */\n"
"QToolTip {\n"
"    background-color: #1e293b;\n"
"    color: #f1f5f9;\n"
"    border: 1px solid #30b9bf;\n"
"    padding: 6px 8px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"/* Tables / List / Tree */\n"
"QTableView, QListView, QTreeView {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #e2e8f0;\n"
"    bor"
                        "der-radius: 8px;\n"
"    gridline-color: #e2e8f0;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"    color: #1f2937;\n"
"    outline: none;\n"
"}\n"
"\n"
"QTableView::item:hover, QListView::item:hover, QTreeView::item:hover {\n"
"    background-color: #f0f9ff;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #f1f5f9;\n"
"    padding: 8px;\n"
"    border: none;\n"
"    border-right: 1px solid #e2e8f0;\n"
"    border-bottom: 1px solid #e2e8f0;\n"
"    color: #1f2937;\n"
"    font-weight: bold;\n"
"    font-size: 9pt;\n"
"}\n"
"\n"
"/* Menu Bar */\n"
"QMenuBar {\n"
"    background-color: #ffffff;\n"
"    border-bottom: 1px solid #d8e0f0;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: #e2efff;\n"
"}\n"
"\n"
"QMenu {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #d8e0f0;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    background-color: #30b9bf;\n"
"    color: white;\n"
"}\n"
"\n"
"/* Sta"
                        "tus Bar */\n"
"QStatusBar {\n"
"    background-color: #f1f5f9;\n"
"    border-top: 1px solid #d8e0f0;\n"
"    color: #4b5563;\n"
"}\n"
"\n"
"/* Group Box */\n"
"QGroupBox {\n"
"    border: 1px solid #d8e0f0;\n"
"    border-radius: 8px;\n"
"    margin-top: 12px;\n"
"    padding-top: 12px;\n"
"    color: #1f2937;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 0 8px;\n"
"    color: #1a7a7f;\n"
"}\n"
"\n"
"/* Tabs */\n"
"QTabWidget::pane {\n"
"    border: 1px solid #d8e0f0;\n"
"    background-color: #ffffff;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: #f8fafc;\n"
"    color: #64748b;\n"
"    border: none;\n"
"    border-bottom: 3px solid transparent;\n"
"    padding: 12px 20px;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    color: #1f2937;\n"
"    background-color: #ffffff;\n"
"    border-bottom: 3px solid #30b9bf;\n"
"}\n"
"\n"
"QTabBar::tab:hov"
                        "er {\n"
"    color: #1f2937;\n"
"    background-color: #f1f5f9;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1271, 741));
        stackedWidget->setStyleSheet(QString::fromUtf8("/* Research Publication App Stylesheet - LIGHT MODE */\n"
"\n"
"* {\n"
"    font-family: -apple-system, BlinkMacSystemFont, \"Segoe UI\", Roboto, Arial, sans-serif;\n"
"}\n"
"\n"
"QMainWindow {\n"
"    background-color: #f6f8fc;\n"
"}\n"
"\n"
"#sidebar {\n"
"    background-color: #ffffff;\n"
"    border-right: 1px solid #d8e0f0;\n"
"}\n"
"\n"
"/* For QDateEdit */\n"
"QDateEdit {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"/* For QSpinBox / QDoubleSpinBox */\n"
"QSpinBox, QDoubleSpinBox {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"#appTitle {\n"
"    color: #1a7a7f;                /* darker version of your teal */\n"
"    font-size: 20pt;\n"
"    font-weight: bold;\n"
"    padding: 16px;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Navigatio"
                        "n Buttons */\n"
"#homeNavButton, #myPageNavButton, #quitb {\n"
"    text-align: left;\n"
"    padding: 12px 16px;\n"
"    border-radius: 8px;\n"
"    background-color: transparent;\n"
"    color: #2d3748;\n"
"    font-size: 11pt;\n"
"    border: none;\n"
"}\n"
"\n"
"#homeNavButton:hover, #myPageNavButton:hover {\n"
"    background-color: rgba(48, 185, 191, 0.08);\n"
"}\n"
"\n"
"#homeNavButton:pressed, #myPageNavButton:pressed {\n"
"    background-color: rgba(48, 185, 191, 0.15);\n"
"}\n"
"\n"
"#quitb {\n"
"    color: #2d3748;\n"
"    margin-top: 8px;\n"
"}\n"
"\n"
"#quitb:hover {\n"
"    background-color: rgba(200, 30, 30, 0.08);\n"
"    color: #c62828;\n"
"}\n"
"\n"
"/* Top Bars */\n"
"#homeTopBar, #myPageTopBar {\n"
"    background-color: #f6f8fc;\n"
"    padding: 16px 24px;\n"
"}\n"
"\n"
"#homeTitle, #myPageTitle {\n"
"    color: #1f2937;\n"
"    font-size: 18pt;\n"
"    font-weight: bold;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Search Bar */\n"
"QLineEdit#searchBar {\n"
"    background-col"
                        "or: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 20px;\n"
"    padding: 10px 16px;\n"
"    color: #1f2937;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QLineEdit#searchBar:focus {\n"
"    border: 2px solid #30b9bf;\n"
"    background-color: #ffffff !important;\n"
"}\n"
"\n"
"QLineEdit#searchBar:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"/* Scroll Areas */\n"
"#homeScrollArea, #myScrollArea {\n"
"    background-color: #f6f8fc;\n"
"    border: none;\n"
"}\n"
"\n"
"#homeScrollArea > QWidget, #myScrollArea > QWidget {\n"
"    background-color: #f6f8fc;\n"
"}\n"
"\n"
"/* Publication Cards */\n"
"#publicationCard {\n"
"    background-color: #ffffff;\n"
"    border-radius: 10px;\n"
"    border: 1px solid #e2e8f0;\n"
"    box-shadow: 0 1px 3px rgba(0,0,0,0.06);\n"
"}\n"
"\n"
"#publicationCard:hover {\n"
"    border: 1px solid #30b9bf;\n"
"    background-color: #f8fcff;\n"
"    box-shadow: 0 4px 12px rgba(48,185,191,0.12);\n"
"}\n"
"\n"
"#cardTitle {\n"
"    color: #1f2937;\n"
""
                        "    font-size: 14pt;\n"
"    font-weight: bold;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"#cardAuthors {\n"
"    color: #4b5563;\n"
"    font-size: 10pt;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"#cardDate {\n"
"    color: #6b7280;\n"
"    font-size: 9pt;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Primary Button (Upload/Browse) */\n"
"#Browse {\n"
"    background-color: #30b9bf;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 20px;\n"
"    padding: 10px 20px;\n"
"    font-weight: bold;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"#Browse:hover {\n"
"    background-color: #3dd4db;\n"
"}\n"
"\n"
"#Browse:pressed {\n"
"    background-color: #26a0a6;\n"
"}\n"
"\n"
"/* Secondary Buttons (View, Download) */\n"
"#secondaryButton {\n"
"    background-color: transparent;\n"
"    border: 1px solid #30b9bf;\n"
"    color: #30b9bf;\n"
"    border-radius: 16px;\n"
"    padding: 6px 16px;\n"
"    font-size: 9pt;\n"
"    font-weight: 600;\n"
"}\n"
"\n"
"#secondaryButton:hov"
                        "er {\n"
"    background-color: #30b9bf;\n"
"    color: white;\n"
"}\n"
"\n"
"#secondaryButton:pressed {\n"
"    background-color: #26a0a6;\n"
"    color: white;\n"
"}\n"
"\n"
"/* Default QPushButton */\n"
"QPushButton {\n"
"    background-color: #e2efff;\n"
"    color: #1e40af;\n"
"    border: 1px solid #bfdbfe;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #dbeafe;\n"
"    border-color: #93c5fd;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #bfdbfe;\n"
"    border-color: #60a5fa;\n"
"}\n"
"\n"
"/* ALL QLabel */\n"
"QLabel {\n"
"    color: #1f2937;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"#sidebar QLabel {\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"/* Status Badges */\n"
".statusAccepted {\n"
"    background-color: #dcfce7;\n"
"    color: #166534;\n"
"    border: 1px solid #86efac;\n"
"    border-radius: 12px;\n"
"    padding: 4px 12px;\n"
"    font-size: 9pt;\n"
"    font-weight: bold;\n"
""
                        "}\n"
"\n"
".statusReview {\n"
"    background-color: #fef3c7;\n"
"    color: #92400e;\n"
"    border: 1px solid #fcd34d;\n"
"    border-radius: 12px;\n"
"    padding: 4px 12px;\n"
"    font-size: 9pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
".statusRejected {\n"
"    background-color: #fee2e2;\n"
"    color: #991b1b;\n"
"    border: 1px solid #fca5a5;\n"
"    border-radius: 12px;\n"
"    padding: 4px 12px;\n"
"    font-size: 9pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Scrollbars */\n"
"QScrollBar:vertical {\n"
"    background: #f6f8fc;\n"
"    width: 10px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #c0d0e8;\n"
"    min-height: 30px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #30b9bf;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    background: #f6f8fc;\n"
"    height: 10px;\n"
"    border-radius: 5px;\n"
""
                        "}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #c0d0e8;\n"
"    min-width: 30px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:hover {\n"
"    background: #30b9bf;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {\n"
"    width: 0px;\n"
"}\n"
"\n"
"/* ALL Input Fields */\n"
"QLineEdit {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #30b9bf;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"QTextEdit, QPlainTextEdit {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"}\n"
""
                        "\n"
"QTextEdit:focus, QPlainTextEdit:focus {\n"
"    border: 2px solid #30b9bf;\n"
"}\n"
"\n"
"QTextEdit:hover, QPlainTextEdit:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"/* Combo Boxes */\n"
"QComboBox {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 2px solid #30b9bf;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 20px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-left: 5px solid transparent;\n"
"    border-right: 5px solid transparent;\n"
"    border-top: 5px solid #6b7280;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #c0d0e8;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"   "
                        " outline: none;\n"
"}\n"
"\n"
"/* Checkboxes & Radio */\n"
"QCheckBox, QRadioButton {\n"
"    spacing: 8px;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"QCheckBox::indicator, QRadioButton::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 4px;     /* radio will override radius */\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #30b9bf;\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #ffffff;\n"
"    border: 5px solid #30b9bf;\n"
"}\n"
"\n"
"QCheckBox::indicator:hover, QRadioButton::indicator:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"/* Progress Bar */\n"
"QProgressBar {\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    text-align: center;\n"
"    background-color: #f1f5f9;\n"
"    color: #1f2937;\n"
"    font-weight: bold;\n"
"}\n"
""
                        "\n"
"QProgressBar::chunk {\n"
"    background-color: #30b9bf;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"/* Tooltips */\n"
"QToolTip {\n"
"    background-color: #1e293b;\n"
"    color: #f1f5f9;\n"
"    border: 1px solid #30b9bf;\n"
"    padding: 6px 8px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"/* Tables / List / Tree */\n"
"QTableView, QListView, QTreeView {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 8px;\n"
"    gridline-color: #e2e8f0;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"    color: #1f2937;\n"
"    outline: none;\n"
"}\n"
"\n"
"QTableView::item:hover, QListView::item:hover, QTreeView::item:hover {\n"
"    background-color: #f0f9ff;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #f1f5f9;\n"
"    padding: 8px;\n"
"    border: none;\n"
"    border-right: 1px solid #e2e8f0;\n"
"    border-bottom: 1px solid #e2e8f0;\n"
"    color: #1f2937;\n"
"    font-weight: bold;\n"
"    font-size: 9pt;\n"
"}\n"
""
                        "\n"
"/* Menu Bar */\n"
"QMenuBar {\n"
"    background-color: #ffffff;\n"
"    border-bottom: 1px solid #d8e0f0;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: #e2efff;\n"
"}\n"
"\n"
"QMenu {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #d8e0f0;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    background-color: #30b9bf;\n"
"    color: white;\n"
"}\n"
"\n"
"/* Status Bar */\n"
"QStatusBar {\n"
"    background-color: #f1f5f9;\n"
"    border-top: 1px solid #d8e0f0;\n"
"    color: #4b5563;\n"
"}\n"
"\n"
"/* Group Box */\n"
"QGroupBox {\n"
"    border: 1px solid #d8e0f0;\n"
"    border-radius: 8px;\n"
"    margin-top: 12px;\n"
"    padding-top: 12px;\n"
"    color: #1f2937;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 0 8px;\n"
"    color: #1a7a7f;\n"
"}\n"
"\n"
"/* Tabs */\n"
"QTabWidget::pane {\n"
"    border: 1px solid #d8e0f0;\n"
""
                        "    background-color: #ffffff;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: #f8fafc;\n"
"    color: #64748b;\n"
"    border: none;\n"
"    border-bottom: 3px solid transparent;\n"
"    padding: 12px 20px;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    color: #1f2937;\n"
"    background-color: #ffffff;\n"
"    border-bottom: 3px solid #30b9bf;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    color: #1f2937;\n"
"    background-color: #f1f5f9;\n"
"}"));
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        reveiw4 = new QPushButton(page_5);
        reveiw4->setObjectName("reveiw4");
        reveiw4->setGeometry(QRect(20, 180, 41, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8("icons/plus-square.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        reveiw4->setIcon(icon);
        pushButton_25 = new QPushButton(page_5);
        pushButton_25->setObjectName("pushButton_25");
        pushButton_25->setGeometry(QRect(20, 260, 41, 41));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("icons/pie-chart.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_25->setIcon(icon1);
        pushButton_26 = new QPushButton(page_5);
        pushButton_26->setObjectName("pushButton_26");
        pushButton_26->setGeometry(QRect(20, 340, 41, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("icons/calendar.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_26->setIcon(icon2);
        homeButton4 = new QPushButton(page_5);
        homeButton4->setObjectName("homeButton4");
        homeButton4->setEnabled(true);
        homeButton4->setGeometry(QRect(20, 80, 40, 40));
        homeButton4->setMinimumSize(QSize(40, 40));
        homeButton4->setMaximumSize(QSize(40, 40));
        homeButton4->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        homeButton4->setMouseTracking(true);
        homeButton4->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        homeButton4->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        homeButton4->setAutoFillBackground(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("icons/menu.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        homeButton4->setIcon(icon3);
        homeButton4->setIconSize(QSize(22, 22));
        homeButton4->setFlat(true);
        pic_4 = new QLabel(page_5);
        pic_4->setObjectName("pic_4");
        pic_4->setGeometry(QRect(20, 10, 41, 41));
        pic_4->setPixmap(QPixmap(QString::fromUtf8("build/Desktop_Qt_6_7_3-Debug/icons/user.svg")));
        pic_4->setScaledContents(true);
        pic_4->setWordWrap(false);
        profile4 = new QPushButton(page_5);
        profile4->setObjectName("profile4");
        profile4->setGeometry(QRect(20, 610, 41, 41));
        profile4->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("icons/user.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        profile4->setIcon(icon4);
        line_3 = new QFrame(page_5);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(80, -30, 20, 841));
        QPalette palette1;
        line_3->setPalette(palette1);
        line_3->setCursor(QCursor(Qt::CursorShape::ForbiddenCursor));
        line_3->setAutoFillBackground(false);
        line_3->setFrameShadow(QFrame::Shadow::Plain);
        line_3->setLineWidth(3);
        line_3->setFrameShape(QFrame::Shape::VLine);
        pushButton_28 = new QPushButton(page_5);
        pushButton_28->setObjectName("pushButton_28");
        pushButton_28->setGeometry(QRect(20, 420, 41, 41));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("icons/hard-drive.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_28->setIcon(icon5);
        pushButton_29 = new QPushButton(page_5);
        pushButton_29->setObjectName("pushButton_29");
        pushButton_29->setGeometry(QRect(20, 500, 41, 41));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("icons/zap.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_29->setIcon(icon6);
        stackedWidget->addWidget(page_5);
        page = new QWidget();
        page->setObjectName("page");
        quit = new QPushButton(page);
        quit->setObjectName("quit");
        quit->setGeometry(QRect(710, 620, 81, 41));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("icons/log-out.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        quit->setIcon(icon7);
        quit->setIconSize(QSize(25, 25));
        pushButton = new QPushButton(page);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(400, 620, 141, 41));
        QPalette palette2;
        QBrush brush2(QColor(30, 64, 175, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QBrush brush3(QColor(226, 239, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush3);
        QBrush brush4(QColor(31, 155, 93, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Highlight, brush4);
        QBrush brush5(QColor(30, 64, 175, 128));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Highlight, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Highlight, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        pushButton->setPalette(palette2);
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon8(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSend));
        pushButton->setIcon(icon8);
        groupBox = new QGroupBox(page);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(260, 50, 781, 541));
        QPalette palette3;
        QBrush brush6(QColor(31, 41, 55, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QBrush brush7(QColor(145, 65, 172, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QBrush brush8(QColor(61, 61, 61, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush8);
        QBrush brush9(QColor(31, 41, 55, 128));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        groupBox->setPalette(palette3);
        groupBox->setStyleSheet(QString::fromUtf8("/* Research Publication App Stylesheet - LIGHT MODE */\n"
"\n"
"* {\n"
"    font-family: -apple-system, BlinkMacSystemFont, \"Segoe UI\", Roboto, Arial, sans-serif;\n"
"}\n"
"\n"
"QMainWindow {\n"
"    background-color: #f6f8fc;\n"
"}\n"
"\n"
"#sidebar {\n"
"    background-color: #ffffff;\n"
"    border-right: 1px solid #d8e0f0;\n"
"}\n"
"\n"
"#appTitle {\n"
"    color: #1a7a7f;                /* darker version of your teal */\n"
"    font-size: 20pt;\n"
"    font-weight: bold;\n"
"    padding: 16px;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Navigation Buttons */\n"
"#homeNavButton, #myPageNavButton, #quitb {\n"
"    text-align: left;\n"
"    padding: 12px 16px;\n"
"    border-radius: 8px;\n"
"    background-color: transparent;\n"
"    color: #2d3748;\n"
"    font-size: 11pt;\n"
"    border: none;\n"
"}\n"
"\n"
"#homeNavButton:hover, #myPageNavButton:hover {\n"
"    background-color: rgba(48, 185, 191, 0.08);\n"
"}\n"
"\n"
"#homeNavButton:pressed, #myPageNavButton:pressed {\n"
"    background-co"
                        "lor: rgba(48, 185, 191, 0.15);\n"
"}\n"
"\n"
"#quitb {\n"
"    color: #2d3748;\n"
"    margin-top: 8px;\n"
"}\n"
"\n"
"#quitb:hover {\n"
"    background-color: rgba(200, 30, 30, 0.08);\n"
"    color: #c62828;\n"
"}\n"
"\n"
"/* Top Bars */\n"
"#homeTopBar, #myPageTopBar {\n"
"    background-color: #f6f8fc;\n"
"    padding: 16px 24px;\n"
"}\n"
"\n"
"#homeTitle, #myPageTitle {\n"
"    color: #1f2937;\n"
"    font-size: 18pt;\n"
"    font-weight: bold;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Search Bar */\n"
"QLineEdit#searchBar {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 20px;\n"
"    padding: 10px 16px;\n"
"    color: #1f2937;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QLineEdit#searchBar:focus {\n"
"    border: 2px solid #30b9bf;\n"
"    background-color: #ffffff !important;\n"
"}\n"
"\n"
"QLineEdit#searchBar:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"/* Scroll Areas */\n"
"#homeScrollArea, #myScrollArea {\n"
"    backgro"
                        "und-color: #f6f8fc;\n"
"    border: none;\n"
"}\n"
"\n"
"#homeScrollArea > QWidget, #myScrollArea > QWidget {\n"
"    background-color: #f6f8fc;\n"
"}\n"
"\n"
"/* Publication Cards */\n"
"#publicationCard {\n"
"    background-color: #ffffff;\n"
"    border-radius: 10px;\n"
"    border: 1px solid #e2e8f0;\n"
"    box-shadow: 0 1px 3px rgba(0,0,0,0.06);\n"
"}\n"
"\n"
"#publicationCard:hover {\n"
"    border: 1px solid #30b9bf;\n"
"    background-color: #f8fcff;\n"
"    box-shadow: 0 4px 12px rgba(48,185,191,0.12);\n"
"}\n"
"\n"
"#cardTitle {\n"
"    color: #1f2937;\n"
"    font-size: 14pt;\n"
"    font-weight: bold;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"#cardAuthors {\n"
"    color: #4b5563;\n"
"    font-size: 10pt;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"#cardDate {\n"
"    color: #6b7280;\n"
"    font-size: 9pt;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Primary Button (Upload/Browse) */\n"
"#Browse {\n"
"    background-color: #30b9bf;\n"
"    color: white;\n"
"    b"
                        "order: none;\n"
"    border-radius: 20px;\n"
"    padding: 10px 20px;\n"
"    font-weight: bold;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"#Browse:hover {\n"
"    background-color: #3dd4db;\n"
"}\n"
"\n"
"#Browse:pressed {\n"
"    background-color: #26a0a6;\n"
"}\n"
"\n"
"/* Secondary Buttons (View, Download) */\n"
"#secondaryButton {\n"
"    background-color: transparent;\n"
"    border: 1px solid #30b9bf;\n"
"    color: #30b9bf;\n"
"    border-radius: 16px;\n"
"    padding: 6px 16px;\n"
"    font-size: 9pt;\n"
"    font-weight: 600;\n"
"}\n"
"\n"
"#secondaryButton:hover {\n"
"    background-color: #30b9bf;\n"
"    color: white;\n"
"}\n"
"\n"
"#secondaryButton:pressed {\n"
"    background-color: #26a0a6;\n"
"    color: white;\n"
"}\n"
"\n"
"/* Default QPushButton */\n"
"QPushButton {\n"
"    background-color: #e2efff;\n"
"    color: #1e40af;\n"
"    border: 1px solid #bfdbfe;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-col"
                        "or: #dbeafe;\n"
"    border-color: #93c5fd;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #bfdbfe;\n"
"    border-color: #60a5fa;\n"
"}\n"
"\n"
"/* ALL QLabel */\n"
"QLabel {\n"
"    color: #1f2937;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"#sidebar QLabel {\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"/* Status Badges */\n"
".statusAccepted {\n"
"    background-color: #dcfce7;\n"
"    color: #166534;\n"
"    border: 1px solid #86efac;\n"
"    border-radius: 12px;\n"
"    padding: 4px 12px;\n"
"    font-size: 9pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
".statusReview {\n"
"    background-color: #fef3c7;\n"
"    color: #92400e;\n"
"    border: 1px solid #fcd34d;\n"
"    border-radius: 12px;\n"
"    padding: 4px 12px;\n"
"    font-size: 9pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
".statusRejected {\n"
"    background-color: #fee2e2;\n"
"    color: #991b1b;\n"
"    border: 1px solid #fca5a5;\n"
"    border-radius: 12px;\n"
"    padding: 4px 12px;\n"
"    font-size: 9pt;\n"
"    font-wei"
                        "ght: bold;\n"
"}\n"
"\n"
"/* Scrollbars */\n"
"QScrollBar:vertical {\n"
"    background: #f6f8fc;\n"
"    width: 10px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #c0d0e8;\n"
"    min-height: 30px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #30b9bf;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    background: #f6f8fc;\n"
"    height: 10px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #c0d0e8;\n"
"    min-width: 30px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:hover {\n"
"    background: #30b9bf;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {\n"
"    width: 0px;\n"
"}\n"
"\n"
"/* ALL Input Fields */\n"
"QLineEdit {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
" "
                        "   border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #30b9bf;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"QTextEdit, QPlainTextEdit {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QTextEdit:focus, QPlainTextEdit:focus {\n"
"    border: 2px solid #30b9bf;\n"
"}\n"
"\n"
"QTextEdit:hover, QPlainTextEdit:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"/* Combo Boxes */\n"
"QComboBox {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    bo"
                        "rder: 1px solid #30b9bf;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 2px solid #30b9bf;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 20px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-left: 5px solid transparent;\n"
"    border-right: 5px solid transparent;\n"
"    border-top: 5px solid #6b7280;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #c0d0e8;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"    outline: none;\n"
"}\n"
"\n"
"/* Checkboxes & Radio */\n"
"QCheckBox, QRadioButton {\n"
"    spacing: 8px;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"QCheckBox::indicator, QRadioButton::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 4px;     /* radio will override radius */\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #30"
                        "b9bf;\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #ffffff;\n"
"    border: 5px solid #30b9bf;\n"
"}\n"
"\n"
"QCheckBox::indicator:hover, QRadioButton::indicator:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"/* Progress Bar */\n"
"QProgressBar {\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    text-align: center;\n"
"    background-color: #f1f5f9;\n"
"    color: #1f2937;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #30b9bf;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"/* Tooltips */\n"
"QToolTip {\n"
"    background-color: #1e293b;\n"
"    color: #f1f5f9;\n"
"    border: 1px solid #30b9bf;\n"
"    padding: 6px 8px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"/* Tables / List / Tree */\n"
"QTableView, QListView, QTreeView {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #e2e8f0;\n"
"    bor"
                        "der-radius: 8px;\n"
"    gridline-color: #e2e8f0;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"    color: #1f2937;\n"
"    outline: none;\n"
"}\n"
"\n"
"QTableView::item:hover, QListView::item:hover, QTreeView::item:hover {\n"
"    background-color: #f0f9ff;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #f1f5f9;\n"
"    padding: 8px;\n"
"    border: none;\n"
"    border-right: 1px solid #e2e8f0;\n"
"    border-bottom: 1px solid #e2e8f0;\n"
"    color: #1f2937;\n"
"    font-weight: bold;\n"
"    font-size: 9pt;\n"
"}\n"
"\n"
"/* Menu Bar */\n"
"QMenuBar {\n"
"    background-color: #ffffff;\n"
"    border-bottom: 1px solid #d8e0f0;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: #e2efff;\n"
"}\n"
"\n"
"QMenu {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #d8e0f0;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    background-color: #30b9bf;\n"
"    color: white;\n"
"}\n"
"\n"
"/* Sta"
                        "tus Bar */\n"
"QStatusBar {\n"
"    background-color: #f1f5f9;\n"
"    border-top: 1px solid #d8e0f0;\n"
"    color: #4b5563;\n"
"}\n"
"\n"
"/* Group Box */\n"
"QGroupBox {\n"
"    border: 1px solid #d8e0f0;\n"
"    border-radius: 8px;\n"
"    margin-top: 12px;\n"
"    padding-top: 12px;\n"
"    color: #1f2937;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 0 8px;\n"
"    color: #1a7a7f;\n"
"}\n"
"\n"
"/* Tabs */\n"
"QTabWidget::pane {\n"
"    border: 1px solid #d8e0f0;\n"
"    background-color: #ffffff;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: #f8fafc;\n"
"    color: #64748b;\n"
"    border: none;\n"
"    border-bottom: 3px solid transparent;\n"
"    padding: 12px 20px;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    color: #1f2937;\n"
"    background-color: #ffffff;\n"
"    border-bottom: 3px solid #30b9bf;\n"
"}\n"
"\n"
"QTabBar::tab:hov"
                        "er {\n"
"    color: #1f2937;\n"
"    background-color: #f1f5f9;\n"
"}"));
        Browse = new QPushButton(groupBox);
        Browse->setObjectName("Browse");
        Browse->setGeometry(QRect(440, 420, 121, 31));
        QPalette palette4;
        QBrush brush10(QColor(255, 255, 255, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush10);
        QBrush brush11(QColor(48, 185, 191, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush10);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush10);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush11);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette4.setBrush(QPalette::Active, QPalette::Highlight, brush4);
        QBrush brush12(QColor(255, 255, 255, 128));
        brush12.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush12);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush10);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush10);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush10);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush11);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette4.setBrush(QPalette::Inactive, QPalette::Highlight, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Highlight, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
#endif
        Browse->setPalette(palette4);
        Browse->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Browse->setStyleSheet(QString::fromUtf8(""));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(310, 430, 131, 19));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QBrush brush13(QColor(0, 0, 0, 0));
        brush13.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush13);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush13);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush13);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush13);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush13);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush13);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush13);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush13);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        label_4->setPalette(palette5);
        textEdit_2 = new QTextEdit(groupBox);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(290, 160, 431, 131));
        textEdit_2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::IBeamCursor)));
        textEdit_2->setFrameShape(QFrame::Shape::NoFrame);
        textEdit_2->setLineWidth(9);
        plainTextEdit = new QPlainTextEdit(groupBox);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(290, 60, 391, 51));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 80, 131, 19));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 210, 171, 19));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 430, 211, 19));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(80, 340, 161, 19));
        plainTextEdit_2 = new QPlainTextEdit(groupBox);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setGeometry(QRect(290, 330, 391, 51));
        profile1 = new QPushButton(page);
        profile1->setObjectName("profile1");
        profile1->setGeometry(QRect(20, 610, 41, 41));
        profile1->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        profile1->setIcon(icon4);
        pushButton_4 = new QPushButton(page);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(20, 340, 41, 41));
        pushButton_4->setIcon(icon2);
        pushButton_3 = new QPushButton(page);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 260, 41, 41));
        pushButton_3->setIcon(icon1);
        reveiw1 = new QPushButton(page);
        reveiw1->setObjectName("reveiw1");
        reveiw1->setGeometry(QRect(20, 180, 41, 41));
        reveiw1->setIcon(icon);
        homeButton = new QPushButton(page);
        homeButton->setObjectName("homeButton");
        homeButton->setEnabled(true);
        homeButton->setGeometry(QRect(20, 80, 40, 40));
        homeButton->setMinimumSize(QSize(40, 40));
        homeButton->setMaximumSize(QSize(40, 40));
        homeButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        homeButton->setMouseTracking(true);
        homeButton->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        homeButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        homeButton->setAutoFillBackground(false);
        homeButton->setIcon(icon3);
        homeButton->setIconSize(QSize(22, 22));
        homeButton->setFlat(true);
        pushButton_5 = new QPushButton(page);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(20, 420, 41, 41));
        pushButton_5->setIcon(icon5);
        pushButton_6 = new QPushButton(page);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(20, 500, 41, 41));
        pushButton_6->setIcon(icon6);
        line = new QFrame(page);
        line->setObjectName("line");
        line->setGeometry(QRect(80, -30, 20, 841));
        QPalette palette6;
        line->setPalette(palette6);
        line->setCursor(QCursor(Qt::CursorShape::ForbiddenCursor));
        line->setAutoFillBackground(false);
        line->setFrameShadow(QFrame::Shadow::Plain);
        line->setLineWidth(3);
        line->setFrameShape(QFrame::Shape::VLine);
        pushButton_43 = new QPushButton(page);
        pushButton_43->setObjectName("pushButton_43");
        pushButton_43->setGeometry(QRect(140, 20, 41, 41));
        pushButton_43->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon9(QIcon::fromTheme(QIcon::ThemeIcon::GoPrevious));
        pushButton_43->setIcon(icon9);
        pic = new QLabel(page);
        pic->setObjectName("pic");
        pic->setGeometry(QRect(20, 10, 41, 41));
        pic->setPixmap(QPixmap(QString::fromUtf8("build/Desktop_Qt_6_7_3-Debug/icons/user.svg")));
        pic->setScaledContents(true);
        pic->setWordWrap(false);
        modeSwitch = new QPushButton(page);
        modeSwitch->setObjectName("modeSwitch");
        modeSwitch->setGeometry(QRect(20, 660, 41, 41));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("icons/sun.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        modeSwitch->setIcon(icon10);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        line_2 = new QFrame(page_2);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(80, -20, 20, 841));
        QPalette palette7;
        line_2->setPalette(palette7);
        line_2->setCursor(QCursor(Qt::CursorShape::ForbiddenCursor));
        line_2->setAutoFillBackground(false);
        line_2->setFrameShadow(QFrame::Shadow::Plain);
        line_2->setLineWidth(3);
        line_2->setFrameShape(QFrame::Shape::VLine);
        profile2 = new QPushButton(page_2);
        profile2->setObjectName("profile2");
        profile2->setGeometry(QRect(20, 610, 41, 41));
        profile2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        profile2->setIcon(icon4);
        listWidget = new QListWidget(page_2);
        QBrush brush14(QColor(0, 0, 0, 255));
        brush14.setStyle(Qt::SolidPattern);
        QBrush brush15(QColor(0, 0, 0, 255));
        brush15.setStyle(Qt::NoBrush);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setBackground(brush15);
        __qlistwidgetitem->setForeground(brush14);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(100, 160, 231, 411));
        listWidget->setFrameShape(QFrame::Shape::WinPanel);
        listWidget->setLineWidth(3);
        pushButton_8 = new QPushButton(page_2);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(20, 260, 41, 41));
        pushButton_8->setIcon(icon1);
        reveiw2 = new QPushButton(page_2);
        reveiw2->setObjectName("reveiw2");
        reveiw2->setGeometry(QRect(20, 180, 41, 41));
        reveiw2->setIcon(icon);
        pushButton_10 = new QPushButton(page_2);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(20, 340, 41, 41));
        pushButton_10->setIcon(icon2);
        homeButton2 = new QPushButton(page_2);
        homeButton2->setObjectName("homeButton2");
        homeButton2->setEnabled(true);
        homeButton2->setGeometry(QRect(20, 80, 40, 40));
        homeButton2->setMinimumSize(QSize(40, 40));
        homeButton2->setMaximumSize(QSize(40, 40));
        homeButton2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        homeButton2->setMouseTracking(true);
        homeButton2->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        homeButton2->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        homeButton2->setAutoFillBackground(false);
        homeButton2->setIcon(icon3);
        homeButton2->setIconSize(QSize(22, 22));
        homeButton2->setFlat(true);
        pic_2 = new QLabel(page_2);
        pic_2->setObjectName("pic_2");
        pic_2->setGeometry(QRect(20, 10, 41, 41));
        pic_2->setPixmap(QPixmap(QString::fromUtf8("build/Desktop_Qt_6_7_3-Debug/icons/user.svg")));
        pic_2->setScaledContents(true);
        pic_2->setWordWrap(false);
        pushButton_11 = new QPushButton(page_2);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(20, 420, 41, 41));
        pushButton_11->setIcon(icon5);
        pushButton_12 = new QPushButton(page_2);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(20, 500, 41, 41));
        pushButton_12->setIcon(icon6);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        label_6 = new QLabel(page_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(410, 50, 70, 19));
        textEdit = new QTextEdit(page_3);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(500, 40, 291, 41));
        textEdit_3 = new QTextEdit(page_3);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(500, 100, 291, 41));
        label_7 = new QLabel(page_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(410, 110, 91, 19));
        label_8 = new QLabel(page_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(500, 140, 141, 31));
        label_8->setFrameShape(QFrame::Shape::VLine);
        label_8->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_15 = new QPushButton(page_3);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(560, 200, 121, 41));
        tabWidget = new QTabWidget(page_3);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(50, 250, 1201, 461));
        ReveiwT = new QWidget();
        ReveiwT->setObjectName("ReveiwT");
        temp = new QPushButton(ReveiwT);
        temp->setObjectName("temp");
        temp->setGeometry(QRect(440, 120, 121, 41));
        tabWidget->addTab(ReveiwT, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());
        userPic1 = new QLabel(page_3);
        userPic1->setObjectName("userPic1");
        userPic1->setGeometry(QRect(210, 120, 51, 51));
        userPic1->setScaledContents(true);
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        scrollArea = new QScrollArea(page_4);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(130, 40, 1101, 556));
        scrollArea->setStyleSheet(QString::fromUtf8("/* Research Publication App Stylesheet - LIGHT MODE */\n"
"\n"
"* {\n"
"    font-family: -apple-system, BlinkMacSystemFont, \"Segoe UI\", Roboto, Arial, sans-serif;\n"
"}\n"
"\n"
"QMainWindow {\n"
"    background-color: #f6f8fc;\n"
"}\n"
"\n"
"#sidebar {\n"
"    background-color: #ffffff;\n"
"    border-right: 1px solid #d8e0f0;\n"
"}\n"
"\n"
"#appTitle {\n"
"    color: #1a7a7f;                /* darker version of your teal */\n"
"    font-size: 20pt;\n"
"    font-weight: bold;\n"
"    padding: 16px;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QScrollArea#scrollArea {\n"
"    background-color: #f6f8fc;\n"
"    border: none;\n"
"}\n"
"\n"
"QScrollArea#scrollArea > QWidget {\n"
"    background-color: #f6f8fc;\n"
"}\n"
"\n"
"QScrollArea#scrollArea > QWidget > QWidget {\n"
"    background-color: #f6f8fc;\n"
"}\n"
"\n"
"/* Navigation Buttons */\n"
"#homeNavButton, #myPageNavButton, #quitb {\n"
"    text-align: left;\n"
"    padding: 12px 16px;\n"
"    border-radius: 8px;\n"
"    background-color: transpar"
                        "ent;\n"
"    color: #2d3748;\n"
"    font-size: 11pt;\n"
"    border: none;\n"
"}\n"
"\n"
"#homeNavButton:hover, #myPageNavButton:hover {\n"
"    background-color: rgba(48, 185, 191, 0.08);\n"
"}\n"
"\n"
"#homeNavButton:pressed, #myPageNavButton:pressed {\n"
"    background-color: rgba(48, 185, 191, 0.15);\n"
"}\n"
"\n"
"#quitb {\n"
"    color: #2d3748;\n"
"    margin-top: 8px;\n"
"}\n"
"\n"
"#quitb:hover {\n"
"    background-color: rgba(200, 30, 30, 0.08);\n"
"    color: #c62828;\n"
"}\n"
"\n"
"/* Top Bars */\n"
"#homeTopBar, #myPageTopBar {\n"
"    background-color: #f6f8fc;\n"
"    padding: 16px 24px;\n"
"}\n"
"\n"
"#homeTitle, #myPageTitle {\n"
"    color: #1f2937;\n"
"    font-size: 18pt;\n"
"    font-weight: bold;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Search Bar */\n"
"QLineEdit#searchBar {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 20px;\n"
"    padding: 10px 16px;\n"
"    color: #1f2937;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
""
                        "QLineEdit#searchBar:focus {\n"
"    border: 2px solid #30b9bf;\n"
"    background-color: #ffffff !important;\n"
"}\n"
"\n"
"QLineEdit#searchBar:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"/* Scroll Areas */\n"
"#homeScrollArea, #myScrollArea {\n"
"    background-color: #f6f8fc;\n"
"    border: none;\n"
"}\n"
"\n"
"#homeScrollArea > QWidget, #myScrollArea > QWidget {\n"
"    background-color: #f6f8fc;\n"
"}\n"
"\n"
"/* Publication Cards */\n"
"#publicationCard {\n"
"    background-color: #ffffff;\n"
"    border-radius: 10px;\n"
"    border: 1px solid #e2e8f0;\n"
"    box-shadow: 0 1px 3px rgba(0,0,0,0.06);\n"
"}\n"
"\n"
"#publicationCard:hover {\n"
"    border: 1px solid #30b9bf;\n"
"    background-color: #f8fcff;\n"
"    box-shadow: 0 4px 12px rgba(48,185,191,0.12);\n"
"}\n"
"\n"
"#cardTitle {\n"
"    color: #1f2937;\n"
"    font-size: 14pt;\n"
"    font-weight: bold;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"#cardAuthors {\n"
"    color: #4b5563;\n"
"    font-size: 10pt;\n"
"    back"
                        "ground-color: transparent;\n"
"}\n"
"\n"
"#cardDate {\n"
"    color: #6b7280;\n"
"    font-size: 9pt;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Primary Button (Upload/Browse) */\n"
"#Browse {\n"
"    background-color: #30b9bf;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 20px;\n"
"    padding: 10px 20px;\n"
"    font-weight: bold;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"#Browse:hover {\n"
"    background-color: #3dd4db;\n"
"}\n"
"\n"
"#Browse:pressed {\n"
"    background-color: #26a0a6;\n"
"}\n"
"\n"
"/* Secondary Buttons (View, Download) */\n"
"#secondaryButton {\n"
"    background-color: transparent;\n"
"    border: 1px solid #30b9bf;\n"
"    color: #30b9bf;\n"
"    border-radius: 16px;\n"
"    padding: 6px 16px;\n"
"    font-size: 9pt;\n"
"    font-weight: 600;\n"
"}\n"
"\n"
"#secondaryButton:hover {\n"
"    background-color: #30b9bf;\n"
"    color: white;\n"
"}\n"
"\n"
"#secondaryButton:pressed {\n"
"    background-color: #26a0a6;\n"
"    color: white;\n"
"}\n"
"\n"
"/*"
                        " Default QPushButton */\n"
"QPushButton {\n"
"    background-color: #e2efff;\n"
"    color: #1e40af;\n"
"    border: 1px solid #bfdbfe;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #dbeafe;\n"
"    border-color: #93c5fd;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #bfdbfe;\n"
"    border-color: #60a5fa;\n"
"}\n"
"\n"
"/* ALL QLabel */\n"
"QLabel {\n"
"    color: #1f2937;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"#sidebar QLabel {\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"/* Status Badges */\n"
".statusAccepted {\n"
"    background-color: #dcfce7;\n"
"    color: #166534;\n"
"    border: 1px solid #86efac;\n"
"    border-radius: 12px;\n"
"    padding: 4px 12px;\n"
"    font-size: 9pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
".statusReview {\n"
"    background-color: #fef3c7;\n"
"    color: #92400e;\n"
"    border: 1px solid #fcd34d;\n"
"    border-radius: 12px;\n"
"    padding: 4px 12px;\n"
""
                        "    font-size: 9pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
".statusRejected {\n"
"    background-color: #fee2e2;\n"
"    color: #991b1b;\n"
"    border: 1px solid #fca5a5;\n"
"    border-radius: 12px;\n"
"    padding: 4px 12px;\n"
"    font-size: 9pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Scrollbars */\n"
"QScrollBar:vertical {\n"
"    background: #f6f8fc;\n"
"    width: 10px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #c0d0e8;\n"
"    min-height: 30px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #30b9bf;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    background: #f6f8fc;\n"
"    height: 10px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #c0d0e8;\n"
"    min-width: 30px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:hover {\n"
""
                        "    background: #30b9bf;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {\n"
"    width: 0px;\n"
"}\n"
"\n"
"/* ALL Input Fields */\n"
"QLineEdit {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #30b9bf;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"QTextEdit, QPlainTextEdit {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QTextEdit:focus, QPlainTextEdit:focus {\n"
"    border: 2px solid #30b9bf;\n"
"}\n"
"\n"
"QTextEdit:hover, QPlainTextEdit:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
""
                        "/* Combo Boxes */\n"
"QComboBox {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 2px solid #30b9bf;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 20px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-left: 5px solid transparent;\n"
"    border-right: 5px solid transparent;\n"
"    border-top: 5px solid #6b7280;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #c0d0e8;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"    outline: none;\n"
"}\n"
"\n"
"/* Checkboxes & Radio */\n"
"QCheckBox, QRadioButton {\n"
"    spacing: 8px;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"QCheckBox::indicator, QRadioButton::in"
                        "dicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 4px;     /* radio will override radius */\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #30b9bf;\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #ffffff;\n"
"    border: 5px solid #30b9bf;\n"
"}\n"
"\n"
"QCheckBox::indicator:hover, QRadioButton::indicator:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"/* Progress Bar */\n"
"QProgressBar {\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    text-align: center;\n"
"    background-color: #f1f5f9;\n"
"    color: #1f2937;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #30b9bf;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"/* Tooltips */\n"
"QToolTip {\n"
"    background-color: #1e293b;\n"
"    colo"
                        "r: #f1f5f9;\n"
"    border: 1px solid #30b9bf;\n"
"    padding: 6px 8px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"/* Tables / List / Tree */\n"
"QTableView, QListView, QTreeView {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 8px;\n"
"    gridline-color: #e2e8f0;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"    color: #1f2937;\n"
"    outline: none;\n"
"}\n"
"\n"
"QTableView::item:hover, QListView::item:hover, QTreeView::item:hover {\n"
"    background-color: #f0f9ff;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #f1f5f9;\n"
"    padding: 8px;\n"
"    border: none;\n"
"    border-right: 1px solid #e2e8f0;\n"
"    border-bottom: 1px solid #e2e8f0;\n"
"    color: #1f2937;\n"
"    font-weight: bold;\n"
"    font-size: 9pt;\n"
"}\n"
"\n"
"/* Menu Bar */\n"
"QMenuBar {\n"
"    background-color: #ffffff;\n"
"    border-bottom: 1px solid #d8e0f0;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
" "
                        "   background-color: #e2efff;\n"
"}\n"
"\n"
"QMenu {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #d8e0f0;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    background-color: #30b9bf;\n"
"    color: white;\n"
"}\n"
"\n"
"/* Status Bar */\n"
"QStatusBar {\n"
"    background-color: #f1f5f9;\n"
"    border-top: 1px solid #d8e0f0;\n"
"    color: #4b5563;\n"
"}\n"
"\n"
"/* Group Box */\n"
"QGroupBox {\n"
"    border: 1px solid #d8e0f0;\n"
"    border-radius: 8px;\n"
"    margin-top: 12px;\n"
"    padding-top: 12px;\n"
"    color: #1f2937;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 0 8px;\n"
"    color: #1a7a7f;\n"
"}\n"
"\n"
"/* Tabs */\n"
"QTabWidget::pane {\n"
"    border: 1px solid #d8e0f0;\n"
"    background-color: #ffffff;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: #f8fafc;\n"
"    color: #64748b;\n"
"    border: none;\n"
"    "
                        "border-bottom: 3px solid transparent;\n"
"    padding: 12px 20px;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    color: #1f2937;\n"
"    background-color: #ffffff;\n"
"    border-bottom: 3px solid #30b9bf;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    color: #1f2937;\n"
"    background-color: #f1f5f9;\n"
"}"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1101, 556));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("/* Research Publication App Stylesheet - LIGHT MODE */\n"
"\n"
"* {\n"
"    font-family: -apple-system, BlinkMacSystemFont, \"Segoe UI\", Roboto, Arial, sans-serif;\n"
"}\n"
"\n"
"QMainWindow {\n"
"    background-color: #f6f8fc;\n"
"}\n"
"\n"
"#sidebar {\n"
"    background-color: #ffffff;\n"
"    border-right: 1px solid #d8e0f0;\n"
"}\n"
"\n"
"#appTitle {\n"
"    color: #1a7a7f;                /* darker version of your teal */\n"
"    font-size: 20pt;\n"
"    font-weight: bold;\n"
"    padding: 16px;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Navigation Buttons */\n"
"#homeNavButton, #myPageNavButton, #quitb {\n"
"    text-align: left;\n"
"    padding: 12px 16px;\n"
"    border-radius: 8px;\n"
"    background-color: transparent;\n"
"    color: #2d3748;\n"
"    font-size: 11pt;\n"
"    border: none;\n"
"}\n"
"\n"
"#homeNavButton:hover, #myPageNavButton:hover {\n"
"    background-color: rgba(48, 185, 191, 0.08);\n"
"}\n"
"\n"
"#homeNavButton:pressed, #myPageNavButton:pressed {\n"
"    background-co"
                        "lor: rgba(48, 185, 191, 0.15);\n"
"}\n"
"\n"
"#quitb {\n"
"    color: #2d3748;\n"
"    margin-top: 8px;\n"
"}\n"
"\n"
"#quitb:hover {\n"
"    background-color: rgba(200, 30, 30, 0.08);\n"
"    color: #c62828;\n"
"}\n"
"\n"
"/* Top Bars */\n"
"#homeTopBar, #myPageTopBar {\n"
"    background-color: #f6f8fc;\n"
"    padding: 16px 24px;\n"
"}\n"
"\n"
"#homeTitle, #myPageTitle {\n"
"    color: #1f2937;\n"
"    font-size: 18pt;\n"
"    font-weight: bold;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Search Bar */\n"
"QLineEdit#searchBar {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 20px;\n"
"    padding: 10px 16px;\n"
"    color: #1f2937;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QLineEdit#searchBar:focus {\n"
"    border: 2px solid #30b9bf;\n"
"    background-color: #ffffff !important;\n"
"}\n"
"\n"
"QLineEdit#searchBar:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"/* Scroll Areas */\n"
"#homeScrollArea, #myScrollArea {\n"
"    backgro"
                        "und-color: #f6f8fc;\n"
"    border: none;\n"
"}\n"
"\n"
"#homeScrollArea > QWidget, #myScrollArea > QWidget {\n"
"    background-color: #f6f8fc;\n"
"}\n"
"\n"
"/* Publication Cards */\n"
"#publicationCard {\n"
"    background-color: #ffffff;\n"
"    border-radius: 10px;\n"
"    border: 1px solid #e2e8f0;\n"
"    box-shadow: 0 1px 3px rgba(0,0,0,0.06);\n"
"}\n"
"\n"
"#publicationCard:hover {\n"
"    border: 1px solid #30b9bf;\n"
"    background-color: #f8fcff;\n"
"    box-shadow: 0 4px 12px rgba(48,185,191,0.12);\n"
"}\n"
"\n"
"#cardTitle {\n"
"    color: #1f2937;\n"
"    font-size: 14pt;\n"
"    font-weight: bold;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"#cardAuthors {\n"
"    color: #4b5563;\n"
"    font-size: 10pt;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"#cardDate {\n"
"    color: #6b7280;\n"
"    font-size: 9pt;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Primary Button (Upload/Browse) */\n"
"#Browse {\n"
"    background-color: #30b9bf;\n"
"    color: white;\n"
"    b"
                        "order: none;\n"
"    border-radius: 20px;\n"
"    padding: 10px 20px;\n"
"    font-weight: bold;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"#Browse:hover {\n"
"    background-color: #3dd4db;\n"
"}\n"
"\n"
"#Browse:pressed {\n"
"    background-color: #26a0a6;\n"
"}\n"
"\n"
"/* Secondary Buttons (View, Download) */\n"
"#secondaryButton {\n"
"    background-color: transparent;\n"
"    border: 1px solid #30b9bf;\n"
"    color: #30b9bf;\n"
"    border-radius: 16px;\n"
"    padding: 6px 16px;\n"
"    font-size: 9pt;\n"
"    font-weight: 600;\n"
"}\n"
"\n"
"#secondaryButton:hover {\n"
"    background-color: #30b9bf;\n"
"    color: white;\n"
"}\n"
"\n"
"#secondaryButton:pressed {\n"
"    background-color: #26a0a6;\n"
"    color: white;\n"
"}\n"
"\n"
"/* Default QPushButton */\n"
"QPushButton {\n"
"    background-color: #e2efff;\n"
"    color: #1e40af;\n"
"    border: 1px solid #bfdbfe;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-col"
                        "or: #dbeafe;\n"
"    border-color: #93c5fd;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #bfdbfe;\n"
"    border-color: #60a5fa;\n"
"}\n"
"\n"
"/* ALL QLabel */\n"
"QLabel {\n"
"    color: #1f2937;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"#sidebar QLabel {\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"/* Status Badges */\n"
".statusAccepted {\n"
"    background-color: #dcfce7;\n"
"    color: #166534;\n"
"    border: 1px solid #86efac;\n"
"    border-radius: 12px;\n"
"    padding: 4px 12px;\n"
"    font-size: 9pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
".statusReview {\n"
"    background-color: #fef3c7;\n"
"    color: #92400e;\n"
"    border: 1px solid #fcd34d;\n"
"    border-radius: 12px;\n"
"    padding: 4px 12px;\n"
"    font-size: 9pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
".statusRejected {\n"
"    background-color: #fee2e2;\n"
"    color: #991b1b;\n"
"    border: 1px solid #fca5a5;\n"
"    border-radius: 12px;\n"
"    padding: 4px 12px;\n"
"    font-size: 9pt;\n"
"    font-wei"
                        "ght: bold;\n"
"}\n"
"\n"
"/* Scrollbars */\n"
"QScrollBar:vertical {\n"
"    background: #f6f8fc;\n"
"    width: 10px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #c0d0e8;\n"
"    min-height: 30px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #30b9bf;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    background: #f6f8fc;\n"
"    height: 10px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #c0d0e8;\n"
"    min-width: 30px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:hover {\n"
"    background: #30b9bf;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {\n"
"    width: 0px;\n"
"}\n"
"\n"
"/* ALL Input Fields */\n"
"QLineEdit {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
" "
                        "   border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #30b9bf;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"QTextEdit, QPlainTextEdit {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QTextEdit:focus, QPlainTextEdit:focus {\n"
"    border: 2px solid #30b9bf;\n"
"}\n"
"\n"
"QTextEdit:hover, QPlainTextEdit:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"/* Combo Boxes */\n"
"QComboBox {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    bo"
                        "rder: 1px solid #30b9bf;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 2px solid #30b9bf;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 20px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-left: 5px solid transparent;\n"
"    border-right: 5px solid transparent;\n"
"    border-top: 5px solid #6b7280;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #c0d0e8;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"    outline: none;\n"
"}\n"
"\n"
"/* Checkboxes & Radio */\n"
"QCheckBox, QRadioButton {\n"
"    spacing: 8px;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"QCheckBox::indicator, QRadioButton::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 4px;     /* radio will override radius */\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #30"
                        "b9bf;\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #ffffff;\n"
"    border: 5px solid #30b9bf;\n"
"}\n"
"\n"
"QCheckBox::indicator:hover, QRadioButton::indicator:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"/* Progress Bar */\n"
"QProgressBar {\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    text-align: center;\n"
"    background-color: #f1f5f9;\n"
"    color: #1f2937;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #30b9bf;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"/* Tooltips */\n"
"QToolTip {\n"
"    background-color: #1e293b;\n"
"    color: #f1f5f9;\n"
"    border: 1px solid #30b9bf;\n"
"    padding: 6px 8px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"/* Tables / List / Tree */\n"
"QTableView, QListView, QTreeView {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #e2e8f0;\n"
"    bor"
                        "der-radius: 8px;\n"
"    gridline-color: #e2e8f0;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"    color: #1f2937;\n"
"    outline: none;\n"
"}\n"
"\n"
"QTableView::item:hover, QListView::item:hover, QTreeView::item:hover {\n"
"    background-color: #f0f9ff;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #f1f5f9;\n"
"    padding: 8px;\n"
"    border: none;\n"
"    border-right: 1px solid #e2e8f0;\n"
"    border-bottom: 1px solid #e2e8f0;\n"
"    color: #1f2937;\n"
"    font-weight: bold;\n"
"    font-size: 9pt;\n"
"}\n"
"\n"
"/* Menu Bar */\n"
"QMenuBar {\n"
"    background-color: #ffffff;\n"
"    border-bottom: 1px solid #d8e0f0;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: #e2efff;\n"
"}\n"
"\n"
"QMenu {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #d8e0f0;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    background-color: #30b9bf;\n"
"    color: white;\n"
"}\n"
"\n"
"/* Sta"
                        "tus Bar */\n"
"QStatusBar {\n"
"    background-color: #f1f5f9;\n"
"    border-top: 1px solid #d8e0f0;\n"
"    color: #4b5563;\n"
"}\n"
"\n"
"/* Group Box */\n"
"QGroupBox {\n"
"    border: 1px solid #d8e0f0;\n"
"    border-radius: 8px;\n"
"    margin-top: 12px;\n"
"    padding-top: 12px;\n"
"    color: #1f2937;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 0 8px;\n"
"    color: #1a7a7f;\n"
"}\n"
"\n"
"/* Tabs */\n"
"QTabWidget::pane {\n"
"    border: 1px solid #d8e0f0;\n"
"    background-color: #ffffff;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: #f8fafc;\n"
"    color: #64748b;\n"
"    border: none;\n"
"    border-bottom: 3px solid transparent;\n"
"    padding: 12px 20px;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    color: #1f2937;\n"
"    background-color: #ffffff;\n"
"    border-bottom: 3px solid #30b9bf;\n"
"}\n"
"\n"
"QTabBar::tab:hov"
                        "er {\n"
"    color: #1f2937;\n"
"    background-color: #f1f5f9;\n"
"}"));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("/* Research Publication App Stylesheet - LIGHT MODE */\n"
"\n"
"* {\n"
"    font-family: -apple-system, BlinkMacSystemFont, \"Segoe UI\", Roboto, Arial, sans-serif;\n"
"}\n"
"\n"
"QMainWindow {\n"
"    background-color: #f6f8fc;\n"
"}\n"
"\n"
"#sidebar {\n"
"    background-color: #ffffff;\n"
"    border-right: 1px solid #d8e0f0;\n"
"}\n"
"\n"
"#appTitle {\n"
"    color: #1a7a7f;                /* darker version of your teal */\n"
"    font-size: 20pt;\n"
"    font-weight: bold;\n"
"    padding: 16px;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Navigation Buttons */\n"
"#homeNavButton, #myPageNavButton, #quitb {\n"
"    text-align: left;\n"
"    padding: 12px 16px;\n"
"    border-radius: 8px;\n"
"    background-color: transparent;\n"
"    color: #2d3748;\n"
"    font-size: 11pt;\n"
"    border: none;\n"
"}\n"
"\n"
"#homeNavButton:hover, #myPageNavButton:hover {\n"
"    background-color: rgba(48, 185, 191, 0.08);\n"
"}\n"
"\n"
"#homeNavButton:pressed, #myPageNavButton:pressed {\n"
"    background-co"
                        "lor: rgba(48, 185, 191, 0.15);\n"
"}\n"
"\n"
"#quitb {\n"
"    color: #2d3748;\n"
"    margin-top: 8px;\n"
"}\n"
"\n"
"#quitb:hover {\n"
"    background-color: rgba(200, 30, 30, 0.08);\n"
"    color: #c62828;\n"
"}\n"
"\n"
"/* Top Bars */\n"
"#homeTopBar, #myPageTopBar {\n"
"    background-color: #f6f8fc;\n"
"    padding: 16px 24px;\n"
"}\n"
"\n"
"#homeTitle, #myPageTitle {\n"
"    color: #1f2937;\n"
"    font-size: 18pt;\n"
"    font-weight: bold;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Search Bar */\n"
"QLineEdit#searchBar {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 20px;\n"
"    padding: 10px 16px;\n"
"    color: #1f2937;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QLineEdit#searchBar:focus {\n"
"    border: 2px solid #30b9bf;\n"
"    background-color: #ffffff !important;\n"
"}\n"
"\n"
"QLineEdit#searchBar:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"/* Scroll Areas */\n"
"#homeScrollArea, #myScrollArea {\n"
"    backgro"
                        "und-color: #f6f8fc;\n"
"    border: none;\n"
"}\n"
"\n"
"#homeScrollArea > QWidget, #myScrollArea > QWidget {\n"
"    background-color: #f6f8fc;\n"
"}\n"
"\n"
"/* Publication Cards */\n"
"#publicationCard {\n"
"    background-color: #ffffff;\n"
"    border-radius: 10px;\n"
"    border: 1px solid #e2e8f0;\n"
"    box-shadow: 0 1px 3px rgba(0,0,0,0.06);\n"
"}\n"
"\n"
"#publicationCard:hover {\n"
"    border: 1px solid #30b9bf;\n"
"    background-color: #f8fcff;\n"
"    box-shadow: 0 4px 12px rgba(48,185,191,0.12);\n"
"}\n"
"\n"
"#cardTitle {\n"
"    color: #1f2937;\n"
"    font-size: 14pt;\n"
"    font-weight: bold;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"#cardAuthors {\n"
"    color: #4b5563;\n"
"    font-size: 10pt;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"#cardDate {\n"
"    color: #6b7280;\n"
"    font-size: 9pt;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Primary Button (Upload/Browse) */\n"
"#Browse {\n"
"    background-color: #30b9bf;\n"
"    color: white;\n"
"    b"
                        "order: none;\n"
"    border-radius: 20px;\n"
"    padding: 10px 20px;\n"
"    font-weight: bold;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"#Browse:hover {\n"
"    background-color: #3dd4db;\n"
"}\n"
"\n"
"#Browse:pressed {\n"
"    background-color: #26a0a6;\n"
"}\n"
"\n"
"/* Secondary Buttons (View, Download) */\n"
"#secondaryButton {\n"
"    background-color: transparent;\n"
"    border: 1px solid #30b9bf;\n"
"    color: #30b9bf;\n"
"    border-radius: 16px;\n"
"    padding: 6px 16px;\n"
"    font-size: 9pt;\n"
"    font-weight: 600;\n"
"}\n"
"\n"
"#secondaryButton:hover {\n"
"    background-color: #30b9bf;\n"
"    color: white;\n"
"}\n"
"\n"
"#secondaryButton:pressed {\n"
"    background-color: #26a0a6;\n"
"    color: white;\n"
"}\n"
"\n"
"/* Default QPushButton */\n"
"QPushButton {\n"
"    background-color: #e2efff;\n"
"    color: #1e40af;\n"
"    border: 1px solid #bfdbfe;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-col"
                        "or: #dbeafe;\n"
"    border-color: #93c5fd;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #bfdbfe;\n"
"    border-color: #60a5fa;\n"
"}\n"
"\n"
"/* ALL QLabel */\n"
"QLabel {\n"
"    color: #1f2937;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"#sidebar QLabel {\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"/* Status Badges */\n"
".statusAccepted {\n"
"    background-color: #dcfce7;\n"
"    color: #166534;\n"
"    border: 1px solid #86efac;\n"
"    border-radius: 12px;\n"
"    padding: 4px 12px;\n"
"    font-size: 9pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
".statusReview {\n"
"    background-color: #fef3c7;\n"
"    color: #92400e;\n"
"    border: 1px solid #fcd34d;\n"
"    border-radius: 12px;\n"
"    padding: 4px 12px;\n"
"    font-size: 9pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
".statusRejected {\n"
"    background-color: #fee2e2;\n"
"    color: #991b1b;\n"
"    border: 1px solid #fca5a5;\n"
"    border-radius: 12px;\n"
"    padding: 4px 12px;\n"
"    font-size: 9pt;\n"
"    font-wei"
                        "ght: bold;\n"
"}\n"
"\n"
"/* Scrollbars */\n"
"QScrollBar:vertical {\n"
"    background: #f6f8fc;\n"
"    width: 10px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #c0d0e8;\n"
"    min-height: 30px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #30b9bf;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    background: #f6f8fc;\n"
"    height: 10px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #c0d0e8;\n"
"    min-width: 30px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:hover {\n"
"    background: #30b9bf;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {\n"
"    width: 0px;\n"
"}\n"
"\n"
"/* ALL Input Fields */\n"
"QLineEdit {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
" "
                        "   border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #30b9bf;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"QTextEdit, QPlainTextEdit {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QTextEdit:focus, QPlainTextEdit:focus {\n"
"    border: 2px solid #30b9bf;\n"
"}\n"
"\n"
"QTextEdit:hover, QPlainTextEdit:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"/* Combo Boxes */\n"
"QComboBox {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    bo"
                        "rder: 1px solid #30b9bf;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 2px solid #30b9bf;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 20px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-left: 5px solid transparent;\n"
"    border-right: 5px solid transparent;\n"
"    border-top: 5px solid #6b7280;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #c0d0e8;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"    outline: none;\n"
"}\n"
"\n"
"/* Checkboxes & Radio */\n"
"QCheckBox, QRadioButton {\n"
"    spacing: 8px;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"QCheckBox::indicator, QRadioButton::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 4px;     /* radio will override radius */\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #30"
                        "b9bf;\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #ffffff;\n"
"    border: 5px solid #30b9bf;\n"
"}\n"
"\n"
"QCheckBox::indicator:hover, QRadioButton::indicator:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"/* Progress Bar */\n"
"QProgressBar {\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    text-align: center;\n"
"    background-color: #f1f5f9;\n"
"    color: #1f2937;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #30b9bf;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"/* Tooltips */\n"
"QToolTip {\n"
"    background-color: #1e293b;\n"
"    color: #f1f5f9;\n"
"    border: 1px solid #30b9bf;\n"
"    padding: 6px 8px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"/* Tables / List / Tree */\n"
"QTableView, QListView, QTreeView {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #e2e8f0;\n"
"    bor"
                        "der-radius: 8px;\n"
"    gridline-color: #e2e8f0;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"    color: #1f2937;\n"
"    outline: none;\n"
"}\n"
"\n"
"QTableView::item:hover, QListView::item:hover, QTreeView::item:hover {\n"
"    background-color: #f0f9ff;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #f1f5f9;\n"
"    padding: 8px;\n"
"    border: none;\n"
"    border-right: 1px solid #e2e8f0;\n"
"    border-bottom: 1px solid #e2e8f0;\n"
"    color: #1f2937;\n"
"    font-weight: bold;\n"
"    font-size: 9pt;\n"
"}\n"
"\n"
"/* Menu Bar */\n"
"QMenuBar {\n"
"    background-color: #ffffff;\n"
"    border-bottom: 1px solid #d8e0f0;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: #e2efff;\n"
"}\n"
"\n"
"QMenu {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #d8e0f0;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    background-color: #30b9bf;\n"
"    color: white;\n"
"}\n"
"\n"
"/* Sta"
                        "tus Bar */\n"
"QStatusBar {\n"
"    background-color: #f1f5f9;\n"
"    border-top: 1px solid #d8e0f0;\n"
"    color: #4b5563;\n"
"}\n"
"\n"
"/* Group Box */\n"
"QGroupBox {\n"
"    border: 1px solid #d8e0f0;\n"
"    border-radius: 8px;\n"
"    margin-top: 12px;\n"
"    padding-top: 12px;\n"
"    color: #1f2937;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 0 8px;\n"
"    color: #1a7a7f;\n"
"}\n"
"\n"
"/* Tabs */\n"
"QTabWidget::pane {\n"
"    border: 1px solid #d8e0f0;\n"
"    background-color: #ffffff;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: #f8fafc;\n"
"    color: #64748b;\n"
"    border: none;\n"
"    border-bottom: 3px solid transparent;\n"
"    padding: 12px 20px;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    color: #1f2937;\n"
"    background-color: #ffffff;\n"
"    border-bottom: 3px solid #30b9bf;\n"
"}\n"
"\n"
"QTabBar::tab:hov"
                        "er {\n"
"    color: #1f2937;\n"
"    background-color: #f1f5f9;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        frame = new QFrame(widget);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("/* Research Publication App Stylesheet - LIGHT MODE */\n"
"\n"
"* {\n"
"    font-family: -apple-system, BlinkMacSystemFont, \"Segoe UI\", Roboto, Arial, sans-serif;\n"
"}\n"
"\n"
"QMainWindow {\n"
"    background-color: #f6f8fc;\n"
"}\n"
"\n"
"#sidebar {\n"
"    background-color: #ffffff;\n"
"    border-right: 1px solid #d8e0f0;\n"
"}\n"
"\n"
"#appTitle {\n"
"    color: #1a7a7f;                /* darker version of your teal */\n"
"    font-size: 20pt;\n"
"    font-weight: bold;\n"
"    padding: 16px;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Navigation Buttons */\n"
"#homeNavButton, #myPageNavButton, #quitb {\n"
"    text-align: left;\n"
"    padding: 12px 16px;\n"
"    border-radius: 8px;\n"
"    background-color: transparent;\n"
"    color: #2d3748;\n"
"    font-size: 11pt;\n"
"    border: none;\n"
"}\n"
"\n"
"#homeNavButton:hover, #myPageNavButton:hover {\n"
"    background-color: rgba(48, 185, 191, 0.08);\n"
"}\n"
"\n"
"#homeNavButton:pressed, #myPageNavButton:pressed {\n"
"    background-co"
                        "lor: rgba(48, 185, 191, 0.15);\n"
"}\n"
"\n"
"#quitb {\n"
"    color: #2d3748;\n"
"    margin-top: 8px;\n"
"}\n"
"\n"
"#quitb:hover {\n"
"    background-color: rgba(200, 30, 30, 0.08);\n"
"    color: #c62828;\n"
"}\n"
"\n"
"/* Top Bars */\n"
"#homeTopBar, #myPageTopBar {\n"
"    background-color: #f6f8fc;\n"
"    padding: 16px 24px;\n"
"}\n"
"\n"
"#homeTitle, #myPageTitle {\n"
"    color: #1f2937;\n"
"    font-size: 18pt;\n"
"    font-weight: bold;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Search Bar */\n"
"QLineEdit#searchBar {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 20px;\n"
"    padding: 10px 16px;\n"
"    color: #1f2937;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QLineEdit#searchBar:focus {\n"
"    border: 2px solid #30b9bf;\n"
"    background-color: #ffffff !important;\n"
"}\n"
"\n"
"QLineEdit#searchBar:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"/* Scroll Areas */\n"
"#homeScrollArea, #myScrollArea {\n"
"    backgro"
                        "und-color: #f6f8fc;\n"
"    border: none;\n"
"}\n"
"\n"
"#homeScrollArea > QWidget, #myScrollArea > QWidget {\n"
"    background-color: #f6f8fc;\n"
"}\n"
"\n"
"/* Publication Cards */\n"
"#publicationCard {\n"
"    background-color: #ffffff;\n"
"    border-radius: 10px;\n"
"    border: 1px solid #e2e8f0;\n"
"    box-shadow: 0 1px 3px rgba(0,0,0,0.06);\n"
"}\n"
"\n"
"#publicationCard:hover {\n"
"    border: 1px solid #30b9bf;\n"
"    background-color: #f8fcff;\n"
"    box-shadow: 0 4px 12px rgba(48,185,191,0.12);\n"
"}\n"
"\n"
"#cardTitle {\n"
"    color: #1f2937;\n"
"    font-size: 14pt;\n"
"    font-weight: bold;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"#cardAuthors {\n"
"    color: #4b5563;\n"
"    font-size: 10pt;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"#cardDate {\n"
"    color: #6b7280;\n"
"    font-size: 9pt;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Primary Button (Upload/Browse) */\n"
"#Browse {\n"
"    background-color: #30b9bf;\n"
"    color: white;\n"
"    b"
                        "order: none;\n"
"    border-radius: 20px;\n"
"    padding: 10px 20px;\n"
"    font-weight: bold;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"#Browse:hover {\n"
"    background-color: #3dd4db;\n"
"}\n"
"\n"
"#Browse:pressed {\n"
"    background-color: #26a0a6;\n"
"}\n"
"\n"
"/* Secondary Buttons (View, Download) */\n"
"#secondaryButton {\n"
"    background-color: transparent;\n"
"    border: 1px solid #30b9bf;\n"
"    color: #30b9bf;\n"
"    border-radius: 16px;\n"
"    padding: 6px 16px;\n"
"    font-size: 9pt;\n"
"    font-weight: 600;\n"
"}\n"
"\n"
"#secondaryButton:hover {\n"
"    background-color: #30b9bf;\n"
"    color: white;\n"
"}\n"
"\n"
"#secondaryButton:pressed {\n"
"    background-color: #26a0a6;\n"
"    color: white;\n"
"}\n"
"\n"
"/* Default QPushButton */\n"
"QPushButton {\n"
"    background-color: #e2efff;\n"
"    color: #1e40af;\n"
"    border: 1px solid #bfdbfe;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-col"
                        "or: #dbeafe;\n"
"    border-color: #93c5fd;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #bfdbfe;\n"
"    border-color: #60a5fa;\n"
"}\n"
"\n"
"/* ALL QLabel */\n"
"QLabel {\n"
"    color: #1f2937;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"#sidebar QLabel {\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"/* Status Badges */\n"
".statusAccepted {\n"
"    background-color: #dcfce7;\n"
"    color: #166534;\n"
"    border: 1px solid #86efac;\n"
"    border-radius: 12px;\n"
"    padding: 4px 12px;\n"
"    font-size: 9pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
".statusReview {\n"
"    background-color: #fef3c7;\n"
"    color: #92400e;\n"
"    border: 1px solid #fcd34d;\n"
"    border-radius: 12px;\n"
"    padding: 4px 12px;\n"
"    font-size: 9pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
".statusRejected {\n"
"    background-color: #fee2e2;\n"
"    color: #991b1b;\n"
"    border: 1px solid #fca5a5;\n"
"    border-radius: 12px;\n"
"    padding: 4px 12px;\n"
"    font-size: 9pt;\n"
"    font-wei"
                        "ght: bold;\n"
"}\n"
"\n"
"/* Scrollbars */\n"
"QScrollBar:vertical {\n"
"    background: #f6f8fc;\n"
"    width: 10px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #c0d0e8;\n"
"    min-height: 30px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #30b9bf;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    background: #f6f8fc;\n"
"    height: 10px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #c0d0e8;\n"
"    min-width: 30px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:hover {\n"
"    background: #30b9bf;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {\n"
"    width: 0px;\n"
"}\n"
"\n"
"/* ALL Input Fields */\n"
"QLineEdit {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
" "
                        "   border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #30b9bf;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"QTextEdit, QPlainTextEdit {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QTextEdit:focus, QPlainTextEdit:focus {\n"
"    border: 2px solid #30b9bf;\n"
"}\n"
"\n"
"QTextEdit:hover, QPlainTextEdit:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"/* Combo Boxes */\n"
"QComboBox {\n"
"    background-color: #ffffff !important;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    color: #1f2937;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    bo"
                        "rder: 1px solid #30b9bf;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 2px solid #30b9bf;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 20px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-left: 5px solid transparent;\n"
"    border-right: 5px solid transparent;\n"
"    border-top: 5px solid #6b7280;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #c0d0e8;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"    outline: none;\n"
"}\n"
"\n"
"/* Checkboxes & Radio */\n"
"QCheckBox, QRadioButton {\n"
"    spacing: 8px;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"QCheckBox::indicator, QRadioButton::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 4px;     /* radio will override radius */\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #30"
                        "b9bf;\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #ffffff;\n"
"    border: 5px solid #30b9bf;\n"
"}\n"
"\n"
"QCheckBox::indicator:hover, QRadioButton::indicator:hover {\n"
"    border: 1px solid #30b9bf;\n"
"}\n"
"\n"
"/* Progress Bar */\n"
"QProgressBar {\n"
"    border: 1px solid #c0d0e8;\n"
"    border-radius: 6px;\n"
"    text-align: center;\n"
"    background-color: #f1f5f9;\n"
"    color: #1f2937;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #30b9bf;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"/* Tooltips */\n"
"QToolTip {\n"
"    background-color: #1e293b;\n"
"    color: #f1f5f9;\n"
"    border: 1px solid #30b9bf;\n"
"    padding: 6px 8px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"/* Tables / List / Tree */\n"
"QTableView, QListView, QTreeView {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #e2e8f0;\n"
"    bor"
                        "der-radius: 8px;\n"
"    gridline-color: #e2e8f0;\n"
"    selection-background-color: #30b9bf;\n"
"    selection-color: white;\n"
"    color: #1f2937;\n"
"    outline: none;\n"
"}\n"
"\n"
"QTableView::item:hover, QListView::item:hover, QTreeView::item:hover {\n"
"    background-color: #f0f9ff;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #f1f5f9;\n"
"    padding: 8px;\n"
"    border: none;\n"
"    border-right: 1px solid #e2e8f0;\n"
"    border-bottom: 1px solid #e2e8f0;\n"
"    color: #1f2937;\n"
"    font-weight: bold;\n"
"    font-size: 9pt;\n"
"}\n"
"\n"
"/* Menu Bar */\n"
"QMenuBar {\n"
"    background-color: #ffffff;\n"
"    border-bottom: 1px solid #d8e0f0;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: #e2efff;\n"
"}\n"
"\n"
"QMenu {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #d8e0f0;\n"
"    color: #1f2937;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    background-color: #30b9bf;\n"
"    color: white;\n"
"}\n"
"\n"
"/* Sta"
                        "tus Bar */\n"
"QStatusBar {\n"
"    background-color: #f1f5f9;\n"
"    border-top: 1px solid #d8e0f0;\n"
"    color: #4b5563;\n"
"}\n"
"\n"
"/* Group Box */\n"
"QGroupBox {\n"
"    border: 1px solid #d8e0f0;\n"
"    border-radius: 8px;\n"
"    margin-top: 12px;\n"
"    padding-top: 12px;\n"
"    color: #1f2937;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 0 8px;\n"
"    color: #1a7a7f;\n"
"}\n"
"\n"
"/* Tabs */\n"
"QTabWidget::pane {\n"
"    border: 1px solid #d8e0f0;\n"
"    background-color: #ffffff;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: #f8fafc;\n"
"    color: #64748b;\n"
"    border: none;\n"
"    border-bottom: 3px solid transparent;\n"
"    padding: 12px 20px;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    color: #1f2937;\n"
"    background-color: #ffffff;\n"
"    border-bottom: 3px solid #30b9bf;\n"
"}\n"
"\n"
"QTabBar::tab:hov"
                        "er {\n"
"    color: #1f2937;\n"
"    background-color: #f1f5f9;\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_9 = new QLabel(frame);
        label_9->setObjectName("label_9");
        label_9->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(label_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_10 = new QLabel(frame);
        label_10->setObjectName("label_10");
        label_10->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(label_10);

        label_11 = new QLabel(frame);
        label_11->setObjectName("label_11");
        label_11->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(label_11);

        label_12 = new QLabel(frame);
        label_12->setObjectName("label_12");
        label_12->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(label_12);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_16 = new QPushButton(frame);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_16->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(pushButton_16);

        editConferenceBtn = new QPushButton(frame);
        editConferenceBtn->setObjectName("editConferenceBtn");
        editConferenceBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        editConferenceBtn->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(editConferenceBtn);

        pushButton_17 = new QPushButton(frame);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_17->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(pushButton_17);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(frame);


        verticalLayout->addWidget(widget);

        scrollArea->setWidget(scrollAreaWidgetContents);
        profile3 = new QPushButton(page_4);
        profile3->setObjectName("profile3");
        profile3->setGeometry(QRect(20, 610, 41, 41));
        profile3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        profile3->setIcon(icon4);
        line_5 = new QFrame(page_4);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(80, -30, 20, 841));
        QPalette palette8;
        line_5->setPalette(palette8);
        line_5->setCursor(QCursor(Qt::CursorShape::ForbiddenCursor));
        line_5->setAutoFillBackground(false);
        line_5->setFrameShadow(QFrame::Shadow::Plain);
        line_5->setLineWidth(3);
        line_5->setFrameShape(QFrame::Shape::VLine);
        pushButton_18 = new QPushButton(page_4);
        pushButton_18->setObjectName("pushButton_18");
        pushButton_18->setGeometry(QRect(740, 630, 321, 51));
        pushButton_18->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        pushButton_18->setStyleSheet(QString::fromUtf8(""));
        addConferenceBtn = new QPushButton(page_4);
        addConferenceBtn->setObjectName("addConferenceBtn");
        addConferenceBtn->setGeometry(QRect(340, 630, 301, 51));
        addConferenceBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addConferenceBtn->setStyleSheet(QString::fromUtf8(""));
        pushButton_23 = new QPushButton(page_4);
        pushButton_23->setObjectName("pushButton_23");
        pushButton_23->setGeometry(QRect(20, 500, 41, 41));
        pushButton_23->setIcon(icon6);
        pushButton_19 = new QPushButton(page_4);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setGeometry(QRect(20, 260, 41, 41));
        pushButton_19->setIcon(icon1);
        pushButton_21 = new QPushButton(page_4);
        pushButton_21->setObjectName("pushButton_21");
        pushButton_21->setGeometry(QRect(20, 340, 41, 41));
        pushButton_21->setIcon(icon2);
        homeButton3 = new QPushButton(page_4);
        homeButton3->setObjectName("homeButton3");
        homeButton3->setEnabled(true);
        homeButton3->setGeometry(QRect(20, 80, 40, 40));
        homeButton3->setMinimumSize(QSize(40, 40));
        homeButton3->setMaximumSize(QSize(40, 40));
        homeButton3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        homeButton3->setMouseTracking(true);
        homeButton3->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        homeButton3->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        homeButton3->setAutoFillBackground(false);
        homeButton3->setIcon(icon3);
        homeButton3->setIconSize(QSize(22, 22));
        homeButton3->setFlat(true);
        reveiw3 = new QPushButton(page_4);
        reveiw3->setObjectName("reveiw3");
        reveiw3->setGeometry(QRect(20, 180, 41, 41));
        reveiw3->setIcon(icon);
        pic_3 = new QLabel(page_4);
        pic_3->setObjectName("pic_3");
        pic_3->setGeometry(QRect(20, 10, 41, 41));
        pic_3->setPixmap(QPixmap(QString::fromUtf8("build/Desktop_Qt_6_7_3-Debug/icons/user.svg")));
        pic_3->setScaledContents(true);
        pic_3->setWordWrap(false);
        pushButton_22 = new QPushButton(page_4);
        pushButton_22->setObjectName("pushButton_22");
        pushButton_22->setGeometry(QRect(20, 420, 41, 41));
        pushButton_22->setIcon(icon5);
        stackedWidget->addWidget(page_4);
        page_9 = new QWidget();
        page_9->setObjectName("page_9");
        frame_3 = new QFrame(page_9);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(10, 10, 771, 461));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        layoutWidget_3 = new QWidget(frame_3);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(0, 0, 761, 441));
        formLayout = new QFormLayout(layoutWidget_3);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(10, 10, 10, 0);
        label_25 = new QLabel(layoutWidget_3);
        label_25->setObjectName("label_25");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_25);

        topicCombo = new QComboBox(layoutWidget_3);
        topicCombo->setObjectName("topicCombo");

        formLayout->setWidget(0, QFormLayout::FieldRole, topicCombo);

        label_26 = new QLabel(layoutWidget_3);
        label_26->setObjectName("label_26");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_26);

        dateEdit = new QDateEdit(layoutWidget_3);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(1, QFormLayout::FieldRole, dateEdit);

        label_27 = new QLabel(layoutWidget_3);
        label_27->setObjectName("label_27");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_27);

        locationEdit = new QLineEdit(layoutWidget_3);
        locationEdit->setObjectName("locationEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, locationEdit);

        label_28 = new QLabel(layoutWidget_3);
        label_28->setObjectName("label_28");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_28);

        priceSpin = new QDoubleSpinBox(layoutWidget_3);
        priceSpin->setObjectName("priceSpin");
        priceSpin->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(4, QFormLayout::FieldRole, priceSpin);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        saveButton = new QPushButton(layoutWidget_3);
        saveButton->setObjectName("saveButton");
        saveButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout->addWidget(saveButton);

        cancelButton = new QPushButton(layoutWidget_3);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);


        formLayout->setLayout(6, QFormLayout::FieldRole, horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 200, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        formLayout->setItem(5, QFormLayout::FieldRole, verticalSpacer);

        stackedWidget->addWidget(page_9);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        reveiw4->setToolTip(QCoreApplication::translate("MainWindow", "Send to Research Reveiw", nullptr));
#endif // QT_CONFIG(tooltip)
        reveiw4->setText(QString());
        pushButton_25->setText(QString());
        pushButton_26->setText(QString());
#if QT_CONFIG(tooltip)
        homeButton4->setToolTip(QCoreApplication::translate("MainWindow", "Home", nullptr));
#endif // QT_CONFIG(tooltip)
        homeButton4->setText(QString());
        pic_4->setText(QString());
        profile4->setText(QString());
        pushButton_28->setText(QString());
        pushButton_29->setText(QString());
#if QT_CONFIG(tooltip)
        quit->setToolTip(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#endif // QT_CONFIG(tooltip)
        quit->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "Send to review ", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Research Information", nullptr));
#if QT_CONFIG(tooltip)
        Browse->setToolTip(QCoreApplication::translate("MainWindow", "Look for files", nullptr));
#endif // QT_CONFIG(tooltip)
        Browse->setText(QCoreApplication::translate("MainWindow", "Browse..", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "No file selected..", nullptr));
#if QT_CONFIG(tooltip)
        plainTextEdit->setToolTip(QCoreApplication::translate("MainWindow", "What is it about", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        plainTextEdit->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        label->setText(QCoreApplication::translate("MainWindow", "Research Title :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Research Description :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Research Documents:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Research Category :", nullptr));
        profile1->setText(QString());
        pushButton_4->setText(QString());
        pushButton_3->setText(QString());
#if QT_CONFIG(tooltip)
        reveiw1->setToolTip(QCoreApplication::translate("MainWindow", "Send to Research Reveiw", nullptr));
#endif // QT_CONFIG(tooltip)
        reveiw1->setText(QString());
#if QT_CONFIG(tooltip)
        homeButton->setToolTip(QCoreApplication::translate("MainWindow", "Home", nullptr));
#endif // QT_CONFIG(tooltip)
        homeButton->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_43->setText(QString());
        pic->setText(QString());
        modeSwitch->setText(QString());
        profile2->setText(QString());

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(1);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "1- hello world", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(2);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "2- hello world", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        pushButton_8->setText(QString());
#if QT_CONFIG(tooltip)
        reveiw2->setToolTip(QCoreApplication::translate("MainWindow", "Send to Research Reveiw", nullptr));
#endif // QT_CONFIG(tooltip)
        reveiw2->setText(QString());
        pushButton_10->setText(QString());
#if QT_CONFIG(tooltip)
        homeButton2->setToolTip(QCoreApplication::translate("MainWindow", "Home", nullptr));
#endif // QT_CONFIG(tooltip)
        homeButton2->setText(QString());
        pic_2->setText(QString());
        pushButton_11->setText(QString());
        pushButton_12->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "Email :", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Password :", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Forgot password?", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        temp->setText(QCoreApplication::translate("MainWindow", "Home page", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ReveiwT), QCoreApplication::translate("MainWindow", "Reveiw status", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Published Researchs", nullptr));
        userPic1->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "Conference Title", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Location", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Price", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "View Map", nullptr));
        editConferenceBtn->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        profile3->setText(QString());
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "View Calendar", nullptr));
        addConferenceBtn->setText(QCoreApplication::translate("MainWindow", "Add Conference", nullptr));
        pushButton_23->setText(QString());
        pushButton_19->setText(QString());
        pushButton_21->setText(QString());
#if QT_CONFIG(tooltip)
        homeButton3->setToolTip(QCoreApplication::translate("MainWindow", "Home", nullptr));
#endif // QT_CONFIG(tooltip)
        homeButton3->setText(QString());
#if QT_CONFIG(tooltip)
        reveiw3->setToolTip(QCoreApplication::translate("MainWindow", "Send to Research Reveiw", nullptr));
#endif // QT_CONFIG(tooltip)
        reveiw3->setText(QString());
        pic_3->setText(QString());
        pushButton_22->setText(QString());
        label_25->setText(QCoreApplication::translate("MainWindow", "Topic", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Location", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Price", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        cancelButton->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
