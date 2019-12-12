#ifndef MENU_COMPAGNE_H
#define MENU_COMPAGNE_H
#include "compagne.h"
#include <QDialog>
#include <QMainWindow>
#include <QSqlDatabase>

namespace Ui {
class menu_compagne;
}

class menu_compagne : public QDialog
{
    Q_OBJECT

public:
    explicit menu_compagne(QWidget *parent = nullptr);
    ~menu_compagne();

private slots:
    void on_ajouter_clicked();

     void on_pb_supprimer_2_clicked();

     void on_pushButton_clicked();

     void on_pb_back_clicked();

     void on_next_clicked();

private:
    Ui::menu_compagne *ui;
    compagne tmpc;
};

#endif // MENU_COMPAGNE_H
