//modifysurface.cpp

#include <modifysurface.h>
#include <osg\Geometry>

void ModifySurface::operator()(osg::Node* node, osg::NodeVisitor* nv)
{
    {
        std::lock_guard<std::mutex> lgMutex(_mutex);
        node->asGeometry()->setVertexArray(_vertices);
        node->asGeometry()->setNormalArray(_normals);
    }
    traverse(node, nv);
    emit SendTime(nv->getFrameStamp()->getSimulationTime());
}

void ModifySurface::ReceiveVertices(osg::ref_ptr<osg::Vec3Array> vertices, osg::ref_ptr<osg::Vec3Array> normals)
{
    std::lock_guard<std::mutex> lgMutex(_mutex);
    _vertices = vertices;
    _normals = normals;
}