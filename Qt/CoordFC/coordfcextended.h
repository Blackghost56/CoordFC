#ifndef COORDFCEXTENDED_H
#define COORDFCEXTENDED_H

#include "coordfc.h"


class CoordFCExtended : public CoordFC
{
   Q_OBJECT
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

    bool parsing(const QString &str) override;

    // Returned coordinates with prefix and postfix. If prefix or postfix is epsent, returns only coordinates
    QString getCoord(COORD_FORMAT coord_format, COORD_PREFIX_POSTFIX coord_addition);

    // N, E = +
    // W, S = -
    // S, N = latitude
    // E, W = longitude
};

#endif // COORDFCEXTENDED_H
