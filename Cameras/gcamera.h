#ifndef GCAMERA_H
#define GCAMERA_H

#include "Core/graydifferential.h"
#include "Core/gfilm.h"
#include "Samplers/gsampler.h"
#include "Core/ganimatedtransform.h"
#include "Medium/gmedium.h"
#include "Interactions/ginteraction.h"

class GCameraSample
{
public:
    QVector2D m_pFilm;
    QVector2D m_pLens;
    float m_time;
};

class GCamera
{
public:
    GCamera(const GAnimatedTransform& cameraToWorld, float shutterOpen, float shutterClose, GFilm *film, const GMedium* medium);
    virtual ~GCamera();
    virtual float generateRay(const GSampler &sample, GRay& ray) const;
    virtual float generateRayDifferential(const GCameraSample& sample, GRayDifferential *rd) const;
    virtual GSpectrum we(const GRay &ray, QVector2D *pRaster2 = NULL) const;
    virtual void pdf_we(const GRay &ray, float *pdfPos, float *pdfDir) const;
    virtual GSpectrum sample_wi(const GInteraction &ref, const QVector2D &u, QVector3D *wi, float *pdf, QVector2D *pRaster, GVisibilityTester *vis) const;
public:
    GAnimatedTransform m_cameraToWorld;
    const float m_shutterOpen;
    const float m_shutterClose;
    GFilm* m_film;
    const GMedium *m_medium;
};

#endif // GCAMERA_H
