#include "gfilm.h"
#include <QtDebug>
#include "Core/gcolorspace.h"

//GFilm::GFilm(const QSize& resolution, const QRectF& cropWindow, GFilter* filter, float diagonal, int scale, float maxSampleLuminance)
//    :m_fullResolution(resolution), m_filter(filter), m_diagonal(diagonal),m_scale(scale),m_maxSampleLuminance(maxSampleLuminance)
//{
//    int left = qFloor( m_fullResolution.width() * cropWindow.x() );
//    int bottom = qFloor( m_fullResolution.height() * cropWindow.y() );
//    int width = qCeil( m_fullResolution.width() * cropWindow.width() );
//    int height = qCeil( m_fullResolution.height() * cropWindow.height() );
//    m_croppedPixelBounds = QRect(left, bottom, width, height);
//}

//QRect GFilm::sampleBounds()
//{
//    return m_croppedPixelBounds;
//}

GFilm::GFilm()
{
    m_resolution = QSize(1024,1024);
//    m_resolution = QSize(2, 2);
    m_pixelSize = 0.01f;
    m_pImage = new QImage(m_resolution, QImage::Format_RGBA8888);
    m_pImage->fill(Qt::black);
}

QSize& GFilm::resolution()
{
    return m_resolution;
}

void GFilm::setPixel(int x, int y, QColor& color)
{
    m_pImage->setPixelColor(x, y, color);
}

void GFilm::save(QString& filePath)
{
//    QImage image = GColorSpace::imageCIE1931XYZ();
//    if(image.save(filePath))
    if(m_pImage->save(filePath))
    {
        qDebug()<<"saved succeeful.";
    }
    else
    {
        qDebug()<<"saved failed.";
    }
}

