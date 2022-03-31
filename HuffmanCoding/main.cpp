#include "pair.h"
#include "haffmanalgorithm.h"

#include <string>
#include <iostream>

using namespace std;


int main()
{
	string quote = "it is test string";


	//getline(std::cin, quote);

	Map<char, int> symbolsMap;

	for (char character : quote) 
	{
		symbolsMap.Insert(character, 1);
	}

	



	EncodeByHaffman(symbolsMap);
	//string stroka = "afwegwe";
	//Pair<int, string> p = makepair(1, stroka);


	//cout << p.first << " " << p.second << endl;

	symbolsMap.Print();



	

	//BinaryHeap<HaffmanNode> heap;

	//heap.insert(*node);

	//cout << heap.getRoot().symbols;

}