/*
* File:	Book.h
* Author:	Jeremy Bickford
* Course:	CSCI 3110
* Instructor:	Zhijiang Dong
* Date:	oct. 12 2016
* This program is a object class that includes methods and members used to handle movies
*/
/*
* No methods are provided to modify book information.
* Movie information should be stable, whch means whenever
* you get a book object, you are not supposed to
* change book information such as title, and author.
*/
#ifndef BOOK_H
#define BOOK_H
#pragma message ("Bookobject is defined")
#include "StoreItem.h"


class Book : public StoreItem
{
public:
	//default constructor setting every thing to empty or 0
	Book(std::string title = "", std::string author = "",std::string pulishDate="", std::string barcode = "", double price = 0, int copy = 0, int demand = 0);

	std::string getTitle() const;

	std::string getAuthor() const;

	std::string getDate()const;

	//This function returns a dynamically created StoreItem object
	//which is created from a string.
	//The string info must be of the line format specificed in
	//inventory.txt
	Book* createFromString(const std::string info) override;

	//Print current item to the screen
	void printItem() override;
	std::string getType()override;

private:
	std::string m_title;        // book title
	std::string m_author;     // book author
	std::string m_publishDate; //publish date
};
#endif
