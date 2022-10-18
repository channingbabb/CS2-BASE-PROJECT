#include <iostream>
#include "graph1.h"
#include "CardPlayer.h"

CardPlayer::CardPlayer()
{
	noCards = 0;
	color = NULL;
	hand = NULL;
}

CardPlayer::~CardPlayer()
{
	delete[] hand;
}
void CardPlayer::setNoCards(int noCards)
{
	if (noCards < 5) {
		hand = new int[5];
	}
	else if (noCards > 10) {
		hand = new int[10];
	}
	else {
		this->noCards = noCards;
	}
	hand = new int[this->noCards];
}

int CardPlayer::getNoCards()
{
	return this->noCards;
}

void CardPlayer::setColor(char color)
{
	this->color = color;
}

void CardPlayer::displayHand(int x, int y)
{
	// red == diamond
	// black == spades
	string prefix;
	if (color == 'r') {
		prefix = "d";
	}
	else if (color == 'b') {
		prefix = "s";
	}
	for (int i = 0; i < noCards; i++) {
		if (i != 0) {
			y = y + 20;
		}
		int card = displayBMP(prefix + to_string(hand[i]) + ".bmp", x, y);
	}
}

int CardPlayer::computeScore()
{

	int score = 0;
	for (int i = 0; i < noCards; i++)
	{
		// face card, not ace
		if (hand[i] >= 10 && hand[i] < 14) {
			score = score + 10;
		}
		else if (hand[i] == 14) {
			score = score + 11;
		}
		else {
			score = score + hand[i];
		}
	}
	return score;
}

//Implemented for you
void CardPlayer::deal()
{
	bool duplicate = false;


	for (int i = 0; i < noCards; i++)
	{
		hand[i] = rand() % 13 + 2;

		do
		{
			duplicate = false;
			for (int j = 0; j < i; j++)
			{
				if (hand[i] == hand[j])
				{
					hand[i] = rand() % 13 + 2;
					duplicate = true;
					break;
				}
			}
		} while (duplicate);
	}

}
