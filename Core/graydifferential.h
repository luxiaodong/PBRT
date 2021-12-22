#ifndef GRAYDIFFERENTIAL_H
#define GRAYDIFFERENTIAL_H

#include "Core/gray.h"

class GRayDifferential : public GRay
{
public:
    GRayDifferential(const QVector3D& origin, const QVector3D& direction);
    GRayDifferential(const GRay& ray);

public:
    void scaleDifferentials(float s);

public:
    bool m_hasDifferentials;

    QVector3D m_dxOrigin;
    QVector3D m_dyOrigin;
    QVector3D m_dxDirection;
    QVector3D m_dyDirection;
};

#endif // GRAYDIFFERENTIAL_H
