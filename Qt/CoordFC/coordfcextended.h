#ifndef COORDFCEXTENDED_H
#define COORDFCEXTENDED_H

#include "coordfc.h"


class CoordFCExtended : public CoordFC
{
   Q_OBJECT
private:
    bool match;
    const QString expDd = "([0-9]{1,3})[.,]([0-9]{1,})([°]{0,1})[\s]";
    const QString expDMd = "([0-9]{1,3})[°](60|[1-5][0-9]|[0-9])([.,]([0-9]{1,})){0,1}['][\s]";
    const QString expDMSd = "([0-9]{1,3})[°](60|[1-5][0-9]|[0-9])['](60|[1-5][0-9]|[0-9])([.,]([0-9]{1,})){0,1}[\"]";

public:
    enum COORD_PREFIX_POSTFIX {
        SIGN_PREFIX,            // + or -
        SIGN_POSTFIX,
        LETTER_PREFIX,          // N, E, W, S,
        LETTER_POSTFIX,
        WORD_PREFIX,            // nl., el., sl., wl.
        WORD_POSTFIX,
    };
    explicit CoordFCExtended(QObject *parent = nullptr);


//    // Parsing a string with coordinates. Returns true if successful, false if unsuccessful
//    virtual bool parsing(const QString &str);
//    // Returns true if data is parsed successfully
//    bool isMatch();
//    // Return string with coordinates in rear format. If data isn't valid returns empty string
//    QString getCoord(COORD_FORMAT coord_format);
//    // Return coordinates in degree with deimal part. If data isn't valid returns -1000
//    double getCoord();

    //bool parsing(const QString &str) override;

    // Returned coordinates with prefix and postfix. If prefix or postfix is epsent, returns only coordinates
    QString getCoord(COORD_FORMAT coord_format, COORD_PREFIX_POSTFIX coord_addition);

    // N, E = +
    // W, S = -
    // S, N = latitude
    // E, W = longitude
};

#endif // COORDFCEXTENDED_H
