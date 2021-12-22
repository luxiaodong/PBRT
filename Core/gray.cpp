#include "gray.h"

GRay::GRay(const QVector3D& origin,const QVector3D& direction) : m_origin(origin), m_direction(direction)
{

}

QVector3D GRay::operator()(float t)
{
    return m_origin + m_direction*t;
}
