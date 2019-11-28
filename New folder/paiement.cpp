#include "paiement.h"
#include <QDebug>
#include <QVariant>

paiement::paiement(){
    codepaie=0;
    montant=0;
    idclient=0;
    typepaie="";
}

paiement::paiement(QString typepaie, int montant, int idclient, int codepaie){
    this->typepaie=typepaie;
    this->montant=montant;
    this->codepaie=codepaie;
    this->idclient=idclient;

}

QString paiement::get_typepaie(){return  typepaie;}
int paiement::get_codepaie(){return  codepaie;}
int paiement::get_montant(){return  montant;}
int paiement::get_idclient(){return  idclient;}

bool paiement::ajouter_pa(){
    QSqlQuery query;
    QString res= QString::number(codepaie);
    query.prepare("INSERT INTO PAIEMENT(TYPEPAIE, MONTANT,CODEPAIE, IDCLIENT) "
                        "VALUES (:typepaie, :montant, :codepaie, :idclient) ");
    query.bindValue(":typepaie", typepaie);
    query.bindValue(":montant", montant);
    query.bindValue(":codepaie", res);
    query.bindValue(":idclient", idclient);

    return    query.exec();
}

QSqlQueryModel* paiement::afficher_pa(){
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from PAIEMENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPEPAIE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("MONTANT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CODEPAIE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("IDCLIENT"));

        return model;
    }


bool paiement::supprimer_pa(int codepaie){
    QSqlQuery query;
    QString res= QString::number(codepaie);
    query.prepare("Delete from PAIEMENT where CODEPAIE = :codepaie ");
    query.bindValue(":codepaie", res);
    return    query.exec();
}

bool paiement:: modifier_pa(int codepaie,int montant,int idclient,QString typepaie){
    QSqlQuery query;
    QString res=  QString::number(codepaie);
    query.prepare("UPDATE paiement SET TYPEPAIE = :typepaie WHERE  CODEPAIE = :codepaie  ");
    query.bindValue(":typepaie",typepaie);
    query.bindValue(":codepaie",res);
    query.bindValue(":montant",montant);
    query.bindValue(":idclient",idclient);



    bool result=query.exec();
    return result;
}

