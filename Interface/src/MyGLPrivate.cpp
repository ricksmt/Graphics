/*
 * MyGLPrivate.cpp
 *
 *  Created on: Jan 19, 2013
 *      Author: ricksmt
 */

#include "MyGL.h"

namespace MyGL{

	float raster[WIDTH * HEIGHT * BYTES];

	float clearR = 0, clearG = 0, clearB = 0, clearA = 0;
	float currentR = 1, currentG = 1, currentB = 1, currentA = 1;

	bool reading = false;
	GLenum readingMode;

	void setPixel(int x, int y, float r, float g, float b){
		raster[((y * WIDTH) + x) * 3 + 0] = r;
		raster[((y * WIDTH) + x) * 3 + 1] = g;
		raster[((y * WIDTH) + x) * 3 + 2] = b;
	}
}
