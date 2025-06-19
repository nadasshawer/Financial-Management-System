#include "classes.h"
#include "functions.h"
#include "data_display.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*EXPENSE CLASS*/
//VARIABLES
char newExpChoice;
string currency;

//SETTERS & GETTERS
void Expense::setName(const string name) {
	string capitalizedName = capitalizeFirstLetter(name);
	Name = capitalizedName;
}
string Expense::getName() const {
	return Name;
}
void Expense::setDay(const int day) {
	EDay = day;
}
int Expense::getDay() const {
	return EDay;
}
void Expense::setMonth(const int month) {
	EMonth = month;
}
int Expense::getMonth() const {
	return EMonth;
}
void Expense::setYear(const int year) {
	EYear = year;
}
int Expense::getYear() const {
	return EYear;
}
void Expense::setCategory(const string category) {
	string capitalizedCategory = capitalizeFirstLetter(category);
	Category = capitalizedCategory;
}
string Expense::getCategory() const {
	return Category;
}
void Expense::setDescription(const string description) {
	string capitalizedDescription = capitalizeFirstLetter(description);
	Description = capitalizedDescription;
}
string Expense::getDescription() const {
	return Description;
}
void Expense::setAmount(const double amount) {
	double roundedAmount = roundTo2Decimals(amount);
	Amount = roundedAmount;
}
double Expense::getAmount() const {
	return Amount;
}

//CONSTRUCTORS
//default constructor
Expense::Expense() {
	Name = "";
	EDay = 0;
	EMonth = 0;
	EYear = 0;
	Category = "";
	Description = "";
	Amount = 0;
}

//expense info constructor
Expense::Expense(const string cName, const int cDay, const int cMonth, const int cYear, const string cCategory, const string cDescription, const double cAmount) {
	Name = cName;
	EDay = cDay;
	EMonth = cMonth;
	EYear = cYear;
	Category = cCategory;
	Description = cDescription;
	Amount = cAmount;
}

//METHODS
//DISPLAY EXPENSE DATA
void Expense::displayExpenseData() {
	cout << "v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^" << endl;
	cout << "<[ YOUR EXPENSE REPORT ]>" << endl << endl;
	cout << "- Name: " << getName() << endl;
	cout << "- Date: " << getDay() << "/" << getMonth() << "/" << getYear() <<endl;
	cout << "- Category: " << getCategory() << endl;
	cout << "- Description: " << getDescription() << endl;
	cout << "- Amount: " << currency << " " << getAmount() << endl << endl;
	cout << "Add new expense? --> Choice: ";
	bool addedNewExpChoice = newChoice(getExpenseInfo, calcExpenseTotal);

	//find total of expenses entered
	if (!addedNewExpChoice) {
		cout << "v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^" << endl;
		cout << "<[ YOUR EXPENSES OVERVIEW ]>" << endl << endl;
		cout << "- Total Expenses: " << currency << " " << calcExpenseTotal() << endl << endl;
	}
}

//CATEGORIZE EXPENSE DATA
void Expense::displayExpCategorizationData() {
	cout << "v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^" << endl;
	cout << "<[ CATEGORIZING YOUR EXPENSES ]>" << endl << endl;
	classifyExpenses();
}

/*INCOME CLASS*/
//SETTERS & GETTERS
void Income::setDay(const int day) {
	IDay = day;
}
int Income::getDay() const {
	return IDay;
}
void Income::setMonth(const int month) {
	IMonth = month;
}
int Income::getMonth() const {
	return IMonth;
}
void Income::setYear(const int year) {
	IYear = year;
}
int Income::getYear() const {
	return IYear;
}
void Income::setEmployer(const string employer) {
	string capitalizedEmployer = capitalizeFirstLetter(employer);
	Employer = capitalizedEmployer;
}
string Income::getEmployer() const {
	return Employer;
}
void Income::setBusiness(const string business) {
	string capitalizedBusiness = capitalizeFirstLetter(business);
	Business = capitalizedBusiness;
}
string Income::getBusiness() const {
	return Business;
}
void Income::setOther(const string other) {
	string capitalizedOther = capitalizeFirstLetter(other);
	Other = capitalizedOther;
}
string Income::getOther() const {
	return Other;
}
void Income::setGrossAmount(const double grossAmount) {
	GrossAmount = grossAmount;
}
double Income::getGrossAmount() const {
	return GrossAmount;
}
void Income::setCategory(const string category) {
	string capitalizedCategory = capitalizeFirstLetter(category);
	Category = capitalizedCategory;
}
string Income::getCategory() const {
	return Category;
}
void Income::setFrequency(const int frequency) {
	Frequency = frequency;
}
int Income::getFrequency() const {
	return Frequency;
}
void Income::setMode(const string mode) {
	string capitalizedMode = capitalizeFirstLetter(mode);
	Mode = capitalizedMode;
}
string Income::getMode() const {
	return Mode;
}
void Income::setTaxRate(const double taxRate) {
	TaxRate = taxRate;
}
double Income::getTaxRate() const {
	return TaxRate;
}
void Income::setTaxCategory(const string taxCategory) {
	string capitalizedTaxCategory = capitalizeFirstLetter(taxCategory);
	TaxCategory = capitalizedTaxCategory;
}
string Income::getTaxCategory() const {
	return TaxCategory;
}
void Income::setStatus(const string status) {
	Status = status;
}
string Income::getStatus() const {
	return Status;
}
void Income::setBudgetAllocation(const string budgetAllocation) {
	BudgetAllocation = budgetAllocation;
}
string Income::getBudgetAllocation() const {
	return BudgetAllocation;
}

//CONSTRUCTORS
//default constructor
Income::Income() {
	IDay = 0;
	IMonth = 0;
	IYear = 0;
	Employer = "";
	Business = "";
	Other = "";
	GrossAmount = 0;
	Category = "";
	Frequency = 0;
	Mode = "";
	TaxRate = 0;
	TaxCategory = "";
	Status = "";
	BudgetAllocation = "";
}

//income info constructor
Income::Income(const int cDay, const int cMonth, const int cYear, const string cEmployer, const string CBusiness, const string cOther, const double cGrossAmount, const string cCategory, const int cFrequency, const string cMode, const double cTaxRate, const string cTaxCategory, const string cStatus, const string cBudgetAllocation) {
	IDay = cDay;
	IMonth = cMonth;
	IYear = cYear;
	Employer = cEmployer;
	Business = CBusiness;
	Other = cOther;
	GrossAmount = cGrossAmount;
	Category = cCategory;
	Frequency = cFrequency;
	Mode = cMode;
	TaxRate = cTaxRate;
	TaxCategory = cTaxCategory;
	Status = cStatus;
	BudgetAllocation = cBudgetAllocation;
}

//METHODS
//DISPLAY INCOME DATA
void Income::displayIncomeData() {
	cout << "v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^" << endl;
	cout << "<[ YOUR INCOME REPORT ]>" << endl << endl;
	cout << "- Date: " << getDay() << "/" << getMonth() << "/" << getYear() <<endl;
	cout << "- Employer: " << getEmployer() << endl;
	cout << "- Business: " << getBusiness() << endl;
	cout << "- Other Sources: " << getOther() << endl;
	cout << "- Gross Amount: " << currency << " " << getGrossAmount() << endl;
	cout << "- Category: " << getCategory() << endl;
	cout << "- Frequency: " << getFrequency() << "/month" << endl;
	cout << "- Mode: " << getMode() << endl;
	cout << "- Tax Rate: " << getTaxRate() << "%" << endl;
	cout << "- Tax Category: " << getTaxCategory() << endl;
	cout << "- Payment Status: " << getStatus() << endl;
	cout << "- Budget Allocation: " << getBudgetAllocation() << endl << endl;

	cout << "Add new income stream? --> Choice: ";
	bool addedNewIncChoice = newChoice(getIncomeInfo, calcIncomeTotal);

	//find total of incomes entered
	if (!addedNewIncChoice) {
		cout << "v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^" << endl;
		cout << "<[ YOUR INCOME OVERVIEW ]>" << endl << endl;
		cout << "- Net Income: " << currency << " " << calcIncomeTotal() << endl << endl;
	}
}

//CATEGORIZE INCOME DATA
void Income::displayIncCategorizationData() {
	cout << "v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^" << endl;
	cout << "<[ CATEGORIZING YOUR INCOME STREAMS ]>" << endl << endl;
	classifyIncome();
}

/*BUDGET CLASS*/
//SETTERS & GETTERS
void Budget::setBudgetedAmount(const double budgetedAmount) {
	BudgetedAmount = budgetedAmount;
}
double Budget::getBudgetedAmount() const {
	return BudgetedAmount;
}
void Budget::setActualAmount(const double actualAmount) {
	ActualAmount = actualAmount;
}
double Budget::getActualAmount() const {
	return ActualAmount;
}
/*void Budget::setShortTermGoal(const string shortTermGoal) {
	ShortTermGoal = shortTermGoal;
}
string Budget::getShortTermGoal() const {
	return ShortTermGoal;
}
void Budget::setLongTermGoal(const string longTermGoal) {
	LongTermGoal = longTermGoal;
}
string Budget::getLongTermGoal() const {
	return LongTermGoal;
}*/

//CONSTRUCTORS
//default constructor
Budget::Budget() {
	BudgetedAmount = 0;
	ActualAmount = 0;
	/*ShortTermGoal = "";
	LongTermGoal = "";*/
}

//budget info constructor
Budget::Budget(const double cBudgetedAmount, const double cActualAmount, const string cShortTermGoal, const string cLongTermGoal) {
	BudgetedAmount = cBudgetedAmount;
	ActualAmount = cActualAmount;
	/*ShortTermGoal = cShortTermGoal;
	LongTermGoal = cLongTermGoal;*/
}

//METHODS
void Budget::calcDifference() {
	double difference;
	difference = BudgetedAmount - ActualAmount;
	if(difference < 0) {
		cout << difference << " (You have a negative cash flow)" << endl;
	} else {
		cout << difference << " (You have a positive cash flow)" << endl;
	}
}

//DISPLAY BUDGET DATA
void Budget::displayBudgetData() {
	cout << "v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^" << endl;
	cout << "<[ BUDGET SUMMARY ]>" << endl << endl;
	cout << "- Budgeted Amount: " << currency << getBudgetedAmount() << endl;
	cout << "- Actual Amount: " << currency << getActualAmount() << endl;
	cout << "- Difference: " << currency << " ";
	calcDifference();
}
