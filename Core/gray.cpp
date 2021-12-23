#include "gray.h"

GRay::GRay()
{}

GRay::GRay(const QVector3D& origin,const QVector3D& direction) : m_origin(origin), m_direction(direction)
{
}

QVector3D GRay::operator()(float t)
{
    return m_origin + m_direction*t;
}

GRay GRay::transform(const QMatrix4x4& m)
{
    GRay ray;
    ray.m_origin = m * m_origin;
    ray.m_direction = m * m_direction;
    return ray;
}
