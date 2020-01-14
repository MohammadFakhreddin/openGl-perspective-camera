#include "Application.h"
#include "../polyline/shape_generator/ShapeGenerator.h"
#include <memory>
#include "../Constants.h"

Application* Application::instance;

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
	instance = this;

	std::vector<BaseShape> shapes;
	{
		BaseShape a(ShapeGenerator::gear(50, 10), 0, 0, 1, 0, Vec3DFloat(255, 0, 0));
		shapes.emplace_back(a);
	}
	{
		BaseShape a(ShapeGenerator::gear(50, 10), Constants::Window::screenWidth/4, Constants::Window::screenHeight/4, 1, 0, Vec3DFloat(0, 255, 0));
		shapes.emplace_back(a);
	}
	{
		BaseShape a(ShapeGenerator::rectangle(100, 10), Constants::Window::screenWidth / 3, Constants::Window::screenHeight * 0.75, 1, 0, Vec3DFloat(0, 0, 255));
		shapes.emplace_back(a);
	}
	{
		BaseShape a(ShapeGenerator::gear(100, 10), Constants::Window::screenWidth * 0.7, Constants::Window::screenHeight * 0.75, 1, 0, Vec3DFloat(0, 100, 100));
		shapes.emplace_back(a);
	}
	{
		BaseShape a(ShapeGenerator::gear(10, 10), Constants::Window::screenWidth * 0.2, Constants::Window::screenHeight * 0.4, 1, 0, Vec3DFloat(100, 400, 100));
		shapes.emplace_back(a);
	}
	{
		BaseShape a(ShapeGenerator::gear(100, 10), Constants::Window::screenWidth * 0.1, Constants::Window::screenHeight * 0.7, 1, 0, Vec3DFloat(100, 100, 100));
		shapes.emplace_back(a);
	}
	{
		BaseShape a(ShapeGenerator::gear(100, 10), Constants::Window::screenWidth * 0.8, Constants::Window::screenHeight * 0.1, 1, 0, Vec3DFloat(100, 100, 100));
		shapes.emplace_back(a);
	}
	camera = std::unique_ptr<Camera>(new Camera(shapes, 0, 0, 1, 0));

	glutKeyboardFunc(handleKeyboardEvent);
}

void Application::render() {
	camera->render();
}

void Application::update() {
	if (keyEvents[leftButton]==true) {
		camera->addTransform(-1*Camera::cameraTranformSpeed,0);
		keyEvents[leftButton] = false;
	}
	if (keyEvents[rightButton]==true) {
		camera->addTransform(Camera::cameraTranformSpeed,0);
		keyEvents[rightButton] = false;
	}
	if (keyEvents[forwardButton] == true) {
		camera->addTransform(0,1 * Camera::cameraTranformSpeed);
		keyEvents[forwardButton] = false;
	}
	if (keyEvents[backwardButton] == true) {
		camera->addTransform(0,-1 * Camera::cameraTranformSpeed);
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

Application* Application::getInstance()
{
	return Application::instance;
}
