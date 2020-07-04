#include <stdio.h>

#include "game.h"

int p_hand ;
int b_hand ;
int n_hand ;

int main()
{
    t_game * g = game_init();

    game_loop(g);
    return 0;
}

void game_loop(t_game * g)
{

print_player_coins(g->player);
broker_new_hand(g);
player_new_hand(g);
print_player_hand(g->player);
p_hand = sum_player_hand(g->player);
broker_place_bet(g);
player_place_bet(g); 
print_turn_results(g, p_hand);

n_hand = player_ask_cards(g);

if (p_hand > 21)
 {
  player_lost(g);
 }

if (p_hand > g->broker)
{
 player_win(g);
}
  
              
if (p_hand == 21)
{
 player_win(g);
}
        
}





