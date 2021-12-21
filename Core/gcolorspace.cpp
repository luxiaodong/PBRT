#include "gcolorspace.h"

#include <QMatrix3x3>

GColorSpace::GColorSpace()
{

}

QVector3D GColorSpace::xyzToRgb(QVector3D xyz)
{
    QMatrix4x4 m(
                    3.240479f, -1.537150f, -0.498535f, 0.0f,
                    -0.969256f, 1.875991f, 0.041556f, 0.0f,
                    0.055648f, -0.204043f, 1.057311f, 0.0f,
                    0.0f, 0.0f, 0.0f, 1.0f
                );
    return m*xyz;
}

QVector3D GColorSpace::rgbToXyz(QVector3D rgb)
{
    QMatrix4x4 m(
                    0.412453f, 0.357580f, 0.180423f,0.0f,
                    0.212671f, 0.715160f, 0.072169f,0.0f,
                    0.019334f, 0.119193f, 0.950227f,0.0f,
                    0.0f, 0.0f, 0.0f, 1.0f
                );
    return m*rgb;
}

QVector3D GColorSpace::yuvToRgb(QVector3D yuv)
{
    QMatrix4x4 m(
                    0.299f,0.587f,0.114f,0.0f,
                  -0.147f,-0.289f,0.436f,0.0f,
                    0.615f,-0.515f,-0.1f,0.0f,
                    0.0f, 0.0f, 0.0f, 1.0f
                );
    return m*yuv;
}

QVector3D GColorSpace::rgbToYuv(QVector3D rgb)
{
    QMatrix4x4 m(
                    1.0f, 0.0f, 1.14f,0.0f,
                    1.0f, 0.395f, 0.581f,0.0f,
                    1.0f, 2.032f, 0.001f,0.0f,
                    0.0f, 0.0f, 0.0f, 1.0f
                );
    return m*rgb;
}
