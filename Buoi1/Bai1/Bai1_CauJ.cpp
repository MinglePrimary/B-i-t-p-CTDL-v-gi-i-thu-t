//Sắp xếp mảng trên có giá trị tăng dần bằng thuật toán sắp xếp mà các bạn đã học
//(Selection Sort, Interchange Sort, Bubble Sort, Insertion Sort, Quick Sort)


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
	printf("\n");
}

/*void bubbleSort(int A[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (A[j] > A[j + 1])
				//swap
			{
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
}*/

void insertionSort(int A[], int n)
{
	int temp, j;
	for (int i = 1; i < n; i++)
	{
		j = i - 1;
		temp = A[i];
		while (j >= 0 && temp < A[j])
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = temp;
	}
}
void interchangeSort(int A[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (A[i] > A[j])
			{
				//swap
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
}

void swap(int &x, int &y)
{
	int temp  = x;
	x = y;
	y = temp;
}
void selectionSort(int A[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int MinPos = i;
		for (int j = i + 1; j < n; j++)
			if (A[MinPos] > A[j])
				MinPos = j;
		swap(A[i], A[MinPos]);
	}
}
void quickSort(int A[], int left, int right)
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
		quickSort(A, left, j);
	if (right > i)
		quickSort(A, i, right);
}

int main()
{
	int A[SIZE], n;
	input(A, n);
	output(A, n);
	//bubbleSort(A, n);
	//insertionSort(A, n);
	//interchangeSort(A, n);
	//selectionSort(A, n);
	quickSort(A, 0, n-1);
	output(A, n);
	system("pause");
	return 0;
}