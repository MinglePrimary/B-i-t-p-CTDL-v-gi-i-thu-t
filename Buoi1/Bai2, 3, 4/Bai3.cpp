//Bài 3: Dùng mảng 1 chiều để lưu trữ khi đổi một số ở hệ 10 sang hệ nhị phân

#include <iostream>
#include <stdio.h>
#define SIZE 100

void input(int &x)
{
	scanf("%d", &x);
}
void changeArr(int A[], int B[], int n)
{
	int j = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		A[j] = B[i];
		j++;
	}
}
void changeDecToBin(int A[], int &n, int x)
{
	int dec = x, sum = 0, rem = 1, i = 1, pos = 0;
	int B[SIZE];
	while (dec >0)
	{
		rem = dec % 2;
		sum = sum + (i*rem);
		B[pos] = rem;
		pos++;
		dec = dec / 2;	
		i = i * 10;
	}
	// dao chuoi
	n = pos;
	changeArr(A, B, n);
}

void output(int A[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
}

int main()
{
	int A[SIZE], n, x;
	input(x);
	changeDecToBin(A, n, x);
	output(A, n);
	system("pause");
	return 0;

}