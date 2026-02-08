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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
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
    QPushButton *pushButton_7;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *homeButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QFrame *line;
    QWidget *page_2;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *homeButton_2;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QFrame *line_2;
    QPushButton *pushButton_13;
    QListWidget *listWidget;
    QWidget *page_3;
    QLabel *label_6;
    QTextEdit *textEdit;
    QTextEdit *textEdit_3;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QMenuBar *menubar;
    QStatusBar *statusbar;

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
        stackedWidget->setGeometry(QRect(0, 0, 1201, 741));
        page = new QWidget();
        page->setObjectName("page");
        quit = new QPushButton(page);
        quit->setObjectName("quit");
        quit->setGeometry(QRect(780, 580, 81, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8("icons/log-out.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        quit->setIcon(icon);
        quit->setIconSize(QSize(25, 25));
        pushButton = new QPushButton(page);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(470, 580, 141, 41));
        QPalette palette1;
        QBrush brush2(QColor(30, 64, 175, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QBrush brush3(QColor(226, 239, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush3);
        QBrush brush4(QColor(31, 155, 93, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush4);
        QBrush brush5(QColor(30, 64, 175, 128));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        pushButton->setPalette(palette1);
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSend));
        pushButton->setIcon(icon1);
        groupBox = new QGroupBox(page);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(330, 40, 721, 511));
        QPalette palette2;
        QBrush brush6(QColor(31, 41, 55, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QBrush brush7(QColor(145, 65, 172, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QBrush brush8(QColor(61, 61, 61, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush8);
        QBrush brush9(QColor(31, 41, 55, 128));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        groupBox->setPalette(palette2);
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
        Browse->setGeometry(QRect(440, 420, 112, 31));
        QPalette palette3;
        QBrush brush10(QColor(255, 255, 255, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush10);
        QBrush brush11(QColor(0, 120, 212, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush10);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush10);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush11);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette3.setBrush(QPalette::Active, QPalette::Highlight, brush4);
        QBrush brush12(QColor(255, 255, 255, 128));
        brush12.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush12);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::Highlight, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
#endif
        QBrush brush13(QColor(102, 102, 102, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush13);
        QBrush brush14(QColor(204, 204, 204, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush13);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush13);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::Highlight, brush4);
        QBrush brush15(QColor(102, 102, 102, 128));
        brush15.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush15);
#endif
        Browse->setPalette(palette3);
        Browse->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Browse->setStyleSheet(QString::fromUtf8("/* Modern Qt Stylesheet */\n"
"\n"
"/* Global Settings */\n"
"* {\n"
"    font-family: \"Segoe UI\", Arial, sans-serif;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"/* Main Window */\n"
"QMainWindow {\n"
"    background-color: #f5f5f5;\n"
"}\n"
"\n"
"/* Buttons */\n"
"QPushButton {\n"
"    background-color: #0078d4;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 8px 16px;\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #106ebe;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005a9e;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #cccccc;\n"
"    color: #666666;\n"
"}\n"
"\n"
"/* Text Input Fields */\n"
"QLineEdit, QTextEdit, QPlainTextEdit {\n"
"    background-color: white;\n"
"    border: 1px solid #d0d0d0;\n"
"    border-radius: 3px;\n"
"    padding: 6px;\n"
"    selection-background-color: #0078d4;\n"
"}\n"
"\n"
"QLineEdit:focus, QTextEdit:focus, QPlainTextEdit:focus {\n"
"    border: 2px solid #0078d"
                        "4;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* ComboBox */\n"
"QComboBox {\n"
"    background-color: white;\n"
"    border: 1px solid #d0d0d0;\n"
"    border-radius: 3px;\n"
"    padding: 6px;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1px solid #0078d4;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 20px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(down_arrow.png); /* You'll need to provide this icon */\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: white;\n"
"    border: 1px solid #d0d0d0;\n"
"    selection-background-color: #0078d4;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"/* Checkboxes */\n"
"QCheckBox {\n"
"    spacing: 8px;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"    border: 2px solid #0078d4;\n"
"    border-radius: 3px;\n"
"    background-color: white;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-co"
                        "lor: #0078d4;\n"
"    image: url(check.png); /* You'll need to provide this icon */\n"
"}\n"
"\n"
"QCheckBox::indicator:hover {\n"
"    border: 2px solid #106ebe;\n"
"}\n"
"\n"
"/* Radio Buttons */\n"
"QRadioButton {\n"
"    spacing: 8px;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"    border: 2px solid #0078d4;\n"
"    border-radius: 9px;\n"
"    background-color: white;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: white;\n"
"    border: 5px solid #0078d4;\n"
"}\n"
"\n"
"/* Sliders */\n"
"QSlider::groove:horizontal {\n"
"    height: 6px;\n"
"    background: #d0d0d0;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #0078d4;\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    margin: -5px 0;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"    background: #106ebe;\n"
"}\n"
"\n"
"/* Progress Bar */\n"
"QProgressBar {\n"
"    border: 1px solid #d0d0d0;\n"
"    border"
                        "-radius: 3px;\n"
"    text-align: center;\n"
"    background-color: white;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #0078d4;\n"
"    border-radius: 2px;\n"
"}\n"
"\n"
"/* Tabs */\n"
"QTabWidget::pane {\n"
"    border: 1px solid #d0d0d0;\n"
"    background-color: white;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: #e0e0e0;\n"
"    border: 1px solid #d0d0d0;\n"
"    padding: 8px 16px;\n"
"    margin-right: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: white;\n"
"    border-bottom-color: white;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background-color: #f0f0f0;\n"
"}\n"
"\n"
"/* Scrollbars */\n"
"QScrollBar:vertical {\n"
"    background: #f5f5f5;\n"
"    width: 12px;\n"
"    margin: 0;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #c0c0c0;\n"
"    min-height: 20px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #a0a0a0;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    background: #f5f5f"
                        "5;\n"
"    height: 12px;\n"
"    margin: 0;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #c0c0c0;\n"
"    min-width: 20px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:hover {\n"
"    background: #a0a0a0;\n"
"}\n"
"\n"
"QScrollBar::add-line, QScrollBar::sub-line {\n"
"    background: none;\n"
"    border: none;\n"
"}\n"
"\n"
"/* Menu Bar */\n"
"QMenuBar {\n"
"    background-color: white;\n"
"    border-bottom: 1px solid #d0d0d0;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"    padding: 6px 12px;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: #e5f3ff;\n"
"}\n"
"\n"
"QMenu {\n"
"    background-color: white;\n"
"    border: 1px solid #d0d0d0;\n"
"}\n"
"\n"
"QMenu::item {\n"
"    padding: 6px 24px 6px 12px;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    background-color: #e5f3ff;\n"
"}\n"
"\n"
"/* Tooltips */\n"
"QToolTip {\n"
"    background-color: #333333;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
""
                        "    padding: 4px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"/* Tables */\n"
"QTableView {\n"
"    background-color: white;\n"
"    border: 1px solid #d0d0d0;\n"
"    gridline-color: #e0e0e0;\n"
"    selection-background-color: #0078d4;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #f0f0f0;\n"
"    padding: 6px;\n"
"    border: none;\n"
"    border-right: 1px solid #d0d0d0;\n"
"    border-bottom: 1px solid #d0d0d0;\n"
"}\n"
"\n"
"/* Status Bar */\n"
"QStatusBar {\n"
"    background-color: #f0f0f0;\n"
"    border-top: 1px solid #d0d0d0;\n"
"}"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(310, 430, 131, 19));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QBrush brush16(QColor(0, 0, 0, 0));
        brush16.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush16);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush16);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush16);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush16);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush16);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush16);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush16);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush16);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush16);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        label_4->setPalette(palette4);
        textEdit_2 = new QTextEdit(groupBox);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(290, 160, 321, 131));
        textEdit_2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::IBeamCursor)));
        textEdit_2->setFrameShape(QFrame::Shape::NoFrame);
        textEdit_2->setLineWidth(9);
        plainTextEdit = new QPlainTextEdit(groupBox);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(290, 60, 321, 51));
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
        plainTextEdit_2->setGeometry(QRect(290, 330, 321, 51));
        pushButton_7 = new QPushButton(page);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(20, 630, 41, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("icons/user.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_7->setIcon(icon2);
        pushButton_4 = new QPushButton(page);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(20, 280, 41, 41));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("icons/calendar.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_4->setIcon(icon3);
        pushButton_3 = new QPushButton(page);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 210, 41, 41));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("icons/pie-chart.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_3->setIcon(icon4);
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 130, 41, 41));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("icons/plus-square.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_2->setIcon(icon5);
        homeButton = new QPushButton(page);
        homeButton->setObjectName("homeButton");
        homeButton->setEnabled(true);
        homeButton->setGeometry(QRect(20, 20, 40, 40));
        homeButton->setMinimumSize(QSize(40, 40));
        homeButton->setMaximumSize(QSize(40, 40));
        homeButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        homeButton->setMouseTracking(true);
        homeButton->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        homeButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        homeButton->setAutoFillBackground(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("icons/menu.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        homeButton->setIcon(icon6);
        homeButton->setIconSize(QSize(22, 22));
        homeButton->setFlat(true);
        pushButton_5 = new QPushButton(page);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(20, 360, 41, 41));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("icons/hard-drive.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_5->setIcon(icon7);
        pushButton_6 = new QPushButton(page);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(20, 440, 41, 41));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("icons/zap.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_6->setIcon(icon8);
        line = new QFrame(page);
        line->setObjectName("line");
        line->setGeometry(QRect(80, -30, 20, 841));
        QPalette palette5;
        line->setPalette(palette5);
        line->setCursor(QCursor(Qt::CursorShape::ForbiddenCursor));
        line->setAutoFillBackground(false);
        line->setFrameShadow(QFrame::Shadow::Plain);
        line->setLineWidth(3);
        line->setFrameShape(QFrame::Shape::VLine);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        pushButton_8 = new QPushButton(page_2);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(20, 280, 41, 41));
        pushButton_8->setIcon(icon3);
        pushButton_9 = new QPushButton(page_2);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(20, 210, 41, 41));
        pushButton_9->setIcon(icon4);
        pushButton_10 = new QPushButton(page_2);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(20, 130, 41, 41));
        pushButton_10->setIcon(icon5);
        homeButton_2 = new QPushButton(page_2);
        homeButton_2->setObjectName("homeButton_2");
        homeButton_2->setEnabled(true);
        homeButton_2->setGeometry(QRect(20, 20, 40, 40));
        homeButton_2->setMinimumSize(QSize(40, 40));
        homeButton_2->setMaximumSize(QSize(40, 40));
        homeButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        homeButton_2->setMouseTracking(true);
        homeButton_2->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        homeButton_2->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        homeButton_2->setAutoFillBackground(false);
        homeButton_2->setIcon(icon6);
        homeButton_2->setIconSize(QSize(22, 22));
        homeButton_2->setFlat(true);
        pushButton_11 = new QPushButton(page_2);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(20, 360, 41, 41));
        pushButton_11->setIcon(icon7);
        pushButton_12 = new QPushButton(page_2);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(20, 440, 41, 41));
        pushButton_12->setIcon(icon8);
        line_2 = new QFrame(page_2);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(80, -20, 20, 841));
        QPalette palette6;
        line_2->setPalette(palette6);
        line_2->setCursor(QCursor(Qt::CursorShape::ForbiddenCursor));
        line_2->setAutoFillBackground(false);
        line_2->setFrameShadow(QFrame::Shadow::Plain);
        line_2->setLineWidth(3);
        line_2->setFrameShape(QFrame::Shape::VLine);
        pushButton_13 = new QPushButton(page_2);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(20, 630, 41, 41));
        pushButton_13->setIcon(icon2);
        listWidget = new QListWidget(page_2);
        QBrush brush17(QColor(0, 0, 0, 255));
        brush17.setStyle(Qt::SolidPattern);
        QBrush brush18(QColor(0, 0, 0, 255));
        brush18.setStyle(Qt::NoBrush);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setBackground(brush18);
        __qlistwidgetitem->setForeground(brush17);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(100, 160, 231, 411));
        listWidget->setFrameShape(QFrame::Shape::WinPanel);
        listWidget->setLineWidth(3);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        label_6 = new QLabel(page_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(390, 340, 70, 19));
        textEdit = new QTextEdit(page_3);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(480, 330, 291, 41));
        textEdit_3 = new QTextEdit(page_3);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(480, 390, 291, 41));
        label_7 = new QLabel(page_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(390, 400, 91, 19));
        label_8 = new QLabel(page_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(480, 430, 141, 31));
        label_8->setFrameShape(QFrame::Shape::VLine);
        label_8->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_14 = new QPushButton(page_3);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(430, 520, 121, 41));
        pushButton_15 = new QPushButton(page_3);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(630, 520, 121, 41));
        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1298, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        quit->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "Send to review ", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Research Information", nullptr));
#if QT_CONFIG(tooltip)
        Browse->setToolTip(QCoreApplication::translate("MainWindow", "Look for files", nullptr));
#endif // QT_CONFIG(tooltip)
        Browse->setText(QCoreApplication::translate("MainWindow", "Browse..", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "No file selected..", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Research Title :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Research Description :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Research Documents:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Research Category :", nullptr));
        pushButton_7->setText(QString());
        pushButton_4->setText(QString());
        pushButton_3->setText(QString());
        pushButton_2->setText(QString());
#if QT_CONFIG(tooltip)
        homeButton->setToolTip(QCoreApplication::translate("MainWindow", "Home", nullptr));
#endif // QT_CONFIG(tooltip)
        homeButton->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_8->setText(QString());
        pushButton_9->setText(QString());
        pushButton_10->setText(QString());
#if QT_CONFIG(tooltip)
        homeButton_2->setToolTip(QCoreApplication::translate("MainWindow", "Home", nullptr));
#endif // QT_CONFIG(tooltip)
        homeButton_2->setText(QString());
        pushButton_11->setText(QString());
        pushButton_12->setText(QString());
        pushButton_13->setText(QString());

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(1);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "1- hello world", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(2);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "2- hello world", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        label_6->setText(QCoreApplication::translate("MainWindow", "Email :", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Password :", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Forgot password?", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
