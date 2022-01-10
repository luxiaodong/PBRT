#include "goptions.h"

QString GOptions::camera_type = "";
QString GOptions::film_type = "";
QSize GOptions::film_resolution = QSize();
QRectF GOptions::film_cropwindow = QRectF(0,0,1,1);
QString GOptions::sampler_type = "";
int GOptions::sampler_pixel = 1;
QString GOptions::integrator_type = "";
