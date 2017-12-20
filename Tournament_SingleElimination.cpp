//
// Created by nicolas on 20/12/17.
//

#include "Tournament_SingleElimination.h"


// best tournament for nplayers = 2, 4, 8, 16, 32, 64...

//____________________________________________________________

Tournament_SingleElimination::Tournament_SingleElimination(int newPlayerNumber) : playerNumber(newPlayerNumber)
{
    this->isPlayerNumberOptimal = false;
}




//____________________________________________________________

bool Tournament_SingleElimination::getIsPlayerNumberOptimal() const
{
    return isPlayerNumberOptimal;
}


void Tournament_SingleElimination::setIsPlayerNumberOptimal(bool isPlayerNumberOptimal)
{
    Tournament_SingleElimination::isPlayerNumberOptimal = isPlayerNumberOptimal;
}


//____________________________________________________________

bool Tournament_SingleElimination::IsPlayerNumberOptimal(int playerNumber)
{
    int optimalNumber = 2;

    while (optimalNumber < playerNumber)
        optimalNumber *= 2;

    if (playerNumber == optimalNumber)
        return true;
    else
        return false;
}


//____________________________________________________________


void Tournament_SingleElimination::Test_IsPlayerNumberOptimal()
{
    std::cout << "\n=== IsPlayerNumberOptimal ===" << std::endl
              << "IsPlayerNumberOptimal(1): " << IsPlayerNumberOptimal(1) << std::endl
              << "IsPlayerNumberOptimal(2): " << IsPlayerNumberOptimal(2) << std::endl
              << "IsPlayerNumberOptimal(3): " << IsPlayerNumberOptimal(3) << std::endl
              << "IsPlayerNumberOptimal(4): " << IsPlayerNumberOptimal(4) << std::endl
              << "IsPlayerNumberOptimal(7): " << IsPlayerNumberOptimal(7) << std::endl
              << "IsPlayerNumberOptimal(8): " << IsPlayerNumberOptimal(8) << std::endl
              << "IsPlayerNumberOptimal(9): " << IsPlayerNumberOptimal(9) << std::endl;
}

void Tournament_SingleElimination::Test_Tournament_SingleEliminationClass()
{
    std::cout << "\n============================================" << std::endl
              << "|| Test_Tournament_SingleEliminationClass ||" << std::endl
              << "============================================" << std::endl;

    Test_IsPlayerNumberOptimal();
}
