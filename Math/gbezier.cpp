#include "gbezier.h"
#include "Math/gmath.h"

GBezier::GBezier()
{

}

GBezier::GBezier(QList<QVector3D> &pts)
{
    m_coefficient.clear();
    int m = pts.size() - 1;

    for(int i = 0; i <= m; ++i)
    {
        int c = this->c(m, i);
        m_coefficient.append(pts.at(i)*c);
    }
}

QVector3D GBezier::value(QList<QVector3D> &pts, float t)
{
    QList<QVector3D> list = pts;
    int n = pts.size();

    for(int j = n - 1; j > 0; j--)
    {
        for(int i = 0; i < j; ++i)
        {
            QVector3D a = pts.at(i);
            QVector3D b = pts.at(i+1);
            list[i] = GMath::lerp(a,b,t);
        }
    }

    return list[0];
}

// 0<t<1
QVector3D GBezier::value(float t)
{
    QVector3D ret;
    int n = m_coefficient.size() - 1;
    for(int i = 0; i < m_coefficient.size(); ++i)
    {
        // pt(i)*C(n,i)*(1-t)^(n-i)*(t^i)
        ret += m_coefficient[i]*GMath::pow(1.0f-t,n-i)*GMath::pow(t,i);
    }
    return ret;
}

int GBezier::c(int m, int n)
{
    if(n == 0) return 1;
    if(n == m) return 1;

    int ret = m;
    int i = 1;
    int j = 2;

    while(i <= n)
    {
        while( j <= n && ret%j == 0)
        {
            ret /= j;
            j++;
        }

        ret *= (m - i);
        i++;
    }

    return ret;
}
