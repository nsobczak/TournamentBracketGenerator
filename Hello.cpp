//
// Created by nicolas on 20/12/17.
//

#include "Hello.h"


/**
 * \fn
 * \brief
 */
Hello::Hello() {
    this->nature = "civilized";
};


Hello::Hello(std::string
             newNature) {
    this->
            nature = newNature;
};


void Hello::sayHello() {
    if (this->nature == "civilized")
        std::cout << "Hello, World!" << std::endl;
    else
        std::cout << "Hi!" << std::endl;
}
