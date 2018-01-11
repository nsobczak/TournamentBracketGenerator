cmake_minimum_required(VERSION 3.9)
project(TournamentBracketGenerator)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5Widgets REQUIRED)

add_executable(TournamentBracketGenerator main.cpp TournamentSingleElimination.cpp TournamentSingleElimination.h Match.cpp Match.h Competitor.cpp Competitor.h tabLibray.cpp tabLibray.h qtTry.cpp qtTry.h QTWindowTry.cpp QTWindowTry.h)
target_link_libraries(TournamentBracketGenerator Qt5::Widgets)
