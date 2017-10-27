// B. Maritza Trevizo Nava
#pragma once
#include <iostream>
#include <algorithms>
#include <random>
#include <chrono>

enum Rank {
	Ace,
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

enum Suit {
	Heart,
	Diamond,
	Spade,
	Club,
};

enum Color {
	Red,
	Black,
};

struct Card {
	virtual void print() const
	{
		throw std::logic_error("INVALID");
	}
};

struct SuitedCard : Card {
	Rank rank;
	Suit suit;


	SuitedCard(Rank r, Suit s) {
              rank = r;
              suit = s;

	}
	void SuitedCard::print() const override
	{
		std::cout << rank << ' ' << suit << endl;

	}
};

struct JokerCard : Card {
	Color color;
	JokerCard(Color c) {
		color = c;
        }

	void JokerCard::print() const override
	{
		std::cout << color << endl;
	}
};


using std::vector<Card*> = Deck;

// Create a standard deck
Deck make_deck() {
	Deck myDeck;
	for(int s=Heart; s<=Club; ++s){
		for(int r=Ace; r<=King; ++r){
			Rank rank = static_cast<Rank>(r);
                        Suit suit = static_cast<Suit>(s);
                        SuitedCard* card_ptr = new SuitedCard(rank, suit);
			myDeck.push_back(card_ptr);

		}
	}

	// Create two jokers
	JokerCard* blk_ptr = new JokerCard(Black);
        JokerCard* red_ptr = new JokerCard(Red);
        myDeck.push_back(blk_ptr);
        myDeck.push_back(red_ptr);

        return myDeck;

}

int main() {
	Deck myDeck = make_deck();
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        // Shuffle deck
	std::shuffle(myDeck.begin(), myDeck.end(), std::default_random_engine(seed));

}
