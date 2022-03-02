#include "gray.h"

GRay::GRay()
{}

GRay::GRay(const QVector3D& origin,const QVector3D& direction) : m_origin(origin), m_direction(direction)
{
    m_max = 100.0f;
}

QVector3D GRay::operator()(float t) const
{
    return m_origin + m_direction*t;
}

GRay GRay::transform(const QMatrix4x4& m) const
{
    GRay ray;
    ray.m_origin = m.map(m_origin);
    ray.m_direction = m.mapVector(m_direction);
    ray.m_max = m_max;
    return ray;
}
