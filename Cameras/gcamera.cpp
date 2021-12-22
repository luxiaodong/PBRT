#include "gcamera.h"

GCamera::GCamera()
{

}

GCamera::GCamera(GFilm* film)
{
    m_film = film;
}

bool GCamera::generateRay(const GSampler &sample, GRay& ray)
{
    return false;
}
