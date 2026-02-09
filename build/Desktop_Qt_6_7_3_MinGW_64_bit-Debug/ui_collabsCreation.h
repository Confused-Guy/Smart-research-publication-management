/********************************************************************************
** Form generated from reading UI file 'collabsCreation.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLLABSCREATION_H
#define UI_COLLABSCREATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QFrame *collaborationCreationFrame;
    QPlainTextEdit *collaborationCreationCollaborationTitileEdit;
    QTextEdit *collaborationCreationCollaborationDescriptionEdit;
    QLabel *collaborationCreationCollaborationTitleLabel;
    QLabel *collaborationCreationCollaborationDescriptionLabel;
    QComboBox *collaboartionCreationTopicMenu;
    QPushButton *collaborationCreationAddContributorsButton;
    QPushButton *collaborationCreationCancelButton;
    QPushButton *collaborationCreationConfirmButton;
    QLabel *collaborationCreationCollaborationCreationLabel;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(1280, 720);
        collaborationCreationFrame = new QFrame(Form);
        collaborationCreationFrame->setObjectName("collaborationCreationFrame");
        collaborationCreationFrame->setGeometry(QRect(140, 70, 1041, 571));
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
        QFont font;
        font.setPointSize(12);
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
        QFont font1;
        font1.setPointSize(10);
        collaborationCreationAddContributorsButton->setFont(font1);
        collaborationCreationCancelButton = new QPushButton(Form);
        collaborationCreationCancelButton->setObjectName("collaborationCreationCancelButton");
        collaborationCreationCancelButton->setGeometry(QRect(750, 650, 181, 61));
        collaborationCreationCancelButton->setFont(font1);
        collaborationCreationConfirmButton = new QPushButton(Form);
        collaborationCreationConfirmButton->setObjectName("collaborationCreationConfirmButton");
        collaborationCreationConfirmButton->setGeometry(QRect(950, 650, 181, 61));
        collaborationCreationConfirmButton->setFont(font1);
        collaborationCreationCollaborationCreationLabel = new QLabel(Form);
        collaborationCreationCollaborationCreationLabel->setObjectName("collaborationCreationCollaborationCreationLabel");
        collaborationCreationCollaborationCreationLabel->setGeometry(QRect(140, 40, 251, 31));
        collaborationCreationCollaborationCreationLabel->setFont(font);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        collaborationCreationCollaborationTitleLabel->setText(QCoreApplication::translate("Form", "Collaboration Title", nullptr));
        collaborationCreationCollaborationDescriptionLabel->setText(QCoreApplication::translate("Form", "Collaboration Description", nullptr));
        collaborationCreationAddContributorsButton->setText(QCoreApplication::translate("Form", "Add Contributors", nullptr));
        collaborationCreationCancelButton->setText(QCoreApplication::translate("Form", "Cancel", nullptr));
        collaborationCreationConfirmButton->setText(QCoreApplication::translate("Form", "Confirm", nullptr));
        collaborationCreationCollaborationCreationLabel->setText(QCoreApplication::translate("Form", "Collaboration Creation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLLABSCREATION_H
