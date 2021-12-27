#include "gsphere.h"

GSphere::GSphere(const QMatrix4x4* objectToWorld, const QMatrix4x4* worldToObject, bool reverseOrientation, float radius, float zMin, float zMax, float phiMax)
        :GShape(objectToWorld, worldToObject, reverseOrientation),
          m_radius(radius),
          m_zMin( GMath::clamp(-radius, radius, qMin(zMin, zMax)) ),
          m_zMax( GMath::clamp(-radius, radius, qMax(zMin, zMax)) ),
          m_thetaMin( qAcos( GMath::clamp(-1,1, qMin(zMin, zMax)/radius)) ),
          m_thetaMax( qAcos( GMath::clamp(-1,1, qMax(zMin, zMax)/radius)) ),
          m_phiMax( qDegreesToRadians(GMath::clamp(0, 360, phiMax)) )
{

}

GBound3D GSphere::objectBound() const
{
    GBound3D b;

    if (m_phiMax < M_PI/2)
    {
        b.m_min = QVector3D(0, 0, m_zMin);
        b.m_max = QVector3D(m_radius, m_radius * qSin(m_phiMax) , m_zMax);
    }
    else if(m_phiMax < M_PI)
    {
        b.m_min = QVector3D(m_radius * qCos(m_phiMax), 0, m_zMin);
        b.m_max = QVector3D(m_radius, m_radius, m_zMax);
    }
    else if(m_phiMax < 3*M_PI/2)
    {
        b.m_min = QVector3D(-m_radius, m_radius * qSin(m_phiMax), m_zMin);
        b.m_max = QVector3D(m_radius, m_radius, m_zMax);
    }
    else
    {
        b.m_min = QVector3D(-m_radius, -m_radius, m_zMin);
        b.m_max = QVector3D(m_radius, m_radius, m_zMax);
    }

    return b;
}

bool GSphere::intersect(const GRay &ray, float *tHit, GSurfaceInteraction *isect, bool testAlphaTexture) const
{
    GRay objRay = ray.transform(*m_worldToObject);

    // x^2 + y^2 + z^2 = r^2;
    // p(t) = o + dir*t;
    // (o.x + dir.x*t)^2 + (o.y + dir.y*t)^2 + (o.z + dir.z*t)^2 = r^2;

    float a = QVector3D::dotProduct(objRay.m_direction, objRay.m_direction);
    float b = 2.0f*QVector3D::dotProduct(objRay.m_direction, objRay.m_origin);
    float c = QVector3D::dotProduct(objRay.m_origin, objRay.m_origin) - m_radius*m_radius;
    float t0, t1;
    if( GMath::quadratic(a,b,c,t0,t1) == false ) return false;

    if(t0 > objRay.m_max || t1 < 0) return false;
    float hitT;
    if(t0 > 0 && this->isValidPointInSphere(objRay(t0)))
    {
        hitT = t0;
    }
    else if(t1 < objRay.m_max && this->isValidPointInSphere(objRay(t1)))
    {
        hitT = t1;
    }
    else
    {
        return false;
    }

    QVector3D hitPoint = objRay(hitT);
    // 计算该点的偏导数
    return true;
}

bool GSphere::intersectP(const GRay &ray, bool testAlphaTexture) const
{
    return false;
}

float GSphere::area() const
{
    return m_radius * (m_zMax - m_zMin) * m_phiMax;
}

GInteraction GSphere::sample(const QVector2D& u, float* pdf) const
{
    GInteraction it;
    return it;
}

GInteraction GSphere::sample(const GInteraction& ref, const QVector2D& u, float* pdf) const
{
    GInteraction it;
    return it;
}

float GSphere::pdf(const GInteraction& ref, const QVector3D& wi) const
{
    return 0.0f;
}

float GSphere::solidAngle(const QVector3D &p, int nSamples) const
{
    return 0.0f;
}

bool GSphere::isValidPointInSphere(const QVector3D p) const
{
    float phi = qAtan2(p.y(), p.x());
    if(phi < 0) phi += 2*M_PI;

    if(phi < m_phiMax && m_zMin < p.z() && p.z() < m_zMax)
    {
        return true;
    }

    return false;
}
