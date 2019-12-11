#include "client_type.h"
#include "ui_mainwindow.h"
#include <QDebug>

Client_type::Client_type(){
    type="";
    desp="";
}

Client_type::Client_type(QString type, QString desp){
    this->type=type;
    this->desp=desp;
}

QString Client_type::get_type(){return  type;}
QString Client_type::get_desp(){return desp;}

bool Client_type::ajouter_type(){
    QSqlQuery query;

    query.prepare("INSERT INTO CLIENT_CATEGORY(TYPE_C, DESCRIPTION) "
                        "VALUES (:typec, :desp)");
    query.bindValue(":typec", type);
    query.bindValue(":desp", desp);

    return    query.exec();
}

bool Client_type::supprimer_type(QString type){
        QSqlQuery query;
        query.prepare("Delete from CLIENT_CATEGORY where TYPE_C = :type");
        query.bindValue(":type", type);
        return query.exec();
}


