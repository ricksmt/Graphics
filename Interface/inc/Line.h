/*
 * Line.h
 *
 *  Created on: Feb 26, 2013
 *      Author: Matthew
 */

#ifndef LINE_H_
#define LINE_H_

#include "Point.h"

namespace MyGL{

	struct Line: Shape{

		Point start, end;

		Line(Point s, Point e): start(s), end(e) { }
		virtual ~Line() {}

		virtual void draw() const {}
	};
}

#endif /* LINE_H_ */
