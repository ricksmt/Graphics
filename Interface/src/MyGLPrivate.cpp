/*
 * MyGLPrivate.cpp
 *
 *  Created on: Jan 19, 2013
 *      Author: ricksmt
 */

#include "MyGL.h"

namespace MyGL{

	float raster[WIDTH * HEIGHT * BYTES];

	Color clearColor(0, 0, 0);
	Color currentColor(1, 1, 1);

	bool reading = false;
	GLenum readingMode;
	GLenum sBlend = GL_ONE, dBlend = GL_ZERO;
	GLfloat pointSize = 1;

	void glBlendFunc(GLenum sfactor, GLenum dfactor){
		sBlend = sfactor;
		dBlend = dfactor;
	}

	void setPixel(int x, int y, Color c){
		raster[((y * WIDTH) + x) * 3 + 0] = c.red;
		raster[((y * WIDTH) + x) * 3 + 1] = c.green;
		raster[((y * WIDTH) + x) * 3 + 2] = c.blue;
	}
}
