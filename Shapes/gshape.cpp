#include "gshape.h"

GShape::GShape()
{}

GShape::~GShape()
{}

void GShape::setTransformMatrix(QVector3D pos, QVector3D degree, QVector3D scale)
{
    QMatrix4x4 matT;
    matT.translate(pos);
    QMatrix4x4 matR = GMath::createRotateMatrix(degree);
    QMatrix4x4 matS;
    matS.scale(scale);

    QMatrix4x4 coord(
                1.0f, 0.0f, 0.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 1.0f, 0.0f, 0.0f,
                0.0f, 0.0f, 0.0f, 1.0f
                );

    m_objectToWorld = matT*matR*matS*coord;
    m_worldToObject = m_objectToWorld.inverted();
}

//GShape::GShape(const QMatrix4x4* objectToWorld, const QMatrix4x4* worldToObject, bool reverseOrientation)
//    : m_objectToWorld(objectToWorld) , m_worldToObject(worldToObject) , m_reverseNormal(reverseOrientation)
//{
//    m_isSwapHandedness = objectToWorld->determinant() < 0.0f;
////    m_shapeCount++;
//}

//GShape::~GShape()
//{}

//GBound3D GShape::worldBound() const
//{
//    //这是包围盒子整体转成世界坐标的包围盒子
//    //优化的办法是先转物体的顶点,再计算包围盒子
//    return objectBound().transform(*m_objectToWorld);
//}

//bool GShape::intersectP(const GRay &ray, bool testAlphaTexture) const
//{
//    return intersect(ray, NULL, NULL, testAlphaTexture);
//}

//float GShape::pdf(const GInteraction &) const
//{
//    return 1.0/area();
//}

//GInteraction GShape::sample(const GInteraction& ref, const QVector2D& u, float* pdf) const
//{
//    GInteraction a;
//    return a;
//}

//float GShape::pdf(const GInteraction& ref, const QVector3D& wi) const
//{
//    return 0.0f;
//}

//float GShape::solidAngle(const QVector3D &p, int nSamples) const
//{
//    return 2.0f;
//}

