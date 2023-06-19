#include "../inc/game_ai.h"

#include <algorithm>  
#include <limits>

int infinity = std::numeric_limits<int>::max();


/**
 * @brief Algorytm min_max z alfa beta ciecie
 * 
 * @param Game plansza do gry
 * @param depth glebokosc rekursji
 * @param alpha alfa
 * @param beta beta
 * @param maximizing max
 * @return int 
 */
int Game_ai::min_max(Game game, int depth, int alpha, int beta, bool maximizing) const 
{
    int game_status = game.current();
    
    if(game_status != 0 || game.fullCheck() || depth == 0)
    {
        return game_status;
        }
    if(maximizing){
        int max = -infinity;
        for(int i = 1; i <= game.getSize(); i++) 
            for(int j = 1; j <= game.getSize(); j++) 
                if(!game.available(i, j) && depth >= 0)
                {
                    game.changeTurn(1);
                    game.set(i, j);
                    max = std::max(max, min_max(game, depth - 1, alpha, beta, false));
                    game.remove(i, j);
                    alpha = std::max(alpha, max);
                    if(alpha >= beta)
                    {
                        return alpha;
                        }
                }
        return max;
    }
    else{
        int min = infinity;
        for(int i = 1; i < game.getSize() + 1; i++) 
            for(int j = 1; j < game.getSize() + 1; j++) 
                if(!game.available(i, j) && depth >= 0 )
                {
                    game.changeTurn(0);
                    game.set(i, j);
                    min = std::min(min, min_max(game, depth - 1, alpha, beta, true));
                    game.remove(i, j);
                    beta = std::min(beta, min);
                    if(beta <= alpha)
                        {
                        return beta;
                        }
                }
        return min;
    }
}


/**
 * @brief Funkcja ruchu ai
 * 
 * @param game plansza do gry
 */
void Game_ai::move(Game game)
{
    int current=0;
    int best = infinity;
    for(int i = 1; i <= game.getSize(); i++) 
        for(int j = 1; j <= game.getSize(); j++) 
            if(!game.available(i, j)) 
            {
                game.changeTurn(0);
                game.set(i, j);
                current = min_max(game, depth_limit, -infinity, infinity, true);
                game.remove(i, j);
                if(current <= best) 
                {
                    x = i;
                    y = j;
                    best = current;
                }
            }
}




