//Channing Babb
//Lab 1 out
//Processes a set of sales data

#include<iostream>
#include "graph1.h"

int getNoMonths();
void getSales(int sales[], int no_months);
int getMax(int sales[], int no_months);
int getMin(int sales[], int no_months);
double getAverage(int sales[], int no_months);
void displayResults(int sales[], int no_months, int max, int min, double avg);

int main() {
	const int MAX_MONTHS = 6;
	int sales[MAX_MONTHS];
	int max;
	int min;
	double average;
	int numOfMonths = getNoMonths();
	displayGraphics();
	getSales(sales, numOfMonths);
	max = getMax(sales, numOfMonths);
	min = getMin(sales, numOfMonths);
	average = getAverage(sales, numOfMonths);
	displayResults(sales, numOfMonths, max, min, average);
}

// this function will get the number of months that the user wants to process.
int getNoMonths() {
	int num;
	do {
		cout << "Enter number of months to process: (between 3 and 6 inclusive): ";
		cin >> num;
		if (num < 3 || num > 6) {
			cout << "Please choose a number between 3 and 6 inclusive." << endl;
		}
	} while (num < 3 || num > 6);
	return num;
}

// this function will get the sales for the number of months the user previously specified.
void getSales(int sales[], int no_months) {
	for (int i = 0; i < no_months; i++) {
		cout << "Enter sales for month #" << i + 1 << ": ";
		cin >> sales[i];
	}
}

// this function will get the month with the most sales out of all of the months
int getMax(int sales[], int no_months) {
	int max;
	int i;
	for (i = 0; i < no_months; i++) {
		if (i == 0) {
			max = sales[i];
		}
		else {
			if (sales[i] > max) {
				max = sales[i];
			}
		}
	}
	return max;
}

// this function will get the month with the least amount of sales out of all of the months
int getMin(int sales[], int no_months) {
	int min;
	int i;
	for (i = 0; i < no_months; i++) {
		if (i == 0) {
			min = sales[i];
		}
		else {
			if (sales[i] < min) {
				sales[i] = min;
			}
		}
	}
	return min;
}

// this function will get the average sales in all of the months
double getAverage(int sales[], int no_months) {
	int i;
	double total = 0.0;
	for (i = 0; i < no_months; i++) {
		total = sales[i] + total;
	}
	return total / no_months;
}

// display sales graph
void displayResults(int sales[], int no_months, int max, int min, double avg) {
	// image file
	displayBMP("sales1.bmp", 250, 25);
	
	//sales for x months
	gout << setPos(375, 36) << setColor(0, 255, 0) << "Sales for " << no_months << " months" << endg;

	// monthly 
	gout << setPos(100, 190) << setColor(0, 255, 0) << "Monthly";
	// sales

	gout << setPos(100, 201) << setColor(0, 255, 0) << "Sales";
	// horizontal line for graph
	drawLine(200, 280, 640, 280, 2);
	// verical line for graph
	drawLine(200, 280, 200, 130, 2);

	// sales statistics
	gout << setPos(205, 340) << setColor(0, 255, 0) << "Sales Stastics" << endg;
	// top line
	drawLine(200, 345, 400, 345, 2);
	// left line
	drawLine(200, 345, 200, 445, 2);
	// bottom line
	drawLine(200, 445, 400, 445, 2);
	// right line
	drawLine(400, 345, 400, 445, 2);

	// max sales
	gout << setPos(220, 380) << setColor(0, 255, 0) << "Max Sales: $" << max << endg;
	// min sales
	gout << setPos(220, 400) << setColor(0, 255, 0) << "Min Sales: $" << min << endg;
	// average sales
	gout << setPos(220, 420) << setColor(0, 255, 0) << "Avg Sales: $" << setPrecision(0) << avg << endg;

	// graph bars
	for (int i = 0; i < no_months; i++) {
		// jan - (255,0,0)
		// feb - (0,255,0)
		// mar - (0,0,255)
		// apr - (255,255,0)
		// may - (255,0,255)
		// june - (0,255,255)

		// set to 1 if 0
		if (sales[i] == 0) {
			sales[i] = 1;
		}

		if (i == 0) {
			int jan;
			int height = ((double)sales[i] / max) * 100.0;
			// doing (-height) because this goes from the top to the bottom, so it would be going from the bottom of the graph down.
			jan = drawRect(203, 278-height, 50, height);
			setColor(jan, 255, 0, 0);
			gout << setPos(203, 278 - height - 2) << setColor(0, 255, 0) << "Jan" << endg;
		} else if (i == 1) {
			int feb;
			int height = ((double)sales[i] / max) * 100.0;
			feb = drawRect(263, 278 - height, 50, height);
			setColor(feb, 0, 255, 0);
			gout << setPos(263, 278 - height - 2) << setColor(0, 255, 0) << "Feb" << endg;
		} else if (i == 2) {
			int mar;
			int height = ((double)sales[i] / max) * 100.0;
			mar = drawRect(323, 278 - height, 50, height);
			setColor(mar, 0, 0, 255);
			gout << setPos(323, 278 - height - 2) << setColor(0, 255, 0) << "Mar" << endg;
		}
		else if (i == 3) {
			int apr;
			int height = ((double)sales[i] / max) * 100.0;
			apr = drawRect(383, 278 - height, 50, height);
			setColor(apr, 255, 255, 0);
			gout << setPos(383, 278 - height - 2) << setColor(0, 255, 0) << "Apr" << endg;
		}
		else if (i == 4) {
			int may;
			int height = ((double)sales[i] / max) * 100.0;
			may = drawRect(443, 278 - height, 50, height);
			setColor(may, 255, 0, 255);
			gout << setPos(443, 278 - height - 2) << setColor(0, 255, 0) << "May" << endg;
		}
		else if (i == 5) {
			int june;
			int height = ((double)sales[i] / max) * 100.0;
			june = drawRect(503, 278 - height, 50, height);
			setColor(june, 0, 255, 255);
			gout << setPos(503, 278 - height - 2) << setColor(0, 255, 0) << "June" << endg;
		}
	}

}