#include "gbspline.h"

GBSpline::GBSpline()
{

}

GBSpline::GBSpline(QList<float> &us, QList<QVector3D> &pts, int degree)
{
    m_us = us;
    m_points = pts;
    m_degree = qMin(m_points.size() - 2, degree); //n个点,n-1个区间,n-2次多项式
}

QVector3D GBSpline::value(float t)
{
    QVector3D ret;
    for(int i = 0; i < m_points.size() - m_degree - 1; ++i)
    {
        ret +=  m_points.at(i) * this->value(i, m_degree, m_us.size() - 1, t);
    }

    return ret;
}

float GBSpline::value(int i, int p, int n, float u)
{
    if(p == 0)
    {
        if( m_us.at(i) < u && u < m_us.at(i+1) ) return 1.0f;
        return 0.0f;
    }

    float n_i0 = this->value(i, p - 1, n, u);
    float n_i1 = this->value(i+1, p-1, n, u);
    float c0 = (u - m_us.at(i) )/(m_us.at(i+p) - m_us.at(i));
    float c1 = (m_us.at(i+p+1) - u)/(m_us.at(i+p+1) - m_us.at(i+1));
    return c0*n_i0 + c1*n_i1;
}
