#ifndef GRAY_H
#define GRAY_H

#include <QVector3D>
#include <QMatrix4x4>

class GRay
{
public:
    GRay();
    GRay(const QVector3D& origin, const QVector3D& direction);
    QVector3D operator()(float t) const;
    GRay transform(const QMatrix4x4& m) const;

public:
    QVector3D m_origin;
    QVector3D m_direction;
    float m_max;
    float m_time;
//    GMedium* medium; 媒介
};

#endif // GRAY_H
