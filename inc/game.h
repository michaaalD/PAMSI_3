#pragma once
#ifndef GAME
#define GAME
#include <vector>

class Game{
    private:
        int size;                                // rozmiar planszy 
        int to_win;                              // ilosc znakow do wygranej
        bool turn;                               // true-gracz, false-ai
        char player_symbol;
        char ai_symbol;           
        std::vector<std::vector<char>> moves;  // wektorw znakow x/o
        
    public:
        Game(){};
        Game(int size, int to_win, char player);
        void changeTurn(bool player);
        void print() const;                   // wydruk planszy
        void remove(int x, int y);            // usuniecie znaku z planszy
        bool turnCheck() const;               // sprawdzenie czy tura gracza
        //void reset();                         // reset planszy
        char check(int x, int y) const;       // sprawdzanie znaku w polu
        bool available(int x, int y) const;  // sprawdzanie czy wolna wspolrzedna
        bool fullCheck() const;                  // sprawdzanie czy zapelniona
        int current() const;                // sprawdzanie stanu gry
        void set(int x, int y);               // wwpisanie w planszy
        int getSize() const{return size;} // getter rozmiaru
};

#endif