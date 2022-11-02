// https://www.interviewbit.com/blog/cpp-projects/
// https://github.com/wkhaliddev/Bank-Management

#include <iostream>
#include <string>
#include <unordered_map>
#include "admin.h"
#include "Account.h"
using namespace std;

int main()
{
	std::unordered_map<int, Account> allAccounts;
	int condition = 0;
	while (condition != 4)
	{
		// Check if input is valid
		bool inputValid = false;
		while (!inputValid) {
			cout << "YOU want to login as:" << endl;
			cout << "\t1-ADMIN" << endl;
			cout << "\t2-CUSTOMER" << endl;
			cout << "\t3-EXIT\n" << endl;

			string input;
			getline(cin, input);
			cout << endl;
			if (input.length() != 1) {
				cout << "Invalid input, please try again.\n" << endl;
			}
			else {
				if (isdigit(input[0])) {
					condition = stoi(input);
					if (condition >= 1 && condition <= 4) {
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
			cout << "You are logged in as Admin" << "\n" << endl;
			admin(allAccounts);
		}
		if (condition == 2)
		{
			cout << "You are logged in as Customer" << "\n" << endl;
			condition = 2;
		}
		if (condition == 3)
		{
			condition = 3;
			break;
		}
	}
}