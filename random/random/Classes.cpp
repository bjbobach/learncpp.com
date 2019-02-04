#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "Common.h"
#include "Classes.h"

void Stack::reset()
{
	length = 0;
	for (int i = 0; i<10; i++)
	{
		array[i] = 0;
	}
}

bool Stack::push(int val)
{
	if (length >= 10)
	{
		return false;
	}
	else
	{
		array[length++] = val;
		return true;
	}
}

int Stack::pop()
{
	assert(length > 0 && "Pop not possible -> Stack empty");
	return array[--length];
}

void Stack::print()
{
	std::cout << "(";
	for (int i = 0; i<length; i++)
	{
		if (i != 0)
		{
			std::cout << ", ";
		}
		std::cout << array[i];
	}
	std::cout << ")\n";
}

Fraction::Fraction(int num, int den)
	: m_num(num),
	m_den(den)
{
	reduce();
}

void Fraction::print()
{
	std::cout << m_num << "/" << m_den << "\n";
}

double Fraction::eval()
{
	return static_cast<double>(m_num) / static_cast<double>(m_den);
}

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
	return Fraction( (f1.m_num * f2.m_num), (f1.m_den * f2.m_den));
}

Fraction operator*(const Fraction &f1, int factor)
{
	return Fraction((f1.m_num * factor), (f1.m_den));
}

Fraction operator*(int factor,const Fraction &f2)
{
	return f2*factor;
}

int gcd(int a, int b)
{
	return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
}

void Fraction::reduce()
{
	int cd = gcd(m_num, m_den);
	m_num /= cd;
	m_den /= cd;
}

std::ostream& operator<<(std::ostream &out, const Fraction &f)
{
	return out << f.m_num << "/" << f.m_den;
}

std::istream& operator>>(std::istream &in, Fraction &f)
{
	char c;

	in >> f.m_num;
	in >> c;
	in >> f.m_den;

	f.reduce();

	return in;
}


Car::Car(std::string make, std::string model) : m_make(make), m_model(model){}

std::ostream& operator<<(std::ostream &out, Car &car)
{
	return out << "(" << car.m_make << ", " << car.m_model << ")\n";
}

bool operator< (Car &c1, Car &c2)
{
	if (c1.m_make == c2.m_make)
	{
		return (c1.m_model < c2.m_model);
	}
	else
	{
		return (c1.m_make < c2.m_make);
	}
}

bool operator<= (Car &c1, Car &c2)
{
	if (c1.m_make == c2.m_make)
	{
		return (c1.m_model <= c2.m_model);
	}
	else
	{
		return (c1.m_make <= c2.m_make);
	}
}

bool operator> (Car &c1, Car &c2)
{
	return !(c1 <= c2);
}

bool operator>= (Car &c1, Car &c2)
{
	return !(c1 < c2);
}

GradeMap::GradeMap()
{
}

char& GradeMap::operator[](const std::string &name)
{
	for (StudentGrade &student : m_map)
	{
		if (student.name == name)
		{
			return student.grade;
		}
	}
	StudentGrade newStudent{ name, ' ' };
	m_map.push_back(newStudent);
	return m_map.back().grade;
}