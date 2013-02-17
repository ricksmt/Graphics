/*
 * Interface.cpp
 *
 *  Created on: Jan 9, 2013
 *      Author: Matthew Ricks
 */

#include <unistd.h>// Sleeping
#include <stdlib.h>// RAND_MAX
#include <iostream>

#include "MyGL.h"
#include "Samples.h"


#define ESCAPE 27 // ASCII code for the escape key.
int window;// The number of our GLUT window
unsigned char lastKey = 'c';

enum DrawMode{
	OPENGL,
	MYGL,
} drawmode = OPENGL;

float randomFloat(const float high = 1, const float low = 0) {
	return (float)rand() / ((float)RAND_MAX / (high - low)) + low;
}

using namespace MyGL;


/* A general OpenGL initialization function.  Sets all of the initial parameters. */
void InitGL(int width, int height) {// We call this right after our OpenGL window is created.
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);// This will clear the background color to black
	glClearDepth(1.0);// Enables clearing of the depth buffer
	glDepthFunc(GL_LESS);// The type of depth test to do
	glEnable(GL_DEPTH_TEST);// Enables depth testing
	glShadeModel(GL_SMOOTH);// Enables smooth color shading

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();// Reset the projection matrix
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);// Calculate the aspect ratio of the window
	glMatrixMode(GL_MODELVIEW);
}

/* The function called when our window is resized (which shouldn't happen, because we're fullscreen) */
void ReSizeGLScene(int width, int height){
	if (height == 0) height = 1;// Prevent a divide by zero if the window is too small
	glViewport(0, 0, width, height);// Reset the current viewport and perspective transformation

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

//	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1);// TODO: ONLY for Project 2; delete thereafter.
}

/* The function called whenever a key is pressed. */
void keyPressed(unsigned char key, int x, int y){
	usleep(100);// Avoid thrashing this procedure.

	switch(key){
		case 27:// Escape
			glutDestroyWindow(window);// Shut down our window.
			exit(0);// Exit the program...normal termination.
			break;
		case '1':
			drawmode = OPENGL;
			key = lastKey;
			break;
		case '2':
			drawmode = MYGL;
			key = lastKey;
			break;
		case 'c':// Clear
			myClear(GL_COLOR_BUFFER_BIT);
			break;
		case 'l':// Lines
			lines();
			break;
		case 'r':// Random clear color
			myClearColor(randomFloat(), randomFloat(), randomFloat(), randomFloat());
			key = lastKey;
			break;
		case 's':// Spiral
			spiral();
			break;
		case 't':// Triangles
			triangles();
			break;
		default:// Don't want to stop if someone mistypes
			key = lastKey;
			break;
	}

	if(x != 0 && y != 0 && key != lastKey){
		std::cout << "Setting last key to " << key << '.' << std::endl;
		lastKey = key;
	}
}

void DrawGLScene(){// The main drawing function.

	myClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// DO NOT REMOVE DEPTH

	keyPressed(lastKey, 0, 0);

	if (drawmode == MYGL) {
		// Save the old state so that you can set it back after you draw
		GLint oldmatrixmode;
		GLboolean depthWasEnabled = glIsEnabled(GL_DEPTH_TEST);
		glDisable(GL_DEPTH_TEST);
		glGetIntegerv(GL_MATRIX_MODE, &oldmatrixmode);
		glMatrixMode(GL_MODELVIEW); glPushMatrix(); glLoadIdentity();
		glMatrixMode(GL_PROJECTION); glPushMatrix(); glLoadIdentity();

		// Draw the array of pixels
		// (This is where you draw the values you have stored in the array 'raster')
		glRasterPos2f(-1,-1);
		glDrawPixels(WIDTH, HEIGHT, GL_RGB, GL_FLOAT, raster);

		//Set the state back to what it was
		glPopMatrix(); glMatrixMode(GL_MODELVIEW);
		glPopMatrix(); glMatrixMode(oldmatrixmode);
		if (depthWasEnabled) glEnable(GL_DEPTH_TEST);
	}

	glFlush();
	glutSwapBuffers();
}

int main(int argc, char **argv){
	for(int i = 0; i < WIDTH * HEIGHT * BYTES; i++){
		raster[i] = ((float)i)/(WIDTH * HEIGHT * BYTES);
	}

	/* Initialize GLUT state - glut will take any command
	 * line arguments that pertain to it or X Windows.
	 *
	 * Documentation at http://reality.sgi.com/mjk/spec3/spec3.html
	 */
	glutInit(&argc, argv);

	/* Select type of Display mode:
	 * Double buffer					GLUT_DOUBLE
	 * RGBA color						GLUT_RGBA
	 * Alpha components supported		GLUT_ALPHA
	 * Depth buffer						GLUT_DEPTH
	 */
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);// Get a WIDTH x HEIGHT window
	glutInitWindowPosition(0, 0);// The window starts at the upper left corner of the screen

	window = glutCreateWindow("Setting up the Interface");// Open a window

	glutDisplayFunc(&DrawGLScene);// Register the function to do all our OpenGL drawing.
//	glutFullScreen();// Go full screen.  This is the soonest we could possibly go full screen.
	glutIdleFunc(&DrawGLScene);// Even if there are no events, redraw our GL scene.
	glutReshapeFunc(&ReSizeGLScene);// Register the function called when our window is resized.
	glutKeyboardFunc(&keyPressed);// Register the function called when the keyboard is pressed.

	InitGL(WIDTH, HEIGHT);// Initialize our window.
	glutMainLoop();// Start Event Processing Engine
}

