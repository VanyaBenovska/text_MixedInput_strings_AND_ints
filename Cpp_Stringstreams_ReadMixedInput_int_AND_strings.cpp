// Cpp_Stringstreams_ReadMixedInput_int_AND_strings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include<cstdlib>
#include <cctype>
#include<cctype>

using namespace std;
const int maxSize = 1000;

int findLength(string &str);
void initializeArray(int arr[], int sizeArr, string &str);
bool AreOnlyNumbers(string strNum);

int main()
{
	cout << "enter the array elements: ";
	string str;
	getline(cin, str);
	int arr[maxSize] = {};
	int maxFilledIndex1 = findLength(str);
	initializeArray(arr, maxFilledIndex1, str);	

	cout << "arr1 elements: ";
	for (int i = 0; i < maxFilledIndex1; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}

int findLength(string &str)
{
	int n = 0;

	for (char e : str)
		if (e == ' ')
			n++;

	return ++n;
}

void initializeArray(int arr[], int sizeArr, string &str)
{
	bool sInput = false;
	int index = 0;

	while (!sInput)
	{
		istringstream inputStream(str);

		ostringstream outputStream;

		sInput = true;

		while (inputStream)
		{
			string strNum;
			inputStream >> strNum;

			if (AreOnlyNumbers(strNum))
			{
				int num = atoi(strNum.c_str());
				arr[index] = num;
				index++;
			}
			else
			{
				//inputStream.clear();
				//string unparsed;
				//inputStream >> unparsed;				

				if (!strNum.empty())
				{
					outputStream << strNum << " ";
					sInput = false;
				}
			}
		}

		if (!sInput)
		{
			cout << "unparsed numbers: " << outputStream.str() << "enter again: ";

			getline(cin, str);
		}
	}
}

bool AreOnlyNumbers(string strNum)
{
	if (strNum.empty())
	{
		return false;
	}
	for (int i = 0; i < strNum.size(); i++)
	{
		if (isalpha(strNum[i]))
		{
			return false;
		}
	}
	return true;
}

