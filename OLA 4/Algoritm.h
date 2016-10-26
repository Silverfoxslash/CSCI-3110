/*
* File:	Algorithm.h
* Author:	Jeremy Bickford
* Course:	CSCI 3110
* Instructor:	Zhijiang Dong
* Date:	oct. 24 2016
* This file is the header for sorting algorithms.
*/
#pragma once
#include <cstdlib>
#include <ctime>
#include <Windows.h>
const long max_length = 100000;
typedef int DataType;

void bubbleSort(DataType theArray[], int n);

void insertionSort(DataType theArray[], int n);

void mergesort(DataType theArray[], int first, int last);

void quicksort(DataType theArray[], int first, int last);
