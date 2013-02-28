/*
 * Shape.h
 *
 *  Created on: Feb 27, 2013
 *      Author: Matthew
 */

#ifndef SHAPE_H_
#define SHAPE_H_

namespace MyGL{

	struct Shape{

		virtual ~Shape() {}

		virtual void draw() const = 0;
	};
}


#endif /* SHAPE_H_ */
