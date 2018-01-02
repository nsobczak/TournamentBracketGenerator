//
// Created by nicolas on 20/12/17.
//

#include "Competitor.h"

//____________________________________________________________
Competitor::Competitor() : points{0}
{
}

Competitor::Competitor(const std::string &pseudo) : points{0}, pseudo{pseudo}
{
}

const std::string &Competitor::getPseudo() const
{
    return pseudo;
}

void Competitor::setPseudo(const std::string &pseudo)
{
    Competitor::pseudo = pseudo;
}

int Competitor::getPoints() const
{
    return points;
}

void Competitor::setPoints(int points)
{
    Competitor::points = points;
}

//____________________________________________________________



