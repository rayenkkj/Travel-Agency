QT       += core gui sql multimedia printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agent.cpp \
    agent_type.cpp \
    annonce.cpp \
    annonce_type.cpp \
    client.cpp \
    client_type.cpp \
    compagne.cpp \
    connection.cpp \
    departement.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    media.cpp \
    menu_agent.cpp \
    menu_annonce.cpp \
    menu_client.cpp \
    menu_compagne.cpp \
    menu_departement.cpp \
    menu_media.cpp \
    menu_paiement.cpp \
    menu_pub.cpp \
    menu_reclamation.cpp \
    menu_reservation.cpp \
    paiement.cpp \
    pub.cpp \
    reclamation.cpp \
    reclamation_type.cpp \
    reservation.cpp

HEADERS += \
    agent.h \
    agent_type.h \
    annonce.h \
    annonce_type.h \
    client.h \
    client_type.h \
    compagne.h \
    connection.h \
    departement.h \
    mainmenu.h \
    mainwindow.h \
    media.h \
    menu_agent.h \
    menu_annonce.h \
    menu_client.h \
    menu_compagne.h \
    menu_departement.h \
    menu_media.h \
    menu_paiement.h \
    menu_pub.h \
    menu_reclamation.h \
    menu_reservation.h \
    paiement.h \
    pub.h \
    reclamation.h \
    reclamation_type.h \
    reservation.h

FORMS += \
    mainmenu.ui \
    mainwindow.ui \
    menu_agent.ui \
    menu_annonce.ui \
    menu_client.ui \
    menu_compagne.ui \
    menu_departement.ui \
    menu_media.ui \
    menu_paiement.ui \
    menu_pub.ui \
    menu_reclamation.ui \
    menu_reservation.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
