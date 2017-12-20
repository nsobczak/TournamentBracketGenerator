//
// Created by nicolas on 20/12/17.
//

#ifndef TOURNAMENTBRACKETGENERATOR_TOURNAMENT_SINGLEELIMINATION_H
#define TOURNAMENTBRACKETGENERATOR_TOURNAMENT_SINGLEELIMINATION_H

#include <iostream>
#include "Match.h"

class TournamentSingleElimination
{
private:
    int playerNumber;
    bool isPlayerNumberOptimal;

    //tests
    static bool Test_IsPlayerNumberOptimal();

public:
    TournamentSingleElimination(int newPlayerNumber);

    bool getIsPlayerNumberOptimal() const;

    void setIsPlayerNumberOptimal(bool isPlayerNumberOptimal);

    //methods
    void generateTournament();

    //tests
    static bool IsPlayerNumberOptimal(int playerNumber);

    static void Test_Tournament_SingleEliminationClass();
};


#endif //TOURNAMENTBRACKETGENERATOR_TOURNAMENT_SINGLEELIMINATION_H
