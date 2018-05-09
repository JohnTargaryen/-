#include "stdafx.h"
#include "SortingManager.h"


SortingManager::SortingManager()
{
}


// ֱ�Ӳ������򣬲��������һ��λ�ô���ڱ�
// �ȶ��ģ�O(1)�ռ䣻O(N^2)ʱ��
// ��ͷ��β�������飬������ĳλiʱ������ǰ���[1...i-1]���Ѿ��������
// ��[2]��ʼ��������ô��ǰ��ֻ��[1]��ֻ��һ��������
// ��[2]>[1]����ô�����ƶ�2��λ�ã���[2]�Ĳ������
// ��[2]<[1]����[1]��ֵ���ƣ��ŵ�2��Ȼ����ڱ�λȡ��ԭ����������[2]ֵ�ŵ�1
// ������[3]��Ҫ����[3]��[1,2]�Ѿ�����
// ��[3]>[2]��ֱ�Ӳ��룬���򽫴�������[3]��ֵ�ݴ����ڱ���Ȼ��[2]��ֵ���ƣ��ŵ�3
// �Ӻ���ǰ�鵽ĳλi�����������[3]��ֵ>[i]������ڱ�λȡ��ԭ����������[3]ֵ�ŵ�λi
vector<int> SortingManager::StarightInsertionSort(vector<int> ArrayToSort) {
	vector<int> SortResult(ArrayToSort); // copy vector
	int index, j;
	for (index = 2; index < SortResult.size(); index++) { // index���ǵ�ǰ���������λ��
		if (SortResult[index] < SortResult[index - 1]) { // �������������ǰһλ��¼С������ҪΪ���������ҵ����ʵ�λ�ò���
			SortResult[0] = SortResult[index]; // �����������ֵ�ݴ����ڱ�λ
			for (j = index - 1; ; j--) { // �Ӵ��������ǰһ������ǰ����
				if (SortResult[0] < SortResult[j]) // ����������ȸ���С���򽫸������
					SortResult[j + 1] = SortResult[j];
				else								// �����ҵ��˴���������ڵ��ڸ���j����j+1��Ӧ�ò������ȷλ�� 
					break;
			}
			SortResult[j + 1] = SortResult[0];
		} else { // �������������ǰһ���˵����������λ����ȷ��������λ

		}
	}
	SortResult[0] = -1; // ��ԭ�ڱ�ֵ
	return SortResult;
}

// �۰�������򣬽�ֱ�Ӳ�������Ĳ��Ҳ�����˳������滻Ϊ�۰����
// ��ֱ�Ӳ����Ż��ˡ����ҡ��Ĳ��֣������˱ȽϵĴ���������λ�Ĵ����Բ���
// O(1), O(N^2)
vector<int> SortingManager::BinaryInsertionSort(vector<int> ArrayToSort)
{
	vector<int> SortResult(ArrayToSort);
	int index;
	for (index = 2; index < SortResult.size(); index++) { // index���ǵ�ǰ���������λ��
		if (SortResult[index] < SortResult[index - 1]) { // �������������ǰһλ��¼С������ҪΪ���������ҵ����ʵ�λ�ò���
			SortResult[0] = SortResult[index]; // �����������ֵ�ݴ����ڱ�λ
			
			int high = index - 1, low = 0; // ���ҷ�Χ��0�����������ǰһλ
			while (low <= high) { 
				int mid = high + low / 2;
				if (SortResult[0] > SortResult[mid]) {
					low = mid + 1;
				}
				else {
					high = mid - 1;
				}
			} // ѭ����������ҵ�����ȷ����λ����high+1 
			for (int j = index - 1; j >= high + 1; j--) // ����������ǰһλ��high+1������һλ
				SortResult[j + 1] = SortResult[j];
			SortResult[high + 1] = SortResult[0]; // �������������high+1
		}
		else { // �������������ǰһ���˵����������λ����ȷ��������λ
			continue;
		}
	}
	SortResult[0] = -1; // ��ԭ�ڱ�ֵ
	return SortResult;
}

// �¿�һ��������Ϊ�洢�ź���Ľ����ѭ�����飬�����Ϳ��Լ����ƶ�����
// �ֳɶ�·�����룬���·�ֱ���һ��Բ��firstָ���lastָ��ָ�ɵ�����Բ��

vector<int> SortingManager::TwoWayInsertionSort(vector<int> ArrayToSort)
{
	vector<int> SortResult(ArrayToSort);
	

	return SortResult;
}

// ��������򣬲���/�Ƚϴ�����ͬ����2n��ָ���ƶ������¼���ƶ���O(n^2)
// ��̬����ȱ�㣺ֻ��˳����Ҷ������������
SLinkList SortingManager::StaticListInsertionSort(vector<int> ArraytoSort)
{
	SLinkList Result;
	SLNode HeadNode(-1, 1), FirstNode(ArraytoSort[1], 0);

	// ��̬�����ʼ������ʼ����ͷ���͵�һ����㣬��������next��ָ�γ�ѭ��
	Result.r[0] = HeadNode;
	Result.r[1] = FirstNode;
	Result.length = 2;

	for (int i = 2; i < ArraytoSort.size(); i++) {
		int CurrentRecord = ArraytoSort[i]; // ��ǰ��������
		int CurrentPointer = 0; // ��ʼָ���ͷ
		while (1) {
			if ((CurrentRecord < Result.r[Result.r[CurrentPointer].next].rc) // ����ǰ��¼С�ڵ�ǰָ�����һ����¼
			|| Result.r[CurrentPointer].next == 0){ // ���Ǳ�β
				break; // ������ѭ��
			} else { 
				CurrentPointer = Result.r[CurrentPointer].next; // ����ָ�����
			}
		}// ѭ��������ָ��ָ��ļ�¼�ȴ�����С����ָ��������һ���ȴ������
		
		
		SLNode newnode(CurrentRecord, Result.r[CurrentPointer].next); // �½����㣬����Ϊ�����ָ��ǰ��ָ����һ�����ȴ��������ģ�
		Result.length++;
		Result.r[i] = newnode;
		Result.r[CurrentPointer].next = i;
	}
	Result.print();
	cout << endl;
	return Result;
}

// ������IncrementSeq��������������������IncrementSeq�д���һ���ݼ����У�����ϣ�������ֽ���С��������
// ��������ʾ����[9, 7, 5, 3, 1]
// ϣ������ĸ��Ӷ����������еĺ���
vector<int> SortingManager::ShellSort(vector<int> ArraytoSort, vector<int> IncrementSeq)
{
	vector<int> Result(ArraytoSort);

	for (int i = 0; i < IncrementSeq.size(); i++)
		ShellInsert(Result, IncrementSeq[i]);
	Result[0] = -1; // ��ԭ�ڱ�
	return Result;
}

// �Բ���Incre��Ϊ��������һ��ϣ����������
// ������ֳ��˶�������н��в�������������һ��������[0, 0+Incre, 0+2*Incre ����]
void SortingManager::ShellInsert(vector<int>& ArraytoSort, int Incre)
{
	int i, j;
	for (i = Incre + 1; i < ArraytoSort.size(); i++) {
		if (ArraytoSort[i] < ArraytoSort[i - Incre]) { // ArraytoSort[i]�ǵ�ǰ�����������ǰС��ǰ����������е����ֵ������Ҫ��ǰ����������һ������λ�ò���
			ArraytoSort[0] = ArraytoSort[i]; // �ݴ��������
			for (j = i; j-Incre >= 0; j -= Incre) { // ע���ж�������J-incre>=0����j>=0
				if (ArraytoSort[0] < ArraytoSort[j - Incre]) {
					ArraytoSort[j] = ArraytoSort[j - Incre]; // ����һλ
				} else { // ��ǰ���������ǰ������,j��ΪҪ�����λ��
					break;
				}
			}
			ArraytoSort[j] = ArraytoSort[0];
		}
	}
}

// O��n^2��
vector<int> SortingManager::BubbleSort(vector<int> ArrayToSort)
{
	vector<int> Result(ArrayToSort);
	bool Change = true;
	for (int i = Result.size() - 1; i > 0 && Change; i--) { // ÿ�ֽ�һ��ǰi������������λ��[i]
		Change = false; // δ��������ʱ�������
		for (int j = 1; j <= i; j++) { // ע��j�ĳ�ʼֵ
			if (Result[j - 1] > Result[j]) { // ���ϴ��������
				int temp = Result[j - 1];
				Result[j - 1] = Result[j];
				Result[j] = temp;
				Change = true;
			}
		}
	}
	return Result;
}

// �����arraytosort[low��������high]�еļ�¼��pivotΪ�磬����pivot��ߵı�pivot��ֵ��С���ұߵĶ���
int SortingManager::Partition(vector<int>& ArrayToSort, int low, int high)
{
	int temp = ArrayToSort[low]; // �ݴ�pivotֵ����[low]�ڳ����ӡ�
	int pivotKey = ArrayToSort[low]; // ��[low]��pivot
	while (low < high) {
		while (low < high && ArrayToSort[high] >= pivotKey) // high��ֵӦ�ñ�pivot��ֵҪ��
			high--;											// �����ϴ���pivotֵ������Ӹ�λ����λ����
		ArrayToSort[low] = ArrayToSort[high]; // ����[high]��ֵ��[pivot]��ֵҪС��Ҫ����ֵ����pivot��ߣ���[low]�ġ��ӡ���[high]����һ�����ӡ�
		// ���õ���[low]��ֵ��ʧ����Ϊ�Ѿ��ݴ���[0]
		while (low < high && ArrayToSort[low] <= pivotKey)
			low++;
		ArrayToSort[high] = ArrayToSort[low]; // ����[low]��ֵ��[pivot]��ֵҪ�󣬽���ֵ����pivot�ұߣ���[high]�ġ��ӡ�������[low]����һ�����ӡ�
		// ���õ���[high]��ֵ��ʧ����Ϊ�Ѵ���low
	}
	ArrayToSort[low] = temp; // ���[low]�ġ��ӡ�
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
		int temp = ArrayToSort[low]; // �ݴ�pivotֵ����[low]�ڳ����ӡ�
		int pivotKey = ArrayToSort[low]; // ��[low]��pivot
		int l = low, h = high;
		while (l < h) {
			while (l < h && ArrayToSort[h] >= pivotKey) // high��ֵӦ�ñ�pivot��ֵҪ��
				h--;											// �����ϴ���pivotֵ������Ӹ�λ����λ����
			ArrayToSort[l] = ArrayToSort[h]; // ����[high]��ֵ��[pivot]��ֵҪС��Ҫ����ֵ����pivot��ߣ���[low]�ġ��ӡ���[high]����һ�����ӡ�
												  // ���õ���[low]��ֵ��ʧ����Ϊ�Ѿ��ݴ���[0]
			while (l < h && ArrayToSort[l] <= pivotKey)
				l++;
			ArrayToSort[h] = ArrayToSort[l]; // ����[low]��ֵ��[pivot]��ֵҪ�󣬽���ֵ����pivot�ұߣ���[high]�ġ��ӡ�������[low]����һ�����ӡ�
												  // ���õ���[high]��ֵ��ʧ����Ϊ�Ѵ���low
		}
		ArrayToSort[l] = temp; // ���[low]�ġ��ӡ�
		QuickSort_ConciseVersion(ArrayToSort, low, l - 1);
		QuickSort_ConciseVersion(ArrayToSort, l + 1, high);
	}
	return ArrayToSort;
}

vector<int> SortingManager::SelectionSort(vector<int> ArrayToSort)
{
	vector<int> Result(ArrayToSort);
	for (int i = 0; i < Result.size(); i++) { // ÿ��ѭ����[i����result.size()-1]��ѡһ����С�ķ���λ��i
		int MinIndex = i;
		for (int j = i + 1; j < Result.size(); j++) {
			if (Result[j] < Result[MinIndex])
				MinIndex = j;
		}
		// �ҵ���С�ļ�¼���[i]����
		int temp = Result[i];
		Result[i] = Result[MinIndex];
		Result[MinIndex] = temp;
	}
	return Result;
}



