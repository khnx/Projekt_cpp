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
  darr.fill(2.3, 3);
  darr.push(5, 1);

  cVector<double> v1(p1, p2);
  cVector<double> v2(darr);

  std::cout << "v1: " << v1 << "\n";
  std::cout << "v2: " << v2 << "\n";
  std::cout << "v1.cross_product(): " << v1.cross_product(v2) << "\n";

  const std::complex<double> z1(2, 4);
  const std::complex<double> z2(-1, 2);
  const std::complex<double> z3(2.1, 7);
  const std::complex<double> z4(3.1, 7.5);
  const std::complex<double> z5(-3.2, 3.5);
  const std::complex<double> z6(-2.7, 4);
  const std::complex<double> z7(7.3, 5.4);
  const std::complex<double> z8(-2.9, -4.5);

  const std::complex<double> az1[] = {z1, z2};
  const std::complex<double> az2[] = {z3, z4};
  const std::complex<double> az3[] = {z5, z6};
  const std::complex<double> az4[] = {z7, z8};

  cPoint<std::complex<double>> pz1(az1,
                                   sizeof(az1) / sizeof(std::complex<double>));
  cPoint<std::complex<double>> pz2(az2,
                                   sizeof(az2) / sizeof(std::complex<double>));
  cPoint<std::complex<double>> pz3(az3,
                                   sizeof(az3) / sizeof(std::complex<double>));
  cPoint<std::complex<double>> pz4(az4,
                                   sizeof(az4) / sizeof(std::complex<double>));

  std::cout << "pz1: " << pz1 << "\n";
  std::cout << "pz1: " << pz2 << "\n";
  std::cout << "pz1: " << pz3 << "\n";
  std::cout << "pz1: " << pz4 << "\n";

  cVector<std::complex<double>> vz1(pz1, pz2);
  cVector<std::complex<double>> vz2(pz3, pz4);

  std::cout << "vz1: " << vz1 << "\n";
  std::cout << "vz2: " << vz2 << "\n";

  std::cout << "vz1 + vz2" << vz1 + vz2 << "\n";
  std::cout << "vz1 - vz2" << vz1 - vz2 << "\n";
  std::cout << "vz1 * z1" << vz1 * z2 << "\n";
  std::cout << "vz1.dot_product(vz2, pi/2)" << vz1.dot_product(vz2, M_PI_2f64)
            << "\n";
  std::cout << "vz1.cross_product_theta(vz2, pi/2)"
            << vz1.cross_product_theta(vz2, M_PI_2f64) << "\n";
  std::cout << "vz1.cross_product(vz2, pi/2)" << vz1.cross_product(vz2) << "\n";
  return 0;
}
