#include <iostream>

#include "include/cDynamicArray.h"
#include "include/cPoint.h"
#include "include/cVector.h"

int main() {

  double a[] = {1, 22, 45};
  double b[] = {11, 5, 39};
  double c[] = {-1, 6, 5};
  double d[] = {7, 95, 9};

  cPoint<double> p1(a, sizeof(a) / sizeof(double));
  cPoint<double> p2(b, sizeof(b) / sizeof(double));
  cPoint<double> p3(c, sizeof(c) / sizeof(double));
  cPoint<double> p4(d, sizeof(d) / sizeof(double));

  cDynamicArray<double> darr;
  darr.fill(2.3, 3);
  darr.push(5, 1);

  cVector<double> v1(p1, p2);
  cVector<double> v2(darr);

  std::cout << "v1: " << v1 << "\n";
  std::cout << "v2: " << v2 << "\n";
  std::cout << "v1.cross_product(): " << v1.cross_product(v2) << "\n";

  return 0;
}
