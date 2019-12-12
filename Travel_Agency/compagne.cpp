#include "compagne.h"
#include <QDebug>
#include <QSqlQuery>
compagne::compagne()
{
id_comp=0;
nom_comp="";
tel=0;
}
compagne::compagne(int id_comp,QString nom_comp,int tel)
{
  this->id_comp=id_comp;
  this->nom_comp=nom_comp;
  this->tel=tel;
}
QString compagne::get_nom_comp(){return  nom_comp;}
int compagne::get_tel(){return tel;}
int compagne::get_id_comp(){return  id_comp;}

bool compagne::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_comp);
query.prepare("INSERT INTO COMPAGNE (ID_COMP, NOM_COMP, TELEPHONE) "
                    "VALUES(:id_comp, :nom_comp, :tel)");
query.bindValue(":id_comp", id_comp);
query.bindValue(":nom_comp", nom_comp);
query.bindValue(":tel", tel);

return    query.exec();
}

QSqlQueryModel * compagne::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from compagne");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_comp"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_comp "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("telephone"));
    return model;
}

bool compagne::supprimer(int idd_compagne)
{
QSqlQuery query;
QString res= QString::number(idd_compagne);
query.prepare("Delete from compagne where ID_comp= :id_comp ");
query.bindValue(":id_comp", res);
return    query.exec();
}
bool compagne::Modifier(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE compagne SET NOM_comp= :nom_comp, telephone= :tel WHERE id_comp= :id");
    qDebug() << "compagne modifiee avec succee" ;
    query.bindValue(":id",id);
    //query.bindValue(":nom",QString::fromStdString(nom));
    //query.bindValue(":prenom",QString::fromStdString(prenom)) ;
   // query.bindValue(":heures",heures);
    query.bindValue(":tel",tel);
    query.bindValue(":nom_comp",nom_comp);
    return query.exec();
}
QSqlQueryModel * compagne::trier(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from compagne order by ID_comp") ;
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_comp")) ;
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_comp")) ;
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("telephone")) ;
      return model ;

}
