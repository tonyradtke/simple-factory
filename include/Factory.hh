#ifndef FACTORY_H
#define FACTORY_H

#include <map>
#include <any>
#include <string>
#include <functional>
#include <iostream>
#include <type_traits>

//must bring your own base..

template<typename Base>
class Factory {
public:
  std::map<std::string, std::function<std::shared_ptr<Base>()>> m_dispatcher;

  Factory() {};  

  //T must have T::T() and T::T(const Base&)
  template<typename T>
  void register_type(std::string key) {
    static_assert(std::is_default_constructible_v<T>, "Parameter must be default-constructible");
    static_assert(std::is_copy_constructible<const Base&>::value, "Parameter must be constructible from const Base&");
    if (m_dispatcher.count(key)) { 
      return;
    }
    m_dispatcher[key] = []() -> std::shared_ptr<T> { return std::shared_ptr<T>(new T()); };
  } 


  template<typename T>
  T dispatch_type(std::string f_id) {
    if (not m_dispatcher.count(f_id)) { 
      std::cout << "key not in factory : " << f_id << "\n";
      return T();
    }
    return *(m_dispatcher[f_id]());
  }


  void size() {
    std::cout << "size : " << m_dispatcher.size() << "\n";
  }

};


#endif
