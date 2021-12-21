#ifndef GFILM_H
#define GFILM_H

#include <QSize>
#include <QRect>
#include <QRectF>
#include <QPoint>
#include <QtMath>

class GFilm
{
public:
    GFilm();

    //图片大小, 渲染到哪个区域, 基本上(0,0,1,1)
    GFilm(QSize& resolution, QRectF& cropWindow);

public:
    QRect m_croppedPixelBounds;
    QSize m_fullResolution;
};

#endif // GFILM_H
