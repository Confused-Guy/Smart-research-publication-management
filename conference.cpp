#include "conference.h"
#include <QSqlQuery>
#include <QSqlQueryModel>

Conference::Conference() {}

Conference::Conference(int id, QString title, int topicId,
                       QDate date, QString location,
                       double price, QString description)
{
    this->id = id;
    this->title = title;
    this->topicId = topicId;
    this->date = date;
    this->location = location;
    this->price = price;
    this->description = description;
}

bool Conference::add()
{
    QSqlQuery query;

    query.prepare(
        "INSERT INTO CONFERENCE "
        "(ID, TITLE, TOPIC_ID, CONF_DATE, LOCATION, PRICE, DESCRIPTION) "
        "VALUES (CONF_SEQ.NEXTVAL, :title, :topicId, :date, :location, :price, :description)"
        );

    query.bindValue(":title", title);
    query.bindValue(":topicId", topicId);
    query.bindValue(":date", date);
    query.bindValue(":location", location);
    query.bindValue(":price", price);
    query.bindValue(":description", description);

    return query.exec();
}


bool Conference::update()
{
    QSqlQuery query;

    query.prepare(
        "UPDATE CONFERENCE SET "
        "TITLE=:title, TOPIC_ID=:topicId, CONF_DATE=:date, "
        "LOCATION=:location, PRICE=:price, DESCRIPTION=:description "
        "WHERE ID=:id"
        );

    query.bindValue(":id", id);
    query.bindValue(":title", title);
    query.bindValue(":topicId", topicId);
    query.bindValue(":date", date);
    query.bindValue(":location", location);
    query.bindValue(":price", price);
    query.bindValue(":description", description);

    return query.exec();
}


bool Conference::remove(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM CONFERENCE WHERE ID=:id");
    query.bindValue(":id", id);
    return query.exec();
}


QSqlQueryModel* Conference::display()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM CONFERENCE ORDER BY CONF_DATE DESC");
    return model;
}
