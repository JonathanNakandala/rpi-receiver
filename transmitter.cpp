#include <globalVar.h>
#include "transmitter.h"
#include <QtNetwork>
#include <control.h>
transmitter::transmitter()
{

}
void transmitter::connect(QByteArray datagram, QHostAddress clientIP, qint16 clientPort)
{
        QByteArray connectedReply = "Connected";

        udpSocket = new QUdpSocket(this);
        qDebug() << "Sucessfully Connected" << endl ;
        udpSocket->writeDatagram(connectedReply.data(),connectedReply.size(),clientIP,clientPort);
        pinStatus(clientIP, clientPort);

}

void transmitter::pinStatus(QHostAddress clientIP, qint16 clientPort)
{
    control contol;
    udpSocket = new QUdpSocket(this);
    for(int i = 0; i < NUMBER_OF_PINS; i = i+1)
    {
        int returnValue;
        returnValue = contol.getStatus(i);
        deviceStatusArray[i] = returnValue;
        qDebug() << "Value of Pin " << i << "is" << deviceStatusArray[i] << endl;

    }
        // Convert pin statuses to be transmitted
        QString str0 = QString::number(deviceStatusArray[0]);
        QString str1 = QString::number(deviceStatusArray[1]);
        QByteArray deviceStatus = str0.toUtf8() + str1.toUtf8();
        qDebug() << deviceStatus;
        udpSocket->writeDatagram(deviceStatus.data(),deviceStatus.size(),clientIP,clientPort);
}

void transmitter::sendDatagram(QByteArray datagram, QHostAddress clientIP, qint16 clientPort)
{
    udpSocket = new QUdpSocket(this);
    udpSocket->writeDatagram(datagram.data(),datagram.size(),clientIP,clientPort);

}
