// Maritza Trevizo

#include "player.hpp"
#include <iostream>

// Player draws top card of deck
Card Player::drawCard(Deck &my_deck){
  Card top_card = my_deck.front();
  my_deck.pop_back();
  return top_card;
}

// Player places won cards on temporary pile
Deck Player::placeOnTempPile(Deck &my_temp_pile){
  temp_pile = my_temp_pile;
}
