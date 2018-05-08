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

// �����������2n��ָ���ƶ������¼���ƶ���O(n^2)
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
		int CurrentPointer = Result.r[0].next; // ��ʼָ����С�ļ�¼
		while (1) {
			if ((CurrentRecord < Result.r[Result.r[CurrentPointer].next].rc) // ��С�ڵ�ǰָ��ļ�¼����һ����¼
			|| Result.r[CurrentPointer].next == 0){ // ���Ǳ�β
				break; // ������ѭ��
			} else { 
				CurrentPointer = Result.r[CurrentPointer].next; // ����ָ�����
			}
		}// ѭ��������ָ��ָ��ļ�¼�ȴ�����С����ָ��������һ���ȴ������
		
		
		SLNode newnode(CurrentRecord, Result.r[CurrentPointer].next); // �½����㣬����Ϊ�����ָ��ǰ��ָ����һ�����ȴ��������ģ�
		Result.r[i] = newnode;
		Result.r[CurrentPointer].next = i;
	}
	Result.print();
	return Result;
}



