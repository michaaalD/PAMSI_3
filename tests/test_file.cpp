
#include "doctest/doctest.h"
// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.

#include "../inc/board.h"
#include "../inc/computer.h"


TEST_CASE("Sprawdzenie printa planszy"){
    Board board(3, 3, 'x');
    Computer ai(3);
    board.print();
}

TEST_CASE("Sprawdzenie zmiany tury")
{
    int ai = 0;
    int player = 1;
    Board board(3, 3, player);
    //Computer ai(3);
    board.changeTurn(ai);
   bool result =  board.turnCheck();
   CHECK(result == false);
}

TEST_CASE("Sprawdzenie reseta"){

}