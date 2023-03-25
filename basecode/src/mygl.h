#ifndef MYGL_H
#define MYGL_H

#include <memory>
#include <openglcontext.h>
#include <utils.h>
#include <shaderprograms/postprocessshader.h>
#include <shaderprograms/surfaceshader.h>
#include "texture.h"
#include <scene/quad.h>
#include <scene/mesh.h>
#include <scene/camera.h>

#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>

#include <clusterStructure/SVGContext.h>

class MyGL
    : public OpenGLContext
{
    Q_OBJECT
private:

    // The screen-space quadrangle used to draw
    // the scene with the post-process shaders.
    Quad m_geomQuad;

    // The camera used to view the scene.
    Camera m_camera;

    // The collection of surface shaders available to the user. This vector is only
    // ever modified once, in createShaders().
    std::vector<std::shared_ptr<SurfaceShader>> m_surfaceShaders;
    // The collection of post-process shaders available to the user. This vector is only
    // ever modified once, in createShaders().
    std::vector<std::shared_ptr<PostProcessShader>> m_postprocessShaders;

    // A pointer to the surface shader currently being used to render the scene's model.
    // Used by paintGL to determine which surface shader to apply to the model.
    // Modified by slot_setCurrentSurfaceShaderProgram().
    SurfaceShader* mp_progSurfaceCurrent;
    // A pointer to the post-process shader currently being used to render the scene.
    // Used by paintGL to determine which post-process shader to apply to the scene.
    // Modified by slot_setCurrentPostprocessShaderProgram().
    PostProcessShader* mp_progPostprocessCurrent;
    // A pointer to our no-operation post-process shader, used to draw the scene's background
    PostProcessShader* mp_progPostprocessNoOp;

    // The collection of renderable models available to the user. This vector is only
    // modified once, in createMeshes().
    std::vector<std::shared_ptr<Mesh>> m_models;
    // A pointer to the model that is currently being rendered. Used by paintGL to determine
    // which model to render.
    Mesh* mp_modelCurrent;

    std::vector<std::shared_ptr<Texture>> m_matcapTextures;
    Texture* mp_matcapTexCurrent;

    // A handle for our vertex array object.
    // This will store the VBOs created in our geometry classes.
    GLuint m_vao;

    // A collection of handles to the five frame buffers we've given
    // ourselves to perform render passes. The 0th frame buffer is always
    // written to by the render pass that uses the currently bound surface shader.
    GLuint m_frameBuffer;
    // A collection of handles to the textures used by the frame buffers.
    // m_frameBuffers[i] writes to m_renderedTextures[i].
    GLuint m_renderedTexture;
    // A collection of handles to the depth buffers used by our frame buffers.
    // m_frameBuffers[i] writes to m_depthRenderBuffers[i].
    GLuint m_depthRenderBuffer;

    GLuint m_SVGFrameBuffer;
    GLuint m_SVGRenderTexture;

    // A variable used to keep track of the time elapsed.
    // It increments by 1 at the end of each call of paintGL().
    // In paintGL, it is passed to the currently bound surface and post-process shaders,
    // if they have a uniform variable for time.
    int m_time;
    // A variable used to track the mouse's previous position when
    // clicking and dragging on the GL viewport. Used to move the camera
    // in the scene.
    glm::vec2 m_mousePosPrev;


    //SVG File
    SVGContext svgContext;

private:
    // Sets up the arrays of frame buffers
    // used to store render passes. Invoked
    // once in initializeGL().
    void createRenderBuffers();
    // Sets up the different shaders used to
    // render the scene. Invoked once in
    // initializeGL().
    void createShaders();
    // Loads the mesh scenes into m_models.
    // Also sets up the VBOs and other GL data
    // of the meshes.
    // Invoked once in initializeGL().
    void createMeshes();
    // Loads the different matcap textures
    // into memory and stores them on the
    // GPU. Invoked once in initializeGL().
    void createMatcapTextures();

    // A helper function that checks which
    // surface shader is being used to render
    // the model and binds the relevant
    // textures on the GPU.
    void bindAppropriateTexture();

    void render3DScene();

    //SVG render function
    void renderSVG();

    // A helper function that iterates through
    // each of the render passes required by the
    // currently bound post-process shader and
    // invokes them.
    void performPostprocessRenderPass();

    //Draw bezier curve

    float distPtSeg(float x, float y, float px, float py,float qx,float qy);
    void cubicBezierCurve(float x1, float y1, float x2, float y2,float x3, float y3, float x4, float y4,float tol, int level);
    void drawPath(float* pts, int npts, char closed, float tol);
    void drawFrame();


public:
    explicit MyGL(QWidget *parent = 0);
    ~MyGL();

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

protected:
    void keyPressEvent(QKeyEvent *e);
    void mousePressEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
    void wheelEvent(QWheelEvent* e);

public slots:
    void slot_setCurrentSurfaceShaderProgram(int);
    void slot_setCurrentPostprocessShaderProgram(int);
    void slot_setCurrentModel(int);
    void slot_setCurrentMatcapTexture(int);
};


#endif // MYGL_H
