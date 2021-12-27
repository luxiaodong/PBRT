#ifndef GSPHERE_H
#define GSPHERE_H

#include "Shapes/gshape.h"
#include "Math/gbound3d.h"

class GSphere : public GShape
{
public:
    GSphere(const QMatrix4x4* objectToWorld, const QMatrix4x4* worldToObject, bool reverseOrientation, float radius, float zMin, float zMax, float phiMax);
    GBound3D objectBound() const;

    bool intersect(const GRay &ray, float *tHit, GSurfaceInteraction *isect, bool testAlphaTexture = true) const;
    bool intersectP(const GRay &ray, bool testAlphaTexture = true) const;
    float area() const;
    GInteraction sample(const QVector2D& u, float* pdf) const;
    GInteraction sample(const GInteraction& ref, const QVector2D& u, float* pdf) const;
    float pdf(const GInteraction& ref, const QVector3D& wi) const;
    float solidAngle(const QVector3D &p, int nSamples = 512) const;

private:
    bool isValidPointInSphere(const QVector3D p) const;

public:
    const float m_radius;
    const float m_zMin;
    const float m_zMax;
    const float m_thetaMin;
    const float m_thetaMax;
    const float m_phiMax;

    // x = r * sin(theta) * cos(phi)
    // y = r * sin(theta) * sin(phi)
    // z = r * cos(theta)
};

#endif // GSPHERE_H
