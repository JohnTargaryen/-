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

// 表插入排序，用2n次指针移动代替记录的移动，O(n^2)
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
		int CurrentPointer = Result.r[0].next; // 初始指向最小的记录
		while (1) {
			if ((CurrentRecord < Result.r[Result.r[CurrentPointer].next].rc) // 且小于当前指向的记录的下一个记录
			|| Result.r[CurrentPointer].next == 0){ // 或是表尾
				break; // 则跳出循环
			} else { 
				CurrentPointer = Result.r[CurrentPointer].next; // 否则指针后移
			}
		}// 循环结束后，指针指向的记录比待插入小，且指向的项的下一个比待插入大
		
		
		SLNode newnode(CurrentRecord, Result.r[CurrentPointer].next); // 新建表结点，数据为插入项，指向当前所指的下一个（比待插入项大的）
		Result.r[i] = newnode;
		Result.r[CurrentPointer].next = i;
	}
	Result.print();
	return Result;
}



