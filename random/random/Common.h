#pragma once


struct Student
{
	std::string name;
	int score;
};

struct StudentGrade
{
	std::string name;
	char grade;
};

int getUserIntRanged(int rangeMin, int rangeMax);
int getUserInteger();
std::string getUserString();
char getUserChar();
void printIntArray(int *arrayPointer, int arrayLength);
void printStringArray(std::string *arrayPointer, int arrayLength);
void bubbleSortIntArray(int *arrayPointer, int arrayLength);
void bubbleSortStringArray(std::string *arrayPointer, int arrayLength);
void populateNameArray(std::string *arrayPointer, int arrayLength);
void printStudentArray(Student *arrayPointer, int numberStudents);
void bubbleSortStudentArray(Student *arrayPointer, int numberStudents);
void printCStyleString(char *stringPtr);
int binarySearch(int *array, int target, int min, int max);