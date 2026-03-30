#include "review.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

Review::Review() {}

Review::Review(int id, QString reviewerName, QDate reviewDate,
               int submissionId, int publicationId,
               QString comment, QString status)
{
    this->id            = id;
    this->reviewerName  = reviewerName;
    this->reviewDate    = reviewDate;
    this->submissionId  = submissionId;
    this->publicationId = publicationId;
    this->comment       = comment;
    this->status        = status;
}

// Getters
int     Review::getId()            const { return id; }
QString Review::getReviewerName()  const { return reviewerName; }
QDate   Review::getReviewDate()    const { return reviewDate; }
int     Review::getSubmissionId()  const { return submissionId; }
int     Review::getPublicationId() const { return publicationId; }
QString Review::getComment()       const { return comment; }
QString Review::getStatus()        const { return status; }

bool Review::add()
{
    QSqlQuery query;
    query.prepare(
        "INSERT INTO REVIEW "
        "  (IDREVIEW, REVIEWER_NAME, REVIEW_DATE, SUBMISSION_ID, PUBLICATION_ID, COMMENTREVIEW, STATUS) "
        "VALUES "
        "  (REVIEW_SEQ.NEXTVAL, ?, ?, ?, ?, ?, ?)"
        );
    query.addBindValue(reviewerName);
    query.addBindValue(reviewDate);
    query.addBindValue(submissionId);
    query.addBindValue(publicationId);
    query.addBindValue(comment);
    query.addBindValue(status.isEmpty() ? "Pending" : status);

    if (!query.exec()) {
        qDebug() << "Review insert error:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Review::update()
{
    QSqlQuery query;
    query.prepare(
        "UPDATE REVIEW SET "
        "  REVIEWER_NAME = ?, "
        "  REVIEW_DATE   = ?, "
        "  COMMENTREVIEW = ?, "
        "  STATUS        = ? "
        "WHERE IDREVIEW  = ?"
        );
    query.addBindValue(reviewerName);
    query.addBindValue(reviewDate);
    query.addBindValue(comment);
    query.addBindValue(status);
    query.addBindValue(id);

    if (!query.exec()) {
        qDebug() << "Review update error:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Review::remove(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM REVIEW WHERE IDREVIEW = ?");
    query.addBindValue(id);

    if (!query.exec()) {
        qDebug() << "Review delete error:" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel* Review::display()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(
        "SELECT IDREVIEW, REVIEWER_NAME, REVIEW_DATE, SUBMISSION_ID, "
        "       PUBLICATION_ID, COMMENTREVIEW, STATUS "
        "FROM REVIEW ORDER BY REVIEW_DATE DESC"
        );
    return model;
}

Review Review::getById(int id, bool* ok)
{
    QSqlQuery q;
    q.prepare(
        "SELECT IDREVIEW, REVIEWER_NAME, REVIEW_DATE, SUBMISSION_ID, "
        "       PUBLICATION_ID, COMMENTREVIEW, STATUS "
        "FROM REVIEW WHERE IDREVIEW = ?"
        );
    q.addBindValue(id);

    if (q.exec() && q.next()) {
        if (ok) *ok = true;
        return Review(
            q.value(0).toInt(),
            q.value(1).toString(),
            q.value(2).toDate(),
            q.value(3).toInt(),
            q.value(4).toInt(),
            q.value(5).toString(),
            q.value(6).toString()
            );
    }

    if (ok) *ok = false;
    return Review();
}
