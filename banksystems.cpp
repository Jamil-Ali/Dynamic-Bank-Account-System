#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include<cmath> //For math equations
#include <vector>
#include "banksystems.h"
using namespace std; // So "std::cout" may be abbreviated to "cout"

BankSystem::BankSystem(string i, string fn, string ln)
{
	oneClient = new Client(i, fn, ln);
}
void BankSystem::start() {
	int choice;
	cout << "===MENU===" << endl;
	cout << "1. Add a Checking account" << endl;
	cout << "2. Remove Checking account" << endl;
	cout << "3. Deposit into Checking Account" << endl;
	cout << "4. Withdraw from Checking Account" << endl;
	cout << "5. Add a Saving account" << endl;
	cout << "6. Remove Saving account" << endl;
	cout << "7. Deposit into Saving account" << endl;
	cout << "8. Transfer from Saving to Checking account" << endl;
	cout << "9. Exit" << endl;

	bool loop = false;
	while (loop == false)
	{
		cout << "Choose an option [1-9]: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			AddCheckingDialog();
			break;
		case 2:
			RemoveCheckingDialog();
			break;
		case 3:
			DepositCheckingDialog();
			break;
		case 4:
			WithdrawCheckingDialog();
			break;
		case 5:
			AddSavingDialog();
			break;
		case 6:
			RemoveSavingDialog();
			break;
		case 7:
			DepositSavingDialog();
			break;
		case 8:
			TransferDialog();
			break;
		case 9:
			loop = true;
			cout << "=== LOGS ===\n";

			for (int i=0; i<log.size();i++)
			{
				cout << log.at(i) << endl;
			}

			break;
		default:
			cout << "Choose an option from [1-9]";
		}

		if (loop)
			break;
	}
}
	



void BankSystem::AddCheckingDialog()
{
	if (oneClient->checking != NULL)
	{
		cout << "The client already has a checking account" << endl;
		log.push_back("Invalid attempt to overwrite a checking account.");
	}
	else
	{
		float initialBalance;
		cout << "Enter the initial balance for checking account: ";
		cin >> initialBalance;
		CheckingAccount* check = new CheckingAccount(initialBalance);
		oneClient->checking = check;
		log.push_back("Checking account successfully created.");
	}
}


void BankSystem::RemoveCheckingDialog() 
{

	if (oneClient->checking == NULL) 
	{
		cout << "The client does not have a checking account" << endl;
		log.push_back("Invalid attempt to remove a non-existing checking account.");
	}
	else {

		oneClient->checking = NULL;
		delete oneClient->checking;
		log.push_back("Checking account successfully removed.");
	}

}

void BankSystem::DepositCheckingDialog()
{
	if (oneClient->checking == NULL)
	{
		cout << "The client does not have a checking account" << endl;
		log.push_back("Invalid attempt to deposit in a non-existing checking account.");
	}
	else
	{
		float amount;
		cout << "Enter amount you would like to deposit: ";
		cin >> amount;
		oneClient->checking->deposit(amount);
		log.push_back("$" + to_string(amount) + " successfully deposited in checking account.");
	}
}

void BankSystem::WithdrawCheckingDialog() {

	if (oneClient->checking == NULL) {
		cout << "The client does not have a checking account" << endl;
		log.push_back("“Invalid attempt to withdraw from a non-existing checking account");

	}
	else {
		float amount;
		cout << "Enter amount you would like to withdraw: ";
		cin >> amount;
		oneClient->checking->withdraw(amount);
		log.push_back("$" + to_string(amount) + " successfully withdrawm from checking account.");
	}
}

void BankSystem::AddSavingDialog() {
	if (oneClient->saving != NULL) {
		cout << "The client already has a saving account" << endl;
		log.push_back("“Invalid attempt to overwrite a saving account.");

	}
	else {
		float initialBalance, rate;
		cout << "Enter the initial balance for saving account: ";
		cin >> initialBalance;
		cout << "Enter the rate for saving account: ";
		cin >> rate;
		SavingAccount* save = new SavingAccount(initialBalance, rate);
		oneClient->saving = save;
		log.push_back("Saving account successfully created.");
	}
}

	void BankSystem::RemoveSavingDialog()
	{
		if (oneClient->saving == NULL)
		{
			cout << "The client does not have a saving account" << endl;
			log.push_back("Invalid attempt to remove a non-existing saving account.");
		}
		else
		{
			oneClient->saving = NULL;
			delete oneClient->saving;
			log.push_back("Saving account successfully removed.");
		}
	}

void BankSystem::DepositSavingDialog()
{
	if (oneClient->saving == NULL) {
		cout << "The client does not have a saving account" << endl;
		log.push_back("Invalid attempt to deposit in a non-existing saving account.");
	}
	else {
		float amount;
		cout << "Enter amount to deposit: ";
		cin >> amount;
		oneClient->saving->deposit(amount);
		log.push_back("$" + to_string(amount) + " successfully deposited in saving account.");
	}
}

void BankSystem::TransferDialog()
{
	if (oneClient->saving == NULL)
	{
		cout << "The client does not have a saving account" << endl;
		log.push_back("Invalid attempt to use a non-existing saving account.");
	}

	else if (oneClient->checking == NULL)
	{
		cout << "The client does not have a checking account\n";
		log.push_back("Invalid attempt to use a non-existing checking account.");
	}

	else
	{
		float amount;
		cout << "Enter the amount to transfer: ";
		cin >> amount;
		oneClient->saving->transfer(*(oneClient->checking), amount);
		log.push_back("$" + to_string(amount) + " successfully transferred from saving to checking account.");
	}
}