#include "conference.h"
#include "ui_conference.h"

#include "addconferencedialog.h"
#include "conference_model.h"

conference::conference(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::conference)
{
    ui->setupUi(this);
}

conference::~conference()
{
    delete ui;
}

void conference::on_addConferenceBtn_clicked()
{
    addconferencedialog dialog(this);

    if (dialog.exec() == QDialog::Accepted)
    {
        conference_model c = dialog.getConference();


    }
}

