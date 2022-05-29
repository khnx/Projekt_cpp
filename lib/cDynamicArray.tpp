// -------------------- CONSTRUCTORS --------------------

template <typename T> cDynamicArray<T>::cDynamicArray() {
  this->p = new T[1];
  this->cap = 1;
  this->siz = 0;
}

template <typename T>
cDynamicArray<T>::cDynamicArray(std::initializer_list<T> init) {
  this->p = new T[1];
  this->cap = 1;
  this->siz = 0;

  for (size_t i = 0; i < init.size(); i++) {
    this->push(*(init.begin() + i));
  }
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
    throw cExceptions("Error: Array Index Out of Bounds.");
  } else {
    return this->p[index];
  }
}

template <typename T>
cDynamicArray<T> const
cDynamicArray<T>::operator=(const cDynamicArray<T> &darr) {
  // Ditch old p[].
  delete[] p;
  // Make new p[] and populate it with darr values.
  this->p = new T[1];
  this->cap = 1;
  this->siz = 0;
  for (size_t i = 0; i < darr.siz; i++) {
    this->push(darr.p[i]);
  }
  return *this;
}

// -------------------- OTHER --------------------

template <typename T> void cDynamicArray<T>::push(const T entry) {
  // No space left in the array. Allocate twice more space than current size.
  // Rewrite old values to the new array.
  if (this->siz == this->cap) {
    T *temp = new T[2 * this->cap];

    for (size_t i = 0; i < this->cap; i++) {
      temp[i] = this->p[i];
    }

    delete[] this->p; // Delete old p[].
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
