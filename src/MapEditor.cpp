#include "cinder/app/AppNative.h"
#include "Object/GameObject/MainCamera/MainCamera.h"
#include "Object/GameObject/Grid/Grid.h"
#include "Object/GameObject/SkyDome/SkyDome.h"
#include "cinder/MayaCamUI.h"


class MapEditor : public ci::app::AppNative
{
private:

	enum WindowSize
	{
		WIDTH = 1024,
		HEIGHT = 786
	};

	MainCamera main_camera;
	Grid grid;
	SkyDome sky_dome;

public:
	void prepareSettings(Settings *settings) override;
	void setup() override;
	void resize() override;
	void update() override;
	void draw() override;
	void mouseMove(ci::app::MouseEvent event) override;
	void mouseDrag(ci::app::MouseEvent event) override;
	void mouseWheel(ci::app::MouseEvent event) override;
	void mouseDown(ci::app::MouseEvent event) override;
	void mouseUp(ci::app::MouseEvent event) override;
	void keyDown(ci::app::KeyEvent event) override;
	void keyUp(ci::app::KeyEvent event) override;
};

void MapEditor::prepareSettings(Settings * settings)
{
	settings->setWindowSize(WindowSize::WIDTH, WindowSize::HEIGHT);
	settings->setFullScreen(false);
}

void MapEditor::setup()
{
	//SoundManager::Get().Setup();
	TextureManager::Get().Setup();

	main_camera.Setup();
	main_camera.SetMoveSpeed(ci::Vec3f(0.1f, 0.1f, 0.1f));
	grid.Setup();
	sky_dome.Setup();

	ci::gl::enableAlphaBlending();
	ci::gl::enableDepthRead();
	ci::gl::enableDepthWrite();
	glCullFace(GL_BACK);
}

void MapEditor::resize()
{

}

void MapEditor::update()
{
	main_camera.Update();

	grid.Update();

	MOUSE.FlushInput();
	KEY.FlushInput();
}

void MapEditor::draw()
{
	ci::gl::clear(ci::Color(0, 0, 0));

	ci::gl::pushModelView();
	main_camera.Draw();

	sky_dome.Draw();

	grid.Draw();
	ci::gl::popModelView();
}

void MapEditor::mouseMove(ci::app::MouseEvent event)
{
	MOUSE.UpdateMousePosition(event);
}

void MapEditor::mouseDrag(ci::app::MouseEvent event)
{
	MOUSE.UpdateMousePosition(event);
}

void MapEditor::mouseWheel(ci::app::MouseEvent event)
{
	MOUSE.UpdateMouseWheelValue(event);
}

void MapEditor::mouseDown(ci::app::MouseEvent event)
{
	MOUSE.PushButton(event);
}

void MapEditor::mouseUp(ci::app::MouseEvent event)
{
	MOUSE.PullButton(event);
}

void MapEditor::keyDown(ci::app::KeyEvent event)
{
	KEY.PushKey(event);
}

void MapEditor::keyUp(ci::app::KeyEvent event)
{
	KEY.PullKey(event);
}

CINDER_APP_NATIVE(MapEditor, ci::app::RendererGl)
