//
// Created by nicolas on 20/12/17.
//

#ifndef TOURNAMENTBRACKETGENERATOR_TOURNAMENT_SINGLEELIMINATION_H
#define TOURNAMENTBRACKETGENERATOR_TOURNAMENT_SINGLEELIMINATION_H

#include <iostream>
#include <memory>
#include <algorithm>
#include "Match.h"
#include "tabLibray.h"


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

    int getPlayerNumber() const;

    bool getIsPlayerNumberOptimal() const;

    void setIsPlayerNumberOptimal(bool isPlayerNumberOptimal);

    const std::unique_ptr<int[]> &getPlayersIdArray() const;

    //methods
    void generateTournament();

    //tests
    static bool IsPlayerNumberOptimal(int playerNumber);

    static void Test_printArray();

    static void Test_generateTournament();

    static void Test_TournamentSingleEliminationClass();
};


#endif //TOURNAMENTBRACKETGENERATOR_TOURNAMENT_SINGLEELIMINATION_H

