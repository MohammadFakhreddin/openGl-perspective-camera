#include "Camera.h"
#include "../Constants.h"

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

void Camera::addTransform(float valueX,float valueY)
{
	const auto sinValue = sin(-1 * rotationValue);
	const auto cosValue = cos(-1 * rotationValue);
	const float cameraTransformX = valueX * cosValue - valueY * sinValue;
	const float cameraTransformY = valueX * sinValue + valueY * cosValue;
	transformValue.setX(transformValue.getX() + cameraTransformX);
	transformValue.setY(transformValue.getY() + cameraTransformY);
}

void Camera::addRotation(float value)
{
	rotationValue += value;
}

void Camera::addScale(float value)
{
	scaleValue += value;
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
		float localX;
		float localY;
		float globalX;
		float globalY;
		float shapeLocalRotationSinValue;
		float shapeLocalRotationCosValue;
		float shapeGlobalRotationSinValue = sin(double(rotationValue));
		float shapeGlobalRotationCosValue = cos(double(rotationValue));
		for (auto shape : shapes) {
			glBegin(GL_POLYGON);
			glColor3f(
				shape.getColor().getX() / 255.0f, 
				shape.getColor().getY() / 255.0f, 
				shape.getColor().getZ() / 255.0f
			);
			shapeLocalRotationSinValue = sin(double(shape.getRotationValue()));
			shapeLocalRotationCosValue = cos(double(shape.getRotationValue()));
			for (auto vertix : shape.getOriginalShape()) {
				localX = vertix.getX() * shapeLocalRotationCosValue - vertix.getY() * shapeLocalRotationSinValue;
				localY = vertix.getX() * shapeLocalRotationSinValue + vertix.getY() * shapeLocalRotationCosValue;
				localX *= shape.getScaleValue();
				localY *= shape.getScaleValue();
				localX += shape.getTransform().getX() - (Constants::Window::screenWidth / 2) - transformValue.getX();
				localY += shape.getTransform().getY() - (Constants::Window::screenHeight / 2) - transformValue.getY();
				globalX = (localX * shapeGlobalRotationCosValue - localY * shapeGlobalRotationSinValue);
				globalY = (localX * shapeGlobalRotationSinValue + localY * shapeGlobalRotationCosValue);
				globalX *= scaleValue;
				globalY *= scaleValue;
				globalX += (Constants::Window::screenWidth / 2);
				globalY += (Constants::Window::screenHeight / 2);
				glVertex3f(globalX, globalY, 0.0f);
			}
			glEnd();
		}
	}
}

void Camera::update() {

}