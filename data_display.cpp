#include "data_display.h"
#include "classes.h"
#include "functions.h"
#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <algorithm>
using namespace std;

/*VARIABLES*/
//EXPENSES
string expName;
char expCategory;
string expDescription;
double expAmount;
string expCurrency;
vector <double> totalOfExpAmounts;

//INCOME
string incEmployer;
string incBusiness;
string incOther;
double incGrossAmount;
char incCategory;
int incFrequency;
char incMode;
double incTaxRate;
string incTaxCategory;
char incStatus;
char incBudgetAllocation;
vector <double> totalOfIncAmounts;

//BUDGET
double budBudgetedAmount;
double budActualAmount;
double budDifference;
//string budShortTermGoal;
//string budLongTermGoal;
bool budMonthlyCashFlow;
double budYearlyCashFlow;
string budTransaction;
double budTransactionAmount;
vector <string> allShortTermGoals;
vector <string> allLongTermGoals;

//CLASS CALLS
Expense newExpense; //expenses class
Income newIncome;   //income class
Budget newBudget;   //budget class

//GET SYSTEM CURRENCY
string getSystemCurrency() {
	cout << "- Please enter your currency: ";
	string expCurrency;
	cin >> expCurrency;
	string currency = expCurrency;
	return currency;
}

/*FUNCTIONS - EXPENSES*/
//CHOOSE CATEGORY
bool chooseExpCategory(char choice) {
	string categoryFSpecify;
	string category;
	while(true) {
		if (cin.good()) {
			//match category with letter of choice
			switch(choice) {
			case 'a':
				category = "Housing";
				newExpense.setCategory("Housing");
				return true;
				break;
			case 'b':
				category = "Transport";
				newExpense.setCategory("Transport");
				return true;
				break;
			case 'c':
				category = "Food";
				newExpense.setCategory("Food");
				return true;
				break;
			case 'd':
				category = "Utilities";
				newExpense.setCategory("Utilities");
				return true;
				break;
			case 'e':
				category = "Health & Medical";
				newExpense.setCategory("Health & Medical");
				return true;
				break;
			case 'f':
				cin.clear();
				cin.ignore();
				cout << "Please specifiy: ";
				getline(cin, categoryFSpecify);
				category = categoryFSpecify;
				newExpense.setCategory(category);
				return true;
				break;
			default:
				cin.clear();
				cin.ignore();
				cout << "Please enter a valid category. Retry --> ";
				cin >> choice;
				return false;
			}
			break;
		}
	}
}

//STORE EXPENSE AMOUNTS
void storeExpenses(double amount) {
	totalOfExpAmounts.push_back(amount);
}

//CALCULATE TOTAL OF EXPENSE AMOUNTS
double calcExpenseTotal() {
	double total = 0;
	for(double amount : totalOfExpAmounts) {
		total += amount;
	}
	return total;
}

//CATEGORIZING EXPENSES
//BASED ON CATEGORY
void getExpBasedOnCategory() {
	char choice;
	string category;

	cout << "- Show expenses for which category? (select one):" << endl <<
	     "a)Housing  " << "b)Transport  " << "c)Food  " << "d)Utilities  " << "e)Health & Medical  " << "f)Other" << endl;
	cout << "Your choice --> ";

	while(true) {
		cin >> choice;
		switch(choice) {
		case 'a':
			category = "Housing";
			break;
		case 'b':
			category = "Transport";
			break;
		case 'c':
			category = "Food";
			break;
		case 'd':
			category = "Utilities";
			break;
		case 'e':
			category = "Health & Medical";
			break;
		case 'f':
			category = "Other";
			break;
		default:
			cout << "Please enter a valid category. Retry --> ";
			continue;
		}
		break;
	}
	printExpNames(&Expense::getCategory, category);     //referencing the getCategory method in the Expense class
}

//BASED ON DAY
void getExpBasedOnDay() {
	int day;
	cout << "- Show expenses for which day? Your choice --> ";
	cin >> day;
	printExpNames(&Expense::getDay, day);        //referencing the getDay method in the Expense class
}

//BASED ON MONTH
void getExpBasedOnMonth() {
	int month;
	cout << "- Show expenses for which month (in digits)? Your choice --> ";
	cin >> month;
	printExpNames(&Expense::getMonth, month);        //referencing the getMonth method in the Expense class
}

//BASED ON YEAR
void getExpBasedOnYear() {
	int year;
	cout << "- Show expenses for which year? Your choice --> ";
	cin >> year;
	printExpNames(&Expense::getYear, year);        //referencing the getYear method in the Expense class
}

//CLASSIFY EXPENSES BASED ON CHOICE
void classifyExpenses() {
	string choice;
	cout << "Categorize expenses based on: ";
	while (true) {
		cin >> choice;
		//convert upper cases to lower for case comparisions
		transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

		if(choice == "category") {
			//classify expenses by category
			getExpBasedOnCategory();
			cout << endl;
			cout << "Search another category? --> Choice: ";
			bool addedNewExpCategoryChoice = newChoice(getExpBasedOnCategory);
		} else if(choice == "day") {
			//classify expenses by day
			getExpBasedOnDay();
			cout << endl;
			cout << "Search another day? --> Choice: ";
			bool addedNewExpDayChoice = newChoice(getExpBasedOnDay);
		} else if(choice == "month") {
			//classify expenses by month
			getExpBasedOnMonth();
			cout << endl;
			cout << "Search another month (in digits)? --> Choice: ";
			bool addedNewExpMonthChoice = newChoice(getExpBasedOnMonth);
		} else if(choice == "year") {
			//classify expenses by year
			getExpBasedOnYear();
			cout << endl;
			cout << "Search another year? --> Choice: ";
			bool addedNewExpYearChoice = newChoice(getExpBasedOnYear);
		} else {
			cout << "Please enter a valid classification. Retry --> ";
		}
	}
}

//GET EXPENSE DATA
void getExpenseInfo() {
	cout << "v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^" << endl;
	cout << "<[ EXPENSE DETAILS ]>" << endl << endl;
	// clear input buffer before getting the name
	if(expName.empty()) {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	//name info
	cout << "- Name: ";
	getline(cin, expName);
	while(!checkNameInput(expName)) {
		cout << "Please enter a valid name! Retry --> ";
		getline(cin, expName);
	}
	newExpense.setName(expName);

	//date info
	cout << "- Date:" << endl << "Use today's date? (Y/N) -->  ";
	chooseTodayAsDate(newExpense, &Expense::setDay, &Expense::setMonth, &Expense::setYear);

	//category info
	cout << "- Category (select one):" << endl <<
	     "a)Housing  " << "b)Transport  " << "c)Food  " << "d)Utilities  " << "e)Health & Medical  " << "f)Other" << endl;
	cout << "Your selection --> ";
	cin >> expCategory;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	chooseExpCategory(expCategory);

	//description info
	cout << "- Description (maximum 50 characters): ";
	string limitedDescrText = textLimitAndCounter(50);
	newExpense.setDescription(limitedDescrText);

	//amount info
	cout << "- Amount: ";
	while(!(cin >> expAmount) || expAmount <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a valid positive number! Retry --> ";
	}
	newExpense.setAmount(expAmount);
	storeExpenses(expAmount);

	//stores expense objects
	allExpenses.push_back(newExpense);

	//display expense details
	newExpense.displayExpenseData();

	//display categorization details
	newExpense.displayExpCategorizationData();
}

/*FUNCTIONS - INCOME*/
//STORE INCOME AMOUNTS
void storeIncomes(double amount) {
	totalOfIncAmounts.push_back(amount);
}

//CALCULATE NET INCOME
double calcIncomeTotal() {
	double total = 0;
	double netIncome;
	double decimalIncTaxRate = incTaxRate / 100;
	for(double amount : totalOfIncAmounts) {
		netIncome = (incGrossAmount * incFrequency) * (1- decimalIncTaxRate);
		total += netIncome;
	}
	return total;
}

//CHOOSE CATEGORY
bool chooseIncCategory(char choice) {
	string categoryDSpecify;
	string category;
	while(true) {
		if (cin.good()) {
			//match category with letter of choice
			switch(choice) {
			case 'a':
				category = "Primary Job";
				newIncome.setCategory("Primary Job");
				return true;
				break;
			case 'b':
				category = "Secondary Job";
				newIncome.setCategory("Secondary Job");
				return true;
				break;
			case 'c':
				category = "Investments";
				newIncome.setCategory("Investments");
				return true;
				break;
			case 'd':
				cout << "Please specifiy: ";
				getline(cin, categoryDSpecify);
				category = categoryDSpecify;
				newIncome.setCategory(category);
				return true;
				break;
			default:
				cout << "Please enter a valid category. Retry --> ";
				cin >> choice;
				return false;
			}
			break;
		}
	}
}

//CHOOSE MODE
bool chooseIncMode(char choice) {
	string mode;
	while(true) {
		if (cin.good()) {
			//match mode with letter of choice
			switch(choice) {
			case 'a':
				mode = "Bank Transfer";
				newIncome.setMode("Bank Transfer");
				return true;
				break;
			case 'b':
				mode = "Cash";
				newIncome.setMode("Cash");
				return true;
				break;
			case 'c':
				mode = "Check";
				newIncome.setMode("Check");
				return true;
				break;
			case 'd':
				mode = "Digital Payment";
				newIncome.setMode("Digital Payment");
				return true;
				break;
			default:
				cout << "Please enter a valid category. Retry --> ";
				cin >> choice;
				return false;
			}
			break;
		}
	}
}

//CHOOSE STATUS
bool chooseIncStatus(char choice) {
	string status;
	while(true) {
		if (cin.good()) {
			//match status with letter of choice
			switch(choice) {
			case 'a':
				status = "Paid";
				newIncome.setStatus("Paid");
				return true;
				break;
			case 'b':
				status = "Pending";
				newIncome.setStatus("Pending");
				return true;
				break;
			default:
				cout << "Please enter a valid status. Retry --> ";
				cin >> choice;
				return false;
			}
			break;
		}
	}
}

//CHOOSE BUDGET ALLOCATION
bool chooseIncBudAllo(char choice) {
	string BudAllo;
	while(true) {
		if (cin.good()) {
			//match budget allocation with letter of choice
			switch(choice) {
			case 'a':
				BudAllo = "Savings";
				newIncome.setBudgetAllocation("Savings");
				return true;
				break;
			case 'b':
				BudAllo = "Investments";
				newIncome.setBudgetAllocation("Investments");
				return true;
				break;
			case 'c':
				BudAllo = "Spending";
				newIncome.setBudgetAllocation("Spending");
				return true;
				break;
			default:
				cout << "Please enter a valid category. Retry --> ";
				cin >> choice;
				return false;
			}
			break;
		}
	}
}

//CATEGORIZING INCOME STREAMS
//BASED ON CATEGORY
void getIncBasedOnCategory() {
	char choice;
	string category;

	cout << "- Category (select one):" << endl << "a)Primary Job  " << "b)Secondary Job  " << "c)Investments  " << "d)Other  " << endl;
	cout << "Your choice --> ";

	while(true) {
		cin >> choice;
		switch(choice) {
		case 'a':
			category = "Primary Job";
			break;
		case 'b':
			category = "Secondary Job";
			break;
		case 'c':
			category = "Investments";
			break;
		case 'd':
			category = "Other";
			break;
		default:
			cout << "Please enter a valid category. Retry --> ";
			continue;
		}
		break;
	}
	printIncNames(&Income::getCategory, category);
}

//BASED ON MONTH
void getIncBasedOnMonth() {
	int month;
	cout << "- Show income for which month (in digits)? Your choice --> ";
	cin >> month;
	printIncNames(&Income::getMonth, month);
}

//BASED ON YEAR
void getIncBasedOnYear() {
	int year;
	cout << "- Show income for which year? Your choice --> ";
	cin >> year;
	printIncNames(&Income::getYear, year);
}

//BASED ON MODE
void getIncBasedOnMode() {
	char choice;
	string mode;

	cout << "- Mode (select one):" << endl << "a)Bank Transfer  " << "b)Cash  " << "c)Check  " << "d)Digital Payment  " << endl;
	cout << "Your choice --> ";

	while(true) {
		cin >> choice;
		switch(choice) {
		case 'a':
			mode = "Bank Transfer";
			break;
		case 'b':
			mode = "Cash";
			break;
		case 'c':
			mode = "Check";
			break;
		case 'd':
			mode = "Digital Payment";
			break;
		default:
			cout << "Please enter a valid mode. Retry --> ";
			continue;
		}
		break;
	}
	printIncNames(&Income::getMode, mode);
}

//BASED ON STATUS
void getIncBasedOnStatus() {
	char choice;
	string status;

	cout << "- Payment Status (select one):" << endl << "a)Paid  " << "b)Pending  " << endl;
	cout << "Your selection --> ";

	while(true) {
		cin >> choice;
		switch(choice) {
		case 'a':
			status = "Paid";
			break;
		case 'b':
			status = "Pending";
			break;
		default:
			cout << "Please enter a valid status. Retry --> ";
			continue;
		}
		break;
	}
	printIncNames(&Income::getStatus, status);
}

//BASED ON BUDGET ALLOCATION
void getIncBasedOnBudAllo() {
	char choice;
	string budAllo;

	cout << "- Budget Allocation (select one):" << endl << "a)Savings  " << "b)Investments  " << "c)Spending" << endl;
	cout << "Your selection --> ";

	while(true) {
		cin >> choice;
		switch(choice) {
		case 'a':
			budAllo = "Savings";
			break;
		case 'b':
			budAllo = "Investments";
			break;
		case 'c':
			budAllo = "Spending";
			break;
		default:
			cout << "Please enter a valid budget allocation. Retry --> ";
			continue;
		}
		break;
	}
	printIncNames(&Income::getBudgetAllocation, budAllo);
}

//CLASSIFY INCOME BASED ON CHOICE
void classifyIncome() {
	string choice;
	cout << "Categorize income based on: ";
	while (true) {
		cin >> choice;
		//convert upper cases to lower for case comparisions
		transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

		if(choice == "category") {
			//classify income by category
			getIncBasedOnCategory();
			cout << endl;
			cout << "Search another category? --> Choice: ";
			bool addedNewIncCategoryChoice = newChoice(getIncBasedOnCategory);
		} else if(choice == "month") {
			//classify income by month
			getIncBasedOnMonth();
			cout << endl;
			cout << "Search another month (in digits)? --> Choice: ";
			bool addedNewIncMonthChoice = newChoice(getIncBasedOnMonth);
		} else if(choice == "year") {
			//classify income by year
			getIncBasedOnYear();
			cout << endl;
			cout << "Search another year? --> Choice: ";
			bool addedNewIncYearChoice = newChoice(getIncBasedOnYear);
		} else if(choice == "mode") {
			//classify income by mode
			getIncBasedOnMode();
			cout << endl;
			cout << "Search another mode? --> Choice: ";
			bool addedNewIncModeChoice = newChoice(getIncBasedOnMode);
		} else if(choice == "status") {
			//classify income by status
			getIncBasedOnStatus();
			cout << endl;
			cout << "Search another status? --> Choice: ";
			bool addedNewIncStatusChoice = newChoice(getIncBasedOnStatus);
		} else if(choice == "budget allocation") {
			//classify income by budget allocation
			getIncBasedOnBudAllo();
			cout << endl;
			cout << "Search another budget allocation? --> Choice: ";
			bool addedNewIncBudAlloChoice = newChoice(getIncBasedOnBudAllo);
		} else {
			cout << "Please enter a valid classification. Retry --> ";
		}
	}
}

//GET INCOME INFO
void getIncomeInfo() {
	cout << "v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^" << endl;
	cout << "<[ INCOME DETAILS ]>" << endl << endl;

	//date info
	cout << "- Date:" << endl << "Use today's date? (Y/N) -->  ";
	chooseTodayAsDate(newIncome, &Income::setDay, &Income::setMonth, &Income::setYear);

	//employer info
	cout << "- Employer: ";
	getline(cin, incEmployer);
	while(!checkNameInput(incEmployer)) {
		cout << "Please enter a valid name! Retry --> ";
		getline(cin, incEmployer);
	}
	newIncome.setEmployer(incEmployer);

	//business info
	cout << "- Business: ";
	getline(cin, incBusiness);
	while(!checkNameInput(incBusiness)) {
		cout << "Please enter a valid name! Retry --> ";
		getline(cin, incBusiness);
	}
	newIncome.setBusiness(incBusiness);

	//other info
	cout << "- Other Sources (if applicable): ";
	getline(cin, incOther);
	while(!checkNameInput(incOther)) {
		cout << "Please enter a valid name! Retry --> ";
		getline(cin, incOther);
	}
	newIncome.setOther(incOther);

	//gross amount info
	cout << "- Gross Amount: ";
	while(!(cin >> incGrossAmount) || incGrossAmount <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a valid positive number! Retry --> ";
	}
	newIncome.setGrossAmount(incGrossAmount);
	storeIncomes(incGrossAmount);

	//category info
	cout << "- Category (select one):" << endl << "a)Primary Job  " << "b)Secondary Job  " << "c)Investments  " << "d)Other  " << endl;
	cout << "Your selection --> ";
	cin >> incCategory;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	chooseIncCategory(incCategory);

	//frequency info
	cout << "- Frequency (per month): ";
	while(!(cin >> incFrequency) || incFrequency <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a valid positive number! Retry --> ";
	}
	newIncome.setFrequency(incFrequency);

	//mode info
	cout << "- Mode (select one):" << endl << "a)Bank Transfer  " << "b)Cash  " << "c)Check  " << "d)Digital Payment  " << endl;
	cout << "Your selection --> ";
	cin >> incMode;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	chooseIncMode(incMode);

	//TAX INFO
	cout << "<--TAXES-->" << endl;

	//tax rate info
	cout << "- Tax Rate (in perecentage): ";
	while(!(cin >> incTaxRate) || incTaxRate <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a valid positive number! Retry --> ";
	}
	newIncome.setTaxRate(incTaxRate);

	//tax category info
	// clear input buffer before getting the category name
	if(incTaxCategory.empty()) {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "- Tax Category: ";
	getline(cin, incTaxCategory);
	while(!checkNameInput(incTaxCategory)) {
		cout << "Please enter a valid name! Retry --> ";
		getline(cin, incTaxCategory);
	}
	newIncome.setTaxCategory(incTaxCategory);

	//status info
	cout << "- Payment Status (select one):" << endl << "a)Paid  " << "b)Pending  " << endl;
	cout << "Your selection --> ";
	cin >> incStatus;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	chooseIncStatus(incStatus);

	//budget allocation info
	cout << "- Budget Allocation (select one):" << endl << "a)Savings  " << "b)Investments  " << "c)Spending" << endl;
	cout << "Your selection --> ";
	cin >> incBudgetAllocation;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	chooseIncBudAllo(incBudgetAllocation);

	//stores income objects
	allIncome.push_back(newIncome);

	//display income details
	newIncome.displayIncomeData();

	//display categorization details
	newIncome.displayIncCategorizationData();
}

/*FUNCTIONS - BUDGET*/
//GET SHORT/LONG TERM GOALS INFO
void inputGoal(string& goal) {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, goal);
	while(!checkNameInput(goal)) {
		cout << "Please enter a valid name! Retry --> ";
		getline(cin, goal);
	}
}

//GET BUDGET INFO
void getBudgetInfo() {
	cout << "v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^" << endl;
	cout << "<[ BUDGET DETAILS ]>" << endl << endl;

	//budgeted amount info
	cout << "- Budgeted Amount: ";
	while(!(cin >> budBudgetedAmount) || budBudgetedAmount <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a valid positive number! Retry --> ";
	}
	newBudget.setBudgetedAmount(budBudgetedAmount);

	//actual amount info
	cout << "- Actual Amount Spent: ";
	while(!(cin >> budActualAmount) || budActualAmount <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a valid positive number! Retry --> ";
	}
	newBudget.setActualAmount(budActualAmount);

	/*//GOAL INFO - FAILED ATTEMPT :(
	cout << "<--GOALS-->" << endl;
	bool addedNewBudShortTermGoalChoice = true;
	//short term goal info
	while(addedNewBudShortTermGoalChoice) {
		cout << "- Short term goal: ";
		inputGoal(budShortTermGoal);
		allShortTermGoals.push_back(budShortTermGoal);
		newBudget.setShortTermGoal(budShortTermGoal);

		cout << "Add another short term goal? --> Choice: ";
		addedNewBudShortTermGoalChoice = newChoice([&] {
			inputGoal(budShortTermGoal);
			newBudget.setShortTermGoal(budShortTermGoal);
			allShortTermGoals.push_back(budShortTermGoal);
		});
		if (!addedNewBudShortTermGoalChoice) {
		    break;
		}
	}

	//long term goal info
	while (true) {
		cout << "- Long term goal: ";
		// clear input buffer before getting the text
		if(budLongTermGoal.empty()) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		inputGoal(budLongTermGoal);
		allLongTermGoals.push_back(budLongTermGoal);
		newBudget.setLongTermGoal(budLongTermGoal);

		cout << "Add another long term goal? --> Choice: ";
		bool addedNewBudLongTermGoalChoice = newChoice([] {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			inputGoal(budLongTermGoal);
			allLongTermGoals.push_back(budLongTermGoal);
			newBudget.setLongTermGoal(budLongTermGoal);
		});
		if (!addedNewBudLongTermGoalChoice) {
			break;
		}
	}*/

	//display budget details
	newBudget.displayBudgetData();
}
