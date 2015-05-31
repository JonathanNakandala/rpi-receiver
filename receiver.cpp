#include "receiver.h"
#include <QtNetwork>

void receiver::receive()
{
    udpSocket = new QUdpSocket();
    udpSocket->bind(45455, QUdpSocket::ShareAddress);
    connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(checker()));
        qDebug() << "Gut 猫" << endl << endl;

}


void receiver::checker()
{
  while (udpSocket->hasPendingDatagrams()) {
      QByteArray datagram;
      datagram.resize(udpSocket->pendingDatagramSize());
      QHostAddress sender;
      quint16 senderPort;

      udpSocket->readDatagram(datagram.data(), datagram.size(),
                              &sender, &senderPort);
      qDebug() << datagram << endl ;

  }
}




