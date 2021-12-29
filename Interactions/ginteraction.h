#ifndef GINTERACTION_H
#define GINTERACTION_H

#include "qtinclude.h"
#include "Medium/gmediuminterface.h"
#include "Core/gray.h"

//class GMediumInterface;
class GMedium;
class GInteraction
{
public:
    GInteraction();
    GInteraction(const QVector3D& p, const QVector3D& n, const QVector3D& pError, const QVector3D& wOut, float time, const GMediumInterface& mediumInterface);
    GInteraction(const QVector3D& p, const QVector3D& wo, float time, const GMediumInterface& mediumInterface);
    GInteraction(const QVector3D& p, float time, const GMediumInterface &mediumInterface);
    bool isSurfaceInteraction() const;
    GRay spawnRay(const QVector3D& d) const;
    GRay spawnRayTo(const QVector3D& p) const;
    GRay spawnRayTo(const GInteraction &it) const;
    bool isMediumInteraction() const;
    const GMedium* medium(const QVector3D &w) const;
    const GMedium* medium() const;

public:
    QVector3D m_point;
    QVector3D m_normal;
    QVector3D m_wOut; //出去的方向
    QVector3D m_pError; //误差项
    float m_time;
    GMediumInterface m_mediumInterface; //介质表面
};

#endif // GINTERACTION_H
