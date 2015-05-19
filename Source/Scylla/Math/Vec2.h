/*
 * Scylla
 * Copyright (C) 2015-2015 Callan Acton <callanacton@gmail.com>
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1.	The origin of this software must not be misrepresented; you must not
 *  	claim that you wrote the original software. If you use this software
 *    	in a product, an acknowledgment in the product documentation would be
 *    	appreciated but is not required.
 * 
 *  2. 	Altered source versions must be plainly marked as such, and must not be
 *    	misrepresented as being the original software.
 * 	
 *  3. 	This notice may not be removed or altered from any source distribution.
 */
#pragma once
#include <cstdint>

namespace Math {

/**
 * @brief Simple class that defines a mathematical vector with two coordinates (x and y).
 * 
 * Can be used to represent anything that has two dimensions; a size, a point,
 * velocity, etc.
 * 
 * The template parameter T is the type of the coordinates. It can be
 * any type that supports arithmetic operations (+, -, /, *) and comparisons (==, !=).
 * 
 * Generally, you shouldn't have to care about the templated form (Math::Vec2<T>) as
 * the most common specializations have special typedefs.
 * @li Math::Vec2<int32_t> is Vec2i
 * @li Math::Vec2<uint32_t> is Vec2u
 * @li Math::Vec2<float> is Vec2f
 * 
 * The Math::Vec2 class has a small and simple interface, its x and y
 * members can be accessed directly and it contains no mathematical functions.
 * 
 * @code
 * Vec2f v1(16.5f, 24.f);
 * v1.x = 17.3f;
 * float y = v1.y;
 * 
 * Vec2f v2 = v1 * 4.f;
 * Vec2f v3;
 * v3 = v1 + v2;
 * 
 * bool different = (v2 != v3);
 * @endcode
 * 
 * Note: For 3D Vectors, see @ref Math::Vec3.
 */
template <typename T> class Vec2 {
public:
	// Members
	T x;
	T y;

	/** @brief Default constructor */
	Vec2() : x(0), y(0) {}

	/** @brief Create vector from coordinates */
	Vec2(T X, T Y) : x(X), y(Y) {} 

	/** @brief Construct vector from another type of vector */
	template <typename U> explicit Vec2(const Vec2<U>& vector)
		: x(static_cast<T>(vector.x))
		, y(static_cast<T>(vector.y)) {}
};

template <typename T> Vec2<T> operator - (const Vec2<T>& r) {
	return Vec2<T>(-right.x, -right.y);
}

template <typename T> Vec2<T>& operator += (Vec2<T>& left, const Vec2<T>& right) {
	left.x += right.x;
	left.y += right.y;

	return left;
}

template <typename T> Vec2<T>& operator -= (Vec2<T>& left, const Vec2<T>& right) {
	left.x -= right.x;
	left.y -= right.y;

	return left;
}

template <typename T> Vec2<T> operator + (const Vec2<T>& left, const Vec2<T>& right) {
	return Vec2<T>(left.x + right.x, left.y + right.y);
}

template <typename T> Vec2<T> operator - (const Vec2<T>& left, const Vec2<T>& right) {
	return Vec2<T>(left.x - right.x, left.y - right.y);
}

template <typename T> Vec2<T> operator * (const Vec2<T>& left, T right) {
	return Vec2<T>(left.x * right, left.y * right);
}

template <typename T> Vec2<T> operator * (T left, const Vec2<T>& right) {
	return Vec2<T>(left.x * right.x, left.y * right.y);
}

template <typename T> Vec2<T>& operator *= (const Vec2<T>& left, T right) {
	left.x *= right;
	left.y *= right;

	return left;
}

template <typename T> Vec2<T> operator / (const Vec2<T>& left, T right) {
	return Vec2<T>(left.x / right, left.y / right);
}

template <typename T> Vec2<T>& operator /=(const Vec2<T>& left, T right) {
	left.x /= right;
	left.y /= right;

	return left;
}

template <typename T> bool operator == (const Vec2<T>& left, const Vec2<T>& right) {
	return (left.x == right.x) && (left.y == right.y);
}

template <typename T> inline bool operator !=(const Vec2<T>& left, const Vec2<T>& right) {
	return (left.x != right.x) || (left.y != right.y);
}
}

// Define the most common types of Vec2
typedef Math::Vec2<int32_t> 	Vec2i;
typedef Math::Vec2<uint32_t> 	Vec2u;
typedef Math::Vec2<float>	Vec2f;