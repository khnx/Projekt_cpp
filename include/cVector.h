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

  // Printing.
  friend std::ostream &operator<<(std::ostream &out, cVector<T> &v) {

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

#endif