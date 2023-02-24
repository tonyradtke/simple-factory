<h2> Introduction </h2>

  - This is intended to be a simple, lightweight, portable,header only Factory implementation
  - BYOB (Bring Your Own Base!) (templatized by a 'base' class that you provide upon init)

  <p> Each type to be registered in the factory, must inheret from a single parent type. This allows us to have any type in the factory.
      Althought inhereting from this single parent type is necessary to get around some compiler limitations surrounding implicit conversion, the 
      type need not have any content. class Base{}; will suffice.   
      Types to be registered in the factory must have a default constructor, as well as a constructor taking a const Base&.
  </p>


<h2> Example </h2>
 
  - First lets create our universal ancestor type (Base.hh) : 

  ```cpp

    class Base{};
  ```

  - Now we create a type to be registered in the factory (Foo.hh) : 

  ```cpp

    #include "Base.hh"
    
    class Foo : public Base {
      public: 

        // no actual implementation needed for these
        Foo(){};              // need default for factory creation function
        Foo(const Base& b){}; // need to circumvent compiler limitation
    
        void foo() {
          std::cout << "foo!\n";
        }
    };
  ```

  - Now we can register and dispatch types by key with the factory : 

  ```cpp

    #include <Factory.hh>
    #include "Base.hh"
    #include "Foo.hh"
    
    Factory<Base> factory;
  
    factory.register_type<Foo>("foo");
    
    Foo f = factory.dispatch_type<Foo>("foo");

    f.foo();
  ```
  
 

  


<h2> Building </h2>

<ol>
  <li> Download, Build and Install simple-factory with CMake 
    <ul>
      <li> git clone https://github.com/tonyradtke/simple-factory.git </li>
      <li> cd simple-factory </li>
      <li> mkdir build </li>
      <li> cd build </li>
      <li> cmake .. </li>
      <li> make install </li>
    </ul>
  </li>
  <br>
  <li>  Build and Run the demo to make sure things are working 
    <ul> 
      <li> cd demo </li>
      <li> mkdir build </li>
      <li> cd build </li>
      <li> cmake . </li>
      <li> make </li>
      <li> ./bin/__demo__ </li>
    </ul>
  </li>
  <br>
  <li> Include simple-factory in your project </li>
    <ul>
      <li> include_directories(${YOUR_INCLUDE_DIR})  </li>
      <li> include Factory.hh in your project </li>
      <li> Bring Your Own Base type for all factory items to inheret from </li>
      <li> Ensure all factory types inheret from this base type </li>
    </ul> 
  </li>
  <br>
</ol>




