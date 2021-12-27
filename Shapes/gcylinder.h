#ifndef GCYLINDER_H
#define GCYLINDER_H

#include "Shapes/gshape.h"
#include "Math/gbound3d.h"

class GCylinder : public GShape
{
public:
    GCylinder(const QMatrix4x4* objectToWorld, const QMatrix4x4* worldToObject, bool reverseOrientation, float radius, float zMin, float zMax, float phiMax);

    GBound3D objectBound() const;
    bool intersect(const GRay &ray, float *tHit, GSurfaceInteraction *isect, bool testAlphaTexture = true) const;
    float area() const;

private:
    bool isValidPointInCylinder(const QVector3D p) const;

public:
    const float m_radius;
    const float m_zMin;
    const float m_zMax;
    const float m_phiMax;
};

#endif // GCYLINDER_H
