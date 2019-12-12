#include "agent.h"
#include <QDebug>

Agent::Agent(){
    numagent="";
    nomagent="";
    prenomagent="";
    age=0;
    iddepartement=0;
    poste="";
    adresse="";
    mdp="";


}

Agent::Agent(QString numagent, QString nomagent, QString prenomagent, int age, int iddepartement,QString poste, QString adresse, QString mdp)
{
    this->numagent=numagent;
    this->nomagent=nomagent;
    this->prenomagent=prenomagent;
    this->age=age;
    this->iddepartement=iddepartement;
    this->poste=poste;
    this->adresse=adresse;
    this->mdp=mdp;
}

QString Agent:: get_numagent(){return  numagent;}
QString Agent::get_nomagent(){return nomagent;}
QString Agent::get_prenomagent(){return  prenomagent;}
int Agent::get_age(){return  age;}
int Agent::get_iddepatement(){return iddepartement;}
QString Agent::get_poste(){return poste;}
QString Agent :: get_adresse(){return adresse;}
QString Agent :: get_mdp(){return mdp;}


bool Agent::ajouter_ag(){
    QSqlQuery query;
    query.prepare("INSERT INTO AGENT(IDAGENT, NOM, PRENOM, AGE, ID_DEPARTEMENT, POSTE, ADRESSE, MDP)"
                        "VALUES (:numagent, :nomagent, :prenomagent, :age, :iddepartement, :poste, :adresse, :mdp)");
    query.bindValue(":numagent", numagent);
    query.bindValue(":nomagent", nomagent);
    query.bindValue(":prenomagent", prenomagent);
    query.bindValue(":age", age);
    query.bindValue(":iddepartement", iddepartement);
    query.bindValue(":poste",poste);
    query.bindValue(":adresse",adresse);
    query.bindValue(":mdp",mdp);


    return    query.exec();
}

QSqlQueryModel* Agent::afficher_ag(){
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from AGENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numagent"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomagent"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenomagent"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("id departement"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("poste"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("mdp"));

        return model;
    }

bool Agent::supprimer_ag(QString numagent){
    QSqlQuery query;
    query.prepare("Delete from AGENT where  IDAGENT=:numagent ");
    query.bindValue(":numagent", numagent);
    return    query.exec();

}
bool Agent::modifier_ag(QString numagent)
{
    QSqlQuery query;
    QString res= QString:: number(age);
    query.prepare ("UPDATE AGENT set NOM= :nomagent ,PRENOM= :prenomagent, AGE= :age , ID_DEPARTEMENT= :iddepartement, POSTE= :poste, adresse= :adresse, mdp= :mdp where IDAGENT= :numagent");
    query.bindValue(":numagent", numagent);
    query.bindValue(":nomagent", nomagent);
    query.bindValue(":prenomagent", prenomagent);
    query.bindValue(":age", res);
    query.bindValue(":iddepartement", iddepartement);
    query.bindValue(":poste", poste);
    query.bindValue(":adresse", adresse);
    query.bindValue(":mdp", mdp);
    return query.exec();
}
QSqlQueryModel* Agent::affichertrie_ag (){
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from AGENT order by IDAGENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numagent"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomagent"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenomagent"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("id departement"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("poste"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("mdp"));
        return model;
    }

QSqlQueryModel* Agent::rechercher(QString numagent){
    QSqlQuery query;
    query.prepare("select * from AGENT where IDAGENT = :numagent ");
    query.bindValue(":numagent", numagent);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numagent"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomagent"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenomagent"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("id departement"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("poste"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("mdp"));
    return model;
    }
QSqlQueryModel* Agent::trier_rec2()
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from Agent order by IDAGENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numagent"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomagent"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenomagent"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("id departement"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("poste"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("mdp"));
        return model;
}
