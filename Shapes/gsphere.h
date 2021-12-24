#ifndef GSPHERE_H
#define GSPHERE_H

#include "Shapes/gshape.h"

class GSphere : public GShape
{
public:
    GSphere(const QMatrix4x4* objectToWorld, const QMatrix4x4* worldToObject, bool reverseOrientation, float radius, float zMin, float zMax, float phiMax);

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
