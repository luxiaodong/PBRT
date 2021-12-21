#ifndef GRAY_H
#define GRAY_H

#include <QVector3D>

class GRay
{
public:
    GRay(QVector3D& origin, QVector3D& direction);

public:
    QVector3D m_origin;
    QVector3D m_direction;
};

#endif // GRAY_H
