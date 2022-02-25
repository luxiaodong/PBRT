#include "gcolorspace.h"

#include <QMatrix4x4>
#include <QMatrix3x3>
#include <QtMath>
#include "Math/gmath.h"

GColorSpace::GColorSpace()
{

}

QImage GColorSpace::imageCIE1931XYZ()
{
    QVector3D r(0.64f,0.33f,0.03f);
    QVector3D g(0.30f,0.60f,0.10f);
    QVector3D b(0.15f,0.06f,0.79f);
    QVector3D w(0.3127f,0.3290f,0.3583f);

    qDebug()<<GColorSpace::CIEXYZToSRGB(r);
    qDebug()<<GColorSpace::CIEXYZToSRGB(g);
    qDebug()<<GColorSpace::CIEXYZToSRGB(b);
    qDebug()<<GColorSpace::CIEXYZToSRGB(w);

    QSize s(1024, 1024);
    QImage image(s, QImage::Format_RGBA8888);
    image.fill(Qt::black);

    for(int j = 0; j < s.height(); ++j)
    {
        for(int i = 0; i < s.width(); ++i)
        {
            float r = 1.0f*(i+1)/(s.width());
            float g = 1.0f*(j+1)/(s.height());
            float b = 1 -r - g;
            QVector3D srgb(r,g,b);
            QVector3D xyz = GColorSpace::CIEXYZToSRGB(srgb);
            if(xyz.x() >0.0f && xyz.x() < 1.0f &&
               xyz.y() >0.0f && xyz.y() < 1.0f &&
               xyz.z() >0.0f && xyz.z() < 1.0f)
            {
                QColor color = GMath::toColor(xyz);
                image.setPixelColor(i, j, color);
            }
        }
    }

    return image;
}

QVector3D GColorSpace::CIExyYToCIEXYZ(QVector3D& xyY)
{
    float x = xyY.x();
    float y = xyY.y();
    float Y = xyY.z();
    return QVector3D(x*Y/y, Y, Y*(1.0f - x - y)/y);
}

QVector3D GColorSpace::CIEXYZToCIExyY(QVector3D& XYZ)
{
    float s = XYZ.x() + XYZ.y() + XYZ.z();
    return QVector3D(XYZ.x()/s, XYZ.y()/s, XYZ.y());
}

QVector3D GColorSpace::CIEXYZToSRGB(QVector3D& XYZ)
{
    float X = XYZ.x();
    float Y = XYZ.y();
    float Z = XYZ.z();

    float r = X * 3.2406f + Y * -1.5372f + Z * -0.4986f;
    float g = X * -0.9689f + Y * 1.8758f + Z * 0.0415f;
    float b = X * 0.0557f + Y * -0.2040f + Z * 1.0570f;

    //gamma correction
    r = r > 0.0031308f ? 1.055f * qPow(r, 1.0f/2.4f) - 0.055f : 12.92f * r;
    g = g > 0.0031308f ? 1.055f * qPow(g, 1.0f/2.4f) - 0.055f : 12.92f * g;
    b = b > 0.0031308f ? 1.055f * qPow(b, 1.0f/2.4f) - 0.055f : 12.92f * b;

    r = GMath::clamp(r);
    g = GMath::clamp(g);
    b = GMath::clamp(b);

    return QVector3D(r,g,b);
}

QVector3D GColorSpace::SRGBToCIEXYZ(QVector3D& SRGB)
{
    float R = SRGB.x();
    float G = SRGB.y();
    float B = SRGB.z();

    float r = R > 0.04045f ? qPow((R+0.055f)/1.055f, 2.4f) : R/12.92f;
    float g = G > 0.04045f ? qPow((G+0.055f)/1.055f, 2.4f) : G/12.92f;
    float b = B > 0.04045f ? qPow((B+0.055f)/1.055f, 2.4f) : B/12.92f;

    float x = r * 0.412424f + g * 0.357579f + b * 0.180464f;
    float y = r * 0.212656f + g * 0.715158f + b * 0.072186f;
    float z = r * 0.019332f + g * 0.119193f + b * 0.950444f;

    return QVector3D(x,y,z);
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

float GColorSpace::gamma(float c)
{
    return qPow(c, 2.2);
}

QVector3D GColorSpace::linearToSrgb(QVector3D& linear)
{
    float r = GColorSpace::linearToSrgb(linear.x());
    float g = GColorSpace::linearToSrgb(linear.y());
    float b = GColorSpace::linearToSrgb(linear.z());
    QVector3D srgb = QVector3D(r,g,b);
    return GMath::clamp(srgb);
}

float GColorSpace::linearToSrgb(float c)
{
    if(c < 0.00304f) return 12.92f*c;
    float a = 0.055f;
    return (1.0f+a)*qPow(c, 1.0f/2.4f) - a;
}

float GColorSpace::srgbToLinear(float c)
{
    if(c < 0.04045f) return c/12.92f;
    float a = 0.055f;
    return qPow( (c+a)/(1.0f+a), 2.4f);
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
