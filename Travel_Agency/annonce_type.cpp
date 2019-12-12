#include "annonce_type.h"
#include "ui_mainwindow.h"
#include <QDebug>

Annonce_type::Annonce_type(){
    typean="";
    desp="";
}

Annonce_type::Annonce_type(QString typean, QString desp){
    this->typean=typean;
    this->desp=desp;
}

QString Annonce_type::get_typean(){return  typean;}
QString Annonce_type::get_desp(){return desp;}

bool Annonce_type::ajouter_type(){
    QSqlQuery query;

    query.prepare("INSERT INTO ANNONCE_TYPE(TYPE_AN, DESCRIPTION) "
                        "VALUES (:typean, :desp)");
    query.bindValue(":typean", typean);
    query.bindValue(":desp", desp);

    return    query.exec();
}

bool Annonce_type::supprimer_type(QString typean){
        QSqlQuery query;
        query.prepare("Delete from ANNONCE_TYPE where TYPE_AN = :typean");
        query.bindValue(":typean", typean);
        return query.exec();
}


bool Annonce_type::modifier_type(QString typean, QString typean_nv){
    QSqlQuery query;
        query.prepare("UPDATE ANNONCE_TYPE set TYPE_AN= :typean_nv, DESCRIPTION= :desp WHERE TYPE_AN= :typean ");
        query.bindValue("typean_nv", typean_nv);
        query.bindValue("typean", typean);
        query.bindValue(":desp", desp);
        return    query.exec();
}

QSqlQueryModel* Annonce_type::afficher_type(){
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from ANNONCE_TYPE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Type d'annonce"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));

        return model;
    }

