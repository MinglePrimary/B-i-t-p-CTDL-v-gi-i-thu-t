//Bài 2: Dùng mảng một chiều để lưu trữ một lớp học có N sinh viên.Biết rằng mỗi sinh viên
//bao gồm các thông tin sau : Tên(chuỗi ký tự), Mã số sinh viên(chuỗi ký tự), Điểm trung bình.
//Hãy viết hàm thực hiện các yêu cầu sau :
//a.In danh sách sinh viên ra màn hình

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
	MyClass.SHead = MyClass.STail= NULL;
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
		cout <<"Hoc sinh: "<< i->Name <<" MSSV: "<< i->ID <<" Diem: "<< i->DiemTrungBinh<<";"<<endl;
		count++;
	}
}

int main()
{
	int n;
	Class MyClass;
	initClass(MyClass);
	inputClass(MyClass, n);
	outputClass(MyClass);
	system("pause");
	return 0;
}