//Nhập mảng 1 chiều có N phần tử, mỗi phần tử có kiểu dữ liệu là 1 số nguyên.Hãy
//thực hiện các yêu cầu sau bằng ngôn ngữ lập trình C.
//c. Liệt kê những phần tử mang giá trị lớn nhất trong mảng

#include <iostream>
#include <stdio.h>
#define SIZE 100

void input(int A[], int &n)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
}

void output(int A[], int k, int n)
{
	for (int i = n-1; i > k; i--)
		printf("%d ", A[i]);
}

void inputK(int &k)
{
	scanf("%d", &k);
}

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;

}


void sort(int A[], int left, int right) //using quickSort
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


int main()
{
	int A[SIZE], n, k;
	printf("input n, A array: ");
	input(A, n);
	printf("input k: ");
	inputK(k);
	sort(A, 0, n-1);
	output(A, k, n);
	system("pause");
	return 0;
}