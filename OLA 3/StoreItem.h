/*
* File:	StoreItem.h
* Author:	Jeremy Bickford
* Course:	CSCI 3110
* Instructor:	Zhijiang Dong
* Date:	oct. 12 2016
* This program is a abstract class used for the base of other classes.
*/
#pragma once
#ifndef STOREITEM_H
#define STOREITEM_H



#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
// assume the delimiter never appears in the book information
const char DELIMITER = '|';

class StoreItem
{
public:
	//default constructor setting every thing to empty or 0
	StoreItem(std::string barcode = "", double price = 0, int copy = 0, int demand = 0);

	//for debug purpose
	virtual ~StoreItem()
	{
		
	}

	//Get movie title
	std::string getBarcode(void) const;

	//Get price
	double getPrice(void) const;

	//Get number of copies in the store
	int getCopy(void) const;

	//Get number of copies to be ordered
	int getDemand(void) const;

	//Increase # of copies by 1
	//precondition: m_copy >= 0
	void increaseCopy(void);

	//Decrease # of copies by 1
	//precondition: m_copy > 0
	void decreaseCopy(void);

	//Increase # of copies to be ordered by 1
	//precondition: m_copy == 0
	void increaseDemand(void);

	//Decrease # of copies to be ordered by 1
	//precondition: m_demand > 0
	void decreaseDemand(void);

	//Compare two store items. Return true if they have the same barcode,
	//otherwise false.
	bool operator == (const StoreItem& rhs) const;

	//Compare two store items by barcode
	bool operator < (const StoreItem& rhs) const;

	//This function returns a dynamically created StoreItem object
	//which is created from a string.
	//The string info must be of the line format specificed in
	//inventory.txt
	virtual StoreItem* createFromString(const std::string info) = 0;
	//get type of object
	virtual std::string getType() = 0;
	//Print current item to the screen
	virtual void printItem() = 0;

protected:
	std::string m_barcode;  // bar code
	double       m_price;    // the retail price of the item
	int         m_copy;     // # of copies available in the store.
	int         m_demand;   // # of copies to be ordered};
};
#endif // !STOREITEM_H
