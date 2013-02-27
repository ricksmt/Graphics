/*
 * MyGLVariables.cpp
 *
 *  Created on: Feb 26, 2013
 *      Author: Matthew
 */

#include "MyGL.h"

	void MyGL::myClearColor(float r, float g, float b, float a = 1){
		glClearColor(r, g, b, a);
		clearColor = Color(r, g, b, a);
	}

	void MyGL::myColor3f(float r, float g, float b){
		glColor3f(r, g, b);
		currentColor = Color(r, g, b);
	}

	void MyGL::myPointSize(GLfloat size){
		glPointSize(size);
		MyGL::pointSize = size;
	}


