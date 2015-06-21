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
    if(datagram == "All on")
    {
        control.setPin(0,1);
        control.setPin(1,1);
    }
    if(datagram == "All off")
    {
        control.setPin(0,0);
        control.setPin(1,0);
    }
    QString stringDatagram(datagram);
    QRegularExpression rx("[ ]");
    QStringList list = stringDatagram.split(rx, QString::SkipEmptyParts);
    QString pinSel = list.at(0);
    QString onOff = list.at(1);
    qint8 pinNum = pinSel.toInt();
    qint8 status;

    if(onOff == "on")
    {
        status = 1;
    }
    else {
        status = 0;
    }

    control.setPin(pinNum,status);

    qDebug() << list;
    //Pin 0
//    if(datagram =="0 on")
//    {
//        control.setPin(0,1);
//    }
//    if(datagram =="0 off")
//    {
//        control.setPin(0,0);
//    }
//    //Pin 1
//    if(datagram =="1 on")
//    {
//        control.setPin(1,1);
//    }
//    if(datagram=="1 off")
//    {
//        control.setPin(1,0);
//    }

}




