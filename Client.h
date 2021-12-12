#pragma once
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "Account.h"

using namespace std;


class Client
{
private:
	int id;
	string firstName;
	string lastName;
public:
	CheckingAccount* checking;
	SavingAccount* saving;
	Client();
	void setID(int i);
	int getID();
	void setName(string fn, string ln);
	string getFirstName();
	string getLastName();
	Client(string i, string fn, string ln);
};