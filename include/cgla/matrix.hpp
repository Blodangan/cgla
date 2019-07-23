#ifndef CGLA_MATRIX_HPP
#define CGLA_MATRIX_HPP

#include <cstddef>
#include <ostream>
#include <type_traits>
#include "vector.hpp"

namespace cgla {

template<typename T, std::size_t M, std::size_t N>
class Matrix
{
    static_assert(std::is_arithmetic<T>::value, "Argument T must be an arithmetic type");
    static_assert(M > 0 && N > 0, "Arguments M and N must be greater than zero");

    public:
        Matrix();
        Matrix(const Matrix<T, M, N>& other);
        template<typename... Args, typename = typename std::enable_if<sizeof...(Args) == M * N>::type> Matrix(Args... args);
        template<std::size_t P = M * N, typename = typename std::enable_if<(P > 1)>::type> explicit Matrix(T v);
        explicit Matrix(const T (&v)[M * N]);
        explicit Matrix(const T (&v)[N][M]);
        explicit Matrix(const Vector<T, M> (&v)[N]);
        template<typename U> explicit Matrix(const Matrix<U, M, N>& other);

        T* data();
        const T* data() const;
        T& operator[](std::size_t i);
        T operator[](std::size_t i) const;
        T& operator()(std::size_t i, std::size_t j);
        T operator()(std::size_t i, std::size_t j) const;

        Matrix<T, M, N>& operator=(const Matrix<T, M, N>& rhs);
        Matrix<T, M, N>& operator+=(const Matrix<T, M, N>& rhs);
        Matrix<T, M, N>& operator-=(const Matrix<T, M, N>& rhs);
        template<typename U> Matrix<T, M, N>& operator*=(U rhs);
        template<typename U> Matrix<T, M, N>& operator/=(U rhs);
        bool operator==(const Matrix<T, M, N>& rhs) const;
        bool operator!=(const Matrix<T, M, N>& rhs) const;
        bool operator<(const Matrix<T, M, N>& rhs) const;

    private:
        T values[M * N];
};

template<typename T, std::size_t M, std::size_t N> Matrix<T, M, N> operator-(Matrix<T, M, N> rhs);
template<typename T, std::size_t M, std::size_t N> Matrix<T, M, N> operator+(Matrix<T, M, N> lhs, const Matrix<T, M, N>& rhs);
template<typename T, std::size_t M, std::size_t N> Matrix<T, M, N> operator-(Matrix<T, M, N> lhs, const Matrix<T, M, N>& rhs);
template<typename T, std::size_t M, std::size_t N, typename U> Matrix<T, M, N> operator*(Matrix<T, M, N> lhs, U rhs);
template<typename T, std::size_t M, std::size_t N, typename U> Matrix<T, M, N> operator*(U lhs, Matrix<T, M, N> rhs);
template<typename T, std::size_t L, std::size_t M, std::size_t N> Matrix<T, L, N> operator*(const Matrix<T, L, M>& lhs, const Matrix<T, M, N>& rhs);
template<typename T, std::size_t M, std::size_t N> Vector<T, M> operator*(const Matrix<T, M, N>& lhs, const Vector<T, N>& rhs);
template<typename T, std::size_t M, std::size_t N> Vector<T, N> operator*(const Vector<T, M>& lhs, const Matrix<T, M, N>& rhs);
template<typename T, std::size_t M, std::size_t N, typename U> Matrix<T, M, N> operator/(Matrix<T, M, N> lhs, U rhs);
template<typename T, std::size_t M, std::size_t N> std::ostream& operator<<(std::ostream& lhs, const Matrix<T, M, N>& rhs);

template<typename T, std::size_t M, std::size_t N> Matrix<T, N, M> transpose(const Matrix<T, M, N>& mat);
template<typename T, std::size_t M> Matrix<T, M, M> inverse(Matrix<T, M, M> mat);
template<typename T, std::size_t M, std::size_t N> Matrix<T, M, N> matrixCompMult(const Matrix<T, M, N>& x, const Matrix<T, M, N>& y);
template<typename T, std::size_t M, std::size_t N> Matrix<T, M, N> outerProduct(const Vector<T, M>& u, const Vector<T, N>& v);

using Matrix2x2i = Matrix<int, 2, 2>; using Matrix2x3i = Matrix<int, 2, 3>; using Matrix2x4i = Matrix<int, 2, 4>;
using Matrix3x2i = Matrix<int, 3, 2>; using Matrix3x3i = Matrix<int, 3, 3>; using Matrix3x4i = Matrix<int, 3, 4>;
using Matrix4x2i = Matrix<int, 4, 2>; using Matrix4x3i = Matrix<int, 4, 3>; using Matrix4x4i = Matrix<int, 4, 4>;
using Matrix2i = Matrix2x2i; using Matrix3i = Matrix3x3i; using Matrix4i = Matrix4x4i;
using Matrix2x2f = Matrix<float, 2, 2>; using Matrix2x3f = Matrix<float, 2, 3>; using Matrix2x4f = Matrix<float, 2, 4>;
using Matrix3x2f = Matrix<float, 3, 2>; using Matrix3x3f = Matrix<float, 3, 3>; using Matrix3x4f = Matrix<float, 3, 4>;
using Matrix4x2f = Matrix<float, 4, 2>; using Matrix4x3f = Matrix<float, 4, 3>; using Matrix4x4f = Matrix<float, 4, 4>;
using Matrix2f = Matrix2x2f; using Matrix3f = Matrix3x3f; using Matrix4f = Matrix4x4f;
using Matrix2x2d = Matrix<double, 2, 2>; using Matrix2x3d = Matrix<double, 2, 3>; using Matrix2x4d = Matrix<double, 2, 4>;
using Matrix3x2d = Matrix<double, 3, 2>; using Matrix3x3d = Matrix<double, 3, 3>; using Matrix3x4d = Matrix<double, 3, 4>;
using Matrix4x2d = Matrix<double, 4, 2>; using Matrix4x3d = Matrix<double, 4, 3>; using Matrix4x4d = Matrix<double, 4, 4>;
using Matrix2d = Matrix2x2d; using Matrix3d = Matrix3x3d; using Matrix4d = Matrix4x4d;

}

#include "matrix.inl"

#endif
