#include "ggeometry.h"

GGeometry::GGeometry()
{

}

int GGeometry::sign(float value)
{
    if(value < -0.00001f) return -1;
    if(value > 0.00001f) return 1;
    return 0;
}

float GGeometry::determinant3D(QVector3D &a, QVector3D &b, QVector3D &c)
{
    return a.x()*b.y()*c.z() + b.x()*c.y()*a.z() + c.x()*a.y()*b.z() - c.x()*b.y()*a.z() - b.x()*a.y()*c.z() - a.x()*c.y()*b.z();
}

QVector4D GGeometry::createPlane(QVector3D &n, QVector3D &p)
{
    float d = QVector3D::dotProduct(n, p);
    if (d > 0)
    {
        return QVector4D(n.x(), n.y(), n.z(), -d);
    }

    return QVector4D(-n.x(), -n.y(), -n.z(), d);
}

QVector4D GGeometry::createPlane(QVector3D &v1, QVector3D &v2, QVector3D &p)
{
    QVector3D n = QVector3D::crossProduct(v1, v2).normalized();
    return GGeometry::createPlane(n, p);
}

QVector4D GGeometry::createPlaneByLineAndPoint(QVector3D &p0, QVector3D &dir, QVector3D &p1)
{
    QVector3D v1 = p1 - p0;
    return GGeometry::createPlane(dir, v1, p1);
}

QVector4D GGeometry::createPlaneByThreePoint(QVector3D &p1, QVector3D &p2, QVector3D &p3)
{
    QVector3D v1 = p2 - p1;
    QVector3D v2 = p3 - p1;
    return GGeometry::createPlane(v1, v2, p1);
}

int GGeometry::relationshipBetweenLineAndPoint(QVector3D &p0, QVector3D &dir, QVector3D &p1)
{
    QVector3D p2 = p0 + dir;
    return GGeometry::sign( GGeometry::determinant3D(p0, p1, p2)) == 0 ? 0 : 1;
}

int GGeometry::relationshipBetweenPlaneAndline(QVector4D &plane, QVector3D &dir)
{
    return GGeometry::sign(QVector3D::dotProduct(plane.toVector3D(), dir)) == 0 ? 0 : 1;
}

float GGeometry::signedDistanceBetweenPlaneAndPoint(QVector4D &plane, QVector3D &p)
{
    QVector3D n = plane.toVector3D();
    return (QVector3D::dotProduct(n, p) + plane.w())/n.length();
}

float GGeometry::distanceBetweenPlaneAndPoint(QVector4D &plane, QVector3D &p)
{
    float distance = GGeometry::signedDistanceBetweenPlaneAndPoint(plane, p);
    return qAbs(distance);
}

int GGeometry::relationshipBetweenPlaneAndPoint(QVector4D &plane, QVector3D &p)
{
    return GGeometry::sign(GGeometry::signedDistanceBetweenPlaneAndPoint(plane, p));
}

float GGeometry::distanceBetweenLineAndPoint(QVector3D &p0, QVector3D &dir, QVector3D &p1)
{
    QVector3D n = QVector3D::crossProduct(dir, QVector3D::crossProduct(p1 - p0, dir));
    QVector4D plane = GGeometry::createPlane(n, p0);
    float distance = GGeometry::distanceBetweenPlaneAndPoint(plane, p1);
    return qAbs(distance);
}

QVector3D GGeometry::crossPointBetweenPlaneAndLine(QVector4D &plane, QVector3D &p0, QVector3D &dir)
{
    QVector3D n = plane.toVector3D();
    float t = (plane.z() + QVector3D::dotProduct(p0, n))/(QVector3D::dotProduct(dir, n));
    return p0 + t*dir;
}

QVector3D GGeometry::crossPointVerticalLine(QVector3D &p0, QVector3D &dir, QVector3D &p1)
{
    QVector3D n = QVector3D::crossProduct(dir, QVector3D::crossProduct(p1 - p0, dir));
    QVector4D plane = createPlane(n, p0);
    return crossPointBetweenPlaneAndLine(plane, p1, n);
}
