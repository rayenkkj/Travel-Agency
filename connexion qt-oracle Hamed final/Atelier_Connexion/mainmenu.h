#ifndef MAINMENU_H
#define MAINMENU_H
#include "mainwindow.h"
#include "typedegestion.h"

#include <QDialog>

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainMenu *ui;
    MainWindow* connect;
    Typedegestion* connect2;
};

#endif // MAINMENU_H
