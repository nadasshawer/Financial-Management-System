#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include <vector>
using namespace std;

//EXPENSES CLASS
class Expense {
protected:
	//VARIABLES
	string Name;
	int EDay;
	int EMonth;
	int EYear;
	string Category;
	string Description;
	double Amount;

public:
	//SETTERS
	void setName(const string name);
	void setDay(const int day);
	void setMonth(const int month);
	void setYear(const int year);
	void setCategory(const string category);
	void setDescription(const string description);
	void setAmount(const double amount);

	//GETTERS
	string getName() const;
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	string getCategory() const;
	string getDescription() const;
	double getAmount() const;

	//CONSTRUCTORS
	Expense();
	Expense(const string cName, const int cDay, const int cMonth, const int cYear, const string cCategory, const string cDescription, const double cAmount);

	//METHODS
	void displayExpenseData();
	void displayExpCategorizationData();
};

//INCOME CLASS
class Income {
protected:
	//VARIABLES
	int IDay;
	int IMonth;
	int IYear;
	string Employer;
	string Business;
	string Other;
	double GrossAmount;
	string Category;
	int Frequency;
	string Mode;
	double TaxRate;
	string TaxCategory;
	string Status;
	string BudgetAllocation;

public:
	//SETTERS
	void setDay(const int day);
	void setMonth(const int month);
	void setYear(const int year);
	void setEmployer(const string employer);
	void setBusiness(const string business);
	void setOther(const string other);
	void setGrossAmount(const double grossAmount);
	void setCategory(const string category);
	void setFrequency(const int frequency);
	void setMode(const string mode);
	void setTaxRate(const double taxRate);
	void setTaxCategory(const string taxCategory);
	void setStatus(const string status);
	void setBudgetAllocation (const string budgetAllocation);

	//GETTERS
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	string getEmployer() const;
	string getBusiness() const;
	string getOther() const;
	double getGrossAmount() const;
	string getCategory() const;
	int getFrequency() const;
	string getMode() const;
	double getTaxRate() const;
	string getTaxCategory() const;
	string getStatus() const;
	string getBudgetAllocation() const;

	//CONSTRUCTORS
	Income();
	Income(const int cDay, const int cMonth, const int cYear, const string cEmployer, const string CBusiness, const string cOther, const double cGrossAmount, const string cCategory, const int cFrequency, const string cMode, const double cTaxRate, const string cTaxCategory, const string cStatus, const string cBudgetAllocation);

	//METHODS
	void displayIncomeData();
	void displayIncCategorizationData();
};

//BUDGET CLASS
class Budget{
protected:
	//VARIABLES
	double BudgetedAmount;
	double ActualAmount;
	/*string ShortTermGoal;
	string LongTermGoal;*/

public:
	//SETTERS
	void setBudgetedAmount(const double budgetedAmount);
	void setActualAmount(const double actualAmount);
	/*void setShortTermGoal(const string shortTermGoal);
	void setLongTermGoal(const string longTermGoal);*/

	//GETTERS
	double getBudgetedAmount() const;
	double getActualAmount() const;
	/*string getShortTermGoal() const;
	string getLongTermGoal() const;*/

	//CONSTRUCTORS
	Budget();
	Budget(const double cBudgetedAmount, const double cActualAmount, const string cShortTermGoal, const string cLongTermGoal);

	//METHODS
	void calcDifference();
	void displayBudgetData();
};

#endif