#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
#endif

#include "computer.h"
#include "board.h"
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
            if (size < 3 || size > 7)
                std::cout << "Error - zly wymiar planszy\n";
        }while(size < 3 || size >7);

        do{
            std::cout << "glebokosc rekursji AI: ";
            std::cin >> depth;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }while(depth <= 0 || depth > 7);

        
        do{
            std::cout << "Ile znakow do wygranej: ";
            std::cin >> length;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            if (length < 2 || length > size)
                std::cout << "Ilosc znakow musi byc z przedzialu <2," << size << ">\n";
        }while (length < 2 || length > size);
       
    Board board(size, length, player);
    Computer ai(depth);

    // gra
        board.reset();
        board.print();

        while(board.current() == 0 && !board.isFull()){  // dopoki wygrana lub remis
            // ruch gracza
            if(board.turnCheck()) {
                int x; 
                int y;
                std::cout << "Twoja Tura\n";
                do{
                    // wczytywanie x
                    do{
                        x = 0;
                        std::cout << "x ---> ";
                        std::cin >> x;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        if(x < 1 || x > size)
                            std::cout << "xE<1," << size << ">\n";
                    } while(x < 1 || x > size);

                    // wczytywanie y
                    do {
                        y = 0;
                        std::cout << "y ---> ";
                        std::cin >> y;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        if (y < 1 || y > size)
                            std::cout << "# yE <1," << size << ">\n";
                    }while(y < 1 || y > size);

                    // zajete pole
                    if(board.available(x, y)) {
                        std::cout << "pole (" << x << "," << y << ") jest zajete";
                        std::cout << '\n';
                    }
                } while(board.available(x, y) || x < 1 || x > size || y < 1 || y > size);
                board.set(x, y);
                board.changeTurn(0);
            }
            // ruch ai
            else{
                std::cout << "Tura AI" << std::endl;
                ai.move(board);
                board.set(ai.get_x(), ai.get_y());
                 board.changeTurn(1);
            }

            board.print();

            // sprawdzenie stanu gry
            if(board.isFull() && board.current() == 0)
                std::cout << "Wynik: Remis";
            else if(board.current() != 0) {
                std::cout << "Wynik: wygrywa ";
                if(!board.turnCheck())
                    std::cout << "gracz (" << player << ")";
                else{
                    std::cout << "AI (" << ai_player << ")";
                }
            }
            std::cout << '\n';
        }
        

}
