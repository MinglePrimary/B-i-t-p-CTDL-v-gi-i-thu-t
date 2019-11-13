//Bài 2: Dùng mảng một chiều để lưu trữ một lớp học có N sinh viên.Biết rằng mỗi sinh viên
//bao gồm các thông tin sau : Tên(chuỗi ký tự), Mã số sinh viên(chuỗi ký tự), Điểm trung bình.
//Hãy viết hàm thực hiện các yêu cầu sau :
//f.Sắp xếp danh sách sinh viên tăng theo điểm trung bình bằng thuật toán sắp xếp mà
//các bạn đã học(Selection Sort, Interchange Sort, Bubble Sort, Insertion Sort, Quick Sort)

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

struct Student
{
	string Name;
	string ID;
	double DiemTrungBinh;
	Student *SNext;
};

struct Class
{
	Student *SHead;
	Student *STail;
};

void initClass(Class &MyClass)
{
	MyClass.SHead = MyClass.STail = NULL;
}

Student *createStudent(string Name, string ID, double Dtb)
{
	Student *student = new Student;
	if (student == NULL)
		return NULL;
	student->Name = Name;
	student->ID = ID;
	student->DiemTrungBinh = Dtb;
	student->SNext = NULL;
	return student;
}

bool isEmptyClass(Class MyClass)
{
	if (MyClass.SHead == NULL)
		return true; // danh sach rong
	return false; // danh sach ko rong
}

void addClass(Class &MyClass, Student *student)
{
	if (isEmptyClass(MyClass))
	{
		MyClass.SHead = MyClass.STail = student;
	}
	else
	{
		student->SNext = MyClass.SHead;
		MyClass.SHead = student;
	}
}
void inputClass(Class &MyClass, int &n)
{
	printf("?N student: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		string Name, ID;
		double Dtb;
		printf("*Number %d:\n", i);
		printf("Name: ");
		cin >> Name;
		printf("MSSV: ");
		cin >> ID;
		printf("Diem trung binh: ");
		cin >> Dtb;
		Student *sv = createStudent(Name, ID, Dtb);
		addClass(MyClass, sv);
	}
}
void outputClass(Class MyClass)
{
	printf("! Check class: \n");
	int count = 0;
	for (Student *i = MyClass.SHead; i != NULL; i = i->SNext)
	{
		printf("*Number %d: ", count);
		cout << "Hoc sinh: " << i->Name << " MSSV: " << i->ID << " Diem: " << i->DiemTrungBinh << ";" << endl;
		count++;
	}
}

void sortStudent_QuickSort(Class &myClass)
{
	Class myClass1;
	Class myClass2;
	initClass(myClass1);
	initClass(myClass2);
	Student *p, *pivot;
	if (myClass.SHead == myClass.STail)
		return;
	pivot = myClass.SHead;
	p = myClass.SHead->SNext;
	while (p != NULL)
	{
		Student *q = p;
		p = p->SNext;
		q->SNext = NULL;
		if (q->DiemTrungBinh < pivot->DiemTrungBinh)
			addClass(myClass1, q);
		else
			addClass(myClass2, q);
	};

	sortStudent_QuickSort(myClass1);
	sortStudent_QuickSort(myClass2);
	// ghep noi ds 1 + pivot
	if (!isEmptyClass(myClass1))
	{
		myClass.SHead = myClass1.SHead;
		myClass1.STail->SNext = pivot;
	}
	else
		myClass.SHead = pivot;
	// ghep noi pivot + ds 2
	pivot->SNext = myClass2.SHead;
	if (!isEmptyClass(myClass2))
		myClass.STail = myClass2.STail;
	else
		myClass.STail = pivot;
}

/* Bubble sort the given linked list */
void sortStudent_BubbleSort(Student *start)
{
	int swapped, i;
	Student *ptr1;
	Student *lptr = NULL;

	/* Checking for empty list */
	if (start == NULL)
		return;

	do
	{
		swapped = 0;
		ptr1 = start;

		while (ptr1->SNext != lptr)
		{
			if (ptr1->DiemTrungBinh > ptr1->SNext->DiemTrungBinh)
			{
				swap(ptr1, ptr1->SNext);
				swapped = 1;
			}
			ptr1 = ptr1->SNext;
		}
		lptr = ptr1;
	} while (swapped);
}

/* function to swap data of two nodes a and b*/
void swap(Student *a, Student *b)
{
	double Temp = a->DiemTrungBinh;
	a->DiemTrungBinh = b->DiemTrungBinh;
	b->DiemTrungBinh = Temp;
}

int main()
{
	int n;
	Class MyClass;
	initClass(MyClass);
	inputClass(MyClass, n);
	//sortStudent_QuickSort(MyClass);
	sortStudent_BubbleSort(MyClass.SHead);
	outputClass(MyClass);
	system("pause");
	return 0;
}