#include "widget.h"
#include "Core/gscene.h"
#include "Integrators/gintegrator.h"
#include "Core/goptions.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent) , m_width(600) , m_height(600) , m_drawOnce(0)
{
    this->resize(m_width, m_height);
}

void Widget::parsePbrtFile(GScene& scene)
{
    QString filePath("/Users/luxiaodong/Project/Temp/pbrt-v3/scenes/killeroo-simple.pbrt");
}

void Widget::renderToImage(QImage& image)
{
//    GScene scene;
//    this->parsePbrtFile(scene);

//    GIntegrator* integrator = this->createIntegrator();
//    integrator->render(scene);
}

void Widget::paintEvent(QPaintEvent *)
{
    qDebug()<<m_drawOnce;
    m_drawOnce++;
    if(m_drawOnce == 3)
    {
        QImage image(m_width, m_height, QImage::Format_RGBA8888);
        this->renderToImage(image);
        QPainter painter(this);
        painter.drawImage(QRectF(0,0,m_width,m_height), image);
    }
}

//---------------------------------------------------------------------
GIntegrator* Widget::createIntegrator()
{
    GCamera* camera = this->createCamera();
    GSampler* sample = this->createSampler();

    //
    GIntegrator* integrator = new GSamplerIntegrator(sample, camera);
    return integrator;
}

GCamera* Widget::createCamera()
{
    // filmParams
//    GFilm* film = new GFilm(GOptions::film_resolution, GOptions::film_viewPort);

    // cameraParams
    // GCamera(const GAnimatedTransform& cameraToWorld, float shutterOpen, float shutterClose, GFilm *film, const GMedium* medium);
//    GCamera* camera = new GCamera(film);
//    return camera;
    return NULL;
}

GSampler* Widget::createSampler()
{
    GSampler* sample = new GSampler();
    return sample;
}

Widget::~Widget()
{
}
