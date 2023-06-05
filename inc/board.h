#pragma once
#include <vector>

class Board{
    private:
        int size;                                // rozmiar planszy 
        int to_win;                              // ilosc znakow do wygranej
        bool turn;                               // kolej, 1-gracz, 0-ai
        char player_symbol, ai_symbol;           // X/O
        std::vector<std::vector<char>> entries;  // pola (X lub O)
    public:
        Board(){};
        Board(int size, int to_win, char player);
        void changeTurn(bool player);
        void print() const;                   // wyswietlenie planszy
        void remove(int x, int y);            // usuniecie pola planszy
        bool turnCheck() const;            // sprawdzenie czy teraz jest ruch gracza
        void reset();                         // czyszczenie planszy
        char check(int x, int y) const;       // sprawdzanie znaku w polu
        bool available(int x, int y) const;  // sprawdzanie czy pole jest zajete
        bool isFull() const;                  // sprawdzanie czy plansza jest zapelniona
        int current() const;                // sprawdzanie stanu gry
        void set(int x, int y);               // ustawianie pola planszy


        int getSize() const { return size; } // getter rozmiaru
};