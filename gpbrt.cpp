#include "gpbrt.h"
#include "Samplers/gpixelsampler.h"
#include "Integrators/gsamplerintegrator.h"

GPBRT::GPBRT()
{
    m_pScene = nullptr;
    m_pIntegrator = nullptr;
    m_pCamera = nullptr;
    m_pSampler = nullptr;
}

void GPBRT::init()
{
    m_pFilm = new GFilm();
    m_pScene = this->createScene();
    m_pCamera = this->createCamera();
    m_pSampler = this->createSampler();
    m_pIntegrator = this->createIntegrator();
}

void GPBRT::rendering(QString& filePath)
{
    m_pIntegrator->render(*m_pScene);
    m_pFilm->save(filePath);
}

// -------------------------------------------------------------

GScene* GPBRT::createScene()
{
    GScene* scene = new GScene();
    scene->createTestScene();
    return scene;
    // 创建灯光和物体
}

GCamera* GPBRT::createCamera()
{
    return new GCamera(m_pFilm);
}

GSampler* GPBRT::createSampler()
{
    return new GPixelSampler();
}

GIntegrator* GPBRT::createIntegrator()
{
    return new GSamplerIntegrator(m_pSampler, m_pCamera);
}
