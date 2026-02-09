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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_collabsWindow
{
public:
    QWidget *centralwidget;
    QLabel *collaborationCreationCollaborationCreationLabel;
    QPushButton *collaborationCreationConfirmButton;
    QFrame *collaborationCreationFrame;
    QPlainTextEdit *collaborationCreationCollaborationTitileEdit;
    QTextEdit *collaborationCreationCollaborationDescriptionEdit;
    QLabel *collaborationCreationCollaborationTitleLabel;
    QLabel *collaborationCreationCollaborationDescriptionLabel;
    QComboBox *collaboartionCreationTopicMenu;
    QPushButton *collaborationCreationAddContributorsButton;
    QPushButton *collaborationCreationCancelButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *collabsWindow)
    {
        if (collabsWindow->objectName().isEmpty())
            collabsWindow->setObjectName("collabsWindow");
        collabsWindow->resize(1280, 720);
        centralwidget = new QWidget(collabsWindow);
        centralwidget->setObjectName("centralwidget");
        collaborationCreationCollaborationCreationLabel = new QLabel(centralwidget);
        collaborationCreationCollaborationCreationLabel->setObjectName("collaborationCreationCollaborationCreationLabel");
        collaborationCreationCollaborationCreationLabel->setGeometry(QRect(110, 0, 251, 31));
        QFont font;
        font.setPointSize(12);
        collaborationCreationCollaborationCreationLabel->setFont(font);
        collaborationCreationConfirmButton = new QPushButton(centralwidget);
        collaborationCreationConfirmButton->setObjectName("collaborationCreationConfirmButton");
        collaborationCreationConfirmButton->setGeometry(QRect(920, 610, 181, 61));
        QFont font1;
        font1.setPointSize(10);
        collaborationCreationConfirmButton->setFont(font1);
        collaborationCreationFrame = new QFrame(centralwidget);
        collaborationCreationFrame->setObjectName("collaborationCreationFrame");
        collaborationCreationFrame->setGeometry(QRect(110, 30, 1041, 571));
        collaborationCreationFrame->setFrameShape(QFrame::Shape::StyledPanel);
        collaborationCreationFrame->setFrameShadow(QFrame::Shadow::Raised);
        collaborationCreationCollaborationTitileEdit = new QPlainTextEdit(collaborationCreationFrame);
        collaborationCreationCollaborationTitileEdit->setObjectName("collaborationCreationCollaborationTitileEdit");
        collaborationCreationCollaborationTitileEdit->setGeometry(QRect(70, 60, 891, 61));
        collaborationCreationCollaborationDescriptionEdit = new QTextEdit(collaborationCreationFrame);
        collaborationCreationCollaborationDescriptionEdit->setObjectName("collaborationCreationCollaborationDescriptionEdit");
        collaborationCreationCollaborationDescriptionEdit->setGeometry(QRect(70, 180, 891, 211));
        collaborationCreationCollaborationTitleLabel = new QLabel(collaborationCreationFrame);
        collaborationCreationCollaborationTitleLabel->setObjectName("collaborationCreationCollaborationTitleLabel");
        collaborationCreationCollaborationTitleLabel->setGeometry(QRect(80, 30, 251, 31));
        collaborationCreationCollaborationTitleLabel->setFont(font);
        collaborationCreationCollaborationDescriptionLabel = new QLabel(collaborationCreationFrame);
        collaborationCreationCollaborationDescriptionLabel->setObjectName("collaborationCreationCollaborationDescriptionLabel");
        collaborationCreationCollaborationDescriptionLabel->setGeometry(QRect(70, 140, 251, 31));
        collaborationCreationCollaborationDescriptionLabel->setFont(font);
        collaboartionCreationTopicMenu = new QComboBox(collaborationCreationFrame);
        collaboartionCreationTopicMenu->setObjectName("collaboartionCreationTopicMenu");
        collaboartionCreationTopicMenu->setGeometry(QRect(190, 430, 311, 51));
        collaborationCreationAddContributorsButton = new QPushButton(collaborationCreationFrame);
        collaborationCreationAddContributorsButton->setObjectName("collaborationCreationAddContributorsButton");
        collaborationCreationAddContributorsButton->setGeometry(QRect(540, 430, 351, 51));
        collaborationCreationAddContributorsButton->setFont(font1);
        collaborationCreationCancelButton = new QPushButton(centralwidget);
        collaborationCreationCancelButton->setObjectName("collaborationCreationCancelButton");
        collaborationCreationCancelButton->setGeometry(QRect(720, 610, 181, 61));
        collaborationCreationCancelButton->setFont(font1);
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
        collaborationCreationCollaborationCreationLabel->setText(QCoreApplication::translate("collabsWindow", "Collaboration Creation", nullptr));
        collaborationCreationConfirmButton->setText(QCoreApplication::translate("collabsWindow", "Confirm", nullptr));
        collaborationCreationCollaborationTitleLabel->setText(QCoreApplication::translate("collabsWindow", "Collaboration Title", nullptr));
        collaborationCreationCollaborationDescriptionLabel->setText(QCoreApplication::translate("collabsWindow", "Collaboration Description", nullptr));
        collaborationCreationAddContributorsButton->setText(QCoreApplication::translate("collabsWindow", "Add Contributors", nullptr));
        collaborationCreationCancelButton->setText(QCoreApplication::translate("collabsWindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class collabsWindow: public Ui_collabsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLLABSWINDOW_H
