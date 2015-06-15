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
     QHostAddress Adders("192.168.0.3");

     udpSocket = new QUdpSocket(this);
    if (datagram == "Toast")
    {
        qDebug() << "I like Toast 10Q" << endl ;
        udpSocket->writeDatagram(connectedReply.data(),connectedReply.size(),clientIP,clientPort);
        pinStatus();
    }

}

void transmitter::pinStatus()
{
    control contol;
    for(int i = 0; i < 2; i = i+1)
    {
        int returnValue;
        returnValue = contol.getStatus(i);
        deviceStatusArray[i] = returnValue;
      qDebug() << "Value of Pin " << i << "is" << deviceStatusArray[i] << endl;

    }
}
