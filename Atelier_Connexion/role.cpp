#include "role.h"
#include <QDebug>
#include <QString>

Role::Role(QString poste ,QString description)
{
    this->poste=poste;
    this->description=description;

}

QString Role::get_poste(){return poste;}
QString Role::get_description(){return description;}


bool Role::ajouter_role(){
    QSqlQuery query;
    query.prepare("INSERT INTO AGENT_ROLE(poste , description)"
                        "VALUES (:poste,:description)");
    query.bindValue(":poste",poste);
    query.bindValue(":description",description);

    return    query.exec();
}
bool Role::supprimer_role(QString poste)
{
    QSqlQuery query;
    query.prepare("DELETE * FROM AGENT_ROLE WHERE poste=:poste");
    query.bindValue(":poste",poste);

    return    query.exec();
}
