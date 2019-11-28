#ifndef COMPAGNE_H
#define COMPAGNE_H
#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

class COMPAGNEData;

class COMPAGNE
{
public:
    COMPAGNE();
    COMPAGNE(int,QString,int);
    ~COMPAGNE();
    int get_telephone();
    int get_id_comp();
    QString get_nom_comp();

    bool ajouter_comp();
    bool modifier_comp(int);
    QSqlQueryModel * afficher_comp();
    bool supprimer_comp(int);
private:

    int id_comp;

    QString nom_comp;
    int telephone;
};

#endif // DEPARTEMENT_H
