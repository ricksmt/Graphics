/*
 * Point.h
 *
 *  Created on: Jan 23, 2013
 *      Author: ricksmt
 */

#ifndef POINT_H_
#define POINT_H_

#include <stdarg.h>
#include <vector>

//#include <Eigen/Core>
//template <typename T, int dimension>
//typedef Eigen::Matrix<T, dimension, 1> Point;

template <typename T>
class Point{
	const static double ERROR = 0.000001;

	std::vector<T> points;
public:
	Point(const int dimension, ...) {
		va_list args;
		va_start(args, dimension);
		for(int i = 0; i < dimension; i++) points[i] = va_arg(args, T);
		va_end(args);
	}

	unsigned dimension() const { return points.size(); }

	T& operator [](const int index) const {
		if(index < 0 || index >= dimension) throw "Index out of bounds. Index = " + index;
		return points[index];
	}

//	bool normalized() const {
//		T squares;
//		for(int i = 0; i < dimension(); i++) squares += pow((double)points[i], 2);
//		squares = pow(squares, 0.5);
//		return squares < 1 + ERROR && squares > 1 - ERROR;
//	}
//
//	void normalize() {
//		T squares;
//		for(int i = 0; i < dimension(); i++) squares += pow((double)points[i], 2);
//		squares = pow(squares, 0.5);
//		for(int i = 0; i < dimension(); i++) points[i] /= squares;
//	}
};


#endif /* POINT_H_ */
