#ifndef GSURFACEINTERACTION_H
#define GSURFACEINTERACTION_H

#include "Interactions/ginteraction.h"
#include "Shapes/gshape.h"
#include "Core/graydifferential.h"

class GShape;
class GSurfaceInteraction : public GInteraction
{
public:
    GSurfaceInteraction();
    GSurfaceInteraction(const QVector3D &p, const QVector3D &pError, const QVector2D &uv, const QVector3D &wo,
                        const QVector3D &dpdu, const QVector3D &dpdv, const QVector3D &dndu, const QVector3D &dndv, float time, const GShape* shape, int faceIndex = 0);
    void shadingGeometry(const QVector3D &dpdu, const QVector3D &dpdv, const QVector3D &dndu, const QVector3D &dndv, bool orientationIsAuthoritative);
    void computeScatteringFunctions(const GRayDifferential& ray, GMemoryArena& arena, bool allowMultipleLobes, int transportMode);
    void computeDifferentials(const GRayDifferential &r) const;
    GSpectrum le(const QVector3D &w) const;

public:
    QVector2D m_uv; //曲面参数化uv坐标
    QVector3D m_dpdu; //点p处对u的偏导数
    QVector3D m_dpdv;
    QVector3D m_dndu; //法向量的u的偏导数
    QVector3D m_dndv;
    const GShape* m_shape;
    int m_faceIndex;

    // const Shape *shape = nullptr; //还有其他
    // const Primitive
};

#endif // GSURFACEINTERACTION_H
