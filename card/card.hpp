// B. Maritza Trevizo Nava

#pragma once
#include <utility>
#include <iosfwd>

// Ranks of a card are:
// ace, 2-10, jack, king, and queen.
// Suits of a card are:
// hearts, diamonds, clubs, spades

// Card ranks represented as numbers
enum Rank {
  Ace = 1,
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  Jack,
  Queen,
  King,
};

// Every card has a suit
enum Suit {
  Hearts,
  Diamonds,
  Clubs,
  Spades,
};

// Every card has one rank and one suit
class Card {
public:
  // Default constructor
  Card() {}

  // Construct a card with a rank and a suit
  Card(Rank r, Suit s) {
    rank = r;
    suit = s;
  }

  // Copy constructor
  Card(const Card& c){
    rank = c.rank;
    suit = c.suit;
  }

  // Setters
  void set_rank(Rank ra) { rank = ra; }
  void set_suit(Suit su) { suit = su; }

  // Getters
  Rank get_rank() const { return rank; }
  Suit get_suit() const { return suit; }

private:
  Rank rank;
  Suit suit;
};

// Equality comparison
bool operator==(Card a, Card b);
bool operator!=(Card a, Card b);

// Ordering
bool operator<(Card a, Card b);
bool operator>(Card a, Card b);
bool operator<=(Card a, Card b);
bool operator>=(Card a, Card b);

// Outputting
std::ostream& operator<<(std::ostream& os, Card c);
std::ostream& operator<<(std::ostream& os, Rank r);
std::ostream& operator<<(std::ostream& os, Suit s);
