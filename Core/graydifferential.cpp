#include "graydifferential.h"

GRayDifferential::GRayDifferential(const QVector3D& origin, const QVector3D& direction) : GRay(origin, direction)
{
    m_hasDifferentials = false;
}

GRayDifferential::GRayDifferential(const GRay& ray) : GRay(ray)
{
    m_hasDifferentials = false;
}

//采样偏移后的缩放.
void GRayDifferential::scaleDifferentials(float s)
{
    m_dxOrigin = m_origin + (m_dxOrigin - m_origin)*s;
    m_dyOrigin = m_origin + (m_dyOrigin - m_origin)*s;
    m_dxDirection = m_direction + (m_dxDirection - m_direction)*s;
    m_dyDirection = m_direction + (m_dyDirection - m_direction)*s;
}
