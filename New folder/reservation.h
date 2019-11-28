#ifndef RESERVATION_H
#define RESERVATION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class reservation
{
public:
    reservation();
    reservation(int,QString,QString,QString,int,int);
    int get_idreservation();
    QString get_destination();
    QString get_datede();
    QString get_datear();
    int get_idclient();
    int get_codean();

    bool ajouter_res();
    QSqlQueryModel* afficher_res();
    bool supprimer_res(int coderes);
    bool modifier_res(int idreservation,QString destination,QString datede,QString datear,int idclient,int codean );
private:
    QString destination,datede,datear;
    int idreservation,idclient,codean;

};

#endif // RESERVATION_H

