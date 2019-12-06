#include <QCoreApplication>
#include "coordfc.h"
#include "coordfcextended.h"
#include "QDebug"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString str = "56°43'21\"";
    CoordFC coord;
    qDebug() << coord.parsing(str);
    qDebug() << "str: " << coord.getCoord(CoordFC::DMSd) << "\tdouble: " << coord.getCoord();
//    CoordFCExtended coordExtended;
//    qDebug() << coordExtended.parsing(str);

    return a.exec();
}
