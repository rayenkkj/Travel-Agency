#ifndef ROLE_H
#define ROLE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Role
{

public:
    Role(QString,QString);
    QString get_poste();
    QString get_description();
    bool ajouter_role();
    bool supprimer_role(QString);
private:
    QString poste,description;
};

#endif // ROLE_H
