/*
 * MyGLSettings.cpp
 *
 *  Created on: Feb 28, 2013
 *      Author: Matthew
 */

#include "MyGLSettings.h"

	bool MyGL::reading = false;
	bool MyGL::pointSmooth = false;
	GLfloat MyGL::pointSize = 1;

	void MyGL::glEnable(GLenum setting){
		glSetting(setting, true);
	}

	void MyGL::glDisable(GLenum setting){
		glSetting(setting, false);
	}

	void MyGL::glSetting(GLenum setting, bool value){
		switch(setting){
			case GL_POINT_SMOOTH:
				pointSmooth = value;
				break;
		}
	}

	void MyGL::glEnable(GLenum setting, GLuint index){
		glSetting(setting, index, true);
	}

	void MyGL::glDisable(GLenum setting, GLuint index){
		glSetting(setting, index, false);
	}

	void MyGL::glSetting(GLenum setting, GLuint index, bool value){
		switch(setting){

		}
	}
