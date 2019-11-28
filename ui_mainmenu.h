/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;

    void setupUi(QDialog *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainMenu->resize(640, 480);
        pushButton = new QPushButton(MainMenu);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 80, 75, 23));
        pushButton_2 = new QPushButton(MainMenu);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 80, 75, 23));
        pushButton_3 = new QPushButton(MainMenu);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(190, 80, 75, 23));
        pushButton_4 = new QPushButton(MainMenu);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(270, 80, 75, 23));
        pushButton_5 = new QPushButton(MainMenu);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(350, 80, 75, 23));
        pushButton_6 = new QPushButton(MainMenu);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(430, 80, 75, 23));
        pushButton_7 = new QPushButton(MainMenu);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(510, 80, 75, 23));

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QDialog *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainMenu", "Annonce", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainMenu", "Agent", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainMenu", "Client", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainMenu", "Resevation", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainMenu", "Paiement", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainMenu", "Reclamation", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainMenu", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
