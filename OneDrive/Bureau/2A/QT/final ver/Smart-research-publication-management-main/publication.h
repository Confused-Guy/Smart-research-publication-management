#ifndef PUBLICATION_H
#define PUBLICATION_H

#include <QString>
#include <QDate>
#include <QList>

class Publication
{
private:
    int     publicationID;
    int     authorID;
    int     submissionID;
    QString description;
    QDate   createdDate;
    QString field;
public:
    Publication();
    Publication(int     publicationID,
                int     authorID,
                int     submissionID,
                const QString &description,
                const QDate   &createdDate,
                const QString &field);

    Publication(const Publication &other);
    Publication &operator=(const Publication &other);
    ~Publication();
    int     getPublicationID() const;
    int     getAuthorID()      const;
    int     getSubmissionID()  const;
    QString getDescription()   const;
    QDate   getCreatedDate()   const;
    QString getField()         const;

    void setPublicationID(int publicationID);
    void setAuthorID(int authorID);
    void setSubmissionID(int submissionID);
    void setDescription(const QString &description);
    void setCreatedDate(const QDate   &createdDate);
    void setField(const QString &field);


    bool               create();
    QList<Publication> read();
    bool               update();
    bool               deletePublication();


    QList<Publication> search(const QString &keyword);
    static int getNextSequenceValue();
};

#endif
