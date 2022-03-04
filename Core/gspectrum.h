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

    float &operator[](int i);
    float operator[](int i) const;
    GSpectrum &operator+=(const GSpectrum &s1);
    GSpectrum operator+(const GSpectrum &s1) const;
    GSpectrum operator-(const GSpectrum &s1) const;
    GSpectrum &operator*=(const GSpectrum &s1);
    GSpectrum operator*(const GSpectrum &s1) const;

public:
    float m_coefficient[GColorSpace::m_SpectralSamples]; //spd 光谱分布的系数

private:
    QColor m_color;
};


#endif // GSPECTRUM_H
