#include "gsamplerintegrator.h"

GSamplerIntegrator::GSamplerIntegrator()
{
}

GSamplerIntegrator::GSamplerIntegrator(GSampler* sample, GCamera* camera)
{
    m_sampler = sample;
    m_camera = camera;
}

void GSamplerIntegrator::render(const GScene &scene)
{
}

GSamplerIntegrator::~GSamplerIntegrator()
{}
