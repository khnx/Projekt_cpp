#ifndef CLASS_CPOINT
#define CLASS_CPOINT

#include <iostream>

#include "cDynamicArray.h"

template <class T> class cPoint {
private:
  cDynamicArray<T> coord;

public:
  // Constructors.
  cPoint();
  cPoint(T[], size_t);
  cPoint(cDynamicArray<T>);

  // Operators.
  cPoint<T> operator+(cPoint<T> &);
  cPoint<T> operator-(cPoint<T> &);
  cPoint<T> operator=(cPoint<T> &);

  // Get/set.
  cDynamicArray<T> get_coord();
  bool set_coord(cDynamicArray<T> &);

  // Printing.
  friend std::ostream &operator<<(std::ostream &out, cPoint<T> pt) {
    std::cout << "(";
    for (size_t i = 0; i < pt.coord.size(); i++) {
      std::cout << pt.coord[i];
      if (i < pt.coord.size() - 1)
        std::cout << ", ";
    }
    std::cout << ")";
    return std::cout;
  }
};

// -------------------- CONSTRUCTORS --------------------

template <typename T> cPoint<T>::cPoint() {
  cDynamicArray<T> temp;
  this->coord = temp;
}

template <typename T> cPoint<T>::cPoint(T arr[], size_t siz) {
  cDynamicArray<T> temp(arr, siz);
  this->coord = temp;
}

template <typename T> cPoint<T>::cPoint(cDynamicArray<T> darr) {
  this->coord = darr;
}

// -------------------- OPERATORS --------------------

template <typename T> cPoint<T> cPoint<T>::operator+(cPoint<T> &pt) {
  if (this->coord.size() != pt.coord.size()) {
    std::cerr << "Error: Invalid cPoint Dimensions.";
    return *this;
  }

  cPoint<T> temp;
  temp.coord.fill(0, this->coord.size());

  for (size_t i = 0; i < this->coord.size(); i++) {
    temp.coord.push(this->coord[i] + pt.coord[i], i);
  }
  return temp;
}

template <typename T> cPoint<T> cPoint<T>::operator-(cPoint<T> &pt) {
  if (this->coord.size() != pt.coord.size()) {
    std::cerr << "Error: Invalid cPoint Dimensions.";
    return *this;
  }

  cPoint<T> temp;
  temp.coord.fill(0, this->coord.size());

  for (size_t i = 0; i < this->coord.size(); i++) {
    temp.coord.push(this->coord[i] - pt.coord[i], i);
  }
  return temp;
}

template <typename T> cPoint<T> cPoint<T>::operator=(cPoint<T> &pt) {
  this->coord = pt.coord;
  return *this;
}

// -------------------- GET/SET --------------------

template <typename T> cDynamicArray<T> cPoint<T>::get_coord() {
  return this->coord;
}

template <typename T> bool cPoint<T>::set_coord(cDynamicArray<T> &coord) {
  if (this->coord.size() != coord.size()) {
    std::cerr << "Error: Invalid cPoints Size. Returning Initial cPoint.\n";
    return false;
  }
  this->coord = coord;
  return true;
}

#endif