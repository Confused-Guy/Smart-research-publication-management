#include "conference.h"
#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStringList drivers = QSqlDatabase::drivers();
    qDebug() << "Available SQL Drivers:" << drivers;

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("OraclePeerly");
    db.setUserName("system");
    db.setPassword("123");

    if (!db.open())
        qDebug() << "Error:" << db.lastError().text();
    else
        qDebug() << "Connected!";


    MainWindow w;
    w.show();
    return a.exec();
}

