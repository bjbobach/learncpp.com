#include <iostream>
#include <string>
#include <array>
#include <random>
#include <ctime>
#include "Cards.h"
#include "Common.h"






bool getUserHit()
{
	while (true)
	{
		char input = getUserChar();
		if (input == 'h')
		{
			std::cout << "You hit.\n";
			return true;
		}
		else if (input == 's')
		{
			std::cout << "You stand.\n";
			return false;
		}
		else
		{
			std::cout << "Invalid input. Retry using 'h' for hit and 's' for stand.\n";
		}
	}
}

void blackJackSimple(const std::array<Card, 52> &deckRef)
{
	const Card *cardPtr{ &(deckRef[0]) };
	int scoreDealer{ 0 };
	int scorePlayer{ 0 };
	while (true)
	{
		std::cout << "First card Dealer: ";
		printCard(*cardPtr);
		scoreDealer += getCardValue(*cardPtr++);
		std::cout << ", total value: " << scoreDealer << "\n";

		std::cout << "First card Player: ";
		printCard(*cardPtr);
		scorePlayer += getCardValue(*cardPtr++);
		std::cout << "\n";
		
		do
		{
			std::cout << "Next card Player: ";
			printCard(*cardPtr);
			scorePlayer += getCardValue(*cardPtr++);
			std::cout << ", total value: " << scorePlayer << "\n";

			if (scorePlayer > 20)
			{
				break;
			}

			std::cout << "Hit or Stand? Type 'h' or 's'\n";
		} while (getUserHit());

		if (scorePlayer > 21)
		{
			std::cout << "You are bust. You lose!\n\n";
			break;
		}
		else if (scorePlayer == 21)
		{
			std::cout << "Black Jack! You win!\n\n";
			break;
		}

		while (scoreDealer < 17 && scoreDealer < scorePlayer)
		{
			std::cout << "Next card Dealer: ";
			printCard(*cardPtr);
			scoreDealer += getCardValue(*cardPtr++);
			std::cout << ", total value: " << scoreDealer << "\n";
			if (scoreDealer > 20)
			{
				break;
			}
		}

		if (scoreDealer > 21)
		{
			std::cout << "Dealer is bust. You win!\n\n";
			break;
		}
		else if (scoreDealer == 21)
		{
			std::cout << "Black Jack! You lose!\n\n";
			break;
		}
		else if (scorePlayer > scoreDealer)
		{
			std::cout << "Dealer Stands, your hand is better. You win!\n\n";
			break;
		}
		else
		{
			std::cout << "Dealer Stands, your hand is not better. You lose!\n\n";
			break;
		}
	}
	return;
}