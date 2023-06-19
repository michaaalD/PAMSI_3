
#include "doctest/doctest.h"
// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.

#include "../inc/game.h"
#include "../inc/game_ai.h"


TEST_CASE("Sprawdzenie printa planszy")
{
    Game game(3, 3, 'x');
    Game_ai ai(3);
    game.print();
}

TEST_CASE("Sprawdzenie zmiany tury")
{
    int ai = 0;
    int player = 1;
    Game game(3, 3, player);
   game.changeTurn(ai);
   bool result =  game.turnCheck();
   CHECK(result == false);
}

TEST_CASE("Sprawdzenie wpisywania znaku")
{
    char player = 'x';
    Game game(3, 3, player);
    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            game.set(i+1, j+1);
        }
    }
    game.print();
}


TEST_CASE("Sprawdzenie czy plansza jest pelna")
{
    char player = 'x';
    Game game(5, 5, player);

    for(int i=0; i < 5; i++){
        for(int j=0; j < 5; j++){
            game.set(i+1, j+1);
        }
    }
    bool result = game.fullCheck();
    CHECK(result == true);
}

TEST_CASE("Sprawdzenie czy plansza jest pelna")
{
    char player = 'x';
    Game game(6, 6, player);

    for(int i=0; i < 6; i++){
        for(int j=0; j < 6; j++){
            game.set(i+1, j+1);
        }
    }
    bool result = game.available(3,2);
    game.print();
    CHECK(result == true);
}

/*
TEST_CASE("Sprawdzenie resetu planszy ")
{
    char player = 'x';
    Game game(6, 6, player);

    for(int i=0; i < 6; i++){
        for(int j=0; j < 6; j++){
            game.set(i+1, j+1);
        }
    }
    game.reset();
    for(int i=0; i <6; i++){
        for(int j=0; j < 6; j++){
            CHECK(game.check(i+1,j+1) == 0);
        }
    }
}
*/
TEST_CASE("Sprawdzenie usuwania z planszy")
{
    char player = 'x';
    Game game(6, 6, player);

    for(int i=0; i < 6; i++){
        for(int j=0; j < 6; j++){
            game.set(i+1, j+1);
        }
    }
    game.print();
    game.remove(2,2);
    CHECK(game.check(2,2) == 0);
}


TEST_CASE("Sprawdzenie czy uzyskano ilosc w jednej linii po skosie")
{
    char player = 'x';
    Game game(5, 5, player);

    game.set(1,1);
    game.set(2,2);
    game.set(3,3);
    game.set(4,4);
    game.set(5,5);
     
    bool result = game.current();
    CHECK(result == true);
}

TEST_CASE("Sprawdzenie czy uzyskano ilosc w jednej linii w poziomie")
{
    char player = 'x';
    Game game(5, 5, player);

    game.set(1,1);
    game.set(1,2);
    game.set(1,3);
    game.set(1,4);
    game.set(1,5);
     
    bool result = game.current();
    CHECK(result == true);
}

TEST_CASE("Sprawdzenie czy uzyskano ilosc w jednej linii w pionie")
{
    char player = 'x';
    Game game(5, 5, player);

    game.set(1,1);
    game.set(2,1);
    game.set(3,1);
    game.set(4,1);
    game.set(5,1);
     
    bool result = game.current();
    CHECK(result == true);
}