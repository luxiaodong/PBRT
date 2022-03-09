#ifndef GBSPLINE_H
#define GBSPLINE_H

#include <QList>
#include <QVector3D>

//https://www.cnblogs.com/icmzn/p/5100761.html

class GBSpline
{
public:
    GBSpline();
    GBSpline(QList<float> &us, QList<QVector3D> &pts, int degree); //控制点

    QVector3D value(float t);

private:
    float value(int i, int p, int n, float u);

private:
    QList<float> m_us;
    QList<QVector3D> m_points;
    int m_degree;
};

#endif // GBSPLINE_H
