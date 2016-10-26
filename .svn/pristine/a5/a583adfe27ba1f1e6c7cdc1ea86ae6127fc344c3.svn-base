/*
* File:	Card.cpp
* Author:	Jeremy Bickford
* Course:	CSCI 3110
* Instructor:	Zhijiang Dong
* Date:	Sep. 15 2016
* This program handles the numbers to the  cards
*/
#include "Card.h"
#include <iostream>
#include <string>
#include <ctime>

Card::Card()
{
};


Card::Card(int faceValue, suite type): faceValue(faceValue), type(type)
{
	switch (faceValue) 
		{
		case(1): pointValue = 15;
			break;
		case(11): pointValue = 10;
			break;
		case(12):pointValue = 10;
			break;
		case(13):pointValue = 10;
			break;
		default:pointValue = faceValue;
	}
};


int Card::getPointValue() const
{
	return pointValue;
}

bool Card::operator== (const Card& cd) const
{
	return (faceValue == cd.faceValue && (type == cd.type));
}

bool Card::operator < (const Card& cd) const
{
	return (pointValue < cd.pointValue);

}

bool Card::operator > (const Card& cd) const
{
	return (pointValue > cd.pointValue);
}
 ostream& operator << (ostream& os, const Card& cd)
{
	switch (cd.faceValue)//Changes int face values to letter if 11-13
	{
	case(1):os << 'A';
		break;
	case(11):os << 'J';
		break;
	case(12): os << 'Q';
		break;
	case(13): os << 'K';
		break;
	default: os << cd.faceValue;
	}

	switch (cd.type)// print symbol based on enum value
	{
	case(0):
		os << (char)0x05; //print Club symbol;
		break;
	case(1):
		os << (char)0x03; //print Heart symbol  
		break;
	case(2):
		os << (char)0x06; //print Spade symbol 
		break;
	case(3):
		os << (char)0x04; //print Diamond symbol
		break;
	default:
		std::cerr << "Error invaid suite";
	}
	os << "[" << cd.pointValue << "]";
	return os;
};