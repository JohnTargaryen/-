#pragma once
#include<iostream>
using namespace std;
struct SLNode {
	int rc; // 数据记录
	int next; // 指针

	SLNode(int RC, int NEXT) {
		rc = RC;
		next = NEXT;
	}

	SLNode() {
		rc = 0;
		next = 0;
	}
};

struct SLinkList
{
	SLNode r[101]; // 0号单元是表头结点
	int length; // 链表长度 
	
	SLinkList() {
		length = 0;
	}

	void print() {
		int ptr = r[0].next;
		while (ptr != 0) {
			cout << r[ptr].rc << " ";
			ptr = r[ptr].next;
		}
	}

	void ReArrange() { // 重排有序的静态链表，使第i小的元素放在[i-1]位上
		int CurrentPtr = r[0].next; // 初始指向最小的记录
		int NextPtr = r[CurrentPtr].next; // 记录当前指向记录的下一个
		for (int i = 1; i < length; i++) { 
			while (CurrentPtr < i) // 前i个是已经有序的序列，若当前指向某个已排好序的则往后查找
				CurrentPtr = r[CurrentPtr].next;

			NextPtr = r[CurrentPtr].next;
			if (CurrentPtr != i) {
				// 将位置[i]和当前指向位置的记录互换
				SLNode temp = r[i]; // 暂存r[i]
				r[i] = r[CurrentPtr]; 
				r[CurrentPtr] = temp;

				r[i].next = CurrentPtr; // 位置[i]的next指向当前指向位置
			}
			CurrentPtr = NextPtr;
		}
	}
}; //静态链表 