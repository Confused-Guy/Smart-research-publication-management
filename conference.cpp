#include "conference.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QDateTime>
#include <QVariant>

Conference::Conference() {}

Conference::Conference(int id, QString title, int topicId,
                       QDate date, QString location,
                       double price)
{
    this->id       = id;
    this->title    = title;
    this->topicId  = topicId;
    this->date     = date;
    this->location = location;
    this->price    = price;
}

//GETTERS
int     Conference::getId()       const { return id; }
QString Conference::getTitle()    const { return title; }
int     Conference::getTopicId()  const { return topicId; }
QDate   Conference::getDate()     const { return date; }
QString Conference::getLocation() const { return location; }
double  Conference::getPrice()    const { return price; }

bool Conference::add()
{
    QSqlQuery query;
    query.prepare(
        "INSERT INTO CONFERENCE "
        "(ID, TITLE, TOPIC_ID, CONF_DATE, LOCATION, PRICE) "
        "VALUES (CONF_SEQ.NEXTVAL, ?, ?, ?, ?, ?)"
        );
    query.addBindValue(title);
    query.addBindValue(topicId);
    query.addBindValue(QDateTime(date, QTime(0, 0, 0)));
    query.addBindValue(location);
    query.addBindValue(price);

    if (!query.exec()) {
        qDebug() << "Insert error:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Conference::update()
{
    QSqlQuery query;
    query.prepare(
        "UPDATE CONFERENCE SET "
        "TITLE = ?, "
        "TOPIC_ID = ?, "
        "CONF_DATE = ?, "
        "LOCATION = ?, "
        "PRICE = ? "
        "WHERE ID = ?"
        );
    query.addBindValue(title);
    query.addBindValue(topicId);
    query.addBindValue(QDateTime(date, QTime(0, 0, 0)));
    query.addBindValue(location);
    query.addBindValue(price);
    query.addBindValue(id);

    if (!query.exec()) {
        qDebug() << "Update error:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Conference::remove(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM CONFERENCE WHERE ID = ?");
    query.addBindValue(id);

    if (!query.exec()) {
        qDebug() << "Delete error:" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel* Conference::display()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM CONFERENCE ORDER BY CONF_DATE DESC");
    return model;
}
