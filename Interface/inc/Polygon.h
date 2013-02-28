/*
 * Polygon.h
 *
 *  Created on: Feb 26, 2013
 *      Author: Matthew
 */

#ifndef POLYGON_H_
#define POLYGON_H_

#include <vector>
#include "MyGL.h"
#include "Point.h"

namespace MyGL{

	struct Polygon: Shape{

		std::vector<Point> vertices;

		Polygon() {};
		Polygon(const std::vector<Point> v): vertices(v) { }
		virtual ~Polygon() {}

		Polygon& operator <<(const Point& p){
			vertices.push_back(p);
			return *this;
		}

		virtual void draw() const {}
	};
}

#endif /* POLYGON_H_ */
