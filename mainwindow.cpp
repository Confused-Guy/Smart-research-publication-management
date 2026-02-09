#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize({800,600});
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_quitb_clicked()
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
        // File was selected, do something with it
        // For example, display it in a label or line edit:
        // ui->label->setText(filePath);
        // Or just for testing:
        qDebug() << "Selected file:" << filePath;
    }
}

