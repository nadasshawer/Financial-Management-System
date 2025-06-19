#include <iostream>
#include "registration.h"
#include "classes.h"
#include "data_display.h"
#include "functions.h"
using namespace std;

int main()
{
	//PROGRAM WELCOME MSG
	cout << "୨ৎ WELCOME TO PERSONAL FINANCE MANAGER ୨ৎ" << endl << endl << "Please enter your information to register." << endl << endl;
	
	//REGISTER USER
	registerUser();
	
	//TRACKER CHOICE
	chooseTracker();
	
	return 0;
}