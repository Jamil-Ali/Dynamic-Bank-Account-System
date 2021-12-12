#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

float Account::getBalance() const
{
    return balance;
}

void Account::deposit(float amount)
{
    balance = balance + amount;
}

CheckingAccount::CheckingAccount(float amount)
{
    balance = amount;
}

void CheckingAccount::withdraw(float amount)
{
    if (amount > balance)
    {
        cout << ("Withdraw ammount greater than balance. Cannot withdraw, disregarding changes.") << endl;
        return;
    }
    else
    {
        balance = balance - amount;
    }
}

SavingAccount::SavingAccount(float amount, float rate)
{
    SavingRate = rate;
    balance = amount;
}

void SavingAccount::setSavingRate(float rate)
{
    SavingRate = rate;
}

float SavingAccount::getSavingRate()
{
    return SavingRate;
}

void SavingAccount::transfer(CheckingAccount& checkingAcc, float amount)
{
    if (amount > balance)
    {
        cout << ("Withdraw ammount greater than balance. Cannot withdraw, disregarding changes.") << endl;
        return;
    }
    else
    {
        balance = balance - amount;
        checkingAcc.deposit(amount);
    }
}
