/*
 * Color.h
 *
 *  Created on: Jan 23, 2013
 *      Author: ricksmt
 */

#ifndef COLOR_H_
#define COLOR_H_

struct Color {

	float red;
	float green;
	float blue;
	float alpha;// Transparent 0 -- 1 Opaque

	Color(const float red = 1, const float green = 1, const float blue = 1, const float alpha = 1):
		red(red), green(green), blue(blue), alpha(alpha) { }
	~Color() {}

	Color& operator =(const Color& c){
		if(this != &c){
			red = c.red;
			green = c.green;
			blue = c.blue;
			alpha = c.alpha;
		}
		return *this;
	}
};

#endif /* COLOR_H_ */
