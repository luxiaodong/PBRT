#include "ginteraction.h"

GInteraction::GInteraction():m_time(0)
{}

GInteraction::GInteraction(const QVector3D& p, const QVector3D& n, const QVector3D& pError, const QVector3D& wo, float time, const GMediumInterface& mediumInterface)
    :m_point(p), m_time(time), m_pError(pError), m_normal(n), m_wOut(wo), m_mediumInterface(mediumInterface)
{}

GInteraction::GInteraction(const QVector3D& p, const QVector3D& wo, float time, const GMediumInterface& mediumInterface)
    :m_point(p), m_time(time), m_wOut(wo), m_mediumInterface(mediumInterface)
{}

GInteraction::GInteraction(const QVector3D& p, float time, const GMediumInterface &mediumInterface)
    :m_point(p), m_time(time), m_mediumInterface(mediumInterface)
{
}

bool GInteraction::isSurfaceInteraction() const
{
    return m_normal != QVector3D();
}

GRay GInteraction::spawnRay(const QVector3D& d) const
{
    GRay ray;
    return ray;
}

GRay GInteraction::spawnRayTo(const QVector3D& p) const
{
    GRay ray;
    return ray;
}

GRay GInteraction::spawnRayTo(const GInteraction &it) const
{
    GRay ray;
    return ray;
}

bool GInteraction::isMediumInteraction() const
{
    return !isSurfaceInteraction();
}

const GMedium* GInteraction::medium(const QVector3D &w) const
{
    return NULL;
}

const GMedium* GInteraction::medium() const
{
    return NULL;
}

