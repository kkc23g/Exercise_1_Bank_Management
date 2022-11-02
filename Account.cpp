#include <string>
#include <iostream>
#include "Account.h"
using namespace std;

Account::Account() {
	accountNunber = 0;
	name = "";
	balance = 0;
	password = "";
}
Account::Account(int _accountNunber, string _name, double _balance, string _password) {
	accountNunber = _accountNunber;
	name = _name;
	balance = _balance;
	password = _password;
}