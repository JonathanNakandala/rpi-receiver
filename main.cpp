#include <QCoreApplication>
#include <QDebug>
#include <QtNetwork>
#include <qsysinfo.h>

#include <QObject>
#include "receiver.h"
#include "transmitter.h"

int main(int argc, char *argv[])
{


    QCoreApplication app(argc, argv);
    qDebug() << "Start of Program" << endl;

    receiver lol;

    lol.receive();
    qDebug() << "END HERE PLZ" << endl << endl;
    QString abi = QSysInfo::buildAbi();
     qDebug() << abi << endl << endl;
    return app.exec();
}
