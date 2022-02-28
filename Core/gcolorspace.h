#ifndef GCOLORSPACE_H
#define GCOLORSPACE_H

#include <QVector3D>
#include <QMatrix4x4>
#include <QImage>

class GColorSpace
{
public:
    GColorSpace();

    static QVector3D CIExyYToCIEXYZ(QVector3D& xyY);
    static QVector3D CIEXYZToCIExyY(QVector3D& XYZ);

    static QVector3D CIEXYZToSRGB(QVector3D& XYZ);
    static QVector3D SRGBToCIEXYZ(QVector3D& SRGB);

    static QImage imageCIE1931XYZ();

    static QVector3D yuvToRgb(QVector3D yuv);
    static QVector3D rgbToYuv(QVector3D rgb);
};

#endif // GCOLORSPACE_H
