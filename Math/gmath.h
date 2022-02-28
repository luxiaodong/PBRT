#ifndef GMATH_H
#define GMATH_H

#define G_PI 3.1415926f

#include <QVector2D>
#include <QVector3D>
#include <QMatrix>
#include <QMatrix4x4>
#include <QColor>
#include <QtMath>
#include <QQuaternion>

class GMath
{
public:
    GMath();
    static float m_pi;
    static void testDecompositionTRS();

    static float clamp(float);
    static float clamp(float a, float b, float t);
    static QVector3D clamp(const QVector3D&);
    static QVector3D toVector(const QColor&);
    static QColor toColor(const QVector3D&);

    static QVector2D normalToUv(const QVector3D& n);
    static QVector3D uvToNormal(const QVector2D& uv);

    static float lerp(float a, float b, float p);
    static QVector3D lerp(const QVector3D& a, const QVector3D& b, float p);
    static QColor lerp(const QColor& a, const QColor& b, float p);

    static QVector3D min(const QVector3D& a,const QVector3D& b);
    static QVector3D max(const QVector3D& a,const QVector3D& b);

    static bool quadratic(float a, float b, float c, float& t0, float& t1);
    static float randomZeroToOne();
    static float randomMinusToOne();

    static QMatrix4x4 createRotateMatrix(QVector3D degree);
    static QMatrix4x4 createWorldToViewMatrix(QVector3D position, float xDegree, float yDegree, float zDegree);
    static QMatrix4x4 createWorldToViewMatrix(QVector3D position, QVector3D forward, QVector3D up);
    static QMatrix4x4 createOrthogonalMatrix(float size, float aspect, float n, float f);
    static QMatrix4x4 createProjectionMatrix(float fov, float aspect, float n, float f);
};

#endif // GMATH_H
