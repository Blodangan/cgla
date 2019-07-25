#ifndef CGLA_TRANSFORM_HPP
#define CGLA_TRANSFORM_HPP

#include "vector.hpp"
#include "matrix.hpp"

namespace cgla {

template<typename T> Matrix<T, 4, 4> translate(const Vector<T, 3>& v);
template<typename T> Matrix<T, 4, 4> scale(const Vector<T, 3>& v);
template<typename T> Matrix<T, 4, 4> scale(T v);
template<typename T> Matrix<T, 4, 4> rotateX(T angle);
template<typename T> Matrix<T, 4, 4> rotateY(T angle);
template<typename T> Matrix<T, 4, 4> rotateZ(T angle);
template<typename T> Matrix<T, 4, 4> rotate(T angle, const Vector<T, 3>& axis);
template<typename T> Matrix<T, 4, 4> lookAt(const Vector<T, 3>& eye, const Vector<T, 3>& target, const Vector<T, 3>& up);
template<typename T> Matrix<T, 4, 4> orthographic(T left, T right, T bottom, T top, T near, T far);
template<typename T> Matrix<T, 4, 4> frustum(T left, T right, T bottom, T top, T near, T far);
template<typename T> Matrix<T, 4, 4> perspective(T fovy, T aspect, T near, T far);

}

#include "transform.inl"

#endif
