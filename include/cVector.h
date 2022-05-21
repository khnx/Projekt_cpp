#ifndef CLASS_CVECTOR
#define CLASS_CVECTOR

#include <cmath>
#include <iostream>

#include "cDynamicArray.h"
#include "cPoint.h"

template <class T> class cVector {
private:
  cDynamicArray<T> vec; // Free vector.
  cPoint<T> origin;     // Starting point.

public:
  // Constructors.
  cVector(cDynamicArray<T> &);
  cVector(cDynamicArray<T> &, cPoint<T> &);
  cVector(cPoint<T> &, cPoint<T> &);

  // Get/set.
  cDynamicArray<T> get_vec();
  bool set_vec(cDynamicArray<T> &);
  cPoint<T> get_origin();
  bool set_origin(cPoint<T> &);

  // Operators.
  cVector<T> operator+(cVector &);
  cVector<T> operator-(cVector &);
  cVector<T> operator=(cVector &);
  cVector<T> operator*(T);

  // Other.
  T norm();
  T abs();
  cVector<T> opposite();
  cVector<T> translate(cVector<T> &);
  T dot_product(cVector<T> &, T);
  T cross_product_theta(cVector<T> &, T);
  cVector<T> cross_product(cVector<T> &);

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

// -------------------- CONSTRUCTORS --------------------

template <typename T> cVector<T>::cVector(cDynamicArray<T> &darr) {
  this->vec = darr;

  cDynamicArray<T> temp;
  temp.fill(0, darr.size());
  cPoint<T> origin;
  this->origin = origin;
}

template <typename T>
cVector<T>::cVector(cDynamicArray<T> &darr, cPoint<T> &origin) {
  if (darr.size() != origin.get_coord().size()) {
    std::cerr
        << "Error: Invalid Size of Parameters Inside cVector's Constructor.\n";
    return;
  }

  this->vec = darr;
  this->origin = origin;
}

template <typename T>
cVector<T>::cVector(cPoint<T> &origin, cPoint<T> &ending) {
  if (origin.get_coord().size() != ending.get_coord().size()) {
    std::cerr
        << "Error: Incalid Size of Parameters Inside cVector's Constructor.\n";
    return;
  }

  cPoint<T> diff = ending - origin;

  this->vec = diff.get_coord();
  this->origin = origin;
}

// -------------------- GET/SET --------------------
template <typename T> cDynamicArray<T> cVector<T>::get_vec() {
  return this->vec;
}

template <typename T> cPoint<T> cVector<T>::get_origin() {
  return this->origin;
}

template <typename T> bool cVector<T>::set_vec(cDynamicArray<T> &vec) {
  if (vec.size() != this->vec.size()) {
    std::cerr << "Error: Invalid Size of Vector Inside set_vector().\n";
    return false;
  }

  this->vec = vec;
  return true;
}

template <typename T> bool cVector<T>::set_origin(cPoint<T> &origin) {
  if (origin.get_coord().size() != this->origin.get_coord().size()) {
    std::cerr << "Error: Invalid Size of cPoint Inside set_origin().\n";
    return false;
  }

  this->origin = origin;
  return true;
}

// -------------------- OPERATORS --------------------

template <typename T> cVector<T> cVector<T>::operator+(cVector<T> &v) {
  // Allow only addition of vectors of the same size.
  if (this->vec.size() != v.get_vec().size()) {
    std::cerr << "Error: Attempt to Add Vectors of Incompatible Sizes.\n";
    return *this;
  }

  cVector temp(this->vec);
  temp.vec.fill(0, this->vec.size());

  for (size_t i = 0; i < this->vec.size(); i++) {
    temp.vec.push(this->vec[i] + v.vec[i], i);
  }
  return temp;
}

template <typename T> cVector<T> cVector<T>::operator-(cVector<T> &v) {
  // Allow only addition of vectors of the same size.
  if (this->vec.size() != v.get_vec().size()) {
    std::cerr << "Error: Attempt to Add Vectors of Incompatible Sizes.\n";
    return *this;
  }

  cVector temp(this->vec);
  temp.vec.fill(0, this->vec.size());

  for (size_t i = 0; i < this->vec.size(); i++) {
    temp.vec.push(this->vec[i] - v.vec[i], i);
  }
  return temp;
}

template <typename T> cVector<T> cVector<T>::operator=(cVector<T> &v) {
  this->vec = v.vec;
  this->origin = v.origin;
  return *this;
}

template <typename T> cVector<T> cVector<T>::operator*(T scalar) {
  cVector temp(this->vec);
  temp.vec.fill(0, this->vec.size());

  for (size_t i = 0; i < this->vec.size(); i++) {
    temp.vec.push(this->vec[i] * scalar, i);
  }
  return temp;
}

// -------------------- OTHER --------------------

template <typename T> T cVector<T>::norm() {
  T norm = this->vec[0] * this->vec[0];
  // Start from 1, because of what above.
  for (size_t i = 1; i < this->vec.size(); i++) {
    norm += this->vec[i] * this->vec[i];
  }

  return norm;
}

template <typename T> T cVector<T>::abs() { return sqrt((*this).norm()); }

template <typename T> cVector<T> cVector<T>::opposite() {
  cVector temp(this->vec);
  for (size_t i = 0; i < this->vec.size(); i++) {
    temp.vec.push(this->vec[i] * -1, i);
  }
  return temp;
}

template <typename T> cVector<T> cVector<T>::translate(cVector<T> &v) {
  if (this->vec.size() != v.vec.size()) {
    std::cerr << "Error: Invalid Dimiensions of Vectors in translate().\n";
    return *this;
  }
  cDynamicArray<T> temp(this->origin.get_coord());
  for (size_t i = 0; i < this->vec.size(); i++) {
    temp.push(temp[i] + v.vec[i], i);
  }
  this->origin.set_coord(temp);
  return *this;
}

template <typename T> T cVector<T>::dot_product(cVector<T> &v, T theta) {
  T temp = (*this).abs() * v.abs() * cos(theta);
  return temp;
}

template <typename T>
T cVector<T>::cross_product_theta(cVector<T> &v, T theta) {
  T temp = (*this).abs() * v.abs() * sin(theta);
  return temp;
}

template <typename T> cVector<T> cVector<T>::cross_product(cVector<T> &v) {
  if (this->vec.size() != v.vec.size()) {
    std::cerr << "Error: Invalid Dimensions of Vectors in cross_product().\n";
    return *this;
  }
  if (this->vec.size() != 3) {
    std::cerr
        << "Error: Cross Product May Be Calculated for 3D Vectors Only.\n";
    return *this;
  }
  cVector<T> temp(*this);
  T minor1 = this->vec[1] * v.vec[2] - this->vec[2] * v.vec[1];
  T minor2 = this->vec[2] * v.vec[0] - this->vec[0] * v.vec[2];
  T minor3 = this->vec[0] * v.vec[1] - this->vec[1] * v.vec[0];
  temp.vec.push(minor1, 0);
  temp.vec.push(minor2, 1);
  temp.vec.push(minor3, 2);

  return temp;
}

#endif