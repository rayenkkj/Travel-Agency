#ifndef RECLAMATION_H
#define RECLAMATION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
using namespace std;

class Rec
{
public:
    Rec();
    Rec(int, int, QString, QString);
    int get_numrec();
    int get_idclient();
    QString get_daterec();
    QString get_description();
    bool ajouter_rec();
    bool modifier_rec();
    QSqlQueryModel* afficher_rec();
    bool supprimer_rec(int);
    QSqlQueryModel* recherche_rec(int);
    QSqlQueryModel* trier_rec();
    int test(int res);
    bool search(int cin);
    QSqlQueryModel* recherche_affect(int cin1,int cin2);
private:
    QString daterec,description;
    int numrec,idclient;
};

class Rec2:public Rec
{
public:
    Rec2();
    Rec2(int, QString);
    bool ajouter_rec2();
    bool modifier_rec2();
    QSqlQueryModel* afficher_rec2();
    bool supprimer_rec2(int);
    QSqlQueryModel* recherche_rec2(int);
    QSqlQueryModel* trier_rec2();
private:
     QString des;
     int numrec;
};

#endif // RECLAMATION_H
