#ifndef GPARSEPBRT_H
#define GPARSEPBRT_H

#include "qtinclude.h"

class GParsePbrt
{
public:
    GParsePbrt();
    void parse(const QString filePath);

private:
    void parseLine(const QString line);
    void parseLookAt(const QString line);
    void parseRotate(const QString line);
    void parseCamera(const QString line);

public:

};

#endif // GPARSEPBRT_H
