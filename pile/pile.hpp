// Maritza Trevizo

#include "deck.hpp"

class Pile {
public:
  // Default constructor
  Pile() {
    //temp_pile = new Deck();
  }

  // Setters
  void set_pile(Deck &my_pile) {
    my_pile.insert(my_pile.begin(), temp_pile.begin() , temp_pile.end());
  }

  // Getters
  Deck get_pile() const { return temp_pile; }

private:
  Deck temp_pile;

};
