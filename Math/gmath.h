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
};

#endif // GMATH_H
