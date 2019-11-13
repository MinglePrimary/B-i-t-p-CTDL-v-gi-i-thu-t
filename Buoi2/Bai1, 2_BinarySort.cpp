#include <stdio.h>
#include <iostream>
#include <chrono>
#define SIZE 100
using namespace std;
using namespace std::chrono;
// Bài 1: Nhập mảng 1 chiều có N phần tử, hãy sắp xếp mảng tăng dần bằng các thuật toán
//Binary Sort, Shaker Sort, Shell Sort, Heap Sort.
//Bài 2: Phát sinh ngẫu nhiên mảng 1 chiều có N phần tử, mỗi phần tử có kiểu dữ liệu là 1 số
//nguyên.Sắp xếp và đo thời gian sắp xếp của các thuật toán ở bài 1
// Binary sort_insert sort using binary search
void inputN(int &n)
{
	printf("Nhap n: ");
	scanf("%d", &n);
}
// ham khoi tao cac gt trong mang A
void initA(int A[], int n) 
{
	for (int i = 0; i < n; i++)
		A[i] = rand() % 100 + 1;
}

void output(int A[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int binarySearch(int a[], int item, int low, int high)
{
	if (high <= low)
		return (item > a[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;

	if (item == a[mid])
		return mid + 1;

	if (item > a[mid])
		return binarySearch(a, item, mid + 1, high);
	return binarySearch(a, item, low, mid - 1);
}
// Function to sort an array a[] of size 'n' 
void insertionSort(int a[], int n)
{
	int i, loc, j, k, selected;

	for (i = 1; i < n; ++i)
	{
		j = i - 1;
		selected = a[i];

		// find location where selected sould be inseretd 
		loc = binarySearch(a, selected, 0, j);

		// Move all elements after location to create space 
		while (j >= loc)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
}

int main()
{
	int A[SIZE], n;
	inputN(n);
	initA(A, n);
	auto start = high_resolution_clock::now();
	insertionSort(A, n); // insertion sort using binary search
	auto end = high_resolution_clock::now();
	output(A, n);
	auto time = duration_cast<nanoseconds>(end - start);
	cout <<"->It takes "<< time.count() <<" nanoseconds"<<endl;
	system("pause");
	return 0;
}