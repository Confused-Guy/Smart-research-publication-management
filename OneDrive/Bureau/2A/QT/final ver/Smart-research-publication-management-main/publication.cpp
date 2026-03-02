#include "publication.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

Publication::Publication()
    : publicationID(0),
    authorID(0),
    submissionID(0),
    description(""),
    createdDate(QDate::currentDate()),
    field("")
{}

Publication::Publication(int            publicationID,
                         int            authorID,
                         int            submissionID,
                         const QString &description,
                         const QDate   &createdDate,
                         const QString &field)
    : publicationID(publicationID),
    authorID(authorID),
    submissionID(submissionID),
    description(description),
    createdDate(createdDate),
    field(field)
{}

Publication::Publication(const Publication &other)
    : publicationID(other.publicationID),
    authorID(other.authorID),
    submissionID(other.submissionID),
    description(other.description),
    createdDate(other.createdDate),
    field(other.field)
{}

Publication &Publication::operator=(const Publication &other)
{
    if (this != &other) {
        publicationID = other.publicationID;
        authorID      = other.authorID;
        submissionID  = other.submissionID;
        description   = other.description;
        createdDate   = other.createdDate;
        field         = other.field;
    }
    return *this;
}

Publication::~Publication()
{
}

int     Publication::getPublicationID() const { return publicationID; }
int     Publication::getAuthorID()      const { return authorID;      }
int     Publication::getSubmissionID()  const { return submissionID;  }
QString Publication::getDescription()   const { return description;   }
QDate   Publication::getCreatedDate()   const { return createdDate;   }
QString Publication::getField()         const { return field;         }

void Publication::setPublicationID(int id)            { publicationID = id;   }
void Publication::setAuthorID(int id)                 { authorID      = id;   }
void Publication::setSubmissionID(int id)             { submissionID  = id;   }
void Publication::setDescription(const QString &desc) { description   = desc; }
void Publication::setCreatedDate(const QDate   &date) { createdDate   = date; }
void Publication::setField(const QString &f)          { field         = f;    }

bool Publication::create()
{
    QSqlQuery query;

    query.prepare(
        "INSERT INTO PUBLICATIONS "
        "    (PUBLICATIONID, AUTHORID, SUBMISSIONID, DESCRIPTION, CREATEDDATE, FIELD) "
        "VALUES "
        "    (PUB_SEQ.NEXTVAL, :authorID, :submissionID, :description, :createdDate, :field)"
        );

    query.bindValue(":authorID",     authorID);
    query.bindValue(":submissionID", submissionID);
    query.bindValue(":description",  description);
    query.bindValue(":createdDate",  createdDate);
    query.bindValue(":field",        field);

    if (!query.exec()) {
        qDebug() << "[Publication::create] Error:" << query.lastError().text();
        return false;
    }
    return true;
}

QList<Publication> Publication::read()
{
    QList<Publication> list;
    QSqlQuery query;

    query.prepare(
        "SELECT PUBLICATIONID, AUTHORID, SUBMISSIONID, "
        "       DESCRIPTION, CREATEDDATE, FIELD "
        "FROM   PUBLICATIONS "
        "ORDER BY CREATEDDATE DESC"
        );

    if (!query.exec()) {
        qDebug() << "[Publication::read] Error:" << query.lastError().text();
        return list;
    }

    while (query.next()) {
        Publication p(
            query.value("PUBLICATIONID").toInt(),
            query.value("AUTHORID").toInt(),
            query.value("SUBMISSIONID").toInt(),
            query.value("DESCRIPTION").toString(),
            query.value("CREATEDDATE").toDate(),
            query.value("FIELD").toString()
            );
        list.push_back(p);
    }

    return list;
}

bool Publication::update()
{
    QSqlQuery query;

    query.prepare(
        "UPDATE PUBLICATIONS "
        "SET    AUTHORID     = :authorID,    "
        "       SUBMISSIONID = :submissionID, "
        "       DESCRIPTION  = :description,  "
        "       CREATEDDATE  = :createdDate,  "
        "       FIELD        = :field         "
        "WHERE  PUBLICATIONID = :publicationID"
        );

    query.bindValue(":authorID",      authorID);
    query.bindValue(":submissionID",  submissionID);
    query.bindValue(":description",   description);
    query.bindValue(":createdDate",   createdDate);
    query.bindValue(":field",         field);
    query.bindValue(":publicationID", publicationID);

    if (!query.exec()) {
        qDebug() << "[Publication::update] Error:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Publication::deletePublication()
{
    QSqlQuery query;

    query.prepare(
        "DELETE FROM PUBLICATIONS WHERE PUBLICATIONID = :publicationID"
        );
    query.bindValue(":publicationID", publicationID);

    if (!query.exec()) {
        qDebug() << "[Publication::deletePublication] Error:" << query.lastError().text();
        return false;
    }
    return true;
}

QList<Publication> Publication::search(const QString &keyword)
{
    QList<Publication> resultList;
    QSqlQuery query;

    query.prepare(
        "SELECT PUBLICATIONID, AUTHORID, SUBMISSIONID, "
        "       DESCRIPTION, CREATEDDATE, FIELD "
        "FROM   PUBLICATIONS "
        "WHERE  LOWER(FIELD)       LIKE :kw "
        "OR     LOWER(DESCRIPTION) LIKE :kw "
        "ORDER BY CREATEDDATE DESC"
        );

    QString pattern = "%" + keyword.toLower() + "%";
    query.bindValue(":kw", pattern);

    if (!query.exec()) {
        qDebug() << "[Publication::search] Error:" << query.lastError().text();
        return resultList;
    }

    while (query.next()) {
        Publication p(
            query.value("PUBLICATIONID").toInt(),
            query.value("AUTHORID").toInt(),
            query.value("SUBMISSIONID").toInt(),
            query.value("DESCRIPTION").toString(),
            query.value("CREATEDDATE").toDate(),
            query.value("FIELD").toString()
            );
        resultList.push_back(p);
    }

    QList<Publication>::const_iterator it;
    for (it = resultList.begin(); it != resultList.end(); ++it) {
        qDebug() << "[Publication::search] Found ID:" << it->getPublicationID()
        << "| Field:" << it->getField();
    }

    return resultList;
}

int Publication::getNextSequenceValue()
{
    QSqlQuery query;
    query.prepare("SELECT PUB_SEQ.CURRVAL FROM DUAL");

    if (!query.exec() || !query.next()) {
        qDebug() << "[Publication::getNextSequenceValue] Error:" << query.lastError().text();
        return -1;
    }
    return query.value(0).toInt();
}
