#ifndef GFILM_H
#define GFILM_H

#include "qtinclude.h"
#include "Filter/gfilter.h"

class GFilm
{
public:
    //图片大小, 渲染到哪个区域, 基本上(0,0,1,1)
    GFilm(const QSize& resolution, const QRectF& cropWindow, GFilter* filter, float diagonal, int scale, float maxSampleLuminance);

public:
    QRect sampleBounds();

public:
    QRect m_croppedPixelBounds;
    const QSize m_fullResolution;
    GFilter* m_filter;
    const float m_diagonal;
    const float m_scale;
    const float m_maxSampleLuminance;
};

#endif // GFILM_H
