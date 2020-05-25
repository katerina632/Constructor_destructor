#include "Student.h"
#include<fstream>
#include<iostream>

using namespace std;

const string fileName = "StudentProfile.txt";

void Student::CalcAverageMark()
{
	float sum = 0;
	for (int i = 0; i < countMarks; i++)
	{
		sum += marksArr[i];
		avgMark = sum / countMarks;
	}
}

Student::Student()
{
	marksArr = nullptr;
	name = nullptr;
	SetName("No name");
	age = 0;
	avgMark = 0;
}

Student::Student(const char* _name, int _age) : Student()
{
	name = nullptr;
	SetName(_name);

	if (IsValidAge(_age))
	{
		age = _age;
	}
	else { age = 0; }
}

void Student::DelMemory() const
{
	if (name != nullptr) {
		delete[] name;
	}
	if (marksArr != nullptr) {
		delete[] marksArr;
	}
}

const char* Student::GetName() const
{
	return name;
}

int Student::GetAge() const
{
	return age;
}

void Student::SetName(const char* _name)
{
	if (name != nullptr) {
		delete[] name;
	}
	int size = strlen(_name) + 1;
	name = new char[size];
	strcpy_s(name, size, _name);
}

void Student::SetAge(int _age)
{
	if (IsValidAge(_age)) {
		age = _age;
	}
}

void Student::AddMark(int value)
{
	int* newMarksArr = new int[countMarks + 1];

	for (int i = 0; i < countMarks; i++) {
		newMarksArr[i] = marksArr[i];
	}
	newMarksArr[countMarks] = value;

	delete[] marksArr;
	marksArr = newMarksArr;
	++countMarks;

	CalcAverageMark();
}

void Student::Print() const
{
	cout << "------ STUDENT ------" << endl;
	if (name != nullptr)
		cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Marks: ";
	for (int i = 0; i < countMarks; i++)
	{
		cout << marksArr[i];
		if (i == countMarks - 1) {
			cout << " ";
		}
		else {
			cout << ",";
		}

	}
	cout << endl;
	cout << "Average mark: " << avgMark << endl;
	cout << "-----------------------" << endl;
}

void Student::Save()
{
	ofstream fout;
	fout.open(fileName);
	bool isOpen = fout.is_open();
	if (isOpen == true) {

		fout << name << endl;
		fout << age << endl;
		fout << countMarks << endl;
		for (int i = 0; i < countMarks; i++) {
			fout << marksArr[i] << endl;
		}
		fout << avgMark << endl;
	}
	else {
		cout << "Error!" << endl;
	}
	fout.close();
}

void Student::Load()
{
	ifstream fin;
	fin.open(fileName);

	bool isOpen = fin.is_open();
	if (isOpen == true) {		

		char newName[50];
		fin.getline(newName, 50);
		SetName(newName);

		fin >> age;
		fin >> countMarks;
		delete[] marksArr;
		marksArr = new int[countMarks];

		for (int i = 0; i < countMarks; i++) {

			fin >> marksArr[i];
		}
		fin >> avgMark;
	}
	else {
		cout << "Error!" << endl;
	}
	fin.close();
}

