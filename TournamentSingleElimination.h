//
// Created by nicolas on 20/12/17.
//

#ifndef TOURNAMENTBRACKETGENERATOR_TOURNAMENT_SINGLEELIMINATION_H
#define TOURNAMENTBRACKETGENERATOR_TOURNAMENT_SINGLEELIMINATION_H

#include <iostream>
#include <memory>
#include "Match.h"


/**
 * \class TournamentSingleElimination
 * \brief generate bracket for single tournament elimination
 */
class TournamentSingleElimination
{
private:
    int playerNumber;
    bool isPlayerNumberOptimal;
    std::unique_ptr<int[]> playersIdArray;

    //tests
    static bool Test_IsPlayerNumberOptimal();

public:
    TournamentSingleElimination(int newPlayerNumber);

    bool getIsPlayerNumberOptimal() const;

    void setIsPlayerNumberOptimal(bool isPlayerNumberOptimal);

    //methods
    void generateTournament();

    void printarray();

    //tests
    static bool IsPlayerNumberOptimal(int playerNumber);

    static void Test_printarray();

    static void Test_Tournament_SingleEliminationClass();
};


#endif //TOURNAMENTBRACKETGENERATOR_TOURNAMENT_SINGLEELIMINATION_H

