/*
* File:	main.cpp
* Author:	Jeremy Bickford
* Course:	CSCI 3110
* Instructor:	Zhijiang Dong
* Date:	NOV 16 2016
* This is the client file that uses the class word check to search dictionary for near misses
*
*/
#include "wordChecker.h"
#include <string>
#include <iostream>
using namespace std;

const string    FileName = "dict.txt";

int main()
{	
	wordChecker dictionary(FileName);
	
	string input;
	
	while(true)
	{	
		cout << "Enter a value to search: ";
		cin >> input;
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);// makes input lower case
		dictionary.wordSearch(input);
		cout << endl;
	}
	system("PAUSE");
	return 0;
}

