//Channing Babb
//Lab 4 out
//implements a postage addressing system for letters mailed via the United States Postal system

#include <iostream>
#include <string>
#include <cctype>
#include "graph1.h"

using namespace std;

//prototypes
string getString(string prompt);
bool validateName(string name);
bool validateAddress(string address);
bool validateCity(string city);
bool validateState(string state);
bool validateZip(string zip);
bool validateWeight(int weight);
string convertToUpper(string input);
void displayLetter(string fn, string ln, string addr, string city, string state, string zip, int weight);

void main() {
	string firstName = "";
	string lastName = "";
	string address = "";
	string city = "";
	string state = "";
	string zip = "";
	int weight;


	bool res = false;
	char repeat;

	do {
		do { //first name
			firstName = getString("Enter First Name: ");
			res = validateName(firstName);
		} while (!res);
		do { //last name
			lastName = getString("Enter Last Name: ");
			res = validateName(lastName);
		} while (!res);
		do { //address
			address = getString("Enter Street Address: ");
			res = validateAddress(address);
		} while (!res);
		do { //city
			city = getString("Enter City: ");
			res = validateCity(city);
		} while (!res);
		do { //state
			state = getString("Enter State: ");
			state = convertToUpper(state);
			res = validateState(state);
		} while (!res);
		do { //zip
			zip = getString("Enter Zip Code: ");
			res = validateZip(zip);
		} while (!res);
		do { //weight
			cout << "Enter weight: ";
			cin >> weight;
			res = validateWeight(weight);
		} while (!res);
		displayLetter(firstName, lastName, address, city, state, zip, weight);
		cout << "Run program again? (y/n): ";
		cin >> repeat;
		if (tolower(repeat) == 'y') {
			clearGraphics();
			cin.ignore();
		}
	} while (tolower(repeat) == 'y');
}

// get the string from the prompt
string getString(string prompt)
{
	//Prompt user for name using getline (prompt contains the message displayed to user))
	cin.clear();
	string user_prompt;
	cout << prompt;
	getline(cin, user_prompt);
	return user_prompt;

}

//Validates characters of name
bool validateName(string name)
{
	bool result = true;
	for (int i = 0; i < (int)name.length(); i++) {
		if (!isalpha(name[i])) {
			cout << "The name entered is not valid, please re-enter: " << endl;
			result = false;
			break;
		}
	}
	return result;
}

//Validates characters of address
bool validateAddress(string address)
{
	bool result = true;
	for (int i = 0; i < (int)address.length(); i++) {
		if (!isalpha(address[i]) && !isspace(address[i]) && !isdigit(address[i])) {
			cout << "The address entered is not valid, please re-enter: " << endl;
			result = false;
			break;
		}
	}
	return result;	//Validate the address return true if valid, false if not
}

//Validates city
bool validateCity(string city)
{
	bool result = true;
	for (int i = 0; i < (int)city.length(); i++) {
		if (!isalpha(city[i]) || !isupper(city[0])) {
			cout << "The city entered is not valid, please re-enter: " << endl;
			result = false;
			break;
		}
	}
	return result;
}

//Validates state
bool validateState(string state)
{
	bool result = true;
	for (int i = 0; i < (int)state.length(); i++) {
		if (!isalpha(state[i]) || !isupper(state[i]) || (int)state.length() != 2) {
			cout << "The state entered is not valid, please re-enter: " << endl;
			result = false;
			break;
		}
	}
	return result;
}

//Validates zip
bool validateZip(string zip)
{
	bool result = true;
	for (int i = 0; i < (int)zip.length(); i++) {
		if (!isdigit(zip[i]) || (int)zip.length() != 5) {
			cout << "The zip entered is not valid, please re-enter: " << endl;
			result = false;
			break;
		}
	}
	return result;
}

//Validates weight
bool validateWeight(int weight)
{
	bool result = true;
	if (weight > 6 || weight < 1) {
		result = false;
	}
	return result;
}

//Converts text to uppercase
string convertToUpper(string input)
{
	//Convert input to all uppercase
	for (int i = 0; i < (int)input.length(); i++) {
		input[i] = toupper(input[i]);
	}
	return input;
}

// display the results
void displayLetter(string fn, string ln, string addr, string city, string state, string zip, int weight) {
	displayGraphics();
	int envelope = displayBMP("envelope.bmp", 0, 0);
	int returnAddress = displayBMP("returnAddress.bmp", 43, 26);
	const double stampCost = 0.47;
	int i = 0;

	// stamps
	int curX = 525;
	int curY = 20;
	int count = 0;
	double mailingCost = 0.00;
	for (i; i < weight; i++) {
		if (count == 3) {
			curX = 525;
			curY = curY+89;
		}
		else if (count == 6) {
			curX = 525;
			curY = curY + 79;
		}
		displayBMP("stamp.bmp", curX, curY);
		count++;
		curX = curX - 75;
		mailingCost = mailingCost + stampCost;
	}

	gout << setPos(315, 210) << setColor(0,255,0) << fn << " " << ln << endg;
	gout << setPos(315, 220) << setColor(0, 255, 0) << addr << endg;
	gout << setPos(315, 230) << setColor(0, 255, 0) << city << ", " << state << " " << zip << endg;

	//box
	int lineL = drawLine(200, 385, 200, 385 + 85, 2);
	int lineR = drawLine(200+290, 385, 200+290, 385 + 85, 2);
	int lineT = drawLine(200, 385, 200 + 290, 385, 2);
	int lineB = drawLine(200, 385+85, 200+290, 385+85, 2);

	gout << setPos(210, 397) << setColor(0, 255, 0) << "Weight: " << weight << " ounces" << endg;
	gout << setPos(210, 417) << setColor(0, 255, 0) << "Cost of First Class Stamp: 47 Cents" << endg;
	gout << setPos(210, 437) << setColor(0, 255, 0) << setPrecision(2) << "Total Mailing Cost: $" << mailingCost << endg;
}