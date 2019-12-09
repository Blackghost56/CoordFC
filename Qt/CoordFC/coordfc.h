#ifndef COORDFC_H
#define COORDFC_H

#include <QObject>
#include <QRegExp>
#include <QDebug>

class CoordFC : public QObject
{
    Q_OBJECT   
public:
    using T = QVariant;
    enum COORD_FORMAT {
        Dd,          // D - degree, M - minute, S - second, d - decimal part
        DMd,
        DMSd,
    };

    explicit CoordFC(QObject *parent = nullptr);
    // Set coordinate in arbitrary format
    bool setCoord(COORD_FORMAT format, QVector<T> &coord);
    // Set coordinate in degree with decimal part (Dd)
    bool setCoord(double coord);
    bool isValid();
    QVector<T> getCoord(COORD_FORMAT format);
    double getCoord();
    //    // Return string with coordinates in rear format. If data isn't valid returns empty string
    //    QString getCoord(COORD_FORMAT format);
    //    // Return coordinates in degree with deimal part. If data isn't valid returns -1000
    //    double getCoord();

signals:

public slots:

private:
    struct TCoordCommon{
        COORD_FORMAT format;
        QVector<T> data;
    } coord;
    double coordD;
    bool valid = false;
    struct TCoefficient{
        const QVector<T> Dd{1};
        const QVector<T> DMd{1, 60};
        const QVector<T> DMSd{1, 60, 3600};
    } coefficient;
    const T thLow = 0;
    const T thHigh = 180;

    bool convertToDouble(const QVector<CoordFC::T> *coeff, const QVector<T> &coord, double &res);
    bool checkRange(const double coord);


};

#endif // COORDFC_H
