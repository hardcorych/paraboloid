//modifysurface.h

#pragma once

#include <osg\Geometry>
#include <mutex>
#include <thread>
#include <qobject.h>
#include <osgUtil/SmoothingVisitor>

class ModifySurface : public QObject, public osg::NodeCallback      //для рендера (рендер-поток)
{
    Q_OBJECT
public:
    ModifySurface()
    {}

    ~ModifySurface()
    {}

    virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);

private:
    osg::ref_ptr<osg::Vec3Array> _vertices;
    osg::ref_ptr<osg::Vec3Array> _normals;
    std::mutex _mutex;

signals:
    void SendTime(double t);

public slots:
    void ReceiveVertices(osg::ref_ptr<osg::Vec3Array> vertices, osg::ref_ptr<osg::Vec3Array> normals);
};