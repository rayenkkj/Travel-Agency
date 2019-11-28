#ifndef MEDIA_H
#define MEDIA_H


#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QVariant>

class MEDIA
{
public:
    MEDIA();
    MEDIA(int,std::string);
    //MEDIA(int,std::string);
    int get_ID_MEDIA();
    std::string get_NOM_MEDIA();
    int get_NB_FOLLOWERS();
    bool ajouter();
    bool modifier(int);
    QSqlQueryModel * afficher();
    bool supprimer(int);
 private:
    int ID_MEDIA;
    std::string NOM_MEDIA;
    int NB_FOLLOWERS;

};

#endif // employe_H
