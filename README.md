# cgla

A (n-dimensional) linear algebra library for computer graphics.

## Documentation

### [vector.hpp](include/cgla/vector.hpp)

`Vector<T, N>` defines a vector containing `N` scalar components of type `T`.

Aliases are provided. N can be 2, 3, or 4 :
* `VectorNi` : a vector of `int`
* `VectorNf` : a vector of `float`
* `VectorNd` : a vector of `double`
* `VectorNui` : a vector of `unsigned int`

#### Constructors

* Default constructor
```cpp
cgla::Vector3i v; // v = {0, 0, 0}
```

* Constructible from a combination of vectors and scalars of type `T`
```cpp
cgla::Vector3i u{2, 3, 4}; // u = {2, 3, 4}
cgla::Vector<int, 5> v{1, u, 5}; // v = {1, 2, 3, 4, 5}
```

* Copy constructor
```cpp
cgla::Vector3i u{1, 2, 3};
cgla::Vector3i v{u}; // v = {1, 2, 3}
```

* Explicitly constructible from a scalar of type `T`
```cpp
cgla::Vector3i v{1}; // v = {1, 1, 1}
```

* Explicitly constructible from an array of scalars of type `T`
```cpp
int values[3] = {1, 2, 3};
cgla::Vector3i v{values}; // v = {1, 2, 3}
```

* Explicitly constructible from a `Vector<U, N>`
```cpp
cgla::Vector3i u{1, 2, 3};
cgla::Vector3f v{u}; // v = {1.f, 2.f, 3.f}
```

#### Accessors

* Direct access to the underlying array
```cpp
cgla::Vector3i v{1, 2, 3};
int* p = v.data();
p[2] = 4; // v = {1, 2, 4}
```

* Indexing
```cpp
cgla::Vector3i v{1, 2, 3};
v[2] = 4; // v = {1, 2, 4}
```

* `x()`, `y()`, `z()`, `w()` accessors
```cpp
cgla::Vector<int, 5> v{1, 2, 3, 4, 5};
v.y() = 1; // v = {1, 1, 3, 4, 5}
v.w() = 3; // v = {1, 1, 3, 3, 5}
```

* `r()`, `g()`, `b()`, `a()` accessors. See [config.hpp](#confighpp)
* `s()`, `t()`, `p()`, `q()` accessors. See [config.hpp](#confighpp)

#### Operators

* Assignment
```cpp
cgla::Vector3i u{1, 2, 3};
cgla::Vector3i v;
v = u; // v = {1, 2, 3}
```

* Unary operator `-`
```cpp
cgla::Vector3i u{1, 2, 3};
cgla::Vector3i v = -u; // v = {-1, -2, -3}
```

* Binary operators `+=`, `-=`, `*=`, `/=`, `+`, `-`, `*`, `/` between `Vector<T, N>` work component-wise
```cpp
cgla::Vector3i u{1, 2, 3};
cgla::Vector3i v{5, 4, 3};
u = v / u; // u = {5, 2, 1}
v += u; // v = {10, 6, 4}
```

* Binary operators `*=`, `/=`, `*`, `/` between `Vector<T, N>` and scalar of type `U` work component-wise
```cpp
cgla::Vector3f u{1.f, 2.f, 4.f};
cgla::Vector3f v = 3 * u; // v = {3.f, 6.f, 12.f}
cgla::Vector3f w = 1 / u; // w = {1.f, 0.5f, 0.25f}
```

* Comparison operators `==`, `!=`, `<`
```cpp
cgla::Vector3i u{1, 2, 3};
cgla::Vector3i v{4, 5, 6};
bool eq = (u == v); // eq = false
bool neq = (u != v); // neq = true
bool lt = (u < v); // lt = true (lexicographic order)
```

* `<<` operator for `std::ostream`
```cpp
cgla::Vector3i u{1, 2, 3};
std::cout << u; // prints (1, 2, 3)
```

#### Functions

* `dot` : returns the dot product of two vectors
```cpp
T dot(Vector<T, N> u, Vector<T, N> v)
```

* `cross` : returns the cross product of two vectors
```cpp
Vector<T, 3> cross(Vector<T, 3> u, Vector<T, 3> v)
```

* `lengthSquared` : returns the squared length of a vector
```cpp
T lengthSquared(Vector<T, N> v)
```

* `length` : returns the length of a vector
```cpp
float length(Vector<T, N> v)
```

* `distanceSquared` : returns the squared distance between two vectors
```cpp
T distanceSquared(Vector<T, N> u, Vector<T, N> v)
```

* `distance` : returns the distance between two vectors
```cpp
float distance(Vector<T, N> u, Vector<T, N> v)
```

* `normalize` : returns the normalized form of a vector
```cpp
Vector<T, N> normalize(Vector<T, N> v)
```

* `swizzle` : returns a vector from a combination of components
```cpp
template<std::size_t... Indices> Vector<T, sizeof...(Indices)> swizzle(Vector<T, N> v)
```
```cpp
cgla::Vector3i u{1, 2, 3};
cgla::Vector<int, 5> v = cgla::swizzle<2, 2, 1, 0, 0>(u); // v = {3, 3, 2, 1, 1}
```

* `xy` : shorthand for `swizzle<0, 1>`
* `xyz` : shorthand for `swizzle<0, 1, 2>`

* `rgb` : shorthand for `swizzle<0, 1, 2>`. See [config.hpp](#confighpp)
* `bgr` : shorthand for `swizzle<2, 1, 0>`. See [config.hpp](#confighpp)
* `bgra` : shorthand for `swizzle<2, 1, 0, 3>`. See [config.hpp](#confighpp)

* `st` : shorthand for `swizzle<0, 1>`. See [config.hpp](#confighpp)
* `pq` : shorthand for `swizzle<2, 3>`. See [config.hpp](#confighpp)

### [matrix.hpp](include/cgla/matrix.hpp)

### [transform.hpp](include/cgla/transform.hpp)

### [config.hpp](include/cgla/config.hpp)

### [cgla.hpp](include/cgla/cgla.hpp)

This header is an all-in-one header.

## License

cgla is released under the [MIT License](LICENSE).
