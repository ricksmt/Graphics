/*
 * MyGLException.h
 *
 *  Created on: Jan 19, 2013
 *      Author: ricksmt
 */

#ifndef MYGLEXCEPTION_H_
#define MYGLEXCEPTION_H_

#include <exception>
#include <string>

class MyGLException: public std::exception {

	std::string message;

public:
	MyGLException() {}
	MyGLException(const std::string message): message(message) {}
	virtual ~MyGLException() throw() {}

	virtual const char* what() const throw() { return message.c_str(); }
};

#endif /* MYGLEXCEPTION_H_ */
