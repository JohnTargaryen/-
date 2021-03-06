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
	SLinkList SLLResult = SrtMgr->StaticListInsertionSort(RandomArray);
	SLLResult.ReArrange();

	int n[] = { 7, 5, 3, 1 };
	vector<int> IncrementSeq(n, n+4);
	vector<int> ShellResult = SrtMgr->ShellSort(RandomArray, IncrementSeq);
	cout << "After Shell sort : ";
	PrintArray(ShellResult);

	vector<int> BubbleSort = SrtMgr->BubbleSort(RandomArray);
	cout << "After Bubble sort : ";
	PrintArray(BubbleSort);

	vector<int> temp(RandomArray);
	vector<int> QuickSortRes = SrtMgr->QuickSort(temp, 0, temp.size() - 1);
	cout << "After QuickSort : ";
	PrintArray(QuickSortRes);

	vector<int> temp1(RandomArray);
	vector<int> QuickSort_ConciseVersionRes = SrtMgr->QuickSort_ConciseVersion(temp1, 0, temp.size() - 1);
	cout << "After QuickSort_ConciseVersionRes : ";
	PrintArray(QuickSort_ConciseVersionRes);

	vector<int> SelectionSortRes = SrtMgr->SelectionSort(RandomArray);
	cout << "After SelectionSort : ";
	PrintArray(SelectionSortRes);
	
	vector<int> HeapSortRes(RandomArray);
	cout << "After Heap sort : ";
	SrtMgr->HeapSort(HeapSortRes);
	PrintArray(HeapSortRes);

	vector<int> MergeSortRes(RandomArray.size());
	vector<int> ArrayToMerge(RandomArray);
	cout << "After Merge sort : ";
	SrtMgr->MergeSort(ArrayToMerge, 0, RandomArray.size()-1, MergeSortRes);
	PrintArray(MergeSortRes);
		
	sort(RandomArray.begin(), RandomArray.end());
	cout << "After STL sort : ";
	PrintArray(RandomArray);

	cout << ((insertionsortarray == RandomArray) ? "排序正确" : "排序错误") << endl;
	cout << ((binsertionsortarray == RandomArray) ? "排序正确" : "排序错误") << endl;
    return 0;
}

