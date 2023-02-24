#ifndef BAR_H
#define BAR_H

#include <iostream>

#include "Product.hh"

class Bar : public Product {
public: 

  Bar(const Product& p) {}
  Bar(){}

  void bar() {
    std::cout << "bar\n";
  }

};

#endif 
