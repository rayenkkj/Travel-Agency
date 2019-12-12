#ifndef PUB_H
#define PUB_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class pub
{public:
    pub();
    pub(int,QString,int);
   // QString get_nom();
    int get_id_c();
    int get_id_m();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int, int);
    bool Modifier(int);
    QSqlQueryModel * trier() ;

     // QSqlQueryModel * verifier(QString) ;
   // bool exist(QString nom,int nb_abonnees) ;
private:
    QString description ;
    int id_media,id_comp;

};

#endif // PUB_H
