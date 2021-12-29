#include "gmediuminterface.h"

GMediumInterface::GMediumInterface():m_inside(NULL),m_outside(NULL)
{
}

GMediumInterface::GMediumInterface(const GMedium *medium)
{
    m_inside = medium;
    m_outside = medium;
}

GMediumInterface::GMediumInterface(const GMedium *inside, const GMedium *outside)
{
    m_inside = inside;
    m_outside = outside;
}

bool GMediumInterface::isMediumTransition() const
{
    return m_inside != m_outside;
}

