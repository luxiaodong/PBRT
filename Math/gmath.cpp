#include "gmath.h"
#include <QDebug>

float GMath::m_pi = 3.1415926f;
float GMath::m_epsilon = 0.000001f;

GMath::GMath()
{

}

void GMath::testDecompositionTRS()
{
    QMatrix4x4 r = GMath::createRotateMatrix(QVector3D(30, 45, 60));
    QMatrix4x4 s(1,0,0,0,
                 0,0,0,0,
                 0,0,3,0,
                 0,0,0,1);
qDebug()<<r;
    QMatrix4x4 m = r*s;
qDebug()<<m;

//方法3
    float sx = m.map(QVector4D(1,0,0,0)).toVector3D().length();
    float sy = m.map(QVector4D(0,1,0,0)).toVector3D().length();
    float sz = m.map(QVector4D(0,0,1,0)).toVector3D().length();
    qDebug()<<sx<<sy<<sz;
    //分解后的矩阵不保证唯一性,只保证乘积的矩阵是对的
    //需要检查是否为负数,用行列式检查,如果是则任意轴添加一个负数即可
    //检查是否为0.如果有两个0

//方法2,用四元素
    QVector3D forward = m.column(2).toVector3D();
    QVector3D up = m.column(1).toVector3D();
    QQuaternion q2 = QQuaternion::fromDirection(forward, up);
qDebug()<<q2.toRotationMatrix();

//方法1,迭代
    for(int i=0; i<100; ++i)
    {
        QMatrix4x4 mt = m.transposed().inverted();
        m = (m + mt)/2;
    }
qDebug()<<m;
}


float GMath::abs(float value)
{
    return static_cast<float>(qAbs(static_cast<double>(value)));
}

float GMath::sqrt(float value)
{
    return static_cast<float>(qSqrt(static_cast<double>(value)));
}

float GMath::sin(float value)
{
    return static_cast<float>(qSin(static_cast<double>(value)));
}

float GMath::cos(float value)
{
    return static_cast<float>(qCos(static_cast<double>(value)));
}

float GMath::asin(float value)
{
    return static_cast<float>(qAsin(static_cast<double>(value)));
}

float GMath::tan(float value)
{
    return static_cast<float>(qTan(static_cast<double>(value)));
}

float GMath::acos(float value)
{
    return static_cast<float>(qAcos(static_cast<double>(value)));
}

float GMath::atan2(float y, float x)
{
    return static_cast<float>(qAtan2(static_cast<double>(y), static_cast<double>(x)));
}

float GMath::clamp(float a, float b, float t)
{
    if(t < a) return a;
    if(t > b) return b;
    return t;
}

float GMath::clamp(float f)
{
    return clamp(0.0f, 1.0f, f);
}

QVector3D GMath::clamp(const QVector3D& v)
{
    float x = clamp(v.x());
    float y = clamp(v.y());
    float z = clamp(v.z());
    return QVector3D(x,y,z);
}

QVector3D GMath::toVector(const QColor& c)
{
    float x = static_cast<float>(c.redF());
    float y = static_cast<float>(c.greenF());
    float z = static_cast<float>(c.blueF());
    return QVector3D(x,y,z);
}

QColor GMath::toColor(const QVector3D& v)
{
    QVector3D cv = clamp(v);
    int r = static_cast<int>(cv.x()*255);
    int g = static_cast<int>(cv.y()*255);
    int b = static_cast<int>(cv.z()*255);
    return QColor(r,g,b);
}

QVector2D GMath::normalToUv(const QVector3D& n)
{
    float theta = GMath::acos(n.y()); //(0, pi)
    float phi = GMath::atan2(n.z(), n.x()); //(-pi, pi]
    phi += G_PI;
    return QVector2D(phi/2/G_PI , theta/G_PI);
}

QVector3D GMath::uvToNormal(const QVector2D& uv)
{
    float phi = 2*m_pi*uv.x();
//    float theta = G_PI*uv.y(); // 非均匀分布
//    float theta = qACos(1 - uv.y()); //均匀分布
//    float theta = 2*qAcos(qSqrt(1- uv.y())); // 余弦均匀分布
    float theta = GMath::acos(1 - 2*uv.y()); //余弦均匀分布,等同于上面
    return QVector3D( GMath::sin(theta)*GMath::cos(phi), GMath::sin(theta)*GMath::sin(phi), GMath::cos(theta));
}

float GMath::lerp(float a, float b, float p)
{
    return a + (b-a)*p;
}

QVector3D GMath::lerp(const QVector3D& a,const QVector3D& b, float p)
{
    p = GMath::clamp(p);
    return a + (b-a)*p;
}

QColor GMath::lerp(const QColor& a,const QColor& b, float p)
{
    QVector3D va = GMath::toVector(a);
    QVector3D vb = GMath::toVector(b);

    QVector3D v = GMath::lerp(va, vb, p);
    float w = GMath::lerp(static_cast<float>(a.alphaF()), static_cast<float>(b.alphaF()), p);
//    return QColor(v.x()*255, v.y()*255, v.z()*255, w*255);
    return QColor( static_cast<int>(v.x()*255), static_cast<int>(v.y()*255), static_cast<int>(v.z()*255), static_cast<int>(w*255));
}

QVector3D GMath::min(const QVector3D& a,const QVector3D& b)
{
    float x = qMin(a.x(), b.x());
    float y = qMin(a.y(), b.y());
    float z = qMin(a.z(), b.z());
    return QVector3D(x,y,z);
}

QVector3D GMath::max(const QVector3D& a,const QVector3D& b)
{
    float x = qMax(a.x(), b.x());
    float y = qMax(a.y(), b.y());
    float z = qMax(a.z(), b.z());
    return QVector3D(x,y,z);
}

bool GMath::quadratic(float a, float b, float c, float& t0, float& t1)
{
    float delta = b*b - 4*a*c;
    if(delta < 0) return false;

    t0 = (-b-GMath::sqrt(delta))/(2*a);
    t1 = (-b+GMath::sqrt(delta))/(2*a);
    if(t0 > t1) qSwap(t0, t1);
    return true;
}

float GMath::randomZeroToOne()
{
    return qrand()/RAND_MAX;
}

float GMath::randomMinusToOne()
{
    return 2.0f*GMath::randomZeroToOne() - 1.0f;
}

QMatrix4x4 GMath::createRotateMatrix(QVector3D degree)
{
    float xRadians = qDegreesToRadians(degree.x());
    float yRadians = qDegreesToRadians(degree.y());
    float zRadians = qDegreesToRadians(degree.z());

    QMatrix4x4 xMat(
                1.0,            0.0,             0.0, 0.0,
                0.0, GMath::cos(xRadians), -GMath::sin(xRadians), 0.0,
                0.0, GMath::sin(xRadians),  GMath::cos(xRadians), 0.0,
                0.0,            0.0,             0.0, 1.0
                );

    QMatrix4x4 yMat(
                GMath::cos(yRadians),  0.0, GMath::sin(yRadians), 0.0,
                0.0,             1.0,            0.0, 0.0,
                -GMath::sin(yRadians), 0.0, GMath::cos(yRadians), 0.0,
                0.0,             0.0,            0.0, 1.0
                );

    QMatrix4x4 zMat(
                GMath::cos(zRadians), -GMath::sin(zRadians), 0.0, 0.0,
                GMath::sin(zRadians),  GMath::cos(zRadians), 0.0, 0.0,
                0.0,            0.0,             1.0, 0.0,
                0.0,            0.0,             0.0, 1.0
                );

    QMatrix4x4 mat = yMat*xMat*zMat;
    return mat;
}

QMatrix4x4 GMath::createWorldToViewMatrix(QVector3D position, float xDegree, float yDegree, float zDegree)
{
    QMatrix4x4 zflip(
                1.0, 0.0,  0.0, 0.0,
                0.0, 1.0,  0.0, 0.0,
                0.0, 0.0, -1.0, 0.0,
                0.0, 0.0,  0.0, 1.0
                );

    QMatrix4x4 pos(
                1.0, 0.0, 0.0, -position.x(),
                0.0, 1.0, 0.0, -position.y(),
                0.0, 0.0, 1.0, -position.z(),
                0.0, 0.0, 0.0,           1.0
                );

    QMatrix4x4 xyzMat = GMath::createRotateMatrix(QVector3D(xDegree, yDegree, zDegree));
    QMatrix4x4 mat = zflip*xyzMat.inverted()*pos;
    return mat;
}

QMatrix4x4 GMath::createWorldToViewMatrix(QVector3D position, QVector3D forward, QVector3D up)
{
    QVector3D right = QVector3D::crossProduct(up, forward).normalized();
    QVector3D up2 = QVector3D::crossProduct(forward, right).normalized();

    QMatrix4x4 view(
                right.x(), up2.x(), forward.x(), 0.0,
                right.y(), up2.y(), forward.y(), 0.0,
                right.z(), up2.z(), forward.z(), 0.0,
                      0.0,     0.0,         0.0, 1.0
                );

    QMatrix4x4 pos(
                1.0, 0.0, 0.0, -position.x(),
                0.0, 1.0, 0.0, -position.y(),
                0.0, 0.0, 1.0, -position.z(),
                0.0, 0.0, 0.0,           1.0
                );

    QMatrix4x4 zflip(
                1.0, 0.0,  0.0, 0.0,
                0.0, 1.0,  0.0, 0.0,
                0.0, 0.0, -1.0, 0.0,
                0.0, 0.0,  0.0, 1.0
                );

    QMatrix4x4 mat = zflip*view.inverted()*pos;
    return mat;
}

QMatrix4x4 GMath::createOrthogonalMatrix(float size, float aspect, float n, float f)
{
    QMatrix4x4 mat(
        1.0f/(aspect*size),      0.0f,          0.0f,          0.0f,
                0.0f,       1.0f/size,          0.0f,          0.0f,
                0.0f,            0.0f,       2/(f-n),   (n+f)/(f-n),
                0.0f,            0.0f,          0.0f,         1.0f);

    QMatrix4x4 zflip(
                1.0, 0.0,  0.0, 0.0,
                0.0, 1.0,  0.0, 0.0,
                0.0, 0.0, -1.0, 0.0,
                0.0, 0.0,  0.0, 1.0
                );

    return zflip*mat;
}

QMatrix4x4 GMath::createProjectionMatrix(float fov, float aspect, float n, float f)
{
    // z in [-n,f]
    float tan = GMath::tan( qDegreesToRadians(fov/2) );
    QMatrix4x4 mat(
        1.0f/(aspect*tan),       0.0f,          0.0f,          0.0f,
                0.0f,        1.0f/tan,          0.0f,          0.0f,
                0.0f,            0.0f,   (f+n)/(f-n),   2*n*f/(f-n),
                0.0f,            0.0f,         -1.0f,         0.0f);

    // 逆矩阵.
    // 1/A
    //     1/B
    //          0    -1
    //          1/D  C/D

    QMatrix4x4 zflip(
                1.0, 0.0,  0.0, 0.0,
                0.0, 1.0,  0.0, 0.0,
                0.0, 0.0, -1.0, 0.0,
                0.0, 0.0,  0.0, 1.0
                );

    return zflip*mat;
}

