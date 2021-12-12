#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "banksystems.h";

using namespace std;

int main()
{
    BankSystem bank("1", "Jamil", "Ali");
    bank.start();

    return 0;
}
