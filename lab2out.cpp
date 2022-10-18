// Channing Babb
// Assignment: lab2out
// This program is a memory game where the user is asked to remember colors that are displayed randomly for a short period of time

#include <iostream>
#include <ctime>
#include "graph1.h"

using namespace std;

void getNoColors(int* no_colors);
void setColors(int* colors, int no_colors);
void getDelay(int* no_secs);
void displayColors(int* colors, int no_colors, int delay);
void game(int* colors, int no_colors, int delay, int plays);


int main()
{
	char repeat;
	int games = 0;
	do {
		//initialize random 
		srand(time(0));

		//game counter
		games++;

		int no_colors{};
		int colors[5];
		int no_secs{};

		getNoColors(&no_colors);
		setColors(colors, no_colors);
		getDelay(&no_secs);
		displayColors(colors, no_colors, no_secs);
		game(colors, no_colors, no_secs, games);
		cout << "Would you like to play again? (Y or n): ";
		cin >> repeat;
		cout << "\n";
		if (tolower(repeat) == 'y') {
			clearGraphics();
		}
	} while (tolower(repeat) == 'y');
}

// this function prompts the user for the number of colors to select from the 5 possible colors
void getNoColors(int* no_colors) {
	do {
		
		cout << "Enter the number of colors to display: ";
		cin >> *no_colors;

		if (*no_colors < 2 || *no_colors > 5) {
			cout << "Be sure the number of colors is between 2 and 5, inclusive";
		}
	} while (*no_colors < 2 || *no_colors > 5);

}

// this function randomly sets colors from the 5 possible colors and assigns them in an array of ints
void setColors(int* colors, int no_colors) {
	for (int i = 0; i < no_colors; i++) {
		colors[i] = rand() % ((4 - 0) + 1) + 0;
	}
}

// this function prompts the user for the number of seconds to display when generating the randomly generated colors.  The user will enter a number between 1 and 3.
void getDelay(int* no_secs) {
	do {

		cout << "Enter delay: ";
		cin >> *no_secs;
		if (*no_secs < 1 || *no_secs > 3) {
			cout << "Be sure the number of seconds is between 1 and 3, inclusive.\n";
		}
	} while (*no_secs < 1 || *no_secs > 3);

}

// this function draws the rectangles with their colors.  they are displayed for delay seconds
void displayColors(int* colors, int no_colors, int delay) {
	displayGraphics();
	//to make this less work for me, I made an array of strings that match the order of the "colors" array.
	int colorsRGB[5][3] = { {255,0,0} , {0,255,0}, {0,0,255}, {255,255,0}, {255,0,255} };

	int x = 50;
	for (int i = 0; i < no_colors; i++) {
		int rect;
		i != 0 && (x = x + 75 + 25);
		rect = drawRect(x, 100, 75, 75);
		setColor(rect, colorsRGB[colors[i]][0], colorsRGB[colors[i]][1], colorsRGB[colors[i]][2]);
		gout << setPos(x, 120+75) << setColor(0, 255, 0) << "Color # " << i+1 << endg;
	}

	//initial sleep
	//delay *= CLOCKS_PER_SEC;
	//clock_t now = clock();
	//while (clock() - now < delay);
	Sleep(1000 * delay);

	clearGraphics();
}

// the function that controls the program   
void game(int* colors, int no_colors, int delay, int plays) {
	int total = 0;
	int temp;
	int x = 50;
	int colorsRGB[5][3] = { {255,0,0} , {0,255,0}, {0,0,255}, {255,255,0}, {255,0,255} };
	for (int i = 0; i < no_colors; i++) {
		cout << "Select Color #" + i;
		cout << "\n1. Red\n2. Green\n3. Blue\n4. Yellow\n5. Purple\nEnter choice: ";
		cin >> temp;
		if (temp == colors[i]+1) {
			total = total + 2;
			gout << setPos(250, 70) << setColor(0, 255, 0) << "CORRECT" << endg;
			gout << setPos(250, 80) << setColor(0, 255, 0) << "Score: " << total << endg;
		}
		else {
			total = total - 2;
			gout << setPos(250, 70) << setColor(0, 255, 0) << "INCORRECT" << endg;
			gout << setPos(250, 80) << setColor(0, 255, 0) << "Score: " << total << endg;
			do {
				cout << "Incorrect!  Please try again.\n" << "Select Colors #" + i;
				cout << "\n1. Red\n2. Green\n3. Blue\n4. Yellow\n5. Purple\nEnter choice: ";
				cin >> temp;
			} while (temp != colors[i] + 1);
		}

		int rect;
		i != 0 && (x = x + 75 + 25);
		rect = drawRect(x, 100, 75, 75);
		setColor(rect, colorsRGB[colors[i]][0], colorsRGB[colors[i]][1], colorsRGB[colors[i]][2]);
	}

	gout << setPos(250, 300) << setColor(0, 255, 0) << "Game Over!!!" << endg;
	gout << setPos(250, 315) << setColor(0, 255, 0) << "Score: " << total << endg;
	gout << setPos(250, 330) << setColor(0, 255, 0) << "Number of Plays: " << plays << endg;
}