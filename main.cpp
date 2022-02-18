#include <iostream>
#include "array.hpp"

int main() {
  
  std::cout << "Create two empty arrays: \n";
  
  Array a1(3); // Array of length 3 filled with zeroes
  Array a2(3); // Array of length 3 filled with zeroes

  std::cout << "Array 1: ";
  a1.print(); // [0, 0, 0]
  std::cout << "Array 2: ";
  a2.print(); // [0, 0, 0]

  double data1[3] = {1.0, 2.1, 3.6}; // Data for array 1
  double data2[3] = {-2.0, 3.0, 5.2}; // Data for array 2

  for(unsigned i = 0; i < a1.size(); i++) { // Insert data into arrays
    a1.data()[i] = data1[i];
    a2.data()[i] = data2[i];
  }
  
  std::cout << "\nPrint arrays that are filled with data \n";
  std::cout << "Array 1: ";
  a1.print();   // [1, 2, 3]
  std::cout << "Array 2: ";
  a2.print();   // [-2, 3, 5]

  std::cout << "\nShow norms: \n";
  double norm1 = a1.norm();
  double norm2 = a2.norm();
  std::cout << "Norm of array 1: " << norm1 << "\nNorm of array 2: "
	    << norm2 << std::endl;

  std::cout << "\nShow dot product: \n";
  double dot = a1.dot(a2);
  std::cout << "Dot product of the arrays: " << dot << std::endl;

  Array a_sum = a1 + a2;  // Overloaded assignment operator
  Array a_diff = a1 - a2;  // Overloaded assignment operator
  
  std::cout << "\nAdd the arrays with overloaded binary operator: \n";
  std::cout << "Sum of array 1 and array 2 is: ";
  a_sum.print();

  std::cout << "\nSubtract the arrays with overloaded binary operator: \n";
  std::cout << "Difference of array 1 and array 2 is: ";
  a_diff.print();

  std::cout << "\nPresent value at certain index: \n";
  std::cout << "Value at second index of array 1: " << a1.at(1) << std::endl;

  std::cout << "\nPresent max and min values in array 2: \n";
  std::cout << "Max value in array 2: " << a2.max() << std::endl
	    << "Min value in array 2: " << a2.min() << std::endl;

  std::cout << "\nPresent sum of array 1 elements: " << a1.sum();

  std::cout << "\nPresent overloaded accessing operator: \n";
  double val2 = a1[1];
  std::cout << "Second value of array 1: " << val2 << std::endl;

  std::cout << "\nPresent copying of array2 to array1: \n";
  a1.copy(a2);
  std::cout << "New array 1 is: ";
  a1.print();

  std::cout << "\nPresent resizing of array 1: ";
  a1.resize(5);
  std::cout << "New size of array 1 after resizing: " << a1.size() << std::endl
	    << "New array preserves old values by default: \n";
  a1.print();
  std::cout << "Sizing down truncates: \n";
  a1.resize(2);
  std::cout << "New size of array 1 after resizing again: " << a1.size() << std::endl;
  a1.print();
  

  return 0;
};
