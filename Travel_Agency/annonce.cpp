#include "annonce.h"
#include <QDebug>

Annonce::Annonce(){
    codean=0;
    nbplace=0;
    pays="";
    typean="";
    idcompagne=0;
    prix=0;
}

Annonce::Annonce(int codean, int nbplace, QString pays, QString typean, int idcompagne, int prix){
    this->codean=codean;
    this->nbplace=nbplace;
    this->pays=pays;
    this->typean=typean;
    this->idcompagne=idcompagne;
    this->prix=prix;
}

int Annonce::get_codean(){return  codean;}
int Annonce::get_nbplace(){return  nbplace;}
QString Annonce::get_typean(){return  typean;}
QString Annonce::get_pays(){return pays;}
int Annonce::get_idcompagne(){return  idcompagne;}
int Annonce::get_prix(){return prix;}

bool Annonce::ajouter_an(){
    QSqlQuery query;
    QString res= QString::number(codean);
    query.prepare("INSERT INTO ANNONCE(CODEAN, NB_PLACE, PAYS, ID_COMPAGNE, TYPE_AN, PRIX) "
                        "VALUES (:codean, :nbplace, :pays, :idcompagne, :typean, :prix)");
    query.bindValue(":codean", res);
    query.bindValue(":nbplace", nbplace);
    query.bindValue(":pays", pays);
    query.bindValue(":typean", typean);
    query.bindValue(":idcompagne", idcompagne);
    query.bindValue(":prix", prix);

    return query.exec();
}


QSqlQueryModel* Annonce::afficher_an(){
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from ANNONCE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code annonce"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nb place"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Destination"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Type annonce"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num compagne"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Prix en DT"));
        return model;
    }

QSqlQueryModel* Annonce::afficher_asc(){
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from ANNONCE ORDER BY PRIX");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code annonce"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nb place"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Destination"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Type annonce"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num compagne"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Prix en DT"));
        return model;
    }

QSqlQueryModel* Annonce::afficher_desc(){
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from ANNONCE ORDER BY PRIX DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code annonce"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nb place"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Destination"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Type annonce"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num compagne"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Prix en DT"));
        return model;
    }

QSqlQueryModel* Annonce::afficher_pays(QString pays){
    QSqlQuery query;
    query.prepare("select * from ANNONCE where PAYS = :pays");
    query.bindValue(":pays", pays);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code annonce"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nb place"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Destination"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Type annonce"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num compagne"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Prix en DT"));
        return model;
    }



bool Annonce::search(int codean){
    QSqlQuery query;
    QString res = QString::number(codean);
    query.prepare("SELECT CODEAN FROM ANNONCE WHERE CODEAN = :codean");
    query.bindValue(":codean", res);
    query.exec();

    if(query.size()!=codean){return false;}
    else return true;


}


bool Annonce::supprimer_an(int codean){
    QSqlQuery query;
    QString res= QString::number(codean);
    Annonce a;
        query.prepare("Delete from ANNONCE where CODEAN = :codean");
        query.bindValue(":codean", res);
        return query.exec();

}

bool Annonce::modifier_an(int codean){
    QSqlQuery query;
    QString res= QString::number(codean);
        query.prepare("UPDATE ANNONCE set CODEAN= :codean, NB_PLACE= :nbplace, PAYS= :pays, TYPE_AN= :typean, ID_COMPAGNE= :idcompagne, PRIX= :prix WHERE CODEAN= :codean ");
        query.bindValue(":codean", res);
        query.bindValue(":nbplace", nbplace);
        query.bindValue(":pays", pays);
        query.bindValue(":typean", typean);
        query.bindValue(":idcompagne", idcompagne);
        query.bindValue(":prix", prix);

        return    query.exec();
}





