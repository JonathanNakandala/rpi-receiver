#include <globalVar.h>
#include "receiver.h"
#include <QtNetwork>
#include "transmitter.h"
#include <control.h>
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
       react(datagram);


  }
}

void receiver::react(QByteArray datagram)
{
    control control;

    QString stringDatagram(datagram);
    QRegularExpression rx("[ ]");
    QStringList list = stringDatagram.split(rx, QString::SkipEmptyParts);
    QString pinSel = list.at(0);
    QString onOff = list.at(1);


    // Convert Status from Off and On to 1 and 0
    qint8 status;
    if(onOff == "on")
    {
        status = 1;
    }
    else {
        status = 0;
    }

    // For loop to turn on or off all pins else set single pin
    if(pinSel == "All")
    {
        for(int i = 0; i<NUMBER_OF_PINS;i++)
        {
            control.setPin(i,status);
        }
    }
    else {
            qint8 pinNum = pinSel.toInt();
            control.setPin(pinNum,status);
    }



    qDebug() << list;

}




