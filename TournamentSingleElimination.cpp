//
// Created by nicolas on 20/12/17.
//

#include "TournamentSingleElimination.h"


// best tournament for nplayers = 2, 4, 8, 16, 32, 64...


//____________________________________________________________

bool TournamentSingleElimination::IsPlayerNumberOptimal(int playerNumber)
{
    int optimalNumber = 2;

    while (optimalNumber < playerNumber)
        optimalNumber *= 2;

    if (playerNumber == optimalNumber)
        return true;
    else
        return false;
}


//____________________________________________________________
//____________________________________________________________

TournamentSingleElimination::TournamentSingleElimination(int newPlayerNumber) : playerNumber{newPlayerNumber},
                                                                                matchNumber{playerNumber - 1},
                                                                                playersIdArray{
                                                                                        new int[playerNumber]},
                                                                                matchArray{
                                                                                        new Match[matchNumber]}
{
    this->isPlayerNumberOptimal = IsPlayerNumberOptimal(newPlayerNumber);
    for (int i = 0; i < this->playerNumber; ++i)
        this->playersIdArray[i] = i;
}


//____________________________________________________________

int TournamentSingleElimination::getPlayerNumber() const
{
    return playerNumber;
}


int TournamentSingleElimination::getMatchNumber() const
{
    return matchNumber;
}


bool TournamentSingleElimination::getIsPlayerNumberOptimal() const
{
    return isPlayerNumberOptimal;
}


void TournamentSingleElimination::setIsPlayerNumberOptimal(bool isPlayerNumberOptimal)
{
    TournamentSingleElimination::isPlayerNumberOptimal = isPlayerNumberOptimal;
}


const std::unique_ptr<int[]> &TournamentSingleElimination::getPlayersIdArray() const
{
    return playersIdArray;
}


const std::unique_ptr<Match[]> &TournamentSingleElimination::getMatchArray() const
{
    return matchArray;
}


//____________________________________________________________
//____________________________________________________________
// === Methods ===


void TournamentSingleElimination::linkMatches(int start, int mid, int end)
{
    if (end - mid < 1)
        return;
    else
    {
        int j = start;
        for (int i = mid; i < end; ++i)
        {
            this->matchArray[i].setPreviousMatchA(&this->matchArray[j]);
            this->matchArray[i].setPreviousMatchB(&this->matchArray[j + 1]);
            j += 2;
        }
        this->linkMatches(mid, end, end + (end - mid) / 2);
    }
}

void TournamentSingleElimination::generateTournament()
{
    if (this->isPlayerNumberOptimal)
    {
        //shuffle and generate here
        std::random_shuffle(&this->playersIdArray[0],
                            &this->playersIdArray[this->playerNumber]);//std::begin(this->playersIdArray), std::end(this->playersIdArray)
//        tabLibrary::printArray(this->playersIdArray.get(), this->playerNumber);

        for (int i = 0; i < playerNumber / 2; ++i)  //first matches = playerNumber / 2
        {
            this->matchArray[i] = Match(Competitor(std::to_string(this->playersIdArray[i * 2])),
                                        Competitor(std::to_string(this->playersIdArray[i * 2 + 1])));
        }

        //set previous matches to have links and order
        this->linkMatches(0, this->getPlayerNumber() / 2, this->getPlayerNumber() / 2 + this->getPlayerNumber() / 4);
//        Match::printMatchArray(this->matchArray.get(), this->matchNumber, 0);

    }
}


void TournamentSingleElimination::updateTournamentProgress()
{
    if (this->isPlayerNumberOptimal)
    {
        for (int i = this->getPlayerNumber() / 2; i < this->getMatchNumber(); ++i)
            this->getMatchArray()[i].updateMatchCompetitors();
    }
}


//____________________________________________________________
//____________________________________________________________
// === Tests ===


bool TournamentSingleElimination::Test_IsPlayerNumberOptimal()
{
    std::cout << "\n=== IsPlayerNumberOptimal ===" << std::endl;
    if ((IsPlayerNumberOptimal(1) == 0) && (IsPlayerNumberOptimal(2) == 1) &&
        (IsPlayerNumberOptimal(3) == 0) && (IsPlayerNumberOptimal(4) == 1) &&
        (IsPlayerNumberOptimal(7) == 0) && (IsPlayerNumberOptimal(8) == 1) &&
        (IsPlayerNumberOptimal(9) == 0))
        return true;
    else
        return false;
}


bool TournamentSingleElimination::Test_generateTournament()
{
    std::cout << "\n=== generateTournament ===" << std::endl;
    bool test1, test2, test3;

    // === test 1 ===
    TournamentSingleElimination tournament1(9);
    TournamentSingleElimination tournament1ref(9);
    tournament1.generateTournament();
    test1 = tabLibrary::compare_tabs(tournament1.getPlayersIdArray().get(), tournament1ref.getPlayersIdArray().get(),
                                     tournament1.getPlayerNumber()) == 1;
    std::cout << "\ntest1 (not optimal number): " << test1 << "\n" << std::endl;

    // === test 2 ===
    TournamentSingleElimination tournament2(8);
    TournamentSingleElimination tournament2ref(8);
    tournament2.generateTournament();
    test2 = tabLibrary::compare_tabs(tournament2.getPlayersIdArray().get(), tournament2ref.getPlayersIdArray().get(),
                                     tournament2.getPlayerNumber()) == 0;
    std::cout << "test2 (8 as optimal number): " << test2 << "\n" << std::endl;

    // === test 3 ===
    TournamentSingleElimination tournament3(16);
    TournamentSingleElimination tournament3ref(16);
    tournament3.generateTournament();
    test3 = tabLibrary::compare_tabs(tournament3.getPlayersIdArray().get(), tournament3ref.getPlayersIdArray().get(),
                                     tournament3.getPlayerNumber()) == 0;
    std::cout << "test3 (16 as optimal number): " << test3 << "\n" << std::endl;

    // === final ===
    if (test1 && test2 && test3)
        return 1;
    else
        return 0;
}


bool TournamentSingleElimination::Test_updateTournamentProgress()
{
    std::cout << "\n=== updateTournamentProgress ===" << std::endl;
    bool test1, test2;

    // === test 1 ===
    TournamentSingleElimination tournament1(5);
    tournament1.generateTournament();
    tournament1.updateTournamentProgress();
    test1 = true;
    for (int i = 0; i < tournament1.getMatchNumber(); ++i)
    {
        if (tournament1.getMatchArray()[i].getCompetitorA().getPseudo() != "" ||
            tournament1.getMatchArray()[i].getCompetitorB().getPseudo() != "")
            test1 = false;
    }
    std::cout << "test1: " << test1 << "\n" << std::endl;

    // === test 2 ===
    TournamentSingleElimination tournament2(8);
    tournament2.generateTournament();
    tournament2.getMatchArray()[0].setWinner(tournament2.getMatchArray()[0].getCompetitorA());
    tournament2.getMatchArray()[1].setWinner(tournament2.getMatchArray()[1].getCompetitorB());
    tournament2.getMatchArray()[2].setWinner(tournament2.getMatchArray()[2].getCompetitorB());
    tournament2.updateTournamentProgress();
    Match::printMatchArray(tournament2.getMatchArray().get(), tournament2.getMatchNumber());

    test2 = (tournament2.getMatchArray()[4].getCompetitorA().getPseudo() != "" &&
             tournament2.getMatchArray()[4].getCompetitorB().getPseudo() != "" &&
             tournament2.getMatchArray()[5].getCompetitorA().getPseudo() != "" &&
             tournament2.getMatchArray()[5].getCompetitorB().getPseudo() == "");
    std::cout << "test2: " << test2 << "\n" << std::endl;


    //TODO: see if test 3 is useful
    // === test 3 ===
//    TournamentSingleElimination tournament3(16);
//    tournament3.generateTournament();
//    tournament3.updateTournamentProgress();

    // === final ===
    if (test1 && test2)
        return 1;
    else
        return 0;
}


void TournamentSingleElimination::Test_TournamentSingleEliminationClass()
{
    std::cout << "\n\n||=======================================||" << std::endl
              << "|| Test_TournamentSingleEliminationClass ||" << std::endl
              << "||=======================================||" << std::endl;

    std::cout << (Test_IsPlayerNumberOptimal() == 1) << std::endl;

    std::cout << (Test_generateTournament() == 1) << std::endl;

    std::cout << (Test_updateTournamentProgress() == 1) << std::endl;
}



