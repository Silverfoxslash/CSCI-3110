

/*
* File:	Main.cpp
* Author:	Jeremy Bickford
* Course:	CSCI 3110
* Instructor:	Zhijiang Dong
* Date:	Oct. 06 2006
*
* Purpose: This file is a part of the 1st open lab assignment, which
* includes Student.h, Student.cpp, Roster.h, Roster.cpp,
* and main.cpp. This file gives outputs a menu for reading a class list and scores or to search for one student using two user defined classes.
*/


#include <stdio.h>
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Roster.h"
using namespace std;
void displayMenu();

int main()
{
	Roster studentlist("3110");//initiate roster
	studentlist.readStudentRecord("point.dat");


	char input=NULL;
	string searchInput;
	while (toupper(input) != 'Q')
	{

			displayMenu();
			cout << "Please enter a command(I, L, Q):";
			cin >> input;
			cout << endl;
			
		switch (toupper(input))
			{
			case('I'): cout << "Pleae enter the student's c-number:";
				cin >> searchInput;
				studentlist.searchStudent(searchInput);
				break;
			case('L'): studentlist.printClass();
				break;
			default:
				break;

			}
		cin.ignore();
		}
	
	return 0;
}
void displayMenu()
{
	string stars(31, '*');
	cout << stars << "MAIN MENU" << stars << endl;
	cout << left << setw(70) << "| COMMAND     DESCRIPTION" << "|" << endl;
	cout << setw(70) << "| I           Display a student's information by an id" << "|" << endl;
	cout << setw(70) << "| L           List the entire class" << "|" << endl;
	cout << setw(70) << "| Q           Quit the program" << "|" << endl;
	cout << stars << stars << "*********\n";
}
