#include "conference_model.h"

conference_model::conference_model(int id,
                                   int topicId,
                                   QDate date,
                                   const QString &location,
                                   double price)
    : id(id),
    topicId(topicId),
    date(date),
    location(location),
    price(price)
{
}
