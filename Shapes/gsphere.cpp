#include "gsphere.h"

GSphere::GSphere(float radius, float zMin, float zMax, float phiMax)
        :GShape(),
          m_radius(radius),
          m_zMin( GMath::clamp(-radius, radius, qMin(zMin, zMax)) ),
          m_zMax( GMath::clamp(-radius, radius, qMax(zMin, zMax)) ),
          m_thetaMin( qAcos( GMath::clamp(-1,1, qMin(zMin, zMax)/radius)) ),
          m_thetaMax( qAcos( GMath::clamp(-1,1, qMax(zMin, zMax)/radius)) ),
          m_phiMax( qDegreesToRadians(GMath::clamp(0, 360, phiMax)) )
{

}

GSphere::~GSphere()
{}

GBound3D GSphere::objectBound() const
{
    GBound3D b;

    if (m_phiMax < GMath::m_pi/2)
    {
        b.m_min = QVector3D(0, 0, m_zMin);
        b.m_max = QVector3D(m_radius, m_radius *  qSin(m_phiMax) , m_zMax);
    }
    else if(m_phiMax < GMath::m_pi)
    {
        b.m_min = QVector3D(m_radius * qCos(m_phiMax), 0, m_zMin);
        b.m_max = QVector3D(m_radius, m_radius, m_zMax);
    }
    else if(m_phiMax < 3.0f*GMath::m_pi/2)
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

bool GSphere::intersect(const GRay &ray, float *tHit, GInteraction *isect) const
{
    GRay objRay = ray.transform(m_worldToObject);

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
    float phi;
    if(t0 > 0 && this->isValidPointInSphere(objRay(t0), phi))
    {
        hitT = t0;
    }
    else if(t1 < objRay.m_max && this->isValidPointInSphere(objRay(t1), phi))
    {
        hitT = t1;
    }
    else
    {
        return false;
    }

    tHit = &hitT;

//    QVector3D hitPoint = objRay(hitT);
    // 计算该点的偏导数, uv要在(0,1)内
    // u: 0 < phi < phiMax
    // v: zMin < cos(theta) < zMax

//    float u = phi/m_phiMax;
//    float theta = qAcos( GMath::clamp(hitPoint.z()/m_radius) );
//    float v = (theta - m_thetaMin)/(m_thetaMax - m_thetaMin);
//    float zRadius = qSqrt(hitPoint.x()*hitPoint.x() + hitPoint.y()*hitPoint.y());
//    float cosPhi = hitPoint.x()/zRadius;
//    float sinPhi = hitPoint.y()/zRadius;
//    QVector3D dpdu( (-m_phiMax) * hitPoint.y(), m_phiMax * hitPoint.x(), 0);
//    QVector3D dpdv = (m_thetaMax - m_thetaMin) * QVector3D(hitPoint.z()*cosPhi, hitPoint.z()*sinPhi, -m_radius*qSin(theta));
    return true;
}

//bool GSphere::intersectP(const GRay &ray, bool testAlphaTexture) const
//{
//    return false;
//}

//float GSphere::area() const
//{
//    return m_radius * (m_zMax - m_zMin) * m_phiMax;
//}

//GInteraction GSphere::sample(const QVector2D& u, float* pdf) const
//{
//    GInteraction it;
//    return it;
//}

//GInteraction GSphere::sample(const GInteraction& ref, const QVector2D& u, float* pdf) const
//{
//    GInteraction it;
//    return it;
//}

//float GSphere::pdf(const GInteraction& ref, const QVector3D& wi) const
//{
//    return 0.0f;
//}

//float GSphere::solidAngle(const QVector3D &p, int nSamples) const
//{
//    return 0.0f;
//}

bool GSphere::isValidPointInSphere(const QVector3D p, float& phi) const
{
    phi = static_cast<float>(qAtan2( static_cast<double>(p.y()) , static_cast<double>(p.x())));
    if(phi < 0) phi += 2*GMath::m_pi;

    if(phi < m_phiMax && m_zMin < p.z() && p.z() < m_zMax)
    {
        return true;
    }

    return false;
}
