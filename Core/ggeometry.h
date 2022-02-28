#ifndef GGEOMETRY_H
#define GGEOMETRY_H

#include <QVector3D>
#include <QVector4D>

// 点线面交互信息
class GGeometry
{
public:
    GGeometry();

    // 平面表示: ax+by+cz+d=0,(a,b,c)是单位外法向量,d必须是负数,-d是(0,0,0)点到平面的距离
    // 直线表示: 一个点和一个向量,两个Vector3, 注:没有法向量概念
    // 圆的表示: 圆点和半径

    static int sign(float value);
    static float determinant3D(QVector3D &a, QVector3D &b, QVector3D &c);

    static QVector4D createPlane(QVector3D &n, QVector3D &p);
    static QVector4D createPlane(QVector3D &v1, QVector3D &v2, QVector3D &p);
    static QVector4D createPlaneByLineAndPoint(QVector3D &p0, QVector3D &dir, QVector3D &p1);
    static QVector4D createPlaneByThreePoint(QVector3D &p1, QVector3D &p2, QVector3D &p3);

    static int relationshipBetweenLineAndPoint(QVector3D &p0, QVector3D &dir, QVector3D &p1);
    static int relationshipBetweenPlaneAndline(QVector4D &plane, QVector3D &dir);
    static float signedDistanceBetweenPlaneAndPoint(QVector4D &plane, QVector3D &p);
    static int relationshipBetweenPlaneAndPoint(QVector4D &plane, QVector3D &p);

    static float distanceBetweenPlaneAndPoint(QVector4D &plane, QVector3D &p);
    static float distanceBetweenLineAndPoint(QVector3D &p0, QVector3D &dir, QVector3D &p1);

    static QVector3D crossPointBetweenPlaneAndLine(QVector4D &plane, QVector3D &p0, QVector3D &dir);
    static QVector3D crossPointVerticalLine(QVector3D &p0, QVector3D &dir, QVector3D &p1);
};

#endif // GGEOMETRY_H
