//Nhập mảng 1 chiều có N phần tử, mỗi phần tử có kiểu dữ liệu là 1 số nguyên.Hãy
//thực hiện các yêu cầu sau bằng ngôn ngữ lập trình C.
//h. Tìm một phần tử có khoá bằng X có hay không trong mảng (dùng thuật toán tìm
//kiếm tuyến tính)

#include <iostream>
#include <stdio.h>
#define SIZE 100

void input(int A[], int &n)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
}

void inputX(int &x)
{
	scanf("%d", &x);
}
int findValueX(int A[], int n, int x)
{
	int position = -1;
	for (int i = 0; i < n; i++)
		if (A[i] == x)
		{
			position = i;
			break;
		}
	return position;
}

void output(int res)
{
	if (res == -1) printf("(!) cound not find x in array\n");
	else
	printf("-> %d", res);
}

int main()
{
	int A[SIZE], n, x;
	printf("input n, A array: ");
	input(A, n);
	printf("input x: ");
	inputX(x);
	int result = findValueX(A, n, x);
	output(result);
	system("pause");
	return 0;
}