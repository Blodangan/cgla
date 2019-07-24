#include <cmath>
#include "vector.hpp"
#include "matrix.hpp"

namespace cgla {

template<typename T>
Matrix<T, 4, 4> translate(const Vector<T, 3>& v)
{
    Matrix<T, 4, 4> res{static_cast<T>(1)};

    res[12] = v[0];
    res[13] = v[1];
    res[14] = v[2];

    return res;
}

template<typename T>
Matrix<T, 4, 4> scale(const Vector<T, 3>& v)
{
    Matrix<T, 4, 4> res{};

    res[0] = v[0];
    res[5] = v[1];
    res[10] = v[2];
    res[15] = static_cast<T>(1);

    return res;
}

template<typename T>
Matrix<T, 4, 4> scale(T v)
{
    Matrix<T, 4, 4> res{};

    res[0] = v;
    res[5] = v;
    res[10] = v;
    res[15] = static_cast<T>(1);

    return res;
}

template<typename T>
Matrix<T, 4, 4> rotateX(T angle)
{
    Matrix<T, 4, 4> res{static_cast<T>(1)};

    T c = std::cos(angle);
    T s = std::sin(angle);

    res[5] = c;
    res[6] = s;
    res[9] = -s;
    res[10] = c;

    return res;
}

template<typename T>
Matrix<T, 4, 4> rotateY(T angle)
{
    Matrix<T, 4, 4> res{static_cast<T>(1)};

    T c = std::cos(angle);
    T s = std::sin(angle);

    res[0] = c;
    res[2] = -s;
    res[8] = s;
    res[10] = c;

    return res;
}

template<typename T>
Matrix<T, 4, 4> rotateZ(T angle)
{
    Matrix<T, 4, 4> res{static_cast<T>(1)};

    T c = std::cos(angle);
    T s = std::sin(angle);

    res[0] = c;
    res[1] = s;
    res[4] = -s;
    res[5] = c;

    return res;
}

template<typename T>
Matrix<T, 4, 4> rotate(T angle, const Vector<T, 3>& axis)
{
    Matrix<T, 4, 4> res{};

    T c = std::cos(angle);
    T s = std::sin(angle);
    T omc = static_cast<T>(1) - c;
    Vector<T, 3> v = normalize(axis);

    res[0] = c + v[0] * v[0] * omc;
    res[1] = v[1] * v[0] * omc + v[2] * s;
    res[2] = v[2] * v[0] * omc - v[1] * s;

    res[4] = v[0] * v[1] * omc - v[2] * s;
    res[5] = c + v[1] * v[1] * omc;
    res[6] = v[2] * v[1] * omc + v[0] * s;

    res[8] = v[0] * v[2] * omc + v[1] * s;
    res[9] = v[1] * v[2] * omc - v[0] * s;
    res[10] = c + v[2] * v[2] * omc;

    res[15] = static_cast<T>(1);

    return res;
}

template<typename T>
Matrix<T, 4, 4> lookAt(const Vector<T, 3>& eye, const Vector<T, 3>& target, const Vector<T, 3>& up)
{
    Matrix<T, 4, 4> res{};

    Vector<T, 3> f = normalize(eye - target);
    Vector<T, 3> s = normalize(cross(up, f));
    Vector<T, 3> u = cross(f, s);

    res[0] = s[0];
    res[4] = s[1];
    res[8] = s[2];

    res[1] = u[0];
    res[5] = u[1];
    res[9] = u[2];

    res[2] = f[0];
    res[6] = f[1];
    res[10] = f[2];

    res[12] = -dot(s, eye);
    res[13] = -dot(u, eye);
    res[14] = -dot(f, eye);
    res[15] = static_cast<T>(1);

    return res;
}

template<typename T>
Matrix<T, 4, 4> orthographic(T left, T right, T bottom, T top, T near, T far)
{
    Matrix<T, 4, 4> res{};

    res[0] = static_cast<T>(2) / (right - left);
    res[5] = static_cast<T>(2) / (top - bottom);
    res[10] = -static_cast<T>(2) / (far - near);
    res[12] = -(right + left) / (right - left);
    res[13] = -(top + bottom) / (top - bottom);
    res[14] = -(far + near) / (far - near);
    res[15] = static_cast<T>(1);

    return res;
}

template<typename T>
Matrix<T, 4, 4> perspective(T fovy, T aspect, T near, T far)
{
    Matrix<T, 4, 4> res{};

    T invTan = static_cast<T>(1) / std::tan(fovy / static_cast<T>(2));

    res[0] = invTan / aspect;
    res[5] = invTan;
    res[10] = -(far + near) / (far - near);
    res[11] = -static_cast<T>(1);
    res[14] = -(static_cast<T>(2) * far * near) / (far - near);

    return res;
}

}
