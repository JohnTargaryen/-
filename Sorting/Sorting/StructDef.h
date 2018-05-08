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
}; //静态链表 