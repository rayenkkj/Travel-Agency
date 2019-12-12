#ifndef MAINMENU_H
#define MAINMENU_H

#include "mainwindow.h"
#include <QMainWindow>
#include <QDialog>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QPrinter>
#include <QPrintDialog>
#include <QTimer>


namespace Ui {
class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_pb_Connect_clicked();

private:
    Ui::MainMenu *ui;
    MainWindow * connect;

};
#endif // MAINMENU_H
