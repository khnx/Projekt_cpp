#include <iostream>

#include "include/cDynamicArray.h"
#include "include/cPoint.h"
#include "include/cVector.h"

int main() {

  double a[] = {1, 22, 45};
  double b[] = {11, 5, 39};

  cPoint<double> p1(a, sizeof(a) / sizeof(double));
  cPoint<double> p2(b, sizeof(b) / sizeof(double));

  cDynamicArray<double> darr;
  darr.fill(2.3, 3);
  darr.push(5, 1);

  cVector<double> v1(p1, p2);
  std::cout << "v1: " << v1 << "\n";

  return 0;
}
