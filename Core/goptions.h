#ifndef GOPTIONS_H
#define GOPTIONS_H

#include "qtinclude.h"

class GOptions
{
public:
    static QString camera_type;
    static QString film_type;
    static QSize film_resolution;
    static QRectF film_cropwindow;
    static QString sampler_type;
    static int sampler_pixel;
    static QString integrator_type;
};

#endif // GOPTIONS_H
