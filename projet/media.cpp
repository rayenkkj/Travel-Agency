#include "media.h"
#include <QDebug>

MEDIA::MEDIA()
{
    ID_MEDIA=0;
    NOM_MEDIA="";
}

MEDIA::MEDIA(int i,std::string n)
{
    ID_MEDIA=i;
    NOM_MEDIA=n;
}


int MEDIA::get_ID_MEDIA()
{
    return ID_MEDIA;
}

std::string MEDIA::get_NOM_MEDIA()
{
    return NOM_MEDIA;
}

int MEDIA::get_NB_FOLLOWERS()
{return NB_FOLLOWERS;}

bool MEDIA::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO MEDIA (ID_MEDIA,NOM_MEDIA,NB_FOLLOWERS)""VALUES(:ID_MEDIA,:NOM_MEDIA,:NB_FOLLOWERS)");
    query.bindValue(":ID_MEDIA",ID_MEDIA);
    query.bindValue(":NOM_MEDIA",QString::fromStdString(NOM_MEDIA));
    query.bindValue(":NB_FOLLOWERS",NB_FOLLOWERS);
    return query.exec();
}

QSqlQueryModel * MEDIA::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlDatabase db = QSqlDatabase::database();
    //UPDATE tab_MEDIA SET NB_FOLLOWERSs = NB_FOLLOWERSs + 500 WHERE (SELECT ID_MEDIA FROM MEDIA WHERE Checked='N' ORDER BY ID_MEDIA LIMIT 1);
    model->setQuery("select ID_MEDIA,NOM_MEDIA,NB_FOLLOWERS FROM MEDIA",db);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_MEDIA"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_MEDIA"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NB_FOLLOWERS"));
    return model;
}

bool MEDIA::supprimer(int ID_MEDIA)
{
    QSqlQuery query;
    query.prepare("DELETE FROM MEDIA WHERE ID_MEDIA= :ID_MEDIA");
    query.bindValue(":ID_MEDIA",ID_MEDIA);
    return query.exec();
}

bool MEDIA::modifier(int ID_MEDIA)
{
    QSqlQuery query;
    query.prepare("UPDATE MEDIA SET NB_FOLLOWERS= :NB_FOLLOWERS, NOM_MEDIA= :NOM_MEDIA WHERE ID_MEDIA= :ID_MEDIA");
    qDebug() << "MEDIA modifier avec succee" ;
    query.bindValue(":ID_MEDIA",ID_MEDIA);
    query.bindValue(":NOM_MEDIA",QString::fromStdString(NOM_MEDIA));
     query.bindValue(":NB_FOLLOWERS",NB_FOLLOWERS);
    return query.exec();
}
