#include "pub.h"
#include <QDebug>
#include <QSqlQuery>
pub::pub()
{
id_comp=0;
description="";
id_media=0;
}
pub::pub(int id_comp,QString description,int id_media)
{
  this->id_comp=id_comp;
  this->description=description;
  this->id_media=id_media;
}

int pub::get_id_c(){return id_comp;}
int pub::get_id_m(){return  id_media;}

bool pub::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_media);
QString res1= QString::number(id_comp);
query.prepare("INSERT INTO PUB (ID_MEDIA, ID_COMP, DESCRIPTION) "
                    "VALUES(:id_media, :id_comp, :description)");
query.bindValue(":id_media", res);
query.bindValue(":description", description);
query.bindValue(":id_comp", res1);

return    query.exec();
}

QSqlQueryModel * pub::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * FROM PUB");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_media"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_comp "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("description"));
    return model;
}

bool pub::supprimer(int id_comp, int id_media)
{
QSqlQuery query;
QString res= QString::number(id_comp);
QString res1= QString::number(id_media);
query.prepare("DELETE FROM PUB WHERE ID_COMP= :id_comp AND ID_MEDIA= :id_media ");
query.bindValue(":id_comp", res);
query.bindValue(":id_comp", res1);
return    query.exec();
}




