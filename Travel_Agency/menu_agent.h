#ifndef MENU_AGENT_H
#define MENU_AGENT_H
#include "agent.h"
#include "agent_type.h"
#include <QDialog>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QPrinter>
#include <QPrintDialog>
#include <QTimer>


namespace Ui {
class Menu_agent;
}

class Menu_agent : public QDialog
{
    Q_OBJECT

public:
    explicit Menu_agent(QWidget *parent = nullptr);
    ~Menu_agent();

private slots:
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_modifier_clicked();
    void on_Rechercher_clicked();

    void on_show_clicked();
    void on_Load_2_clicked();
    void on_Load_clicked();
    void on_affichertri_clicked();

    void on_pb_ajouter_type_clicked();

    void on_pb_supprimer_type_clicked();
    void on_pb_back_clicked();

    void on_next_clicked();

private:
    Ui::Menu_agent *ui;
     Agent tmpagent;
     Agent_type tmpagent_type;
     QMediaPlayer* player;
     QTimer *timer;
};

#endif // MENU_AGENT_H


