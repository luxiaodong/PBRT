#include "widget.h"

#include <QImage>
#include <QPainter>
#include <QRectF>
#include <QColor>
#include <QDebug>

#include "Core/gscene.h"
#include "Integrators/gintegrator.h"

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
    GScene scene;
    this->parsePbrtFile(scene);

    GIntegrator integrator;
    integrator.render(scene, image);
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

Widget::~Widget()
{

}
