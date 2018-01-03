//
// Created by nicolas on 20/12/17.
//

#include "Match.h"

//____________________________________________________________
Match::Match() : previousMatchA{nullptr}, previousMatchB{nullptr}
{
}

Match::Match(const Competitor &competitorA, const Competitor &competitorB) : competitorA(competitorA),
                                                                             competitorB(competitorB),
                                                                             points_competitorA{0},
                                                                             points_competitorB{0},
                                                                             previousMatchA{nullptr},
                                                                             previousMatchB{nullptr}
{
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

void Match::setWinner(const Competitor &winner)
{
    Match::winner = winner;
}


Match *Match::getPreviousMatchA() const
{
    return previousMatchA;
}

void Match::setPreviousMatchA(Match *previousMatchA)
{
    Match::previousMatchA = previousMatchA;
}

Match *Match::getPreviousMatchB() const
{
    return previousMatchB;
}

void Match::setPreviousMatchB(Match *previousMatchB)
{
    Match::previousMatchB = previousMatchB;
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


void Match::updateMatchCompetitors()
{
    if (this->previousMatchA != nullptr && previousMatchA->getWinner().getPseudo() != "")
        this->competitorA = previousMatchA->getWinner();

    if (this->previousMatchB != nullptr && previousMatchB->getWinner().getPseudo() != "")
        this->competitorB = previousMatchB->getWinner();
}


void Match::printMatchArray(Match *pTab, int arraySize, bool withPreviousMatch)
{
    std::cout << "|";
    for (int i = 0; i < arraySize; ++i)
    {
        if (withPreviousMatch)
            std::cout << "|" << "-" << pTab[i].previousMatchA << "-" << pTab[i].previousMatchB << "- "
                      << pTab[i].competitorA.getPseudo() << " vs " << pTab[i].competitorB.getPseudo();
        else
            std::cout << "|" << pTab[i].competitorA.getPseudo() << " vs " << pTab[i].competitorB.getPseudo();
    }

    std::cout << "||" << std::endl;
}


//____________________________________________________________
//____________________________________________________________
// === Tests ===


bool Match::Test_computeWinner()
{
    std::cout << "\n=== Test_computeWinner ===" << std::endl;

    Competitor p1, p2;
    Match matchA = Match(p1, p2);
    matchA.points_competitorB += 2;
    matchA.computeWinner();

    Competitor p3("p3"), p4("p4");
    Match matchB = Match(p3, p4);
    matchB.points_competitorA += 2;
    matchB.computeWinner();

    Competitor p5("p5"), p6("p6");
    Match matchC = Match(p5, p6);
    matchC.points_competitorA += 1;
    matchC.points_competitorB += 1;
    matchC.computeWinner();

    if (matchA.winner.getPseudo() == matchA.competitorB.getPseudo() &&
        matchB.winner.getPseudo() == matchB.competitorA.getPseudo() &&
        matchB.winner.getPseudo() != matchB.competitorB.getPseudo() &&
        matchC.winner.getPseudo() != matchC.competitorA.getPseudo() &&
        matchC.winner.getPseudo() != matchC.competitorB.getPseudo() &&
        matchC.winner.getPseudo() == "")
        return true;
    else
        return false;
}


bool Match::Test_updateMatchCompetitors()
{
    std::cout << "\n=== Test_updateMatchCompetitors ===" << std::endl;

    Competitor p1("p1"), p2("p2");
    Match matchA = Match(p1, p2);
    matchA.points_competitorB += 2;
    matchA.computeWinner();
    //test nullptr
    Match matchANext;
    matchANext.updateMatchCompetitors();

    Competitor p3("p3"), p4("p4");
    Match matchB = Match(p3, p4);
    matchB.points_competitorA += 2;
    matchB.computeWinner();
    //test add competitors
    Match matchBNext;
    matchBNext.setPreviousMatchA(&matchA);
    matchBNext.setPreviousMatchB(&matchB);
    matchBNext.updateMatchCompetitors();

    Competitor p5("p5"), p6("p6");
    Match matchC = Match(p5, p6);
    matchC.points_competitorA += 1;
    matchC.points_competitorB += 1;
    matchC.computeWinner();
    //test nullpseudo
    Match matchCNext;
    matchCNext.setPreviousMatchA(&matchA);
    matchCNext.setPreviousMatchB(&matchC);
    matchCNext.updateMatchCompetitors();

    if (matchANext.competitorA.getPseudo() == "" &&
        matchANext.competitorB.getPseudo() == "" &&
        matchBNext.competitorA.getPseudo() == matchA.getWinner().getPseudo() &&
        matchBNext.competitorB.getPseudo() == matchB.getWinner().getPseudo() &&
        matchCNext.competitorA.getPseudo() == matchA.getWinner().getPseudo() &&
        matchCNext.competitorB.getPseudo() == "")
        return true;
    else
        return false;
}


void Match::Test_MatchClass()
{
    std::cout << "\n||=================||" << std::endl
              << "|| Test_MatchClass ||" << std::endl
              << "||=================||" << std::endl;

    std::cout << (Test_computeWinner() == 1) << std::endl;

    std::cout << (Test_updateMatchCompetitors() == 1) << std::endl;
}



