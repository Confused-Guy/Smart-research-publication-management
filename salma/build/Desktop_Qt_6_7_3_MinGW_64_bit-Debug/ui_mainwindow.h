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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_main;
    QWidget *sidebar;
    QVBoxLayout *verticalLayout_sidebar;
    QPushButton *menuButton;
    QPushButton *homeButton;
    QPushButton *clockButton;
    QPushButton *fileButton;
    QPushButton *printButton;
    QSpacerItem *verticalSpacer;
    QPushButton *userButton;
    QWidget *mainContent;
    QVBoxLayout *verticalLayout_main;
    QGroupBox *publicationInfoGroup;
    QFormLayout *formLayout;
    QLabel *titleLabel;
    QLineEdit *titleEdit;
    QLabel *descriptionLabel;
    QTextEdit *descriptionEdit;
    QLabel *categoryLabel;
    QComboBox *categoryCombo;
    QHBoxLayout *horizontalLayout_buttons;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QSpacerItem *horizontalSpacer;
    QGroupBox *publicationListGroup;
    QVBoxLayout *verticalLayout_list;
    QListWidget *publicationList;
    QGroupBox *innovativeFeaturesGroup;
    QHBoxLayout *horizontalLayout_features;
    QPushButton *summaryButton;
    QPushButton *emailButton;
    QLabel *statusLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 700);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"    QMainWindow {\n"
"        background-color: #f5f5f5;\n"
"    }\n"
"\n"
"    QGroupBox {\n"
"        background-color: white;\n"
"        border: 1px solid #e0e0e0;\n"
"        border-radius: 8px;\n"
"        margin-top: 10px;\n"
"        padding: 15px;\n"
"        font-weight: bold;\n"
"        font-size: 14px;\n"
"        color: #00ACC1;\n"
"    }\n"
"\n"
"    QGroupBox::title {\n"
"        subcontrol-origin: margin;\n"
"        left: 10px;\n"
"        padding: 0 5px;\n"
"    }\n"
"\n"
"    QLineEdit, QTextEdit, QComboBox {\n"
"        border: 1px solid #00ACC1;\n"
"        border-radius: 4px;\n"
"        padding: 8px;\n"
"        background-color: white;\n"
"        font-size: 12px;\n"
"    }\n"
"\n"
"    QLineEdit:focus, QTextEdit:focus, QComboBox:focus {\n"
"        border: 2px solid #00ACC1;\n"
"    }\n"
"\n"
"    QPushButton {\n"
"        background-color: #00ACC1;\n"
"        color: white;\n"
"        border: none;\n"
"        border-radius: 4px;\n"
"        padding: 10px 20px;\n"
"        font"
                        "-size: 12px;\n"
"        font-weight: bold;\n"
"        min-width: 100px;\n"
"    }\n"
"\n"
"    QPushButton:hover {\n"
"        background-color: #0097A7;\n"
"    }\n"
"\n"
"    QPushButton:pressed {\n"
"        background-color: #00838F;\n"
"    }\n"
"\n"
"    QPushButton#deleteButton {\n"
"        background-color: #e0e0e0;\n"
"        color: #333;\n"
"    }\n"
"\n"
"    QPushButton#deleteButton:hover {\n"
"        background-color: #d0d0d0;\n"
"    }\n"
"\n"
"    QListWidget {\n"
"        border: 1px solid #00ACC1;\n"
"        border-radius: 4px;\n"
"        background-color: white;\n"
"        padding: 5px;\n"
"    }\n"
"\n"
"    QListWidget::item {\n"
"        padding: 8px;\n"
"        border-bottom: 1px solid #f0f0f0;\n"
"    }\n"
"\n"
"    QListWidget::item:selected {\n"
"        background-color: #E0F7FA;\n"
"        color: #00838F;\n"
"    }\n"
"\n"
"    QLabel#statusLabel {\n"
"        color: #666;\n"
"        font-size: 11px;\n"
"        padding: 5px;\n"
"    }\n"
"   "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_main = new QHBoxLayout(centralwidget);
        horizontalLayout_main->setObjectName("horizontalLayout_main");
        sidebar = new QWidget(centralwidget);
        sidebar->setObjectName("sidebar");
        sidebar->setMinimumSize(QSize(50, 0));
        sidebar->setMaximumSize(QSize(50, 16777215));
        sidebar->setStyleSheet(QString::fromUtf8("\n"
"        QWidget#sidebar {\n"
"            background-color: #37474F;\n"
"        }\n"
"        QPushButton {\n"
"            background-color: #E3F2FD;\n"
"            color: #00ACC1;\n"
"            border: none;\n"
"            border-radius: 8px;\n"
"            padding: 12px;\n"
"            margin: 5px;\n"
"        }\n"
"        QPushButton:hover {\n"
"            background-color: #B3E5FC;\n"
"        }\n"
"       "));
        verticalLayout_sidebar = new QVBoxLayout(sidebar);
        verticalLayout_sidebar->setObjectName("verticalLayout_sidebar");
        menuButton = new QPushButton(sidebar);
        menuButton->setObjectName("menuButton");
        QFont font;
        font.setBold(true);
        menuButton->setFont(font);

        verticalLayout_sidebar->addWidget(menuButton);

        homeButton = new QPushButton(sidebar);
        homeButton->setObjectName("homeButton");
        homeButton->setFont(font);

        verticalLayout_sidebar->addWidget(homeButton);

        clockButton = new QPushButton(sidebar);
        clockButton->setObjectName("clockButton");
        clockButton->setFont(font);

        verticalLayout_sidebar->addWidget(clockButton);

        fileButton = new QPushButton(sidebar);
        fileButton->setObjectName("fileButton");
        fileButton->setFont(font);

        verticalLayout_sidebar->addWidget(fileButton);

        printButton = new QPushButton(sidebar);
        printButton->setObjectName("printButton");
        printButton->setFont(font);

        verticalLayout_sidebar->addWidget(printButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_sidebar->addItem(verticalSpacer);

        userButton = new QPushButton(sidebar);
        userButton->setObjectName("userButton");
        userButton->setFont(font);

        verticalLayout_sidebar->addWidget(userButton);


        horizontalLayout_main->addWidget(sidebar);

        mainContent = new QWidget(centralwidget);
        mainContent->setObjectName("mainContent");
        verticalLayout_main = new QVBoxLayout(mainContent);
        verticalLayout_main->setObjectName("verticalLayout_main");
        publicationInfoGroup = new QGroupBox(mainContent);
        publicationInfoGroup->setObjectName("publicationInfoGroup");
        formLayout = new QFormLayout(publicationInfoGroup);
        formLayout->setObjectName("formLayout");
        titleLabel = new QLabel(publicationInfoGroup);
        titleLabel->setObjectName("titleLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, titleLabel);

        titleEdit = new QLineEdit(publicationInfoGroup);
        titleEdit->setObjectName("titleEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, titleEdit);

        descriptionLabel = new QLabel(publicationInfoGroup);
        descriptionLabel->setObjectName("descriptionLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, descriptionLabel);

        descriptionEdit = new QTextEdit(publicationInfoGroup);
        descriptionEdit->setObjectName("descriptionEdit");
        descriptionEdit->setMaximumSize(QSize(16777215, 120));

        formLayout->setWidget(1, QFormLayout::FieldRole, descriptionEdit);

        categoryLabel = new QLabel(publicationInfoGroup);
        categoryLabel->setObjectName("categoryLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, categoryLabel);

        categoryCombo = new QComboBox(publicationInfoGroup);
        categoryCombo->addItem(QString());
        categoryCombo->addItem(QString());
        categoryCombo->addItem(QString());
        categoryCombo->addItem(QString());
        categoryCombo->addItem(QString());
        categoryCombo->addItem(QString());
        categoryCombo->addItem(QString());
        categoryCombo->addItem(QString());
        categoryCombo->setObjectName("categoryCombo");

        formLayout->setWidget(2, QFormLayout::FieldRole, categoryCombo);

        horizontalLayout_buttons = new QHBoxLayout();
        horizontalLayout_buttons->setObjectName("horizontalLayout_buttons");
        addButton = new QPushButton(publicationInfoGroup);
        addButton->setObjectName("addButton");

        horizontalLayout_buttons->addWidget(addButton);

        deleteButton = new QPushButton(publicationInfoGroup);
        deleteButton->setObjectName("deleteButton");

        horizontalLayout_buttons->addWidget(deleteButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_buttons->addItem(horizontalSpacer);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_buttons);


        verticalLayout_main->addWidget(publicationInfoGroup);

        publicationListGroup = new QGroupBox(mainContent);
        publicationListGroup->setObjectName("publicationListGroup");
        verticalLayout_list = new QVBoxLayout(publicationListGroup);
        verticalLayout_list->setObjectName("verticalLayout_list");
        publicationList = new QListWidget(publicationListGroup);
        publicationList->setObjectName("publicationList");

        verticalLayout_list->addWidget(publicationList);


        verticalLayout_main->addWidget(publicationListGroup);

        innovativeFeaturesGroup = new QGroupBox(mainContent);
        innovativeFeaturesGroup->setObjectName("innovativeFeaturesGroup");
        horizontalLayout_features = new QHBoxLayout(innovativeFeaturesGroup);
        horizontalLayout_features->setObjectName("horizontalLayout_features");
        summaryButton = new QPushButton(innovativeFeaturesGroup);
        summaryButton->setObjectName("summaryButton");

        horizontalLayout_features->addWidget(summaryButton);

        emailButton = new QPushButton(innovativeFeaturesGroup);
        emailButton->setObjectName("emailButton");

        horizontalLayout_features->addWidget(emailButton);


        verticalLayout_main->addWidget(innovativeFeaturesGroup);

        statusLabel = new QLabel(mainContent);
        statusLabel->setObjectName("statusLabel");

        verticalLayout_main->addWidget(statusLabel);


        horizontalLayout_main->addWidget(mainContent);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Publishing Management", nullptr));
        menuButton->setText(QCoreApplication::translate("MainWindow", "\342\230\260", nullptr));
        homeButton->setText(QCoreApplication::translate("MainWindow", "\360\237\223\204", nullptr));
        clockButton->setText(QCoreApplication::translate("MainWindow", "\360\237\225\220", nullptr));
        fileButton->setText(QCoreApplication::translate("MainWindow", "\360\237\223\213", nullptr));
        printButton->setText(QCoreApplication::translate("MainWindow", "\360\237\226\250", nullptr));
        userButton->setText(QCoreApplication::translate("MainWindow", "\360\237\221\244", nullptr));
        publicationInfoGroup->setTitle(QCoreApplication::translate("MainWindow", "Publication Information", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "Publication Title :", nullptr));
        titleEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter publication title", nullptr));
        descriptionLabel->setText(QCoreApplication::translate("MainWindow", "Publication Description :", nullptr));
        descriptionEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter publication description", nullptr));
        categoryLabel->setText(QCoreApplication::translate("MainWindow", "Publication Category :", nullptr));
        categoryCombo->setItemText(0, QCoreApplication::translate("MainWindow", "Computer Science", nullptr));
        categoryCombo->setItemText(1, QCoreApplication::translate("MainWindow", "Biology", nullptr));
        categoryCombo->setItemText(2, QCoreApplication::translate("MainWindow", "Physics", nullptr));
        categoryCombo->setItemText(3, QCoreApplication::translate("MainWindow", "Mathematics", nullptr));
        categoryCombo->setItemText(4, QCoreApplication::translate("MainWindow", "Engineering", nullptr));
        categoryCombo->setItemText(5, QCoreApplication::translate("MainWindow", "Medicine", nullptr));
        categoryCombo->setItemText(6, QCoreApplication::translate("MainWindow", "Social Sciences", nullptr));
        categoryCombo->setItemText(7, QCoreApplication::translate("MainWindow", "Other", nullptr));

        addButton->setText(QCoreApplication::translate("MainWindow", " Add Publication", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Delete Selected", nullptr));
        publicationListGroup->setTitle(QCoreApplication::translate("MainWindow", "Publications List", nullptr));
        innovativeFeaturesGroup->setTitle(QCoreApplication::translate("MainWindow", "Innovative Features", nullptr));
        summaryButton->setText(QCoreApplication::translate("MainWindow", "Summary", nullptr));
        emailButton->setText(QCoreApplication::translate("MainWindow", "Send Email Notification", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
