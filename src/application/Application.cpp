#include "Application.h"
#include "../polyline/shape_generator/ShapeGenerator.h"
#include <memory>
#include "../Constants.h"

std::unique_ptr<Application> Application::instance;

void handleKeyboardEvent(unsigned char key, int x, int y)
{
	if (!Application::getInstance()) {
		return;
	}
	if (key == 'a' || key == 'A') {
		Application::getInstance()->notifyKeyIsPressed(Application::Buttons::leftButton);
	}
	if (key == 'd' || key == 'D') {
		Application::getInstance()->notifyKeyIsPressed(Application::Buttons::rightButton);
	}
	if (key == 'w' || key == 'W') {
		Application::getInstance()->notifyKeyIsPressed(Application::Buttons::forwardButton);
	}
	if (key == 's' || key == 'S') {
		Application::getInstance()->notifyKeyIsPressed(Application::Buttons::backwardButton);
	}
	if (key == 'e' || key == 'E') {
		Application::getInstance()->notifyKeyIsPressed(Application::Buttons::rotationRightButton);
	}
	if (key == 'q' || key == 'Q') {
		Application::getInstance()->notifyKeyIsPressed(Application::Buttons::rotationLeftButton);
	}
	if (key == 'x' || key == 'X') {
		Application::getInstance()->notifyKeyIsPressed(Application::Buttons::zoomInButton);
	}
	if (key == 'c' || key == 'C') {
		Application::getInstance()->notifyKeyIsPressed(Application::Buttons::zoomOutButton);
	}
}

Application::Application() {
	instance = std::unique_ptr<Application>(this);

	std::vector<BaseShape> shapes;
	BaseShape a(ShapeGenerator::gear(100, 10),0,0,1,0,Vec3DFloat(255,0,0));
	shapes.emplace_back(a);
	camera = std::unique_ptr<Camera>(new Camera(shapes, 0, 0, 1, 0));

	glutKeyboardFunc(handleKeyboardEvent);
}

void Application::render() {
	camera->render();
}

void Application::update() {
	if (keyEvents[leftButton]==true) {
		camera->addTransformX(-1*Camera::cameraTranformSpeed);
		keyEvents[leftButton] = false;
	}
	if (keyEvents[rightButton]==true) {
		camera->addTransformX(Camera::cameraTranformSpeed);
		keyEvents[rightButton] = false;
	}
	if (keyEvents[forwardButton] == true) {
		camera->addTransformY(1 * Camera::cameraTranformSpeed);
		keyEvents[forwardButton] = false;
	}
	if (keyEvents[backwardButton] == true) {
		camera->addTransformY(-1 * Camera::cameraTranformSpeed);
		keyEvents[backwardButton] = false;
	}
	if (keyEvents[rotationRightButton] == true) {
		camera->addRotation(Camera::cameraRotationSpeed);
		keyEvents[rotationRightButton] = false;
	}
	if (keyEvents[rotationLeftButton]) {
		camera->addRotation(-1* Camera::cameraRotationSpeed);
		keyEvents[rotationLeftButton] = false;
	}
	if (keyEvents[zoomInButton]) {
		camera->addScale(Camera::cameraScaleSpeed);
		keyEvents[zoomInButton] = false;
	}
	if (keyEvents[zoomOutButton]) {
		camera->addScale(-1 * Camera::cameraScaleSpeed);
		keyEvents[zoomOutButton] = false;
	}
	camera->update();
}

void Application::notifyKeyIsPressed(Application::Buttons keyEvent)
{
	keyEvents[keyEvent] = true;
}

std::unique_ptr<Application>& Application::getInstance()
{
	return Application::instance;
}
