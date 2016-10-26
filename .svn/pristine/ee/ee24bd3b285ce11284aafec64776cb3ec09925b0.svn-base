/*
* File:	Deck.cpp
* Author:	Jeremy Bickford
* Course:	CSCI 3110
* Instructor:	Zhijiang Dong
* Date:	Sep. 15 2016
* This program creats a deck of 52 cards and deals as requested
*/
#include "Deck.h"
#include <iostream>

#include <ctime>

using namespace std;

Deck::Deck()
{
	topCard = 0;// uses nested loop for suites and facevalues
	for (int s = 0; s < 4; s++)
	{
		for (int v = 1; v <= 13; v++)
		{
			theDeck[topCard] = Card(v, static_cast<suite>(s));
			topCard++;
		}
	}
}
bool Deck::isEmpty()
{
	bool empty = true;
	if (topCard != 0)
	{
		empty = false;
	}

	return empty;
}


Card Deck::dealCard()//pulls out top of deck
{
	Card c;

	if (topCard > 0)
	{
		c = theDeck[topCard-1];
		--topCard;
	}
	else
	{
		cerr << "Cannot add card from an empty deck.";
	}
	return c;
}



void Deck::Shuffle()//swaps two random places in the deck 100 times
{

	srand(time(NULL));//uses time as a seed number
	int x, rand1, rand2;
	Card temp;
	for (x = 0; x < 100; x++)
	{
		rand1 = rand() % 52;//random number1
		rand2 = rand() % 52;//random number2

		temp = theDeck[rand1];//swaps the card indexes
		theDeck[rand1] = theDeck[rand2];
		theDeck[rand2] = temp;
	}
}
 ostream &operator<<(ostream& output, const Deck& deck)// loops through every index and prints each card
{
	for (int x = 0; x < deck.topCard; ++x)
	{
		output << deck.theDeck[x] << "  ";
		if (x % 9 == 0 && x!=0)
			output << std::endl;
	}
	output << std::endl;
	return output;
}
