#include <iostream>
//using namespace std;

#include "TournamentSingleElimination.h"
#include "qtTry.h"
#include "QTWindowTry.h"

//____________________________________________________________

int main(int argc, char **argv)
{

//    Match::Test_MatchClass();
//
//    TournamentSingleElimination::Test_TournamentSingleEliminationClass();


    qDebug() << QT_VERSION_STR;

//    qtTry::tryQT(argc, argv);

    QApplication app(argc, argv);
    QTWindowTry windowTest;
    windowTest.show();

    return app.exec();
}