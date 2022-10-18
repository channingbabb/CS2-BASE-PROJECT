// Channing Babb
// Lab 5 out
// Program that draws a clock with the arms based on the user inputted seconds, minutes, hours.

#include<iostream>
#include "graph1.h"

using namespace std;

// starting class
class Clock
{
private:
	int hour;
	int min;
	int sec;


public:
	Clock();
	bool setHour(int hour);
	bool setMin(int min);
	bool setSec(int sec);
	int getHour();
	int getMin();
	int getSec();
	void draw();

};

// initialization
Clock::Clock() {
	hour = 0;
	min = 0;
	sec = 0;
}

// set the hour of the time
   //class name prefix NEEDED for this->
bool Clock::setHour(int hour) {
	bool result = false;
	if (hour > 11) {
		this->hour = 11;
	}
	else if (hour < 0) {
		this->hour = 0;
	}
	else {
		this->hour = hour;
		result = true;
	}
	return result;
}

// get the hour
int Clock::getHour() {
	return hour;
}

// set the amount of minutes
bool Clock::setMin(int min) {
	bool result = false;
	if (min > 59) {
		this->min = 59;
	}
	else if (min < 0) {
		this->min = 0;
	}
	else {
		this->min = min;
		result = true;
	}
	return result;
}

// get the minutes
int Clock::getMin() {
	return min;
}

// set the amount of seconds
bool Clock::setSec(int sec) {
	bool result = false;
	if (sec > 59) {
		this->sec = 59;
	}
	else if (sec < 0) {
		this->sec = 0;
	}
	else {
		this->sec = sec;
		result = true;
	}
	return result;
}

// get the seconds
int Clock::getSec() {
	return sec;
}

// function to draw out the clock
void Clock::draw() {
	//init
	double SECOND_end_x;
	double SECOND_end_y;
	double MINUTE_end_x;
	double MINUTE_end_y;
	double HOUR_end_x;
	double HOUR_end_y;

	double const PI = 3.14159265359;

	//NTS:
	// SECOND SPECS:
	//  length 158
	//  red
	// MINUTE SPECS:
	//  length 180
	//  black
	// HOUR SPECS:
	//  length 133
	//  black
	//  DRAWN LAST

	// display the graphics
	displayGraphics();

	// determine quadrants
	int secondCompute = getSec() * 6;
	int minuteCompute = getMin() * 6 + (getSec() / 60.0) * 6;
	int hourCompute = getHour() * 30 + (getMin() / 60.0) * 30;

	// I really don't feel like writing them all out 2 more times bc of pure laziness so just loop for seconds, minutes, hours
	// this is for the end x and y coords
	//thanks

	for (int i = 0; i < 3; i++) {
		int TEMP_END_X = 0;
		int TEMP_END_Y = 0;
		int TEMP_COMPUTE = 0;
		int TEMP_LENGTH = 0;
		if (i == 0) {
			TEMP_COMPUTE = secondCompute;
			TEMP_LENGTH = 150;
		}
		else if (i == 1) {
			TEMP_COMPUTE = minuteCompute;
			TEMP_LENGTH = 180;
		}
		else if (i == 2) {
			TEMP_COMPUTE = hourCompute;
			TEMP_LENGTH = 133;
		}

		if (TEMP_COMPUTE >= 0 && TEMP_COMPUTE < 90) {
			TEMP_END_X = 197 + (cos((90 - TEMP_COMPUTE) * PI / 180.0)) * TEMP_LENGTH;
			TEMP_END_Y = 189 - (sin((90 - TEMP_COMPUTE) * PI / 180.0)) * TEMP_LENGTH;
		}
		else if (TEMP_COMPUTE >= 90 && TEMP_COMPUTE < 180) {
			TEMP_END_X = 197 + (cos((TEMP_COMPUTE - 90) * PI / 180.0)) * TEMP_LENGTH;
			TEMP_END_Y = 189 + (sin((TEMP_COMPUTE - 90) * PI / 180.0)) * TEMP_LENGTH;
		}
		else if (TEMP_COMPUTE >= 180 && TEMP_COMPUTE < 270) {
			TEMP_END_X = 197 - (cos((270 - TEMP_COMPUTE) * PI / 180.0)) * TEMP_LENGTH;
			TEMP_END_Y = 189 + (sin((270 - TEMP_COMPUTE) * PI / 180.0)) * TEMP_LENGTH;
		}
		else if (TEMP_COMPUTE >= 270 && TEMP_COMPUTE < 360) {
			TEMP_END_X = 197 - (cos((TEMP_COMPUTE - 270) * PI / 180.0)) * TEMP_LENGTH;
			TEMP_END_Y = 189 - (sin((TEMP_COMPUTE - 270) * PI / 180.0)) * TEMP_LENGTH;
		}

		if (i == 0) {
			SECOND_end_x = TEMP_END_X;
			SECOND_end_y = TEMP_END_Y;
		}
		else if (i == 1) {
			MINUTE_end_x = TEMP_END_X;
			MINUTE_end_y = TEMP_END_Y;
		}
		else if (i == 2) {
			HOUR_end_x = TEMP_END_X;
			HOUR_end_y = TEMP_END_Y;
		}
	}
	// draw the clock and all of the arms
	int clockPNG = displayPNG("clock_face.png", 123, 50);

	// i will be adding 123 to x and 50 to y because of the clock offset
	int secondHand = drawLine(197 + 123, 189 + 50, SECOND_end_x, SECOND_end_y, 5);
	setColor(secondHand, 255, 0, 0);
	int minuteHand = drawLine(197 + 123, 189 + 50, MINUTE_end_x, MINUTE_end_y, 5);
	setColor(minuteHand, 0, 0, 0);
	int hourHand = drawLine(197 + 123, 189 + 50, HOUR_end_x, HOUR_end_y, 5);
	setColor(hourHand, 0, 0, 0);


}

// main function, orchestrates magic making.
int main() {
	int seconds;
	int minutes;
	int hours;
	bool result = false;
	char repeat;

	Clock coolclock;

	do {

		cout << "Enter the number of seconds: ";
		cin >> seconds;
		result = coolclock.setSec(seconds);
		if (!result) {
			cout << "The number of seconds you entered is invalid.  Setting to default value" << endl;
		}
		cout << "Enter the number of minutes: ";
		cin >> minutes;
		result = coolclock.setMin(minutes);
		if (!result) {
			cout << "The number of minutes you entered is invalid.  Setting to default value" << endl;
		}
		cout << "Enter the number of hours: ";
		cin >> hours;
		result = coolclock.setHour(hours);
		if (!result) {
			cout << "The number of hours you entered is invalid.  Setting to default value" << endl;
		}

		coolclock.draw();

		cout << "\nWould you like to repeat? (y/n): ";
		cin >> repeat;
		if (repeat == 'y' || repeat == 'Y') {
			clearGraphics();
		}
	} while (repeat == 'y' || repeat == 'Y');
	return 0;
}