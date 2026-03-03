#ifndef SUBMISSION_H
#define SUBMISSION_H

#include <QString>
#include <QDate>
#include <QList>

class Submission
{
private:
    int     submissionID;
    QString title;
    QString status;
    QString sourcesCitation;
    QDate   createdAt;
    int     authorID;
    int     topicID;
    QString manuscript;

public:
    Submission();
    Submission(int submissionID,
               const QString &title,
               const QString &status,
               const QString &sourcesCitation,
               const QDate &createdAt,
               int authorID,
               int topicID,
               const QString &manuscript);

    Submission(const Submission &other);
    Submission &operator=(const Submission &other);
    ~Submission();

    // Getters
    int     getSubmissionID() const;
    QString getTitle() const;
    QString getStatus() const;
    QString getSourcesCitation() const;
    QDate   getCreatedAt() const;
    int     getAuthorID() const;
    int     getTopicID() const;
    QString getManuscript() const;

    // Setters
    void setSubmissionID(int id);
    void setTitle(const QString &title);
    void setStatus(const QString &status);
    void setSourcesCitation(const QString &citation);
    void setCreatedAt(const QDate &date);
    void setAuthorID(int id);
    void setTopicID(int id);
    void setManuscript(const QString &manuscript);

    // CRUD Operations
    bool create();
    QList<Submission> read();
    bool update();
    bool deleteSubmission();

    // Helper methods
    QList<Submission> searchByTitle(const QString &keyword);
    QList<Submission> searchByAuthorID(int authorID);
    QList<Submission> searchByStatus(const QString &status);
};

#endif // SUBMISSION_H
