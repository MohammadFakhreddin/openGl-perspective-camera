#pragma once

#include <vector>
#include "../polyline/base/BaseShape.h"

class Camera {
public:
	static constexpr float cameraTranformSpeed = 3;
	static constexpr float cameraRotationSpeed = 0.1f;
	static constexpr float cameraScaleSpeed = 0.05f;
	Camera();
	Camera(std::vector<BaseShape> shapes);
	Camera(std::vector<BaseShape> shapes, float transformX, float transformY, float scale, float rotation);
	void render();
	void update();
	float getTransformX() const;
	float getTransformY() const;
	float getRotationValue() const;
	float getScaleValue() const;
	void addTransformX(float);
	void addTransformY(float);
	void addRotation(float);
	void addScale(float);
private:
	Vec2DFloat transformValue;
	float rotationValue;
	float scaleValue;
	std::vector<BaseShape> shapes;
};