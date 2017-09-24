// B. Maritza Trevizo Nava

#include "card.hpp"
#include "deck.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm>

std::random_device rng;
std::minstd_rand prng;

int main() {
  // Create random numbers from seed
  prng.seed(rng());

  // Create two standard decks and one combined deck
  Deck d1 = make_standard_deck();
  Deck d2 = make_standard_deck();
  Deck d3 = make_combined_deck(d1, d2);


  // Print cards of combined deck
  print(d3);
  // Shuffle cards of combined deck
  shuffle(d3);
  // Print again
  print(d3);


  return 0;
}
