// random.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <utility> // for std::swap
#include <array>
#include <vector>
#include <random>
#include <ctime>
#include <cassert>
#include <cstdint>
#include "Common.h"
//#include "Cards.h"
#include "Classes.h"

enum class Animal
{
	PIG,
	CHICKEN,
	GOAT,
	CAT,
	DOG,
	OSTRICH
};
	
std::string getAnimalName(Animal a)
{
	switch (a)
	{
	case Animal::PIG:
		return "Pig";
	case Animal::CHICKEN:
		return "Chicken";
	case Animal::GOAT:
		return "Goat";
	case Animal::CAT:
		return "Cat";
	case Animal::DOG:
		return "Dog";
	case Animal::OSTRICH:
		return "Ostrich";
	default:
		return "Invalid animal type";
	}
}

void printNumberOfLegs(Animal a)
{
	int legs;
	switch (a)
	{
		case Animal::PIG:
		case Animal::DOG:
		case Animal::GOAT:
		case Animal::CAT:
			legs = 4;
			break;

		case Animal::CHICKEN:
		case Animal::OSTRICH:
			legs = 2;
			break;

		default:
			std::cout << "error!";
			return;
	}
	std::cout << "A " << getAnimalName(a) << " has " << legs << " legs.\n";
}


void quizStringArray()
{
	std::cout << "enter Number of strings: ";
	int arrayLength = getUserInteger();
	std::string *nameArray = new std::string[arrayLength];
	populateNameArray(nameArray, arrayLength);
	std::cout << "Your array of strings:\n";
	printStringArray(nameArray, arrayLength);
	std::cout << "Sorting strings:\n";
	bubbleSortStringArray(nameArray, arrayLength);
	delete[] nameArray;
	return;
}



void quizStudentStruct()
{
	int minGrade{ 0 }, maxGrade{ 100 };
	std::cout << "Enter number of students: "; 
	int numberStudents = getUserInteger();
	Student *studentArray = new Student[numberStudents];
	for (int i = 0; i < numberStudents; ++i)
	{
		std::cout << "\nEnter name #" << i + 1 << ": \n";
		(studentArray[i]).name = getUserString();
		std::cout << "\nEnter grade of " << (studentArray[i]).name << ": \n";
		(studentArray[i]).score = getUserIntRanged(minGrade, maxGrade);
	}
	bubbleSortStudentArray(studentArray, numberStudents);
	delete[] studentArray;
	return;
}

/*
void playCards()
{
	std::array<Card, 52> deck;
	using index_t = std::array<Card, 52>::size_type;
	index_t counter{ 0 };
	for (int suit = 0; suit < static_cast<int>(Suits::MAX_SUITS); ++suit)
	for (int rank = 0; rank < static_cast<int>(Ranks::MAX_RANKS); ++rank)
	{
		deck[counter].suit = static_cast<Suits>(suit);
		deck[counter].rank = static_cast<Ranks>(rank);
		++counter;
	}
	//printDeck(deck);
	std::cout << "\nShuffling...\n";
	shuffleDeck(deck);
	std::cout << "\nDone!\n";
	//printDeck(deck);
	blackJackSimple(deck);
}
*/

void testBinarySearch()
{
	int array[] = { 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

	// We're going to test a bunch of values to see if they produce the expected results
	const int numTestValues = 9;
	// Here are the test values
	int testValues[numTestValues] = { 0, 3, 12, 13, 22, 26, 43, 44, 49 };
	// And here are the expected results for each value
	int expectedValues[numTestValues] = { -1, 0, 3, -1, -1, 8, -1, 13, -1 };

	// Loop through all of the test values
	for (int count = 0; count < numTestValues; ++count)
	{
		// See if our test value is in the array
		int index = binarySearch(array, testValues[count], 0, 14);
		// If it matches our expected value, then great!
		if (index == expectedValues[count])
			std::cout << "test value " << testValues[count] << " passed!\n";
		else // otherwise, our binarySearch() function must be broken
			std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
	}
	return;
}

class Point3d
{
	double coord_x;
	double coord_y;
	double coord_z;
public:
	void setValues(double x, double y, double z)
	{
		coord_x = x;
		coord_y = y;
		coord_z = z;
	}
	void print()
	{
		std::cout << "<" << coord_x << ", " << coord_y << ", " << coord_z << ">";
	}
	bool isEqual(Point3d &point)
	{
		if (point.coord_x == coord_x && point.coord_y == coord_y && point.coord_z == coord_z)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};



class RGBA
{
private:
	std::uint_fast8_t m_red;
	std::uint_fast8_t m_green;
	std::uint_fast8_t m_blue;
	std::uint_fast8_t m_alpha;

public:
	RGBA(std::uint_fast8_t r = 0, std::uint_fast8_t b = 0, std::uint_fast8_t g = 0, std::uint_fast8_t a = 255)
		: m_red(r),
		m_green(g),
		m_blue(b),
		m_alpha(a)
	{
	}
	void print()
	{
		std::cout << "<" << static_cast<int>(m_red) << ", " << static_cast<int>(m_green) << ", " << static_cast<int>(m_blue) << ", " << static_cast<int>(m_alpha) << ">";
	}
};



int main()
{
	GradeMap grades;
	grades["Joe"] = 'A';
	grades["Frank"] = 'B';
	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';
	//testBinarySearch();
	//playCards();
	//quizStudentStruct();
	//quizStringArray();
	return 0;
}

