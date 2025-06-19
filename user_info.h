#ifndef USER_INFO_H
#define USER_INFO_H

#include <string>
using namespace std;

class UserInfo {
private:
	//VARIABLES
	string FirstName;
	string LastName;
	int BirthDay;
	string BirthMonth;
	int BirthYear;
	int Age;
	string Username;
	string Password;
	int numericalBirthMonth;

public:
	//SETTERS
	void setFirstName(const string firstName);
	void setLastName(const string lastName);
	void setBirthDay(const int birthDay);
	void setBirthMonth(const string birthMonth);
	void setBirthYear(const int birthYear);
	void setAge();
	void setPassword(const string password);

	//GETTERS
	string getFirstName() const;
	string getLastName() const;
	int getBirthDay() const;
	int getBirthMonth() const;
	int getBirthYear() const;
	int getAge();
	string getUsername();
	string getPassword() const;

	//CONSTRUCTORS
	UserInfo();
	UserInfo(const string cFirstName, const string cLastName, const int cBirthDay, const string cBirthMonth, const int cBirthYear, const string cUsername, const string cPassword);

	//METHODS
	void getCurrentDate();
	void getCurrentTime();
	void displayUserProfile();
};

#endif
