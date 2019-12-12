#include "media.h"
#include <QDebug>
#include <QSqlQuery>

media::media()
{
id=0;
nom="";
nb_abonnees=0;
}
media::media(int id,QString nom,int nb_abonnees)
{
  this->id=id;
  this->nom=nom;
  this->nb_abonnees=nb_abonnees;
}
QString media::get_nom(){return  nom;}
int media::get_nb_abonnees(){return nb_abonnees;}
int media::get_id(){return  id;}

bool media::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO media (ID_MEDIA, NOM_MEDIA, NB_FOLLOWERS) "
                    "VALUES(:id, :nom, :nb_abonnees)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":nb_abonnees", nb_abonnees);

return    query.exec();
}

QSqlQueryModel * media::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from media");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_MEDIA"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_MEDIA "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NB_FOLLOWERS"));
    return model;
}

bool media::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from media where ID_MEDIA = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool media::Modifier(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE media SET NOM_media= :nom, NB_followers= :nb_abonnees WHERE id_media= :id");
    qDebug() << "media modifiee avec succee" ;
    query.bindValue(":id",id);
    //query.bindValue(":nom",QString::fromStdString(nom));
    //query.bindValue(":prenom",QString::fromStdString(prenom)) ;
   // query.bindValue(":heures",heures);
    query.bindValue(":nb_abonnees",nb_abonnees);
    query.bindValue(":nom",nom);
    return query.exec();
}


QSqlQueryModel * media::trier(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from media order by NB_followers") ;
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_media")) ;
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_media")) ;
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("nb_followers")) ;
      return model ;

}

bool media::exist(QString nom,int nb_abonnees) {
    QSqlQuery querry;
    querry.prepare("UPDATE media SET NB_FOLLOWERS=NB_FOLLOWERS+:nb_abonnees where NOM_MEDIA=:nom") ;
    querry.bindValue(":nb_abonnees",nb_abonnees);
    querry.bindValue(":nom",nom);
    return querry.exec() ;
}

