// B. Maritza Trevizo Nava

#include "card.hpp"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
  // Creating two ranks
  Rank r1 = Two;
  Rank r2 = Ace;

  // This is a test case
  // Compares first card's rank to second card's rank
  cout << boolalpha << (r1 == r2) << '\n';
  cout << boolalpha << (r1 < r2) << '\n';

  // This is a test case
  int n = Jack;
  cout << n << '\n';

  // Initializing two cards
  Card c1 {Ace, Spades};
  Card c2 {Four, Hearts};

  // Calling the default constructor
  Card c;

  // Calling the copy constructor
  Card c3 = c1;

  // Creates a deck of cards
  vector<Card> deck;
  // Creates 52 spots in the vector
  deck.reserve(52);
  // Assigns a rank and a suit for each card
  for (int r = Ace; r <= King; ++r) {
    for (int s = Hearts; s <= Spades; ++s) {
      // Constructs the card
      Card c{static_cast<Rank>(r), static_cast<Suit>(s)};
      // Places the created card onto the deck
      deck.push_back(c);
    }
  }

  // Displays the rank and suit of every card in the deck
  for (Card c : deck) {
    cout << c.get_rank() << ' ' << c.get_suit() << '\n';
  }

}
