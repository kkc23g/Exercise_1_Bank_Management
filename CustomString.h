#pragma once
#include <string>
using namespace std;

bool IsNumber(string str) {
	string cstr = str.c_str();
	for (int i = 0; i < cstr.length(); i++)
	{
		if (!isdigit(cstr[i])) {
			return false;
		}
	}
	return true;
}