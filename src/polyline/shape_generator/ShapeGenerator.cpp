#include "ShapeGenerator.h"
#include <math.h>
#include "../../Constants.h"
#include <assert.h>

std::vector<Vec2DFloat> ShapeGenerator::star(
	float innerRadius,
	float outerRadius,
	int numberOfAngles
) {
	std::vector<Vec2DFloat> polyLines;
	return polyLines;
}

std::vector<Vec2DFloat> ShapeGenerator::gear(
	const float radius, 
	const int numberOfCorners
)
{
	std::vector<Vec2DFloat> polyLines;
	{
		//I assume that center is zero in both x and y
		const double rectAngle = (2 * Constants::Math::piDouble) / (numberOfCorners);
		const double startingAngle = numberOfCorners % 2 == 0 ? 0 : rectAngle / 2;
		{
			double x = 0;
			double y = 0;
			double currentAngle = startingAngle;
			for (int i = 0; i < numberOfCorners; i++) {
				x = radius * cos(currentAngle);
				y = radius * sin(currentAngle);
				currentAngle += rectAngle;
				polyLines.emplace_back(Vec2DFloat((float)x, (float)y));
			}
			polyLines.emplace_back(
				Vec2DFloat(
					polyLines.at(0).getX(),
					polyLines.at(0).getY()
				)
			);
		}
	}
	return polyLines;
}

std::vector<Vec2DFloat> ShapeGenerator::rectangle(
	const int length,
	const int width
) {
	std::vector<Vec2DFloat> polyLines;
	{//Generating polyLine
		const float halfLength = float(length) / 2;
		const float halfWidth = float(width) / 2;
		{//Creating four angles
			polyLines.emplace_back(halfLength, halfWidth);
			polyLines.emplace_back(-halfLength, halfWidth);
			polyLines.emplace_back(-halfLength, -halfWidth);
			polyLines.emplace_back(halfLength, -halfWidth);
		}
		//Copying last member to create close loop
		polyLines.emplace_back(
			polyLines.at(0).getX(),
			polyLines.at(0).getY()
		);
	}
	return polyLines;
}