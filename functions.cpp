#include "functions.h"
#include "classes.h"
#include "data_display.h"
#include <iostream>
#include <string>
#include <ranges>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <cmath>
#include <sstream>
#include <limits>
using namespace std;

//GLOBAL VARIABLE CALLS/DEFINATIONS
vector <Expense> allExpenses;
vector <Income> allIncome;

//CHECK NAME INPUT
bool checkNameInput(string name) {
	if(name.empty()) {
		return false;
	}
	for (char ch : name) {
		if(!isalpha(ch) && !isspace(ch)) {
			return false;
		}
	}
	return true;
}

/*//CHECK NUMBER INPUT - FAILED ATTEMPT :(
bool checkNumInput(string str) {
	istringstream iss(str);    //creates an input string stream from string
	double num;
	char extraChars;

	if(str.empty()) {
		return false;
	}
	//extracting an int from the string - checks for digits
	if(!(iss >> num)) {
		return false;
	}
	//check for extra chars in the buffer
	if(iss >> extraChars) {
		return false;
	}
	return true;
}
*/

//CHECK BIRTH DAY
bool checkDayInput(int date) {
	auto validDays = ranges::iota_view(1,32);
	if(ranges::find(validDays, date) == validDays.end()) {
		return false;
	}
	return true;
}

//CHECK BIRTH MONTH AS NUMBERS
bool checkNumMonthInput(int numMonth) {
	if(numMonth < 1 || numMonth > 12) {
		return false;
	} else {
		return true;
	}
}

//CHECK YEAR INPUT
bool checkYearInput(int year) {
	int currentYear = getCurrentYear();
	if(year > currentYear || year < 2020) {
		return false;
	} else {
		return true;
	}
}

//GET CURRENT DATE
//year
int getCurrentYear() {
	time_t currentTime = time(0);   //returns current calendar time
	tm* timeNow = localtime(&currentTime);  //converts to local time

	int currentYear = timeNow -> tm_year + 1900;    //current year
	return currentYear;
}

//month
int getCurrentMonth() {
	time_t currentTime = time(0);
	tm* timeNow = localtime(&currentTime);

	int currentMonth = timeNow -> tm_mon + 1;
	return currentMonth;
}
//day
int getCurrentDay() {
	time_t currentTime = time(0);
	tm* timeNow = localtime(&currentTime);

	int currentDay = timeNow -> tm_mday;
	return currentDay;
}

//GET CURRENT TIME
//hour
int getCurrentHour() {
	time_t currentTime = time(0);
	tm* timeNow = localtime(&currentTime);

	int currentHour = timeNow -> tm_hour;
	return currentHour;
}
//minute
int getCurrentMinute() {
	time_t currentTime = time(0);
	tm* timeNow = localtime(&currentTime);

	int currentMinute = timeNow -> tm_min;
	return currentMinute;
}
//second
int getCurrentSecond() {
	time_t currentTime = time(0);
	tm* timeNow = localtime(&currentTime);

	int currentSecond = timeNow -> tm_sec;
	return currentSecond;
}

//COUNT DIGITS OF NUMBER
int digitCount(int num) {
	int count = 0;
	if(num == 0) {
		return 1;
	} else if(num < 0) {
		num = abs(num);     //get absolute value of -ve nums
	}
	while(num > 0) {
		num /= 10;          //remove last digit with each iteration
		count++;
	}
	return count;
}

//PRINT FIRST LETTER OF NAME IN CAPS
string capitalizeFirstLetter(string name) {
	string capitalizedName = name;
	if(!name.empty()) {
		if(islower(capitalizedName[0])) {
			capitalizedName[0] = toupper(capitalizedName[0]);
		}
	}
	return capitalizedName;
}

//TEXT LIMIT AND COUNTER
string textLimitAndCounter(int limit) {
	char c;
	string input;
	int count = 0;
	while(count < limit) {
		c = cin.get();          //get a char from input stream
		if(c == '\n') {         //'enter key' is pressed
			break;
		} else if(c == '\b') {  //'backspace key' is pressed
			if(count > 0)
				if(!input.empty()) {
					cout << "\b \b";
					input.pop_back();
					count--;
				}
		} else {
			input += c;
			count++;
		}
	}
	//if limit is reached, stop recieving input from user
	if(count == limit) {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return input;
}

//ROUND NUMBER TO 2 DECIMAL PLACES
double roundTo2Decimals(double num) {
	double roundedNum = round(num * 100) / 100;
	return roundedNum;
}

//ADD NEW THING
bool newChoice(FunctionA functionA, FunctionB functionB) {
	char choice;
	while(true) {
		cin >> choice;
		cin.clear();
		cin.ignore();
		if(choice == 'Y' || choice == 'y') {
			cout << endl;
			functionA();
			return true;
		} else if (choice == 'N' || choice == 'n') {
			functionB();
			return false;
		} else {
			cout << "Please enter a valid Y/N option. Retry --> ";
		}
	}
}

//CHOOSE TRACKER
void chooseTracker() {
	char choice;
	cout << "Hi! What do you want to track today?" << endl << endl;
	cout << "Choose Tracker (please select one):" << endl << "a)Expense Tracker  b)Income Tracker  c)Budget Tracker" << endl << endl;
	cout << "Your Selection --> ";

	while(true) {
		cin >> choice;
		if(choice == 'a' || choice == 'A') {
			//call expense tracker
			cout << endl << "<----------- EXPENSE TRACKER ----------->" << endl << "(Welcome to our program's Expense Tracker. Here you can track and manage all your expenses!)" << endl << endl;
			currency = getSystemCurrency();  //get currency
			cout << endl;
			getExpenseInfo();
		} else if(choice == 'b' || choice == 'B') {
			//call income tracker
			cout << endl << "<----------- INCOME TRACKER ----------->" << endl << "(Welcome to our program's Income Tracker. Here you can track and manage all your income streams!)" << endl << endl;
			currency = getSystemCurrency();  //get currency
			cout << endl;
			getIncomeInfo();
		} else if(choice == 'c' || choice == 'C') {
			//call budget tracker
			cout << endl << "<----------- BUDGET TRACKER ----------->" << endl << "(Welcome to our program's Budget Tracker. Here you can track and manage all your expenses, income, savings, transactions, and more!)" << endl << endl;
			currency = getSystemCurrency();  //get currency
			cout << endl;
			getBudgetInfo();
		} else {
			cout << "Please enter a valid tracker option. Retry --> ";
		}
	}
}


