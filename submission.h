#ifndef SUBMISSION_H
#define SUBMISSION_H

#include <QString>
#include <QList>
#include <QDate>

class Submission
{
public:
    // Constructors / Destructor
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

    // CRUD
    bool              create();
    QList<Submission> read();
    bool              update();
    bool              deleteSubmission();

    // Search helpers
    QList<Submission> searchByTitle(const QString &keyword);
    QList<Submission> searchByAuthorID(int authorID);
    QList<Submission> searchByStatus(const QString &status);

    // Getters
    int     getSubmissionID()    const;
    QString getTitle()           const;
    QString getStatus()          const;
    QString getSourcesCitation() const;
    QDate   getCreatedAt()       const;
    int     getAuthorID()        const;
    int     getTopicID()         const;
    QString getManuscript()      const;

    // Setters
    void setSubmissionID(int id);
    void setTitle(const QString &t);
    void setStatus(const QString &s);
    void setSourcesCitation(const QString &citation);
    void setCreatedAt(const QDate &date);
    void setAuthorID(int id);
    void setTopicID(int id);
    void setManuscript(const QString &m);

private:
    int     submissionID;
    QString title;
    QString status;
    QString sourcesCitation;
    QDate   createdAt;
    int     authorID;
    int     topicID;
    QString manuscript;
};

#endif // SUBMISSION_H
