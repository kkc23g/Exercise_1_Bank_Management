#pragma once
using namespace std;
#include "Account.h"
#include "CustomString.h"

void onEnd() {
	string temp;
	cout << "\nPress any key to go back to admin menu...";
	getline(cin, temp);
	cout << endl;
}
int GetAccountNumber(unordered_map<int, Account> allAccounts, bool exist) {
	string _accountNumber;
	cout << "Enter account number:" << endl;
	getline(cin, _accountNumber);

	// Check if account number is valid
	while (!IsNumber(_accountNumber)) {
		cout << "Account number is not a valid, try again:\n";
		getline(cin, _accountNumber);
	}
	int accountNumber = stoi(_accountNumber);

	// Check if there is such an account number
	if (exist) {
		while (allAccounts.find(accountNumber) == allAccounts.end()) {
			cout << "Account number does not existed. Please enter a new one or enter 0 to exit:\n";
			getline(cin, _accountNumber);

			// Check if account number is valid
			while (!IsNumber(_accountNumber)) {
				cout << "Account number is not a valid, try again:\n";
				getline(cin, _accountNumber);
			}
			accountNumber = stoi(_accountNumber);

			if (accountNumber == 0) {
				return 0;
			}
		}
	} 
	else {
		while (allAccounts.find(accountNumber) != allAccounts.end()) {
			cout << "Account number existed. Please enter a new one:\n";
			getline(cin, _accountNumber);

			// Check if account number is valid
			while (!IsNumber(_accountNumber)) {
				cout << "Account number is not a valid, try again:\n";
				getline(cin, _accountNumber);
			}
			accountNumber = stoi(_accountNumber);
		}
	}

	return accountNumber;
}

void admin(unordered_map<int, Account> allAccounts)
{
	int condition = 0;
	while (condition != 5)
	{
		// Check input is valid
		bool inputValid = false;
		while (!inputValid) {
			cout << "\nWelcome ADMIN, choose the following please\n";
			cout << "\tpress 1 to add account\n";
			cout << "\tpress 2 to delete account\n";
			cout << "\tpress 3 to check all account\n";
			cout << "\tpress 4 to reset password of account\n";
			cout << "\tpress 5 to exit\n" << endl;

			string input;
			getline(cin, input);
			cout << endl;
			if (input.length() != 1) {
				cout << "Invalid input, please try again.\n" << endl;
			}
			else {
				if (isdigit(input[0])) {
					condition = stoi(input);
					if (condition >= 1 && condition <= 6) {
						inputValid = true;
					}
					else {
						cout << "Invalid input, please try again.\n" << endl;
					}
				}
				else {
					cout << "Invalid input, please try again.\n" << endl;
				}
			}
		}

		if (condition == 1)
		{
			// Add account
			string accountName, _balance, password;
			cout << "Enter name:" << endl;
			getline(cin, accountName);
			int accountNumber = GetAccountNumber(allAccounts, false);
			
			// Balance
			cout << "Enter balance:" << endl;
			getline(cin, _balance);
			// Check if account number is valid
			while (!IsNumber(_balance)) {
				cout << "Balance not valid, Please enter a valid balance:\n";
				getline(cin, _balance);
			}
			double balance = stod(_balance);

			// Password
			cout << "Enter password:" << endl;
			getline(cin, password);
			allAccounts[accountNumber] = Account(accountNumber, accountName, balance, password);

			// Success
			cout << "Account with account number " << accountNumber << " for " << accountName << " is added.\n";
			onEnd();
		}
		if (condition == 2)
		{
			int accountNumber = GetAccountNumber(allAccounts, true);
			if (accountNumber != 0) {
				allAccounts.erase(accountNumber);
				cout << "Account deleted.\n";
				onEnd();
			}
		}
		if (condition == 3)
		{
			cout << "Account Number, Name, Balance, Password\n";
			for (auto kv : allAccounts) {
				cout << kv.first << " " << kv.second.name << " " << kv.second.balance << " " << kv.second.password << "\n";
			}
			onEnd();
		}
		if (condition == 4)
		{
			int accountNumber = GetAccountNumber(allAccounts, true);
			if (accountNumber != 0) {
				string password;
				cout << "Enter the new password:" << endl;
				getline(cin, password);
				allAccounts[accountNumber].password = password;
			}
		}
		if (condition == 5)
		{
			condition = 5;
		}
	}
}