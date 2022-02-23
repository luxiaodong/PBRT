#ifndef GPIXELSAMPLER_H
#define GPIXELSAMPLER_H

#include "gsampler.h"

class GPixelSampler : public GSampler
{
public:
    GPixelSampler();
    float Get1D();
    QVector2D Get2D();
};

#endif // GPIXELSAMPLER_H
