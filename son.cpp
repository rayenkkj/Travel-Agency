#include "son.h"


void  mettreMusique()
{
    QMediaPlayer * music=new QMediaPlayer();
    music->setMedia(QUrl("C:/Users/RayenKKJ/Desktop/connexion qt-oracle/Atelier_Connexion/Mortified.mp3"));
    music->play();
}
