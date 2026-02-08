/********************************************************************************
** Form generated from reading UI file 'addconferencedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCONFERENCEDIALOG_H
#define UI_ADDCONFERENCEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_addconferencedialog
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *topicCombo;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QLabel *label_3;
    QLineEdit *locationEdit;
    QLabel *label_4;
    QDoubleSpinBox *priceSpin;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *addconferencedialog)
    {
        if (addconferencedialog->objectName().isEmpty())
            addconferencedialog->setObjectName("addconferencedialog");
        addconferencedialog->resize(724, 555);
        gridLayout = new QGridLayout(addconferencedialog);
        gridLayout->setObjectName("gridLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(10, 10, 10, -1);
        label = new QLabel(addconferencedialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        topicCombo = new QComboBox(addconferencedialog);
        topicCombo->setObjectName("topicCombo");

        formLayout->setWidget(0, QFormLayout::FieldRole, topicCombo);

        label_2 = new QLabel(addconferencedialog);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        dateEdit = new QDateEdit(addconferencedialog);
        dateEdit->setObjectName("dateEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, dateEdit);

        label_3 = new QLabel(addconferencedialog);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        locationEdit = new QLineEdit(addconferencedialog);
        locationEdit->setObjectName("locationEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, locationEdit);

        label_4 = new QLabel(addconferencedialog);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        priceSpin = new QDoubleSpinBox(addconferencedialog);
        priceSpin->setObjectName("priceSpin");

        formLayout->setWidget(3, QFormLayout::FieldRole, priceSpin);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        saveButton = new QPushButton(addconferencedialog);
        saveButton->setObjectName("saveButton");

        horizontalLayout->addWidget(saveButton);

        cancelButton = new QPushButton(addconferencedialog);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(addconferencedialog);

        QMetaObject::connectSlotsByName(addconferencedialog);
    } // setupUi

    void retranslateUi(QDialog *addconferencedialog)
    {
        addconferencedialog->setWindowTitle(QCoreApplication::translate("addconferencedialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("addconferencedialog", "Topic", nullptr));
        label_2->setText(QCoreApplication::translate("addconferencedialog", "Date", nullptr));
        label_3->setText(QCoreApplication::translate("addconferencedialog", "Location", nullptr));
        label_4->setText(QCoreApplication::translate("addconferencedialog", "Price", nullptr));
        saveButton->setText(QCoreApplication::translate("addconferencedialog", "Save", nullptr));
        cancelButton->setText(QCoreApplication::translate("addconferencedialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addconferencedialog: public Ui_addconferencedialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCONFERENCEDIALOG_H
