/*
* File:	StoreItem.h
* Author:	Jeremy Bickford
* Course:	CSCI 3110
* Instructor:	Zhijiang Dong
* Date:	oct. 12 2016
* This program is a abstract class and includes the implementtation used for the base of other classes.
*/
# include "StoreItem.h"

StoreItem::StoreItem(std::string barcode, double price, int copy, int demand): m_barcode(barcode), m_price(price), m_copy(copy), m_demand(demand)
{
}

//Get movie title
std::string StoreItem::getBarcode() const
{
	return m_barcode;
}


//Get price
double StoreItem::getPrice() const
{
	return m_price;
}

//Get number of copies in the store
int StoreItem::getCopy() const
{
	return m_copy;
}


//Get number of copies to be ordered
int StoreItem::getDemand() const
{
	return m_demand;
}


//Increase # of copies by 1
//precondition: m_copy >= 0
void StoreItem::increaseCopy()
{	if(m_demand>0)
		decreaseDemand();
	else
		++m_copy;
		
}


//Decrease # of copies by 1
//precondition: m_copy > 0
void StoreItem::decreaseCopy()
{
	if (m_copy > 0)
		--m_copy;
	else
		increaseDemand();
}


//Increase # of copies to be ordered by 1
//precondition: m_copy == 0
void StoreItem::increaseDemand()
{	
	if (m_copy == 0)
		++m_demand;
}


//Decrease # of copies to be ordered by 1
//precondition: m_demand > 0
void StoreItem::decreaseDemand()
{
	if (m_demand > 0)
		--m_demand;

}


//Compare two store items. Return true if they have the same barcode,
//otherwise false.
bool StoreItem::operator==(const StoreItem& rhs) const
{
	return (m_barcode == rhs.m_barcode);
}

	
//Compare two store items by barcode
bool StoreItem::operator<(const StoreItem& rhs) const
{
	return (m_barcode < rhs.m_barcode);
}
