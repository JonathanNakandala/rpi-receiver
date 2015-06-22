#include <globalVar.h>
#include "control.h"
#include <qprocess.h>
#include <QDebug>

QProcess gpioPi;
QString programGpio = "gpio";


control::control()

{
}

qint8 control::getStatus(qint8 pin)
{
    qint8 statusValue;
    //Convert pin to string
    QString pinNumber = QString::number(pin);
    QStringList arguments;


    arguments << "read" << pinNumber;

    gpioPi.start(programGpio,arguments);
    gpioPi.waitForFinished(2000);

    QString output(gpioPi.readAll());
    statusValue = output.toInt();
    arguments.clear();
    return(statusValue);

}

void control::setPin(qint8 pin, qint8 value)
{
    QString pinNumber = QString::number(pin);
    QString pinValue   = QString::number(value);
    QStringList arguments;

    arguments << "write" << pinNumber << pinValue;

    gpioPi.start(programGpio,arguments);
    gpioPi.waitForFinished(2000);
    arguments.clear();
}

void control::setWrite(qint8 pinTotal)
{
    QStringList arguments;
    for (int i=0;i<pinTotal;i++)
    {
            QString i2 = QString::number(i);
            arguments << "mode" << i2 << "out";
            gpioPi.start(programGpio,arguments);
            gpioPi.waitForFinished(2000);

            arguments.clear();
    }
}

QString control::readPins()
{
    QString pinStatus;

    for(int i=0; i<NUMBER_OF_PINS; i++)
     {
         qint8 status = getStatus(i);
         QString s = QString::number(status);
         if(i ==NUMBER_OF_PINS - 1)
         {
            pinStatus += s;
         }
         else
         {
            pinStatus += s +" ";
         }
    }
 return pinStatus;
}
