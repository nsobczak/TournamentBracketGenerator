//
// Created by nicolas on 20/12/17.
//

#ifndef TOURNAMENTBRACKETGENERATOR_TOURNAMENT_SINGLEELIMINATION_H
#define TOURNAMENTBRACKETGENERATOR_TOURNAMENT_SINGLEELIMINATION_H

#include <iostream>

class Tournament_SingleElimination
{
private:
    int playerNumber;
    bool isPlayerNumberOptimal;

    static void Test_IsPlayerNumberOptimal();

public:
    Tournament_SingleElimination(int newPlayerNumber);

    bool getIsPlayerNumberOptimal() const;

    void setIsPlayerNumberOptimal(bool isPlayerNumberOptimal);

    static bool IsPlayerNumberOptimal(int playerNumber);

    static void Test_Tournament_SingleEliminationClass();
};


#endif //TOURNAMENTBRACKETGENERATOR_TOURNAMENT_SINGLEELIMINATION_H
