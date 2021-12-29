#ifndef GFILTER_H
#define GFILTER_H

#include <QVector2D>

class GFilter
{
public:
    GFilter(const QVector2D& radius);
    virtual float evaluate(const QVector2D& p) const = 0;

public:
    const QVector2D m_radius;
    const QVector2D m_invRadius;
};

#endif // GFILTER_H
