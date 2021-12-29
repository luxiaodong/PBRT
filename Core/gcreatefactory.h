#ifndef GCREATEFACTORY_H
#define GCREATEFACTORY_H

#include "qtinclude.h"

class GCamera;
class GFilm;
class GFilter;

class GCreateFactory
{
public:
    static GFilter* createFilter();
    static GFilm*   createFilm();
    static GCamera* createCamera();
};

#endif // GCREATEFACTORY_H
