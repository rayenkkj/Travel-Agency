#ifndef ANNONCE_H
#define ANNONCE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Annonce
{
public:
    Annonce();
    Annonce(int, int, QString, QString, int, int);

    int get_codean();
    int get_nbplace();
    QString get_pays();
    QString get_typean();
    int get_idcompagne();
    int get_prix();

    bool ajouter_an();
    QSqlQueryModel* afficher_an();
    QSqlQueryModel* afficher_asc();
    QSqlQueryModel* afficher_desc();
    QSqlQueryModel* afficher_pays(QString pays);
    bool supprimer_an(int codean);
    bool modifier_an(int codean);
    bool search(int codean);


private:
    QString pays,typean;
    int codean,nbplace,idcompagne,prix;

};

#endif // ANNONCE_H
