#include <QCoreApplication>
#include <QDebug>
#include <QtNetwork>

#include <QObject>
#include "receiver.h"

int main(int argc, char *argv[])
{


    QCoreApplication app(argc, argv);
    qDebug() << "Start of Program" << endl << endl;

    receiver lol;
    lol.receive();
    return app.exec();
}
