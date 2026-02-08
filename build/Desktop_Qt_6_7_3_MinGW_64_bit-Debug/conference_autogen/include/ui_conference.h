/********************************************************************************
** Form generated from reading UI file 'conference.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFERENCE_H
#define UI_CONFERENCE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_conference
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *addConferenceBtn;
    QPushButton *pushButton_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_5;
    QPushButton *editConferenceBtn;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QMenu *menuConference_Management;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *conference)
    {
        if (conference->objectName().isEmpty())
            conference->setObjectName("conference");
        conference->resize(1196, 657);
        conference->setStyleSheet(QString::fromUtf8("file:///C:/Users/Mega-pc/Downloads/stylesheet.qss"));
        centralwidget = new QWidget(conference);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        addConferenceBtn = new QPushButton(centralwidget);
        addConferenceBtn->setObjectName("addConferenceBtn");

        horizontalLayout->addWidget(addConferenceBtn);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8("file:///C:/Users/Mega-pc/Downloads/stylesheet.qss"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1176, 562));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName("widget");
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        frame = new QFrame(widget);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("file:///C:/Users/Mega-pc/Downloads/stylesheet.qss"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("file:///C:/Users/Mega-pc/Downloads/stylesheet.qss"));

        verticalLayout_3->addWidget(label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName("pushButton_5");

        horizontalLayout_2->addWidget(pushButton_5);

        editConferenceBtn = new QPushButton(frame);
        editConferenceBtn->setObjectName("editConferenceBtn");

        horizontalLayout_2->addWidget(editConferenceBtn);

        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout_2->addWidget(pushButton_4);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(frame);


        verticalLayout->addWidget(widget);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 3, 0, 1, 1);

        conference->setCentralWidget(centralwidget);
        menubar = new QMenuBar(conference);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1196, 21));
        menuConference_Management = new QMenu(menubar);
        menuConference_Management->setObjectName("menuConference_Management");
        conference->setMenuBar(menubar);
        statusbar = new QStatusBar(conference);
        statusbar->setObjectName("statusbar");
        conference->setStatusBar(statusbar);

        menubar->addAction(menuConference_Management->menuAction());

        retranslateUi(conference);

        QMetaObject::connectSlotsByName(conference);
    } // setupUi

    void retranslateUi(QMainWindow *conference)
    {
        conference->setWindowTitle(QCoreApplication::translate("conference", "conference", nullptr));
        addConferenceBtn->setText(QCoreApplication::translate("conference", "Add Conference", nullptr));
        pushButton_2->setText(QCoreApplication::translate("conference", "View Calendar", nullptr));
        label->setText(QCoreApplication::translate("conference", "Conference Title", nullptr));
        label_3->setText(QCoreApplication::translate("conference", "Date", nullptr));
        label_4->setText(QCoreApplication::translate("conference", "Location", nullptr));
        label_2->setText(QCoreApplication::translate("conference", "Price", nullptr));
        pushButton_5->setText(QCoreApplication::translate("conference", "View Map", nullptr));
        editConferenceBtn->setText(QCoreApplication::translate("conference", "Edit", nullptr));
        pushButton_4->setText(QCoreApplication::translate("conference", "Delete", nullptr));
        menuConference_Management->setTitle(QCoreApplication::translate("conference", "Conference Management   ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class conference: public Ui_conference {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFERENCE_H
