#pragma once
#include <string>
using namespace std;

class Account
{
public:
	int accountNunber;
	string name;
	double balance;
	string password;
	Account();
	Account(int, string, double, string);
};