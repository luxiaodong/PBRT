#include "gfilter.h"

GFilter::GFilter(const QVector2D& radius) : m_radius(radius), m_invRadius(QVector2D(1.0f/radius.x(), 1.0f/radius.y()))
{}

