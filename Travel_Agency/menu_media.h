#ifndef MENU_MEDIA_H
#define MENU_MEDIA_H
#include "media.h"
#include <QMainWindow>
#include <QSqlDatabase>
#include <QDialog>

namespace Ui {
class Menu_media;
}

class Menu_media : public QDialog
{
    Q_OBJECT

public:
    explicit Menu_media(QWidget *parent = nullptr);
    ~Menu_media();

private slots:
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_modifier_clicked();
    void on_pushButton_2_clicked();
    void on_pb_back_clicked();

    void on_next_clicked();

private:
    Ui::Menu_media *ui;
    media tmpmedia;
    media tabmedia;
};

#endif // MENU_MEDIA_H

