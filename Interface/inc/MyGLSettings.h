/*
 * MyGLSettings.h
 *
 *  Created on: Feb 28, 2013
 *      Author: Matthew
 */

#ifndef MYGLSETTINGS_H_
#define MYGLSETTINGS_H_

#include "MyGL.h"

namespace MyGL{

	extern bool reading;
	extern bool pointSmooth;
	extern bool odd;

	void glEnable(GLenum setting);
	void glDisable(GLenum setting);
	void glSetting(GLenum setting, bool value);
	void glEnable(GLenum setting, GLuint index);
	void glDisable(GLenum setting, GLuint index);
	void glSetting(GLenum setting, GLuint index, bool value);
}

#endif /* MYGLSETTINGS_H_ */
