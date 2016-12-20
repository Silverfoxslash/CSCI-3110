#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

#include "BST.h"

//The name of the file containing binary search trees
const string    FileName = "bst.dat";

//The value indicating the end of a binary search tree
// in the file FileName
const int       SentinelValue = -1;

//If you need to count the number of nodes in a Binary 
//Search Tree of integers, please traverse the tree by passing
//the following function as the parameter.
//Remember, every time you count the number of nodes,
//you have to initialize nodeCount by 0
int nodeCount = 0;
void nodeNum()
{
    nodeCount ++;
}


int main(void)
{
	BinarySearchTree<int> Tree;
	ifstream inputFile(FileName);
	if (!inputFile.is_open())//if cant open file exit right away
		exit(-1);
	int value, treeNum = 1;// value holds numbers from files, treeNum counts how many trees I build
	inputFile >> value;//priming read
	while(inputFile.good())
	{
		while (value != SentinelValue)//build tree
		{
			Tree.searchTreeInsert(value);
			nodeNum();
			inputFile >> value;

		}
		cout << string(50, '-') << endl;// print results
		cout << "The Tree NO. " << treeNum << endl;
		cout << "# of tree node	: " << nodeCount << endl;
		int level = Tree.totalLevel();
		cout << "Total Level of Tree : " << level << endl;
		double logarithm = log2(nodeCount);
		float average = static_cast<float>(level) / static_cast<float>(nodeCount);
		cout << "Log(N) of the tree : " << logarithm << endl;
		cout << "Average level : " << average << endl;
		cout << "Average level / Log(N) = " << average / logarithm << endl;
		cout << string(50, '-') << "\n\n";
		++treeNum;
		nodeCount = 0;
		Tree = BinarySearchTree<int>();//clear tree
		inputFile >> value;//priming read for next
	}
	inputFile.close();
	system("PAUSE");
    return 0;
}

