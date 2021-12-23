#ifndef GANIMATEDTRANSFORM_H
#define GANIMATEDTRANSFORM_H

#include "gconstants.h"
#include "Math/gmath.h"
#include "Math/gbound3d.h"

class GAnimatedTransform
{
public:
    GAnimatedTransform();

    static void decompose(const QMatrix4x4& m, QVector3D *t, QVector3D *s, QQuaternion* r);
    QMatrix4x4 interpolate(float time);

    GBound3D motionBounds(const GBound3D& b);
    GBound3D motionBounds(const QVector3D& p);


public:
    float m_startTime;
    float m_endTime;

    QVector3D m_startT;
    QVector3D m_endT;
    QVector3D m_startS;
    QVector3D m_endS;
    QQuaternion m_startQ;
    QQuaternion m_endQ;
    QMatrix4x4 m_startM;
    QMatrix4x4 m_endM;
};

#endif // GANIMATEDTRANSFORM_H
