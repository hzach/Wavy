#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "Resources.h"

using namespace ci;
using namespace ci::app;

// We'll create a new Cinder Application by deriving from the App class.
class Wavy : public App
{
  	public:
        void draw() override;
		void setup() override;

		CameraPersp mCam;
		gl::BatchRef mRect;
		gl::GlslProgRef mGlsl;
};


void Wavy::setup()
{
	mCam.lookAt(vec3(3, 2, 3), vec3(0));
	mGlsl = gl::GlslProg::create(loadResource(RES_VERT_GLSL), loadResource(RES_FRAG_GLSL));

    gl::ScopedGlslProg glslScp(mGlsl);
    auto plane = geom::Plane().subdivisions(ivec2(30));
    mRect = gl::Batch::create(plane, mGlsl);

	gl::enableDepthWrite();
	gl::enableDepthRead();

}

void Wavy::draw()
{
	gl::clear();
	gl::setMatrices(mCam);

	mGlsl->uniform("uCheckSize", 30.0f);
	mGlsl->uniform("uTime", (float)getElapsedSeconds());
	mRect->draw();

}


void prepareSettings( Wavy::Settings* settings )
{
	settings->setMultiTouchEnabled( false );
	settings->setFullScreen( true );
}


// This line tells Cinder to actually create and run the application.
CINDER_APP( Wavy, RendererGl, prepareSettings )
