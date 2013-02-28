/*
 * MyGLPrivate.cpp
 *
 *  Created on: Jan 19, 2013
 *      Author: ricksmt
 */

#include "MyGL.h"
#include "MyGLException.h"
#include "Point.h"

	void MyGL::myClear(GLint mode){
		glClear(mode);
		if(mode & GL_COLOR_BUFFER_BIT){
			for(int i = 0; i < WIDTH; i++){
				for(int j = 0; j < HEIGHT; j++){
					setPixel(i, j, clearColor);
				}
			}
		}
	}

	void MyGL::myBegin(GLenum mode){
		glBegin(mode);
		if(reading) throw MyGLException("myBegin has already been called.");
		reading = true;
		readingMode = mode;
	}

	void MyGL::myEnd(){
		glEnd();
		if(!reading) throw MyGLException("myEnd has already been called.");
		reading = false;
		vertices.clear();
	}

	void MyGL::myVertex2i(int x, int y){
		glVertex2i(x, y);
		vertices.push_back(Point(x, y));
		switch(readingMode){
			case GL_POINTS:
				break;
			case GL_LINES:
				break;
			case GL_LINE_STRIP:
				break;
			case GL_LINE_LOOP:
				break;
			case GL_TRIANGLES:
				break;
			case GL_TRIANGLE_STRIP:
				break;
			case GL_TRIANGLE_FAN:
				break;
			case GL_QUADS:
				break;
			case GL_QUAD_STRIP:
				break;
			case GL_POLYGON:
				break;
		}
		// TODO: Switch on readingMode
	}
