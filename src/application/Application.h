#include "../camera/Camera.h"
#include <memory>

class Application {
public:
	Application();
	void render();
	void update();
private:
	std::unique_ptr<Camera> camera;
};