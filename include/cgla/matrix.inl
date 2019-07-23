#include <cstddef>
#include <cmath>
#include <algorithm>
#include <ostream>
#include "vector.hpp"

namespace cgla {

template<typename T, std::size_t M, std::size_t N>
inline Matrix<T, M, N>::Matrix()
{
    for (std::size_t i = 0; i < M * N; ++i)
        values[i] = static_cast<T>(0);
}

template<typename T, std::size_t M, std::size_t N>
inline Matrix<T, M, N>::Matrix(const Matrix<T, M, N>& other)
{
    for (std::size_t i = 0; i < M * N; ++i)
        values[i] = other.values[i];
}

template<typename T, std::size_t M, std::size_t N>
template<typename... Args, typename>
inline Matrix<T, M, N>::Matrix(Args... args) :
    values{args...}
{
}

template<typename T, std::size_t M, std::size_t N>
template<std::size_t, typename>
inline Matrix<T, M, N>::Matrix(T v)
{
    for (std::size_t j = 0; j < N; ++j)
        for (std::size_t i = 0; i < M; ++i)
            values[j * M + i] = (i == j) ? v : static_cast<T>(0);
}

template<typename T, std::size_t M, std::size_t N>
inline Matrix<T, M, N>::Matrix(const T (&v)[M * N])
{
    for (std::size_t i = 0; i < M * N; ++i)
        values[i] = v[i];
}

template<typename T, std::size_t M, std::size_t N>
inline Matrix<T, M, N>::Matrix(const T (&v)[N][M])
{
    for (std::size_t j = 0; j < N; ++j)
        for (std::size_t i = 0; i < M; ++i)
            values[j * M + i] = v[j][i];
}

template<typename T, std::size_t M, std::size_t N>
inline Matrix<T, M, N>::Matrix(const Vector<T, M> (&v)[N])
{
    for (std::size_t j = 0; j < N; ++j)
        for (std::size_t i = 0; i < M; ++i)
            values[j * M + i] = v[j][i];
}

template<typename T, std::size_t M, std::size_t N>
template<typename U>
inline Matrix<T, M, N>::Matrix(const Matrix<U, M, N>& other)
{
    for (std::size_t i = 0; i < M * N; ++i)
        values[i] = static_cast<T>(other[i]);
}

template<typename T, std::size_t M, std::size_t N>
inline T* Matrix<T, M, N>::data()
{
    return values;
}

template<typename T, std::size_t M, std::size_t N>
inline const T* Matrix<T, M, N>::data() const
{
    return values;
}

template<typename T, std::size_t M, std::size_t N>
inline T& Matrix<T, M, N>::operator[](std::size_t i)
{
    return values[i];
}

template<typename T, std::size_t M, std::size_t N>
inline T Matrix<T, M, N>::operator[](std::size_t i) const
{
    return values[i];
}

template<typename T, std::size_t M, std::size_t N>
inline T& Matrix<T, M, N>::operator()(std::size_t i, std::size_t j)
{
    return values[j * M + i];
}

template<typename T, std::size_t M, std::size_t N>
inline T Matrix<T, M, N>::operator()(std::size_t i, std::size_t j) const
{
    return values[j * M + i];
}

template<typename T, std::size_t M, std::size_t N>
inline Matrix<T, M, N>& Matrix<T, M, N>::operator=(const Matrix<T, M, N>& rhs)
{
    for (std::size_t i = 0; i < M * N; ++i)
        values[i] = rhs.values[i];

    return *this;
}

template<typename T, std::size_t M, std::size_t N>
inline Matrix<T, M, N>& Matrix<T, M, N>::operator+=(const Matrix<T, M, N>& rhs)
{
    for (std::size_t i = 0; i < M * N; ++i)
        values[i] += rhs.values[i];

    return *this;
}

template<typename T, std::size_t M, std::size_t N>
inline Matrix<T, M, N>& Matrix<T, M, N>::operator-=(const Matrix<T, M, N>& rhs)
{
    for (std::size_t i = 0; i < M * N; ++i)
        values[i] -= rhs.values[i];

    return *this;
}

template<typename T, std::size_t M, std::size_t N>
template<typename U>
inline Matrix<T, M, N>& Matrix<T, M, N>::operator*=(U rhs)
{
    for (std::size_t i = 0; i < M * N; ++i)
        values[i] *= rhs;

    return *this;
}

template<typename T, std::size_t M, std::size_t N>
template<typename U>
inline Matrix<T, M, N>& Matrix<T, M, N>::operator/=(U rhs)
{
    for (std::size_t i = 0; i < M * N; ++i)
        values[i] /= rhs;

    return *this;
}

template<typename T, std::size_t M, std::size_t N>
inline bool Matrix<T, M, N>::operator==(const Matrix<T, M, N>& rhs) const
{
    for (std::size_t i = 0; i < M * N; ++i)
        if (values[i] != rhs.values[i])
            return false;

    return true;
}

template<typename T, std::size_t M, std::size_t N>
inline bool Matrix<T, M, N>::operator!=(const Matrix<T, M, N>& rhs) const
{
    return !(*this == rhs);
}

template<typename T, std::size_t M, std::size_t N>
inline bool Matrix<T, M, N>::operator<(const Matrix<T, M, N>& rhs) const
{
    for (std::size_t i = 0; i < M * N; ++i)
        if (values[i] != rhs.values[i])
            return values[i] < rhs.values[i];

    return false;
}

template<typename T, std::size_t M, std::size_t N>
inline Matrix<T, M, N> operator-(Matrix<T, M, N> rhs)
{
    return rhs *= -1;
}

template<typename T, std::size_t M, std::size_t N>
inline Matrix<T, M, N> operator+(Matrix<T, M, N> lhs, const Matrix<T, M, N>& rhs)
{
    return lhs += rhs;
}

template<typename T, std::size_t M, std::size_t N>
inline Matrix<T, M, N> operator-(Matrix<T, M, N> lhs, const Matrix<T, M, N>& rhs)
{
    return lhs -= rhs;
}

template<typename T, std::size_t M, std::size_t N, typename U>
inline Matrix<T, M, N> operator*(Matrix<T, M, N> lhs, U rhs)
{
    return lhs *= rhs;
}

template<typename T, std::size_t M, std::size_t N, typename U>
inline Matrix<T, M, N> operator*(U lhs, Matrix<T, M, N> rhs)
{
    return rhs *= lhs;
}

template<typename T, std::size_t L, std::size_t M, std::size_t N>
inline Matrix<T, L, N> operator*(const Matrix<T, L, M>& lhs, const Matrix<T, M, N>& rhs)
{
    Matrix<T, L, N> res;

    for (std::size_t j = 0; j < N; ++j)
        for (std::size_t i = 0; i < L; ++i)
            for (std::size_t k = 0; k < M; ++k)
                res(i, j) += lhs(i, k) * rhs(k, j);

    return res;
}

template<typename T, std::size_t M, std::size_t N>
inline Vector<T, M> operator*(const Matrix<T, M, N>& lhs, const Vector<T, N>& rhs)
{
    Vector<T, M> res;

    for (std::size_t i = 0; i < M; ++i)
        for (std::size_t j = 0; j < N; ++j)
            res[i] += lhs(i, j) * rhs[j];

    return res;
}

template<typename T, std::size_t M, std::size_t N>
inline Vector<T, N> operator*(const Vector<T, M>& lhs, const Matrix<T, M, N>& rhs)
{
    Vector<T, N> res;

    for (std::size_t j = 0; j < N; ++j)
        for (std::size_t i = 0; i < M; ++i)
            res[j] += lhs[i] * rhs(i, j);

    return res;
}

template<typename T, std::size_t M, std::size_t N, typename U>
inline Matrix<T, M, N> operator/(Matrix<T, M, N> lhs, U rhs)
{
    return lhs /= rhs;
}

template<typename T, std::size_t M, std::size_t N>
std::ostream& operator<<(std::ostream& lhs, const Matrix<T, M, N>& rhs)
{
    lhs << '(';

    for (std::size_t j = 0; j < N - 1; ++j)
    {
        lhs << '(';

        for (std::size_t i = 0; i < M - 1; ++i)
            lhs << rhs(i, j) << ", ";

        lhs << rhs(M - 1, j) << "), ";
    }

    lhs << '(';

    for (std::size_t i = 0; i < M - 1; ++i)
        lhs << rhs(i, N - 1) << ", ";

    lhs << rhs(M - 1, N - 1) << "))";

    return lhs;
}

template<typename T, std::size_t M, std::size_t N>
inline Matrix<T, N, M> transpose(const Matrix<T, M, N>& mat)
{
    Matrix<T, N, M> res;

    for (std::size_t j = 0; j < M; ++j)
        for (std::size_t i = 0; i < N; ++i)
            res(i, j) = mat(j, i);

    return res;
}

template<typename T, std::size_t M>
Matrix<T, M, M> inverse(Matrix<T, M, M> mat)
{
    Matrix<T, M, M> inv{static_cast<T>(1)};

    for (std::size_t j = 0; j < M; ++j)
    {
        std::size_t p = j;
        T pval = std::abs(mat(j, j));

        for (std::size_t k = j + 1; k < M; ++k)
        {
            T val = std::abs(mat(j, k));
            if (val > pval)
            {
                p = k;
                pval = val;
            }
        }

        if (p != j)
        {
            for (std::size_t i = 0; i < M; ++i)
            {
                std::swap(mat(i, j), mat(i, p));
                std::swap(inv(i, j), inv(i, p));
            }
        }

        T coeff = mat(j, j);
        for (std::size_t i = 0; i < M; ++i)
        {
            mat(i, j) /= coeff;
            inv(i, j) /= coeff;
        }

        for (std::size_t i = 0; i < M; ++i)
        {
            if (i != j)
            {
                T coeff = mat(j, i);
                for (std::size_t k = 0; k < M; ++k)
                {
                    mat(k, i) -= coeff * mat(k, j);
                    inv(k, i) -= coeff * inv(k, j);
                }
            }
        }
    }

    return inv;
}

template<typename T, std::size_t M, std::size_t N>
inline Matrix<T, M, N> matrixCompMult(const Matrix<T, M, N>& x, const Matrix<T, M, N>& y)
{
    Matrix<T, M, N> res;

    for (std::size_t i = 0; i < M * N; ++i)
        res[i] = x[i] * y[i];

    return res;
}

template<typename T, std::size_t M, std::size_t N>
inline Matrix<T, M, N> outerProduct(const Vector<T, M>& u, const Vector<T, N>& v)
{
    Matrix<T, M, N> res;

    for (std::size_t j = 0; j < N; ++j)
        for (std::size_t i = 0; i < M; ++i)
            res(i, j) = u[i] * v[j];

    return res;
}

}
