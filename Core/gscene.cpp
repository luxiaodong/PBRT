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
    pri->m_shape = new GSphere(3.0,-100, 100, 100);
    m_primitives.append(pri);
}

bool GScene::intersect(const GRay &ray, GInteraction &inter) const
{
    return false;
}
