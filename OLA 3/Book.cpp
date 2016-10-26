/*
* File:Book.cpp
* Author:	Jeremy Bickford
* Course:	CSCI 3110
* Instructor:	Zhijiang Dong
* Date:	oct. 12 2016
* This program is  the implementtation used for the Book class.
*/
#include "Book.h"

Book::Book(std::string title, std::string author, std::string publishDate,std::string barcode , double price , int copy , int demand ): 
m_title(title), m_author(author), m_publishDate(publishDate), StoreItem(barcode,price, copy, demand)
{};


std::string Book::getAuthor() const
{
	return m_author;
}

std::string Book::getDate() const
{
	return m_publishDate;
}

std::string Book::getTitle() const
{
	return m_title;
}


//This function returns a dynamically created StoreItem object
//which is created from a string.
//The string info must be of the line format specificed in
//inventory.txt
Book* Book::createFromString(const std::string info)
{
	std::string title, author, date, barcode,temp;
	int copy, demand;
	double price;
	std::stringstream	ss(info);
	std::getline(ss, barcode, DELIMITER);
	std::getline(ss, title, DELIMITER);
	std::getline(ss, author, DELIMITER);
	std::getline(ss, date, DELIMITER);
	std::getline(ss, temp, DELIMITER);
	std::istringstream(temp) >> price;
	std::getline(ss, temp, DELIMITER);
	std::istringstream(temp) >> copy;
	std::getline(ss, temp, DELIMITER);
	std::istringstream(temp) >> demand;
	Book *bookptr;
	bookptr= new Book(title, author,date, barcode, price, copy, demand);
	
	return bookptr;
}


//Print current item to the screen
void Book::printItem()
{
	std::cout << std::string(24, '*') << " Book with barcode " << m_barcode << " " << std::string(24, '*') << std::endl;
	std::cout << std::left << std::setw(13) << "Title:" << m_title << std::endl;
	std::cout << std::setw(13) << "Author:" << m_author << std::endl;
	std::cout << std::setw(13) << "Publish date:" << m_publishDate << std::endl;
	std::cout << std::setw(13) << "Price:" << getPrice() << std::endl;
	std::cout << std::setw(13) << "# of copies:" << m_copy << std::endl;
	std::cout << std::setw(13) << "# of demand:" << m_demand << std::string(2, '\n');
}

std::string Book::getType()
{
	return "Book";
}
