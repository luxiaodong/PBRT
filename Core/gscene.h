#ifndef GSCENE_H
#define GSCENE_H

#include "gconstants.h"
#include "Lights/glight.h"
#include "Core/gprimitive.h"
#include "Math/gbound3d.h"
#include "Core/gray.h"

class GScene
{
public:
    GScene();

public:
    bool intersect(const GRay &ray) const; //检查是否与物体有交点

public:
    QList<GLight*> m_lights;
    QList<GPrimitive*> m_primitives;
    GBound3D m_worldBound;
};

#endif // GSCENE_H
