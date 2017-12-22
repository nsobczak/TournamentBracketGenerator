//
// Created by nicolas on 20/12/17.
//

#ifndef TOURNAMENTBRACKETGENERATOR_MATCH_H
#define TOURNAMENTBRACKETGENERATOR_MATCH_H

#include <iostream>
#include "Competitor.h"

/**
 * \class Match
 * \brief match class, 2 players, their scores, 1 winner
 */
class Match
{

private:
    Competitor competitorA;
    Competitor competitorB;
    Competitor winner;
    int points_competitorA;
    int points_competitorB;

    //tests
    static bool Test_computeWinner();

public:
    Match(const Competitor &competitorA, const Competitor &competitorB);

    const Competitor &getCompetitorA() const;

    const Competitor &getCompetitorB() const;

    int getPoints_competitorA() const;

    void setPoints_competitorA(int points_competitorA);

    int getPoints_competitorB() const;

    void setPoints_competitorB(int points_competitorB);

    const Competitor &getWinner() const;

    //methods
    void computeWinner();

    //tests
    static void Test_MatchClass();
};


#endif //TOURNAMENTBRACKETGENERATOR_MATCH_H
