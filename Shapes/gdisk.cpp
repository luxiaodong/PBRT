#include "gdisk.h"

GDisk::GDisk(const QMatrix4x4* objectToWorld, const QMatrix4x4* worldToObject, bool reverseOrientation, float height, float radius,  float innerRadius, float phiMax)
    :GShape(objectToWorld, worldToObject, reverseOrientation),
      m_height(height),
      m_radius(radius),
      m_innerRadius(innerRadius),
      m_phiMax(qDegreesToRadians(GMath::clamp(0, 360, phiMax)))
{

}

GBound3D GDisk::objectBound() const
{
    GBound3D b;
    if (m_phiMax < M_PI/2)
    {
        b.m_min = QVector3D(0, 0, m_height);
        b.m_max = QVector3D(m_radius, m_radius * qSin(m_phiMax) , m_height);
    }
    else if(m_phiMax < M_PI)
    {
        b.m_min = QVector3D(m_radius * qCos(m_phiMax), 0, m_height);
        b.m_max = QVector3D(m_radius, m_radius, m_height);
    }
    else if(m_phiMax < 3*M_PI/2)
    {
        b.m_min = QVector3D(-m_radius, m_radius * qSin(m_phiMax), m_height);
        b.m_max = QVector3D(m_radius, m_radius, m_height);
    }
    else
    {
        b.m_min = QVector3D(-m_radius, -m_radius, m_height);
        b.m_max = QVector3D(m_radius, m_radius, m_height);
    }

    return b;
}

bool GDisk::intersect(const GRay &ray, float *tHit, GSurfaceInteraction *isect, bool testAlphaTexture) const
{
    GRay objRay = ray.transform(*m_worldToObject);
    if (objRay.m_direction.z() == 0) return false;
    float hitT = (m_height - ray.m_origin.z())/objRay.m_direction.z();
    if(hitT <= 0 || hitT >= objRay.m_max) return false;

    QVector3D hitPoint = objRay(hitT);
    float phi = qAtan2(hitPoint.y(), hitPoint.x());
    if(phi < 0) phi += 2*M_PI;
    if(phi > m_phiMax) return false;
    return true;
}

bool GDisk::intersectP(const GRay &ray, bool testAlphaTexture) const
{
    return false;
}

float GDisk::area() const
{
    return m_phiMax * 0.5f * (m_radius*m_radius - m_innerRadius*m_innerRadius);
}

GInteraction GDisk::sample(const QVector2D& u, float* pdf) const
{
    GInteraction it;
    return it;
}
