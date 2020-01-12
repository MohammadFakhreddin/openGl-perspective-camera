#pragma once
#include <vector>
#include "../../utils/VectorTemplate.h"

class ShapeGenerator
{
public:
	std::vector<Vec2DFloat> static star(
		float innerRadius,
		float outerRadius,
		int numberOfAngles
	);
	std::vector<Vec2DFloat> static gear(
		const float radius,
		const int numberOfCorners
	);
	std::vector<Vec2DFloat> static rectangle(
		const int length,
		const int width
	);
};

