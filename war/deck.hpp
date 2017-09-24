// B. Maritza Trevizo Nava

#include "card.hpp"
#include <vector>


// Vector of cards representing a deck of cards
using Deck = std::vector<Card>;

// Make standard deck of cards
Deck make_standard_deck();

// Combine two decks of cards
Deck make_combined_deck(const Deck& d1, const Deck& d2);

// Shuffle deck of cards
void shuffle(Deck& d);

// Print deck of cards
void print(const Deck& d);


// Call deck functions
// Deck d;
// d.shuffle();
// d.sort();
