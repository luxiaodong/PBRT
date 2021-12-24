#ifndef GINTERACTION_H
#define GINTERACTION_H

#include "gconstants.h"

class GInteraction
{
public:
    GInteraction();

public:
    QVector3D m_point;
    QVector3D m_normal;
    QVector3D m_wOut; //出去的方向
    float m_time;
    // MediumInterface. //散射介质
};

#endif // GINTERACTION_H
