#include "agent.h"
#include <QDebug>

Agent::Agent(){
    numagent="";
    age=0;
    mdp="";
    adresse="";
    nomagent="";
    prenomagent="";
}

Agent:: Agent(QString adresse, QString mdp,QString numagent,int age,QString prenomagent,QString nomagent,QString poste){
    this->numagent=numagent;
    this->age=age;
    this->adresse=adresse;
    this->nomagent=nomagent;
    this->prenomagent=prenomagent;
    this->mdp=mdp;
    this->poste=poste;
}

QString Agent:: get_numagent(){return  numagent;}
QString Agent::get_nomagent(){return nomagent;}
int Agent::get_age(){return  age;}
QString Agent::get_prenomagent(){return  prenomagent;}
QString Agent :: get_mdp(){return mdp;}
QString Agent :: get_adresse(){return adresse;}
QString Agent :: get_poste(){return poste;}


bool Agent::ajouter_ag(){
    QSqlQuery query;
    query.prepare("INSERT INTO AGENT(numagent , nomagent , prenomagent, age , mdp, adresse ,poste)"
                        "VALUES (:numagent, :nomagent, :prenomagent, :age, :mdp, :adresse,:poste)");
    query.bindValue(":numagent", numagent);
    query.bindValue(":nomagent", nomagent);
    query.bindValue(":prenomagent", prenomagent);
    query.bindValue(":age", age);
    query.bindValue(":mdp",mdp);
    query.bindValue(":adresse",adresse);
    query.bindValue(":poste",poste);

    return    query.exec();
}

QSqlQueryModel* Agent::afficher_ag(){
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from AGENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numagent"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomagent"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenomagent"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mdp"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("poste"));
        return model;
    }

bool Agent::supprimer_ag(QString numagent){
    QSqlQuery query;
    query.prepare("Delete from AGENT where  numagent=:numagent ");
    query.bindValue(":numagent", numagent);
    return    query.exec();

}
bool Agent::modifier_ag(QString numagent)
{
    QSqlQuery query;
    QString res= QString:: number(age);
    query.prepare ("UPDATE AGENT set nomagent= :nomagent ,prenomagent= :prenomagent, age= :age , mdp= :mdp ,adresse= :adresse, poste=:poste where numagent= :numagent");
    query.bindValue(":numagent", numagent);
    query.bindValue(":nomagent", nomagent);
    query.bindValue(":prenomagent", prenomagent);
    query.bindValue(":age", res);
    query.bindValue(":mdp", mdp);
    query.bindValue(":adresse", adresse);
    query.bindValue(":poste", poste);
    return query.exec();
}
QSqlQueryModel* Agent::affichertrie_ag (){
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from AGENT where poste= :poste");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numagent"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomagent"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenomagent"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mdp"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("poste"));
        return model;
    }
/*QSqlQueryModel * Agent ::rechercher(QString numagent)
{
    QSqlQueryModel *model=new QSqlQueryModel();
       model->setQuery("select * from AGENT where numagent= :numagent");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("numagent"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomagent"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenomagent"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("mdp"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
     return(model);
}*/
QSqlQueryModel* Agent::rechercher(QString numagent){
    QSqlQuery query;
    query.prepare("select * from AGENT where numagent = :numagent ");
    query.bindValue(":numagent", numagent);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numagent"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mdp"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("poste"));
    return model;
    }
QSqlQueryModel* Agent::trier_rec2(QString numagent)
{
    QSqlQuery query;

    query.prepare("select * from Agent where numagent=:numagent");
    query.bindValue(":poste",numagent);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMAGENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MDP"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("POSTE"));
        return model;
}
