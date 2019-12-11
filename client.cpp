#include "client.h"
#include <QDebug>
#include <QString>
Client::Client()
{
idclient=0;
nom="";
prenom="";
adresse="";
age=0;
type_c="";
}
Client::Client(int idclient,QString nom,QString prenom,int age,QString type_c,QString adresse )
{   this->idclient=idclient;
  this->nom=nom;
  this->prenom=prenom;
  this->adresse=adresse;
  this->age=age;
   this->type_c=type_c;
}
int Client ::get_idclient()
{

    return  idclient;
}
QString Client ::get_nom()
{

    return nom;
}
QString Client ::get_prenom()
{

    return  prenom;
}


QString Client ::get_adresse()
{

    return  adresse;

}int Client ::get_age()
{
    return  age;
}
QString Client ::get_type()
{
    return  type_c;
}



bool Client::ajouter_client()
{
    QSqlQuery query;
    QString res= QString::number(idclient);
    QString res1= QString::number(age);

query.prepare("INSERT INTO CLIENT (IDCLIENT, NOM, PRENOM,AGE,TYPE_C,ADRESSE) "
                    "VALUES ( :id, :nom, :prenom, :age, :type_c, :adresse)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":age", res1);
query.bindValue(":adresse", adresse);
query.bindValue(":type_c", type_c);
return    query.exec();
}

QSqlQueryModel * Client::afficher_client()
{QSqlQueryModel * model= new QSqlQueryModel();
    QSqlDatabase db = QSqlDatabase::database();

    model->setQuery("select * from client");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDCLIENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_C"));

        return model;
}

bool Client::supprimer_client(int NU)
{
QSqlQuery query;
 QString res= QString::number(NU);

query.prepare("Delete from client where IDCLIENT = :id");
query.bindValue(":id", res);
return    query.exec();
}


bool Client::modifier_client(int id){
    QSqlQuery query;
    QString res= QString::number(id);

        query.prepare("UPDATE CLIENT set IDCLIENT= :idclient, NOM= :nom, PRENOM= :prenom, AGE= :age, TYPE_C= :type_c, ADRESSE= :adresse WHERE IDCLIENT= :idclient ");
        query.bindValue(":idclient", res);
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom );
        query.bindValue(":age", age);
        query.bindValue(":type_c", type_c);
        query.bindValue(":adresse", adresse);

        return    query.exec();
}

QSqlQueryModel* Client::afficher_idclient(int idclient){
    QSqlQuery query;
    query.prepare("select * from CLIENT where IDCLIENT = :idclient");
    query.bindValue(":idclient", idclient);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("type_c"));
        return model;
    }

QSqlQueryModel  *  Client ::afficher_trie()
   { QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("select * from client order by IDCLIENT");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("type_c"));

           return model;

   }
