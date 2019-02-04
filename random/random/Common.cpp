#include <iostream>
#include <string>
#include <cassert>
#include "Common.h"

int getUserIntRanged(int rangeMin, int rangeMax)
{
	while (true)
	{
		std::cout << "please enter a number: ";
		int userNum;
		std::cin >> userNum;

		if (std::cin.fail())
		{
			std::cin.clear(); //reset error flag
			std::cin.ignore(32767, '\n'); //empty buffer
			std::cout << "wrong data type! Retry\n";
		}
		else if (userNum < rangeMin || userNum > rangeMax)
		{
			std::cout << "wrong range (" << rangeMin << "-" << rangeMax << ")! Retry\n";
		}
		else
		{
			std::cin.ignore(32767, '\n'); //empty buffer
			return userNum;
		}
	}
}

int getUserInteger()
{
	while (true)
	{
		//std::cout << "please enter a number: ";
		int userNum;
		std::cin >> userNum;

		if (std::cin.fail())
		{
			std::cin.clear(); //reset error flag
			std::cin.ignore(32767, '\n'); //empty buffer
			std::cout << "wrong data type! Retry\n";
		}
		else
		{
			std::cin.ignore(32767, '\n'); //empty buffer
			return userNum;
		}
	}
}

std::string getUserString()
{
	while (true)
	{
		//std::cout << "please enter text: ";
		std::string userText;
		std::cin >> userText;

		if (std::cin.fail())
		{
			std::cin.clear(); //reset error flag
			std::cin.ignore(32767, '\n'); //empty buffer
			std::cout << "wrong data type! Retry\n";
		}
		else
		{
			std::cin.ignore(32767, '\n'); //empty buffer
			return userText;
		}
	}
}

char getUserChar()
{
	while (true)
	{
		//std::cout << "please enter text: ";
		char userChar;
		std::cin >> userChar;

		if (std::cin.fail())
		{
			std::cin.clear(); //reset error flag
			std::cin.ignore(32767, '\n'); //empty buffer
			std::cout << "wrong data type! Retry\n";
		}
		else
		{
			std::cin.ignore(32767, '\n'); //empty buffer
			return userChar;
		}
	}
}

void printIntArray(int *arrayPointer, int arrayLength)
{
	std::cout << "{ ";
	for (int *pointer = arrayPointer; pointer < (arrayPointer + arrayLength); ++pointer)
	{
		if (pointer > arrayPointer)
		{
			std::cout << ", ";
		}
		std::cout << *pointer;
	}
	std::cout << " }";
	return;
}

void printStringArray(std::string *arrayPointer, int arrayLength)
{
	std::cout << "{ ";
	for (std::string *pointer = arrayPointer; pointer < (arrayPointer + arrayLength); ++pointer)
	{
		if (pointer > arrayPointer)
		{
			std::cout << ",\n  ";
		}
		std::cout << *pointer;
	}
	std::cout << " }\n";
	return;
}

void bubbleSortIntArray(int *arrayPointer, int arrayLength)
{
	std::cout << "Original array:\n";
	printIntArray(arrayPointer, arrayLength);
	std::cout << "\n";
	int sorted = 0;
	// outer loop bubbling the highest element to the end of the unsorted array
	for (int *i = arrayPointer; i < (arrayPointer + arrayLength); ++i)
	{
		int lastSwapIndex = 0;
		int innerIndex = 0;
		// inner loop swapping each unsorted element
		for (int *j = arrayPointer; j < (arrayPointer + arrayLength - sorted - 1); ++j)
		{
			if (*j > *(j + 1))
			{
				std::swap(*j, *(j + 1));
				std::cout << "swapping elements " << *j << " and " << *(j + 1) << ". New array:\n";
				printIntArray(arrayPointer, arrayLength);
				std::cout << "\n";
				lastSwapIndex = innerIndex + 1;
			}
			++innerIndex;
		}
		sorted = arrayLength - lastSwapIndex;
		std::cout << "inner loop complete, " << sorted << " elments bubbled to the end of array:\n";
		printIntArray(arrayPointer, arrayLength);
		std::cout << "\n";
		if (lastSwapIndex == 1)
		{
			std::cout << "complete!\n";
			break;
		}
	}
	return;
}

void bubbleSortStringArray(std::string *arrayPointer, int arrayLength)
{
	std::cout << "Original array:\n";
	printStringArray(arrayPointer, arrayLength);
	std::cout << "\n";
	int sorted = 0;
	// outer loop bubbling the highest element to the end of the unsorted array
	for (std::string *i = arrayPointer; i < (arrayPointer + arrayLength); ++i)
	{
		int lastSwapIndex = 0;
		int innerIndex = 0;
		// inner loop swapping each unsorted element
		for (std::string *j = arrayPointer; j < (arrayPointer + arrayLength - sorted - 1); ++j)
		{
			if (*j > *(j + 1))
			{
				std::swap(*j, *(j + 1));
				std::cout << "swapping elements " << *j << " and " << *(j + 1) << ". New array:\n";
				printStringArray(arrayPointer, arrayLength);
				std::cout << "\n";
				lastSwapIndex = innerIndex + 1;
			}
			++innerIndex;
		}
		sorted = arrayLength - lastSwapIndex;
		std::cout << "inner loop complete, " << sorted << " elments bubbled to the end of array:\n";
		printStringArray(arrayPointer, arrayLength);
		std::cout << "\n";
		if (lastSwapIndex == 1)
		{
			std::cout << "complete!\n";
			break;
		}
	}
	return;
}


void populateNameArray(std::string *arrayPointer, int arrayLength)
{
	int counter = 0;
	for (std::string *currentPtr = arrayPointer; currentPtr < (arrayPointer + arrayLength); ++currentPtr)
	{
		std::cout << "Enter name #" << counter << ": ";

		while (true)
		{
			//std::cout << "please enter text: ";
			std::string userText;
			std::cin >> userText;

			if (std::cin.fail())
			{
				std::cin.clear(); //reset error flag
				std::cin.ignore(32767, '\n'); //empty buffer
				std::cout << "wrong data type! Retry\n";
			}
			else
			{
				std::cin.ignore(32767, '\n'); //empty buffer
				*currentPtr = userText;
				break;
			}
		}
		++counter;
	}
	return;
}



void printStudentArray(Student *arrayPointer, int numberStudents)
{
	std::cout << "{ ";
	for (Student *pointer = arrayPointer; pointer < (arrayPointer + numberStudents); ++pointer)
	{
		if (pointer > arrayPointer)
		{
			std::cout << ",\n  ";
		}
		std::cout << (*pointer).name << ", " << (*pointer).score;
	}
	std::cout << " }\n";
	return;
}

void bubbleSortStudentArray(Student *arrayPointer, int numberStudents)
{
	std::cout << "Original array:\n";
	printStudentArray(arrayPointer, numberStudents);
	std::cout << "\n";
	int sorted = 0;
	// outer loop bubbling the highest element to the end of the unsorted array
	for (int i = 0; i < numberStudents; ++i)
	{
		int lastSwapIndex = 0;
		int innerIndex = 0;
		// inner loop swapping each unsorted element
		for (int j = 0; j < (numberStudents - sorted - 1); ++j)
		{
			if ((arrayPointer[j]).score < (arrayPointer[j + 1]).score)
			{
				std::swap((arrayPointer[j]), (arrayPointer[j + 1]));
				std::cout << "swapping students " << (arrayPointer[j]).name << "(" << (arrayPointer[j]).score << ") and " << (arrayPointer[j + 1]).name << "(" << (arrayPointer[j + 1]).score << "). New array:\n";
				printStudentArray(arrayPointer, numberStudents);
				std::cout << "\n";
				lastSwapIndex = innerIndex + 1;
			}
			++innerIndex;
		}
		sorted = numberStudents - lastSwapIndex;
		std::cout << "inner loop complete, " << sorted << " elments bubbled to the end of array:\n";
		printStudentArray(arrayPointer, numberStudents);
		std::cout << "\n";
		if (lastSwapIndex == 1)
		{
			std::cout << "Sorting complete!\n";
			break;
		}
	}
	return;
}


void printCStyleString(char *stringPtr)
{
	do
	{
		if (*stringPtr == '\0')
		{
			return;
		}
		else
		{
			std::cout << *stringPtr;
		}
		++stringPtr;
	} while (true);
}

int binarySearch(int *array, int target, int min, int max)
{
	assert(array); // make sure array exists

	int upperBound = max, lowerBound = min;
	
	// check to rule out the obvious
	if (array[upperBound] == target)
	{
		return upperBound;
	}
	else if (array[lowerBound] == target)
	{
		return lowerBound;
	}
	else if (target < array[lowerBound])
	{
		return -1; // out of bounds
	}
	else if (target > array[upperBound])
	{
		return -1; // out of bounds
	}
	
	// check end points, then cut in half until found or finished
	int middle;
	do
	{
		middle = (upperBound - lowerBound) / 2 + lowerBound;
		if (array[middle] == target)
		{
			return middle;
		}
		else if ( (upperBound - lowerBound) <= 2 )
		{
			return -1; // it is neither upper, lower, nor middle and there are no numbers
		}
		else if (target < array[middle])
		{
			upperBound = middle;
		}
		else if (target > array[middle])
		{
			lowerBound = middle;
		}
	} while (true);
}