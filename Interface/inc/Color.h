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

	Color(const float red, const float green, const float blue):
		red(red), green(green), blue(blue), alpha(1) { }
	Color(const float red, const float green, const float blue, const float alpha):
		red(red), green(green), blue(blue), alpha(alpha) { }
	~Color() {}
};

#endif /* COLOR_H_ */
