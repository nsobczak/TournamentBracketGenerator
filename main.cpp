#include <iostream>


class Hello {
//    int width, height;
public:

    void sayHello() {
        std::cout << "Hello, World!" << std::endl;
    }
};

int main() {
    Hello hello;
    hello.sayHello();
    return 0;
}