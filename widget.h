#ifndef WIDGET_H
#define WIDGET_H

#include "qtinclude.h"
#include "Core/gscene.h"
#include "Integrators/gintegrator.h"
#include "Integrators/gsamplerintegrator.h"
#include "Cameras/gcamera.h"
#include "Core/gfilm.h"
#include "Samplers/gsampler.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void paintEvent(QPaintEvent*);

private:
    void parsePbrtFile(GScene&);
    void renderToImage(QImage&);

private:
    GIntegrator* createIntegrator();
    GCamera* createCamera();
    GSampler* createSampler();

private:
    int m_width;
    int m_height;
    int m_drawOnce;
};

#endif // WIDGET_H
