//
// Created by nicolas on 20/12/17.
//

#ifndef TOURNAMENTBRACKETGENERATOR_COMPETITOR_H
#define TOURNAMENTBRACKETGENERATOR_COMPETITOR_H

#include <iostream>

class Competitor
{
private:
    std::string pseudo;
    int points;

public:

    Competitor();

    Competitor(const std::string &pseudo);

    const std::string &getPseudo() const;

    void setPseudo(const std::string &pseudo);

    int getPoints() const;

    void setPoints(int points);

};


#endif //TOURNAMENTBRACKETGENERATOR_COMPETITOR_H
