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
//____________________________________________________________

TournamentSingleElimination::TournamentSingleElimination(int newPlayerNumber) : playerNumber{newPlayerNumber},
                                                                                playersIdArray{new int[newPlayerNumber]}
{
    this->isPlayerNumberOptimal = IsPlayerNumberOptimal(newPlayerNumber);
    for (int i = 0; i < this->playerNumber; ++i)
    {
        this->playersIdArray[i] = i;
    }
}


//____________________________________________________________

int TournamentSingleElimination::getPlayerNumber() const
{
    return playerNumber;
}


bool TournamentSingleElimination::getIsPlayerNumberOptimal() const
{
    return isPlayerNumberOptimal;
}


void TournamentSingleElimination::setIsPlayerNumberOptimal(bool isPlayerNumberOptimal)
{
    TournamentSingleElimination::isPlayerNumberOptimal = isPlayerNumberOptimal;
}


const std::unique_ptr<int[]> &TournamentSingleElimination::getPlayersIdArray() const
{
    return playersIdArray;
}


//____________________________________________________________
//____________________________________________________________
// === Methods ===

void TournamentSingleElimination::printArray()
{
    std::cout << "|";
    for (int i = 0; i < this->playerNumber; ++i)
        std::cout << "|" << playersIdArray[i];
    std::cout << "||" << std::endl;
}


void TournamentSingleElimination::generateTournament()
{
    if (this->isPlayerNumberOptimal)
    {
        //TODO:generate here
        std::random_shuffle(&this->playersIdArray[0],
                            &this->playersIdArray[this->playerNumber]);//std::begin(this->playersIdArray), std::end(this->playersIdArray)
    }
}


//____________________________________________________________
//____________________________________________________________
// === Tests ===


bool TournamentSingleElimination::Test_IsPlayerNumberOptimal()
{
    std::cout << "\n=== IsPlayerNumberOptimal ===" << std::endl;
    if ((IsPlayerNumberOptimal(1) == 0) && (IsPlayerNumberOptimal(2) == 1) &&
        (IsPlayerNumberOptimal(3) == 0) && (IsPlayerNumberOptimal(4) == 1) &&
        (IsPlayerNumberOptimal(7) == 0) && (IsPlayerNumberOptimal(8) == 1) &&
        (IsPlayerNumberOptimal(9) == 0))
        return true;
    else
        return false;
}


void TournamentSingleElimination::Test_printArray()
{
    std::cout << "\n=== printArray ===" << std::endl;
    TournamentSingleElimination tournamentSingleElimination(9);
    tournamentSingleElimination.printArray();
}


void TournamentSingleElimination::Test_generateTournament()
{
    std::cout << "\n=== generateTournament ===" << std::endl;
    TournamentSingleElimination tournament1(9);
    TournamentSingleElimination tournament1ref(9);
    tournament1.generateTournament();
    //TODO:
    std::cout << "\ntournament1 == tournament1ref : "
              << (compare_tabs(tournament1.getPlayersIdArray(), tournament1ref.getPlayersIdArray(),
                               tournament1.getPlayerNumber()))
              << std::endl;;

    TournamentSingleElimination tournament2(8);
    TournamentSingleElimination tournament2ref(8);
    tournament2.generateTournament();
    tournament2.printArray();
    tournament2ref.printArray();
}


void TournamentSingleElimination::Test_TournamentSingleEliminationClass()
{
    std::cout << "\n\n||=======================================||" << std::endl
              << "|| Test_TournamentSingleEliminationClass ||" << std::endl
              << "||=======================================||" << std::endl;

    std::cout << (Test_IsPlayerNumberOptimal() == 1) << std::endl;

    Test_printArray();

    Test_generateTournament();
}



