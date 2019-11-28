#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
/*class Agent
{
public:
    Agent();
    Agent( QString, QString ,QString,int,QString, QString );
    QString get_numagent();
    QString get_nomagent();
    QString get_prenomagent();
    int get_age();
    QString get_mdp();
    QString get_adresse();
    bool ajouter_ag();
    QSqlQueryModel* afficher_ag();
    bool supprimer_ag(QString numagent);
    bool modifier_ag(QString numagent);
    QSqlQueryModel* affichertrie_ag();
private:
    QString numagent,nomagent,prenomagent,mdp,adresse;
    int age;
};*/

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

private:
    int nbagent;
    QString nomdep,typedep,iddepartement;



};

#endif // DEPARTEMENTH_H
