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

	void ReArrange() { // ��������ľ�̬����ʹ��iС��Ԫ�ط���[i-1]λ��
		int CurrentPtr = r[0].next; // ��ʼָ����С�ļ�¼
		int NextPtr = r[CurrentPtr].next; // ��¼��ǰָ���¼����һ��
		for (int i = 1; i < length; i++) { 
			while (CurrentPtr < i) // ǰi�����Ѿ���������У�����ǰָ��ĳ�����ź�������������
				CurrentPtr = r[CurrentPtr].next;

			NextPtr = r[CurrentPtr].next;
			if (CurrentPtr != i) {
				// ��λ��[i]�͵�ǰָ��λ�õļ�¼����
				SLNode temp = r[i]; // �ݴ�r[i]
				r[i] = r[CurrentPtr]; 
				r[CurrentPtr] = temp;

				r[i].next = CurrentPtr; // λ��[i]��nextָ��ǰָ��λ��
			}
			CurrentPtr = NextPtr;
		}
	}
}; //��̬���� 