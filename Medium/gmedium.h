#ifndef GMEDIUM_H
#define GMEDIUM_H

#include "qtinclude.h"
#include "Core/gspectrum.h"
#include "Core/gray.h"
#include "Samplers/gsampler.h"
#include "Core/gmemoryarena.h"
// #include "Medium/gmediuminteraction.h"

class GMediumInteraction;
class GMedium
{
public:
    GMedium();
    virtual ~GMedium();
    virtual GSpectrum tr(const GRay &ray, GSampler &sampler) const = 0;
    virtual GSpectrum sample(const GRay &ray, GSampler &sample, GMemoryArena &arena, GMediumInteraction* mi) const = 0;
};

#endif // GMEDIUM_H
