#include "mainwindow.h"
#include "connection.h"
#include "mainmenu.h"
#include <QApplication>
#include <QMessageBox>
#include <QtWidgets>
#include <QWidget>
#include <QtDebug>



int main(int argc, char *argv[])
{  QApplication a(argc, argv);

    Connection c;

  MainWindow w;
  try {
      c.createconnect();
      w.show();
  } catch (QString s) {
      qDebug()<<s;
  }

    return a.exec();}
