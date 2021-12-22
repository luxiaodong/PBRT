#ifndef GFILM_H
#define GFILM_H

#include "gconstants.h"

class GFilm
{
public:
    GFilm();

    //图片大小, 渲染到哪个区域, 基本上(0,0,1,1)
    GFilm(const QSize& resolution, const QRectF& cropWindow);
public:
    QRect sampleBounds();

public:
    QRect m_croppedPixelBounds;
    QSize m_fullResolution;
};

#endif // GFILM_H
