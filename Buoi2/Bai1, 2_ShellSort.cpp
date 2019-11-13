
#include <stdio.h>
#include <iostream> 
#include <chrono>
#define SIZE 100
using namespace std;
using namespace std::chrono;
/*Bài 1: Nhập mảng 1 chiều có N phần tử, hãy sắp xếp mảng tăng dần bằng các thuật toán
Binary Sort, Shaker Sort, Shell Sort, Heap Sort.
Bài 2: Phát sinh ngẫu nhiên mảng 1 chiều có N phần tử, mỗi phần tử có kiểu dữ liệu là 1 số
nguyên. Sắp xếp và đo thời gian sắp xếp của các thuật toán ở bài 1.*/
//shel sort

int shellSort(int arr[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{

		for (int i = gap; i < n; i += 1)
		{
			int temp = arr[i];

			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			arr[j] = temp;
		}
	}
	return 0;
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

void inputN(int &n)
{
	printf("Nhap n: ");
	scanf("%d", &n);
}

void initA(int A[], int n)
{
	for (int i = 0; i < n; i++)
		A[i] = rand() % 100 + 1;
}

void output(int A[], int n)
{
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
	int arr[SIZE], n;
	inputN(n);
	initA(arr, n);
	cout << "Array before sorting: \n";
	printArray(arr, n);
	auto start = high_resolution_clock::now();
	shellSort(arr, n);
	auto end = high_resolution_clock::now();
	cout << "\nArray after sorting: \n";
	printArray(arr, n);
	auto time = duration_cast<nanoseconds>(end - start);
	cout <<"\n"<< "It takes " << time.count() << " s" << endl;
	system("pause");
	return 0;
}