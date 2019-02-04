#pragma once


class Stack
{
	int length;
	int array[10];

public:
	void reset();
	bool push(int val);
	int pop();
	void print();

private:

};

class Fraction
{
	int m_num;
	int m_den;
public:
	Fraction(int num = 0, int den = 1);
	void print();
	double eval();
	void reduce();

	friend Fraction operator*(const Fraction &f1, const Fraction &f2);
	friend Fraction operator*(const Fraction &f1, int factor);
	friend Fraction operator*(int factor, const Fraction &f2);

	friend std::ostream& operator<<(std::ostream &out, const Fraction &f);
	friend std::istream& operator>>(std::istream &out, Fraction &f);
private:

};

class Car
{
	std::string m_make;
	std::string m_model;
public:
	Car(std::string make, std::string model);

	friend std::ostream& operator<<(std::ostream &out, Car &car);
	friend bool operator< (Car &c1, Car &c2);
	friend bool operator<= (Car &c1, Car &c2);
	friend bool operator> (Car &c1, Car &c2);
	friend bool operator>= (Car &c1, Car &c2);

private:

};

class GradeMap
{
	std::vector<StudentGrade> m_map;
public:
	GradeMap();

	char& operator[](const std::string &name);

private:

};

