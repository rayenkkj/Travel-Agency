#include "connexion.h"

Connexion::Connexion()
{

}

bool Connexion::ouvrirConnexion(){
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("rayenkkj");//inserer nom de l'utilisateur
    db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

    if(db.open())
        test=true;
    else throw QString("Error Settings "+test);
    return test;
}

void Connexion::fermerConnexion(){
    db.close();
}
