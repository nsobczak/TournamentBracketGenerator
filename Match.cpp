//
// Created by nicolas on 20/12/17.
//

#include "Match.h"

//____________________________________________________________
Match::Match(const Competitor &competitorA, const Competitor &competitorB) : competitorA(competitorA),
                                                                             competitorB(competitorB)
{
    this->points_competitorA = 0;
    this->points_competitorB = 0;
}


const Competitor &Match::getCompetitorA() const
{
    return competitorA;
}

const Competitor &Match::getCompetitorB() const
{
    return competitorB;
}

int Match::getPoints_competitorA() const
{
    return points_competitorA;
}

void Match::setPoints_competitorA(int points_competitorA)
{
    Match::points_competitorA = points_competitorA;
}

int Match::getPoints_competitorB() const
{
    return points_competitorB;
}

void Match::setPoints_competitorB(int points_competitorB)
{
    Match::points_competitorB = points_competitorB;
}

const Competitor &Match::getWinner() const
{
    return winner;
}


//____________________________________________________________

void Match::computeWinner()
{
    if (this->points_competitorA != this->points_competitorB)
    {
        if (this->points_competitorA > this->points_competitorB)
            this->winner = this->competitorA;
        else
            this->winner = this->competitorB;
    }
}


//____________________________________________________________
//____________________________________________________________
// === Tests ===


bool Match::Test_computeWinner()
{
    std::cout << "\n\n=== Test_computeWinner ===" << std::endl;

    Competitor p1, p2;
    Match matchA = Match(p1, p2);
    matchA.points_competitorB += 2;
    matchA.computeWinner();

    Competitor p3, p4;
    Match matchB = Match(p3, p4);
    matchB.points_competitorA += 2;
    matchB.computeWinner();

    Competitor p5, p6;
    Match matchC = Match(p5, p6);
    matchC.points_competitorA += 1;
    matchA.points_competitorB += 1;
    matchC.computeWinner();

    //TODO: initialize pseudo
    //TODO: test matchC
    if (matchA.winner.getPseudo() == matchA.competitorB.getPseudo() &&
        matchA.winner.getPseudo() != matchA.competitorA.getPseudo() &&
        matchB.winner.getPseudo() == matchB.competitorA.getPseudo() &&
        matchB.winner.getPseudo() != matchB.competitorB.getPseudo())
        return true;
    else
        return false;
}


void Match::Test_MatchClass()
{
    std::cout << "\n======================" << std::endl
              << "|| Test_MatchClass ||" << std::endl
              << "======================" << std::endl;

    std::cout << (Test_computeWinner() == 1) << std::endl;

}