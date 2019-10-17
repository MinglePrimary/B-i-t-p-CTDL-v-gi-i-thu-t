//Nhập mảng 1 chiều có N phần tử, mỗi phần tử có kiểu dữ liệu là 1 số nguyên.Hãy
//thực hiện các yêu cầu sau bằng ngôn ngữ lập trình C.
//a.Xuất mảng 1 chiều nói trên ra màn hình

#include <iostream>
#include <stdio.h>
#define SIZE 100

void input(int A[], int &n)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
}

void output(int A[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
}

int main()
{
	int A[SIZE], n;
	input(A, n);
	output(A, n);
	system("pause");
	return 0;
}