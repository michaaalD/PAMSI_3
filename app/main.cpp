#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
#endif

#include "game_ai.h"
#include "game.h"
#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>

int main() 
{
    char player = 'x'; 
    char ai_player = 'o';

    int size;   // rozmiar planszy do gry
    int length; // ilosc znakow do wygranej.
    int depth;  // glebokosc rekursji
    
    
     
     std::cout << "* Menu *\n\'";
        do{
            std::cout << "Rozmiar planszy do gry: ";
            std::cin >> size;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            if (size < 3 || size > 8)
                std::cout << "Error - zly wymiar planszy\n";
        }while(size < 3 || size >8);

        do{
            std::cout << "glebokosc rekursji AI: ";
            std::cin >> depth;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }while(depth <= 0 || depth > 8);

        
        do{
            std::cout << "Ile znakow do wygranej: ";
            std::cin >> length;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            if(length < 2 || length > size)
                std::cout << "Ilosc znakow musi byc z przedzialu <2," << size << ">\n";
        }while(length < 2 || length > size);
       
    Game game(size, length, player);
    Game_ai ai(depth);

    game.print();

    while(game.current() == 0 && !game.fullCheck())
        {  
            if(game.turnCheck()) 
            {
                int x=0; 
                int y=0;
                std::cout << "twoja tura\n";
                do{
                    do{
                        std::cout << "x ---> ";
                        std::cin >> x;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        if(x > size || x < 1)
                        {
                            std::cout << "xE<1," << size << ">\n";
                        }
                    }while(x > size || x < 1);

                  
                    do{
                        std::cout << "y ---> ";
                        std::cin >> y;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        if(y > size || y < 1 )
                        {
                            std::cout << "# yE <1," << size << ">\n";
                        }
                    }while(y > size || y < 1 );

                    
                    if(game.available(x, y)) {
                        std::cout << "punkt (" << x << "," << y << ") jest zajety";
                        std::cout << '\n';
                    }
                }while(game.available(x, y) || x < 1 || x > size || y < 1 || y > size);
                game.set(x, y);
                game.changeTurn(0);
            }
            

            else{
                std::cout << "tura ai" << std::endl;
                ai.move(game);
                game.set(ai.get_x(), ai.get_y());
                game.changeTurn(1);
            }

            game.print();

            // sprawdzenie stanu gry
            if(game.fullCheck() && game.current() == 0)
            {
                std::cout << "Wynik: Remis";
            }
            else if(game.current() != 0) 
            {
                std::cout << "wygrywa: ";
                if(!game.turnCheck())
                {
                    std::cout << player << std::endl;
                }
                else
                {
                    std::cout << ai_player << std::endl;
                }
            }
        }
}
