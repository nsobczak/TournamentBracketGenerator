cmake_minimum_required(VERSION 3.9)
project(TournamentBracketGenerator)

set(CMAKE_CXX_STANDARD 11)

add_executable(TournamentBracketGenerator main.cpp Hello.cpp Hello.h TournamentSingleElimination.cpp TournamentSingleElimination.h Match.cpp Match.h Competitor.cpp Competitor.h)