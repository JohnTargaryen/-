#include "stdafx.h"
#include "SortingManager.h"


SortingManager::SortingManager()
{
}


// 直接插入排序，参数数组第一个位置存放哨兵
// 稳定的；O(1)空间；O(N^2)时间
// 从头到尾遍历数组，遍历到某位i时，则其前面的[1...i-1]都已经是有序的
// 从[2]开始遍历，那么他前面只有[1]，只有一项，是有序的
// 若[2]>[1]，那么不用移动2的位置，对[2]的插入完成
// 若[2]<[1]，将[1]的值后移，放到2，然后从哨兵位取出原来待插入项[2]值放到1
// 遍历到[3]，要插入[3]，[1,2]已经有序
// 若[3]>[2]，直接插入，否则将待插入项[3]的值暂存在哨兵，然后将[2]的值后移，放到3
// 从后往前查到某位i满足待插入项[3]的值>[i]，则从哨兵位取出原来待插入项[3]值放到位i
vector<int> SortingManager::StarightInsertionSort(vector<int> ArrayToSort) {
	vector<int> SortResult(ArrayToSort); // copy vector
	int index, j;
	for (index = 2; index < SortResult.size(); index++) { // index即是当前待插入项的位置
		if (SortResult[index] < SortResult[index - 1]) { // 若待插入项比他前一位记录小，则需要为待插入项找到合适的位置插入
			SortResult[0] = SortResult[index]; // 将待插入项的值暂存于哨兵位
			for (j = index - 1; ; j--) { // 从待插入项的前一项起往前遍历
				if (SortResult[0] < SortResult[j]) // 若待插入项比该项小，则将该项后移
					SortResult[j + 1] = SortResult[j];
				else								// 否则即找到了待插入项大于等于该项j，则j+1是应该插入的正确位置 
					break;
			}
			SortResult[j + 1] = SortResult[0];
		} else { // 若待插入项比他前一项大，说明待插入项位置正确，不用移位

		}
	}
	SortResult[0] = -1; // 还原哨兵值
	return SortResult;
}

// 折半插入排序，将直接插入排序的查找部分由顺序查找替换为折半查找
// 比直接插入优化了“查找”的部分，减少了比较的次数，但移位的次数仍不变
// O(1), O(N^2)
vector<int> SortingManager::BinaryInsertionSort(vector<int> ArrayToSort)
{
	vector<int> SortResult(ArrayToSort);
	int index;
	for (index = 2; index < SortResult.size(); index++) { // index即是当前待插入项的位置
		if (SortResult[index] < SortResult[index - 1]) { // 若待插入项比他前一位记录小，则需要为待插入项找到合适的位置插入
			SortResult[0] = SortResult[index]; // 将待插入项的值暂存于哨兵位
			
			int high = index - 1, low = 0; // 查找范围是0到待插入项的前一位
			while (low <= high) { 
				int mid = high + low / 2;
				if (SortResult[0] > SortResult[mid]) {
					low = mid + 1;
				}
				else {
					high = mid - 1;
				}
			} // 循环结束后查找到的正确插入位置是high+1 
			for (int j = index - 1; j >= high + 1; j--) // 将待插入项前一位到high+1都后移一位
				SortResult[j + 1] = SortResult[j];
			SortResult[high + 1] = SortResult[0]; // 将待插入项插入high+1
		}
		else { // 若待插入项比他前一项大，说明待插入项位置正确，不用移位
			continue;
		}
	}
	SortResult[0] = -1; // 还原哨兵值
	return SortResult;
}

// 新开一个数组作为存储排好序的结果的循环数组，这样就可以减少移动次数
// 分成二路来插入，这二路分别是一个圆由first指针和last指针分割成的两个圆弧

vector<int> SortingManager::TwoWayInsertionSort(vector<int> ArrayToSort)
{
	vector<int> SortResult(ArrayToSort);
	

	return SortResult;
}

// 表插入排序，查找/比较次数相同，用2n次指针移动代替记录的移动，O(n^2)
// 静态链表缺点：只能顺序查找而不能随机访问
SLinkList SortingManager::StaticListInsertionSort(vector<int> ArraytoSort)
{
	SLinkList Result;
	SLNode HeadNode(-1, 1), FirstNode(ArraytoSort[1], 0);

	// 静态链表初始化，初始化表头结点和第一个结点，并让他们next互指形成循环
	Result.r[0] = HeadNode;
	Result.r[1] = FirstNode;
	Result.length = 2;

	for (int i = 2; i < ArraytoSort.size(); i++) {
		int CurrentRecord = ArraytoSort[i]; // 当前待插入项
		int CurrentPointer = 0; // 初始指向表头
		while (1) {
			if ((CurrentRecord < Result.r[Result.r[CurrentPointer].next].rc) // 若当前记录小于当前指向的下一个记录
			|| Result.r[CurrentPointer].next == 0){ // 或是表尾
				break; // 则跳出循环
			} else { 
				CurrentPointer = Result.r[CurrentPointer].next; // 否则指针后移
			}
		}// 循环结束后，指针指向的记录比待插入小，且指向的项的下一个比待插入大
		
		
		SLNode newnode(CurrentRecord, Result.r[CurrentPointer].next); // 新建表结点，数据为插入项，指向当前所指的下一个（比待插入项大的）
		Result.length++;
		Result.r[i] = newnode;
		Result.r[CurrentPointer].next = i;
	}
	Result.print();
	cout << endl;
	return Result;
}

// 按参数IncrementSeq给出的增量来进行排序，IncrementSeq中存着一个递减序列，所以希尔排序又叫缩小增量排序
// 增量序列示例：[9, 7, 5, 3, 1]
// 希尔排序的复杂度是增量序列的函数
vector<int> SortingManager::ShellSort(vector<int> ArraytoSort, vector<int> IncrementSeq)
{
	vector<int> Result(ArraytoSort);

	for (int i = 0; i < IncrementSeq.size(); i++)
		ShellInsert(Result, IncrementSeq[i]);
	Result[0] = -1; // 还原哨兵
	return Result;
}

// 以参数Incre作为增量进行一趟希尔插入排序
// 将数组分成了多个子序列进行插入排序，如其中一个序列是[0, 0+Incre, 0+2*Incre ……]
void SortingManager::ShellInsert(vector<int>& ArraytoSort, int Incre)
{
	int i, j;
	for (i = Incre + 1; i < ArraytoSort.size(); i++) {
		if (ArraytoSort[i] < ArraytoSort[i - Incre]) { // ArraytoSort[i]是当前待插入项，若当前小于前面的有序序列的最大值，则需要在前面序列中找一个合适位置插入
			ArraytoSort[0] = ArraytoSort[i]; // 暂存待插入项
			for (j = i; j-Incre >= 0; j -= Incre) { // 注意判断条件是J-incre>=0而非j>=0
				if (ArraytoSort[0] < ArraytoSort[j - Incre]) {
					ArraytoSort[j] = ArraytoSort[j - Incre]; // 后移一位
				} else { // 当前插入项大于前面那项,j即为要插入的位置
					break;
				}
			}
			ArraytoSort[j] = ArraytoSort[0];
		}
	}
}

// O（n^2）
vector<int> SortingManager::BubbleSort(vector<int> ArrayToSort)
{
	vector<int> Result(ArrayToSort);
	bool Change = true;
	for (int i = Result.size() - 1; i > 0 && Change; i--) { // 每轮将一个前i个最大的数换到位置[i]
		Change = false; // 未发生交换时排序结束
		for (int j = 1; j <= i; j++) { // 注意j的初始值
			if (Result[j - 1] > Result[j]) { // 将较大的数往后换
				int temp = Result[j - 1];
				Result[j - 1] = Result[j];
				Result[j] = temp;
				Change = true;
			}
		}
	}
	return Result;
}

// 结果将arraytosort[low…………high]中的记录以pivot为界，处于pivot左边的比pivot的值都小，右边的都大
int SortingManager::Partition(vector<int>& ArrayToSort, int low, int high)
{
	int temp = ArrayToSort[low]; // 暂存pivot值，在[low]挖出“坑”
	int pivotKey = ArrayToSort[low]; // 以[low]作pivot
	while (low < high) {
		while (low < high && ArrayToSort[high] >= pivotKey) // high的值应该比pivot的值要大
			high--;											// 若符合大于pivot值条件则从高位到低位遍历
		ArrayToSort[low] = ArrayToSort[high]; // 出现[high]的值比[pivot]的值要小，要将此值换到pivot左边，填[low]的“坑”，[high]出现一个“坑”
		// 不用担心[low]的值丢失，因为已经暂存在[0]
		while (low < high && ArrayToSort[low] <= pivotKey)
			low++;
		ArrayToSort[high] = ArrayToSort[low]; // 出现[low]的值比[pivot]的值要大，将此值换到pivot右边，填[high]的“坑”，并在[low]出现一个“坑”
		// 不用担心[high]的值丢失，因为已存在low
	}
	ArrayToSort[low] = temp; // 填回[low]的“坑”
	return low;
}

vector<int> SortingManager::QuickSort(vector<int>& ArrayToSort, int low, int high)
{
	if (low < high) {
		int pivot = Partition(ArrayToSort, low, high);
		QuickSort(ArrayToSort, low, pivot - 1);
		QuickSort(ArrayToSort, pivot+1, high);
	}
	return ArrayToSort;
}

vector<int> SortingManager::QuickSort_ConciseVersion(vector<int>& ArrayToSort, int low, int high)
{
	if (low < high) {
		int temp = ArrayToSort[low]; // 暂存pivot值，在[low]挖出“坑”
		int pivotKey = ArrayToSort[low]; // 以[low]作pivot
		int l = low, h = high;
		while (l < h) {
			while (l < h && ArrayToSort[h] >= pivotKey) // high的值应该比pivot的值要大
				h--;											// 若符合大于pivot值条件则从高位到低位遍历
			ArrayToSort[l] = ArrayToSort[h]; // 出现[high]的值比[pivot]的值要小，要将此值换到pivot左边，填[low]的“坑”，[high]出现一个“坑”
												  // 不用担心[low]的值丢失，因为已经暂存在[0]
			while (l < h && ArrayToSort[l] <= pivotKey)
				l++;
			ArrayToSort[h] = ArrayToSort[l]; // 出现[low]的值比[pivot]的值要大，将此值换到pivot右边，填[high]的“坑”，并在[low]出现一个“坑”
												  // 不用担心[high]的值丢失，因为已存在low
		}
		ArrayToSort[l] = temp; // 填回[low]的“坑”
		QuickSort_ConciseVersion(ArrayToSort, low, l - 1);
		QuickSort_ConciseVersion(ArrayToSort, l + 1, high);
	}
	return ArrayToSort;
}

vector<int> SortingManager::SelectionSort(vector<int> ArrayToSort)
{
	vector<int> Result(ArrayToSort);
	for (int i = 0; i < Result.size(); i++) { // 每次循环从[i……result.size()-1]中选一个最小的放在位置i
		int MinIndex = i;
		for (int j = i + 1; j < Result.size(); j++) {
			if (Result[j] < Result[MinIndex])
				MinIndex = j;
		}
		// 找到最小的记录后和[i]交换
		int temp = Result[i];
		Result[i] = Result[MinIndex];
		Result[MinIndex] = temp;
	}
	return Result;
}



