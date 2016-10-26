/*
* File:	Main.cpp
* Author:	Jeremy Bickford
* Course:	CSCI 3110
* Instructor:	Zhijiang Dong
* Date:	Sep. 15 2016
* This program use a player class, card class, and a deck class to play a game of war.
*/
#include "Card.h"
#include "Player.h"
#include "Deck.h"
#include <iostream>

using namespace std;
void playGame(Player& p1, Player& p2, Deck cardDeck);
void printResults(Card one, Card two, Player& p1, Player& p2);

int main()
{
	int x;
	Player Player1("Player One");//initalize all class var
	Player Player2("Player Two");
	Deck cardDeck;

	cout << "The orignal deck has the following cards\n" << cardDeck<<endl;//Shows all cards are there
	cardDeck.Shuffle();
	cout << "After shuffle the deck has the following cards\n" << cardDeck<<endl;

	Player1.drawCard(cardDeck);//fill hands with cards
	Player2.drawCard(cardDeck);
	playGame(Player1, Player2, cardDeck);
	
	if(Player1.total()>Player2.total())// print winner according to scores
	{
		cout << Player1.getName() << " wins with a total of " << Player1.total() << endl;
	}
	else
	{
		cout << Player2.getName() << " wins with a total of " << Player2.total() << endl;
	}
	system("Pause");
	return 1;
	;
}

void playGame(Player& p1, Player& p2, Deck cardDeck)
{
	int count=1;//round ounter
	Card playedOne, playedTwo;
	while(count<27)
	{
		
		cout << "*************** Hand " << count << "***************\n";
		cout << p1 << " with score " << p1.total()<<"\n";
		cout << p2 << " with score " << p2.total()<< "\n\n";
		playedOne = p1.playCard();
		playedTwo = p2.playCard();
		cout << p1.getName() << " played card: " << playedOne << " ---"<<p2.getName()<< " played card: " << playedTwo << "\n\n";
		printResults(playedOne, playedTwo, p1, p2);
		cout << p1 << " with score " << p1.total() << "\n";
		cout << p2 << " with score " << p2.total() << "\n\n";
		p1.drawCard(cardDeck);//refills hand or attempts if deck if empty
		p2.drawCard(cardDeck);
		++count;
		
	}
	return;
}
//Prints and adds scores accordingly
void printResults(Card one, Card two,Player& p1, Player& p2)
{
	if(one>two)
	{
		cout << p1.getName() << " takes this hand\n";
		p1.addScore(one);
		p1.addScore(two);
		return;
	}
	if(one<two)
	{
		cout << p2.getName() << " takes this hand\n";
		p2.addScore(one);
		p2.addScore(two);
	}
	else
	{
		cout << "Cards are the same\n";
		p1.addScore(one);
		p2.addScore(two);
	}
	return;
}