#include "Factory.hh"



#include "Foo.hh"

int main() {

Factory factory;
Foo foobar = factory.create<Foo>("foo");

foobar.foo();


}

