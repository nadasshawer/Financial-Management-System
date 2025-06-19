#ifndef DATA_DISPLAY_H
#define DATA_DISPLAY_H

#include <string>
using namespace std;

//GET SYSTEM CURRENCY
string getSystemCurrency();

/*EXPENSES*/
//CALCULATE TOTAL OF EXPENSE AMOUNTS
double calcExpenseTotal();

//CLASSIFY EXPENSES BASED ON CHOICE
void classifyExpenses();

//GET EXPENSE INFO
void getExpenseInfo();

/*INCOME*/
//CALCULATE TOTAL OF INCOME AMOUNTS
double calcIncomeTotal();

//CLASSIFY INCOME BASED ON CHOICE
void classifyIncome();

//GET INCOME INFO
void getIncomeInfo();

/*BUDGET*/
//GET BUDGET INFO
void getBudgetInfo();

#endif