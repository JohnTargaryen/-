#include<vector>
#include"StructDef.h"
using namespace std;

#pragma once
class SortingManager
{
public:
	SortingManager();

	vector<int> StarightInsertionSort(vector<int> ArrayToSort);

	vector<int> BinaryInsertionSort(vector<int> ArrayToSort);

	vector<int> TwoWayInsertionSort(vector<int> ArrayToSort);

	SLinkList StaticListInsertionSort(vector<int> ArraytoSort);

	vector<int> ShellSort(vector<int> ArraytoSort, vector<int> IncrementSeq);

	void ShellInsert(vector<int> &ArraytoSort, int Incre);

	vector<int> BubbleSort(vector<int> ArrayToSort);

	int Partition(vector<int>& ArrayToSort, int low, int high);

	vector<int> QuickSort(vector<int>& ArrayToSort, int low, int high);

	vector<int> QuickSort_ConciseVersion(vector<int>& ArrayToSort, int low, int high);

	vector<int> SelectionSort(vector<int> ArrayToSort);

private:
	
};

