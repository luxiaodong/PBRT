#ifndef GINTEGRATOR_H
#define GINTEGRATOR_H

#include <QImage>
#include "Core/gscene.h"

class GIntegrator
{
public:
    GIntegrator();

    virtual void render(const GScene &scene, QImage &image);
    virtual ~GIntegrator();
};

#endif // GINTEGRATOR_H
