#ifndef CLASS_CDYNAMICARRAY
#define CLASS_CDYNAMICARRAY 1

#include <cstdlib>
#include <iostream>

// -------------------- CLASS --------------------

template <class T> class cDynamicArray {
private:
  T *p;       // Address of the array.
  size_t cap; // Total capacity of the array.
  size_t siz; // Number of elements present in the array.

public:
  // Constructors.
  cDynamicArray();
  cDynamicArray(const T[], const size_t);
  cDynamicArray(const cDynamicArray<T> &);

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

// -------------------- CONSTRUCTORS --------------------

template <typename T> cDynamicArray<T>::cDynamicArray() {
  this->p = new T[1];
  this->cap = 1;
  this->siz = 0;
}

template <typename T>
cDynamicArray<T>::cDynamicArray(const T init[], const size_t siz) {
  this->p = new T[1];
  this->cap = 1;
  this->siz = 0;

  for (size_t i = 0; i < siz; i++) {
    this->push(init[i]);
  }
}

template <typename T>
cDynamicArray<T>::cDynamicArray(const cDynamicArray<T> &darr) {
  this->p = new T[1];
  this->cap = 1;
  this->siz = 0;

  for (size_t i = 0; i < darr.siz; i++) {
    this->push(darr.p[i]);
  }
}

// -------------------- OPERATORS --------------------

template <typename T>
const T cDynamicArray<T>::operator[](const size_t index) const {
  if (index >= this->siz) {
    std::cerr << "Error: Array Index Out of Bounds. Exit Failure.\n";
    exit(EXIT_FAILURE);
  }
  return this->p[index];
}

template <typename T>
cDynamicArray<T> const
cDynamicArray<T>::operator=(const cDynamicArray<T> &arr) {
  for (size_t i = 0; i < arr.siz; i++) {
    if (this->siz == i) {
      (*this).push(arr[i]);
    } else {
      this->p[i] = arr[i];
    }
  }
  return *this;
}

// -------------------- OTHER --------------------

template <typename T> void cDynamicArray<T>::push(const T entry) {
  // No space left in the array. Allocate twice more than current size. Rewrite
  // old values to new array.
  if (this->siz == this->cap) {
    T *temp = new T[2 * this->cap];

    for (size_t i = 0; i < this->cap; i++) {
      temp[i] = this->p[i];
    }

    delete[] this->p;
    this->cap *= 2;
    this->p = temp;
  }

  // Append entry to the back.
  this->p[this->siz] = entry;
  siz++;
}

template <typename T>
void cDynamicArray<T>::push(const T entry, const size_t index) {
  if (index == this->cap) {
    push(entry);
  } else {
    this->p[index] = entry;
  }
}

template <typename T> void cDynamicArray<T>::pop() { this->siz--; }

template <typename T>
void cDynamicArray<T>::fill(const T value, const size_t siz) {
  for (size_t i = 0; i < siz; i++) {
    if (i == this->siz) {
      push(value);
    } else {
      this->p[i] = value;
    }
  }
}

template <typename T> const size_t cDynamicArray<T>::size() const {
  return this->siz;
}

template <typename T> const size_t cDynamicArray<T>::get_cap() const {
  return this->cap;
}

#endif