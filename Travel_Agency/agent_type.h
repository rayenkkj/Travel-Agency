#ifndef AGENT_TYPE_H
#define AGENT_TYPE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Agent_type
{
public:
    Agent_type();
    Agent_type(QString, QString);
    QString get_poste();
    QString get_desp();
    bool ajouter_type();
    bool supprimer_type(QString poste);

private:
    QString poste, desp;
};

#endif // AGENT_TYPE_H

