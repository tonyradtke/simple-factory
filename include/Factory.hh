#ifndef FACTORY_H
#define FACTORY_H

#include <map>
#include <any>
#include <string>
#include <functional>
#include <iostream>

//must bring your own base..

template<typename Base>
class Factory {
public:

  std::map<std::string, std::function<std::shared_ptr<Base>()>> m_dispatcher;

  Factory() {};  

  //T must have default ctor....
  template<typename T>
  void registerType(std::string key) {
    if (m_dispatcher.count(key)) { 
      return;
    }
    m_dispatcher[key] = []() -> std::shared_ptr<T> { return std::shared_ptr<T>(new T()); };
  } 

  template<typename T>
  T dispatchType(std::string s) {
    return *(dispatch(s));
  }

  std::shared_ptr<Base> dispatch(std::string f_id) {
    if (not m_dispatcher.count(f_id)) { 
      std::cout << "key not in factory : " << f_id << "\n";
      return nullptr;
    }   
    return m_dispatcher[f_id]();
  }

  void size() {
    std::cout << "size : " << m_dispatcher.size() << "\n";
  }

};


#endif
