#include "gspectrum.h"
#include "Math/gmath.h"

static QVector3D _XYZ[GColorSpace::m_SpectralSamples];

GSpectrum::GSpectrum()
{
    for(int i = 0; i < GColorSpace::m_SpectralSamples; ++i)
    {
        m_coefficient[i] = 0.0f;
    }
}

GSpectrum::GSpectrum(float c)
{
    for(int i = 0; i < GColorSpace::m_SpectralSamples; ++i)
    {
        m_coefficient[i] = c;
    }
}

float &GSpectrum::operator[](int i)
{
    return m_coefficient[i];
}

float GSpectrum::operator[](int i) const
{
    return m_coefficient[i];
}

GSpectrum &GSpectrum::operator+=(const GSpectrum &s1)
{
    for(int i = 0; i < GColorSpace::m_SpectralSamples; ++i)
    {
        m_coefficient[i] += s1.m_coefficient[i];
    }

    return *this;
}

GSpectrum GSpectrum::operator+(const GSpectrum &s1) const
{
    GSpectrum s2 = *this;
    for(int i = 0; i < GColorSpace::m_SpectralSamples; ++i)
    {
        s2.m_coefficient[i] += s1.m_coefficient[i];
    }

    return s2;
}

GSpectrum GSpectrum::operator-(const GSpectrum &s1) const
{
    GSpectrum s2 = *this;
    for(int i = 0; i < GColorSpace::m_SpectralSamples; ++i)
    {
        s2.m_coefficient[i] -= s1.m_coefficient[i];
    }

    return s2;
}

GSpectrum &GSpectrum::operator*=(const GSpectrum &s1)
{
    for(int i = 0; i < GColorSpace::m_SpectralSamples; ++i)
    {
        m_coefficient[i] *= s1.m_coefficient[i];
    }

    return *this;
}

GSpectrum GSpectrum::operator*(const GSpectrum &s1) const
{
    GSpectrum s2 = *this;
    for(int i = 0; i < GColorSpace::m_SpectralSamples; ++i)
    {
        s2.m_coefficient[i] *= s1.m_coefficient[i];
    }

    return s2;
}

void GSpectrum::init()
{
    for(int i = 0; i < GColorSpace::m_SpectralSamples; ++i)
    {
        float left = GMath::lerp(GColorSpace::m_SampledLambdaStart, GColorSpace::m_SampledLambdaEnd, 1.0f*i/GColorSpace::m_SpectralSamples);
        float right = GMath::lerp(GColorSpace::m_SampledLambdaStart, GColorSpace::m_SampledLambdaEnd, 1.0f*(i+1)/GColorSpace::m_SpectralSamples);
        float x = averageSamples(GColorSpace::m_CIELambda, GColorSpace::m_CIEX, GColorSpace::m_CIESamples, left, right);
        float y = averageSamples(GColorSpace::m_CIELambda, GColorSpace::m_CIEY, GColorSpace::m_CIESamples, left, right);
        float z = averageSamples(GColorSpace::m_CIELambda, GColorSpace::m_CIEZ, GColorSpace::m_CIESamples, left, right);
        _XYZ[i] = QVector3D(x,y,z);
    }
}

QVector3D GSpectrum::toXYZ() const
{
    QVector3D xyz(0,0,0);
    for(int i = 0; i < GColorSpace::m_SpectralSamples; ++i)
    {
        xyz += m_coefficient[i] * _XYZ[i];
    }

    float scale = (GColorSpace::m_SampledLambdaEnd - GColorSpace::m_SampledLambdaStart)/( GColorSpace::m_CIE_Y_Integral * GColorSpace::m_SpectralSamples);
    return scale * xyz;
}

QVector3D GSpectrum::toRGB() const
{
    QVector3D xyz = this->toXYZ();
    return GColorSpace::CIEXYZToRGB(xyz);
}

QVector3D GSpectrum::toSRGB() const
{
    QVector3D xyz = this->toXYZ();
    return GColorSpace::CIEXYZToSRGB(xyz);
}

bool GSpectrum::isBlack()
{
    for(int i = 0; i < GColorSpace::m_SpectralSamples; ++i)
    {
        if(m_coefficient[i] > 0.0f) return false;
    }

    return true;
}

// https://zhuanlan.zhihu.com/p/54910283
float GSpectrum::averageSamples(const float *lambda, const float *vals, int n, float lambdaStart, float lambdaEnd)
{
    if (lambdaEnd <= lambda[0]) return vals[0];
    if (lambdaStart >= lambda[n - 1]) return vals[n - 1];
    if (n == 1) return vals[0];

    float sum = 0.0f;
    if (lambdaStart < lambda[0]) //预加上边界的面积
    {
        sum += vals[0] * (lambda[0] - lambdaStart);
    }

    if (lambdaEnd > lambda[n - 1])
    {
        sum += vals[n - 1] * (lambdaEnd - lambda[n - 1]);
    }

    int i = 0;
    while( lambdaStart > lambda[i+1] )  ++i; //找到开始的点

    //计算区间的梯形面积
    for(; i+1<n && lambdaEnd >= lambda[i]; ++i)
    {
        float x0 = qMax(lambdaStart, lambda[i]);
        float x1 = qMin(lambdaEnd, lambda[i+1]);
        float y0 = GMath::lerp(vals[i], vals[i+1], (x0 - lambda[i])/(lambda[i+1] - lambda[i]));
        float y1 = GMath::lerp(vals[i], vals[i+1], (x1 - lambda[i])/(lambda[i+1] - lambda[i]));
        sum += 0.5f*(y0+y1)*(x1-x0);
    }

    //算出平均值
    return sum/(lambdaEnd - lambdaStart);
}

