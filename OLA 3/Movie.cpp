/*
* File:	Movie.cpp
* Author:	Jeremy Bickford
* Course:	CSCI 3110
* Instructor:	Zhijiang Dong
* Date:	oct. 12 2016
* This program is the inplementation of the methods and members of movie class
*/
#include "Movie.h"

Movie::Movie(std::string title, std::string director, std::string barcode, double price, int copy, int demand):
m_title(title), m_director(director), StoreItem(barcode,price,copy,demand)
{
	
}

std::string Movie::getTitle() const
{
	return m_title;
}


std::string Movie::getDirector() const
{
	return m_director;
}


//This function returns a dynamically created StoreItem object
//which is created from a string.
//The string info must be of the line format specificed in
//inventory.txt
Movie* Movie::createFromString(const std::string info)
{


	std::string title, director, barcode,temp;
	int copy, demand;
	double price;
	std::stringstream	ss(info);

	std::getline(ss, barcode, DELIMITER);
	std::getline(ss, title, DELIMITER);
	std::getline(ss, director, DELIMITER);

	std::getline(ss, temp, DELIMITER);
	std::istringstream(temp) >> price;
	std::getline(ss, temp, DELIMITER);
	std::istringstream(temp) >> copy;
	std::getline(ss, temp, DELIMITER);
	std::istringstream(temp) >> demand;
	Movie* movieptr;
	movieptr = new Movie(title, director, barcode, price, copy, demand);
	return movieptr;
}

//Print current item to the screen
void Movie::printItem()
{
	std::cout << std::string(24, '*') << " Movie with barcode " << m_barcode << " " << std::string(24, '*') << std::endl;
	std::cout << std::left<< std::setw(13)<<"Title:"<< m_title<< std::endl;
	std::cout << std::setw(13) << "Director:"<<m_director<< std::endl;
	std::cout << std::setw(13) << "Price:"<< m_price<< std::endl;
	std::cout << std::setw(13) << "# of copies:"<< m_copy<< std::endl;
	std::cout << std::setw(13) << "# of demand:" << m_demand << std::endl<<std::endl;

}

std::string Movie::getType()
{
	return "Movie";
}
