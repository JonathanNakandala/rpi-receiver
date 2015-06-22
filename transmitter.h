#ifndef TRANSMITTER_H
#define TRANSMITTER_H
#include <QtNetwork>

#include <QWidget>
QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QUdpSocket;
class QAction;
QT_END_NAMESPACE
class transmitter : public QObject
{
     Q_OBJECT
public:
    transmitter();
    void connect(QByteArray datagram, QHostAddress clientIP, qint16 clientPort);
    void pinStatus(QHostAddress clientIP, qint16 clientPort);
    void sendDatagram(QByteArray datagram, QHostAddress clientIP, qint16 clientPort);
private:
    QUdpSocket *udpSocket;
};

#endif // TRANSMITTER_H
