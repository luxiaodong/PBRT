#include "gsamplerintegrator.h"
#include <QVector2D>

GSamplerIntegrator::GSamplerIntegrator()
{
}

GSamplerIntegrator::GSamplerIntegrator(GSampler* sample, GCamera* camera)
{
    m_pSampler = sample;
    m_pCamera = camera;
}

void GSamplerIntegrator::render(const GScene &scene)
{
    QSize resolutionSize = m_pCamera->m_pFilm->resolution();
    float pixelSize = m_pCamera->m_pFilm->m_pixelSize;
    for(int j = 0; j < resolutionSize.height(); ++j)
    {
        float y = pixelSize * ((resolutionSize.height() - 1 - j) - resolutionSize.height()/2.0f + 0.5f);
        for(int i = 0; i < resolutionSize.width(); ++i)
        {
            float x = pixelSize * (i - resolutionSize.width()/2.0f + 0.5f);
            QVector2D posInFilm = QVector2D(x, y);
            GRay ray = m_pCamera->generateRay(posInFilm);
            GSpectrum spectrum = this->trace(ray, scene);
            m_pCamera->m_pFilm->setPixel(i, j, spectrum.m_color);
        }
    }

//    QVector2D posInFilm = QVector2D(1, 1);
//    GRay ray = m_pCamera->generateRay(posInFilm);
//qDebug()<<ray.m_origin;
//qDebug()<<ray.m_direction;
//    GSpectrum spectrum = this->trace(ray, scene);
//    m_pCamera->m_pFilm->setPixel(1, 1, spectrum.m_color);

}

GSpectrum GSamplerIntegrator::trace(GRay& ray, const GScene &scene)
{
    GSpectrum spectrum;
    GInteraction interaction;
    if(scene.intersect(ray, interaction) == false)
    {
        return spectrum;
    }

    //点找到了,开始着色.

    spectrum.m_color = Qt::white;
    return spectrum;
}

GSamplerIntegrator::~GSamplerIntegrator()
{}
