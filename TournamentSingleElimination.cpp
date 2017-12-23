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
    bool test1, test2;

    TournamentSingleElimination tournament1(9);
    TournamentSingleElimination tournament1ref(9);
    tournament1.generateTournament();
    test1 = tabLibrary::compare_tabs(tournament1.getPlayersIdArray().get(), tournament1ref.getPlayersIdArray().get(),
                         tournament1.getPlayerNumber()) == 1;
//    std::cout << "test1: " << (test1 == 1) << std::endl;;

    TournamentSingleElimination tournament2(8);
    TournamentSingleElimination tournament2ref(8);
    tournament2.generateTournament();
    test2 = tabLibrary::compare_tabs(tournament2.getPlayersIdArray().get(), tournament2ref.getPlayersIdArray().get(),
                         tournament2.getPlayerNumber()) == 0;
//    std::cout << "test2: " << (test2 == 0) << std::endl;
//    tournament2.printArray();
//    tournament2ref.printArray();

    if (test1 && test2)
        std::cout << 1 << std::endl;
    else
        std::cout << 0 << std::endl;
}


void TournamentSingleElimination::Test_TournamentSingleEliminationClass()
{
    std::cout << "\n\n||=======================================||" << std::endl
              << "|| Test_TournamentSingleEliminationClass ||" << std::endl
              << "||=======================================||" << std::endl;

    std::cout << (Test_IsPlayerNumberOptimal() == 1) << std::endl;

//    Test_printArray();

    Test_generateTournament();
}



