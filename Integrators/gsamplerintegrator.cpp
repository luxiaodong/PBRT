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
        float y = pixelSize * (j - resolutionSize.width()/2.0f + 0.5f);
        for(int i = 0; i < resolutionSize.width(); ++i)
        {
            float x = pixelSize * (i - resolutionSize.width()/2.0f + 0.5f);
            QVector2D posInFilm = QVector2D(x, y);
            GRay ray = m_pCamera->generateRay(posInFilm);
            //光线和场景求交点
        }
    }
}

GSamplerIntegrator::~GSamplerIntegrator()
{}
