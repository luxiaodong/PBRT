#ifndef GLIGHT_H
#define GLIGHT_H

#include "Core/gspectrum.h"

class GLight
{
public:
    GLight();
    void setTransformMatrix(QVector3D pos);
    QVector3D direction(QVector3D pos);

public:
    GSpectrum m_spectrum;
    QMatrix4x4 m_lightToWorld;
    QMatrix4x4 m_worldToLight;
};

#endif // GLIGHT_H
