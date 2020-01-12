#include "Camera.h"

float Camera::getTransformX() const
{
	return transformValue.getX();
}

float Camera::getTransformY() const {
	return transformValue.getY();
}

float Camera::getRotationValue() const
{
	return rotationValue;
}

float Camera::getScaleValue() const
{
	return scaleValue;
}

Camera::Camera()
	: Camera(shapes)
{
}

Camera::Camera(std::vector<BaseShape> shapes)
	: Camera(shapes,0,0,1,0)
{
}

Camera::Camera(std::vector<BaseShape> shapes, float transformX, float transformY, float scale, float rotation)
	:
	transformValue(Vec2DFloat(transformX,transformY)),
	scaleValue(scale),
	rotationValue(rotation)
{
	this->shapes = shapes;
}

void Camera::render() {
	if (shapes.size() > 0) {
		float x;
		float y;
		float sinValue;
		float cosValue;
		float totalScaleValue;
		float totalTransformValueX;
		float totalTransformValueY;
		for (auto shape : shapes) {
			glBegin(GL_POLYGON);
			glColor3f(
				shape.getColor().getX() / 255.0f, 
				shape.getColor().getY() / 255.0f, 
				shape.getColor().getZ() / 255.0f
			);
			sinValue = sin(double(shape.getRotationValue()) + double(rotationValue));
			cosValue = cos(double(shape.getRotationValue()) + double(rotationValue));
			totalScaleValue = scaleValue + shape.getScaleValue();
			totalTransformValueX = transformValue.getX() + shape.getTransform().getX();
			totalTransformValueY = transformValue.getY() + shape.getTransform().getY();
			for (auto vertix : shape.getOriginalShape()) {
				x = vertix.getX() * cosValue - vertix.getY() * sinValue;
				y = vertix.getX() * sinValue + vertix.getY() * cosValue;
				x *= totalScaleValue;
				y *= totalScaleValue;
				x += totalTransformValueX;
				y += totalTransformValueY;
				glVertex3f(vertix.getX(), vertix.getY(), 0.0f);
			}
			glEnd();
		}
	}
}

void Camera::update() {

}