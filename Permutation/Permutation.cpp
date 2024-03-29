// Permutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Question: “ Permutation Given two strings, write a method to decide if one is a permutation of the other

#include "pch.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include "Permutation.h"

using namespace std;

string RemoveWhiteSpaces(string ExampleString)
{
	stringstream SS = stringstream(ExampleString);
	string TokenizedString;
	string ExampleStringWithoutSpaces;
	if (ExampleString.find(" ") == string::npos)
	{
		ExampleStringWithoutSpaces = ExampleString;
		return ExampleStringWithoutSpaces;
	}

	while (getline(SS,TokenizedString,' '))
	{
		if (ExampleStringWithoutSpaces.empty())
		{
			ExampleStringWithoutSpaces = TokenizedString;
		}
		else
		{
			ExampleStringWithoutSpaces.append(TokenizedString);
		}
	}
	return ExampleStringWithoutSpaces;
}

void updateCharacterCount(std::map<char, int> &CharacterCountMapTestString, std::string &TestString, int x)
{
	auto mapIterator = CharacterCountMapTestString.find(TestString[x]);
	if (mapIterator == CharacterCountMapTestString.end())
	{
		CharacterCountMapTestString.insert(pair<char, int>(TestString[x], 1));
	}
	else
	{
		// Update Count
		mapIterator->second++;
	}
}

bool isPermutation(string TestString, string PermuationOfTestString)
{
	// For PermutationOfTestString To Be A Permutation Of Test String The Following Must Apply.
	// 1.) String Lengths Must Be Equal i.e. Same Number Of Characters Present
	// 2.) The Character Count Must Be Identical

	TestString = RemoveWhiteSpaces(TestString);
	PermuationOfTestString = RemoveWhiteSpaces(PermuationOfTestString);
	if (TestString.length() != PermuationOfTestString.length())
	{
		// We don't have a permutation here so no need to continue.
		return false;
	}

	map<char, int> CharacterCountMapTestString;
	map<char,int> CharacterCountMapPermutationOfTestString;

	// Convert The String To Lower Case
	for (int x = 0; x < TestString.length(); x++)
	{
		TestString[x] = tolower(TestString[x]);
		PermuationOfTestString[x] = tolower(PermuationOfTestString[x]);
	}

	// Count the individual character count of both strings
	for (int x = 0; x < TestString.length(); x++)
	{
		updateCharacterCount(CharacterCountMapTestString, TestString, x);
		updateCharacterCount(CharacterCountMapPermutationOfTestString, PermuationOfTestString, x);
	}

	for (auto& x : CharacterCountMapTestString)
	{
		cout << "O.G String Characters [" << x.first << "] = " << x.second << endl;
	}
	for (auto& x : CharacterCountMapPermutationOfTestString)
	{
		cout << "Permutation String Characters [" << x.first << "] = " << x.second << endl;
	}

	if (CharacterCountMapTestString == CharacterCountMapPermutationOfTestString)
	{
		cout << " This is a permutation my guy " << endl;
	}

	return false;
}

int main()
{
	string PermutationString = "ABC EF";
	string PermutationString2 = "CABfE";

	string PermutationString3 = "Dog";
	string PermutationString4 = "God";

	//cout << RemoveWhiteSpaces(PermutationString) << endl;

	isPermutation(PermutationString, PermutationString2);
	
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
