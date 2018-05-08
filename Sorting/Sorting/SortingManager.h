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

private:
	
};

