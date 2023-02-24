#include <Factory.hh>

#include "Foo.hh"
#include "Bar.hh"

#include "Product.hh"

int main() {

Factory<Product> factory;

factory.register_type<Bar>("foo");
factory.register_type<Bar>("bar");

Foo f = factory.dispatch_type<Foo>("foo");
Bar b = factory.dispatch_type<Bar>("bar");

f.foo();
b.bar();

}

