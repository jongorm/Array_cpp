#include <iostream>
#include <cmath>  
#include "array.hpp"


//////////////////CONSTRUCTORS & DESTRUCTORS/////////////////////

Array::Array() {                 // Empty array CONSTRUCTOR
  this->_size = 0;               // Initialize size as argument
  this->_data = new double [0];   // Allocate space for data array
}


Array::Array(const Array &other) {  // Copy CONSTRUCTOR
  this->_size = other._size;        // New object's (this) size equals other object's size
  for (unsigned i = 0; i < _size; i++){
    this->_data[i] = other._data[i]; // Copy each element of other into the new array
  }
}

Array::Array(unsigned n, double v) {  // Initialized array CONSTRUCTOR (explicit keyword only in declaration)
  this->_size = n;                          // Size intialized as n
  this->_data = new double [this->_size];   // Allocate array of size _size
  for (unsigned i = 0; i < this->_size; i++){    // Initialize array with 0.0 entries throughout
    _data[i] = v;
  } 
}

  
Array::~Array() {         // DESTRUCTOR
  delete [] _data; // De-allocate space upon destruction
}


///////////////////////MEMBER FUNCTIONS//////////////////////////


unsigned Array::size() const {  // Return type unsigned, which is a constant size value
  return this->_size;
}

double* Array::data() {   // Return type double, which is the data array pointer
  return this->_data;
}

const double* Array::data() const {  // Return constant (immutable) type double array pointer, which is a constant data array pointer
  return this->_data;
}

void Array::copy(const Array &rhs) {   // Copy (essentially a reassignment) an existing array (array1.copy(array2))
  if (this->_size == rhs._size) {      // Check if sizes are equal (use attribute instead of getter inside class)
    for (unsigned i = 0; i < _size; i++) {  // Copy entries iteratively
      this->_data[i] = rhs._data[i];   
    }
  }
}

double& Array::at(unsigned index) { // Obtain the element of array at a particular
  return this->_data[index];
}

const double& Array::at(unsigned index) const {
  return this->_data[index];
}

void Array::resize(unsigned new_size, bool prsv) {
  double *new_data;
  new_data = new double [new_size];
  //Array::Array tmp_array(this->_size);  // Temporary array to hold preserved data with the size of 'this'
  if (prsv) {                        // Conditional for preserving the old array
    unsigned min = this->_size;      // Initiliaze the minimum to _size
    if (new_size < this->_size) {    // If new_size is the actual min, reset min
      min = new_size;
    }
    for (unsigned i = 0; i < min; i++) {  // copy up to min
      new_data[i] = this->_data[i];
    }
  }
  delete [] this->_data;  // Free memory
  this->_data = new_data; // Copy pointer
  this->_size = new_size; // Change size
}

double Array::norm() const {  // Compute the norm of the array (vector)
  double sum = 0.0;
  for (unsigned i = 0; i < this->_size; i++) {
    sum += (this->_data[i])*(this->_data[i]);
  }
  return (std::sqrt(sum));
}

double Array::sum() const {  // Compute the sum of array elements
  double sum = 0.0;
  for (unsigned i = 0; i < this->_size; i++) {
    sum += this->_data[i];
  }
  return sum;
}

double Array::max() const {     // Obtain the max entry of the array
  double max = this->_data[0];  // Set first element of array as max
  for (unsigned i = 0; i < this->_size; i++) {
    if (this->_data[i] > max) {
      max = this->_data[i];
    }
  }
  return max;
}

double Array::min() const {    // Obtain the min entry of the array
 double min = this->_data[0];  // Set first element of array as min
  for (unsigned i = 0; i < this->_size; i++) {
    if (this->_data[i] < min) {
      min = this->_data[i];
    }
  }
  return min;
}

double Array::dot(const Array &rhs) const {
  double sum = 0.0;
  // Arrays must be equal length
  if(rhs._size != this->_size) {  // Use rhs attribute _size instead of getter function
    std::cerr << "Cannot compute dot product with different dimension" << std::endl;
  }
  for (unsigned i = 0; i < this->_size; i++) {
    sum += (rhs._data[i])*(this->_data[i]);
  }
  return sum;
}

Array Array::add(const Array &rhs) const {
  // Arrays must be equal length
  if(rhs._size != this->_size) {  // Use rhs attribute _size instead of getter function
    std::cerr << "Cannot compute sum with different dimension" << std::endl;
  }
  Array sum(this->_size);  // Construct sum array
  for (unsigned i = 0; i < this->_size; i++) {
    sum._data[i] = this->_data[i] + rhs._data[i];
  }
  return sum;
}

Array Array::sub(const Array &rhs) const {
  // Arrays must be equal length
  if(rhs._size != this->_size) {  // Use rhs attribute _size instead of getter function
    std::cerr << "Cannot compute difference with different dimension" << std::endl;
  }
  Array diff(this->_size);  // Construct sum array
  for (unsigned i = 0; i < this->_size; i++) {
    diff._data[i] = this->_data[i] - rhs._data[i];
  }
  return diff;
}

void Array::print() const {
  for (unsigned i = 0; i < this->_size; i++) {
    if (i == 0) {  // Format for first element of array 
      std::cout << "[" << this->_data[i] << ", ";
    }
    else if (i == (this->_size) - 1) {  // Format for last element of array, create new line
      std::cout << this->_data[i] << "]" << std::endl;
    }
    else { // Format for inner elements of array 
      std::cout << this->_data[i] << ", ";
    }
  }
}

double &Array::operator[](const unsigned index) {  // Overload accessing operator for objects
  return this->_data[index];
}

const double &Array::operator[](const unsigned index) const {  // Overload accessing operator for constant objects
  return this->_data[index];
}

Array &Array::operator=(const Array &other) {
  if (other._size != this->_size) {  // Resize arrays if not equal
    this->resize(other._size);
  }
  this->copy(other);  // Copy other to this
  return *this;  // Return reference
}


/////////////////////FREE FUNCTIONS/////////////////////////

Array operator+(const Array &lhs, const Array &rhs) {
  return lhs.add(rhs);
}

Array operator-(const Array &lhs, const Array &rhs) {
  return lhs.sub(rhs);
}
 
  
 

 


    




  

  



  


  
