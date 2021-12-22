#ifndef GCAMERA_H
#define GCAMERA_H

#include "Core/gray.h"
#include "Core/gfilm.h"
#include "Samplers/gsampler.h"

class GCamera
{
public:
    GCamera();
    GCamera(GFilm* film);

    bool generateRay(const GSampler &sample, GRay& ray);

public:
    GFilm* m_film;
};

#endif // GCAMERA_H
