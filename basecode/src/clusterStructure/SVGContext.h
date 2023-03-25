#ifndef SVGCONTEXT_H
#define SVGCONTEXT_H
#include <stdio.h>
#include <string.h>
#include <math.h>

#include <include/nanoSVG/nanosvg.h>
#include <string.h>
#include <iostream>

using namespace std;


class SVGContext
{
public:
    SVGContext();
    ~SVGContext();

    void loadSVGFromFile(const char* path,float size);
    NSVGshape* getShapesFromImage();
    NSVGimage* getSVGImage();

private:
    NSVGimage* m_image;
};

#endif



