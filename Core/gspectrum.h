#ifndef GSPECTRUM_H
#define GSPECTRUM_H

#include <QVector3D>
#include <QColor>
#include "Core/gcolorspace.h"

//光谱的能量,并非是rgb值
// RGB-> XYZ ->SPD -> Radiance

class GSpectrum
{
public:
    GSpectrum();
    GSpectrum(float c);
    static void init();
    static float averageSamples(const float *lambda, const float *vals, int n, float lambdaStart, float lambdaEnd);
    QVector3D toXYZ() const; //给定m_coefficient,对m_XYZ求积分
    QVector3D toRGB() const; //先转XYZ,再转RGB
    QVector3D toSRGB() const; //比RGB多了一步gamma矫正
    bool isBlack();

    float &operator[](int i);
    float operator[](int i) const;
    GSpectrum &operator+=(const GSpectrum &s1);
    GSpectrum operator+(const GSpectrum &s1) const;
    GSpectrum operator-(const GSpectrum &s1) const;
    GSpectrum &operator*=(const GSpectrum &s1);
    GSpectrum operator*(const GSpectrum &s1) const;

public:
    float m_coefficient[GColorSpace::m_SpectralSamples]; //spd 光谱分布的系数
};


#endif // GSPECTRUM_H
