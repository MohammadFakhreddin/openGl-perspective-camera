#pragma once

#include "../../OpenGlHeaders.h"
#include <vector>
#include "../../utils/VectorTemplate.h"

class BaseShape
{
public:
	BaseShape(std::vector<Vec2DFloat> originalShape, float transformX, float transformY, float scale, float rotation, Vec3DFloat color);
	BaseShape(std::vector<Vec2DFloat> originalShape);
	void update();
	void addTransform(float x, float y);
	void addScale(float value);
	void addRotation(float value);
	void addColor(int r, int g, int b);
	void setTransform(float x, float y);
	void setScale(float value);
	void setRotation(float value);
	void setColor(int r, int g, int b);
	const Vec2DFloat& getTransform();
	float getRotationValue();
	float getScaleValue();
	const Vec3DInt& getColor();
	const std::vector<Vec2DFloat>& getOriginalShape();
private:
	std::vector<Vec2DFloat> originalShape;
	Vec2DFloat transformValue = Vec2DFloat(0,0);
	float rotationValue = 0;
	float scaleValue = 0;
	Vec3DInt colorValue = Vec3DInt(0,0,0);
};
