#include "Application.h"
#include "../polyline/shape_generator/ShapeGenerator.h"

Application::Application() {
	std::vector<BaseShape> shapes;
	BaseShape a(ShapeGenerator::gear(100, 10),0,0,1,0,Vec3DFloat(255,0,0));
	shapes.emplace_back(a);
	Camera* newCamera = new Camera(shapes,0,0,1,0);
	camera = std::unique_ptr<Camera>(newCamera);
}

void Application::render() {
	camera->render();
}

void Application::update() {
	camera->update();
}