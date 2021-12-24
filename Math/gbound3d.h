#ifndef GBOUND3D_H
#define GBOUND3D_H

#include "Core/gray.h"
#include <QVector3D>
#include <QList>

class GBound3D
{
public:
    GBound3D();
    GBound3D(const QVector3D &p1, const QVector3D &p2);
    static GBound3D unionBound(const GBound3D& b1, const GBound3D& b2);
    static bool overlaps(const GBound3D& b1, const GBound3D& b2);

    QVector3D corner(int index) const;
    QVector3D diagonal() const;
    float volume() const;
    float surfaceArea() const;

    bool intersectP(const GRay& ray, float* hitt0 = NULL, float* hitt1 = NULL) const;
    bool intersectP(const GRay& ray, const QVector3D& invDIr, const int dirInNeg[3]) const;
    bool inside(const QVector3D& p) const;
    // InsideExclusive

    int maximumExtent() const;
    QVector3D lerp(float p) const;
    QVector3D offset(const QVector3D p) const;

    GBound3D transform(const QMatrix4x4& m) const;
public:
    QVector3D m_min;
    QVector3D m_max;
};

#endif // GBOUND3D_H
