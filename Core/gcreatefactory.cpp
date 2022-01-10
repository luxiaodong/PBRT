#include "gcreatefactory.h"
#include "Core/goptions.h"
#include "Filter/gboxfilter.h"
#include "Core/gfilm.h"
#include "Cameras/gcamera.h"

GFilter* GCreateFactory::createFilter()
{
    QString name = "box";
    if(name == "box")
        return createBoxFilter();

    return NULL;
}

GFilm* GCreateFactory::createFilm()
{
    GFilter* filter = GCreateFactory::createFilter();
    float diagonal = 35.0f;
    float scale = 1.0f;
    float maxSampleLuminance = 10000000.0f;
    return new GFilm(GOptions::film_resolution, GOptions::film_cropwindow, filter, diagonal, scale, maxSampleLuminance);

//    return new GFilm(GOptions::film_resolution, GOptions::film_viewPort);
    // return NULL;
}

GCamera* GCreateFactory::createCamera()
{
    return NULL;
}
