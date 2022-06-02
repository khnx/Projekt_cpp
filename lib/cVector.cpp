#include "cVector.h"

// -------------------- CONSTRUCTORS --------------------

template <typename T> cVector<T>::cVector(const std::initializer_list<T> init) {
  cDynamicArray<T> temp_vec(init);
  this->vec = temp_vec;
}

template <typename T> cVector<T>::cVector(const cDynamicArray<T> &darr) {
  this->vec = darr;
}

template <typename T>
cVector<T>::cVector(const std::initializer_list<T> init1,
                    const std::initializer_list<T> init2) {
  if (init1.size() != init2.size()) {
    throw cExceptions(
        "Error: Invalid Size of Parameters Inside cVector's Constructor.");
  }

  cPoint<T> pt1(init1);
  cPoint<T> pt2(init2);
  cPoint<T> diff = pt2 - pt1;
  this->vec = diff.get_coord();
}

template <typename T>
cVector<T>::cVector(const cPoint<T> &origin, const cPoint<T> &ending) {
  if (origin.get_coord().size() != ending.get_coord().size()) {
    throw cExceptions(
        "Error: Invalid Size of Parameters Inside cVector's Constructor.");
  }
  cPoint<T> diff = ending - origin;
  this->vec = diff.get_coord();
}

// -------------------- GET/SET --------------------
template <typename T> const cDynamicArray<T> cVector<T>::get_vec() const {
  return this->vec;
}

template <typename T>
const bool cVector<T>::set_vec(const cDynamicArray<T> &vec) {
  if (vec.size() != this->vec.size()) {
    throw cExceptions("Error: Invalid Size of Vector Inside set_vector().");
  }

  this->vec = vec;
  return true;
}

// -------------------- OPERATORS --------------------

template <typename T>
const cVector<T> cVector<T>::operator+(const cVector<T> &v) const {
  // Allow only addition of vectors of the same size.
  if (this->vec.size() != v.get_vec().size()) {
    throw cExceptions("Error: Attempted to Add Vectors of Incompatible Sizes.");
  }

  cVector temp(this->vec);
  temp.vec.fill(0, this->vec.size());

  for (size_t i = 0; i < this->vec.size(); i++) {
    temp.vec.push(this->vec[i] + v.vec[i], i);
  }
  return temp;
}

template <typename T>
const cVector<T> cVector<T>::operator-(const cVector<T> &v) const {
  // Allow only substraction of vectors of the same size.
  if (this->vec.size() != v.get_vec().size()) {
    throw cExceptions(
        "Error: Attempted to Substract Vectors of Incompatible Sizes.");
  }

  cVector temp(this->vec);
  temp.vec.fill(0, this->vec.size());

  for (size_t i = 0; i < this->vec.size(); i++) {
    temp.vec.push(this->vec[i] - v.vec[i], i);
  }
  return temp;
}

template <typename T>
const cVector<T> cVector<T>::operator=(const cVector<T> &v) {
  // Allow only assignment of vectors of the same size.
  if (this->vec.size() != v.get_vec().size()) {
    throw cExceptions(
        "Error: Attempted to Assign to Vector of an Incompatible Size.");
  }
  this->vec = v.vec;
  return *this;
}

template <typename T>
const cVector<T> cVector<T>::operator*(const T scalar) const {
  cVector temp(this->vec);
  temp.vec.fill(0, this->vec.size());

  for (size_t i = 0; i < this->vec.size(); i++) {
    temp.vec.push(this->vec[i] * scalar, i);
  }
  return temp;
}

// -------------------- OTHER --------------------

template <typename T> const double cVector<T>::norm() const {
  double norm = this->vec[0] * this->vec[0];
  // Start from 1, because of what above.
  for (size_t i = 1; i < this->vec.size(); i++) {
    norm += this->vec[i] * this->vec[i];
  }

  return norm;
}

template <typename T> const double cVector<T>::abs() const {
  return sqrt((*this).norm());
}

template <typename T> const cVector<T> cVector<T>::opposite() const {
  cVector temp(this->vec);
  for (size_t i = 0; i < this->vec.size(); i++) {
    temp.vec.push(this->vec[i] * (-1), i);
  }
  return temp;
}

template <typename T>
const double cVector<T>::dot_product(const cVector<T> &v, const T theta) const {
  return (*this).abs() * v.abs() * cos(theta);
}

template <typename T>
const double cVector<T>::cross_product_theta(const cVector<T> &v,
                                             const T theta) const {
  if (this->vec.size() != v.vec.size()) {
    throw cExceptions(
        "Error: Invalid Dimensions of Vectors in cross_product_theta().");
  }
  return (*this).abs() * v.abs() * sin(theta);
}

template <typename T>
const cVector<T> cVector<T>::cross_product(const cVector<T> &v) const {
  if (this->vec.size() != v.vec.size()) {
    throw cExceptions(
        "Error: Invalid Dimensions of Vectors in cross_product().");
  } else if (this->vec.size() != 3) {
    throw cExceptions(
        "Error: Cross Product May Be Calculated for 3D Vectors Only.");
  }

  cVector<T> temp(*this);
  T minor1 = this->vec[1] * v.vec[2] - v.vec[1] * this->vec[2];
  T minor2 = this->vec[2] * v.vec[0] - this->vec[0] * v.vec[2];
  T minor3 = this->vec[0] * v.vec[1] - this->vec[1] * v.vec[0];
  temp.vec.push(minor1, 0);
  temp.vec.push(minor2, 1);
  temp.vec.push(minor3, 2);
  return temp;
}

// -------------------- TYPES --------------------

template class cVector<int>;
template class cVector<long>;
template class cVector<long long>;
template class cVector<float>;
template class cVector<double>;