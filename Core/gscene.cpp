#include "gscene.h"
#include "Shapes/gsphere.h"

GScene::GScene()
{
    m_lights.clear();
    m_primitives.clear();
}

void GScene::createTestScene()
{
    GPrimitive* pri = new GPrimitive();
    pri->m_shape = new GSphere(3.0, -3.0, 3.0, 360);
    pri->m_shape->setTransformMatrix(QVector3D(0,0,5),QVector3D(0,0,0), QVector3D(1,1,1));
    m_primitives.append(pri);

    GLight* light = new GLight();
    light->setTransformMatrix(QVector3D(0,0,-5));
    light->m_spectrum = GSpectrum::m_rgbRefl2SpectCyan;
    m_lights.append(light);
}

bool GScene::intersect(const GRay &ray, GInteraction &inter) const
{
    float nearT = 100.0f;
    GInteraction nearInter;
    bool ret = false;
    foreach(GPrimitive* pri, m_primitives)
    {
        float t;
        GInteraction temp;
        if( pri->m_shape->intersect(ray, temp, t) )
        {
            if(t < nearT)
            {
                nearT = t;
                nearInter = temp;
                nearInter.m_pPrimitive = pri;
                ret = true;
            }
        }
    }

    inter = nearInter;
    return ret;
}
