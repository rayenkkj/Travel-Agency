#include "reservation.h"
#include <QDebug>
#include <QVariant>


reservation::reservation(){
    numres=0;
    destination="";
    datedep="";
    idclient=0;
    codean=0;
    datearr="";
}

reservation::reservation(int numres, QString destination, QString datedep, int idclient, int codean, QString datearr){
    this->numres=numres;
    this->destination=destination;
    this->datedep=datedep;
    this->idclient=idclient;
    this->codean=codean;
    this->datearr=datearr;

}
int reservation::get_numres(){return  numres;}
QString reservation::get_destination(){return  destination;}
QString reservation::get_datedep(){return  datedep;}
int reservation::get_idclient(){return  idclient;}
int reservation::get_codean(){return  codean;}
QString reservation::get_datearr(){return  datearr;}

bool reservation::ajouter_res(){
    QSqlQuery query;
    QString res= QString::number(numres);
    query.prepare("INSERT INTO RESERVATION(NUMRES, DESTINATION, DATE_DEP, IDCLIENT, CODEAN, DATE_ARR) "
                        "VALUES (:idreservation, :destination, :datede, :idclient, :codean, :datear) ");
    query.bindValue(":idreservation", res);
    query.bindValue(":destination", destination);
    query.bindValue(":datede", datedep);
    query.bindValue(":idclient", idclient);
    query.bindValue(":codean", codean);
    query.bindValue(":datear", datearr);


    return    query.exec();
}

QSqlQueryModel* reservation::afficher_res(){
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from RESERVATION");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDRESERVATION"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESTINATION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATEDEP"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("IDCLIENT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CODEAN"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATEARR"));

        return model;
    }

bool reservation::search(int idreservation){
    QSqlQuery query;
    QString res = QString::number(idreservation);
    query.prepare("SELECT * FROM RESERVATION WHERE NUMRES = :idreservation");
    query.bindValue(":idreservation", res);

    return  query.exec();
}


bool reservation::supprimer_res(int numres){
    QSqlQuery query;
    QString res= QString::number(numres);
    query.prepare("Delete from RESERVATION where NUMRES = :numres ");
    query.bindValue(":numres", res);
    return    query.exec();
}

bool reservation:: modifier_res(int numres){
    QSqlQuery query;
    QString res=  QString::number(numres);
    query.prepare("UPDATE RESERVATION SET DESTINATION = :destination ,DATE_DEP = :datedep, IDCLIENT = :idclient, CODEAN = :codean, DATE_ARR = :datearr  WHERE NUMRES = :numres");
    query.bindValue(":numres",res);
    query.bindValue(":destination",destination);
    query.bindValue(":datedep",datedep);
    query.bindValue(":idclient",idclient);
    query.bindValue(":codean",codean);
    query.bindValue(":datearr",datearr);

    return query.exec();
}


QSqlQueryModel* reservation::recherche_res(int numres){
    QSqlQuery query;
    QString res= QString::number(numres);
    query.prepare("select * from RESERVATION where NUMRES = :numres ");
    query.bindValue(":numres", res);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDRESERVATION"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESTINATION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATEDEP"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("IDCLIENT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CODEAN"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATEARR"));

        return model;
    }



