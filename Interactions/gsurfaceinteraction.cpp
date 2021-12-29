#include "gsurfaceinteraction.h"

GSurfaceInteraction::GSurfaceInteraction()
{

}

GSurfaceInteraction::GSurfaceInteraction(const QVector3D &p, const QVector3D &pError, const QVector2D &uv, const QVector3D &wo, const QVector3D &dpdu, const QVector3D &dpdv, const QVector3D &dndu, const QVector3D &dndv, float time, const GShape* shape, int faceIndex)
    :GInteraction(p,QVector3D(), pError, wo, time, NULL),m_uv(uv),m_dpdu(dpdu),m_dpdv(dpdv),m_dndu(dndu),m_dndv(dndv),m_shape(shape),m_faceIndex(faceIndex)
{
}

void GSurfaceInteraction::shadingGeometry(const QVector3D &dpdu, const QVector3D &dpdv, const QVector3D &dndu, const QVector3D &dndv, bool orientationIsAuthoritative)
{}

void GSurfaceInteraction::computeScatteringFunctions(const GRayDifferential& ray, GMemoryArena& arena, bool allowMultipleLobes, int transportMode)
{}

void GSurfaceInteraction::computeDifferentials(const GRayDifferential &r) const
{}

GSpectrum GSurfaceInteraction::le(const QVector3D &w) const
{
    GSpectrum spec;
    return spec;
}

