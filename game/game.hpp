// B. Maritza Trevizo Nava

#include "deck.hpp"
#include "player.hpp"
#include "pile.hpp"

#pragma once

// Game options
struct Options {
  int num_decks = 1;
  bool ace_high = true;
  int num_sacrifice = 1;
  bool negotiable_sacrifice = true;
};


// Game structure
struct Game {
  Options options;
  Deck deck;
  Player p1;
  Player p2;
  Pile pile;
  int turn;
};
