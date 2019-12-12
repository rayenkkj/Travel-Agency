#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Client
{public:
    Client();
    Client(int,QString,QString,int,QString,QString);
    int get_idclient();
    QString get_nom();
    QString get_prenom();
    QString get_adresse();
    int get_age();
    QString get_type();

    bool ajouter_client();
    QSqlQueryModel * afficher_client();
    bool supprimer_client(int idclient);
    bool modifier_client(int idclient);
    QSqlQueryModel* afficher_idclient(int idclient);
    QSqlQueryModel * afficher_trie();

private:

    QString nom,prenom,adresse,type_c;
    int idclient,age;
};

#endif // ETUDIANT_H
