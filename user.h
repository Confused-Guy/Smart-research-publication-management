#ifndef USER_H
#define USER_H

#include <QString>
#include <QSqlQueryModel>

class User
{
private:
    int userID;
    QString email;
    QString password;
    QString username;
    QString role;
    QString specialty;
    QString rfidCode; //NEW FOR THE ARDUINO LOG IN

public:
    User();
    User(int id, QString email, QString password,QString username, QString role, QString specialty);

    int getId() const;
    QString getEmail() const;
    QString getUsername() const;
    QString getRole() const;
    QString getSpecialty() const;


    void setId(int id);
    void setEmail(const QString &email);
    void setPassword(const QString &password);
    void setUsername(const QString &username);
    void setRole(const QString &role);
    void setSpecialty(const QString &specialty);

    QString hashPassword(const QString &password);

    bool create_user();
    bool update_user();
    bool delete_user();
    QSqlQueryModel* display();

    void saveID();
    void readSavedID();
    bool login(QString email, QString password);
    QSqlQueryModel* search(QString string);
    QSqlQueryModel* filter(int state);
    QSqlQueryModel* filter2(int state);
    QSqlQueryModel* filter3(int state);
    QSqlQueryModel* loadUserStatistics();

    //NEW FOR ARDUINO LOG IN
    void setRfidCode(const QString &rfidCode);
    QString getRfidCode() const;
    bool loginByRFID(const QString &rfidCode);
    void extracted(QSqlQuery &query);
    bool assignRFID(int userID, const QString &rfidCode);
};

#endif // USER_H
