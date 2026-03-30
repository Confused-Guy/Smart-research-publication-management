#ifndef REVIEW_H
#define REVIEW_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>

class Review
{
    int     id;
    QString reviewerName;
    QDate   reviewDate;
    int     submissionId;
    int     publicationId;
    QString comment;
    QString status;

public:
    Review();
    Review(int id, QString reviewerName, QDate reviewDate,
           int submissionId, int publicationId,
           QString comment, QString status);

    // Getters
    int     getId()            const;
    QString getReviewerName()  const;
    QDate   getReviewDate()    const;
    int     getSubmissionId()  const;
    int     getPublicationId() const;
    QString getComment()       const;
    QString getStatus()        const;

    // DB operations
    bool add();
    bool update();
    static bool remove(int id);
    static QSqlQueryModel* display();

    // Load a single review by id (for the edit dialog)
    static Review getById(int id, bool* ok = nullptr);
};

#endif // REVIEW_H
