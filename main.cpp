// B. Maritza Trevizo Nava

#include "card.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm>

std::random_device rng;
std::minstd_rand prng;

// Prints deck of cards
void print_deck(const std::vector<Card>& deck) {
  int i = 1;
  // Loops through the deck of cards and prints out each card's content
  for (Card c : deck) {
    std::cout << c << ' ';
    if (i % 13 == 0) {
      std::cout << '\n';
      i = 0;
    }
    ++i;
  }
  std::cout << '\n';
}

// Checks if one card is greater than another
bool card_greater(Card a, Card b) {
  return a > b;
}

int main() {
  // rng(); // Can call as a function.
  // prng(); // Can call as a function.

 // Creates random numbers from seed
  prng.seed(rng());

  // std::uniform_int_distribution<> d6(1, 6);
  // std::bernoulli_distribution coin(.8);

  // for(int i = 0; i < 20; ++i) {
  //   int n = d6(prng);
  //   bool b = coin(prng);
  //   std::cout << n << ' ' << b << '\n';
  // }

  // Creates a deck of cards
  std::vector<Card> deck;
  // Creates 52 spaces
  deck.reserve(52);
  // Loops through all the ranks
  for (int s = Hearts; s <= Spades; ++s) {
    // Loops through all the suits
    for (int r = Ace; r <= King; ++r) {
      // Creates new card
      Card c{static_cast<Rank>(r), static_cast<Suit>(s)};
      // Adds card to the deck
      deck.push_back(c);
    }
  }

  // Prints deck
  print_deck(deck);

  // Randomly shuffles the cards and prints the deck
  std::shuffle(deck.begin(), deck.end(), prng);
  print_deck(deck);

  // Sorts and prints the deck of cards
  std::sort(deck.begin(), deck.end());
  print_deck(deck);

  // Randomly shuffles the deck of cards
  std::shuffle(deck.begin(), deck.end(), prng);
  // Sorts the deck
  std::sort(deck.begin(), deck.end(), [](Card a, Card b) {
    return a > b;
  });
  // Prints deck of cards
  print_deck(deck);

  // Randomly shuffles the deck of cards
  std::shuffle(deck.begin(), deck.end(), prng);
  // Sorts the deck
  std::sort(deck.begin(), deck.end(), card_greater);
  // Prints deck of cards
  print_deck(deck);

  // Randomly shuffles the deck of cards
  std::shuffle(deck.begin(), deck.end(), prng);
  // Sorts the deck
  std::sort(deck.begin(), deck.end(), [](Card a, Card b) {
    return a.get_suit() < b.get_suit();
  });
  // Prints deck of cards
  print_deck(deck);

  // Rank r1 = Two;
  // Rank r2 = Ace;
  // std::cout << std::boolalpha << (r1 == r2) << '\n';
  // std::cout << std::boolalpha << (r1 < r2) << '\n';

  // // Widening conversion. Okay.
  // int n = Jack;
  // std::cout << n << '\n';

  // // Narrowing conversion. Bad.
  // // Rank r3 = 4; // error: cannot convert.

  // // Initialize some cards.
  // Card c1 {Ace, Spades};
  // Card c2 {Four, Hearts};

  // // We should be able to do this.
  // Card c;

  // // Declaration, invokes a constructor to initialize
  // // an object (c3).
  // Card c3 = c1;

  // // Assignment (expression).
  // c1 = (c3 = c2);

  // // Create a deck of cards.
  // std::vector<Card> deck;
  // deck.reserve(52);
  // for (int s = Hearts; s <= Spades; ++s) {
  //   for (int r = Ace; r <= King; ++r) {
  //     Card c{static_cast<Rank>(r), static_cast<Suit>(s)};
  //     deck.push_back(c);
  //   }
  // }

  // // Range-base for loop.
  // for (Card c : deck) {
  //   // std::cout << c.get_rank() << ' ' << c.get_suit() << '\n';
  //   std::cout << c << '\n';
  // }

  // The code above expands (roughly) to this:
  // for (auto iter = deck.begin(); iter != deck.end(); ++iter) {
  //   Card c = *iter;
  // }
}
