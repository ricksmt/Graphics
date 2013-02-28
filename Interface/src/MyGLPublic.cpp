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
		// TODO: Switch on readingMode
		vertices.push_back(Point(x, y));
	}
