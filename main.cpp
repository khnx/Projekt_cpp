#include <complex>
#include <iostream>

#include <vector>

#include "include/cDynamicArray.h"
#include "include/cPoint.h"
#include "include/cVector.h"

int main() {

  const double a[] = {1, 22, 45};
  const double b[] = {11, 5, 39};
  const double c[] = {-1, 6, 5};
  const double d[] = {7, 95, 9};

  cPoint<double> p1(a, sizeof(a) / sizeof(double));
  cPoint<double> p2(b, sizeof(b) / sizeof(double));
  cPoint<double> p3(c, sizeof(c) / sizeof(double));
  cPoint<double> p4(d, sizeof(d) / sizeof(double));

  cDynamicArray<double> darr;
  darr.fill(2.3, 2);
  darr.push(5, 1);

  cVector<double> v1(p1, p2);
  cVector<double> v2(darr);

  std::cout << "v1: " << v1 << "\n";
  std::cout << "v2: " << v2 << "\n";
  std::cout << "v1.cross_product(v2): " << v1.cross_product_theta(v2, M_PI_2)
            << "\n";
  std::cout << "v1: " << v1 << "\n";
  std::cout << "v2: " << v2 << "\n";
  std::cout << "22 * v1: " << 22 * v1 << "\n";

  return 0;
}
