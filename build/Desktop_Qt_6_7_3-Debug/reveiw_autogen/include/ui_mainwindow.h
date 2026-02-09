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
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *quitb;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *Browse;
    QLabel *label_4;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_6;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_10;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1492, 705);
        QPalette palette;
        QBrush brush(QColor(215, 218, 220, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(3, 3, 3, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(215, 218, 220, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        MainWindow->setPalette(palette);
        MainWindow->setStyleSheet(QString::fromUtf8("/* Reddit-Inspired Qt Stylesheet */\n"
"\n"
"/* Global Settings */\n"
"* {\n"
"    font-family: -apple-system, BlinkMacSystemFont, \"Segoe UI\", Roboto, \"Helvetica Neue\", Arial, sans-serif;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"/* Main Window */\n"
"QMainWindow {\n"
"    background-color: #030303;\n"
"}\n"
"\n"
"/* General Widget Background */\n"
"QWidget {\n"
"    background-color: #030303;\n"
"    color: #d7dadc;\n"
"}\n"
"\n"
"/* Buttons */\n"
"QPushButton {\n"
"    background-color: #0079d3;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 20px;\n"
"    padding: 8px 20px;\n"
"    font-weight: bold;\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1484d6;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #0060a8;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #272729;\n"
"    color: #6c757d;\n"
"}\n"
"\n"
"/* Secondary Button Style */\n"
"QPushButton[class=\"secondary\"] {\n"
"    background-color: transparent;\n"
"   "
                        " border: 1px solid #343536;\n"
"    color: #d7dadc;\n"
"}\n"
"\n"
"QPushButton[class=\"secondary\"]:hover {\n"
"    background-color: #1a1a1b;\n"
"}\n"
"\n"
"/* Upvote/Accent Button */\n"
"QPushButton[class=\"accent\"] {\n"
"    background-color: #ff4500;\n"
"}\n"
"\n"
"QPushButton[class=\"accent\"]:hover {\n"
"    background-color: #ff5722;\n"
"}\n"
"\n"
"/* Text Input Fields */\n"
"QLineEdit, QTextEdit, QPlainTextEdit {\n"
"    background-color: #1a1a1b;\n"
"    border: 1px solid #343536;\n"
"    border-radius: 4px;\n"
"    padding: 8px 12px;\n"
"    color: #d7dadc;\n"
"    selection-background-color: #0079d3;\n"
"}\n"
"\n"
"QLineEdit:focus, QTextEdit:focus, QPlainTextEdit:focus {\n"
"    border: 1px solid #d7dadc;\n"
"}\n"
"\n"
"QLineEdit:hover, QTextEdit:hover, QPlainTextEdit:hover {\n"
"    background-color: #272729;\n"
"}\n"
"\n"
"/* ComboBox */\n"
"QComboBox {\n"
"    background-color: #1a1a1b;\n"
"    border: 1px solid #343536;\n"
"    border-radius: 4px;\n"
"    padding: 8px 12px;\n"
"    color: #d7da"
                        "dc;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    background-color: #272729;\n"
"    border: 1px solid #d7dadc;\n"
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
"    border-top: 5px solid #d7dadc;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #1a1a1b;\n"
"    border: 1px solid #343536;\n"
"    selection-background-color: #0079d3;\n"
"    selection-color: white;\n"
"    outline: none;\n"
"}\n"
"\n"
"/* Checkboxes */\n"
"QCheckBox {\n"
"    spacing: 8px;\n"
"    color: #d7dadc;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"    border: 2px solid #818384;\n"
"    border-radius: 3px;\n"
"    background-color: #1a1a1b;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #0079d3;\n"
"    border-color: #0079d3;\n"
"}\n"
""
                        "\n"
"QCheckBox::indicator:hover {\n"
"    border-color: #d7dadc;\n"
"}\n"
"\n"
"/* Radio Buttons */\n"
"QRadioButton {\n"
"    spacing: 8px;\n"
"    color: #d7dadc;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"    border: 2px solid #818384;\n"
"    border-radius: 10px;\n"
"    background-color: #1a1a1b;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #1a1a1b;\n"
"    border: 6px solid #0079d3;\n"
"}\n"
"\n"
"QRadioButton::indicator:hover {\n"
"    border-color: #d7dadc;\n"
"}\n"
"\n"
"/* Sliders */\n"
"QSlider::groove:horizontal {\n"
"    height: 4px;\n"
"    background: #343536;\n"
"    border-radius: 2px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #ff4500;\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    margin: -6px 0;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"    background: #ff5722;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: #ff4500;\n"
"    border-rad"
                        "ius: 2px;\n"
"}\n"
"\n"
"/* Progress Bar */\n"
"QProgressBar {\n"
"    border: none;\n"
"    border-radius: 2px;\n"
"    text-align: center;\n"
"    background-color: #1a1a1b;\n"
"    color: #d7dadc;\n"
"    height: 8px;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #ff4500;\n"
"    border-radius: 2px;\n"
"}\n"
"\n"
"/* Tabs */\n"
"QTabWidget::pane {\n"
"    border: 1px solid #343536;\n"
"    background-color: #1a1a1b;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: #1a1a1b;\n"
"    color: #818384;\n"
"    border: none;\n"
"    border-bottom: 3px solid transparent;\n"
"    padding: 12px 20px;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    color: #d7dadc;\n"
"    border-bottom: 3px solid #0079d3;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    color: #d7dadc;\n"
"    background-color: #272729;\n"
"}\n"
"\n"
"/* Scrollbars */\n"
"QScrollBar:vertical {\n"
"    background: #030303;\n"
"    width: 8px;\n"
"    margin: 0;\n"
"    border-radiu"
                        "s: 4px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #343536;\n"
"    min-height: 30px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #4f5051;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    background: #030303;\n"
"    height: 8px;\n"
"    margin: 0;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #343536;\n"
"    min-width: 30px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:hover {\n"
"    background: #4f5051;\n"
"}\n"
"\n"
"QScrollBar::add-line, QScrollBar::sub-line {\n"
"    background: none;\n"
"    border: none;\n"
"}\n"
"\n"
"QScrollBar::add-page, QScrollBar::sub-page {\n"
"    background: none;\n"
"}\n"
"\n"
"/* Menu Bar */\n"
"QMenuBar {\n"
"    background-color: #1a1a1b;\n"
"    border-bottom: 1px solid #343536;\n"
"    color: #d7dadc;\n"
"    padding: 4px;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"    padding: 8px 16px;\n"
"    background-color: transparent;\n"
""
                        "    border-radius: 4px;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: #272729;\n"
"}\n"
"\n"
"QMenu {\n"
"    background-color: #1a1a1b;\n"
"    border: 1px solid #343536;\n"
"    color: #d7dadc;\n"
"    padding: 4px;\n"
"}\n"
"\n"
"QMenu::item {\n"
"    padding: 8px 24px 8px 12px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    background-color: #0079d3;\n"
"    color: white;\n"
"}\n"
"\n"
"QMenu::separator {\n"
"    height: 1px;\n"
"    background: #343536;\n"
"    margin: 4px 0;\n"
"}\n"
"\n"
"/* Tooltips */\n"
"QToolTip {\n"
"    background-color: #1a1a1b;\n"
"    color: #d7dadc;\n"
"    border: 1px solid #343536;\n"
"    padding: 6px 8px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"/* Tables / List Views */\n"
"QTableView, QListView, QTreeView {\n"
"    background-color: #1a1a1b;\n"
"    border: 1px solid #343536;\n"
"    border-radius: 4px;\n"
"    gridline-color: #343536;\n"
"    selection-background-color: #0079d3;\n"
"    selection-color: white;\n"
"    co"
                        "lor: #d7dadc;\n"
"    outline: none;\n"
"}\n"
"\n"
"QTableView::item:hover, QListView::item:hover, QTreeView::item:hover {\n"
"    background-color: #272729;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #030303;\n"
"    padding: 8px;\n"
"    border: none;\n"
"    border-right: 1px solid #343536;\n"
"    border-bottom: 1px solid #343536;\n"
"    color: #818384;\n"
"    font-weight: bold;\n"
"    text-transform: uppercase;\n"
"    font-size: 9pt;\n"
"}\n"
"\n"
"/* Status Bar */\n"
"QStatusBar {\n"
"    background-color: #1a1a1b;\n"
"    border-top: 1px solid #343536;\n"
"    color: #818384;\n"
"}\n"
"\n"
"/* Group Box */\n"
"QGroupBox {\n"
"    border: 1px solid #343536;\n"
"    border-radius: 4px;\n"
"    margin-top: 12px;\n"
"    padding-top: 12px;\n"
"    color: #d7dadc;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 0 8px;\n"
"    color: #818384;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Splitter */\n"
"QSplit"
                        "ter::handle {\n"
"    background-color: #343536;\n"
"}\n"
"\n"
"QSplitter::handle:hover {\n"
"    background-color: #4f5051;\n"
"}\n"
"\n"
"QSplitter::handle:horizontal {\n"
"    width: 2px;\n"
"}\n"
"\n"
"QSplitter::handle:vertical {\n"
"    height: 2px;\n"
"}\n"
"\n"
"/* Dock Widget */\n"
"QDockWidget {\n"
"    color: #d7dadc;\n"
"    titlebar-close-icon: url(close.png);\n"
"    titlebar-normal-icon: url(float.png);\n"
"}\n"
"\n"
"QDockWidget::title {\n"
"    background-color: #1a1a1b;\n"
"    border: 1px solid #343536;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"/* Labels */\n"
"QLabel {\n"
"    color: #d7dadc;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QLabel[class=\"title\"] {\n"
"    font-size: 14pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QLabel[class=\"subtitle\"] {\n"
"    color: #818384;\n"
"    font-size: 9pt;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(220, 480, 121, 41));
        QPalette palette1;
        QBrush brush3(QColor(255, 255, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        QBrush brush4(QColor(0, 121, 211, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush4);
        QBrush brush5(QColor(31, 155, 93, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush5);
        QBrush brush6(QColor(255, 255, 255, 128));
        brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        QBrush brush7(QColor(108, 117, 125, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        QBrush brush8(QColor(39, 39, 41, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush5);
        QBrush brush9(QColor(108, 117, 125, 128));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        pushButton->setPalette(palette1);
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        quitb = new QPushButton(centralwidget);
        quitb->setObjectName("quitb");
        quitb->setGeometry(QRect(450, 480, 120, 41));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Highlight, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Highlight, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Highlight, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        quitb->setPalette(palette2);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(60, 60, 701, 391));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        groupBox->setPalette(palette3);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 50, 153, 281));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        Browse = new QPushButton(groupBox);
        Browse->setObjectName("Browse");
        Browse->setGeometry(QRect(450, 270, 112, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        QBrush brush10(QColor(0, 120, 212, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush10);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush10);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        QBrush brush11(QColor(102, 102, 102, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        QBrush brush12(QColor(204, 204, 204, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        QBrush brush13(QColor(102, 102, 102, 128));
        brush13.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush13);
#endif
        Browse->setPalette(palette4);
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
        label_4->setGeometry(QRect(290, 280, 131, 19));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush14(QColor(0, 0, 0, 0));
        brush14.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush14);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush14);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush14);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush14);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush14);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush14);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush14);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush14);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush14);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        label_4->setPalette(palette5);
        textEdit_2 = new QTextEdit(groupBox);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(290, 160, 301, 70));
        textEdit_2->setFrameShape(QFrame::Shape::HLine);
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(290, 80, 301, 31));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(940, 170, 340, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 0, 4, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 0, 2, 1, 1);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(940, 300, 371, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(horizontalLayoutWidget);
        label_8->setObjectName("label_8");

        horizontalLayout->addWidget(label_8);

        horizontalSpacer = new QSpacerItem(200, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_9 = new QLabel(horizontalLayoutWidget);
        label_9->setObjectName("label_9");

        horizontalLayout->addWidget(label_9);

        horizontalSpacer_5 = new QSpacerItem(200, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label_10 = new QLabel(horizontalLayoutWidget);
        label_10->setObjectName("label_10");

        horizontalLayout->addWidget(label_10);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1492, 42));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Send to review ", nullptr));
        quitb->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Research Information", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Reveiw Title", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Review Describtion", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Research Documents", nullptr));
        Browse->setText(QCoreApplication::translate("MainWindow", "Browse..", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "No file selected..", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Included Docs", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Title", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Example", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Example Description", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Example files", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
