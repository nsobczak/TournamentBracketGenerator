//
// Created by nicolas on 20/12/17.
//

#include "TournamentSingleElimination.h"


// best tournament for nplayers = 2, 4, 8, 16, 32, 64...


//____________________________________________________________

bool TournamentSingleElimination::IsPlayerNumberOptimal(int playerNumber)
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

TournamentSingleElimination::TournamentSingleElimination(int newPlayerNumber) : playerNumber{newPlayerNumber},
                                                                                playersIdArray{new int[newPlayerNumber]}
{
    this->isPlayerNumberOptimal = IsPlayerNumberOptimal(newPlayerNumber);
    for (int i = 0; i < this->playerNumber; i++)
    {
        this->playersIdArray[i] = i;
    }
}


//Classy::Classy(int parraysize)
//        : arraysize{parraysize}, playersIdArray{new int[arraysize]}
//{
//    for (int i = 0; i < arraysize; i++)
//    {
//        playersIdArray[i] = i * i * 2;
//    }
//}

//____________________________________________________________

bool TournamentSingleElimination::getIsPlayerNumberOptimal() const
{
    return isPlayerNumberOptimal;
}


void TournamentSingleElimination::setIsPlayerNumberOptimal(bool isPlayerNumberOptimal)
{
    TournamentSingleElimination::isPlayerNumberOptimal = isPlayerNumberOptimal;
}


//____________________________________________________________

void TournamentSingleElimination::printarray()
{
    std::cout << "|";
    for (int i = 0; i < this->playerNumber; i++)
        std::cout << "|" << playersIdArray[i];
    std::cout << "||" << std::endl;
}


void TournamentSingleElimination::generateTournament()
{
    if (this->isPlayerNumberOptimal)
    {
        //TODO:generate here
        int tab[this->isPlayerNumberOptimal] = {};


    }
}


//____________________________________________________________
//____________________________________________________________
// === Tests ===


bool TournamentSingleElimination::Test_IsPlayerNumberOptimal()
{
    std::cout << "\n\n=== IsPlayerNumberOptimal ===" << std::endl;
    if ((IsPlayerNumberOptimal(1) == 0) && (IsPlayerNumberOptimal(2) == 1) &&
        (IsPlayerNumberOptimal(3) == 0) && (IsPlayerNumberOptimal(4) == 1) &&
        (IsPlayerNumberOptimal(7) == 0) && (IsPlayerNumberOptimal(8) == 1) &&
        (IsPlayerNumberOptimal(9) == 0))
        return true;
    else
        return false;
}


void TournamentSingleElimination::Test_printarray()
{
    std::cout << "\n\n=== printarray ===" << std::endl;
    TournamentSingleElimination tournamentSingleElimination(9);
    tournamentSingleElimination.printarray();
}


void TournamentSingleElimination::Test_Tournament_SingleEliminationClass()
{
    std::cout << "\n===========================================" << std::endl
              << "|| Test_TournamentSingleEliminationClass ||" << std::endl
              << "===========================================" << std::endl;

    std::cout << (Test_IsPlayerNumberOptimal() == 1) << std::endl;

    Test_printarray();
}
