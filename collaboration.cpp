#include <QSqlQuery>
#include <QSqlQueryModel>
#include <ui_mainwindow.h>

#include "collaboration.h"
#include "user.h"


Collaboration::Collaboration(int collaborationId, QString title, QString description, int authorId, int publicationId)
    :   m_collaborationId(collaborationId),
    m_title(title),
    m_description(description),
    m_authorId(authorId),
    m_publicationId(publicationId)
{

}

int Collaboration::getId() const                                    { return m_collaborationId; }
QString Collaboration::getTitle() const                             { return m_title; }
QString Collaboration::getDescription() const                       { return m_description; }
int Collaboration::getAuthorId() const                              { return m_authorId; }
int Collaboration::getPublicationId() const                         { return m_publicationId; }

void Collaboration::setId(int collaborationId)                      { m_collaborationId = collaborationId; }
void Collaboration::setTitle(const QString &title)                  { m_title = title; }
void Collaboration::setDescription(const QString &description)      { m_description = description; }
void Collaboration::setAuthorId(int authorId)                       { m_authorId = authorId; }
void Collaboration::setPublicationId(int publicationId)             { m_publicationId = publicationId; }

bool Collaboration::create(std::vector<User> &usersToAdd)
{
    if (m_title.isEmpty())
        return false;

    if (m_description.isEmpty())
        return false;

    QSqlQuery query;
    query.prepare
    (
        "INSERT INTO collaboration "
        "(idcollaboration, title, description, authorId, publicationId) "
        "VALUES (collab_SEQ.NEXTVAL, ?, ?, ?, ?)"
    );

    //works on my machine
    //SELECT current_value FROM sys.sequences WHERE name = 'OrderNumberSequence';

    query.addBindValue(m_title);
    query.addBindValue(m_description);
    query.addBindValue(m_authorId);
    query.addBindValue(1);

    if(!query.exec())
        return false;

    query.prepare("INSERT INTO collaboration_users"
                  "(idcollaboration, iduser)"
                  "VALUES(collab_SEQ.CURRVAL, ?)");

    query.addBindValue(m_authorId);

    if (!query.exec())
    {
        qDebug() << "failed to create COLLABORAION_USERS with author";
        return false;
    }

    for (int i = 0; i < usersToAdd.size(); i++)
    {
        query.prepare("INSERT INTO collaboration_users"
                      "(idcollaboration, iduser)"
                      "VALUES(collab_SEQ.CURRVAL, ?)");

        int currentUserId = usersToAdd[i].getId();
        query.addBindValue(currentUserId);

        if (!query.exec())
        {
            qDebug() << "failed to create COLLABORAION_USERS with: " << currentUserId << '\n';
        }
    }

    return true;
}

bool Collaboration::Delete()
{
    QSqlQuery query;
    query.prepare("DELETE FROM collaboration_users WHERE idcollaboration = ?");
    query.addBindValue(m_collaborationId);

    if (!query.exec())
        return false;

    query.prepare("DELETE FROM collaboration_message WHERE idcollaboration = ?");
    query.addBindValue(m_collaborationId);

    if (!query.exec())
        return false;

    query.prepare("DELETE FROM collaboration WHERE idcollaboration = ?");
    query.addBindValue(m_collaborationId);

    if(!query.exec())
        return false;

    return true;
}

bool Collaboration::update()
{
    QSqlQuery query;
    query.prepare
    (
        "UPDATE collaboration SET "
        "title = ?, "
        "description = ?, "
        "authorId = ?, "
        "publicationId = ? "
        "WHERE idcollaboration = ?"
    );
    query.addBindValue(m_title);
    query.addBindValue(m_description);
    query.addBindValue(m_authorId);
    query.addBindValue(m_publicationId);
    query.addBindValue(m_collaborationId);

    if(!query.exec())
        return false;

    qDebug() << "UpdatedCollab With The Following Attributes:";
    qDebug() << "Title: " << m_title;
    qDebug() << "Description: " << m_description;
    qDebug() << "authorId: " << m_authorId;
    qDebug() << "publicationId: " << m_publicationId;
    qDebug() << "Id: " << m_collaborationId;

    return true;
}






