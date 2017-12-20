//
// Created by nicolas on 20/12/17.
//

#ifndef TOURNAMENTBRACKETGENERATOR_HELLO_H
#define TOURNAMENTBRACKETGENERATOR_HELLO_H

#include <iostream>

class Hello
{
    std::string nature;

private:
    void sayHello();

public:
    Hello();

    Hello(std::string newNature);

    static void Test_HelloClass();
};


#endif //TOURNAMENTBRACKETGENERATOR_HELLO_H
