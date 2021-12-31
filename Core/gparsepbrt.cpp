#include "gparsepbrt.h"

GParsePbrt::GParsePbrt()
{

}

void GParsePbrt::parse(const QString filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream ts(&file);
    while( ts.atEnd() == false )
    {
        QString line = ts.readLine();
        this->parseLine(line.trimmed());
    }
}

void GParsePbrt::parseLine(const QString line)
{
    if(line.isEmpty()) return ;
    QChar firstChar = line.at(0);
    QStringList strList = line.split(' ');
    QString firstStr = strList.at(0);

    if(firstChar == 'A')
    {
        if(firstStr == "AttributeBegin")
        {}
        else if(firstStr == "AttributeEnd")
        {}
        else if(firstStr == "ActiveTransform")
        {}
        else if(firstStr == "AreaLightSource")
        {}
        else if(firstStr == "Accelerator")
        {}
    }
    else if(firstChar == "C")
    {
        if(firstStr == "ConcatTransform")
        {}
        else if(firstStr == "CoordinateSystem")
        {}
        else if(firstStr == "CoordSysTransform")
        {}
        else if(firstStr == "Camera")
        {
            this->parseCamera(line);
        }
    }
    else if(firstChar == "F")
    {
        if(firstStr == "Film")
        {}
    }
    else if(firstChar == "I")
    {
        if(firstStr == "Integrator")
        {}
        else if(firstStr == "Include")
        {}
        else if(firstStr == "Identity")
        {}
    }
    else if(firstChar == "L")
    {
        if(firstStr == "LightSource")
        {}
        else if(firstStr == "LookAt")
        {
            this->parseLookAt(line);
        }
    }
    else if(firstChar == "M")
    {
        if(firstStr == "MakeNamedMaterial")
        {}
        else if(firstStr == "MakeNamedMedium")
        {}
        else if(firstStr == "Material")
        {}
        else if(firstStr == "MediumInterface")
        {}
    }
    else if(firstChar == "N")
    {
        if(firstStr == "NamedMaterial")
        {}
    }
    else if(firstChar == "O")
    {
        if(firstStr == "ObjectBegin")
        {}
        else if (firstStr == "ObjectEnd")
        {}
        else if (firstStr == "ObjectInstance")
        {}
    }
    else if(firstChar == "P")
    {
        if(firstStr == "PixelFilter")
        {}
    }
    else if(firstChar == "R")
    {
        if (firstStr == "ReverseOrientation")
        {}
        else if (firstStr == "Rotate")
        {
            this->parseRotate(line);
        }
    }
    else if(firstChar == "S")
    {
        if (firstStr == "Shape")
        {}
        else if(firstStr == "Sampler")
        {}
        else if(firstStr == "Scale")
        {}
    }
    else if(firstChar == "T")
    {
        if(firstStr == "TransformBegin")
        {}
        else if(firstStr == "TransformEnd")
        {}
        else if(firstStr == "Transform")
        {}
        else if(firstStr == "Translate")
        {}
        else if(firstStr == "TransformTimes")
        {}
        else if(firstStr == "Texture")
        {}
    }
    else if(firstChar == "W")
    {
        if(firstStr == "WorldBegin")
        {}
        else if(firstStr == "WorldEnd")
        {}
    }
}

void GParsePbrt::parseLookAt(const QString line)
{
    QStringList strList = line.split(' ', QString::SkipEmptyParts);
    float ex = strList.at(1).toFloat();
    float ey = strList.at(2).toFloat();
    float ez = strList.at(3).toFloat();
    float lx = strList.at(4).toFloat();
    float ly = strList.at(5).toFloat();
    float lz = strList.at(6).toFloat();
    float ux = strList.at(7).toFloat();
    float uy = strList.at(8).toFloat();
    float uz = strList.at(9).toFloat();

    QVector3D pos = QVector3D(ex, ey, ez);
    QVector3D look = QVector3D(lx, ly, lz);
    QVector3D up = QVector3D(ux, uy, uz);
    QVector3D dir = (look - pos).normalized();
    QVector3D right = QVector3D::crossProduct(up, dir).normalized();
    QVector3D newUp = QVector3D::crossProduct(dir, right);

    QMatrix4x4 cameraToWorld(
                right.x(), newUp.x(), dir.x(), pos.x(),
                right.y(), newUp.y(), dir.y(), pos.y(),
                right.z(), newUp.z(), dir.z(), pos.z(),
                0.0, 0.0, 0.0, 1.0f);

    qDebug()<<cameraToWorld;
}

void GParsePbrt::parseRotate(const QString line)
{
    QStringList strList = line.split(' ', QString::SkipEmptyParts);
    float angle = strList.at(1).toFloat();
    float dx = strList.at(2).toFloat();
    float dy = strList.at(3).toFloat();
    float dz = strList.at(4).toFloat();
    QQuaternion q = QQuaternion::fromAxisAndAngle(QVector3D(dx,dy,dz), angle);
qDebug()<<q.toRotationMatrix();
}

void GParsePbrt::parseCamera(const QString line)
{

}
