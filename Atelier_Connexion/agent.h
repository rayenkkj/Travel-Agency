#ifndef AGENT_H
#define AGENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
/*
class Annonce
{
public:
    Annonce();
    Annonce(int, int, QString, QString);
    int get_codean();
    int get_nbplace();
    QString get_pays();
    QString get_typean();
    bool ajouter_an();
    QSqlQueryModel* afficher_an();
    bool supprimer_an(int codean);
private:
    QString pays,typean;
    int codean,nbplace;
};*/
class Agent
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
    QSqlQueryModel * rechercher(QString);

private:
    QString numagent,nomagent,prenomagent,mdp,adresse;
    int age;
};


#endif // ANNONCE_H
