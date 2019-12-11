#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("slim bd");
db.setUserName("hr");//inserer nom de l'utilisateur
db.setPassword("hr");//inserer mot de passe de cet utilisateur


if (db.open())
test=true;

else throw QString ("Erreur Paramétres"+test);



    return  test;
}

void Connection::closeconnect(){db.close();}
