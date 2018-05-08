// Sorting.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SortingManager.h"
#include "main.h"
#include<random>
#include<iostream>
using namespace std;

vector<int> GenerateRandomArray(int size) {
	vector<int> RandomArray(size);
	RandomArray[0] = -1; // 哨兵
	for (int i = 1; i < size; i++)
		RandomArray[i] = (rand() % 10001);

	return RandomArray;
}

void PrintArray(vector<int> ArrayToPrint) {
	for (int i = 0; i < ArrayToPrint.size(); i++)
		cout << ArrayToPrint[i] << " ";
	cout << endl;
}

int main() {
	vector<int> RandomArray = GenerateRandomArray(101);
	cout << "RandomArray : ";
	PrintArray(RandomArray);

	SortingManager* SrtMgr = new SortingManager();

	vector<int> insertionsortarray = SrtMgr->StarightInsertionSort(RandomArray);
	cout << "After StarightInsertionSort : ";
	PrintArray(insertionsortarray);

	vector<int> binsertionsortarray = SrtMgr->BinaryInsertionSort(RandomArray);
	cout << "After BinaryInsertionSort : ";
	PrintArray(binsertionsortarray);

	cout << "After StaticListInsertionSort : ";
	SrtMgr->StaticListInsertionSort(RandomArray);

	sort(RandomArray.begin(), RandomArray.end());
	cout << "After STL sort : ";
	PrintArray(RandomArray);

	cout << ((insertionsortarray == RandomArray) ? "排序正确" : "排序错误") << endl;
	cout << ((binsertionsortarray == RandomArray) ? "排序正确" : "排序错误") << endl;
    return 0;
}

