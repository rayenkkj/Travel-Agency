#ifndef ANNONCE_TYPE_H
#define ANNONCE_TYPE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Annonce_type
{
public:
    Annonce_type();
    Annonce_type(QString, QString);
    QString get_typean();
    QString get_desp();
    bool ajouter_type();
    bool supprimer_type(QString typean);
    QSqlQueryModel* afficher_type();
    bool modifier_type(QString typean, QString typean_nv);


private:
    QString typean, desp;
};

#endif // ANNONCE_TYPE_H
