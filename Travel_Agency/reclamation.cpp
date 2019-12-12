#include "reclamation.h"
#include <QDebug>


Reclamation::Reclamation(){
    numrec=0;
    description="";
    idclient=0;
    typerec="";
    daterec="";

}

Reclamation::Reclamation(int numrec, QString description, int idclient, QString typerec, QString daterec){
    this->numrec=numrec;
    this->description=description;
    this->idclient=idclient;
    this->typerec=typerec;
    this->daterec=daterec;

}

int Reclamation::get_numrec(){return  numrec;}
QString Reclamation::get_description(){return description;}
QString Reclamation::get_typerec(){return  typerec;}
int Reclamation::get_idclient(){return  idclient;}
QString Reclamation::get_daterec(){return  daterec;}



bool Reclamation::ajouter_rec(){
    QSqlQuery query;
    QString res= QString::number(numrec);
    query.prepare("INSERT INTO RECLAMATION(NUMREC, DATEREC, IDCLIENT, DESCRIPTION, TYPE_REC) "
                        "VALUES (:numrec, :daterec, :idclient, :description, :typerec)");
    query.bindValue(":numrec", res);
    query.bindValue(":daterec", daterec);
    query.bindValue(":description", description);
    query.bindValue(":idclient", idclient);
    query.bindValue(":typerec", typerec);

    return    query.exec();
}





QSqlQueryModel* Reclamation::afficher_rec(){
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from RECLAMATION");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMREC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATEREC"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("IDCLIENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPEREC"));
        return model;
    }

bool Reclamation::supprimer_rec(int numrec){
    QSqlQuery query;
    QString res= QString::number(numrec);
    query.prepare("Delete from RECLAMATION where NUMREC = :numrec ");
    query.bindValue(":numrec", res);
    return    query.exec();
}

bool Reclamation::modifier_rec(int numrec){
    QSqlQuery query;
    QString res= QString::number(numrec);
    query.prepare("UPDATE RECLAMATION SET DATEREC = :daterec, DESCRIPTION = :description, IDCLIENT = :idclient, TYPE_REC = :typerec WHERE NUMREC = :numrec ");
    query.bindValue(":numrec", res);
    query.bindValue(":daterec", daterec);
    query.bindValue(":description", description);
    query.bindValue(":idclient", idclient);
    query.bindValue(":typerec", typerec);

    return    query.exec();
}



QSqlQueryModel* Reclamation::recherche_rec(int cin){
    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("SELECT * FROM RECLAMATION WHERE IDCLIENT = :idclient ");
    query.bindValue(":idclient", res);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMREC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATEREC"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("IDCLIENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPEREC"));
        return model;
    }

QSqlQueryModel* Reclamation::trier_rec()
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from RECLAMATION order by NUMREC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMREC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATEREC"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("IDCLIENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPEREC"));
        return model;
}

QSqlQueryModel* Reclamation::trier_desc_rec()
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from RECLAMATION order by NUMREC desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMREC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATEREC"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("IDCLIENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPEREC"));
        return model;
}





