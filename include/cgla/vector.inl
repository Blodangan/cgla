#include <cstddef>
#include <cmath>
#include <ostream>
#include <type_traits>

namespace cgla {

namespace detail {
    template<std::size_t Index, typename T, std::size_t N> T at(const Vector<T, N>& v);
    template<std::size_t Index = 0, typename T, std::size_t N> void insert(Vector<T, N>& u, T v);
    template<std::size_t Index = 0, typename T, std::size_t N, typename... Args> void insert(Vector<T, N>& u, T v, const Args&... args);
    template<std::size_t Index = 0, typename T, std::size_t N, std::size_t M> void insert(Vector<T, N>& u, const Vector<T, M>& v);
    template<std::size_t Index = 0, typename T, std::size_t N, std::size_t M, typename... Args> void insert(Vector<T, N>& u, const Vector<T, M>& v, const Args&... args);
}

template<typename T, std::size_t N>
inline Vector<T, N>::Vector()
{
    for (std::size_t i = 0; i < N; ++i)
        values[i] = static_cast<T>(0);
}

template<typename T, std::size_t N>
inline Vector<T, N>::Vector(const Vector<T, N>& other)
{
    for (std::size_t i = 0; i < N; ++i)
        values[i] = other.values[i];
}

template<typename T, std::size_t N>
template<typename... Args>
inline Vector<T, N>::Vector(const Args&... args)
{
    detail::insert(*this, args...);
}

template<typename T, std::size_t N>
template<std::size_t, typename>
inline Vector<T, N>::Vector(T v)
{
    for (std::size_t i = 0; i < N; ++i)
        values[i] = v;
}

template<typename T, std::size_t N>
inline Vector<T, N>::Vector(const T (&v)[N])
{
    for (std::size_t i = 0; i < N; ++i)
        values[i] = v[i];
}

template<typename T, std::size_t N>
template<typename U>
inline Vector<T, N>::Vector(const Vector<U, N>& other)
{
    for (std::size_t i = 0; i < N; ++i)
        values[i] = static_cast<T>(other[i]);
}

template<typename T, std::size_t N>
inline T* Vector<T, N>::data()
{
    return values;
}

template<typename T, std::size_t N>
inline const T* Vector<T, N>::data() const
{
    return values;
}

template<typename T, std::size_t N>
inline T& Vector<T, N>::operator[](std::size_t i)
{
    return values[i];
}

template<typename T, std::size_t N>
inline T Vector<T, N>::operator[](std::size_t i) const
{
    return values[i];
}

template<typename T, std::size_t N>
inline T& Vector<T, N>::x()
{
    return values[0];
}

template<typename T, std::size_t N>
inline T Vector<T, N>::x() const
{
    return values[0];
}

template<typename T, std::size_t N>
template<std::size_t, typename>
inline T& Vector<T, N>::y()
{
    return values[1];
}

template<typename T, std::size_t N>
template<std::size_t, typename>
inline T Vector<T, N>::y() const
{
    return values[1];
}

template<typename T, std::size_t N>
template<std::size_t, typename>
inline T& Vector<T, N>::z()
{
    return values[2];
}

template<typename T, std::size_t N>
template<std::size_t, typename>
inline T Vector<T, N>::z() const
{
    return values[2];
}

template<typename T, std::size_t N>
template<std::size_t, typename>
inline T& Vector<T, N>::w()
{
    return values[3];
}

template<typename T, std::size_t N>
template<std::size_t, typename>
inline T Vector<T, N>::w() const
{
    return values[3];
}

template<typename T, std::size_t N>
inline Vector<T, N>& Vector<T, N>::operator=(const Vector<T, N>& rhs)
{
    for (std::size_t i = 0; i < N; ++i)
        values[i] = rhs.values[i];

    return *this;
}

template<typename T, std::size_t N>
inline Vector<T, N>& Vector<T, N>::operator+=(const Vector<T, N>& rhs)
{
    for (std::size_t i = 0; i < N; ++i)
        values[i] += rhs.values[i];

    return *this;
}

template<typename T, std::size_t N>
inline Vector<T, N>& Vector<T, N>::operator-=(const Vector<T, N>& rhs)
{
    for (std::size_t i = 0; i < N; ++i)
        values[i] -= rhs.values[i];

    return *this;
}

template<typename T, std::size_t N>
template<typename U>
inline Vector<T, N>& Vector<T, N>::operator*=(U rhs)
{
    for (std::size_t i = 0; i < N; ++i)
        values[i] *= rhs;

    return *this;
}

template<typename T, std::size_t N>
inline Vector<T, N>& Vector<T, N>::operator*=(const Vector<T, N>& rhs)
{
    for (std::size_t i = 0; i < N; ++i)
        values[i] *= rhs.values[i];

    return *this;
}

template<typename T, std::size_t N>
template<typename U>
inline Vector<T, N>& Vector<T, N>::operator/=(U rhs)
{
    for (std::size_t i = 0; i < N; ++i)
        values[i] /= rhs;

    return *this;
}

template<typename T, std::size_t N>
inline Vector<T, N>& Vector<T, N>::operator/=(const Vector<T, N>& rhs)
{
    for (std::size_t i = 0; i < N; ++i)
        values[i] /= rhs.values[i];

    return *this;
}

template<typename T, std::size_t N>
inline bool Vector<T, N>::operator==(const Vector<T, N>& rhs) const
{
    for (std::size_t i = 0; i < N; ++i)
        if (values[i] != rhs.values[i])
            return false;

    return true;
}

template<typename T, std::size_t N>
inline bool Vector<T, N>::operator!=(const Vector<T, N>& rhs) const
{
    return !(*this == rhs);
}

template<typename T, std::size_t N>
inline bool Vector<T, N>::operator<(const Vector<T, N>& rhs) const
{
    for (std::size_t i = 0; i < N; ++i)
        if (values[i] != rhs.values[i])
            return values[i] < rhs.values[i];

    return false;
}

template<typename T, std::size_t N>
inline Vector<T, N> operator-(Vector<T, N> rhs)
{
    return rhs *= -1;
}

template<typename T, std::size_t N>
inline Vector<T, N> operator+(Vector<T, N> lhs, const Vector<T, N>& rhs)
{
    return lhs += rhs;
}

template<typename T, std::size_t N>
inline Vector<T, N> operator-(Vector<T, N> lhs, const Vector<T, N>& rhs)
{
    return lhs -= rhs;
}

template<typename T, std::size_t N, typename U>
inline Vector<T, N> operator*(Vector<T, N> lhs, U rhs)
{
    return lhs *= rhs;
}

template<typename T, std::size_t N, typename U>
inline Vector<T, N> operator*(U lhs, Vector<T, N> rhs)
{
    return rhs *= lhs;
}

template<typename T, std::size_t N>
inline Vector<T, N> operator*(Vector<T, N> lhs, const Vector<T, N>& rhs)
{
    return lhs *= rhs;
}

template<typename T, std::size_t N, typename U>
inline Vector<T, N> operator/(Vector<T, N> lhs, U rhs)
{
    return lhs /= rhs;
}

template<typename T, std::size_t N, typename U>
inline Vector<T, N> operator/(U lhs, const Vector<T, N>& rhs)
{
    Vector<T, N> res;

    for (std::size_t i = 0; i < N; ++i)
        res[i] = lhs / rhs[i];

    return res;
}

template<typename T, std::size_t N>
inline Vector<T, N> operator/(Vector<T, N> lhs, const Vector<T, N>& rhs)
{
    return lhs /= rhs;
}

template<typename T, std::size_t N>
std::ostream& operator<<(std::ostream& lhs, const Vector<T, N>& rhs)
{
    lhs << '(';

    for (std::size_t i = 0; i < N - 1; ++i)
        lhs << rhs[i] << ", ";

    lhs << rhs[N - 1] << ')';

    return lhs;
}

template<typename T, std::size_t N>
inline T dot(const Vector<T, N>& u, const Vector<T, N>& v)
{
    T res = static_cast<T>(0);
    for (std::size_t i = 0; i < N; ++i)
        res += u[i] * v[i];

    return res;
}

template<typename T>
inline Vector<T, 3> cross(const Vector<T, 3>& u, const Vector<T, 3>& v)
{
    return Vector<T, 3>({u[1] * v[2] - u[2] * v[1],
                         u[2] * v[0] - u[0] * v[2],
                         u[0] * v[1] - u[1] * v[0]});
}

template<typename T, std::size_t N>
inline T lengthSquared(const Vector<T, N>& v)
{
    return dot(v, v);
}

template<typename T, std::size_t N>
inline float length(const Vector<T, N>& v)
{
    return std::sqrt(lengthSquared(v));
}

template<typename T, std::size_t N>
inline T distanceSquared(const Vector<T, N>& u, const Vector<T, N>& v)
{
    return lengthSquared(u - v);
}

template<typename T, std::size_t N>
inline float distance(const Vector<T, N>& u, const Vector<T, N>& v)
{
    return length(u - v);
}

template<typename T, std::size_t N>
inline Vector<T, N> normalize(const Vector<T, N>& v)
{
    return v / length(v);
}

template<std::size_t... Indices, typename T, std::size_t N>
inline Vector<T, sizeof...(Indices)> swizzle(const Vector<T, N>& v)
{
    return {detail::at<Indices>(v)...};
}

template<typename T, std::size_t N>
inline Vector<T, 2> xy(const Vector<T, N>& v)
{
    return swizzle<0, 1>(v);
}

template<typename T, std::size_t N>
inline Vector<T, 3> xyz(const Vector<T, N>& v)
{
    return swizzle<0, 1, 2>(v);
}

namespace detail {
    template<std::size_t Index, typename T, std::size_t N>
    inline T at(const Vector<T, N>& v)
    {
        static_assert(Index < N, "swizzle: Index out of range");

        return v[Index];
    }

    template<std::size_t Index, typename T, std::size_t N>
    inline void insert(Vector<T, N>& u, T v)
    {
        static_assert(Index < N, "Too many components");
        static_assert(Index + 2 > N, "Not enough components");

        u[Index] = v;
    }

    template<std::size_t Index, typename T, std::size_t N, typename... Args>
    inline void insert(Vector<T, N>& u, T v, const Args&... args)
    {
        static_assert(Index < N, "Too many components");

        u[Index] = v;

        insert<Index + 1>(u, args...);
    }

    template<std::size_t Index, typename T, std::size_t N, std::size_t M>
    inline void insert(Vector<T, N>& u, const Vector<T, M>& v)
    {
        static_assert(Index + M - 1 < N, "Too many components");
        static_assert(Index + M + 1 > N, "Not enough components");

        for (std::size_t i = 0; i < M; ++i)
            u[Index + i] = v[i];
    }

    template<std::size_t Index, typename T, std::size_t N, std::size_t M, typename... Args>
    inline void insert(Vector<T, N>& u, const Vector<T, M>& v, const Args&... args)
    {
        static_assert(Index + M - 1 < N, "Too many components");

        for (std::size_t i = 0; i < M; ++i)
            u[Index + i] = v[i];

        insert<Index + M>(u, args...);
    }
}

}
