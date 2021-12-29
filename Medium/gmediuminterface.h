#ifndef GMEDIUMINTERFACE_H
#define GMEDIUMINTERFACE_H

#include "Medium/gmedium.h"

class GMediumInterface
{
public:
    GMediumInterface();
    GMediumInterface(const GMedium *medium);
    GMediumInterface(const GMedium *inside, const GMedium *outside);
    bool isMediumTransition() const;

public:
    const GMedium* m_inside;
    const GMedium* m_outside;
};

#endif // GMEDIUMINTERFACE_H
