#pragma once
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    float balance;

public:
    float getBalance() const;
    void deposit(float amount);
};


class CheckingAccount : public Account
{
public:
    void withdraw(float amount);
    CheckingAccount(float amount);
};

class SavingAccount : public Account
{
private:
    float SavingRate;
public:
    void setSavingRate(float rate);
    float getSavingRate();
    void transfer(CheckingAccount& checkingAcc, float amount);
    SavingAccount(float amount, float rate);
};