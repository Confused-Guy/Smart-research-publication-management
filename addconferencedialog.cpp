#include "addconferencedialog.h"
#include "ui_addconferencedialog.h"

#include <QPushButton>

addconferencedialog::addconferencedialog(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::addconferencedialog)
{
    ui->setupUi(this);

    connect(ui->saveButton, &QPushButton::clicked,
            this, &QDialog::accept);

    connect(ui->cancelButton, &QPushButton::clicked,
            this, &QDialog::reject);
}

addconferencedialog::~addconferencedialog()
{
    delete ui;
}

conference_model addconferencedialog::getConference() const
{
    return conference_model(
        0,
        ui->topicCombo->currentData().toInt(),
        ui->dateEdit->date(),
        ui->locationEdit->text(),
        ui->priceSpin->value()
        );
}
