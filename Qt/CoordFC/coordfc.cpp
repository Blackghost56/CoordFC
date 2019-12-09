#include "coordfc.h"
//#include "math.h"

CoordFC::CoordFC(QObject *parent) : QObject(parent)
{

}


bool CoordFC::setCoord(COORD_FORMAT format, QVector<T> &coord)
{
    valid = false;
    const QVector<T> *coeff;
    switch (format) {
    case COORD_FORMAT::Dd:
        coeff = &coefficient.Dd;
        break;
    case COORD_FORMAT::DMd:
        coeff = &coefficient.DMd;
        break;
    case COORD_FORMAT::DMSd:
        coeff = &coefficient.DMSd;
        break;
    default:
        assert(false);
    }

    double val;
    if (!convertToDouble(coeff, coord, val))
        return false;
    if (!checkRange(val))
        return false;

    this->coord.format = format;
    this->coord.data = coord;
    coordD = val;
    valid = true;

    return true;
}

bool CoordFC::setCoord(double coord)
{
    valid = false;
    if (!checkRange(coord))
        return false;
    this->coord.format = Dd;
    this->coord.data.clear();
    this->coord.data.push_back(coord);
    coordD = coord;
    valid = true;
    return true;
}

bool CoordFC::isValid()
{
    return valid;
}

QVector<CoordFC::T> CoordFC::getCoord(CoordFC::COORD_FORMAT format)
{
    QVector<CoordFC::T> vec;
    switch (format) {
    case COORD_FORMAT::Dd:

        break;
    case COORD_FORMAT::DMd:

        break;
    case COORD_FORMAT::DMSd:

        break;
    default:
        assert(false);
    }
    return vec;
}

double CoordFC::getCoord()
{
    if (valid)
        return coordD;
    return -1000.0;
}

bool CoordFC::convertToDouble(const QVector<CoordFC::T> *coeff, const QVector<T> &coord, double &res)
{
    int size;
    size = coeff->size();
    if (coord.size() != (size))
        return false;

    res = 0;
    bool flag1 = false;
    bool flag2 = false;
    for (int i = 0; i < (size - 1); ++i) {
        res += coord.at(i).toDouble(&flag1) / coeff->at(i).toDouble(&flag2);
        if (!(flag1 && flag2))
           return false;
    }

    double dec = 0;

    dec = coord.at(size - 1).toDouble(&flag1) / coeff->at(size - 1).toDouble(&flag2);
    if (!(flag1 && flag2))
       return false;
    res += dec;

    return true;
}


bool CoordFC::checkRange(const double coord)
{
    if ((coord < thLow.toDouble()) || (coord > thHigh.toDouble()))
        return false;
    return true;
}



//QString CoordFC::getCoord(CoordFC::COORD_FORMAT coord_format)
//{

//}

//double CoordFC::getCoord()
//{

//}
