#pragma once
#include<iostream>
using namespace std;
struct SLNode {
	int rc; // ���ݼ�¼
	int next; // ָ��

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
	SLNode r[101]; // 0�ŵ�Ԫ�Ǳ�ͷ���
	int length; // ������ 
	
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
}; //��̬���� 