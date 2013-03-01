/*
 * MyGLPrivate.cpp
 *
 *  Created on: Jan 19, 2013
 *      Author: ricksmt
 */

#include "MyGL.h"
#include "MyGLException.h"
#include "Point.h"
#include "Polygon.h"

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
		switch(readingMode){
			case GL_LINE_LOOP:
				Point p1(vertices.front());
				vertices.pop_front();
				Point p2(vertices.front());
				vertices.pop_front();
				Line l(p1, p2);
				l.draw();
				break;
			case GL_POLYGON:
				Polygon poly;
				while(!vertices.empty()){
					Point p(vertices.front());
					vertices.pop_front();
					poly << p;
				}
				poly.draw();
				break;
		}
		vertices.clear();
		odd = false;
	}

	void MyGL::myVertex2i(int x, int y){
		glVertex2i(x, y);
		vertices.push_back(Point(x, y));
		switch(readingMode){
			case GL_POINTS:
				vertices.front().draw();
				vertices.pop_front();
				break;
			case GL_LINES:
				if(vertices.size() < 2) break;
				Point p1(vertices.front());
				vertices.pop_front();
				Point p2(vertices.front());
				vertices.pop_front();
				Line l(p1, p2);
				l.draw();
				break;
			case GL_LINE_STRIP:
				Point p1(vertices.front());
				vertices.pop_front();
				Point p2(vertices.front());
				Line l(p1, p2);
				l.draw();
				break;
			case GL_LINE_LOOP:
				if(vertices.size() < 2) break;
				else if(vertices.size() == 2){
					Point p1(vertices.front());
					Point p2(vertices.back());
					Line l(p1, p2);
					l.draw();
				}
				else{
					Point p1(vertices.back());
					vertices.pop_back();
					Point p2(vertices.back());
					vertices.pop_back();
					Line l(p1, p2);
					vertices.push_back(p1);
					l.draw();
				}
				break;
			case GL_TRIANGLES:
				if(vertices.size() != 3) break;
				Point p1(vertices.front());
				vertices.pop_front();
				Point p2(vertices.front());
				vertices.pop_front();
				Point p3(vertices.front());
				vertices.pop_front();
				Polygon p;
				p << p1 << p2 << p3;
				p.draw();
				break;
			case GL_TRIANGLE_STRIP:
				if(vertices.size() != 3) break;
				Point p1(vertices.front());
				vertices.pop_front();
				Point p2(vertices.front());
				Point p3(vertices.back());
				Polygon p;
				if (odd) p << p1 << p2 << p3;
				else p << p2 << p1 << p3;
				p.draw();
				odd = !odd;
				break;
			case GL_TRIANGLE_FAN:
				if(vertices.size() != 3) break;
				Point p1(vertices.front());
				vertices.pop_front();
				Point p2(vertices.front());
				vertices.pop_front();
				vertices.push_front(p1);
				Point p3(vertices.back());
				Polygon p;
				p << p1 << p2 << p3;
				p.draw();
				break;
			case GL_QUADS:
				if(vertices.size() != 4) break;
				Point p1(vertices.front());
				vertices.pop_front();
				Point p2(vertices.front());
				vertices.pop_front();
				Point p3(vertices.front());
				vertices.pop_front();
				Point p4(vertices.front());
				vertices.pop_front();
				Polygon p;
				p << p1 << p2 << p3 << p4;
				p.draw();
				break;
			case GL_QUAD_STRIP:
				if(vertices.size() != 4) break;
				Point p1(vertices.front());
				vertices.pop_front();
				Point p2(vertices.front());
				vertices.pop_front();
				vertices.push_back(p2);
				Point p3(vertices.front());
				vertices.pop_front();
				vertices.push_back(p3);
				Point p4(vertices.front());
				vertices.pop_front();
				vertices.push_back(p4);
				Polygon p;
				p << p1 << p2 << p3 << p4;
				p.draw();
				break;
		}
	}
