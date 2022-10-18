//Channing Babb
//Lab 1 Test P2
//Create a polyline based on user input

#include <iostream>
#include <string>
#include <cctype>
#include "graph1.h"

using namespace std;

// prototypes
void getData(int* no_points, int* x, int* y, int* r, int* g, int* b);
int* drawPolyLine(int* x, int* y, int no_points);
void colorPolyLine(int* objects, int no_points, int r, int g, int b);

void main() {
	char repeat;
	do {
		int no_points;
		int x[10];
		int y[10];
		int r;
		int g;
		int b;
		getData(&no_points, x, y, &r, &g, &b);
		int* objects = drawPolyLine(x, y, no_points);
		colorPolyLine(objects, no_points, r, g, b);

		cout << endl << "Would you like to run the program again? (Y or n): ";
		cin >> repeat;
		cout << "\n";
		if (tolower(repeat) == 'y') {
			clearGraphics();
		}
	} while (tolower(repeat) == 'y');
}


// get the user inputted data
void getData(int* no_points, int* x, int* y, int* r, int* g, int* b) {
	int maxX = 640;
	int maxY = 480;

	// NUMBER OF POINTS
	do {
		cout << "Enter # of points: ";
		cin >> *no_points;
		if (*no_points < 3 || *no_points > 10) {
			cout << "Please be sure that the number of points is between 3 and 10, inclusive." << endl;
		}
	} while (*no_points < 3 || *no_points > 10);

	//RGB Color
	do {

		cout << "Enter r/g/b color: ";
		cin >> *r >> *g >> *b;

		if (*r < 0 || *r > 255 || *g < 0 || *g > 255 || *b < 0 || *b > 255) {
			cout << "Please be sure that this is a valid RGB color." << endl;
		}
	} while (*r < 0 || *r > 255 || *g < 0 || *g > 255 || *b < 0 || *b > 255);

	// loop for the x/y coords
	for (int i = 0; i < *no_points; i++) {
		do {
			cout << "Enter x/y coord for Point #" << i+1 << ": ";
			cin >> x[i] >> y[i];
			if (x[i] < 0 || y[i] < 0 || x[i] > maxX || y[i] > maxY) {
				cout << "Please be sure that the x and y coordinates are between 0 and (480 for x and 640 for y)." << endl;
			}
		} while (x[i] < 0 || y[i] < 0 || x[i] > maxX || y[i] > maxY);
	}
}

// draw the polyline graphic
int* drawPolyLine(int* x, int* y, int no_points) {
	int* lines = new int[no_points];
	displayGraphics();
	for (int i = 0; i < no_points; i++) {
		int endX;
		int endY;
		// prevent last line
		if (i+1 == no_points) {
			endX = i;
			endY = i;
		}
		else {
			endX = i + 1;
			endY = i + 1;
		}
		lines[i] = drawLine(x[i], y[i], x[endX], y[endY], 2);

	}
	return lines;
}

// set the color of the polyline
void colorPolyLine(int* objects, int no_points, int r, int g, int b) {
	for (int i = 0; i < no_points; i++) {
		setColor(objects[i], r, g, b);
	}
}