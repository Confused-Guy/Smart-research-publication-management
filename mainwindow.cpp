#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize({1290,780});
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_quit_clicked()
{
    this->close();
}


void MainWindow::on_Browse_pressed()
{
    QString filePath = QFileDialog::getOpenFileName(
        this,
        "Browse Files",
        "",  // Starting directory
        "All Files (*)"  // File filter
        );

    if (!filePath.isEmpty()) {
        qDebug() << "Selected file:" << filePath;
    }
}

