#pragma once

#include <vector>
#include "../polyline/base/BaseShape.h"

class Camera {
public:
	Camera();
	Camera(std::vector<BaseShape> shapes);
	Camera(std::vector<BaseShape> shapes, float transformX, float transformY, float scale, float rotation);
	void render();
	void update();
	float getTransformX() const;
	float getTransformY() const;
	float getRotationValue() const;
	float getScaleValue() const;
private:
	Vec2DFloat transformValue;
	float rotationValue;
	float scaleValue;
	std::vector<BaseShape> shapes;
};