#ifndef CONFERENCE_MODEL_H
#define CONFERENCE_MODEL_H

#include <QString>
#include <QDate>

class conference_model
{
public:
    conference_model(int id,
                     int topicId,
                     QDate date,
                     const QString &location,
                     double price);

private:
    int id;
    int topicId;
    QDate date;
    QString location;
    double price;
};

#endif
