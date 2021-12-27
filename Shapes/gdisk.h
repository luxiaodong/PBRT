#ifndef GDISK_H
#define GDISK_H

#include "Math/gbound3d.h"
#include "Shapes/gshape.h"

class GDisk : public GShape
{
public:
    GDisk(const QMatrix4x4* objectToWorld, const QMatrix4x4* worldToObject, bool reverseOrientation, float height, float radius,  float innerRadius, float phiMax);
    GBound3D objectBound() const;

    bool intersect(const GRay &ray, float *tHit, GSurfaceInteraction *isect, bool testAlphaTexture = true) const;
    bool intersectP(const GRay &ray, bool testAlphaTexture = true) const;
    float area() const;
    GInteraction sample(const QVector2D& u, float* pdf) const;

public:
    const float m_height;
    const float m_radius;
    const float m_innerRadius;
    const float m_phiMax;
};

#endif // GDISK_H
