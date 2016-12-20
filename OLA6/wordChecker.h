#pragma once
/*
* File:	wordChecker.h
* Author:	Jeremy Bickford
* Course:	CSCI 3110
* Instructor:	Zhijiang Dong
* Date:	NOV 16 2016
* This file is the header file for a class of functions to search through a unsorted map.
* 
 */
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <fstream>

class wordChecker
{
public:
	wordChecker(std::string file);

	//Construct every string that can be made by deleting one letter from the word. 
	//(n possibilities, where n is the length of the word)
	void letterDelete(std::string input, int& count, std::unordered_map<std::string, bool >&);

	//Construct every string that can be made by inserting any letter of the alphabet at any position in the string.
	//(26 * (n + 1) possibilities)
	void letterInsert(std::string input, int& count, std::unordered_map<std::string, bool >&);

	//Construct every string that can be made by replacing each letter in the word with some letter of the alphabet. 
	//(26 * n possibilities(including the original word n times, which is probably easier than avoiding it))
	void letterReplace(std::string input, int& count, std::unordered_map<std::string, bool >&);

	//Construct every pair of strings that can be made by inserting a space into the word. 
	//(n - 1 pairs of words; you have to check separately in the dictionary for each word in the pair)
	void wordsplit(std::string input, int& count, std::unordered_map<std::string, bool >&);
	// Construct every string that can be made by swapping two neighboring characters in the string. 
	//(n - 1 possibilities)
	void letterSwap(std::string input, int& count, std::unordered_map<std::string, bool >&);
	//uses all string modifers to search for possible misses
	void wordSearch(std::string word);
	//searches map for word
	int findOneWord(std::string word, int& count);
	
private:
	std::unordered_map<std::string, int> map;
	void readFile(std::string FileName);


};
