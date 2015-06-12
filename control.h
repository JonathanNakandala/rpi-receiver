#ifndef CONTROL_H
#define CONTROL_H

#include <QObject>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QUdpSocket;
class QAction;
QT_END_NAMESPACE


class control : public QObject
{
    Q_OBJECT
public:
    control();
    void getStatus(qint8 pin);

signals:

private slots:

};

#endif // CONTROL_H
