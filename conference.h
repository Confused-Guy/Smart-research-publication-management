#ifndef CONFERENCE_H
#define CONFERENCE_H

#include "qsqlquerymodel.h"
#include <QString>
#include <QDate>

class Conference
{
private:
    int id;
    QString title;
    int topicId;
    QDate date;
    QString location;
    double price;
    QString description;


public:
    Conference();
    Conference(int id, QString title, int topicId,
               QDate date, QString location,
               double price, QString description);

    // Getters
    int getId() const;
    QString getTitle() const;
    int getTopicId() const;
    QDate getDate() const;
    QString getLocation() const;
    double getPrice() const;
    QString getDescription() const;

    // CRUD
    bool add();
    bool update();
    bool remove(int id);
    QSqlQueryModel* display();

};

#endif
