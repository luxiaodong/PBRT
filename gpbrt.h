#ifndef GPBRT_H
#define GPBRT_H

#include "qtinclude.h"
#include "Core/gscene.h"
#include "Integrators/gintegrator.h"
#include "Integrators/gsamplerintegrator.h"
#include "Cameras/gcamera.h"
#include "Core/gfilm.h"
#include "Samplers/gsampler.h"
#include "Core/gfilm.h"

class GPBRT
{
public:
    GPBRT();

public:
    void init();
    void rendering(QString& filePath);

private:
    GScene* createScene();
    GCamera* createCamera();
    GSampler* createSampler();
    GIntegrator* createIntegrator();

private:
    GScene* m_pScene;
    GIntegrator* m_pIntegrator;
    GCamera* m_pCamera;
    GSampler* m_pSampler;
    GFilm* m_pFilm;
};

#endif // GPBRT_H
