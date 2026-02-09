#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("logo.png");
    ui->label->setPixmap(pix);
    QPixmap pix2("researchBgLogin.png");
    ui->label_2->setPixmap(pix2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_label_3_linkActivated(const QString &link)
{
    ui->stack->setCurrentIndex(1);
}



void MainWindow::on_verifyBtnForgot_clicked()
{
    ui->stack->setCurrentIndex(0);
}


void MainWindow::on_cancelFogotBTN_clicked()
{
    ui->stack->setCurrentIndex(2);
}


void MainWindow::on_CancelBTNCode_clicked()
{
    ui->stack->setCurrentIndex(2);
}

