//Channing Babb
//Lab 1 Test
//Create some stairs that have alternating colors

#include <iostream>
#include "graph1.h"

using namespace std;

//prototypes
void getData(int* no_stairs, int* r, int* g, int* b);
void displayStairs(int no_stairs, int r, int g, int b);

void main() {
	char repeat;
	do {
		//vars
		int no_stairs{};
		int r{};
		int g{};
		int b{};

		getData(&no_stairs, &r, &g, &b);
		displayStairs(no_stairs, r, g, b);

		cout << endl << "Would you like to run the program again? (Y or n): ";
		cin >> repeat;
		cout << "\n";
		if (tolower(repeat) == 'y') {
			clearGraphics();
		}
	} while (tolower(repeat) == 'y');
}

// get user-input for the values
void getData(int* no_stairs, int* r, int* g, int* b) {
	//# of stairs
	do {
		cout << "Enter # of stairs to display: ";
		cin >> *no_stairs;
		if (*no_stairs < 3 || *no_stairs > 6) {
			cout << "Please make sure that the number of stairs is between 3 and 6, inclusive." << endl;
		}
	} while (*no_stairs < 3 || *no_stairs > 6);

	//colors
	do {

		cout << "Enter r/g/b color: ";
		cin >> *r >> *g >> *b;

		if (*r < 0 || *r > 255 || *g < 0 || *g > 255 || *b < 0 || *b > 255) {
			cout << "Please be sure that this is a valid RGB color." << endl;
		}
	} while (*r < 0 || *r > 255 || *g < 0 || *g > 255 || *b < 0 || *b > 255);

}

// display the stairs
void displayStairs(int no_stairs, int r, int g, int b) {
	//initialize
	displayGraphics();
	int stairWidth = 100;
	int stairHeight = 20;
	int initialStart[2] = { 0, 400 };
	int evenColor[3] = { 255, 255, 255 };

	int incrementingPosition[2] = { initialStart[0] + stairWidth/2, initialStart[1] - stairHeight};

	for (int i = 1; i < no_stairs+1; i++) {
		// initialize with first rect
		if (i == 1) {
			int rect = drawRect(initialStart[0], initialStart[1], stairWidth, stairHeight);
			setColor(rect, r, g, b);
		}
		else { //not initial
			//even
			if (i % 2 == 0) {
				int rect = drawRect(incrementingPosition[0], incrementingPosition[1], stairWidth, stairHeight);
				setColor(rect, evenColor[0], evenColor[1], evenColor[2]);
			}
			//odd
			else {
				int rect = drawRect(incrementingPosition[0], incrementingPosition[1], stairWidth, stairHeight);
				setColor(rect, r, g, b);
			}
			incrementingPosition[0] = incrementingPosition[0] + stairWidth / 2;
			incrementingPosition[1] = incrementingPosition[1] - stairHeight;
		}
	}

}
