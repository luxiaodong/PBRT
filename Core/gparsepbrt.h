#ifndef GPARSEPBRT_H
#define GPARSEPBRT_H

#include "qtinclude.h"

class GParsePbrt
{
public:
    GParsePbrt();
    ~GParsePbrt();
    void parse(const QString filePath);

private:
    void parseLine(const QString line);
    void parseLookAt(const QString line);
    void parseRotate(const QString line);
    void parseCamera(const QString line);
    void parseFilm(const QString line);
    void parseSampler(const QString line);
    void parseIntegrator(const QString line);

public:
    QTextStream* m_textStream;
};

#endif // GPARSEPBRT_H
