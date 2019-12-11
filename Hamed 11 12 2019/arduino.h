#ifndef ARDUINO_H
#define ARDUINO_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDialog>

namespace Ui {
class Arduino;
}

class Arduino : public QDialog
{
    Q_OBJECT

public:
    explicit Arduino(QWidget *parent = nullptr);
    ~Arduino();
    //Arduino();
    int connect_arduino();
    int close_arduino();
    int write_to_arduino( QByteArray );
    QByteArray read_from_arduino();
    QSerialPort* getserial();
    QString getarduino_port_name()
    {return arduino_port_name;
    }
    int arduinoWriteData(int x);
    int arduinoReadData(int *x);
    void writefile();

private slots:

private:
    Ui::Arduino *ui;
    QSerialPort * serial;
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_producy_id=67;
    QString arduino_port_name = "com3";
    bool arduino_is_available;
    QByteArray data;
};

#endif // ARDUINO_H
