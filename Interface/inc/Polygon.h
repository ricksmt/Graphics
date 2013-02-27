/*
 * Polygon.h
 *
 *  Created on: Feb 26, 2013
 *      Author: Matthew
 */

#ifndef POLYGON_H_
#define POLYGON_H_

#include <cstdarg>
#include <vector>
#include "MyGL.h"
#include "Point.h"

struct Polygon{

	std::vector<Point> vertices;

	Polygon() {};
	Polygon(const std::vector<Point> v): vertices(v) { }

	Polygon& operator <<(const Point& p){
		vertices.push_back(p);
		return *this;
	}
};


#endif /* POLYGON_H_ */
