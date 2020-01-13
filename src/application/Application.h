#pragma once

#include "../camera/Camera.h"
#include <memory>
#include <gainput/gainput.h>
#include <unordered_map>

class Application {
public:
	enum Buttons
	{
		leftButton,
		rightButton,
		forwardButton,
		backwardButton,
		rotationRightButton,
		rotationLeftButton,
		zoomInButton,
		zoomOutButton
	};
	Application();
	void render();
	void update();
	void notifyKeyIsPressed(Application::Buttons);
	static std::unique_ptr<Application>& getInstance();
private:
	std::unique_ptr<Camera> camera;
	static std::unique_ptr<Application> instance;
	std::unordered_map<Application::Buttons,bool> keyEvents;
};