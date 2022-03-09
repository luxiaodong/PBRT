#ifndef GBEZIER_H
#define GBEZIER_H

// 贝塞尔曲线
#include <QList>
#include <QVector3D>

class GBezier
{
public:
    GBezier();
    GBezier(QList<QVector3D> &pts); //控制点

    static QVector3D value(QList<QVector3D> &pts, float t);
    QVector3D value(float t); //[0,1]内
    int c(int m, int n);

private:
    QList<QVector3D> m_coefficient; //基函数的系数
};

#endif // GBEZIER_H
