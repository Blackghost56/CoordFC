#include <QCoreApplication>
#include "coordfc.h"
#include "coordfcextended.h"
#include "QDebug"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CoordFC coord;
    QVector<CoordFC::T> data{180, 60, 60.0};
    qDebug() << "{180, 60, 60.0}" << coord.setCoord(CoordFC::DMSd, data) << "\t" << QString::number(coord.getCoord(), 'g', 10)
             << "\tDMSd" << coord.getCoord(CoordFC::DMSd)
                << "\tDMd" << coord.getCoord(CoordFC::DMd)
                   << "\tDd" << coord.getCoord(CoordFC::Dd);
    QVector<CoordFC::T> data2{180, 0, 0.1};
    qDebug() << "{180, 0, 0.1}" << coord.setCoord(CoordFC::DMSd, data2) << "\t" << QString::number(coord.getCoord(), 'g', 10)
             << "\tDMSd" << coord.getCoord(CoordFC::DMSd)
                << "\tDMd" << coord.getCoord(CoordFC::DMd)
                   << "\tDd" << coord.getCoord(CoordFC::Dd);
    QVector<CoordFC::T> data3{180, 0, 0.0};
    qDebug() << "{180, 0, 0.0}" << coord.setCoord(CoordFC::DMSd, data3) << "\t" << QString::number(coord.getCoord(), 'g', 10)
             << "\tDMSd" << coord.getCoord(CoordFC::DMSd)
                << "\tDMd" << coord.getCoord(CoordFC::DMd)
                   << "\tDd" << coord.getCoord(CoordFC::Dd);
    QVector<CoordFC::T> data4{150, 60, 0};
    qDebug() << "{150, 60, 0}" << coord.setCoord(CoordFC::DMSd, data4) << "\t" << QString::number(coord.getCoord(), 'g', 10)
             << "\tDMSd" << coord.getCoord(CoordFC::DMSd)
                << "\tDMd" << coord.getCoord(CoordFC::DMd)
                   << "\tDd" << coord.getCoord(CoordFC::Dd);
    QVector<CoordFC::T> data5{55, 45, 20.9916};
    qDebug() << "{55, 45, 20.9916}" << coord.setCoord(CoordFC::DMSd, data5) << "\t" << QString::number(coord.getCoord(), 'g', 10)
             << "\tDMSd" << coord.getCoord(CoordFC::DMSd)
                << "\tDMd" << coord.getCoord(CoordFC::DMd)
                   << "\tDd" << coord.getCoord(CoordFC::Dd);

    QVector<CoordFC::T> data6{0, 0, 0.0};
    qDebug() << "{0, 0, 0.0}" << coord.setCoord(CoordFC::DMSd, data6) << "\t" << QString::number(coord.getCoord(), 'g', 10)
             << "\tDMSd" << coord.getCoord(CoordFC::DMSd)
                << "\tDMd" << coord.getCoord(CoordFC::DMd)
                   << "\tDd" << coord.getCoord(CoordFC::Dd);

    qDebug() << "37.617673" << coord.setCoord(37.617673) << "\t" << QString::number(coord.getCoord(), 'g', 10)
             << "\tDMSd" << coord.getCoord(CoordFC::DMSd)
                << "\tDMd" << coord.getCoord(CoordFC::DMd)
                   << "\tDd" << coord.getCoord(CoordFC::Dd);



//    QString str = " 190.231°";   //"56°43'21\"";
//    CoordFC coord;
//    qDebug() << coord.parsing(str);
//    qDebug() << "str: " << coord.getCoord(CoordFC::DMSd) << "\tdouble: " << coord.getCoord();
//    CoordFCExtended coordExtended;
//    qDebug() << coordExtended.parsing(str);

    return a.exec();
}
