#include "gboxfilter.h"

GBoxFilter::GBoxFilter(const QVector2D& radius) : GFilter(radius)
{}

float GBoxFilter::evaluate(const QVector2D &p) const
{
    return 1.0;
}

GBoxFilter* createBoxFilter()
{
    return new GBoxFilter(QVector2D(0.5f,0.5f));
}
