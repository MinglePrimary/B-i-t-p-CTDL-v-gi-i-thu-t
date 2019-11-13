
#include <iostream>
#include <fstream>
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

void removeHead(Class &MyClass)
{
	Student *p;
	if (MyClass.SHead != NULL)
	{
		p = MyClass.SHead;					// b1: co lap phan tu head
		MyClass.SHead = MyClass.SHead->SNext; // b2: chon vtri pHead khac
		delete p;							// b3: xoa pHead ra khoi vung nho
		if (MyClass.SHead == NULL)
			MyClass.STail = NULL;
	}
}

void removeAfterP(Class &MyClass, Student *p)
{
	Student *q;
	if (p != NULL)
	{
		q = p->SNext;
		if (q != NULL)
		{
			p->SNext = q->SNext;
			if (q == MyClass.STail)
				MyClass.STail = p;
			delete q;
		}
	}
}

int deleteStudentX(Class &MyClass)
{
	string Mssv;
	printf("delete student <MSSV>: "); // UI console
	cin >> Mssv;
	if (isEmptyClass(MyClass)) return 0;
	Student *Temp1 = NULL;
	Student *Temp2 = MyClass.SHead;
	while (Temp2 != NULL && Temp2->ID != Mssv)
	{
		Temp1 = Temp2;
		Temp2 = Temp2->SNext;
	}
	if (Temp2 == NULL)  // ko tim thay
		return 0;
	if (Temp1 != NULL)  // tim thay ptu dung id
		removeAfterP(MyClass, Temp1);
	else				// phan tu la head
		removeHead(MyClass);
	return 1;
}


void outputFile(Class MyClass, int n)
{
	fstream f;
	f.open("D:\outputStudent.txt", ios::out);
	f <<"N= "<< n<< endl;
	for (Student *i = MyClass.SHead; i != NULL; i = i->SNext)
	{
		f << i->ID << " " << i->Name << " " << i->DiemTrungBinh << endl;
	}
	f.close();
}

	
int main()
{
	int n;
	Class MyClass;
	initClass(MyClass);
	inputClass(MyClass, n);
	int answer = deleteStudentX(MyClass);
	//cout <<"		key="<< answer <<" "<< endl;
	outputClass(MyClass);
	outputFile(MyClass, n);
	system("pause");
	return 0;
}