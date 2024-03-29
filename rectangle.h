#ifndef D_RECTANGLE_H_
#define D_RECTANGLE_H_ 1

#include <algorithm>
#include <iostream>

#include "vertex.h"
#include "vector.h"

template<class T>
struct rectangle {
	vertex<T> vertices[4];

	rectangle(std::istream& is);

	vertex<double> center() const;

	double area() const;
	void print() const;

};

template<class T>
rectangle<T>::rectangle(std::istream& is) {
	for(int i = 0; i < 4; ++i){
		is >> vertices[i];
	}

	if (isPerpendicular(Vector< vertex<T> >(vertices[0], vertices[1]), Vector< vertex<T> >(vertices[0], vertices[3])) && isPerpendicular(Vector< vertex<T> >(vertices[0], vertices[1]), Vector< vertex<T> >(vertices[1], vertices[2])) && 
		isPerpendicular(Vector< vertex<T> >(vertices[1], vertices[2]), Vector< vertex<T> >(vertices[2], vertices[3])) && isPerpendicular(Vector< vertex<T> >(vertices[2], vertices[3]), Vector< vertex<T> >(vertices[0], vertices[3]))) {



	} else if (isPerpendicular(Vector< vertex<T> >(vertices[0], vertices[3]), Vector< vertex<T> >(vertices[3], vertices[1])) && isPerpendicular(Vector< vertex<T> >(vertices[3], vertices[1]), Vector< vertex<T> >(vertices[1], vertices[2])) && 
		isPerpendicular(Vector< vertex<T> >(vertices[1], vertices[2]), Vector< vertex<T> >(vertices[2], vertices[0])) && isPerpendicular(Vector< vertex<T> >(vertices[0], vertices[2]), Vector< vertex<T> >(vertices[0], vertices[3]))) {

			vertex<T> tmp;
			tmp = vertices[0];
			vertices[0] = vertices[3];
			vertices[3] = tmp;

	} else if (isPerpendicular(Vector< vertex<T> >(vertices[0], vertices[1]), Vector< vertex<T> >(vertices[1], vertices[3])) && isPerpendicular(Vector< vertex<T> >(vertices[1], vertices[3]), Vector< vertex<T> >(vertices[3], vertices[2])) && 
		isPerpendicular(Vector< vertex<T> >(vertices[3], vertices[2]), Vector< vertex<T> >(vertices[2], vertices[0])) && isPerpendicular(Vector< vertex<T> >(vertices[2], vertices[0]), Vector< vertex<T> >(vertices[0], vertices[1]))) {

			vertex<T> tmp;
			tmp = vertices[2];
			vertices[2] = vertices[3];
			vertices[3] = tmp;

	} else if (vertices[0] == vertices[1] || vertices[0] == vertices[2] || vertices[0] == vertices[3] || vertices[1] == vertices[2] || vertices[1] == vertices[3] || vertices[2] == vertices[3]) {
		throw std::logic_error("No points are able to be equal");
	} else {
		throw std::logic_error("That's not a Rectangle, sides are not Perpendicular");
	}

	if (!(Vector< vertex<T> >(vertices[0], vertices[1]).length() == Vector< vertex<T> >(vertices[2], vertices[3]).length() && Vector< vertex<T> >(vertices[1], vertices[2]).length() == Vector< vertex<T> >(vertices[0], vertices[3]).length())) {
		throw std::logic_error("That's not a Rectangle, sides are not equal");
	}
}

template<class T>
double rectangle<T>::area() const {
	return Vector< vertex<T> >(vertices[0], vertices[1]).length() * Vector< vertex<T> >(vertices[1], vertices[2]).length();
}

template<class T>
void rectangle<T>::print() const {
	
	std::cout << vertices[0] << vertices[1] << vertices[2] << vertices[3] << '\n';

}

template<class T>
vertex<double> rectangle<T>::center() const {
	vertex<double> p;
	p.x = (vertices[0].x + vertices[1].x + vertices[2].x + vertices[3].x) / 4;
	p.y = (vertices[0].y + vertices[1].y + vertices[2].y + vertices[3].y) / 4;
	return p;
}

#endif // D_TRIANGLE_H_
