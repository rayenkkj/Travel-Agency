#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class departement
{
public:
    departement();
    departement (QString,QString,QString,int);
    QString get_iddepartement();
    QString get_nomdep();
    QString get_typedep();
    int get_nbagent();
    bool ajouter_dep();
    QSqlQueryModel* afficher_dep();
    bool supprimer_dep(QString iddepartement);
    bool modifier_dep(QString iddepartement);
    QSqlQueryModel * rechercherdep(QString);
    QSqlQueryModel * trier_rec3();

private:
    int nbagent;
    QString nomdep,typedep,iddepartement;



};

#endif // DEPARTEMENTH_H
