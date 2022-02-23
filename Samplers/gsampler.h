#ifndef GSAMPLER_H
#define GSAMPLER_H

#include <QtMath>
#include <QVector2D>

class GSampler
{
public:
    GSampler();
    virtual ~GSampler();
    virtual float Get1D() = 0;
    virtual QVector2D Get2D() = 0;
};

#endif // GSAMPLER_H
