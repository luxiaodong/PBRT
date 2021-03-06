#include "gspectrum.h"
#include "Math/gmath.h"

QVector3D GSpectrum::m_XYZ[GColorSpace::m_SpectralSamples];
GSpectrum GSpectrum::m_rgbRefl2SpectWhite;
GSpectrum GSpectrum::m_rgbRefl2SpectCyan;
GSpectrum GSpectrum::m_rgbRefl2SpectMagenta;
GSpectrum GSpectrum::m_rgbRefl2SpectYellow;
GSpectrum GSpectrum::m_rgbRefl2SpectRed;
GSpectrum GSpectrum::m_rgbRefl2SpectGreen;
GSpectrum GSpectrum::m_rgbRefl2SpectBlue;
GSpectrum GSpectrum::m_rgbIllum2SpectWhite;
GSpectrum GSpectrum::m_rgbIllum2SpectCyan;
GSpectrum GSpectrum::m_rgbIllum2SpectMagenta;
GSpectrum GSpectrum::m_rgbIllum2SpectYellow;
GSpectrum GSpectrum::m_rgbIllum2SpectRed;
GSpectrum GSpectrum::m_rgbIllum2SpectGreen;
GSpectrum GSpectrum::m_rgbIllum2SpectBlue;

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
        m_XYZ[i] = QVector3D(x,y,z);

        m_rgbRefl2SpectWhite.m_coefficient[i] = averageSamples(GColorSpace::m_RGB2SpectLambda, GColorSpace::m_RGBRefl2SpectWhite, GColorSpace::m_RGB2SpectSamples, left, right);
        m_rgbRefl2SpectCyan.m_coefficient[i] = averageSamples(GColorSpace::m_RGB2SpectLambda, GColorSpace::m_RGBRefl2SpectCyan, GColorSpace::m_RGB2SpectSamples, left, right);
        m_rgbRefl2SpectMagenta.m_coefficient[i] = averageSamples(GColorSpace::m_RGB2SpectLambda, GColorSpace::m_RGBRefl2SpectMagenta, GColorSpace::m_RGB2SpectSamples, left, right);
        m_rgbRefl2SpectYellow.m_coefficient[i] = averageSamples(GColorSpace::m_RGB2SpectLambda, GColorSpace::m_RGBRefl2SpectYellow, GColorSpace::m_RGB2SpectSamples, left, right);
        m_rgbRefl2SpectRed.m_coefficient[i] = averageSamples(GColorSpace::m_RGB2SpectLambda, GColorSpace::m_RGBRefl2SpectRed, GColorSpace::m_RGB2SpectSamples, left, right);
        m_rgbRefl2SpectGreen.m_coefficient[i] = averageSamples(GColorSpace::m_RGB2SpectLambda, GColorSpace::m_RGBRefl2SpectGreen, GColorSpace::m_RGB2SpectSamples, left, right);
        m_rgbRefl2SpectBlue.m_coefficient[i] = averageSamples(GColorSpace::m_RGB2SpectLambda, GColorSpace::m_RGBRefl2SpectBlue, GColorSpace::m_RGB2SpectSamples, left, right);
        m_rgbIllum2SpectWhite.m_coefficient[i] = averageSamples(GColorSpace::m_RGB2SpectLambda, GColorSpace::m_RGBIllum2SpectWhite, GColorSpace::m_RGB2SpectSamples, left, right);
        m_rgbIllum2SpectCyan.m_coefficient[i] = averageSamples(GColorSpace::m_RGB2SpectLambda, GColorSpace::m_RGBIllum2SpectCyan, GColorSpace::m_RGB2SpectSamples, left, right);
        m_rgbIllum2SpectMagenta.m_coefficient[i] = averageSamples(GColorSpace::m_RGB2SpectLambda, GColorSpace::m_RGBIllum2SpectMagenta, GColorSpace::m_RGB2SpectSamples, left, right);
        m_rgbIllum2SpectYellow.m_coefficient[i] = averageSamples(GColorSpace::m_RGB2SpectLambda, GColorSpace::m_RGBIllum2SpectYellow, GColorSpace::m_RGB2SpectSamples, left, right);
        m_rgbIllum2SpectRed.m_coefficient[i] = averageSamples(GColorSpace::m_RGB2SpectLambda, GColorSpace::m_RGBIllum2SpectRed, GColorSpace::m_RGB2SpectSamples, left, right);
        m_rgbIllum2SpectGreen.m_coefficient[i] = averageSamples(GColorSpace::m_RGB2SpectLambda, GColorSpace::m_RGBIllum2SpectGreen, GColorSpace::m_RGB2SpectSamples, left, right);
        m_rgbIllum2SpectBlue.m_coefficient[i] = averageSamples(GColorSpace::m_RGB2SpectLambda, GColorSpace::m_RGBIllum2SpectBlue, GColorSpace::m_RGB2SpectSamples, left, right);
    }
}

QVector3D GSpectrum::toXYZ() const
{
    QVector3D xyz(0,0,0);
    for(int i = 0; i < GColorSpace::m_SpectralSamples; ++i)
    {
        xyz += m_coefficient[i] * m_XYZ[i];
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
    if (lambdaStart < lambda[0]) //????????????????????????
    {
        sum += vals[0] * (lambda[0] - lambdaStart);
    }

    if (lambdaEnd > lambda[n - 1])
    {
        sum += vals[n - 1] * (lambdaEnd - lambda[n - 1]);
    }

    int i = 0;
    while( lambdaStart > lambda[i+1] )  ++i; //??????????????????

    //???????????????????????????
    for(; i+1<n && lambdaEnd >= lambda[i]; ++i)
    {
        float x0 = qMax(lambdaStart, lambda[i]);
        float x1 = qMin(lambdaEnd, lambda[i+1]);
        float y0 = GMath::lerp(vals[i], vals[i+1], (x0 - lambda[i])/(lambda[i+1] - lambda[i]));
        float y1 = GMath::lerp(vals[i], vals[i+1], (x1 - lambda[i])/(lambda[i+1] - lambda[i]));
        sum += 0.5f*(y0+y1)*(x1-x0);
    }

    //???????????????
    return sum/(lambdaEnd - lambdaStart);
}

GSpectrum GSpectrum::fromRGB(QVector3D rgb, bool isIlluminant)
{
    GSpectrum s;
    float r = rgb.x();
    float g = rgb.y();
    float b = rgb.z();

    if(isIlluminant)
    {
        if(r <= g && r <= b)
        {
            s += GSpectrum::m_rgbIllum2SpectWhite * r;
            if( g <= b)
            {
                s += GSpectrum::m_rgbIllum2SpectCyan * (g - r);
                s += GSpectrum::m_rgbIllum2SpectBlue * (b - g);
            }
            else
            {
                s += GSpectrum::m_rgbIllum2SpectCyan * (b - r);
                s += GSpectrum::m_rgbIllum2SpectGreen * (g - b);
            }
        }
        else if(g <= r && g <= b)
        {
            s += GSpectrum::m_rgbIllum2SpectWhite * g;
            if (r <= b)
            {
                s += GSpectrum::m_rgbIllum2SpectMagenta * (r - g);
                s += GSpectrum::m_rgbIllum2SpectBlue * (b - r);
            }
            else
            {
                s += GSpectrum::m_rgbIllum2SpectMagenta * (b - g);
                s += GSpectrum::m_rgbIllum2SpectRed * (r - b);
            }
        }
        else
        {
            s += GSpectrum::m_rgbIllum2SpectWhite * b;
            if (r <= g) {
                s += GSpectrum::m_rgbIllum2SpectYellow * (r - b);
                s += GSpectrum::m_rgbIllum2SpectGreen * (g - r);
            } else {
                s += GSpectrum::m_rgbIllum2SpectYellow * (g - b);
                s += GSpectrum::m_rgbIllum2SpectRed * (r - g);
            }
        }

        s *= 0.86445f;
    }
    else
    {
        if(r <= g && r <= b)
        {
            s += GSpectrum::m_rgbRefl2SpectWhite * r;
            if( g <= b)
            {
                s += GSpectrum::m_rgbRefl2SpectCyan * (g - r);
                s += GSpectrum::m_rgbRefl2SpectBlue * (b - g);
            }
            else
            {
                s += GSpectrum::m_rgbRefl2SpectCyan * (b - r);
                s += GSpectrum::m_rgbRefl2SpectGreen * (g - b);
            }
        }
        else if(g <= r && g <= b)
        {
            s += GSpectrum::m_rgbRefl2SpectWhite * g;
            if (r <= b)
            {
                s += GSpectrum::m_rgbRefl2SpectMagenta * (r - g);
                s += GSpectrum::m_rgbRefl2SpectBlue * (b - r);
            }
            else
            {
                s += GSpectrum::m_rgbRefl2SpectMagenta * (b - g);
                s += GSpectrum::m_rgbRefl2SpectRed * (r - b);
            }
        }
        else
        {
            s += GSpectrum::m_rgbRefl2SpectWhite * b;
            if (r <= g) {
                s += GSpectrum::m_rgbRefl2SpectYellow * (r - b);
                s += GSpectrum::m_rgbRefl2SpectGreen * (g - r);
            } else {
                s += GSpectrum::m_rgbRefl2SpectYellow * (g - b);
                s += GSpectrum::m_rgbRefl2SpectRed * (r - g);
            }
        }

        s *= 0.94f;
    }

    return s;
}
