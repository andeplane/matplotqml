#ifndef PLOT_H
#define PLOT_H

#include <QQuickFramebufferObject>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QVector>
#include <QVector3D>

class PlotRenderer : public QQuickFramebufferObject::Renderer
{
public:
    PlotRenderer();
protected:
    QVector<QVector3D> m_points;
    bool m_isInitialized = false;
    QVector<GLuint> m_vboIds;
    QOpenGLShaderProgram *m_program = NULL;

    virtual void render();
    virtual void synchronize(QQuickFramebufferObject *fbo);
    virtual QOpenGLFramebufferObject *createFramebufferObject(const QSize &size);
    void update();
    void generateVBOs();
    void createShaderProgram();
};

class Plot : public QQuickFramebufferObject
{
public:
    Plot();

    // QQuickFramebufferObject interface
public:
    virtual PlotRenderer *createRenderer() const;
    friend class PlotRenderer;
};

#endif // PLOT_H
