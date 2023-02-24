#ifndef FOO_H
#define FOO_H

#include <iostream>

#include "Product.hh"

class Foo : public Product {
public: 

  Foo(const Product& p) {}
  Foo(){}

  void foo() {
    std::cout << "foo\n";
  }

};

#endif 
