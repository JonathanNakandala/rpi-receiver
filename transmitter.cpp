#include "transmitter.h"
#include <QtNetwork>

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

    }

}
