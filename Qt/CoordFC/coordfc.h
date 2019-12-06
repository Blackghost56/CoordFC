#ifndef COORDFC_H
#define COORDFC_H

#include <QObject>

class CoordFC : public QObject
{
    Q_OBJECT
private:
    bool valid;


public:
    enum COORD_FORMAT {
        Dd,          // D - degree, M - minute, S - second, d - decimal part
        DMd,
        DMSd,
    };

    explicit CoordFC(QObject *parent = nullptr);
    // Parsing a string with coordinates. Returns true if successful, false if unsuccessful
    virtual bool parsing(const QString &str);
    // Returns true if data is parsed successfully
    bool isValid();
    // Return string with coordinates in rear format. If data isn't valid returns empty string
    QString getCoord(COORD_FORMAT coord_format);
    // Return coordinates in degree with deimal part. If data isn't valid returns -1000
    double getCoord();

signals:

public slots:
};

#endif // COORDFC_H
