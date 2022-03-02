#include "gbound3d.h"

#include "Math/gmath.h"

GBound3D::GBound3D()
{

}

GBound3D::GBound3D(const QVector3D &p1, const QVector3D &p2)
{
    m_min = GMath::min(p1, p2);
    m_max = GMath::max(p1, p2);
}

GBound3D GBound3D::unionBound(const GBound3D& b1, const GBound3D& b2)
{
    GBound3D b;
    b.m_min = GMath::min(b1.m_min, b2.m_min);
    b.m_max = GMath::max(b1.m_max, b2.m_max);
    return b;
}

QVector3D GBound3D::corner(int index) const
{
    Q_ASSERT(index >=0 && index < 8);
    float x = GMath::lerp( m_min.x(), m_max.x(), index &  1);
    float y = GMath::lerp( m_min.y(), m_max.y(), index &  2);
    float z = GMath::lerp( m_min.z(), m_max.z(), index &  4);
    return QVector3D(x,y,z);
}

QVector3D GBound3D::diagonal() const
{
    return m_max - m_min;
}

int GBound3D::maximumExtent() const
{
    QVector3D d = this->diagonal();
    if(d.x() > d.y() && d.x() > d.z()) return 0;
    else if(d.y() > d.z()) return 1;
    return 2;
}

float GBound3D::volume() const
{
    QVector3D d = this->diagonal();
    return d.x()*d.y()*d.z();
}

float GBound3D::surfaceArea() const
{
    QVector3D d = this->diagonal();
    return 2 * (d.x()*d.y() + d.x()*d.z() + d.y()*d.z());
}

bool GBound3D::overlaps(const GBound3D& b1, const GBound3D& b2)
{
    bool x = (b1.m_max.x() >= b2.m_min.x()) && (b1.m_min.x() <= b2.m_max.x());
    bool y = (b1.m_max.y() >= b2.m_min.y()) && (b1.m_min.y() <= b2.m_max.y());
    bool z = (b1.m_max.z() >= b2.m_min.z()) && (b1.m_min.z() <= b2.m_max.z());
    return (x && y && z);
}

bool GBound3D::inside(const QVector3D& p) const
{
    bool x = (m_min.x() < p.x()) && (p.x() < m_max.x());
    bool y = (m_min.y() < p.y()) && (p.y() < m_max.y());
    bool z = (m_min.z() < p.z()) && (p.z() < m_max.z());
    return (x && y && z);
}

QVector3D GBound3D::lerp(float p) const
{
    return GMath::lerp(m_min, m_max, p);
}

QVector3D GBound3D::offset(const QVector3D p) const
{
    QVector3D d = this->diagonal();
    float x = d.x() > 0 ? (p.x() - m_min.x())/d.x() : 0;
    float y = d.y() > 0 ? (p.y() - m_min.y())/d.y() : 0;
    float z = d.z() > 0 ? (p.z() - m_min.z())/d.z() : 0;
    return QVector3D(x,y,z);
}

//解方程 x = a + b*t;
bool GBound3D::intersectP(const GRay& ray, float* hitt0, float* hitt1) const
{
    float t0 = 0, t1 = ray.m_max;
    for(int i = 0; i < 3; ++i)
    {
        if( GMath::abs(ray.m_direction[i]) < GMath::m_epsilon)
        {
            float tNear = (m_min[i] - ray.m_origin[i])/ray.m_direction[i];
            float tFar  = (m_max[i] - ray.m_origin[i])/ray.m_direction[i];
            if(tNear > tFar) qSwap(tNear, tFar);
            // Update _tFar_ to ensure robust ray--bounds intersection
            // tFar *= 1 + 2 * gamma(3);
            t0 = tNear > t0 ? tNear : t0;
            t1 = tFar  < t1 ? tFar  : t1;
        }
    }

    if(hitt0) *hitt0 = t0;
    if(hitt1) *hitt1 = t1;
    return true;
}

//bool GBound3D::intersectP(const GRay& ray, const QVector3D& invDIr, const int dirInNeg[3]) const
//{
//    return false;
//}

GBound3D GBound3D::transform(const QMatrix4x4& m) const
{
    // 8个顶点取最大值,最小值
    QVector3D min = m * this->corner(0);
    QVector3D max = min;
    for(int i = 1; i < 8; ++i)
    {
        QVector3D v = m * this->corner(i);
        min = GMath::min(min, v);
        max = GMath::max(max, v);
    }

    GBound3D b;
    b.m_min = min;
    b.m_max = max;
    return b;
}
