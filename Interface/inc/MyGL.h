/*
 * MYGL.h
 *
 *  Created on: Jan 19, 2013
 *      Author: ricksmt
 */

#ifndef MYGL_H_
#define MYGL_H_

#include <GL/glut.h>

namespace MyGL{

	// Constants
	const int WIDTH = 640;
	const int HEIGHT = 480;
	const int BYTES = 3;

	// Variables
	extern float raster[WIDTH * HEIGHT * BYTES];

	extern float clearR, clearG, clearB, clearA;
	extern float currentR, currentG, currentB, currentA;

	extern bool reading;
	extern GLenum readingMode;

	// Helper Methods
	void setPixel(int x, int y, float r, float g, float b);

	// OpenGL Methods
	void myClearColor(float r, float g, float b, float a);

	void myClear(GLint mode);

	void myBegin(GLenum mode);

	void myEnd();

	void myColor3f(float r, float g, float b);

	void myVertex2i(int x, int y);
}

#endif /* MYGL_H_ */
