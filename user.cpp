#include "user.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSettings>

User::User() {}

User::User( int userID,  QString email,QString password,QString username, QString role, QString specialty)
{
    this->userID    = userID;
    this->email     = email;
    this->password  = password;
    this->username  = username;
    this->role      = role;
    this->specialty = specialty;
}

#include <QCryptographicHash>

QString User::hashPassword(const QString &password)
{
    QByteArray hashed = QCryptographicHash::hash(
        password.toUtf8(),
        QCryptographicHash::Sha256
        );

    return hashed.toHex();
}

void User::setId(int id){

    userID = id;

}

void User::setPassword(const QString &password){
    this->password = password;
}
void User::setUsername(const QString &username){
    this->username = username;
}
void User::setRole(const QString &role){
    this->role = role;
}
void User::setSpecialty(const QString &specialty){
    this->specialty = specialty;
}

void User::setEmail(const QString &email){
    this->email = email;
}

int User::getId()               const{     return userID;     }
QString User::getEmail()        const{     return email;      }
QString User::getUsername()     const{     return username;   }
QString User::getRole()         const{     return role;       }
QString User::getSpecialty()    const{     return specialty;  }



bool User::create_user(){

    QSqlQuery query;

    QString hashedPass = hashPassword(password);

    query.prepare("INSERT INTO USERS (USERID, EMAIL, PASSWORD, USERNAME, ROLE, SPECIALTY) "
                  "VALUES (user_SEQ.NEXTVAL, ?, ?, ?, ?, ?)"
                  );


    query.addBindValue(email);
    query.addBindValue(hashedPass);
    query.addBindValue(username);
    query.addBindValue(role);
    query.addBindValue(specialty);

    if(!query.exec())
        return false;

    return true;

}

bool User::update_user()
{
    QSqlQuery query;


    query.prepare(
        "UPDATE USERS SET "
        "EMAIL = ?, "
        "PASSWORD = ?, "
        "USERNAME = ?, "
        "ROLE = ?,"
        "SPECIALTY = ? "
        "WHERE USERID = ?"
        );

    query.addBindValue(email);
    query.addBindValue(hashPassword(this->password));
    query.addBindValue(username);
    query.addBindValue(role);
    query.addBindValue(specialty);


    query.addBindValue(userID);

    if(!query.exec())
        return false;

    return true;



}

bool User::delete_user(){

    QSqlQuery query;

    query.prepare("DELETE FROM USERS WHERE USERID = ?");

    query.addBindValue(userID);


    if(query.exec()){
        return true;

    }

    return false;

}

QSqlQueryModel* User::display(){
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT USERID || ' | ' || EMAIL || ' | ' || USERNAME || ' | ' || ROLE || ' | ' || SPECIALTY AS info FROM USERS");
    return model;
}


void User::saveID(){

    QSettings settings("researchApp", "sessionLogin");
    settings.setValue("userID", this->userID );

}


void User::readSavedID(){

    QSettings settings("researchApp","sessionLogin");

    if(settings.contains("userID"))
    {

        this->userID = settings.value("userID").toInt();

    }


}

bool User::login(QString email, QString password){

    QSqlQuery query;
    QString hashedpass = hashPassword(password);

    query.prepare("SELECT * FROM USERS WHERE EMAIL = ? AND PASSWORD = ?");
    query.addBindValue(email);
    query.addBindValue(hashedpass);
    if (query.exec() && query.next())
    {
        this->userID = query.value("USERID").toInt();
        this->username = query.value("USERNAME").toString();
        this->specialty = query.value("SPECIALTY").toString();
        User::saveID();
        return true;
    }
    else qDebug() << "Email or password incorrect";
    return false;

}

QSqlQueryModel* User::search(QString string)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("SELECT USERID || ' | ' || EMAIL || ' | ' || USERNAME || ' | ' || ROLE || ' | ' || SPECIALTY AS info "
                  "FROM USERS "
                  "WHERE LOWER(EMAIL) LIKE LOWER(:string) "
                  "OR LOWER(USERNAME) LIKE LOWER(:string) "
                  "OR LOWER(ROLE) LIKE LOWER(:string) "
                  "OR LOWER(SPECIALTY) LIKE LOWER(:string)");

    query.bindValue(":string", "%" + string + "%");

    query.exec();
    model->setQuery(std::move(query));

    return model;
}

QSqlQueryModel* User::filter(int state)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    if (state == 1) {
        model->setQuery("SELECT USERID || ' | ' || EMAIL || ' | ' || USERNAME || ' | ' || ROLE || ' | ' || SPECIALTY AS info FROM USERS WHERE SPECIALTY = 'Viewer'");

    } else {
        model->setQuery("SELECT USERID || ' | ' || EMAIL || ' | ' || USERNAME || ' | ' || ROLE || ' | ' || SPECIALTY AS info FROM USERS");
    }

    return model;
}

QSqlQueryModel* User::filter2(int state)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    if (state == 1) {


        model->setQuery("SELECT USERID || ' | ' || EMAIL || ' | ' || USERNAME || ' | ' || ROLE || ' | ' || SPECIALTY AS info FROM USERS WHERE SPECIALTY = 'Reviewer'");

    } else {
        model->setQuery("SELECT USERID || ' | ' || EMAIL || ' | ' || USERNAME || ' | ' || ROLE || ' | ' || SPECIALTY AS info FROM USERS");
    }

    return model;
}

QSqlQueryModel* User::filter3(int state)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    if (state == 1) {

        model->setQuery("SELECT USERID || ' | ' || EMAIL || ' | ' || USERNAME || ' | ' || ROLE || ' | ' || SPECIALTY AS info FROM USERS WHERE SPECIALTY = 'Researcher'");

    } else {
        model->setQuery("SELECT USERID || ' | ' || EMAIL || ' | ' || USERNAME || ' | ' || ROLE || ' | ' || SPECIALTY AS info FROM USERS");
    }

    return model;
}

QSqlQueryModel* User::loadUserStatistics()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT SPECIALTY, COUNT(*) AS TotalUsers FROM USERS GROUP BY SPECIALTY");

    model->setHeaderData(0, Qt::Horizontal, "Specialty");
    model->setHeaderData(1, Qt::Horizontal, "Total Users");

    return model;


}

