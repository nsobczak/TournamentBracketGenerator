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
    int matchNumber;
    bool isPlayerNumberOptimal;
    std::unique_ptr<int[]> playersIdArray;
    std::unique_ptr<Match[]> matchArray;

    //methods
    void linkMatches(int start, int mid, int end);

    //tests
    static bool Test_IsPlayerNumberOptimal();

    static bool IsPlayerNumberOptimal(int playerNumber);

    static bool Test_generateTournament();

    static bool Test_updateTournamentProgress();

public:
    TournamentSingleElimination(int newPlayerNumber);

    int getPlayerNumber() const;

    int getMatchNumber() const;

    bool getIsPlayerNumberOptimal() const;

    void setIsPlayerNumberOptimal(bool isPlayerNumberOptimal);

    const std::unique_ptr<int[]> &getPlayersIdArray() const;

    const std::unique_ptr<Match[]> &getMatchArray() const;

    //methods
    void generateTournament();

    void updateTournamentProgress();

    //tests
    static void Test_TournamentSingleEliminationClass();
};


#endif //TOURNAMENTBRACKETGENERATOR_TOURNAMENT_SINGLEELIMINATION_H

