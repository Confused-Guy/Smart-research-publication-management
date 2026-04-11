#ifndef COLLABORATION_H
#define COLLABORATION_H

#include <QString>

class Collaboration
{
public:
    Collaboration(int collaborationId, QString title, QString description, int authorId, int publicationId);

    bool create();
    bool Delete();
    bool update();

    int getId() const;
    QString getTitle() const;
    QString getDescription() const;
    int getAuthorId() const;
    int getPublicationId() const;

    void setId(int collaborationId);
    void setTitle(const QString &title);
    void setDescription(const QString &description);
    void setAuthorId(int authorId);
    void setPublicationId(int publicationId);

private:
    int m_collaborationId;
    QString m_title;
    QString m_description;
    int m_authorId;
    int m_publicationId;
};

#endif
