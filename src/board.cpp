#include "board.h"

#include <iomanip>
#include <iostream>
#include <string>

/**
 * @brief Construct a new Board:: Board object
 * 
 * @param size rozmiar planszy
 * @param to_win ilosc w linii do wygrania 
 * @param player_symbol symbol 
 */
Board::Board(int size, int to_win, char player_symbol) : size(size), to_win(to_win), player_symbol(player_symbol), entries(size, std::vector<char>(size)) {
    // przekroczenia
    if(size < 3){
        size = 3;
        entries.resize(size);
    }

    if(to_win < 2){
        to_win = 2;
    }
    if(to_win > size){
        to_win = size;
    }

    // wyzerowanie pol
    for(int x = 0; x < size; x++)
        for(int y = 0; y < size; y++)
            entries[x][y] = 0;

    if (player_symbol == 'x')
        ai_symbol = 'o';
    else if (player_symbol == 'o')
        ai_symbol = 'x';
    else {
        player_symbol = 'x';
        ai_symbol = 'o';
    }
    turn = 1;  // gracz zaczyna
}

/**
 * @brief Funkcja zmieniajaca ture
 * 
 * @param player zwraca kto teraz ma swoja ture komputer/gracz
 */
void Board::changeTurn(bool player){ 
    player ? turn = 1 : turn = 0; }

/**
 * @brief Funkcja do yswietlania planszy
 * 
 */
void Board::print() const 
{
    std::cout << "     ";
    for(int x = 0; x < size; x++) {
        if(x < 9){
            std::cout << "x" << x + 1 << "   ";
        }
        else{
            std::cout << "x" << x + 1 << "  ";
        }
    }
    std::cout << '\n';

    
    for(int y = 0; y < size; y++){
        std::cout << std::setw(2) << "y" << y + 1 << "   ";
        for(int x = 0; x < size; x++) {
            if(entries[x][y] == 0)
                std::cout << ' ';
            else
                std::cout << entries[x][y];
            if(x < size - 1)
                std::cout << " | ";
        }
        std::cout << "   ";

        if(y < size - 1){
            std::cout << "\n     ";
            for (int i = 0; i < size - 1; i++)
                std::cout << std::string(3, '-') << '+';
            std::cout << std::string(3, '-') << " ";
        }
        std::cout << '\n';
    }
}


/**
 * @brief funkcja usuwajaca z planszy
 * 
 * @param x wspolrzedna x na planszy
 * @param y wspolrzedna y na planszy
 */
void Board::remove(int x, int y){
    entries[x - 1][y - 1] = 0;
}


/**
 * @brief Funkcja sprawdzajaca czyja tura
 * 
 * @return true zwraca 1 jesli tura gracza
 * @return false 0 jesli tura kompa
 */
bool Board::turnCheck() const {
    return turn;
}


/**
 * @brief 
 * 
 */
void Board::reset(){
    for(int x = 0; x < size; x++)
        for(int y = 0; y < size; y++){
            entries[x][y] = 0;
        }
    turn = 1;  // gracz zaczyna
}


/**
 * @brief funkcja zwracajaca element o danej wspoolrzednej
 * 
 * @param x wspolrzedna z na planszy
 * @param y wspolrzedna y na pplanszy
 * @return char 
 */
char Board::check(int x, int y) const{
    if (x >= 1 && x <= size && y >= 1 && y <= size)
        return entries[x - 1][y - 1];
    else
        return 0;
}


/**
 * @brief Funkcja sprawdzajaca czy wspolrzedna na planszy jest wolna
 * 
 * @param x wspolrzedna x na planszy
 * @param y wspolrzedna y na planszy
 * @return true zwraca gdy wolne
 * @return false zwraca gdy zajete
 */
bool Board::available(int x, int y) const {
    return check(x, y);
}


/**
 * @brief Funkcja sprawdza czy jest wolne miejsce na planszy
 * 
 * @return true jezeli jest zapelniona
 * @return false jezeli jest miejsce
 */
bool Board::isFull() const {
    for (int x = 1; x < size+1; x++) {
        for(int y = 1; y < size+1; y++)
            if(!available(x, y))
                return false;
    }
    return true;
}

/**
 * @brief Funkcja sprawdzajaca aktualny stan gry 
 * 
 * @return int zwraca czy gracz/komputer osiagnal ilosc znakow w jednej linii po liniach prostych/przekatnych
 */
int Board::current() const {
    int player_counter;
    int ai_counter;

    // pion
        for(int y = 0; y < size; y++){
            player_counter = ai_counter = 1;
            for(int x = 0; x < size - 1; x++){
                if(entries[x][y] == entries[x + 1][y]){
                    if (entries[x][y] == player_symbol)
                        player_counter++;
                    else if (entries[x][y] == ai_symbol)
                        ai_counter++;
                    if (player_counter == to_win)
                        return 1;
                    if (ai_counter == to_win)
                        return -1;
                }
            }
        }

    // poziom
    for(int x = 0; x < size; x++) {
        player_counter = ai_counter = 1;
        for(int y = 0; y < size - 1; y++) {
            if(entries[x][y] == entries[x][y + 1]){
                if (entries[x][y] == player_symbol)
                    player_counter++;
                else if(entries[x][y] == ai_symbol)
                    ai_counter++;
                if(player_counter == to_win)
                    return 1;
                if(ai_counter == to_win)
                    return -1;
            }
        }
    }

    // przekatne
    for(int x = 1; x < size - to_win + 1; x++){
        player_counter = ai_counter = 1;
        for(int y = 0; y < (size - x - 1); y++){
            if(entries[y][x + y] == entries[y + 1][x + y + 1]){
                if (entries[y][x + y] == player_symbol)
                    player_counter++;
                else if (entries[y][x + y] == ai_symbol)
                    ai_counter++;
                if (player_counter == to_win)
                    return 1;
                if (ai_counter == to_win)
                    return -1;
            }
        }
    }
    for(int x = 0; x < size - to_win + 1; x++){
        player_counter = ai_counter = 1;
        for(int y = 0; y < (size - x - 1); y++){
            if(entries[x + y][y] == entries[x + y + 1][y + 1]){
                if(entries[x + y][y] == player_symbol)
                    player_counter++;
                else if(entries[x + y][y] == ai_symbol)
                    ai_counter++;
                if(player_counter == to_win)
                    return 1;
                if(ai_counter == to_win)
                    return -1;
            }
        }
    }
    for(int x = 0; x < size - to_win + 1; x++){
        player_counter = ai_counter = 1;
        for(int y = 0; y < (size - x - 1); y++){
            if(entries[size - 1 - y][x + y] == entries[size - 1 - (y + 1)][x + y + 1]){
                if(entries[size - 1 - y][x + y] == player_symbol)
                    player_counter++;
                else if(entries[size - 1 - y][x + y] == ai_symbol)
                    ai_counter++;
                if(player_counter == to_win)
                    return 1;
                if(ai_counter == to_win)
                    return -1;
            }
        }
    }
    for(int x = 1; x < size - to_win + 1; x++){
        player_counter = ai_counter = 1;
        for(int y = 0; y < (size - x - 1); y++){
            if(entries[size - 1 - x - y][y] == entries[size - x - y - 2][y + 1]){
                if(entries[size - 1 - x - y][y] == player_symbol)
                    player_counter++;
                else if(entries[size - 1 - x - y][y] == ai_symbol)
                    ai_counter++;
                if(player_counter == to_win)
                    return 1;
                if(ai_counter == to_win)
                    return -1;
            }
        }
    }
    return 0;
}

/**
 * @brief Funkcja setujaca w odpowiednim miejscu planszy
 * 
 * @param x wspolrzedna x na planszy
 * @param y wspolrzedna y na planszy
 */
void Board::set(int x, int y) 
{
    if(x >= 1 && x <= size && y >= 1 && y <= size){
        if(turnCheck()){
            entries[x - 1][y - 1] = player_symbol;
        }
        else{
            entries[x - 1][y - 1] = ai_symbol;
        }
    }
}