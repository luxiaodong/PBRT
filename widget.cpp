#include "widget.h"
#include "Core/gscene.h"
#include "Integrators/gintegrator.h"
#include "Core/goptions.h"
#include "Core/gparsepbrt.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QSize s = QSize(600,600);
    m_pImage = nullptr;
    this->resize(s);
}

Widget::~Widget()
{
}

void Widget::paintEvent(QPaintEvent *)
{
    if(m_pImage == nullptr)
    {
        QString filePath = QString("./test.png");
        GPBRT pbrt;
        pbrt.init();
        pbrt.rendering(filePath);

        QSize s = this->size();
        QImage image(filePath);
        m_pImage = new QImage(image.scaled(s));
    }

    QPainter painter(this);
    painter.drawImage(QPoint(0,0), *m_pImage);
}
