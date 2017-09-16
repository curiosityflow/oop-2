// B. Maritza Trevizo Nava

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


  // // Mutator functions.
  // // Modifier functions.
  //
  // Don't provide mutators if they're just assignment.
  // Prefer to make things public (unless your boss says
  // otherwise).
  //
  // void set_rank(Rank r) { rank = r; }
  // void set_suit(Suit s) { suit = s; }


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

std::ostream& operator<<(std::ostream& os, Card c);
std::ostream& operator<<(std::ostream& os, Rank r);
std::ostream& operator<<(std::ostream& os, Suit s);


// /// A member function is kind of like a normal function.
// /// It is (roughly) equivalent to this:
// ///
// /// NOTE: Not valid C++ (because this is reserved word).
// Rank get_rank(const Card* this) {
//   return this->rank;
// }
