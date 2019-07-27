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

* `r()`, `g()`, `b()`, `a()` accessors. See [config.hpp]()
* `s()`, `t()`, `p()`, `q()` accessors. See [config.hpp]()

#### Operators

#### Functions

### [matrix.hpp](include/cgla/matrix.hpp)

### [transform.hpp](include/cgla/transform.hpp)

### [config.hpp](include/cgla/config.hpp)

### [cgla.hpp](include/cgla/cgla.hpp)

This header is an all-in-one header.

## License

cgla is released under the [MIT License](LICENSE).
