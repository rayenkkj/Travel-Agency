#ifndef RECLAMATION_H
#define RECLAMATION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Reclamation
{
public:
    Reclamation();
    Reclamation(int, QString, int, QString, QString);

    int get_numrec();
    QString get_description();
    int get_idclient();
    QString get_typerec();
    QString get_daterec();

    bool ajouter_rec();
    bool modifier_rec(int numrec);
    QSqlQueryModel* afficher_rec();
    bool supprimer_rec(int);
    QSqlQueryModel* recherche_rec(int idclient);
    QSqlQueryModel* trier_rec();
    QSqlQueryModel* trier_desc_rec();

private:
    QString daterec,description,typerec;
    int numrec,idclient;
};


#endif // RECLAMATION_H
