//Bài 2: Dùng mảng một chiều để lưu trữ một lớp học có N sinh viên.Biết rằng mỗi sinh viên
//bao gồm các thông tin sau : Tên(chuỗi ký tự), Mã số sinh viên(chuỗi ký tự), Điểm trung bình.
//Hãy viết hàm thực hiện các yêu cầu sau :
//d. Tìm một sinh viên có tên X trong lớp học (X nhập từ bàn phím)

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

struct Student
{
	string Name;
	string ID;
	int DiemTrungBinh;
	Student *SNext;
};

struct Class
{
	Student *SHead;
	Student *STail;
};	

void initClass(Class &MyClass)
{
	MyClass.SHead = MyClass.STail= NULL;
}

Student *createStudent(string Name, string ID, int Dtb)
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
		int Dtb;
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
		cout <<"Hoc sinh: "<< i->Name <<" MSSV: "<< i->ID <<" Diem: "<< i->DiemTrungBinh<<";"<<endl;
		count++;
	}
}

void sortStudent(Class &myClass)
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
		if (q->DiemTrungBinh > pivot->DiemTrungBinh)
			addClass(myClass1, q);
		else
			addClass(myClass2, q);
	};

	sortStudent(myClass1);
	sortStudent(myClass2);
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

void checkNStudent_Name(Class MyClass)
{
	string XName;
	bool flag=false;
	printf("?Student's name: ");
	cin >> XName;
	for (Student *i = MyClass.SHead; i != NULL; i = i->SNext)
		if (i->Name == XName)
		{
			cout << "ID: " << i->ID;
			flag = true;
			break;
		}
	if (flag == false)
		printf("\n!Not found\n");
}

int main()
{
	int n;
	Class MyClass;
	initClass(MyClass);
	inputClass(MyClass, n);
	//outputClass(MyClass);
	sortStudent(MyClass);
	//outputClass(MyClass);
	checkNStudent_Name(MyClass);
	system("pause");
	return 0;
}