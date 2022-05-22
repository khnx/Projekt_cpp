#ifndef CLASS_CPOINT
#define CLASS_CPOINT 1

#include <iostream>

#include "cDynamicArray.h"

// -------------------- CLASS --------------------

template <class T> class cPoint {
private:
  cDynamicArray<T> coord;

public:
  // Constructors.
  cPoint();
  cPoint(const T[], const size_t);
  cPoint(cDynamicArray<T>);

  // Operators.
  const cPoint<T> operator+(const cPoint<T> &) const;
  const cPoint<T> operator-(const cPoint<T> &) const;
  const cPoint<T> operator=(const cPoint<T> &);

  // Get/set.
  const cDynamicArray<T> get_coord() const;
  const bool set_coord(const cDynamicArray<T> &);

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

#include "../lib/cPoint.tpp"

#endif