#include "reclamation_type.h"
#include "ui_mainwindow.h"
#include <QDebug>

Reclamation_type::Reclamation_type()
{
    typerec="";
    desp="";
}

Reclamation_type::Reclamation_type(QString typerec, QString desp){
    this->typerec=typerec;
    this->desp=desp;
}

QString Reclamation_type::get_typerec(){return  typerec;}
QString Reclamation_type::get_desp(){return desp;}

bool Reclamation_type::ajouter_type(){
    QSqlQuery query;

    query.prepare("INSERT INTO RECLAMATION_CATEG(TYPE_REC, DESCRIPTION) "
                        "VALUES (:typerec, :desp)");
    query.bindValue(":typerec", typerec);
    query.bindValue(":desp", desp);

    return    query.exec();
}

bool Reclamation_type::supprimer_type(QString typerec)
{
        QSqlQuery query;
        query.prepare("DELETE RECLAMATION_CATEG WHERE TYPE_REC = :typerec");
        query.bindValue(":typerec", typerec);
        return query.exec();
}


