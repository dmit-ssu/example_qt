#include <QCoreApplication>
#include <QDebug>

#include <QSerialPort>
#include <QSerialPortInfo>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qDebug() << "QSerialPortInfo::availablePorts() size is" << QSerialPortInfo::availablePorts().size();

    for (const QSerialPortInfo &info: QSerialPortInfo::availablePorts()) {
        qDebug() << "Name : " << info.portName();
        qDebug() << "Description : " << info.description();
        qDebug() << "Manufacturer : " << info.manufacturer();

        QSerialPort serial;
        serial.setPort(info);

        if (serial.open(QIODevice::ReadWrite)) {
            qDebug() << "Try to open: ok";
            serial.close();
            qDebug() << "Closed";
        } else {
            qDebug() << "Try to open: failed";
        }
    }

    return app.exec();
}
