#include "gcamera.h"
#include <QVector3D>
#include "Math/gmath.h"

GCamera::GCamera(GFilm *film)
{
    m_pFilm = film;
    m_focalLength = 5.0f;
    m_originPt = QVector3D(0,10.0f,-10.0f);
    m_world2ViewMat = GMath::createWorldToViewMatrix(m_originPt, 45, 0, 0);
    m_view2WorldMat = m_world2ViewMat.inverted();
//    m_projectionMat = GMath::createOrthogonalMatrix(5, 1.0f, 0.3f, 1000.0f);
//    m_projectionMat = GMath::createProjectionMatrix(60, 1.0f, 0.3f, 1000.0f);
}

QVector3D& GCamera::originPt()
{
    return m_originPt;
}

GRay GCamera::generateRay(QVector2D& posInFilm)
{
    // 这里假设透视投影
//    QVector3D posInView = QVector3D(posInFilm.x(), posInFilm.y(), -m_focalLength);
//    QVector3D posInWorld = m_view2WorldMat*posInView;
//    QVector3D direction = (posInWorld - m_originPt).normalized();
//    return GRay(m_originPt, direction);

    return GRay(QVector3D(posInFilm.x(), posInFilm.y(), -m_focalLength), QVector3D(0,0,1));
}

//GCamera::GCamera(const GAnimatedTransform& cameraToWorld, float shutterOpen, float shutterClose, GFilm *film, const GMedium* medium)
//    :m_cameraToWorld(cameraToWorld), m_shutterOpen(shutterOpen), m_shutterClose(shutterClose), m_film(film), m_medium(medium)
//{
//}

//GCamera::~GCamera()
//{
//    if(m_film) delete m_film;
//}

//float GCamera::generateRay(const GSampler &sample, GRay& ray) const
//{
//    return 0.0f;
//}

//float GCamera::generateRayDifferential(const GCameraSample& sample, GRayDifferential *rd) const
//{
//    return 0.0f;
//}

//GSpectrum GCamera::we(const GRay &ray, QVector2D *pRaster2) const
//{
//    GSpectrum spec;
//    return spec;
//}

//void GCamera::pdf_we(const GRay &ray, float *pdfPos, float *pdfDir) const
//{
//    return ;
//}

//GSpectrum GCamera::sample_wi(const GInteraction &ref, const QVector2D &u, QVector3D *wi, float *pdf, QVector2D *pRaster, GVisibilityTester *vis) const
//{
//    GSpectrum spec;
//    return spec;
//}
