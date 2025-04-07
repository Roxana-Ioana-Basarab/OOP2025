#include "Student.h"
#include <stdio.h>
#include <vcruntime_string.h>

void Student::SetName(const char* Name, int Size)
{
	this->name = new char[Size + 1];
	memcpy(this->name, Name, Size);
	this->name[Size] = '\0';
}

const char * Student::GetName()
{
	return this->name;
}

void Student::SetMath(float x)
{
	if (x > 1.0f && x < 10.0f)
	this->grade.math = x;
}

float Student::GetMath()
{
	if(this->grade.math>1.0f && this->grade.math < 10.0f)
	return this->grade.math;

	return 0;
}

void Student::SetEng(float x)
{
	if (x > 1.0f && x < 10.0f)
	this->grade.english = x;
}

float Student::GetEng()
{
	if (this->grade.english > 1.0f && this->grade.english < 10.0f)
	return this->grade.english;

	return 0;
}

void Student::SetHys(float x)
{
	if (x > 1.0f && x < 10.0f)
	this->grade.history = x;
}

float Student::GetHys()
{
	if (this->grade.history > 1.0f && this->grade.history < 10.0f)
	return this->grade.history;

	return 0;
}

float Student::Average()
{
	return (GetHys() + GetMath() + GetEng()) / 3;
}