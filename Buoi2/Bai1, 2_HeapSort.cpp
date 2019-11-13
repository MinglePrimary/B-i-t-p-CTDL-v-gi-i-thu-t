#include <iostream> 
#include <iostream>
#include <chrono>
#define SIZE 100
using namespace std;
using namespace std::chrono;
/*Bài 1: Nhập mảng 1 chiều có N phần tử, hãy sắp xếp mảng tăng dần bằng các thuật toán
Binary Sort, Shaker Sort, Shell Sort, Heap Sort.
Bài 2 : Phát sinh ngẫu nhiên mảng 1 chiều có N phần tử, mỗi phần tử có kiểu dữ liệu là 1 số
nguyên.Sắp xếp và đo thời gian sắp xếp của các thuật toán ở bài 1.*/
// heap sort

void heapify(int arr[], int n, int i)
{
	int largest = i;  
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

// main function to do heap sort 
void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

/* A utility function to print array of size n */
void output(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
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
// Driver program 
int main()
{
	int arr[SIZE], n;
	inputN(n);
	initA(arr, n);
	auto start = high_resolution_clock::now(); 
	heapSort(arr, n);
	auto end = high_resolution_clock::now();
	cout << "Sorted array is \n";
	output(arr, n);
	auto time = duration_cast<nanoseconds>(end-start);
	cout << "It takes " << time.count() << " nanoseconds" << endl;
	system("pause");
	return 0;
}