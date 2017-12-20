//
// Created by nicolas on 20/12/17.
//

#include "Hello.h"


//____________________________________________________________
/**
 * \fn
 * \brief constructor
 */
Hello::Hello()
{
    this->nature = "civilized";
};


/**
 * \fn
 * \brief constructor
 */
Hello::Hello(std::string newNature)
{
    this->
            nature = newNature;
};


//____________________________________________________________

/**
 * \fn
 * \brief
 */
void Hello::sayHello()
{
    if (this->nature == "civilized")
        std::cout << "Hello, World!" << std::endl;
    else
        std::cout << "Hi!" << std::endl;
}


//____________________________________________________________

void Hello::Test_HelloClass()
{
    Hello hello;
    hello.sayHello();

    Hello hello2("fearless");
    hello2.sayHello();
}
