<h2> Introduction </h2>

  - This is intended to be a simple, lightweight, portable,header only Factory implementation
  - Factory is Bring Your Own Base (templatized by a 'base' class that you provide upon init)

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
      <li> #include <Factory.hh> </li>
      <li> Bring Your Own Base type for all factory items to inheret from </li>
      <li> Ensure all factory types inheret from this base type </li>
    </ul> 
  </li>
  <br>
</ol>




