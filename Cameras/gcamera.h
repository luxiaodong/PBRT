#ifndef GCAMERA_H
#define GCAMERA_H

#include "Core/gfilm.h"
#include "Math/gray.h"
#include "Samplers/gsampler.h"

class GCamera
{
public:
    GCamera();

    bool generateRay(const GSampler &sample, GRay& ray);

public:
    GFilm m_film;
};

#endif // GCAMERA_H
