#ifndef RECEIVER_H
#define RECEIVER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QUdpSocket;
class QAction;
QT_END_NAMESPACE

class receiver : public QObject
{
     Q_OBJECT
public:
   // void receiver();
    void receive();
    //void checker();
    void processPendingDatagrams();
    //void trasmit()
    void react(QByteArray datagram);
private slots:
    void checker();
private:
    QUdpSocket *udpSocket;
};

#endif // RECEIVER_H
