#include "Factory.hh"

#include "Foo.hh"
#include "Bar.hh"

#include "Product.hh"

int main() {

Factory<Product> factory;

factory.registerType<Bar>("bar");
factory.registerType<Bar>("foo");

Foo f = factory.dispatchType<Foo>("foo");
Bar b = factory.dispatchType<Bar>("bar");

f.foo();
b.bar();

}

