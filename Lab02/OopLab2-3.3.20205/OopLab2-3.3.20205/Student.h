#pragma once
class Student
{
	char* name;
	struct Grades{
		float math, english, history;
	}grade;

public:
	void SetName(const char* Name, int Size);
	const char* GetName();

	void SetMath(float x);
	float GetMath();

	void SetEng(float x);
	float GetEng();

	void SetHys(float x);
	float GetHys();

	float Average();



};

