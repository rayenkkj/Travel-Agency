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
    ch="";
    mv="";
    retard="";
}

Rec2::Rec2(int numrec, QString ch, QString mv, QString retard)
{
    this->numrec=numrec;
    this->ch=ch;
    this->mv=mv;
    this->retard=retard;
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
    query.prepare("UPDATE RECLAMATION SET DATEREC = :nom, DESCRIPTION = :prenom, IDCLIENT = :age WHERE NUMREC = :numrec ");
    query.bindValue(":numrec", res);
    query.bindValue(":daterec", daterec);
    query.bindValue(":description", description);
    query.bindValue(":idclient", idclient);

    return    query.exec();
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
    query.prepare("INSERT INTO TYPE_RECLAMATION(NUMREC, M_SERVICE, CH_CONDS, RETARD) "
                        "VALUES (:numrec, :m_service, :ch_conds, :retard)");
    query.bindValue(":numrec", res);
    query.bindValue(":m_service", mv);
    query.bindValue(":ch_conds", ch);
    query.bindValue(":retard", retard);

    return    query.exec();
}

QSqlQueryModel* Rec2::afficher_rec2(){
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from TYPE_RECLAMATION");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMREC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("M_SERVICE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CH_CONDS"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("RETARD"));
        return model;
    }

bool Rec2::supprimer_rec2(int cin){
    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("Delete from TYPE_RECLAMATION where NUMREC = :numrec ");
    query.bindValue(":numrec", res);
    return    query.exec();
}

bool Rec2::modifier_rec2(){
    QSqlQuery query;
    QString res= QString::number(numrec);
    query.prepare("UPDATE TYPE_RECLAMATION SET M_SERVICE = :m_service, CH_CONDS = :ch_conds, RETARD = :retard WHERE NUMREC = :numrec ");
    query.bindValue(":numrec", res);
    query.bindValue(":m_service", mv);
    query.bindValue(":ch_conds", ch);
    query.bindValue(":retard", retard);

    return    query.exec();
}


QSqlQueryModel* Rec2::recherche_rec2(int cin){
    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("select * from TYPE_RECLAMATION where NUMREC = :numrec ");
    query.bindValue(":numrec", res);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMREC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("M_SERVICE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CH_CONDS"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("RETARD"));
        return model;
    }

QSqlQueryModel* Rec2::trier_rec2()
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from TYPE_RECLAMATION order by NUMREC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMREC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("M_SERVICE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CH_CONDS"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("RETARD"));
        return model;
}
