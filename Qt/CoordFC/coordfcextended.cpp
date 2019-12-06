#include "coordfcextended.h"

CoordFCExtended::CoordFCExtended(QObject *parent) : CoordFC(parent)
{

}

bool CoordFCExtended::parsing(const QString &str)
{
    //return CoordFC::parsing(str);
    return true;
}
