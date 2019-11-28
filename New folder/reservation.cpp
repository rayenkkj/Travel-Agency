#include "reservation.h"
#include <QDebug>
#include <QVariant>


reservation::reservation(){
    idreservation=0;
    destination="";
    datede="";
    datear="";
    idclient=0;
    codean=0;
}

reservation::reservation(int idreservation,QString destination,QString datede,QString datear,int idclient,int codean){
    this->idreservation=idreservation;
    this->destination=destination;
    this->datede=datede;
    this->datear=datear;
    this->idclient=idclient;
    this->codean=codean;


}
int reservation::get_idreservation(){return  idreservation;}
QString reservation::get_destination(){return  destination;}
QString reservation::get_datede(){return  datede;}
QString reservation::get_datear(){return  datear;}
int reservation::get_idclient(){return  idclient;}
int reservation::get_codean(){return  codean;}

bool reservation::ajouter_res(){
    QSqlQuery query;
    QString res= QString::number(idreservation);
    query.prepare("INSERT INTO RESERVATION(IDRESERVATION, DESTINATION, DATEDE, DATEAR, IDCLIENT, CODEAN) "
                        "VALUES (:idreservation, :destination, :datede, :datear, :idclient, :codean)");
    query.bindValue(":idreservation", res);
    query.bindValue(":destination", destination);
    query.bindValue(":datede", datede);
    query.bindValue(":datear", datear);
    query.bindValue(":idclient", idclient);
    query.bindValue(":codean", codean);


    return    query.exec();
}

QSqlQueryModel* reservation::afficher_res(){
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from RESERVATION");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDRESERVATION"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESTINATION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATEDE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEAR"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("IDCLIENT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CODEAN"));




        return model;
    }


bool reservation::supprimer_res(int idreservation){
    QSqlQuery query;
    QString res= QString::number(idreservation);
    query.prepare("Delete from RESERVATION where IDRESERVATION = :idreservation ");
    query.bindValue(":idreservation", res);
    return    query.exec();
}

bool reservation:: modifier_res(int idreservation,QString destination,QString datede,QString datear,int idclient,int codean){
    QSqlQuery query;
    QString res=  QString::number(idreservation);
    query.prepare("UPDATE Reservation SET IDRESERVATION = :idreservation ,DATEDE = :datede, DATEAR = :datear , IDCLIENT = :idclient, CODEAN = :codean WHERE DESTINATION = :destination  ");
    query.bindValue(":idreservation",res);
    query.bindValue(":destination",destination);
    query.bindValue(":datede",datede);
    query.bindValue(":datear",datear);

    query.bindValue(":idclient",idclient);
    query.bindValue(":codean",codean);



    bool result=query.exec();
    return result;
}

