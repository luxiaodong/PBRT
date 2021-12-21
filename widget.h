#ifndef WIDGET_H
#define WIDGET_H

#include <QString>
#include <QWidget>
#include <QPaintEvent>
#include "Core/gscene.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void paintEvent(QPaintEvent*);

private:
    void parsePbrtFile(GScene&);
    void renderToImage(QImage&);

private:
    int m_width;
    int m_height;
    int m_drawOnce;
};

#endif // WIDGET_H
