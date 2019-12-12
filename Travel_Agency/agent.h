#ifndef AGENT_H
#define AGENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Agent
{
public:
    Agent();
    Agent(QString, QString, QString, int, int, QString, QString, QString);
    QString get_numagent();
    QString get_nomagent();
    QString get_prenomagent();
    int get_age();
    int get_iddepatement();
    QString get_poste();
    QString get_adresse();
    QString get_mdp();

    bool ajouter_ag();
    QSqlQueryModel* afficher_ag();
    bool supprimer_ag(QString numagent);
    bool modifier_ag(QString numagent);
    QSqlQueryModel * affichertrie_ag();
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * trier_rec2();

private:
    QString numagent,nomagent,prenomagent,mdp,adresse,poste;
    int age,iddepartement;
};


#endif // ANNONCE_H
