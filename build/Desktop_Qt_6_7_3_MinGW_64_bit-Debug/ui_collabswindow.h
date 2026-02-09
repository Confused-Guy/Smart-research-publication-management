/********************************************************************************
** Form generated from reading UI file 'collabswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLLABSWINDOW_H
#define UI_COLLABSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_collabsWindow
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget;
    QTextBrowser *textBrowser;
    QPushButton *button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *collabsWindow)
    {
        if (collabsWindow->objectName().isEmpty())
            collabsWindow->setObjectName("collabsWindow");
        collabsWindow->resize(1280, 720);
        centralwidget = new QWidget(collabsWindow);
        centralwidget->setObjectName("centralwidget");
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(160, 50, 391, 581));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(590, 50, 591, 581));
        QFont font;
        font.setPointSize(20);
        textBrowser->setFont(font);
        button = new QPushButton(centralwidget);
        button->setObjectName("button");
        button->setGeometry(QRect(1010, 630, 90, 29));
        collabsWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(collabsWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 25));
        collabsWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(collabsWindow);
        statusbar->setObjectName("statusbar");
        collabsWindow->setStatusBar(statusbar);

        retranslateUi(collabsWindow);

        QMetaObject::connectSlotsByName(collabsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *collabsWindow)
    {
        collabsWindow->setWindowTitle(QCoreApplication::translate("collabsWindow", "collabsWindow", nullptr));
        button->setText(QCoreApplication::translate("collabsWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class collabsWindow: public Ui_collabsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLLABSWINDOW_H
