#ifndef GSURFACEINTERACTION_H
#define GSURFACEINTERACTION_H

#include "Interactions/ginteraction.h"

class GSurfaceInteraction : public GInteraction
{
public:
    GSurfaceInteraction();

public:
    QVector2D m_uv; //曲面参数化uv坐标
    QVector3D m_dpdu; //点p处对u的偏导数
    QVector3D m_dpdv;
    QVector3D m_dndu; //法向量的u的偏导数
    QVector3D m_dndv;

    // const Shape *shape = nullptr; //还有其他
    // const Primitive
};

#endif // GSURFACEINTERACTION_H
