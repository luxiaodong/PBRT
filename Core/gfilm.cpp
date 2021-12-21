#include "gfilm.h"

GFilm::GFilm()
{

}

GFilm::GFilm(QSize& resolution, QRectF& cropWindow) : m_fullResolution(resolution)
{
    int left = qFloor( m_fullResolution.width() * cropWindow.x() );
    int bottom = qFloor( m_fullResolution.height() * cropWindow.y() );
    int width = qCeil( m_fullResolution.width() * cropWindow.width() );
    int height = qCeil( m_fullResolution.height() * cropWindow.height() );
    m_croppedPixelBounds = QRect(left, bottom, width, height);
}
