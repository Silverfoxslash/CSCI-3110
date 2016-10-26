/*
* File:	Player.cpp
* Author:	Jeremy Bickford
* Course:	CSCI 3110
* Instructor:	Zhijiang Dong
* Date:	Sep. 15 2016
* This program dictates how drawing cards, scoring and printing hands is handled
*/
#include "Player.h"

Player::Player(string name): name(name), score(0)
{
	for(int x=0; x<3;++x)
	{
		played[x] = true;
	}
};


// The player removes one card from his hand
// and return it.
// You can use whatever stratge you want here such as
// choose a card randomly, choose the largest card,
// choose the first card, or other more complicated algorithm
Card Player::playCard()
{
	Card card = hand[0];// zeros ou last car in hand
	if(played[1]==true)
	{
		played[0] = true;
	}
	if (played[2] == false)//always happens if deck has cards
	{
		hand[0] = hand[1];
		hand[1] = hand[2];
		played[2] = true;
	}
	else //happens when desk is empty
	{
	hand[0] = hand[1];
	played[1] = true;
	}

	
	return card;
};

// The player gets one card from the deck
void Player::drawCard(Deck& dk)
{
	int count = 0;
	if (!dk.isEmpty())
	{
		if (played[0] == true)
		{
			hand[0] = dk.dealCard();
			played[0] = false;
		}

		if (played[1] == true)
		{
			hand[1] = dk.dealCard();
			played[1] = false;
		}
		if (played[2] == true)
		{
			hand[2] = dk.dealCard();
			played[2] = false;
		}
	}
	

	return;
};

// Add the point value of the card
// to the score of the player
void Player::addScore(Card acard)
{
	score += acard.getPointValue();
}

// Return the score the player has earned so far
int Player::total() const
{
	return score;
};

// return the name of the player
string Player::getName() const
{
	return name;
};

// Return true if no more cards in the player's hands,
// otherwise false
bool Player::emptyHand() const
{
	return (played[0] == true) && (played[1] == true) && (played[2] == true);
};

// overload the << operator to display all cards in player's hand
std::ostream& operator << (std::ostream& os, const Player& player)
{
	os << player.name << "'s hand:";
	if (player.played[0] == true)
	{
		os << "____";
	}
	else
		os << player.hand[0] << "  ";

	if (player.played[1] == true)
	{
		 os << "____";
	}
	else
		os << player.hand[1] << "  ";
	if (player.played[2] == true)
	{
		os << "____";
	}
	else
		os << player.hand[2];
	return os;
};