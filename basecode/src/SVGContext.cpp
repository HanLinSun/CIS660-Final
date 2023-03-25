#define NANOSVG_IMPLEMENTATION
#include <clusterStructure/SVGContext.h>

SVGContext::SVGContext(){}
SVGContext::~SVGContext(){}
NSVGshape* SVGContext::getShapesFromImage()
{
    return m_image->shapes;
}

NSVGimage* SVGContext::getSVGImage()
{
    return m_image;
}

void SVGContext::loadSVGFromFile(const char* path,float size)
{
    m_image = nsvgParseFromFile(path, "px", size);
    if(m_image)
    {
        printf("Load Success \n");
    }
    else
    {
         printf("Load failed \n");
    }
}

