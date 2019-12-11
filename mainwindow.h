#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include "client_type.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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


private:
    Ui::MainWindow *ui;
    Client tmpclient;
    Client_type tmpclient_type;
};

#endif // MAINWINDOW_H
