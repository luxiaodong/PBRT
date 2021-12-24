#ifndef GPRIMITIVE_H
#define GPRIMITIVE_H

#include "Shapes/gshape.h"
#include "Materials/gmaterial.h"

class GPrimitive
{
public:
    GPrimitive();

public:
    GShape* m_shape;
    GMaterial* m_material;
};

#endif // GPRIMITIVE_H
