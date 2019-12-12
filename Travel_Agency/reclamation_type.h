#ifndef RECLAMATION_TYPE_H
#define RECLAMATION_TYPE_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Reclamation_type
{
public:
    Reclamation_type();
    Reclamation_type(QString, QString);
    QString get_typerec();
    QString get_desp();
    bool ajouter_type();
    bool supprimer_type(QString typerec);

private:
    QString typerec, desp;
};

#endif // RECLAMATION_TYPE_H

