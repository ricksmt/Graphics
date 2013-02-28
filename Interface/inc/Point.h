/*
 * Point.h
 *
 *  Created on: Feb 26, 2013
 *      Author: Matthew
 */

#ifndef POINT_H_
#define POINT_H_

#include <vector>
#include "MyGL.h"
#include "Color.h"
#include "Shape.h"
#include <Eigen/Core>

using namespace Eigen;

typedef Vector4f Location;

namespace MyGL {

	extern GLfloat pointSize;
	struct Point: Shape{

		Location location;
		GLfloat size;
		Color color;

		Point(float x, float y, float z = 0, float h = 1):
			size(MyGL::pointSize),
			color(MyGL::currentColor)
		{
			location << x, y, z, h;
		}
		virtual ~Point() {}

		virtual void draw() const {}
	};
	extern std::vector<Point> vertices;
}

#endif /* POINT_H_ */
