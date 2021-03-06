#ifndef CLASS_DYNAMIC_ARRAY
#define CLASS_DYNAMIC_ARRAY 1

#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "cExceptions.h"

// -------------------- CLASS --------------------

template <class T> class cDynamicArray {
private:
  T *p;       // Address of the array.
  size_t cap; // Total capacity of the array.
  size_t siz; // Number of elements present in the array.

public:
  // Constructors.
  cDynamicArray();                         // Empty.
  cDynamicArray(std::initializer_list<T>); // Init with object {}.
  cDynamicArray(const T[], const size_t);  // Init with array.
  cDynamicArray(const cDynamicArray<T> &); // Init with cDynamicArray.

  // Operators.
  const T operator[](const size_t) const;
  const cDynamicArray<T> operator=(const cDynamicArray<T> &);

  // Other.
  void push(const T);
  void push(const T, const size_t);
  void pop();
  void fill(const T, const size_t);
  const size_t size() const;
  const size_t get_cap() const;

  // Friends.
  friend std::ostream &operator<<(std::ostream &out,
                                  const cDynamicArray<T> &arr) {

    std::cout << "[";
    for (size_t i = 0; i < arr.siz; i++) {
      std::cout << arr.p[i];
      if (i < arr.siz - 1) {
        std::cout << ", ";
      }
    }
    std::cout << "]";

    return std::cout;
  }
}; // --- cDynamicArray

#include "../lib/cDynamicArray.tpp"

#endif