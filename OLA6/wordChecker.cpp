/*
* File:	wordChecker.cpp
* Author:	Jeremy Bickford
* Course:	CSCI 3110
* Instructor:	Zhijiang Dong
* Date:	NOV 16 2016
* This file is the implementation file for a class of functions to search through a unsorted map.
*
*/
#include "wordChecker.h"

wordChecker::wordChecker(std::string file)
{
	wordChecker::readFile(file);
}

void wordChecker::letterDelete(std::string input, int& count, std::unordered_map<std::string, bool >& usedWords)
{
	int x;
	std::string word = input;
	for (x = input.length() - 1; x >= 0; --x)
	{
		input.erase(input.begin() + x);
		auto finder = usedWords.find(input);
		if (finder == usedWords.end())
		{
			usedWords[input] = true;
			findOneWord(word, count);
		}

		input = word;
	}
}


void wordChecker::letterInsert(std::string input, int& count, std::unordered_map<std::string, bool >& usedWords)
{
	int x;
	char letter;
	std::string word = input;
	for (x = 0; x <= input.length(); ++x)
	{
		for (letter = 'a'; letter <= 'z'; ++letter)
		{
			input.insert(x, 1, letter);

			auto finder = usedWords.find(input);
			if (finder == usedWords.end())
			{
				usedWords[input] = true;
				findOneWord(input, count);
			}
			input = word;
		}

	}
}

void wordChecker::letterReplace(std::string input, int& count, std::unordered_map<std::string, bool >& usedWords)
{
	int x;
	char letter;
	std::string word = input;
	for (x = 0; x <input.length(); ++x)
	{
		for (letter = 'a'; letter <= 'z'; ++letter)
		{
			input.replace(input.begin() + x, input.begin() + x + 1, 1, letter);
			auto finder = usedWords.find(input);
			if (finder == usedWords.end())
			{
				usedWords[input] = true;
				findOneWord(input, count);
			}
			input = word;
		}

	}
}

void wordChecker::wordsplit(std::string input, int& count, std::unordered_map<std::string, bool >& usedWords)
{
	int x;

	std::string word, word2, start = input;
	for (x = 1; x < input.length(); ++x)
	{
		word = input.substr(0, x);
		auto finder = usedWords.find(word);
		if (finder == usedWords.end())
		{
			usedWords[word] = true;
			findOneWord(word, count);
		}
		word2 = input.substr(x, input.length());

		finder = usedWords.find(word2);
		if (finder == usedWords.end())
		{
			usedWords[word2] = true;
			findOneWord(word2, count);
		}
	}
}

void wordChecker::letterSwap(std::string input, int& count, std::unordered_map<std::string, bool >& usedWords)
{
	int x;
	std::string word=input;
	for (x = 0; x < input.length()-1; ++x)
	{
		std::swap(word[x], word[x+1]);
		auto finder = usedWords.find(word);
		if (finder == usedWords.end())
		{
			usedWords[word] = true;
			findOneWord(input, count);
		}
		word = input;
	}
}

void wordChecker::wordSearch(std::string word)
{
	
	auto finder = map.find(word);
	if (!(finder == map.end()))
	{
		std::cout << "Ok\n";
		return;
	}
	std::unordered_map<std::string, bool > usedWords;//store searched words in map to avoid duplicate outputs
	usedWords[word] = true;
	int count = 0;
	letterDelete(word,count,usedWords);
	letterInsert(word, count,usedWords);
	letterReplace(word,count,usedWords);
	letterSwap(word, count,usedWords);
	if (count == 0)
		std::cout << "Not found.\n";
}

int wordChecker::findOneWord(std::string word, int& count)
{	
	auto finder = map.find(word);
	if (!(finder == map.end()))
	{
		std::cout << finder->first << std::endl;
		++count;
		return 0;
	}
	return -1;
}


void wordChecker::readFile(std::string FileName)
{
	std::ifstream inputFile;
	inputFile.open(FileName);
	if (!inputFile.is_open())//if cant open file exit right away
		exit(-1);

	std::string word;
	int count = 0;
	inputFile >> word;//priming read
	while (inputFile)
	{
		map[word] = count;
		++count;
		inputFile >> word;
	}
	inputFile.close();
}
	
