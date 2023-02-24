#ifndef FACTORY_H
#define FACTORY_H

#include <map>
#include <any>
#include <string>
#include <functional>
#include <iostream>

#include "Product.hh"
#include "Foo.hh"

class Factory {
public:

  std::map<std::string, std::function<std::shared_ptr<Product>()>> m_dispatcher;

  Factory() {
   
    m_dispatcher["foo"] = []() -> std::shared_ptr<Foo> { return std::shared_ptr<Foo>(new Foo()); };

  };  

  std::shared_ptr<Product> dispatch(std::string f_id) {
    if (not m_dispatcher.count(f_id)) { 
      std::cout << "key not in factory : " << f_id << "\n";
      return nullptr;
    }   
    return m_dispatcher[f_id]();
  }

  template<typename T>
  T create(std::string s) {
    return *(dispatch(s));
  }

  void size() {
    std::cout << "size : " << m_dispatcher.size() << "\n";
  }

};


#endif
