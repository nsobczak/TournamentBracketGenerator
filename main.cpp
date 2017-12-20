#include <iostream>
//using namespace std;

#include "Hello.h"


int main() {
    Hello hello;
    hello.sayHello();
    Hello hello2("fearless");
    hello2.sayHello();
    return 0;
}