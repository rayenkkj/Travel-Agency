#ifndef MENU_CLIENT_H
#define MENU_CLIENT_H
#include "client.h"
#include "client_type.h"
#include <QDialog>
#include <QMainWindow>

namespace Ui {
class Menu_client;
}

class Menu_client : public QDialog
{
    Q_OBJECT



public:
    explicit Menu_client(QWidget *parent = nullptr);
    ~Menu_client();

private slots:
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_ajouter_type_clicked();
    void on_pb_modifier_clicked();

    void on_load_clicked();

    void on_pushButton_clicked();

    void on_load_2_clicked();

    void on_pb_asc_tri_clicked();

    void on_pb_aff_client_clicked();

    void on_pb_supprimer_type_clicked();

    void on_pb_back_clicked();


    void on_next_clicked();

private:
    Ui::Menu_client *ui;
    Client tmpclient;
    Client_type tmpclient_type;
};

#endif // MENU_CLIENT_H








