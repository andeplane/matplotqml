#include "plot.h"
#include <QOpenGLFramebufferObjectFormat>
#include <QOpenGLFunctions>
#include <cmath>

Plot::Plot()
{

}



PlotRenderer *Plot::createRenderer() const
{
    return new PlotRenderer();
}

void PlotRenderer::generateVBOs() {
    m_vboIds.resize(2);
    QOpenGLFunctions funcs(QOpenGLContext::currentContext());
    funcs.glGenBuffers(2, &m_vboIds.first());

}

PlotRenderer::PlotRenderer()
{
    generateVBOs();
}

void PlotRenderer::render()
{
    QOpenGLFunctions funcs(QOpenGLContext::currentContext());

    static int count = 0;
    float t = count/60.;
    float val = 0.5*(1 + sin(2*M_PI*t));
    count++;

    funcs.glClearColor(val, 0, 0, 1.0);
    funcs.glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    funcs.glDisable(GL_ALPHA_TEST);
    funcs.glDisable(GL_CULL_FACE);
    funcs.glDisable(GL_DEPTH_TEST);

    createShaderProgram();
    m_program->bind();

    // Tell OpenGL which VBOs to use
    funcs.glBindBuffer(GL_ARRAY_BUFFER, m_vboIds[0]);

    // Tell OpenGL programmable pipeline how to locate vertex position data
    int vertexLocation = m_program->attributeLocation("a_position");
    m_program->enableAttributeArray(vertexLocation);
    funcs.glVertexAttribPointer(vertexLocation, 3, GL_FLOAT, GL_FALSE, sizeof(QVector3D), 0);

    // Draw cube geometry using indices from VBO 1
    glDrawArrays(GL_TRIANGLES, 0, m_points.size());

    m_program->disableAttributeArray(vertexLocation);

    m_program->release();


}

QOpenGLFramebufferObject *PlotRenderer::createFramebufferObject(const QSize &size)
{
    QOpenGLFramebufferObjectFormat format;
    format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);
    QOpenGLFramebufferObject* fbo = new QOpenGLFramebufferObject(size, format);
    return fbo;
}

void PlotRenderer::synchronize(QQuickFramebufferObject *fbo)
{
    Plot* plot = static_cast<Plot*>(fbo);
    update();
}

void PlotRenderer::createShaderProgram() {
    if (!m_program) {
        m_program = new QOpenGLShaderProgram();

        m_program->addShaderFromSourceCode(QOpenGLShader::Vertex,
                                           "attribute highp vec4 a_position;\n"
                                           "void main() {\n"
                                           "    gl_Position = a_position;\n"
                                           "}");

        m_program->addShaderFromSourceCode(QOpenGLShader::Fragment,
                                           "void main() {\n"
                                           "    gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);\n"
                                           "}");
        m_program->link();
    }
}

void PlotRenderer::update()
{
    QOpenGLFunctions funcs(QOpenGLContext::currentContext());
    m_points.clear();
    m_points.push_back(QVector3D(0,0,0));
    m_points.push_back(QVector3D(1,0,0));
    m_points.push_back(QVector3D(1,1,0));

    m_points.push_back(QVector3D(0,0,1));
    m_points.push_back(QVector3D(1,0,1));
    m_points.push_back(QVector3D(1,1,1));

    m_points.push_back(QVector3D(0,0,-1));
    m_points.push_back(QVector3D(1,0,-1));
    m_points.push_back(QVector3D(1,1,-1));

    funcs.glBindBuffer(GL_ARRAY_BUFFER, m_vboIds[0]);
    funcs.glBufferData(GL_ARRAY_BUFFER, m_points.size() * sizeof(QVector3D), &m_points.first(), GL_STATIC_DRAW);
}
