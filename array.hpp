#ifndef _ARRAY_HPP
#define _ARRAY_HPP

class Array {
 public:
  // default constructor
  Array();

  // copy constructor
  Array(const Array &other);

  // constructor with array size and
  // the default initialization value
  explicit Array(unsigned n, double v = 0.0);

  ~Array();

  // get the length of array
  unsigned size() const;

  // get the data pointer of array
  double *data();

  // get read-only pointer of array
  const double *data() const;

  // given a rhs Array, copy its value
  void copy(const Array &rhs);

  // reference entry "index" of the data
  double &at(unsigned index);

  // read-only reference entry "index" of the data
  const double &at(unsigned index) const;

  // resize the array
  void resize(unsigned new_size, bool prsv = true);

  // some math functions
  // L-2 norm, sum, maximum/minimum, and dot (inner) products
  double norm() const;
  double sum() const;
  double max() const;
  double min() const;
  double dot(const Array &rhs) const;

  // addition: this+rhs, return a new array
  Array add(const Array &rhs) const;

  // subtraction: this-rhs, return a new array
  Array sub(const Array &rhs) const;

  // do some terminal printing
  void print() const;

  // operators

  // accessing operator
  double &      operator[](const unsigned index);
  const double &operator[](const unsigned index) const;

  // assignment
  Array &operator=(const Array &other);

 private:
  double * _data;  ///< data pointer
  unsigned _size;  ///< length of the array
};

// free functions

// addition of two arrays
Array operator+(const Array &lhs, const Array &rhs);

// subtraction of two arrays
Array operator-(const Array &lhs, const Array &rhs);

#endif
