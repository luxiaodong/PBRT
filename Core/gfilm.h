#ifndef GFILM_H
#define GFILM_H

#include "qtinclude.h"
#include "Filter/gfilter.h"

//class GFilm
//{
//public:
//    //图片大小, 渲染到哪个区域, 基本上(0,0,1,1)
//    GFilm(const QSize& resolution, const QRectF& cropWindow, GFilter* filter, float diagonal, int scale, float maxSampleLuminance);

//public:
//    QRect sampleBounds();

//public:
//    QRect m_croppedPixelBounds;
//    const QSize m_fullResolution;
//    GFilter* m_filter;
//    const float m_diagonal;
//    const float m_scale;
//    const float m_maxSampleLuminance;
//};

class GFilm
{
public:
    GFilm();
    void save(QString& filePath);
    QSize& resolution();

public:
    QImage* m_pImage;
    QSize m_resolution; //渲染的分辨率
    float m_pixelSize;  //一个像素多少距离
};

#endif // GFILM_H
