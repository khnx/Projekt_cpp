#include <complex>
#include <iostream>
#include <stdexcept>

#include "include/cVector.h"

int main() {

  // Example.
  try {

    int arr[] = {7, 8, 9};
    cDynamicArray<int> darr({1, 2, 3});
    cPoint<int> pt({1, 2, 3});
    cPoint<int> pt02({4, 5, 6});

    std::cout << "arr:\n\t{";
    for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++) {
      std::cout << arr[i];
      if (i != sizeof(arr) / sizeof(int) - 1) {
        std::cout << ", ";
      }
    }
    std::cout << "}\n";
    std::cout << "darr:\n\t" << darr << "\n";
    std::cout << "pt:\n\t" << pt << "\n";

#ifdef DARR
    // -------------------- cDynamicArray --------------------
    std::cout << "-------------------- cDynamicArray --------------------\n";

    // Constructors.
    cDynamicArray<int> darr1;
    cDynamicArray<int> darr2({1, 2, 3});
    cDynamicArray<int> darr3(arr, sizeof(arr) / sizeof(int));
    cDynamicArray<int> darr4(darr2);
    std::cout << "darr1:\n\t" << darr1 << "\n";
    std::cout << "darr2:\n\t" << darr2 << "\n";
    std::cout << "darr3:\n\t" << darr3 << "\n";
    std::cout << "darr4:\n\t" << darr4 << "\n";

    // Operators.
    std::cout << "darr[1]:\n\t" << darr2[1] << "\n";
    std::cout << "darr2:\n\t" << darr2 << "\n";
    std::cout << "darr2 = darr3\n\t" << (darr2 = darr3) << "\n";
    std::cout << "darr3:\n\t" << darr3 << "\n";

    // Other.
    darr1.push(0);
    std::cout << "darr1.push(0):\n\t" << darr1 << "\n";
    darr1.push(0, 1);
    std::cout << "darr1.push(0, 1):\n\t" << darr1 << "\n";
    darr1.pop();
    std::cout << "darr1.pop():\n\t" << darr1 << "\n";
    darr1.fill(1, 5);
    std::cout << "darr1.fill(1, 5):\n\t" << darr1 << "\n";
    std::cout << "darr1.size():\n\t" << darr1.size() << "\n";
    std::cout << "darr1.get_cap():\n\t" << darr1.get_cap() << "\n";

    std::cout << "----------------------------------------\n";

#endif // -- DARR
#ifdef PT

    // -------------------- cPoint --------------------
    std::cout << "-------------------- cPoint --------------------\n";
    // Constructors.
    cPoint<int> pt1;
    cPoint<int> pt2({1, 2, 3});
    cPoint<int> pt3(arr, sizeof(arr) / sizeof(int));
    cPoint<int> pt4(darr);
    std::cout << "pt1" << pt1 << "\n";
    std::cout << "pt2" << pt2 << "\n";
    std::cout << "pt3" << pt3 << "\n";
    std::cout << "pt4" << pt4 << "\n";

    // Operators.
    std::cout << "pt2 + pt3:\n\t" << pt2 + pt3 << "\n";
    std::cout << "pt2 - pt3:\n\t" << pt2 - pt3 << "\n";
    std::cout << "pt1 = pt2:\n\t" << (pt1 = pt2) << "\n";

    // Get/set.
    std::cout << "pt1.get_coord():\n\t" << pt3.get_coord() << "\n";
    pt3.set_coord(darr);
    std::cout << "pt1.set_coord(darr):\n\t" << pt3 << "\n";

    std::cout << "----------------------------------------\n";

#endif // -- PT
#define VEC
#ifdef VEC
    // -------------------- cVector --------------------
    std::cout << "-------------------- cVector --------------------\n";

    // Constructors.
    std::cout << "Constructors.\n";
    cVector<int> v1({1, 2, 3});
    cVector<int> v2(darr);
    cVector<int> v3({1, 2, 3}, {4, 5, 6});
    cVector<int> v4(pt, pt02);
    std::cout << "v1:\n\t" << v1 << "\n";
    std::cout << "v2:\n\t" << v2 << "\n";
    std::cout << "v3:\n\t" << v3 << "\n";
    std::cout << "v5:\n\t" << v4 << "\n";

    // Get/set.
    std::cout << "Get/set.\n";
    std::cout << "v1.get_vec():\n\t" << v1.get_vec() << "\n";
    v1.set_vec(darr);
    std::cout << "v1.set_vec(darr):\n\t" << v1.get_vec() << "\n";

    // Operators.
    std::cout << "Operators.\n";
    std::cout << "v1 + v2:\n\t" << v1 + v2 << "\n";
    std::cout << "v1 - v2:\n\t" << v1 - v2 << "\n";
    std::cout << "v1 = v2:\n\t" << (v1 = v2) << "\n";
    std::cout << "v1 * 5:\n\t" << v1 * 5 << "\n";
    std::cout << "7 * v1:\n\t" << 7 * v1 << "\n";

    // Other.
    std::cout << "Other.\n";
    std::cout << "v2.norm():\n\t" << v2.norm() << "\n";
    std::cout << "v2.abs():\n\t" << v2.abs() << "\n";
    std::cout << "v2.opposite():\n\t" << v2.opposite() << "\n";
    std::cout << "translate_pt(pt, v1):\n\t" << translate_pt(pt, v1) << "\n";
    std::cout << "v2.dot_product(v1, pi/6):\n\t" << v2.dot_product(v1, M_PI / 3)
              << "\n";
    std::cout << "v2.cross_product_theta(v1, 5/6*pi):\n\t"
              << v2.cross_product_theta(v1, M_PI / 3) << "\n";
    std::cout << "v2.cross_product(v1):\n\t" << v2.cross_product(v1) << "\n";

    std::cout << "----------------------------------------\n";

#endif // -- VEC
  } catch (const cExceptions &e) {
    std::cerr << e.what() << "\n";
  }

  return 0;
}
