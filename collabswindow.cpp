#include "collabswindow.h"
#include "ui_collabswindow.h"

collabsWindow::collabsWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::collabsWindow)
{
    ui->setupUi(this);
    this->resize(1280, 720);

    {
        QFont tempFont = ui->listWidget->font();
        tempFont.setPointSize(20);
        ui->listWidget->setFont(tempFont);
    }

    {
        QFont tempFont = ui->textBrowser->font();
        tempFont.setPointSize(20);
        ui->textBrowser->setFont(tempFont);
    }

    QString placeHolder =   "{Title of research}\n"\
                            "{Sub-Title}\n"\
                            "{Body of research}";

    ui->textBrowser->setText(placeHolder);
    ui->listWidget->addItem("{name of owner}/{name of project}");

    int h = ui->listWidget->height();
    int w = ui->textBrowser->width();
    int x = ui->textBrowser->x();
    int y = 50;

    ui->textBrowser->resize(w, h);
    ui->textBrowser->move(x, y);
    ui->listWidget->move(150, y);



}


collabsWindow::~collabsWindow()
{
    delete ui;
}


