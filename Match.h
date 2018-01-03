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
    Match *previousMatchA;
    Match *previousMatchB;

    //tests
    static bool Test_computeWinner();

    static bool Test_updateMatchCompetitors();


public:
    Match();

    Match(const Competitor &competitorA, const Competitor &competitorB);

    const Competitor &getCompetitorA() const;

    const Competitor &getCompetitorB() const;

    int getPoints_competitorA() const;

    void setPoints_competitorA(int points_competitorA);

    int getPoints_competitorB() const;

    void setPoints_competitorB(int points_competitorB);

    const Competitor &getWinner() const;

    void setWinner(const Competitor &winner);

    Match *getPreviousMatchA() const;

    void setPreviousMatchA(Match *previousMatchA);

    Match *getPreviousMatchB() const;

    void setPreviousMatchB(Match *previousMatchB);

    //methods
    void computeWinner();

    void updateMatchCompetitors();

    static void printMatchArray(Match *pTab, int arraySize, bool withPreviousMatch = 0);

    //tests
    static void Test_MatchClass();
};


#endif //TOURNAMENTBRACKETGENERATOR_MATCH_H
