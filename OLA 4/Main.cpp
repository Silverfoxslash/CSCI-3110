/*
* File:	Main.cpp
* Author:	Jeremy Bickford
* Course:	CSCI 3110
* Instructor:	Zhijiang Dong
* Date:	oct. 24 2016
* This program generates numbers to a file and reads into arrarys of various sizes and tests different sort algorithms for time.
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include "Algoritm.h"
using namespace std;

int generateAscend();
int generateRandom();
int generateDescend();
void Sort(string, int array[],ofstream& file );
void read(int list[], int length);



int main()
{	int list[max_length];//array for sorting
	ofstream Results("result.dat");// file output
	generateAscend();
	Sort("Ascending",list,Results);

	generateDescend();
	Sort("Descending",list,Results);

	generateRandom();
	Sort("Random",list,Results);
	Results.close();//close filestream
	return 0;
}

//puts random numbers in file for reading
int generateRandom()
{
	ofstream fout("DATA.dat", ios::binary);

	srand(time(nullptr));
	int r;
	for (int i = 0; i < max_length; i++)
	{
		r = rand();
		fout.write(reinterpret_cast<char*>(&r), sizeof(r));
	}

	fout.close();
	return 0;
}
//puts numbers in ascending order into file for reading
int generateAscend()
{
	ofstream fout("DATA.dat", ios::binary);

	for (int i = 0; i < max_length; ++i)
	{

		fout.write(reinterpret_cast<char*>(&i), sizeof(i));
	}

	fout.close();
	return 0;
}
//puts number in descending order for reading
int generateDescend()
{
	ofstream fout("DATA.dat", ios::binary);

	for (int i = max_length; i > 0; --i)
	{

		fout.write((char*)&i, sizeof(i));
	}

	fout.close();
	return 0;
}
//reads array and sorts it then output the time to sort it.
void Sort(string type,int array[], ofstream& file)
{
	int length;
	double t1, t2;
	cout << endl << "Test Cases on " << type << " data in seconds\n";
	file<< "Test Cases on " << type << " data in seconds\n";
	cout <<left << setw(14) << "Array size" << setw(14) << "Bubble Sort" << setw(17) << "Insertion Sort" << setw(12) << "Merge Sort" << setw(12) << "Quick Sort"<<endl;
	file << left << setw(14) << "Array size" << setw(14) << "Bubble Sort" << setw(17) << "Insertion Sort" << setw(12) << "Merge Sort" << setw(12) << "Quick Sort" << endl;
	
	for (length = 10; length <= max_length; )//untill it reaches last case
	{
		cout <<setw(14)<<length;
		file << setw(14) << length;

		read(array,length);
		t1 = clock();
		bubbleSort(array,length);
		t2 = clock();
		cout << setw(14) << (t2 - t1) / CLK_TCK ;
		file << setw(14) << (t2 - t1) / CLK_TCK;

		read(array, length);
		t1 = clock();
		insertionSort(array,length);
		t2 = clock();
		cout << setw(17) << (t2 - t1) / CLK_TCK ;
		file << setw(17) << (t2 - t1) / CLK_TCK;

		read(array, length);
		t1 = clock();
		mergesort(array,0, length);
		t2 = clock();
		cout << setw(12) << (t2 - t1) / CLK_TCK ;
		file << setw(12) << (t2 - t1) / CLK_TCK;

		read(array, length);
		t1 = clock();
		quicksort(array,0, length - 1);
		t2 = clock();
		cout << setw(12) << (t2 - t1) / CLK_TCK << "\n\n";
		file << setw(12) << (t2 - t1) / CLK_TCK << "\n\n";
		//switches between test sizes
		switch (length)
		{
		case 10:
			length = 50;
			break;
		case 50:
			length = 100;
			break;
		case 100:
			length = 200;
			break;
		case 200:
			length = 300;
			break;
		case 300:
			length = 400;
			break;
		case 400:
			length = 500;
			break;
		case 500:
			length = 1000;
			break;
		case 1000:
			length = 2000;
			break;
		case 2000:
			length = 3000;
			break;
		case 3000:
			length = 4000;
			break;
		case 4000:
			length = 5000;
			break;
		case 5000:
			length = 10000;
			break;
		case 10000:
			length = 50000;
			break;
		case 50000:
			length = 100000;
			break;
		case 100000:
			length = 100001;
			break;
		}
	}

}
//refresh array to pre sorted state
void read(int list[], int length)
{
	ifstream fin("DATA.dat", ios::binary);
	for (long i = 0; i < length; i++)
	{
		fin.read(reinterpret_cast<char*>(&list[i]), sizeof(i));
	}
	fin.close();
}