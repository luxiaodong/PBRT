#ifndef GMATH_H
#define GMATH_H

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
    static constexpr float m_pi = 3.1415926f;
    static constexpr float m_epsilon = 0.000001f;
    static constexpr float m_maxFloat = std::numeric_limits<float>::max();
    //static PBRT_CONSTEXPR Float Infinity = std::numeric_limits<Float>::infinity();

    static void testDecompositionTRS();

    static float min(float a, float b);
    static float max(float a, float b);
    static float abs(float value);
    static float sqrt(float value);
    static float pow(float x, float y);
    static float sin(float value);
    static float cos(float value);
    static float tan(float value);
    static float asin(float value);
    static float acos(float value);
    static float atan2(float y, float x);

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
