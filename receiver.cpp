#include "receiver.h"
#include <QtNetwork>
#include "transmitter.h"

void receiver::receive()
{
    udpSocket = new QUdpSocket();
    udpSocket->bind(45455, QUdpSocket::ShareAddress);
     QObject::connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(checker()));
        qDebug() << "猫" << endl ;


}


void receiver::checker()
{
     transmitter transmitterIns;
  while (udpSocket->hasPendingDatagrams()) {
      QByteArray datagram;
      datagram.resize(udpSocket->pendingDatagramSize());
      QHostAddress sender;
      quint16 senderPort;

      udpSocket->readDatagram(datagram.data(), datagram.size(),
                              &sender, &senderPort);
      qDebug() << datagram << endl ;
      transmitterIns.connect(datagram,sender,senderPort);



  }
}






