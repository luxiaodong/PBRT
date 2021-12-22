#ifndef GSAMPLERINTEGRATOR_H
#define GSAMPLERINTEGRATOR_H

#include "Integrators/gintegrator.h"
#include "Samplers/gsampler.h"
#include "Cameras/gcamera.h"

class GSamplerIntegrator : public GIntegrator
{
public:
    GSamplerIntegrator();
    GSamplerIntegrator(GSampler* sample, GCamera* camera);

    virtual void render(const GScene &scene);
    virtual ~GSamplerIntegrator();

public:
    GSampler* m_sampler;
    GCamera* m_camera;
};

#endif // GSAMPLERINTEGRATOR_H
