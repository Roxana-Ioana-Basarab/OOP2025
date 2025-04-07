#pragma once
#include <stdio.h>;
#include <cstring>;
using namespace std;

class Number
{
	char* value;
	int base;

	void setValue(const char* newValue);
public:
	
	Number(const char* v, int b);
	~Number();

	//copy constructor
	Number(const Number& a);
	//move constructor
	Number(Number&& a) noexcept;

	

	// +, -, [], >, <, >=, <=, == operators

	Number& operator=(const Number& a);
	Number& operator=(Number&& a) noexcept;

	friend Number operator+(const Number& n1, const Number& n2);
	friend Number operator-(const Number& n1, const Number& n2);

	friend int convertToBase10(const char* m, int b);
	friend int pow(int a, int p);
	friend int charToInt(char c);

	bool operator>(const Number& a)const;
	bool operator<(const Number& a)const;
	bool operator>=(const Number& a)const;
	bool operator<=(const Number& a)const;
	bool operator==(const Number& a)const;
	
	char operator[](int ind) const;

	Number& operator--();

	Number operator--(int);

	void SwitchBase(int newBase);
	void Print() const;
	int GetDigitCount() const;
	int GetBase() const;

};

