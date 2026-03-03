#include "submission.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

Submission::Submission()
    : submissionID(0),
    title(""),
    status("Draft"),
    sourcesCitation(""),
    createdAt(QDate::currentDate()),
    authorID(0),
    topicID(0),
    manuscript("")
{}

Submission::Submission(int submissionID,
                       const QString &title,
                       const QString &status,
                       const QString &sourcesCitation,
                       const QDate &createdAt,
                       int authorID,
                       int topicID,
                       const QString &manuscript)
    : submissionID(submissionID),
    title(title),
    status(status),
    sourcesCitation(sourcesCitation),
    createdAt(createdAt),
    authorID(authorID),
    topicID(topicID),
    manuscript(manuscript)
{}

Submission::Submission(const Submission &other)
    : submissionID(other.submissionID),
    title(other.title),
    status(other.status),
    sourcesCitation(other.sourcesCitation),
    createdAt(other.createdAt),
    authorID(other.authorID),
    topicID(other.topicID),
    manuscript(other.manuscript)
{}

Submission &Submission::operator=(const Submission &other)
{
    if (this != &other) {
        submissionID = other.submissionID;
        title = other.title;
        status = other.status;
        sourcesCitation = other.sourcesCitation;
        createdAt = other.createdAt;
        authorID = other.authorID;
        topicID = other.topicID;
        manuscript = other.manuscript;
    }
    return *this;
}

Submission::~Submission()
{
}

// Getters
int     Submission::getSubmissionID() const { return submissionID;     }
QString Submission::getTitle() const        { return title;             }
QString Submission::getStatus() const       { return status;            }
QString Submission::getSourcesCitation() const { return sourcesCitation; }
QDate   Submission::getCreatedAt() const    { return createdAt;         }
int     Submission::getAuthorID() const     { return authorID;          }
int     Submission::getTopicID() const      { return topicID;           }
QString Submission::getManuscript() const   { return manuscript;        }

// Setters
void Submission::setSubmissionID(int id)            { submissionID = id;         }
void Submission::setTitle(const QString &t)         { title = t;                 }
void Submission::setStatus(const QString &s)        { status = s;                }
void Submission::setSourcesCitation(const QString &citation) { sourcesCitation = citation; }
void Submission::setCreatedAt(const QDate &date)    { createdAt = date;          }
void Submission::setAuthorID(int id)                { authorID = id;             }
void Submission::setTopicID(int id)                 { topicID = id;              }
void Submission::setManuscript(const QString &m)    { manuscript = m;            }

// CRUD Operations
bool Submission::create()
{
    QSqlQuery query;

    query.prepare(
        "INSERT INTO Submission "
        "    (SUBMISSIONID, TITLE, STATUS, SOURCESCITATION, CREATEDAT, AUTHORID, TOPICID, MANUSCRIPT) "
        "VALUES "
        "    (submission_seq.NEXTVAL, :title, :status, :sourcesCitation, :createdAt, :authorID, :topicID, :manuscript)"
        );

    query.bindValue(":title", title);
    query.bindValue(":status", status);
    query.bindValue(":sourcesCitation", sourcesCitation);
    query.bindValue(":createdAt", createdAt);
    query.bindValue(":authorID", authorID);
    query.bindValue(":topicID", topicID);
    query.bindValue(":manuscript", manuscript);

    if (!query.exec()) {
        qDebug() << "[Submission::create] Error:" << query.lastError().text();
        return false;
    }
    return true;
}

QList<Submission> Submission::read()
{
    QList<Submission> list;
    QSqlQuery query;

    query.prepare(
        "SELECT SUBMISSIONID, TITLE, STATUS, SOURCESCITATION, CREATEDAT, AUTHORID, TOPICID, MANUSCRIPT "
        "FROM   Submission "
        "ORDER BY CREATEDAT DESC"
        );

    if (!query.exec()) {
        qDebug() << "[Submission::read] Error:" << query.lastError().text();
        return list;
    }

    while (query.next()) {
        Submission s(
            query.value("SUBMISSIONID").toInt(),
            query.value("TITLE").toString(),
            query.value("STATUS").toString(),
            query.value("SOURCESCITATION").toString(),
            query.value("CREATEDAT").toDate(),
            query.value("AUTHORID").toInt(),
            query.value("TOPICID").toInt(),
            query.value("MANUSCRIPT").toString()
            );
        list.push_back(s);
    }

    return list;
}

bool Submission::update()
{
    QSqlQuery query;

    query.prepare(
        "UPDATE Submission "
        "SET    TITLE           = :title,        "
        "       STATUS          = :status,       "
        "       SOURCESCITATION = :sourcesCitation, "
        "       AUTHORID        = :authorID,     "
        "       TOPICID         = :topicID,      "
        "       MANUSCRIPT      = :manuscript    "
        "WHERE  SUBMISSIONID    = :submissionID  "
        );

    query.bindValue(":title", title);
    query.bindValue(":status", status);
    query.bindValue(":sourcesCitation", sourcesCitation);
    query.bindValue(":authorID", authorID);
    query.bindValue(":topicID", topicID);
    query.bindValue(":manuscript", manuscript);
    query.bindValue(":submissionID", submissionID);

    if (!query.exec()) {
        qDebug() << "[Submission::update] Error:" << query.lastError().text();
        return false;
    }

    return true;
}

bool Submission::deleteSubmission()
{
    QSqlQuery query;

    query.prepare("DELETE FROM Submission WHERE SUBMISSIONID = :submissionID");
    query.bindValue(":submissionID", submissionID);

    if (!query.exec()) {
        qDebug() << "[Submission::deleteSubmission] Error:" << query.lastError().text();
        return false;
    }

    return true;
}

// Helper methods
QList<Submission> Submission::searchByTitle(const QString &keyword)
{
    QList<Submission> list;
    QSqlQuery query;

    query.prepare(
        "SELECT SUBMISSIONID, TITLE, STATUS, SOURCESCITATION, CREATEDAT, AUTHORID, TOPICID, MANUSCRIPT "
        "FROM   Submission "
        "WHERE  UPPER(TITLE) LIKE UPPER(:keyword) "
        "ORDER BY CREATEDAT DESC"
        );

    query.bindValue(":keyword", "%" + keyword + "%");

    if (!query.exec()) {
        qDebug() << "[Submission::searchByTitle] Error:" << query.lastError().text();
        return list;
    }

    while (query.next()) {
        Submission s(
            query.value("SUBMISSIONID").toInt(),
            query.value("TITLE").toString(),
            query.value("STATUS").toString(),
            query.value("SOURCESCITATION").toString(),
            query.value("CREATEDAT").toDate(),
            query.value("AUTHORID").toInt(),
            query.value("TOPICID").toInt(),
            query.value("MANUSCRIPT").toString()
            );
        list.push_back(s);
    }

    return list;
}

QList<Submission> Submission::searchByAuthorID(int authorID)
{
    QList<Submission> list;
    QSqlQuery query;

    query.prepare(
        "SELECT SUBMISSIONID, TITLE, STATUS, SOURCESCITATION, CREATEDAT, AUTHORID, TOPICID, MANUSCRIPT "
        "FROM   Submission "
        "WHERE  AUTHORID = :authorID "
        "ORDER BY CREATEDAT DESC"
        );

    query.bindValue(":authorID", authorID);

    if (!query.exec()) {
        qDebug() << "[Submission::searchByAuthorID] Error:" << query.lastError().text();
        return list;
    }

    while (query.next()) {
        Submission s(
            query.value("SUBMISSIONID").toInt(),
            query.value("TITLE").toString(),
            query.value("STATUS").toString(),
            query.value("SOURCESCITATION").toString(),
            query.value("CREATEDAT").toDate(),
            query.value("AUTHORID").toInt(),
            query.value("TOPICID").toInt(),
            query.value("MANUSCRIPT").toString()
            );
        list.push_back(s);
    }

    return list;
}

QList<Submission> Submission::searchByStatus(const QString &status)
{
    QList<Submission> list;
    QSqlQuery query;

    query.prepare(
        "SELECT SUBMISSIONID, TITLE, STATUS, SOURCESCITATION, CREATEDAT, AUTHORID, TOPICID, MANUSCRIPT "
        "FROM   Submission "
        "WHERE  UPPER(STATUS) = UPPER(:status) "
        "ORDER BY CREATEDAT DESC"
        );

    query.bindValue(":status", status);

    if (!query.exec()) {
        qDebug() << "[Submission::searchByStatus] Error:" << query.lastError().text();
        return list;
    }

    while (query.next()) {
        Submission s(
            query.value("SUBMISSIONID").toInt(),
            query.value("TITLE").toString(),
            query.value("STATUS").toString(),
            query.value("SOURCESCITATION").toString(),
            query.value("CREATEDAT").toDate(),
            query.value("AUTHORID").toInt(),
            query.value("TOPICID").toInt(),
            query.value("MANUSCRIPT").toString()
            );
        list.push_back(s);
    }

    return list;
}
