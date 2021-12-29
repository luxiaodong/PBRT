#ifndef GBOXFILTER_H
#define GBOXFILTER_H

#include "Filter/gfilter.h"

class GBoxFilter : public GFilter
{
public:
    GBoxFilter(const QVector2D& radius);
    float evaluate(const QVector2D &p) const;
};

GBoxFilter* createBoxFilter();

#endif // GBOXFILTER_H
