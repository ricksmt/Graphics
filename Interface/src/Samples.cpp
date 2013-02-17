/*
 * Samples.cpp
 *
 *  Created on: Jan 22, 2013
 *      Author: ricksmt
 */

#include <math.h>// Sine and cosine
#include "Samples.h"

using namespace MyGL;

void triangles() {
	myBegin(GL_TRIANGLES);
		myColor3f(1, 0, 0);
		myVertex2i(300, 300);
		myColor3f(0, 1, 0);
		myVertex2i(600, 300);
		myColor3f(0, 0, 1);
		myVertex2i(450, 410);
		myColor3f(1, 1, 0);
		myVertex2i(100, 400);
		myColor3f(0, 1, 1);
		myVertex2i(70, 60);
		myColor3f(1, 0, 1);
		myVertex2i(350, 100);
	myEnd();
}

void spiral() {
	myBegin(GL_POINTS);
	for (float theta = 0, radius = 60; radius > 1; theta += 0.1, radius -= 0.3) {
		myColor3f(radius / 60, 0.3, 1 - (radius / 60));
		myVertex2i(200 + radius * cos(theta), 200 + radius * sin(theta));
	}
	myEnd();
}

void lines() {
	myBegin(GL_LINES);
		for (int i = 0; i <= 8; i++) {
			myColor3f(1, 0, 0);
			myVertex2i(200, 200);
			myVertex2i(200 + 10 * i, 280);
			myColor3f(0, 1, 0);
			myVertex2i(200, 200);
			myColor3f(0, 1, 1);
			myVertex2i(200 - 10 * i, 280);
			myVertex2i(200, 200);
			myVertex2i(280, 200 + 10 * i);
			myVertex2i(200, 200);
			myVertex2i(280, 200 - 10 * i);
		}
	myEnd();
}


