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

/*QSqlQuery query;
query.prepare("INSERT INTO AGENT(numagent , nomagent , prenomagent, age , mdp, adresse)"
                    "VALUES (:numagent, :nomagent, :prenomagent, :age, :mdp, :adresse)");
query.bindValue(":numagent", numagent);
query.bindValue(":nomagent", nomagent);
query.bindValue(":prenomagent", prenomagent);
query.bindValue(":age", age);
query.bindValue(":mdp",mdp);
query.bindValue(":adresse",adresse);

return    query.exec();*/
bool departement::ajouter_dep(){
    QSqlQuery query;
    QString res= QString::number(nbagent);
    query.prepare("INSERT INTO DEPARTEMENT(IDDEPARTEMENT , NOMDEP , TYPEDEP, NBAGENT)"
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
    query.prepare("Delete from DEPARTEMENT where iddepartement = :iddepartement ");
    query.bindValue(":iddepartement", iddepartement);
    return    query.exec();
}
bool departement::modifier_dep(QString iddepartement)
{
    QSqlQuery query;
    query.prepare ("UPDATE DEPARTEMENT set nomdep= :nomdep, typedep= :typedep , nbagent= :nbagent  where iddepartement= :iddepartement");
    query.bindValue(":iddepartement", iddepartement);
    query.bindValue(":nomdep", nomdep);
    query.bindValue(":typedep", typedep);
    query.bindValue(":nbagent", nbagent);
    return query.exec();
}
/*QSqlQueryModel* Agent::affichertrie_ag (){
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from AGENT order by NUMAGENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numagent"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomagent"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenomagent"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("mdp"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
        return model;
    }*/
QSqlQueryModel* departement ::rechercherdep(QString iddepartement){
    QSqlQuery query;
    query.prepare("select * from DEPARTEMENT where iddepartement = :iddepartement ");
    query.bindValue(":iddepartement", iddepartement);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDDEPARTEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMDEP"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPEDEP"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NBAGENT"));
        return model;
    }
