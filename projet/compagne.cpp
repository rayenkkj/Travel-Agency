#include "compagne.h"
COMPAGNE::COMPAGNE(){
     id_comp=0;
     telephone=0;

     nom_comp="";

}
COMPAGNE::COMPAGNE(int n,QString d,int i){
     telephone=n;
     id_comp=i;
     nom_comp=d;

}
int COMPAGNE::get_telephone(){return telephone;}
int COMPAGNE::get_id_comp(){return id_comp;}
QString COMPAGNE::get_nom_comp(){return nom_comp;}

COMPAGNE::~COMPAGNE()
{

}
bool COMPAGNE::ajouter_comp()
{
    QSqlQuery query;
    QString id_comp2=QString::number(id_comp);
    QString telephone2=QString::number(telephone);
    query.prepare("INSERT INTO COMPAGNE (telephone,id_comp,nom_comp)""VALUES(:telephone,:id_comp,:nom_comp)");
    query.bindValue(":id_comp",id_comp2);
    query.bindValue(":telephone",telephone2);
    query.bindValue(":nom_comp",nom_comp);

    return query.exec();
}
QSqlQueryModel * COMPAGNE::afficher_comp()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlDatabase db = QSqlDatabase::database();
    model->setQuery("select * FROM COMPAGNE",db);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_comp"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_COMPAGNE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("telephone"));
    return model;
}
bool COMPAGNE::supprimer_comp(int id_comp)
{
    QSqlQuery query;
    QString id_comp2=QString::number(id_comp);
    query.prepare("DELETE FROM COMPAGNE WHERE id_comp= :id_comp");
    query.bindValue(":id_comp",id_comp2);
    return query.exec();
}
bool COMPAGNE::modifier_comp(int id_comp)
{
    QSqlQuery query;
    query.prepare("UPDATE COMPAGNE SET nom_comp= :nom_comp, telephone= :telephone WHERE id_comp= :id_comp");
    query.bindValue(":id_comp",id_comp);
    query.bindValue(":nom_comp",nom_comp);
    query.bindValue(":telephone",telephone);
    return query.exec();
}

