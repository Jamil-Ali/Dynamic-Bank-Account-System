#pragma once
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include<cmath> //For math equations
#include <vector>
#include "Client.h"
using namespace std; // So "std::cout" may be abbreviated to "cout"


class BankSystem :public Client {
private:
	vector<string> log;
	void AddCheckingDialog();
	void RemoveCheckingDialog();
	void DepositCheckingDialog();
	void WithdrawCheckingDialog();
	void AddSavingDialog();
	void RemoveSavingDialog();
	void DepositSavingDialog();
	void TransferDialog();
	Client *oneClient;
public:
	void start();
	
	BankSystem(string i, string fn, string ln);



};