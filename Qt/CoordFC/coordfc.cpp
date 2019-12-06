#include "coordfc.h"

CoordFC::CoordFC(QObject *parent) : QObject(parent)
{

}

bool CoordFC::parsing(const QString &str)
{
    return false;
}

bool CoordFC::isValid()
{
    return valid;
}

QString CoordFC::getCoord(CoordFC::COORD_FORMAT coord_format)
{

}

double CoordFC::getCoord()
{

}
