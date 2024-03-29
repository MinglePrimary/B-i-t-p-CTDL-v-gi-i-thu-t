﻿//Bài 4: Dùng mảng 1 chiều để lưu trữ khi đổi một số ở hệ 10 sang hệ 16
// status: using char type

#include <stdio.h>
#include <iostream>
#include <string>
#define SIZE 100
using namespace std;

void input(int &x)
{
	scanf("%d", &x);
}

char fetchPosValue(int r)
{
	if (r<=9) return char (r+48);
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

void changeArr(char A[], char B[], int end)
{
	int j = 0,i;
	for (i = end; i >= 0; )
	{
		A[j] = B[i];
		j++;
		i--; // conditional variable
	}
	
	A[end+1] = NULL; // end of char
}

void feedDecToDex(int x, char A[])
{
	int dec = x, pos = 0, rem = 1;
	char B[SIZE];
	while (dec > 0)
	{
		rem = dec % 16;
		B[pos] = fetchPosValue(rem);
		pos++;
		dec = dec / 16;
	}	
	B[pos] = NULL;
	changeArr(A, B, pos-1);
}


void output(char answer[])
{
	cout << answer;
}

int main()
{
	char A[SIZE];
	int x, n;
	input(x);
	feedDecToDex(x, A);
	output(A);
	cout << " HEX"<<endl;
	system("pause");
	return 0;
}
