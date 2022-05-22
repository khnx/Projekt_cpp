#ifndef CLASS_CVECTOR
#define CLASS_CVECTOR 1

#include <cmath>
#include <iostream>

#include "cDynamicArray.h"
#include "cPoint.h"

// -------------------- CLASS --------------------

template <class T> class cVector {
private:
  cDynamicArray<T> vec; // Free vector.
  cPoint<T> origin;     // Starting point.

public:
  // Constructors.
  cVector(const cDynamicArray<T> &);
  cVector(const cDynamicArray<T> &, const cPoint<T> &);
  cVector(const cPoint<T> &, const cPoint<T> &);

  // Get/set.
  const cDynamicArray<T> get_vec() const;
  const bool set_vec(const cDynamicArray<T> &);
  const cPoint<T> get_origin() const;
  const bool set_origin(const cPoint<T> &);

  // Operators.
  const cVector<T> operator+(const cVector &) const;
  const cVector<T> operator-(const cVector &) const;
  const cVector<T> operator=(const cVector &);
  const cVector<T> operator*(const T) const;

  // Other.
  const T norm() const;
  const T abs() const;
  const cVector<T> opposite() const;
  const cVector<T> translate(const cVector<T> &);
  const T dot_product(const cVector<T> &, const T) const;
  const T cross_product_theta(const cVector<T> &, const T) const;
  const cVector<T> cross_product(const cVector<T> &) const;

  // Friends.
  friend cVector<T> operator*(T scalar, cVector<T> &v) {

    cVector temp(v.vec);
    temp.vec.fill(0, v.vec.size());

    for (size_t i = 0; i < v.vec.size(); i++) {
      temp.vec.push(v.vec[i] * scalar, i);
    }
    return temp;
  }

  friend std::ostream &operator<<(std::ostream &out, cVector<T> v) {

    std::cout << "(";
    for (size_t i = 0; i < v.vec.size(); i++) {
      std::cout << v.vec[i];
      if (i < v.vec.size() - 1)
        std::cout << ", ";
    }
    std::cout << ")";
    return std::cout;
  }
};

#include "../lib/cVector.tpp"

#endif