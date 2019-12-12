#ifndef COMPAGNE_H
#define COMPAGNE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class compagne
{
public:
    compagne();
    compagne(int,QString,int);
    QString get_nom_comp();
    int get_tel();
    int get_id_comp();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool Modifier(int);
      QSqlQueryModel * trier() ;
private:
    QString nom_comp;
    int id_comp,tel;
};

#endif // COMPAGNE_H
