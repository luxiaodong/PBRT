#include "gpixelsampler.h"
#include "Math/gmath.h"

GPixelSampler::GPixelSampler()
{
}

float GPixelSampler::Get1D()
{
    return GMath::randomZeroToOne();
}

QVector2D GPixelSampler::Get2D()
{
    float a = GMath::randomZeroToOne();
    float b = GMath::randomZeroToOne();
    return QVector2D(a, b);
}
