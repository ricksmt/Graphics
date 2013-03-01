/*
 * Polygon.h
 *
 *  Created on: Feb 26, 2013
 *      Author: Matthew
 */

#ifndef POLYGON_H_
#define POLYGON_H_

#include <queue>
#include <vector>
#include "MyGL.h"
#include "Point.h"

namespace MyGL{

	struct Polygon: Shape{

		std::vector<Point> vertices;

		Polygon() {}
		Polygon(const Polygon& p): vertices(p.vertices) {}
		Polygon(const std::vector<Point> v): vertices(v) {}
		Polygon(const std::queue<Point> q){
			std::queue<Point> copy(q);
			while(!copy.empty()){
				vertices.push_back(copy.front());
				copy.pop();
			}
		}
		virtual ~Polygon() {}

		Polygon& operator =(const Polygon& p){
			if(this != &p){
				vertices = p.vertices;
			}
			return *this;
		}

		Polygon& operator <<(const Point& p){
			vertices.push_back(p);
			return *this;
		}

		virtual void draw() const {}
	};
}

#endif /* POLYGON_H_ */
