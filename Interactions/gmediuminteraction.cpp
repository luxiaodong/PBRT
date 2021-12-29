#include "gmediuminteraction.h"

GMediumInteraction::GMediumInteraction() : m_phase(NULL)
{
}

GMediumInteraction::GMediumInteraction(const QVector3D &p, const QVector3D &wo, float time, const GMedium* medium, const GPhaseFunction *phase)
    : GInteraction(p, wo, time, medium), m_phase(phase)
{}

bool GMediumInteraction::isValid() const
{
    return m_phase != NULL;
}
