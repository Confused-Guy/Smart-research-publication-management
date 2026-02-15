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
    db.setPassword("123");

    if (!db.open())
        qDebug() << "Database Error:" << db.lastError().text();
    else
        qDebug() << "Datbase Connected";


    MainWindow w;
    w.show();
    return a.exec();
}

