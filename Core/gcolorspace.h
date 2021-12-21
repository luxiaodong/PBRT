#ifndef GCOLORSPACE_H
#define GCOLORSPACE_H

#include <QVector3D>
#include <QMatrix4x4>

class GColorSpace
{
public:
    GColorSpace();

    //sRGB空间 和 CIE-XYZ空间转换
    static QVector3D xyzToRgb(QVector3D xyz);
    static QVector3D rgbToXyz(QVector3D rgb);

    static QVector3D yuvToRgb(QVector3D yuv);
    static QVector3D rgbToYuv(QVector3D rgb);
};

#endif // GCOLORSPACE_H
