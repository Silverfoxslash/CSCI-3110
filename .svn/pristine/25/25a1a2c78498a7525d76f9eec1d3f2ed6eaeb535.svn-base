/*
* File:	Main.cpp
* Author:	Jeremy Bickford
* Course:	CSCI 3110
* Instructor:	Zhijiang Dong
* Date:	oct. 12 2016
* This program uses a file input to build moive and book objects, store in a list and allows user to search and display items.
*/
#include <typeinfo>
#include "Book.h"
#include  "Movie.h"
#include  <fstream>
#include <list>
#include "StoreItem.h"
#include <stdlib.h>

void printList( std::list<StoreItem*>&storeList);
void buildList(StoreItem* item, std::list<StoreItem*>& storeList);
void intalizeList(std::list<StoreItem*>& storeList);
void menuDisplay();
void returnItem(std::list<StoreItem*>&storeList);
void checkout(std::list<StoreItem*>&storeList);
void printOneTitle( std::list<StoreItem*>& storeList);
void printOneAuthor(std::list<StoreItem*>&storeList);

void main()
{
	std::list<StoreItem*> storeList;
	intalizeList(storeList);
	char userInput=NULL;
	while(userInput != 'Q')
	{	
		menuDisplay();
		std::cin >> userInput;
		std::cin.ignore();//in case more thn one button is hit
		userInput = toupper(userInput);
		switch (userInput)
		{
		case('M'): printOneTitle(storeList);
			break;
		case('B'): printOneAuthor(storeList);
				break;
		case('L'):printList(storeList);
			break;
		case('R'): returnItem(storeList);
			break;
		case('C'): checkout(storeList);
			break;
			
		

		}
	}
	exit(0);



}



//opens file and builds list and returns
void intalizeList(std::list<StoreItem*>& storeList)
{
	Book bookClass;//initalize objects for creating list
	Movie movieClass;
	Book* tempBook;
	Movie* tempMovie;
	std::ifstream inputFile;
	inputFile.open("inventory.txt");
	if (inputFile.fail())//if file open fails close it
	{
		std::cout << "file opening failed" << std::endl;
		system("PAUSE");
		exit(1);
	}

	std::string itemType, itemInfo;
	;
	std::list<StoreItem*>::iterator it;//used for comparing values

	while (inputFile.good())
	{
		std::getline(inputFile, itemType, '|');//ignores first delim
		std::getline(inputFile, itemType, '|');
		std::getline(inputFile, itemInfo);
		if (itemType == "Movie")//checks if movie or book info
		{
			tempMovie = movieClass.createFromString(itemInfo);
			buildList(tempMovie, storeList);
		}
		else
		{
			tempBook = bookClass.createFromString(itemInfo);
			buildList(tempBook, storeList);
		}
	}
	inputFile.close();
		
}
//sorts list in ascending order
void buildList(StoreItem* item, std::list<StoreItem*>& storeList)
{
	std::list<StoreItem*>::iterator it;
	for (it = storeList.begin(); it != storeList.end(); ++it)
	{
		if (*item< **it)
		{
			storeList.insert(it, item);//insers when not greater than other items in list
			break;
		}
	}
	if (it == storeList.end())
		storeList.push_back(item);//add to end if not less than any
	return;
}
//prints every item in list
void printList( std::list<StoreItem*>&storeList)
{
	std::list<StoreItem*>::iterator it;
	for (it = storeList.begin(); it != storeList.end(); ++it)
	{
		(*it)->printItem();
	}

	system("PAUSE");
	return;
}

void menuDisplay()
{
	std::cout << std::right<< std::setw(30)<<"Mini Movie Store" << std::endl;
	std::cout <<std::left<< std::string(53, '*') << std::endl;
	std::cout  << std::setw(12) << "* Command" << std::setw(40) << "Description" << "*\n";
	std::cout  << std::setw(12) << "* M" << std::setw(40) << "Inquire about item by title" << "*\n";
	std::cout  << std::setw(12) << "* B" << std::setw(40) << "Inquire about item by author or director" << "*\n";
	std::cout  << std::setw(12) << "* L" << std::setw(40) << "List inventory" << "*\n";
	std::cout  <<std::setw(12) << "* R" << std::setw(40) << "Return one Item" << "*\n";
	std::cout  << std::setw(12) << "* C" << std::setw(40) << "Checkout one Item" << "*\n";
	std::cout  << std::setw(12) << "* Q" << std::setw(40) << "Quit the main menu" << "*\n";
	std::cout << std::string(53, '*') << std::endl;
	std::cout << "Please enter your command (M, B, L, R, C, Q):";
}
//search by title and print that one item
void printOneTitle( std::list<StoreItem*>& storeList)
{
	Movie	defaultMovie;	// a movie object
	Book		defaultBook;	// a book object
	std::string userInput;
	std::cout << "Enter a title:";
	std::cin.ignore();
	std::getline(std::cin, userInput);
	std::list<StoreItem*>::iterator it;
	for (it = storeList.begin(); it != storeList.end(); ++it)
	{

		std::string a = "Movie", b = "Book";
		if ((*it)->getType() == a)
		{
			if (static_cast<Movie*>(*it)->getTitle() == userInput)
			{
				(*it)->printItem();
				return;
			}
		}
		else if ((*it)->getType()== b)
		{
			if (static_cast<Book*>(*it)->getTitle() == userInput)
			{
				(*it)->printItem();
				return;
			}
		}
		
	}
	std::cout << "Could not find " << userInput << std::string(2, '\n');
}
//searchs by a barcode and increase copy of that item
void returnItem(std::list<StoreItem*>&storeList)
{

	std::string userInput;
	std::cout << "Enter a barcode Number:";
	std::cin >> userInput;
	std::list<StoreItem*>::iterator it;
	for (it = storeList.begin(); it != storeList.end(); ++it)
	{
		if((*it)->getBarcode()==userInput)
		{
			(*it)->increaseCopy();
			std::cout << "Item return sucessfully.\n";
			return;
		}

	}
	std::cout << "Could not find " << userInput << std::string(2, '\n');
	return;

}
//search by barcode and decrease copies of that item
void checkout(std::list<StoreItem*>&storeList)
{
	std::string userInput;
	std::cout << "Enter a barcode Number:";
	std::cin >> userInput;
	std::list<StoreItem*>::iterator it;
	for (it = storeList.begin(); it != storeList.end(); ++it)
	{
		if ((*it)->getBarcode() == userInput)
		{
			(*it)->decreaseCopy();
			std::cout << "Item checked out sucessfully.\n";
			return;
		}

	}
	std::cout << "Could not find " << userInput << std::string(2, '\n');
	return;
}
//search by a author or director and print that one item
void printOneAuthor(std::list<StoreItem*>&storeList)
{
	Movie	defaultMovie;	// a movie object
	Book		defaultBook;	// a book object
	std::string userInput;
	std::cout << "Enter a Author or director:";
	std::cin.ignore();
	std::getline(std::cin, userInput);
	std::list<StoreItem*>::iterator it;
	for (it = storeList.begin(); it != storeList.end(); ++it)//loops and checks for a sub string in each author
	{
		std::string a = "Movie", b = "Book";
		if ((*it)->getType() == a)
		{
			if ((static_cast<Movie*>(*it)->getDirector()).find(userInput)!=std::string::npos)//only prints if it finds one
			{
				(*it)->printItem();
				return;;
			}
		}
		else if ((*it)->getType()==b)
		{
			if (static_cast<Book*>(*it)->getAuthor().find(userInput) != std::string::npos)
			{
				(*it)->printItem();
				return;
			}
		}
	}
	std::cout << "Could not find " << userInput << std::string(2,'\n');
}