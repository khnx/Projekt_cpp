#include <complex>
#include <iostream>
#include <stdexcept>

#include "include/cVector.h"

int main() {

  // Example use.
  try {
    cVector<int> v1({1, 2, 3, 6, 7, 1});
    cVector<int> v2({4, 5, 6, 7, 3, 1});
    std::cout << "v1:\n\t" << v1 << "\n";
    std::cout << "v2:\n\t" << v2 << "\n";
    std::cout << "v2.norm():\n\t" << v2.norm() << "\n";
    std::cout << "v2.abs():\n\t" << v2.abs() << "\n";
    std::cout << "v2.opposite():\n\t" << v2.opposite() << "\n";
    std::cout << "v2.translate(v1):\n\t" << v2.translate(v1) << "\n";
    std::cout << "v2.dot_product(v1, pi/6):\n\t" << v2.dot_product(v1, M_PI / 3)
              << "\n";
    std::cout << "v2.cross_product_theta(v1, 5/6*pi):\n\t"
              << v2.cross_product_theta(v1, M_PI / 3) << "\n";
    std::cout << "v2.cross_product(v1):\n\t" << v2.cross_product(v1) << "\n";
  } catch (const cExceptions &e) {
    std::cerr << e.what() << "\n";
  }

  return 0;
}
