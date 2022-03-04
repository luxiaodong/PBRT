#include "glight.h"

GLight::GLight()
{

}

void GLight::setTransformMatrix(QVector3D pos)
{
    QMatrix4x4 matT;
    matT.translate(pos);

    m_lightToWorld = matT;
    m_worldToLight = m_lightToWorld.inverted();
}

QVector3D GLight::direction(QVector3D pos)
{
//    QVector3D dir = m_worldToLight*pos;
//    return dir.normalized();
    (void)pos;
    QVector3D dir(0,0,1);
    QVector3D outDir = m_lightToWorld.mapVector(dir);
    return outDir;
}
