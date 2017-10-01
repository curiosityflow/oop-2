// B. Maritza Trevizo Nava

#include "deck.hpp"

class Player {
public:
  // Default constructor
  Player() {}

  // Players needs a deck of cards
  Player(Deck &d) {
    deck = d;
  }

  Card drawCard(Deck &my_deck);
  Deck placeOnTempPile(Deck &my_temp_pile);

private:
  Deck deck;
  Deck temp_pile;
};
