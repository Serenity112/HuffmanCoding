#include "pair.h"
#include "huffmanalgorithm.h"

#include <string>
#include <iostream>

using namespace std;

inline string const BoolToString(bool b)
{
	return b ? "1" : "0";
}

int main()
{
	//Quote 1 The Darksign is the sign of an accursed Undead
	string quote1 = "The Darksign is the sign of an accursed Undead";
	cout << quote1 << ":" << endl;

	Map<char, int>* symbolsMap1 = new Map<char, int>();

	for (char character : quote1) 
	{
		symbolsMap1->Add(character, 1);	
	}

	Map<char, List<bool>*>* haffmanCode1 = EncodeByHaffman(symbolsMap1);

	int encodedSize1 = 0;

	auto map_itr1 = haffmanCode1->create_iterator();
	auto sym_itr1 = symbolsMap1->create_iterator();

	while (map_itr1->has_next())
	{
		Pair<char, List<bool>*> newPair = map_itr1->next();
		auto list_itr = newPair.second->create_iterator();
		
		int symFreq = sym_itr1->next().second;

		cout << newPair.first << " ";
		while (list_itr->has_next())
		{
			encodedSize1 += symFreq;
			cout << list_itr->next();
		}
		cout << endl;
	}
	cout << "Size before encode: " << quote1.length()*sizeof(char)*8 << " bits" << endl;
	cout << "Size after encode: " << encodedSize1 << " bits" << endl;

	cout << "Encoded string: " << endl;
	for (char character : quote1)
	{
		List<bool>* code = haffmanCode1->Find(character);
		auto list_itr = code->create_iterator();
		while (list_itr->has_next())
		{
			cout << BoolToString(list_itr->next());
		}
	}
	cout << endl << endl;
	


	//Quote 2

	string quote2 = "This ring was named after Havel the Rock, Lord Gwyn's old battlefield compatriot";
	cout << quote2 << ":" << endl;

	Map<char, int>* symbolsMap2 = new Map<char, int>();

	for (char character : quote2)
	{
		symbolsMap2->Add(character, 1);
	}

	Map<char, List<bool>*>* haffmanCode2 = EncodeByHaffman(symbolsMap2);

	int encodedSize2 = 0;

	auto map_itr2 = haffmanCode2->create_iterator();
	auto sym_itr2 = symbolsMap2->create_iterator();

	while (map_itr2->has_next())
	{
		Pair<char, List<bool>*> newPair = map_itr2->next();
		auto list_itr = newPair.second->create_iterator();

		int symFreq = sym_itr2->next().second;

		cout << newPair.first << " ";
		while (list_itr->has_next())
		{
			encodedSize2 += symFreq;
			cout << list_itr->next();
		}
		cout << endl;
	}

	cout << "Size before encode: " << quote2.length() * sizeof(char) * 8 << " bits" << endl;
	cout << "Size after encode: " << encodedSize2 << " bits" << endl;
	cout << "Encoded string: " << endl;
	for (char character : quote2)
	{
		List<bool>* code = haffmanCode2->Find(character);
		auto list_itr = code->create_iterator();
		while (list_itr->has_next())
		{
			cout << BoolToString(list_itr->next());
		}
	}
	cout << endl << endl;

	// Quote 3

	string quote3 = "this is where it all begins";
	cout << quote3 << ":" << endl;

	Map<char, int>* symbolsMap3 = new Map<char, int>();

	for (char character : quote3)
	{
		symbolsMap3->Add(character, 1);
	}

	Map<char, List<bool>*>* haffmanCode3 = EncodeByHaffman(symbolsMap3);

	int encodedSize3 = 0;

	auto map_itr3 = haffmanCode3->create_iterator();
	auto sym_itr3 = symbolsMap3->create_iterator();

	while (map_itr3->has_next())
	{
		Pair<char, List<bool>*> newPair = map_itr3->next();
		auto list_itr = newPair.second->create_iterator();

		int symFreq = sym_itr3->next().second;

		cout << newPair.first << " ";
		while (list_itr->has_next())
		{
			encodedSize3 += symFreq;
			cout << list_itr->next();
		}
		cout << endl;
	}
	cout << "Size before encode: " << quote3.length() * sizeof(char) * 8 << " bits" << endl;
	cout << "Size after encode: " << encodedSize3 << " bits" << endl;

	cout << "Encoded string: " << endl;
	for (char character : quote3)
	{
		List<bool>* code = haffmanCode3->Find(character);
		auto list_itr = code->create_iterator();
		while (list_itr->has_next())
		{
			cout << BoolToString(list_itr->next());
		}
	}
	cout << endl << endl;
}