#ifndef WIDGET_H
#define WIDGET_H

#include "gpbrt.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void paintEvent(QPaintEvent*);

private:
    QImage* m_pImage;
};

#endif // WIDGET_H
