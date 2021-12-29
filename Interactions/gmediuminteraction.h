#ifndef GMEDIUMINTERACTION_H
#define GMEDIUMINTERACTION_H

#include "qtinclude.h"
#include "Medium/gphasefunction.h"
#include "Medium/gmedium.h"
#include "Interactions/ginteraction.h"

class GMedium;
class GMediumInteraction : public GInteraction
{
public:
    GMediumInteraction();
    GMediumInteraction(const QVector3D &p, const QVector3D &wo, float time, const GMedium* medium, const GPhaseFunction *phase);
    bool isValid() const;
public:
    const GPhaseFunction* m_phase;
};

#endif // GMEDIUMINTERACTION_H
