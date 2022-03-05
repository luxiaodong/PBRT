#ifndef GCOLORSPACE_H
#define GCOLORSPACE_H

#include <QVector3D>
#include <QMatrix4x4>
#include <QImage>

class GColorSpace
{
public:
    GColorSpace();
    static const int m_CIESamples = 471;
    static float m_CIEX[m_CIESamples];
    static float m_CIEY[m_CIESamples];
    static float m_CIEZ[m_CIESamples];
    static float m_CIELambda[m_CIESamples];
    static constexpr float m_CIE_Y_Integral = 106.856895f;
    static const int m_SpectralSamples = 60;
    static const int m_SampledLambdaStart = 400;
    static const int m_SampledLambdaEnd = 700;
    static const int m_RGB2SpectSamples = 32;

    static float m_RGB2SpectLambda[m_RGB2SpectSamples];
    static float m_RGBRefl2SpectWhite[m_RGB2SpectSamples];
    static float m_RGBRefl2SpectCyan[m_RGB2SpectSamples];
    static float m_RGBRefl2SpectMagenta[m_RGB2SpectSamples];
    static float m_RGBRefl2SpectYellow[m_RGB2SpectSamples];
    static float m_RGBRefl2SpectRed[m_RGB2SpectSamples];
    static float m_RGBRefl2SpectGreen[m_RGB2SpectSamples];
    static float m_RGBRefl2SpectBlue[m_RGB2SpectSamples];
    static float m_RGBIllum2SpectWhite[m_RGB2SpectSamples];
    static float m_RGBIllum2SpectCyan[m_RGB2SpectSamples];
    static float m_RGBIllum2SpectMagenta[m_RGB2SpectSamples];
    static float m_RGBIllum2SpectYellow[m_RGB2SpectSamples];
    static float m_RGBIllum2SpectRed[m_RGB2SpectSamples];
    static float m_RGBIllum2SpectGreen[m_RGB2SpectSamples];
    static float m_RGBIllum2SpectBlue[m_RGB2SpectSamples];

    static QVector3D CIExyYToCIEXYZ(QVector3D& xyY);
    static QVector3D CIEXYZToCIExyY(QVector3D& XYZ);

    static QVector3D CIEXYZToRGB(QVector3D& XYZ);
    static QVector3D RGBToCIEXYZ(QVector3D& RGB);

    static QVector3D CIEXYZToSRGB(QVector3D& XYZ);
    static QVector3D SRGBToCIEXYZ(QVector3D& SRGB);

    static QImage imageCIE1931XYZ();

    static QVector3D yuvToRgb(QVector3D yuv);
    static QVector3D rgbToYuv(QVector3D rgb);
};

#endif // GCOLORSPACE_H
