#include "departement.h"
#include <QDebug>

departement::departement(){
    iddepartement="";
    nomdep="";
    typedep="";
    nbagent=0;
}

departement:: departement(QString iddepartement,QString nomdep,QString typedep,int nbagent ){
    this->iddepartement=iddepartement;
    this->nomdep=nomdep;
    this->typedep=typedep;
    this->nbagent=nbagent;
}

QString departement:: get_iddepartement(){return  iddepartement;}
QString departement::get_nomdep(){return nomdep;}
QString departement::get_typedep(){return  typedep;}
int departement :: get_nbagent(){return nbagent;}


bool departement::ajouter_dep(){
    QSqlQuery query;
    QString res= QString::number(nbagent);
    query.prepare("INSERT INTO DEPARTEMENT(ID_DEPARTEMENT , NOM_DEP , TYPE_DEP, NB_AGENT)"
                        "VALUES (:iddepartement, :nomdep, :typedep, :nbagent)");
    query.bindValue(":iddepartement", iddepartement);
    query.bindValue(":nomdep", nomdep);
    query.bindValue(":typedep", typedep);
    query.bindValue(":nbagent", res);
    return    query.exec();
}

QSqlQueryModel* departement::afficher_dep(){
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from DEPARTEMENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("iddepartement"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomdep"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("typedep"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nbagent"));
        return model;
    }

bool departement::supprimer_dep(QString iddepartement){
    QSqlQuery query;
    query.prepare("DELETE FROM DEPARTEMENT WHERE ID_DEPARTEMENT = :iddepartement ");
    query.bindValue(":iddepartement", iddepartement);
    return    query.exec();
}
bool departement::modifier_dep(QString iddepartement)
{
    QSqlQuery query;
    query.prepare ("UPDATE DEPARTEMENT set NOM_DEP= :nomdep, TYPE_DEP= :typedep , NB_AGENT= :nbagent  where ID_DEPARTEMENT= :iddepartement");
    query.bindValue(":iddepartement", iddepartement);
    query.bindValue(":nomdep", nomdep);
    query.bindValue(":typedep", typedep);
    query.bindValue(":nbagent", nbagent);
    return query.exec();
}

QSqlQueryModel* departement ::rechercherdep(QString iddepartement){
    QSqlQuery query;
    query.prepare("SELECT * FROM DEPARTEMENT WHERE ID_DEPARTEMENT = :iddepartement ");
    query.bindValue(":iddepartement", iddepartement);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_DEPARTEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_DEP"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_DEP"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_AGENT"));
        return model;
    }
QSqlQueryModel* departement::trier_rec3()
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from DEPARTEMENT order by ID_DEPARTEMENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_DEPARTEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMDEP"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPEDEP"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NBAGENT"));
        return model;
}
