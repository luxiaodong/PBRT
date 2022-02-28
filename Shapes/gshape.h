#ifndef GSHAPE_H
#define GSHAPE_H

#include "qtinclude.h"
#include "Math/gmath.h"
#include "Math/gbound3d.h"
#include "Interactions/ginteraction.h"
// #include "Interactions/gsurfaceinteraction.h"

//class GShape
//{
//    static int m_shapeCount;
//public:
//    GShape(const QMatrix4x4* objectToWorld, const QMatrix4x4* worldToObject, bool reverseOrientation);
//    virtual ~GShape();
//    virtual GBound3D objectBound() const = 0;
//    virtual GBound3D worldBound() const;
//    virtual bool intersect(const GRay &ray, float *tHit, GInteraction *isect, bool testAlphaTexture = true) const = 0;
//    virtual bool intersectP(const GRay &ray, bool testAlphaTexture = true) const;
//    virtual float area() const = 0;
//    virtual GInteraction sample(const QVector2D& u, float* pdf) const = 0;
//    virtual GInteraction sample(const GInteraction& ref, const QVector2D& u, float* pdf) const;
//    virtual float pdf(const GInteraction& ref) const;
//    virtual float pdf(const GInteraction& ref, const QVector3D& wi) const;
//    virtual float solidAngle(const QVector3D &p, int nSamples = 512) const;

//public:
//    const QMatrix4x4* m_objectToWorld;
//    const QMatrix4x4* m_worldToObject;
//    bool m_reverseNormal;
//    bool m_isSwapHandedness;
//};

class GShape
{
public:
    GShape();
    virtual ~GShape();
    virtual GBound3D objectBound() const = 0;
    virtual void setTransformMatrix(QVector3D pos, QVector3D degree, QVector3D scale);
    virtual bool intersect(const GRay &ray, float *tHit, GInteraction *isect) const = 0;

public:
    QMatrix4x4 m_objectToWorld;
    QMatrix4x4 m_worldToObject;
};

#endif // GSHAPE_H
