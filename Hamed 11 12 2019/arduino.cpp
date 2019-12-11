#include "arduino.h"
#include "ui_arduino.h"
#include <qdebug.h>
#include <iostream>
#include <fstream>

using namespace std;

Arduino::Arduino(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Arduino)
{
    ui->setupUi(this);
    int ret=connect_arduino();
    switch (ret) {
    case(0):qDebug() << "arduino is available and connected to :"<< getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :"<< getarduino_port_name();
        break;
    case(-1):qDebug() << "arduino is not available";
        break;
    }
}

Arduino::~Arduino()
{
    delete ui;
}

int Arduino::connect_arduino()
{
    foreach(const QSerialPortInfo &serial_port_info, QSerialPortInfo ::availablePorts())
    {
        if(serial_port_info.vendorIdentifier() && serial_port_info.hasProductIdentifier()){
            if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier()
                    == arduino_uno_producy_id){
                arduino_is_available = true;
                arduino_port_name=serial_port_info.portName();
            }}}
    qDebug() << "arduino_port_name is :" << arduino_port_name;
    if(arduino_is_available){
        serial->setPortName(arduino_port_name);
        //serial->setPortName("com4");
        if(serial->open(QSerialPort::ReadWrite)){
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            return  0;
        }
    }
    return 1;

}

int Arduino::close_arduino()
{
    if(serial->isOpen()){
        serial->clear();
        return 0;
    }
    return 1;
}

QByteArray Arduino::read_from_arduino()
{
    if(serial->isReadable()){
        data=serial->readAll();

    }
return  data;
}

int Arduino::write_to_arduino( QByteArray d)
{
    if(serial->isWritable()){
        serial->write(d);
    }else{
        qDebug() << "Coudn't write to serial!";
    }

}

int Arduino::arduinoWriteData(int x)
{
    char chemin[]="C:/Users/hamed/Desktop/Projet c++/Semaine 13/Arduino/mytext.txt";
    FILE*f;

    f=fopen(chemin,"a");
    if(f == nullptr)
        return(-1);

    fprintf(f,"%d \n",x);
    fclose(f);

    return(0);
}

int Arduino::arduinoReadData(int *x)
{
    char chemin[]="C:/Users/hamed/Desktop/Projet c++/Semaine 13/Arduino/mytext.txt";
    FILE*f;
    char c;
    f=fopen(chemin,"r");

    if(f == nullptr)
        return(-1);

    fscanf(f,"%d",x);

    fclose(f);

    return(0);
}

void Arduino::writefile()
{
    ofstream file;
    file.open("mytext.txt");
    file <<"write this and tell me it works \n";
    file.close();
}
