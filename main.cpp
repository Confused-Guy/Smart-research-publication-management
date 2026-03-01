#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDir>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("OraclePeerly");
    db.setUserName("system");
    db.setPassword("root");

    if (!db.open()){
        qDebug() << "Database Error:" << db.lastError().text();
    }else{
        qDebug() << "Datbase Connected";
        qDebug() << "Username:" << db.userName();}

    MainWindow w;
    w.show();
    return a.exec();
}

