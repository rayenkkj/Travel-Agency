#ifndef RESERVATION_H
#define RESERVATION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class reservation
{
public:
    reservation();
    reservation(int numres, QString destination, QString datedep, int idclient, int codean, QString datearr);
    int get_numres();
    QString get_destination();
    QString get_datedep();
    int get_idclient();
    int get_codean();
    QString get_datearr();


    bool ajouter_res();
    QSqlQueryModel* afficher_res();
    bool supprimer_res(int idreservation);
    bool modifier_res(int numres );
    bool search(int numres);
    QSqlQueryModel* recherche_res(int numres);


private:
    QString datedep, datearr, destination;
    int numres, idclient, codean;

};

#endif // RESERVATION_H

