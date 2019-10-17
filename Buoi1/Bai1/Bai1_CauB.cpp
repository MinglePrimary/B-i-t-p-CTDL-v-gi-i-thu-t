//Nhập mảng 1 chiều có N phần tử, mỗi phần tử có kiểu dữ liệu là 1 số nguyên.Hãy
//thực hiện các yêu cầu sau bằng ngôn ngữ lập trình C.
// b.Xoá 1 phần tử tại chỉ số K trong mảng

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

void inputK(int &k)
{
	scanf("%d", &k);
}

void deletePosition_K(int A[], int k, int &n)
{
	for (int i = k; i < n-1; i++)
	{
		A[i] = A[i + 1];
	}
	A[n-1] = NULL;
	n = n - 1;
	
}

int main()
{
	int A[SIZE], n, k;
	printf("input n, A array: ");
	input(A, n);
	printf("input k: ");
	inputK(k);
	deletePosition_K(A, k, n);
	output(A, n);
	system("pause");
	return 0;
}