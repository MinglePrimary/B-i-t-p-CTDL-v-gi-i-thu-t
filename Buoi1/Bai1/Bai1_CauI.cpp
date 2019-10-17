//Nhập mảng 1 chiều có N phần tử, mỗi phần tử có kiểu dữ liệu là 1 số nguyên.Hãy
//thực hiện các yêu cầu sau bằng ngôn ngữ lập trình C.
// i. Đếm số phần tử có giá trị bằng X trong mảng. Nếu không có thì thông báo không có.

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
	int position = 0;
	for (int i = 0; i < n; i++)
		if (A[i] == x)
		{
			position ++;
		}
	return position;
}

void output(int res)
{
	//if (res == 0) printf("(!) cound not find x in array\n");
	
	printf("-> %d ", res);
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