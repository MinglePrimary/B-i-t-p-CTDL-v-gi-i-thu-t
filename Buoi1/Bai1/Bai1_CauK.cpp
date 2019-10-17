
//H.Tìm phần tử có giá trị bằng X trong mảng bằng thuật toán tìm kiếm nhị phân từ
//mảng đã được sắp xếp ở câu j.

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

int binarySearch(int A[], int left, int right, int x)
{
	if (left > right) return -1;

	int mid = (left + right) / 2;

	if (x == A[mid])
		return mid;

	if (x < A[mid])
		return binarySearch(A, left, mid - 1, x);

	if (x > A[mid])
		return binarySearch(A, mid + 1, right, x);
}

void inputX(int &x)
{
	scanf("%d", &x);
}
void outputPosX(int pos)
{
	printf("Position x = %d\n", pos);
}

int main()
{
	int A[SIZE], n, x;
	input(A, n);
	output(A, n);
	//bubbleSort(A, n);
	//insertionSort(A, n);
	//interchangeSort(A, n);
	//selectionSort(A, n);
	quickSort(A, 0, n-1);
	output(A, n);
	inputX(x);
	int result = binarySearch(A, 0, n-1, x);
	outputPosX(result);
	system("pause");
	return 0;
}