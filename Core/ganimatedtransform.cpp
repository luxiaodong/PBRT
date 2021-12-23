#include "ganimatedtransform.h"
#include "Math/gmath.h"

GAnimatedTransform::GAnimatedTransform()
{

}

void GAnimatedTransform::decompose(const QMatrix4x4& m, QVector3D *t, QVector3D *s, QQuaternion* q)
{
    t->setX(m(0,3));
    t->setY(m(1,3));
    t->setZ(m(2,3));

    s->setX(m.column(0).toVector3D().length());
    s->setY(m.column(1).toVector3D().length());
    s->setZ(m.column(2).toVector3D().length());

    QMatrix4x4 mt;
    mt.translate(*t);

    QMatrix4x4 ms;
    ms.scale(*s);

    QMatrix4x4 mr = mt.inverted() * m * ms.inverted();
    float data[9] = {mr(0,0), mr(0,1), mr(0,2),
                     mr(1,0), mr(1,1), mr(1,2),
                     mr(2,0), mr(2,1), mr(2,2)};
    QMatrix3x3 r(data);
    *q = QQuaternion::fromRotationMatrix(r);

//    QVector3D forward = m.column(2).toVector3D();
//    QVector3D up = m.column(1).toVector3D();
//    QQuaternion q2 = QQuaternion::fromDirection(forward, up);
}

QMatrix4x4 GAnimatedTransform::interpolate(float time)
{
    float dt = GMath::clamp((time - m_startTime) / (m_endTime - m_startTime));
    QVector3D t = GMath::lerp(m_startT, m_endT, dt);
    QVector3D s = GMath::lerp(m_startS, m_endS, dt);
    QQuaternion q = QQuaternion::slerp(m_startQ, m_endQ, dt);

    QMatrix4x4 m;
    m.scale(s);
    m.rotate(q);
    m.translate(t);
    return m;
}

GBound3D GAnimatedTransform::motionBounds(const GBound3D& b)
{
    //不动时
    //没有旋转时
    GBound3D bstart = b.transform(m_startM);
    GBound3D bend = b.transform(m_endM);
    return GBound3D::unionBound(bstart, bend);
    //有旋转时,时间采样计算,费性能, 优化：只8个顶点的轨迹, 各个方向求导数
}

// 计算一个点的轨迹构成的包围盒，有点难，用时再计算
GBound3D GAnimatedTransform::motionBounds(const QVector3D& p)
{
    GBound3D b;
    return b;
}

//float sx = m.map(QVector4D(1,0,0,0)).toVector3D().length();
//float sy = m.map(QVector4D(0,1,0,0)).toVector3D().length();
//float sz = m.map(QVector4D(0,0,1,0)).toVector3D().length();
//qDebug()<<sx<<sy<<sz;
