#ifndef MEDIA_H
#define MEDIA_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class media
{public:
    media();
    media(int,QString,int);
    QString get_nom();
    int get_nb_abonnees();
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool Modifier(int);
    QSqlQueryModel * trier() ;
    bool exist(QString nom,int nb_abonnees) ;
private:
    QString nom;
    int id,nb_abonnees;
};

#endif // MEDIA_H
