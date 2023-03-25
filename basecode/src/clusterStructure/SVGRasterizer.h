#ifndef SVGRASTERIZER_H
#define SVGRASTERIZER_H
#include "SVGContext.h"
#include <openglcontext.h>
class SVGRasterizer : public OpenGLContext
{
    Q_OBJECT
public:
    SVGRasterizer();
    SVGRasterizer(SVGContext* context);
    ~SVGRasterizer();

};


#endif // SVGRASTERIZER_H


