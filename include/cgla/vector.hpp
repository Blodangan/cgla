#ifndef CGLA_VECTOR_HPP
#define CGLA_VECTOR_HPP

#include <cstddef>
#include <ostream>
#include <type_traits>
#include "config.hpp"

namespace cgla {

template<typename T, std::size_t N>
class Vector
{
    static_assert(std::is_arithmetic<T>::value, "Argument T must be an arithmetic type");
    static_assert(N > 0, "Argument N must be greater than zero");

    public:
        Vector();
        Vector(const Vector<T, N>& other);
        template<typename... Args> Vector(const Args&... args);
        template<std::size_t M = N, typename = typename std::enable_if<(M > 1)>::type> explicit Vector(T v);
        explicit Vector(const T (&v)[N]);
        template<typename U> explicit Vector(const Vector<U, N>& other);

        T* data();
        const T* data() const;
        T& operator[](std::size_t i);
        T operator[](std::size_t i) const;
        T& x();
        T x() const;
        template<std::size_t M = N, typename = typename std::enable_if<(M > 1)>::type> T& y();
        template<std::size_t M = N, typename = typename std::enable_if<(M > 1)>::type> T y() const;
        template<std::size_t M = N, typename = typename std::enable_if<(M > 2)>::type> T& z();
        template<std::size_t M = N, typename = typename std::enable_if<(M > 2)>::type> T z() const;
        template<std::size_t M = N, typename = typename std::enable_if<(M > 3)>::type> T& w();
        template<std::size_t M = N, typename = typename std::enable_if<(M > 3)>::type> T w() const;
        #ifdef CGLA_RGBA_ACCESSORS
        T& r();
        T r() const;
        template<std::size_t M = N, typename = typename std::enable_if<(M > 1)>::type> T& g();
        template<std::size_t M = N, typename = typename std::enable_if<(M > 1)>::type> T g() const;
        template<std::size_t M = N, typename = typename std::enable_if<(M > 2)>::type> T& b();
        template<std::size_t M = N, typename = typename std::enable_if<(M > 2)>::type> T b() const;
        template<std::size_t M = N, typename = typename std::enable_if<(M > 3)>::type> T& a();
        template<std::size_t M = N, typename = typename std::enable_if<(M > 3)>::type> T a() const;
        #endif
        #ifdef CGLA_STPQ_ACCESSORS
        T& s();
        T s() const;
        template<std::size_t M = N, typename = typename std::enable_if<(M > 1)>::type> T& t();
        template<std::size_t M = N, typename = typename std::enable_if<(M > 1)>::type> T t() const;
        template<std::size_t M = N, typename = typename std::enable_if<(M > 2)>::type> T& p();
        template<std::size_t M = N, typename = typename std::enable_if<(M > 2)>::type> T p() const;
        template<std::size_t M = N, typename = typename std::enable_if<(M > 3)>::type> T& q();
        template<std::size_t M = N, typename = typename std::enable_if<(M > 3)>::type> T q() const;
        #endif

        Vector<T, N>& operator=(const Vector<T, N>& rhs);
        Vector<T, N>& operator+=(const Vector<T, N>& rhs);
        Vector<T, N>& operator-=(const Vector<T, N>& rhs);
        template<typename U> Vector<T, N>& operator*=(U rhs);
        Vector<T, N>& operator*=(const Vector<T, N>& rhs);
        template<typename U> Vector<T, N>& operator/=(U rhs);
        Vector<T, N>& operator/=(const Vector<T, N>& rhs);
        bool operator==(const Vector<T, N>& rhs) const;
        bool operator!=(const Vector<T, N>& rhs) const;
        bool operator<(const Vector<T, N>& rhs) const;

    private:
        T values[N];
};

template<typename T, std::size_t N> Vector<T, N> operator-(Vector<T, N> rhs);
template<typename T, std::size_t N> Vector<T, N> operator+(Vector<T, N> lhs, const Vector<T, N>& rhs);
template<typename T, std::size_t N> Vector<T, N> operator-(Vector<T, N> lhs, const Vector<T, N>& rhs);
template<typename T, std::size_t N, typename U> Vector<T, N> operator*(Vector<T, N> lhs, U rhs);
template<typename T, std::size_t N, typename U> Vector<T, N> operator*(U lhs, Vector<T, N> rhs);
template<typename T, std::size_t N> Vector<T, N> operator*(Vector<T, N> lhs, const Vector<T, N>& rhs);
template<typename T, std::size_t N, typename U> Vector<T, N> operator/(Vector<T, N> lhs, U rhs);
template<typename T, std::size_t N, typename U> Vector<T, N> operator/(U lhs, const Vector<T, N>& rhs);
template<typename T, std::size_t N> Vector<T, N> operator/(Vector<T, N> lhs, const Vector<T, N>& rhs);
#ifdef CGLA_OSTREAM_OVERLOADS
template<typename T, std::size_t N> std::ostream& operator<<(std::ostream& lhs, const Vector<T, N>& rhs);
#endif

template<typename T, std::size_t N> T dot(const Vector<T, N>& u, const Vector<T, N>& v);
template<typename T> Vector<T, 3> cross(const Vector<T, 3>& u, const Vector<T, 3>& v);
template<typename T, std::size_t N> T lengthSquared(const Vector<T, N>& v);
template<typename T, std::size_t N> float length(const Vector<T, N>& v);
template<typename T, std::size_t N> T distanceSquared(const Vector<T, N>& u, const Vector<T, N>& v);
template<typename T, std::size_t N> float distance(const Vector<T, N>& u, const Vector<T, N>& v);
template<typename T, std::size_t N> Vector<T, N> normalize(const Vector<T, N>& v);

template<std::size_t... Indices, typename T, std::size_t N> Vector<T, sizeof...(Indices)> swizzle(const Vector<T, N>& v);
template<typename T, std::size_t N> Vector<T, 2> xy(const Vector<T, N>& v);
template<typename T, std::size_t N> Vector<T, 3> xyz(const Vector<T, N>& v);
#ifdef CGLA_RGBA_ACCESSORS
template<typename T, std::size_t N> Vector<T, 3> rgb(const Vector<T, N>& v);
template<typename T, std::size_t N> Vector<T, 3> bgr(const Vector<T, N>& v);
template<typename T, std::size_t N> Vector<T, 4> bgra(const Vector<T, N>& v);
#endif
#ifdef CGLA_STPQ_ACCESSORS
template<typename T, std::size_t N> Vector<T, 2> st(const Vector<T, N>& v);
template<typename T, std::size_t N> Vector<T, 2> pq(const Vector<T, N>& v);
#endif

#ifdef CGLA_TYPE_ALIASES
using Vector2i = Vector<int, 2>; using Vector3i = Vector<int, 3>; using Vector4i = Vector<int, 4>;
using Vector2f = Vector<float, 2>; using Vector3f = Vector<float, 3>; using Vector4f = Vector<float, 4>;
using Vector2d = Vector<double, 2>; using Vector3d = Vector<double, 3>; using Vector4d = Vector<double, 4>;
using Vector2ui = Vector<unsigned int, 2>; using Vector3ui = Vector<unsigned int, 3>; using Vector4ui = Vector<unsigned int, 4>;
#endif

}

#include "vector.inl"

#endif
