//Nhập mảng 1 chiều có N phần tử, mỗi phần tử có kiểu dữ liệu là 1 số nguyên.Hãy
//thực hiện các yêu cầu sau bằng ngôn ngữ lập trình C.
//f. Cho biết giá trị âm lớn nhất trong mảng.

#include <iostream>
#include <stdio.h>
#define SIZE 100

void input(int A[], int &n)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
}

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

void sort(int A[], int left, int right) // using quicksort
{
	int pivot = A[(left + right) / 2]; // bien cam canh
	int i = left, j = right;
	// buoc phan hoach
	while (i <= j)
	{
		while (A[i] < pivot)
			i++;
		while (A[j] > pivot)
			j--;
		if (i <= j)
		{
			swap(A[i], A[j]);
			i++;
			j--;
		}
	}
	// buoc de qui
	if (left < j)
		sort(A, left, j);
	if (right > i)
		sort(A, i, right);
}

void output(int A[], int res)
{
	printf("-> %d", A[res]);
}

int findMaxSub(int A[], int n)
{
	int temp=-1;
	for (int i = 0; i < n; i++)
		if (A[i] < 0)
			temp = i;
	return temp;
}

int main()
{
	int A[SIZE], n, k;
	printf("input n, A array: ");
	input(A, n);
	sort(A, 0, n - 1);
	int res = findMaxSub(A, n);
	output(A, res);
	system("pause");
	return 0;
}