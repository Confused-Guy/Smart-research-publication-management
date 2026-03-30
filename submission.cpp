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
    topic(""),                              // CHANGED: QString instead of int
    manuscript("")
{}

Submission::Submission(int submissionID,
                       const QString &title,
                       const QString &status,
                       const QString &sourcesCitation,
                       const QDate &createdAt,
                       int authorID,
                       const QString &topic,            // CHANGED: const QString& instead of int
                       const QString &manuscript)
    : submissionID(submissionID),
    title(title),
    status(status),
    sourcesCitation(sourcesCitation),
    createdAt(createdAt),
    authorID(authorID),
    topic(topic),                           // CHANGED
    manuscript(manuscript)
{}

Submission::Submission(const Submission &other)
    : submissionID(other.submissionID),
    title(other.title),
    status(other.status),
    sourcesCitation(other.sourcesCitation),
    createdAt(other.createdAt),
    authorID(other.authorID),
    topic(other.topic),                     // CHANGED
    manuscript(other.manuscript)
{}

Submission &Submission::operator=(const Submission &other)
{
    if (this != &other) {
        submissionID    = other.submissionID;
        title           = other.title;
        status          = other.status;
        sourcesCitation = other.sourcesCitation;
        createdAt       = other.createdAt;
        authorID        = other.authorID;
        topic           = other.topic;      // CHANGED
        manuscript      = other.manuscript;
    }
    return *this;
}

Submission::~Submission() {}

// Getters
int     Submission::getSubmissionID()    const { return submissionID;    }
QString Submission::getTitle()           const { return title;            }
QString Submission::getStatus()          const { return status;           }
QString Submission::getSourcesCitation() const { return sourcesCitation;  }
QDate   Submission::getCreatedAt()       const { return createdAt;        }
int     Submission::getAuthorID()        const { return authorID;         }
QString Submission::getTopic()           const { return topic;            } // CHANGED
QString Submission::getManuscript()      const { return manuscript;       }

// Setters
void Submission::setSubmissionID(int id)                     { submissionID    = id;      }
void Submission::setTitle(const QString &t)                  { title           = t;       }
void Submission::setStatus(const QString &s)                 { status          = s;       }
void Submission::setSourcesCitation(const QString &citation) { sourcesCitation = citation; }
void Submission::setCreatedAt(const QDate &date)             { createdAt       = date;    }
void Submission::setAuthorID(int id)                         { authorID        = id;      }
void Submission::setTopic(const QString &t)                  { topic           = t;       } // CHANGED
void Submission::setManuscript(const QString &m)             { manuscript      = m;       }

// CRUD Operations
bool Submission::create()
{
    QSqlQuery query;

    query.prepare(
        "INSERT INTO Submission "
        "    (SUBMISSIONID, TITLE, STATUS, SOURCESCITATION, CREATEDAT, AUTHORID, TOPIC, MANUSCRIPT) "
        "VALUES "
        "    (submission_seq.NEXTVAL, :title, :status, :sourcesCitation, :createdAt, :authorID, :topic, :manuscript)"
        );

    query.bindValue(":title",           title);
    query.bindValue(":status",          status);
    query.bindValue(":sourcesCitation", sourcesCitation);
    query.bindValue(":createdAt",       createdAt);
    query.bindValue(":authorID",        authorID);
    query.bindValue(":topic",           topic);         // CHANGED: was :topicID bound to int
    query.bindValue(":manuscript",      manuscript);

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
        "SELECT SUBMISSIONID, TITLE, STATUS, SOURCESCITATION, CREATEDAT, AUTHORID, TOPIC, MANUSCRIPT "
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
            query.value("TOPIC").toString(),    // CHANGED: toString() instead of toInt()
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
        "SET    TITLE           = :title,           "
        "       STATUS          = :status,          "
        "       SOURCESCITATION = :sourcesCitation, "
        "       AUTHORID        = :authorID,        "
        "       TOPIC           = :topic,           "  // CHANGED: TOPIC instead of TOPICID
        "       MANUSCRIPT      = :manuscript       "
        "WHERE  SUBMISSIONID    = :submissionID     "
        );

    query.bindValue(":title",           title);
    query.bindValue(":status",          status);
    query.bindValue(":sourcesCitation", sourcesCitation);
    query.bindValue(":authorID",        authorID);
    query.bindValue(":topic",           topic);         // CHANGED
    query.bindValue(":manuscript",      manuscript);
    query.bindValue(":submissionID",    submissionID);

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

// Search helpers
QList<Submission> Submission::searchByTitle(const QString &keyword)
{
    QList<Submission> list;
    QSqlQuery query;

    query.prepare(
        "SELECT SUBMISSIONID, TITLE, STATUS, SOURCESCITATION, CREATEDAT, AUTHORID, TOPIC, MANUSCRIPT "
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
            query.value("TOPIC").toString(),    // CHANGED
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
        "SELECT SUBMISSIONID, TITLE, STATUS, SOURCESCITATION, CREATEDAT, AUTHORID, TOPIC, MANUSCRIPT "
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
            query.value("TOPIC").toString(),    // CHANGED
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
        "SELECT SUBMISSIONID, TITLE, STATUS, SOURCESCITATION, CREATEDAT, AUTHORID, TOPIC, MANUSCRIPT "
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
            query.value("TOPIC").toString(),    // CHANGED
            query.value("MANUSCRIPT").toString()
            );
        list.push_back(s);
    }

    return list;
}

// ==================== VALIDATION METHODS ====================

QString Submission::validateTitle(const QString &t)
{
    QString trimmed = t.trimmed();
    if (trimmed.isEmpty()) {
        return "Title cannot be empty";
    }
    if (trimmed.length() < 3) {
        return "Title must be at least 3 characters long";
    }
    if (trimmed.length() > 255) {
        return "Title must not exceed 255 characters";
    }
    return ""; // Empty string means valid
}

QString Submission::validateStatus(const QString &s)
{
    if (!isValidStatus(s)) {
        return "Invalid status. Must be one of: Draft, Submitted, Under Review, Revision Required, Accepted, Rejected";
    }
    return "";
}

QString Submission::validateTopic(const QString &top)
{
    QString trimmed = top.trimmed();
    if (trimmed.isEmpty()) {
        return "Topic cannot be empty";
    }
    if (trimmed.length() < 2) {
        return "Topic must be at least 2 characters long";
    }
    if (trimmed.length() > 255) {
        return "Topic must not exceed 255 characters";
    }
    return "";
}

QString Submission::validateAuthorID(int id)
{
    if (id <= 0) {
        return "Author ID must be greater than 0";
    }

    // Check if author exists in database
    QSqlQuery query;
    query.prepare("SELECT USERID FROM USERS WHERE USERID = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "[Submission::validateAuthorID] Query error:" << query.lastError().text();
        return "Database error while validating author";
    }

    if (!query.next()) {
        return QString("Author with ID %1 does not exist in the database").arg(id);
    }

    return "";
}

bool Submission::isValidStatus(const QString &s) const
{
    static const QStringList validStatuses = {
        "Draft",
        "Submitted",
        "Under Review",
        "Revision Required",
        "Accepted",
        "Rejected"
    };
    return validStatuses.contains(s);
}

// ==================== REVIEW RESPONSE TRACKER ====================

QList<int> Submission::getUnresolvedReviewIssues() const
{
    QList<int> unresolvedIssues;

    if (submissionID <= 0) {
        return unresolvedIssues;
    }

    QSqlQuery query;
    query.prepare(
        "SELECT IDREVIEW FROM REVIEW "
        "WHERE SUBMISSION_ID = :submissionID AND STATUS != 'Resolved' "
        "ORDER BY REVIEW_DATE DESC"
    );
    query.bindValue(":submissionID", submissionID);

    if (!query.exec()) {
        qDebug() << "[Submission::getUnresolvedReviewIssues] Error:" << query.lastError().text();
        return unresolvedIssues;
    }

    while (query.next()) {
        unresolvedIssues.append(query.value("IDREVIEW").toInt());
    }

    return unresolvedIssues;
}

bool Submission::canResubmit() const
{
    // If status is not "Revision Required", then resubmission is allowed based on review
    if (status != "Revision Required") {
        return true;
    }

    // If status is "Revision Required", check for unresolved reviews
    QList<int> unresolvedIssues = getUnresolvedReviewIssues();
    return unresolvedIssues.isEmpty();
}
