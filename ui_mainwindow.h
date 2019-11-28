/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget_2;
    QWidget *AddA;
    QPushButton *pb_ajouter;
    QComboBox *comboBox_typean;
    QLineEdit *lineEdit_codean;
    QLineEdit *lineEdit_pays;
    QLineEdit *lineEdit_nbplace;
    QLineEdit *lineEdit_idcompagne;
    QLineEdit *lineEdit_prix;
    QPushButton *load;
    QLabel *label_2;
    QWidget *addT;
    QGroupBox *groupBox_5;
    QLineEdit *lineEdit_type;
    QTextEdit *textEdit;
    QPushButton *pb_ajouter_type;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_typean_supp;
    QPushButton *pb_supprimer_type;
    QLabel *label_7;
    QWidget *modif;
    QPushButton *pb_modifier;
    QLineEdit *lineEdit_codean_modif;
    QLineEdit *lineEdit_pays_modif;
    QLineEdit *lineEdit_nbplace_modif;
    QComboBox *comboBox_typean_2;
    QLineEdit *lineEdit_idcompagne_modif;
    QLineEdit *lineEdit_prix_modif;
    QPushButton *load_2;
    QLabel *label_6;
    QWidget *supp;
    QGroupBox *groupBox_2;
    QLineEdit *lineEdit_codean_2;
    QPushButton *pb_supprimer;
    QLabel *label_3;
    QWidget *affiche;
    QTableView *tabannonce;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QWidget *trier;
    QTableView *tabannonce_tri;
    QPushButton *pb_asc_tri;
    QPushButton *pb_desc_tri;
    QLabel *label_4;
    QPushButton *pushButton_3;
    QWidget *pays;
    QTableView *tabannonce_aff_pays;
    QLineEdit *lineEdit_aff_pays;
    QPushButton *pb_aff_pays;
    QLabel *label_5;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(761, 525);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 771, 471));
        AddA = new QWidget();
        AddA->setObjectName(QStringLiteral("AddA"));
        pb_ajouter = new QPushButton(AddA);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(290, 330, 151, 23));
        comboBox_typean = new QComboBox(AddA);
        comboBox_typean->setObjectName(QStringLiteral("comboBox_typean"));
        comboBox_typean->setGeometry(QRect(250, 200, 231, 21));
        comboBox_typean->setEditable(false);
        lineEdit_codean = new QLineEdit(AddA);
        lineEdit_codean->setObjectName(QStringLiteral("lineEdit_codean"));
        lineEdit_codean->setGeometry(QRect(250, 80, 231, 20));
        lineEdit_codean->setStyleSheet(QLatin1String("ui->LineEdit_Name->setStyleSheet(\"QLineEdit{ \"\n"
"                                        \"background-color:rgb(202, 255, 227);\"\n"
"                                        \"border: 2px solid gray;\"\n"
"                                        \"border-radius: 10px;\"\n"
"                                        \"padding: 0 8px;\"\n"
"                                        \"selection-background-color: darkgray;\"\n"
"                                        \"font-size: 16px;}\"\n"
"                                        \"QLineEdit:focus { \"\n"
"                                        \"background-color:rgb(192, 192, 255);}\"\n"
"                                        );"));
        lineEdit_pays = new QLineEdit(AddA);
        lineEdit_pays->setObjectName(QStringLiteral("lineEdit_pays"));
        lineEdit_pays->setGeometry(QRect(250, 120, 231, 20));
        lineEdit_nbplace = new QLineEdit(AddA);
        lineEdit_nbplace->setObjectName(QStringLiteral("lineEdit_nbplace"));
        lineEdit_nbplace->setGeometry(QRect(250, 160, 231, 20));
        lineEdit_idcompagne = new QLineEdit(AddA);
        lineEdit_idcompagne->setObjectName(QStringLiteral("lineEdit_idcompagne"));
        lineEdit_idcompagne->setGeometry(QRect(250, 240, 231, 20));
        lineEdit_prix = new QLineEdit(AddA);
        lineEdit_prix->setObjectName(QStringLiteral("lineEdit_prix"));
        lineEdit_prix->setGeometry(QRect(250, 280, 231, 20));
        load = new QPushButton(AddA);
        load->setObjectName(QStringLiteral("load"));
        load->setGeometry(QRect(520, 200, 75, 23));
        label_2 = new QLabel(AddA);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(600, 420, 161, 21));
        tabWidget_2->addTab(AddA, QString());
        addT = new QWidget();
        addT->setObjectName(QStringLiteral("addT"));
        groupBox_5 = new QGroupBox(addT);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 60, 351, 321));
        lineEdit_type = new QLineEdit(groupBox_5);
        lineEdit_type->setObjectName(QStringLiteral("lineEdit_type"));
        lineEdit_type->setGeometry(QRect(80, 80, 181, 20));
        lineEdit_type->setStyleSheet(QStringLiteral(""));
        textEdit = new QTextEdit(groupBox_5);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 140, 281, 81));
        textEdit->setStyleSheet(QLatin1String("QLineEdit {\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: yellow;\n"
"    selection-background-color: darkgray;\n"
"}"));
        textEdit->setLineWrapMode(QTextEdit::WidgetWidth);
        pb_ajouter_type = new QPushButton(groupBox_5);
        pb_ajouter_type->setObjectName(QStringLiteral("pb_ajouter_type"));
        pb_ajouter_type->setGeometry(QRect(90, 260, 161, 23));
        groupBox = new QGroupBox(addT);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(390, 60, 351, 321));
        lineEdit_typean_supp = new QLineEdit(groupBox);
        lineEdit_typean_supp->setObjectName(QStringLiteral("lineEdit_typean_supp"));
        lineEdit_typean_supp->setGeometry(QRect(90, 80, 181, 20));
        pb_supprimer_type = new QPushButton(groupBox);
        pb_supprimer_type->setObjectName(QStringLiteral("pb_supprimer_type"));
        pb_supprimer_type->setGeometry(QRect(114, 160, 141, 23));
        label_7 = new QLabel(addT);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(600, 420, 161, 21));
        tabWidget_2->addTab(addT, QString());
        modif = new QWidget();
        modif->setObjectName(QStringLiteral("modif"));
        pb_modifier = new QPushButton(modif);
        pb_modifier->setObjectName(QStringLiteral("pb_modifier"));
        pb_modifier->setGeometry(QRect(290, 330, 151, 23));
        lineEdit_codean_modif = new QLineEdit(modif);
        lineEdit_codean_modif->setObjectName(QStringLiteral("lineEdit_codean_modif"));
        lineEdit_codean_modif->setGeometry(QRect(250, 80, 231, 20));
        lineEdit_pays_modif = new QLineEdit(modif);
        lineEdit_pays_modif->setObjectName(QStringLiteral("lineEdit_pays_modif"));
        lineEdit_pays_modif->setGeometry(QRect(250, 120, 231, 20));
        lineEdit_nbplace_modif = new QLineEdit(modif);
        lineEdit_nbplace_modif->setObjectName(QStringLiteral("lineEdit_nbplace_modif"));
        lineEdit_nbplace_modif->setGeometry(QRect(250, 160, 231, 20));
        comboBox_typean_2 = new QComboBox(modif);
        comboBox_typean_2->setObjectName(QStringLiteral("comboBox_typean_2"));
        comboBox_typean_2->setGeometry(QRect(250, 200, 231, 21));
        comboBox_typean_2->setEditable(false);
        lineEdit_idcompagne_modif = new QLineEdit(modif);
        lineEdit_idcompagne_modif->setObjectName(QStringLiteral("lineEdit_idcompagne_modif"));
        lineEdit_idcompagne_modif->setGeometry(QRect(250, 240, 231, 20));
        lineEdit_prix_modif = new QLineEdit(modif);
        lineEdit_prix_modif->setObjectName(QStringLiteral("lineEdit_prix_modif"));
        lineEdit_prix_modif->setGeometry(QRect(250, 280, 231, 20));
        load_2 = new QPushButton(modif);
        load_2->setObjectName(QStringLiteral("load_2"));
        load_2->setGeometry(QRect(520, 200, 75, 23));
        label_6 = new QLabel(modif);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(600, 420, 161, 21));
        tabWidget_2->addTab(modif, QString());
        supp = new QWidget();
        supp->setObjectName(QStringLiteral("supp"));
        groupBox_2 = new QGroupBox(supp);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(120, 60, 511, 321));
        lineEdit_codean_2 = new QLineEdit(groupBox_2);
        lineEdit_codean_2->setObjectName(QStringLiteral("lineEdit_codean_2"));
        lineEdit_codean_2->setGeometry(QRect(122, 120, 241, 20));
        pb_supprimer = new QPushButton(groupBox_2);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(164, 170, 161, 23));
        label_3 = new QLabel(supp);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(600, 420, 161, 21));
        tabWidget_2->addTab(supp, QString());
        affiche = new QWidget();
        affiche->setObjectName(QStringLiteral("affiche"));
        tabannonce = new QTableView(affiche);
        tabannonce->setObjectName(QStringLiteral("tabannonce"));
        tabannonce->setGeometry(QRect(60, 60, 621, 241));
        pushButton = new QPushButton(affiche);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(290, 340, 161, 23));
        pushButton_2 = new QPushButton(affiche);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 380, 75, 23));
        label = new QLabel(affiche);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(600, 420, 161, 21));
        tabWidget_2->addTab(affiche, QString());
        trier = new QWidget();
        trier->setObjectName(QStringLiteral("trier"));
        tabannonce_tri = new QTableView(trier);
        tabannonce_tri->setObjectName(QStringLiteral("tabannonce_tri"));
        tabannonce_tri->setGeometry(QRect(60, 60, 621, 241));
        pb_asc_tri = new QPushButton(trier);
        pb_asc_tri->setObjectName(QStringLiteral("pb_asc_tri"));
        pb_asc_tri->setGeometry(QRect(230, 330, 91, 23));
        pb_desc_tri = new QPushButton(trier);
        pb_desc_tri->setObjectName(QStringLiteral("pb_desc_tri"));
        pb_desc_tri->setGeometry(QRect(404, 330, 91, 23));
        label_4 = new QLabel(trier);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(600, 420, 161, 21));
        pushButton_3 = new QPushButton(trier);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(330, 380, 75, 23));
        tabWidget_2->addTab(trier, QString());
        pays = new QWidget();
        pays->setObjectName(QStringLiteral("pays"));
        tabannonce_aff_pays = new QTableView(pays);
        tabannonce_aff_pays->setObjectName(QStringLiteral("tabannonce_aff_pays"));
        tabannonce_aff_pays->setGeometry(QRect(60, 130, 611, 241));
        lineEdit_aff_pays = new QLineEdit(pays);
        lineEdit_aff_pays->setObjectName(QStringLiteral("lineEdit_aff_pays"));
        lineEdit_aff_pays->setGeometry(QRect(160, 70, 113, 21));
        pb_aff_pays = new QPushButton(pays);
        pb_aff_pays->setObjectName(QStringLiteral("pb_aff_pays"));
        pb_aff_pays->setGeometry(QRect(440, 70, 111, 21));
        label_5 = new QLabel(pays);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(600, 420, 161, 21));
        pushButton_4 = new QPushButton(pays);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(330, 380, 75, 23));
        tabWidget_2->addTab(pays, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 761, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget_2->setCurrentIndex(5);
        comboBox_typean->setCurrentIndex(-1);
        comboBox_typean_2->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        comboBox_typean->setCurrentText(QString());
        lineEdit_codean->setText(QString());
        lineEdit_codean->setPlaceholderText(QApplication::translate("MainWindow", "Code de l'annonce", Q_NULLPTR));
        lineEdit_pays->setPlaceholderText(QApplication::translate("MainWindow", "Destination", Q_NULLPTR));
        lineEdit_nbplace->setText(QString());
        lineEdit_nbplace->setPlaceholderText(QApplication::translate("MainWindow", "Nombre de place", Q_NULLPTR));
        lineEdit_idcompagne->setText(QString());
        lineEdit_idcompagne->setPlaceholderText(QApplication::translate("MainWindow", "Identifiant de la compagne", Q_NULLPTR));
        lineEdit_prix->setPlaceholderText(QApplication::translate("MainWindow", "Prix", Q_NULLPTR));
        load->setText(QApplication::translate("MainWindow", "Load types", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "time", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(AddA), QApplication::translate("MainWindow", "      Ajouter     ", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Ajout type", Q_NULLPTR));
        lineEdit_type->setPlaceholderText(QApplication::translate("MainWindow", "Nouveau type", Q_NULLPTR));
        textEdit->setDocumentTitle(QString());
        textEdit->setPlaceholderText(QApplication::translate("MainWindow", "Description", Q_NULLPTR));
        pb_ajouter_type->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Suppression type", Q_NULLPTR));
        lineEdit_typean_supp->setPlaceholderText(QApplication::translate("MainWindow", "Type \303\240 supprimer", Q_NULLPTR));
        pb_supprimer_type->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "time", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(addT), QApplication::translate("MainWindow", "Ajouter / Supprimer un type ", Q_NULLPTR));
        pb_modifier->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        lineEdit_codean_modif->setPlaceholderText(QApplication::translate("MainWindow", "Code de l'annonce \303\240 modifier", Q_NULLPTR));
        lineEdit_pays_modif->setPlaceholderText(QApplication::translate("MainWindow", "Destination", Q_NULLPTR));
        lineEdit_nbplace_modif->setPlaceholderText(QApplication::translate("MainWindow", "Nombre de place", Q_NULLPTR));
        comboBox_typean_2->setCurrentText(QString());
        lineEdit_idcompagne_modif->setPlaceholderText(QApplication::translate("MainWindow", "Identifiant de la compagne", Q_NULLPTR));
        lineEdit_prix_modif->setPlaceholderText(QApplication::translate("MainWindow", "Prix", Q_NULLPTR));
        load_2->setText(QApplication::translate("MainWindow", "Load types", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "time", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(modif), QApplication::translate("MainWindow", "     Modifer     ", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Suppression", Q_NULLPTR));
        lineEdit_codean_2->setPlaceholderText(QApplication::translate("MainWindow", "Code de l'annonce \303\240 supprimer", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "time", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(supp), QApplication::translate("MainWindow", "     Supprimer    ", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Print", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "time", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(affiche), QApplication::translate("MainWindow", "     Afficher      ", Q_NULLPTR));
        pb_asc_tri->setText(QApplication::translate("MainWindow", "Ascendant ", Q_NULLPTR));
        pb_desc_tri->setText(QApplication::translate("MainWindow", "Descendant", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "time", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Print", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(trier), QApplication::translate("MainWindow", "Trier selon PRIX", Q_NULLPTR));
        lineEdit_aff_pays->setPlaceholderText(QApplication::translate("MainWindow", "Destination", Q_NULLPTR));
        pb_aff_pays->setText(QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "time", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Print", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(pays), QApplication::translate("MainWindow", "Destination sp\303\251cifi\303\251e", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
