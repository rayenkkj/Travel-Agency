#ifndef PROMOTION_H
#define PROMOTION_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Client_type
{public:
    Client_type();
    Client_type(QString,QString);
    QString get_type();
    QString get_desp();
    bool supprimer_type(QString type);
    bool ajouter_type();

private:
    QString desp,type;
};


#endif // PROMOTION_H
