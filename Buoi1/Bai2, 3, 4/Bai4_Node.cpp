//Bài 4: Dùng mảng 1 chiều để lưu trữ khi đổi một số ở hệ 10 sang hệ 16

#include <iostream>
#include <stdio.h>
struct Node
{
	char info;
	Node *pNext;
};

struct LinkedList
{
	Node *pHead;
	Node *pTail;
};

void input(int &x)
{
	scanf("%d", &x);
}

void output(LinkedList myList)
{
	for (Node *i = myList.pHead; i != NULL; i = i->pNext)
		printf("%c", i->info);
	printf(" HEX");
}

char fetchValue(int r)
{
	if (r <= 9) return char(r + 48);
	else
		switch (r)
		{
		case (10): return 'A';
			break;
		case (11): return 'B';
			break;
		case (12): return 'C';
			break;
		case (13): return 'D';
			break;
		case (14): return 'E';
			break;
		case (15): return 'F';
			break;
		}
}

Node *createNode(char c)
{
	Node *p = new Node;
	if (p == NULL)
	{
		return NULL;
	}
	p->info = c;
	p->pNext = NULL;
	return p;
}

bool isEmptyList(LinkedList myList)
{
	if (myList.pHead == NULL)
		return true;
	return false;
}

void pushInLinkedList(Node *p, LinkedList &l)
{

	if (isEmptyList(l))
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void feedDecToBin(int x, LinkedList &myList)
{
	int dec = x, rem = 0;
	while (dec > 0)
	{
		rem = dec % 16;
		Node *p = createNode(fetchValue(rem));
		pushInLinkedList(p, myList);
		dec = dec / 16;
	}
}
void Init(LinkedList &l)
{
	l.pHead = l.pTail = NULL;
}

int main()
{
	LinkedList myList;
	Init(myList);
	int x;
	input(x);
	feedDecToBin(x, myList);
	output(myList);
	system("pause");
	return 0;
}