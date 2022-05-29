#ifndef CLASS_CVECTOR
#define CLASS_CVECTOR 1

#include <cmath>
#include <iostream>

#include "cDynamicArray.h"
#include "cExceptions.h"
#include "cPoint.h"

// -------------------- CLASS --------------------

template <class T> class cVector {
private:
  cDynamicArray<T> vec; // Free vector.
  cPoint<T> origin;     // Starting point.

public:
  // Constructors.
  cVector(const std::initializer_list<T>);
  cVector(const cDynamicArray<T> &);
  cVector(const std::initializer_list<T>, const std::initializer_list<T>);
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
  const double norm() const;
  const double abs() const;
  const cVector<T> opposite() const;
  const cVector<T> translate(const cVector<T> &);
  const double dot_product(const cVector<T> &, const T) const;
  const double cross_product_theta(const cVector<T> &, const T) const;
  const cVector<T> cross_product(const cVector<T> &) const;

  // Friends.
  template <typename U>
  friend const cVector<U> operator*(const U, const cVector<U> &);

  template <typename U>
  friend std::ostream &operator<<(std::ostream &, const cVector<U> &);
};

// -------------------- FRIENDS --------------------

template <typename T>
const cVector<T> operator*(const T scalar, const cVector<T> &v) {

  cVector temp(v.vec);
  temp.vec.fill(0, v.vec.size());

  for (size_t i = 0; i < v.vec.size(); i++) {
    temp.vec.push(v.vec[i] * scalar, i);
  }
  return temp;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const cVector<T> &v) {

  std::cout << "vec: (";
  for (size_t i = 0; i < v.vec.size(); i++) {
    std::cout << v.vec[i];
    if (i < v.vec.size() - 1)
      std::cout << ", ";
  }
  std::cout << ")";
  std::cout << " origin: {";
  for (size_t i = 0; i < v.origin.get_coord().size(); i++) {
    std::cout << v.origin.get_coord()[i];
    if (i < v.origin.get_coord().size() - 1)
      std::cout << ", ";
  }
  std::cout << "}";
  return std::cout;
}

#endif