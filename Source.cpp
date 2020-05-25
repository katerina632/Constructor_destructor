#include<iostream>
#include "MyRectangle.h"
#include "Student.h"

using namespace std;

int main() {

	//Zavdannja 1
	MyRectangle first;
	MyRectangle second(5);
	MyRectangle third(3,5);

	first.Print();
	second.Print();
	third.Print();

	second.SetSymbol('@');
	second.ChangeSize(2, 5);
	second.ChangeCoord(2, 3);

	second.Print();
	cout << endl;

	//Zavdannja 2
	Student firstStudent;
	Student secondStudent("Bob", 20);
	Student thirdStudent;

	firstStudent.SetName("Ben");
	firstStudent.SetAge(22);

	firstStudent.AddMark(12);
	firstStudent.AddMark(10);
	firstStudent.Save();
	firstStudent.Print();
	cout << endl;
	cout << secondStudent.GetName() << " - " << secondStudent.GetAge() << " years old" << endl;
	cout << endl;
	thirdStudent.Load();
	thirdStudent.Print();	

	system("pause");
	return 0;

}