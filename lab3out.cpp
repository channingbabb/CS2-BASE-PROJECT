//Channing Babb
//Lab 3 Out
//Write a program that will implement a plotter for polynomial equations


#include <iostream>
#include <ctime>
#include "graph1.h"
#include <cmath>

using namespace std;

int getNoTerms();
int* createExponents(int no_terms);
double* createCoefficients(int no_terms);
void getPlotParameters(int& noPoints, int& x_start, int& x_end);
double* generatePoints(int* exponents, double* coefficients, int no_terms, int no_points, double x_start, double x_end);
void plotPoints(double* points, int no_points, double x_start, double x_end);

void main() {
	char repeat;
	do {
		displayGraphics();
		int x_start, x_end, no_points=0;
		double* points;

		int no_terms = getNoTerms();
		int* exponents = createExponents(no_terms);
		double* coefficients = createCoefficients(no_terms);
		getPlotParameters(no_points, x_start, x_end);
		points = generatePoints(exponents, coefficients, no_terms, no_points, x_start, x_end);
		plotPoints(points, no_points, x_start, x_end);
		cout << endl << "Would you like to run the program again? (Y or n): ";
		cin >> repeat;
		cout << "\n";
		if (tolower(repeat) == 'y') {
			clearGraphics();
		}
	} while (tolower(repeat) == 'y');
}


//prompts user for the number of terms in an equation
int getNoTerms() {
	int no_terms = 0;
	do {
		cout << "Enter number of terms for the polynomial equation: ";
		cin >> no_terms;
		if (no_terms < 1 || no_terms > 11) {
			cout << "Please keep the number of terms between 1 and 11." << endl;
		}
	} while (no_terms < 1 || no_terms > 11);
	return no_terms;
}

// this function creates the expontents in a dynamically allocated array of integers
int* createExponents(int no_terms) {
	int* exponents = new int[no_terms];
	for (int i = 0; i < no_terms; i++) {
		do {
			cout << "Enter the exponent for term #" << i + 1 << ": ";
			cin >> exponents[i];
			if (exponents[i] < 0 || exponents[i] > 10) {
				cout << "Please keep the number of terms between 0 and 10." << endl;
			}
		} while (exponents[i] < 0 || exponents[i] > 10);
	}
	return exponents;
}
// this function creates the coefficients in a dynamically allocated array of integers
double* createCoefficients(int no_terms) {
	double* coefficients = new double[no_terms];
	for (int i = 0; i < no_terms; i++) {
		cout << "Enter the coefficient for term #" << i + 1 << ": ";
		cin >> coefficients[i];
	}
	return coefficients;
}
//This function prompts the user for the number of points to be generated and plotted for the equation 
void getPlotParameters(int& noPoints, int& x_start, int& x_end) {
	//# of points to be plotted
	do {
		cout << "Enter # of points to be plotted between 100 and 640: ";
		cin >> noPoints;
		if (noPoints < 100 || noPoints > 640) {
			cout << "Please keep the number of points between 100 and 640." << endl;
		}
	} while (noPoints < 100 || noPoints > 640);

	//x start
	do {
		cout << "Enter plot's starting position on x axis: ";
		cin >> x_start;
		if (x_start > -1 || x_start < -100) {
			cout << "Please keep the starting position between -1 and -100." << endl;
		}
	} while (x_start > -1 || x_start < -100);

	//x end
	do {
		cout << "Enter plot's ending position on x axis: ";
		cin >> x_end;
		if (x_end > 100 || x_end < 1) {
			cout << "Please keep the ending position between 1 and 100." << endl;
		}
	} while (x_end > 100 || x_end < 1);



}

// this function creates the points in a dynamically allocated array of doubles
double* generatePoints(int* exponents, double* coefficients, int no_terms, int no_points, double x_start, double x_end) {

	double y;
	double offset = ((x_end - x_start) / (double)no_points);
	double* points = new double[no_points];

	for (int i = 0; i < no_points; i++)
	{
		//reset y value for every loop
		y = 0.0;
		for (int q = 0; q < no_terms; q++)
		{
			y += (coefficients[q] * pow(x_start, exponents[q]));
		}
		points[i] = y;
		x_start += offset;
	}

	return points;
}

//This function first displays the plot
void plotPoints(double* points, int no_points, double x_start, double x_end) {
	int cx = 320, cy = 240;
	double x_plot = 0.0, y_plot = 0.0;
	double x_max = x_end, y_max = points[no_points];
	double offset = (x_end - x_start) / no_points;
	//draw graph with the x and y axis
	//640x480, so 480 will be the 2nd y value in the x axis and 640 will be the second x value in the y axis
	int x_axis = drawLine(320, 0, 320, 480, 2), y_axis = drawLine(0, 240, 640, 240, 2);

	setColor(x_axis, 255, 255, 0);
	setColor(y_axis, 255, 255, 0);

	for (int i = 0; i < no_points; i++)
	{
		if (fabs(points[i]) >= y_max) {
			y_max = points[i]; 
		}
	}

	// (int) to remove the decimal
	gout << setPos(2, (cy + 15)) << setColor(0, 255, 0) << (int)x_start << endg;
	gout << setPos(615, (cy + 15)) << setColor(0, 255, 0) << (int)x_end << endg;
	gout << setPos((cx + 5), 0) << setColor(0, 255, 0) << (int)(fabs(y_max)) << endg;
	gout << setPos((cx + 5), 480) << setColor(0, 255, 0) << (int)fabs(y_max) * -1 << endg;


	//quadrants
	for (int h = 0; h < no_points; h++)
	{
		if (x_start > 0 && points[h] > 0) { //quadrant 1
			x_plot = cx + (fabs(x_start) / x_max) * 320;
			y_plot = cy - (fabs(points[h]) / y_max) * 240;
		} else if (x_start < 0 && points[h] > 0) { //quadrant 2
			x_plot = cx - (fabs(x_start) / x_max) * 320;
			y_plot = cy - (fabs(points[h]) / y_max) * 240;
		} else if (x_start < 0 && points[h] < 0) { //quadrant 3
			x_plot = cx - (fabs(x_start) / x_max) * 320;
			y_plot = cy + (fabs(points[h]) / y_max) * 240;
		} else if (x_start > 0 && points[h] < 0) { //quadrant 4
			x_plot = cx + (fabs(x_start) / x_max) * 320;
			y_plot = cy + (fabs(points[h]) / y_max) * 240;
		}

		// plot the points and increment the x_start value w/ offset
		drawPoint(x_plot, y_plot);
		x_start += offset;
	}
}