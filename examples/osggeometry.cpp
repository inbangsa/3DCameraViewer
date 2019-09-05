// The majority of the application is dedicated to building the
// current contributors list by parsing the ChangeLog, it just takes
// one line in the main itself to report the version number.

#define OSG_LIBRARY_STATIC 
#pragma comment (lib, "OpenGL32.lib")
#include <set>
#include <vector>

#include <osg/Geometry>
#include <osg/Geode>
#include <osgViewer/Viewer>
#if 0
namespace 3DCameraViewer {
	namespace Tools {
				osg::Camera* createHUDCamera( double left, double right, double bottom, double top )
				{
					osg::ref_ptr<osg::Camera> camera = new osg::Camera;
					camera->setReferenceFrame( osg::Transform::ABSOLUTE_RF );
					camera->setClearMask( GL_DEPTH_BUFFER_BIT );
					camera->setRenderOrder( osg::Camera::POST_RENDER );
					camera->setAllowEventFocus( false );
					camera->setProjectionMatrix(
					osg::Matrix::ortho2D(left, right, bottom, top) );
					camera->getOrCreateStateSet()->setMode(
					GL_LIGHTING, osg::StateAttribute::OFF );
					return camera.release();
				}
				
				//osg::ref_ptr<osgText::Font> g_font = osgText::readFontFile("fonts/arial.ttf");
				
				osgText::Text* createText( const osg::Vec3& pos, const std::string& content, float size )
				{
					osg::ref_ptr<osgText::Text> text = new osgText::Text;
					text->setDataVariance( osg::Object::DYNAMIC );
					//text->setFont( g_font.get() );
					text->setCharacterSize( size );
					text->setAxisAlignment( osgText::TextBase::XY_PLANE );
					text->setPosition( pos );
					text->setText( content );
					return text.release();
				}

				class PickHandler : public osgGA::GUIEventHandler
				{
				public:
					// This virtual method must be overrode by subclasses.
					virtual void doUserOperations(osgUtil::LineSegmentIntersector::Intersection& ) = 0;
					virtual bool handle( const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa )
					{
					if ( ea.getEventType()!=osgGA::GUIEventAdapter::RELEASE	|| ea.getButton()!=osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON	||!(ea.getModKeyMask()&osgGA::GUIEventAdapter::MODKEY_CTRL) )
						return false;
					
					osgViewer::View* viewer = dynamic_cast<osgViewer::View*>(&aa);
					if ( viewer )
					{
						osg::ref_ptr<osgUtil::LineSegmentIntersector>
						intersector = new osgUtil::LineSegmentIntersector
						(osgUtil::Intersector::WINDOW, ea.getX(), ea.getY());
						osgUtil::IntersectionVisitor iv( intersector.get() );
						viewer->getCamera()->accept( iv );
						if ( intersector->containsIntersections() )
							{
							osgUtil::LineSegmentIntersector::Intersection&
							result = *(intersector->getIntersections().begin());
							doUserOperations( result );
							}
					}
					
				   return false;
				  }
				};
	}
}
#endif
int main()
{
	#if 1
osg::Matrix m;
m( 0, 1 ) = 0.f; // Set the second element (row 0, column 1)
m( 1, 2 ) = 0.f; // Set the seventh element (row 1, column 2) 
	
    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
    vertices->push_back( osg::Vec3(0.0f, 0.0f, 0.0f) );
    vertices->push_back( osg::Vec3(1.0f, 0.0f, 0.0f) );
    vertices->push_back( osg::Vec3(1.0f, 0.0f, 1.0f) );
    vertices->push_back( osg::Vec3(0.0f, 0.0f, 1.0f) );

    osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;
    normals->push_back( osg::Vec3(0.0f,-1.0f, 0.0f) );

    osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
    colors->push_back( osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f) );
    colors->push_back( osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f) );
    colors->push_back( osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f) );
    colors->push_back( osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f) );

    osg::ref_ptr<osg::Geometry> quad = new osg::Geometry;
    quad->setVertexArray( vertices.get() );
    quad->setNormalArray( normals.get() );
    quad->setNormalBinding( osg::Geometry::BIND_OVERALL );
    quad->setColorArray( colors.get() );
    quad->setColorBinding( osg::Geometry::BIND_PER_VERTEX );

    quad->addPrimitiveSet( new osg::DrawArrays(GL_QUADS, 0, 4) );

    osg::ref_ptr<osg::Geode> root = new osg::Geode;
    root->addDrawable( quad.get() );
    osgViewer::Viewer viewer;
    viewer.setSceneData( root.get() );
    return  viewer.run();
	#endif
	
}  
