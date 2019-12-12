#include "reclamation.h"
#include <QDebug>


Rec::Rec(){
    numrec=0;
    idclient=0;
    daterec="";
    description="";
}

Rec::Rec(int numrec, int idclient, QString daterec, QString description){
    this->numrec=numrec;
    this->idclient=idclient;
    this->daterec=daterec;
    this->description=description;
}

Rec2::Rec2()
{
    numrec=0;
    des="";
}

Rec2::Rec2(int numrec, QString des)
{
    this->numrec=numrec;
    this->des=des;
}

QString Rec::get_daterec(){return  daterec;}
QString Rec::get_description(){return description;}
int Rec::get_numrec(){return  numrec;}
int Rec::get_idclient(){return  idclient;}

bool Rec::ajouter_rec(){
    QSqlQuery query;
    QString res= QString::number(numrec);
    query.prepare("INSERT INTO RECLAMATION(NUMREC, DATEREC, DESCRIPTION, IDCLIENT) "
                        "VALUES (:numrec, :daterec, :description, :idclient)");
    query.bindValue(":numrec", res);
    query.bindValue(":daterec", daterec);
    query.bindValue(":description", description);
    query.bindValue(":idclient", idclient);

    return    query.exec();
}


QSqlQueryModel* Rec::afficher_rec(){
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from RECLAMATION");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMREC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATEREC"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("IDCLIENT"));
        return model;
    }

bool Rec::supprimer_rec(int cin){
    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("Delete from RECLAMATION where NUMREC = :numrec ");
    query.bindValue(":numrec", res);
    return    query.exec();
}

bool Rec::modifier_rec(){
    QSqlQuery query;
    QString res= QString::number(numrec);
    query.prepare("UPDATE RECLAMATION SET DATEREC = :daterec, DESCRIPTION = :description, IDCLIENT = :idclient WHERE NUMREC = :numrec ");
    query.bindValue(":numrec", res);
    query.bindValue(":daterec", daterec);
    query.bindValue(":description", description);
    query.bindValue(":idclient", idclient);

    return    query.exec();
}

int Rec::test(int res)
{
    QSqlQuery query;
    res=query.prepare("SELECT COUNT(*) FROM RECLAMATION");
    return  res;
}

QSqlQueryModel* Rec::recherche_rec(int cin){
    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("select * from RECLAMATION where NUMREC = :numrec ");
    query.bindValue(":numrec", res);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMREC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATEREC"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("IDCLIENT"));
        return model;
    }

QSqlQueryModel* Rec::trier_rec()
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from RECLAMATION order by NUMREC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMREC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATEREC"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("IDCLIENT"));
        return model;
}



bool Rec2::ajouter_rec2(){
    QSqlQuery query;
    QString res= QString::number(numrec);
    query.prepare("INSERT INTO RECLAMATION_CATEG(TYPE_REC, DESCRIPTION) "
                        "VALUES (:type_rec, :description)");
    query.bindValue(":type_rec", res);
    query.bindValue(":description", des);

    return    query.exec();
}

QSqlQueryModel* Rec2::afficher_rec2(){
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from RECLAMATION_CATEG");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE_REC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));
        return model;
    }

bool Rec2::supprimer_rec2(int cin){
    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("Delete from RECLAMATION_CATEG where TYPE_REC = :type_rec ");
    query.bindValue(":type_rec", res);
    return    query.exec();
}

bool Rec2::modifier_rec2(){
    QSqlQuery query;
    QString res= QString::number(numrec);
    query.prepare("UPDATE RECLAMATION_CATEG SET DESCRIPTION = :description WHERE TYPE_REC = :type_rec ");
    query.bindValue(":type_rec", res);
    query.bindValue(":description", des);

    return    query.exec();
}


QSqlQueryModel* Rec2::recherche_rec2(int cin){
    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("select * from RECLAMATION_CATEG where TYPE_REC = :type_rec ");
    query.bindValue(":type_rec", res);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE_REC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));
        return model;
    }

QSqlQueryModel* Rec2::trier_rec2()
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from RECLAMATION_CATEG order by TYPE_REC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE_REC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));
        return model;
}


bool Rec::search(int cin){
    QSqlQuery query;
    QString res = QString::number(cin);
    query.prepare("SELECT * FROM RECLAMATION WHERE NUMREC = :numrec");
    query.bindValue(":numrec", res);

    return  query.exec();
}


QSqlQueryModel* Rec::recherche_affect(int cin1,int cin2){
    QSqlQuery query;
    QString res= QString::number(cin1);
    query.prepare("select * from RECLAMATION,RECLAMATION_CATEG where NUMREC = :numrec AND TYPE_REC = :type_rec");
    query.bindValue(":numrec", res);
    //QSqlQuery query1;
    QString res1= QString::number(cin2);
    //query1.prepare("select * from RECLAMATION_CATEG where TYPE_REC = :type_rec ");
    query.bindValue(":type_rec", res1);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    //model->setQuery(query1);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMREC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATEREC"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("IDCLIENT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_REC"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DESCRIPTION"));
        return model;
    }
