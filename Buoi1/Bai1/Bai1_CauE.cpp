//Nhập mảng 1 chiều có N phần tử, mỗi phần tử có kiểu dữ liệu là 1 số nguyên.Hãy
//thực hiện các yêu cầu sau bằng ngôn ngữ lập trình C.
//e. Đếm số phần tử có giá trị âm trong mảng

#include <iostream>
#include <stdio.h>
#define SIZE 100

void input(int A[], int &n)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
}

int countSub(int A[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (A[i] < 0)
			count++ ;
	return count;
}

void output(int res)
{
	printf("-> %d", res);
}

int main()
{
	int A[SIZE], n, k;
	printf("input n, A array: ");
	input(A, n);
	int res = countSub(A, n);
	output(res);
	system("pause");
	return 0;
}