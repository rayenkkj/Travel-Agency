#ifndef PAIEMENT_H
#define PAIEMENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class paiement
{
public:
    paiement();
    paiement(QString,int,int,int);
    QString get_typepaie();
    int get_codepaie();
    int get_montant();
    int get_idclient();
    bool ajouter_pa();
    QSqlQueryModel* afficher_pa();
    bool supprimer_pa(int codepaie);
    bool modifier_pa(int montant,int codepaie,int idclient, QString typepaie);
private:
    QString typepaie;
    int codepaie,montant,idclient;
};

#endif // PAIEMENT_H
