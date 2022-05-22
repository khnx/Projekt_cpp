// -------------------- CONSTRUCTORS --------------------

template <typename T> cVector<T>::cVector(const cDynamicArray<T> &darr) {
  this->vec = darr;

  cDynamicArray<T> temp;
  temp.fill(0, darr.size());
  cPoint<T> origin;
  this->origin = origin;
}

template <typename T>
cVector<T>::cVector(const cDynamicArray<T> &darr, const cPoint<T> &origin) {
  if (darr.size() != origin.get_coord().size()) {
    std::cerr
        << "Error: Invalid Size of Parameters Inside cVector's Constructor.\n";
    return;
  }

  this->vec = darr;
  this->origin = origin;
}

template <typename T>
cVector<T>::cVector(const cPoint<T> &origin, const cPoint<T> &ending) {
  if (origin.get_coord().size() != ending.get_coord().size()) {
    std::cerr
        << "Error: Incalid Size of Parameters Inside cVector's Constructor.\n";
    return;
  }

  cPoint<T> diff = ending - origin;

  cDynamicArray<T> diff_vec_cp(diff.get_coord());
  this->vec = diff_vec_cp;
  this->origin = origin;
}

// -------------------- GET/SET --------------------
template <typename T> const cDynamicArray<T> cVector<T>::get_vec() const {
  return this->vec;
}

template <typename T> const cPoint<T> cVector<T>::get_origin() const {
  return this->origin;
}

template <typename T>
const bool cVector<T>::set_vec(const cDynamicArray<T> &vec) {
  if (vec.size() != this->vec.size()) {
    std::cerr << "Error: Invalid Size of Vector Inside set_vector().\n";
    return false;
  }

  this->vec = vec;
  return true;
}

template <typename T>
const bool cVector<T>::set_origin(const cPoint<T> &origin) {
  if (origin.get_coord().size() != this->origin.get_coord().size()) {
    std::cerr << "Error: Invalid Size of cPoint Inside set_origin().\n";
    return false;
  }

  this->origin = origin;
  return true;
}

// -------------------- OPERATORS --------------------

template <typename T>
const cVector<T> cVector<T>::operator+(const cVector<T> &v) const {
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

template <typename T>
const cVector<T> cVector<T>::operator-(const cVector<T> &v) const {
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

template <typename T>
const cVector<T> cVector<T>::operator=(const cVector<T> &v) {
  this->vec = v.vec;
  this->origin = v.origin;
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

template <typename T> T const cVector<T>::norm() const {
  T norm = this->vec[0] * this->vec[0];
  // Start from 1, because of what above.
  for (size_t i = 1; i < this->vec.size(); i++) {
    norm += this->vec[i] * this->vec[i];
  }

  return norm;
}

template <typename T> const T cVector<T>::abs() const {
  return sqrt((*this).norm());
}

template <typename T> const cVector<T> cVector<T>::opposite() const {
  cVector temp(this->vec);
  for (size_t i = 0; i < this->vec.size(); i++) {
    temp.vec.push(this->vec[i] * -1, i);
  }
  return temp;
}

template <typename T>
const cVector<T> cVector<T>::translate(const cVector<T> &v) {
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

template <typename T>
const T cVector<T>::dot_product(const cVector<T> &v, const T theta) const {
  T temp = (*this).abs() * v.abs() * cos(theta);
  return temp;
}

template <typename T>
const T cVector<T>::cross_product_theta(const cVector<T> &v,
                                        const T theta) const {
  T temp = (*this).abs() * v.abs() * sin(theta);
  return temp;
}

template <typename T>
const cVector<T> cVector<T>::cross_product(const cVector<T> &v) const {
  if (this->vec.size() != v.vec.size()) {
    std::cerr << "\nError: Invalid Dimensions of Vectors in cross_product().\n";
    cVector<T> temp(*this);
    temp.vec.fill(0, this->vec.size());
    return *this;
  }
  if (this->vec.size() != 3) {
    cVector<T> temp(*this);
    temp.vec.fill(0, this->vec.size());
    std::cerr
        << "\nError: Cross Product May Be Calculated for 3D Vectors Only.\n";
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
