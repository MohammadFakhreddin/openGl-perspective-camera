#include <assert.h>
#include "BaseShape.h"

BaseShape::BaseShape(std::vector<Vec2DFloat> originalShape)
	:BaseShape(originalShape, 0, 0, 1, 0, { 0,0,0 })
{
}

BaseShape::BaseShape(std::vector<Vec2DFloat> originalShape, float transformX, float transformY, float scale, float rotation, Vec3DFloat color)
	:originalShape(originalShape),
	transformValue(transformX,transformY),
	scaleValue(scale),
	rotationValue(rotation),
	colorValue(color)
{
	assert(originalShape.size() > 0);
}

void BaseShape::update() {

}

void BaseShape::addTransform(float x, float y) {
	transformValue.setX(transformValue.getX() + x);
	transformValue.setY(transformValue.getY() + y);
}

void BaseShape::addScale(float value) {
	scaleValue += value;
}

void BaseShape::addRotation(float value)
{
	rotationValue += value;
}

void BaseShape::addColor(int r, int g, int b)
{
	colorValue.setX(colorValue.getX() + r);
	colorValue.setY(colorValue.getY() + g);
	colorValue.setZ(colorValue.getZ() + b);
}

void BaseShape::setTransform(float x, float y)
{
	transformValue.setX(x);
	transformValue.setY(y);
}

void BaseShape::setScale(float value)
{
	scaleValue = value;
}

void BaseShape::setRotation(float value)
{
	rotationValue = value;
}

void BaseShape::setColor(int r, int g, int b)
{
	colorValue.setX(r);
	colorValue.setY(g);
	colorValue.setZ(b);
}

const Vec2DFloat& BaseShape::getTransform()
{
	return transformValue;
}

float BaseShape::getRotationValue()
{
	return rotationValue;
}

float BaseShape::getScaleValue()
{
	return scaleValue;
}

const Vec3DInt& BaseShape::getColor()
{
	return colorValue;
}

const std::vector<Vec2DFloat>& BaseShape::getOriginalShape()
{
	return originalShape;
}
