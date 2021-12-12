#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "Client.h";
using namespace std;


Client::Client(string i, string fn, string ln)
{
    id = stoi(i);
    firstName = fn;
    lastName = ln;
    checking = NULL;
    saving = NULL;
}

void Client::setID(int i)
{
    id = i;
}

int Client::getID()
{
    return id;
}

void Client::setName(string fn, string ln)
{
    firstName = fn;
    lastName = ln;
}

string Client::getFirstName()
{
    return firstName;
}

string Client::getLastName()
{
    return lastName;
}