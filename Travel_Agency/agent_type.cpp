#include "agent_type.h"
#include "ui_mainwindow.h"
#include <QDebug>

Agent_type::Agent_type()
{
    poste="";
    desp="";
}


Agent_type::Agent_type(QString poste, QString desp){
    this->poste=poste;
    this->desp=desp;
}

QString Agent_type::get_poste(){return  poste;}
QString Agent_type::get_desp(){return desp;}

bool Agent_type::ajouter_type(){
    QSqlQuery query;

    query.prepare("INSERT INTO AGENT_ROLE(POSTE, DESCRIPTION) "
                        "VALUES (:poste, :desp)");
    query.bindValue(":poste", poste);
    query.bindValue(":desp", desp);

    return    query.exec();
}

bool Agent_type::supprimer_type(QString poste){
    QSqlQuery query;
        query.prepare("Delete from AGENT_ROLE where POSTE = :psote");
        query.bindValue(":typean", poste);
        return query.exec();
}


