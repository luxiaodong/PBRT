#include "gcamera.h"

GCamera::GCamera(const GAnimatedTransform& cameraToWorld, float shutterOpen, float shutterClose, GFilm *film, const GMedium* medium)
    :m_cameraToWorld(cameraToWorld), m_shutterOpen(shutterOpen), m_shutterClose(shutterClose), m_film(film), m_medium(medium)
{
}

GCamera::~GCamera()
{
    if(m_film) delete m_film;
}

float GCamera::generateRay(const GSampler &sample, GRay& ray) const
{
    return 0.0f;
}

float GCamera::generateRayDifferential(const GCameraSample& sample, GRayDifferential *rd) const
{
    return 0.0f;
}

GSpectrum GCamera::we(const GRay &ray, QVector2D *pRaster2) const
{
    GSpectrum spec;
    return spec;
}

void GCamera::pdf_we(const GRay &ray, float *pdfPos, float *pdfDir) const
{
    return ;
}

GSpectrum GCamera::sample_wi(const GInteraction &ref, const QVector2D &u, QVector3D *wi, float *pdf, QVector2D *pRaster, GVisibilityTester *vis) const
{
    GSpectrum spec;
    return spec;
}
