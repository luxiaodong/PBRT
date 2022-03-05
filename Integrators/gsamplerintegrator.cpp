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
            QColor color = GMath::toColor(spectrum.toSRGB());
            m_pCamera->m_pFilm->setPixel(i, j, color);
        }
    }

//    QVector2D posInFilm = QVector2D(0, 0);
//    GRay ray = m_pCamera->generateRay(posInFilm);
//    GSpectrum spectrum = this->trace(ray, scene);
//    QColor color = GMath::toColor(spectrum.toRGB());
//    m_pCamera->m_pFilm->setPixel(1, 1, color);
}

GSpectrum GSamplerIntegrator::trace(GRay& ray, const GScene &scene)
{
    GSpectrum spectrum;
    GInteraction interaction;
    if(scene.intersect(ray, interaction) == false) //跟场景没有交点
    {
        return spectrum;
    }

    //计算材质上的

    //命中的是区域光

    //计算着色,遍历每盏灯
    foreach(GLight* light, scene.m_lights)
    {
        GSpectrum ls = light->m_spectrum; //源代码是采样计算出来的
        if(ls.isBlack()) continue; //没有颜色
        // 这里要计算brdf的系数f
        // pdf是什么
        GSpectrum f = GSpectrum::m_rgbRefl2SpectCyan;
        QVector3D wi = light->direction(interaction.m_point);
        spectrum += f * ls * GMath::abs( QVector3D::dotProduct(wi, interaction.m_normal) );
    }

    return spectrum;
}

GSamplerIntegrator::~GSamplerIntegrator()
{}
