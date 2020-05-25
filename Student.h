#pragma once
class Student
{
private:

	char* name;
	int age;
	float avgMark;
	int* marksArr;
	int countMarks;
	
	bool IsValidAge(int age) const
	{
		return age >= 0 && age <= 100;
	}

	void CalcAverageMark();	
	void DelMemory() const;

public:
	
	Student();	

	Student(const char* _name, int _age);	

	~Student()
	{		
		DelMemory();
	}		
	
	const char* GetName() const;
	
	int GetAge() const;
	
	void SetName(const char* _name);	

	void SetAge(int _age);	

	void AddMark(int value);		

	void Print() const;
	
	void Save();

	void Load();
};

