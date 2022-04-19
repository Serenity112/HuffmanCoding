#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <iostream>

#include "..\HuffmanCoding\pair.h"
#include "..\HuffmanCoding\huffmanalgorithm.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HuffmanCodingTest
{
	TEST_CLASS(HuffmanCodingTest)
	{

	public:
		inline string const BoolToString(bool b)
		{
			return b ? "1" : "0";
		}
		TEST_METHOD(HaffmanCode1)
		{
			string quote3 = "this is where it all begins";
			cout << quote3 << ":" << endl;

			Map<char, int> symbolsMap3;

			for (char character : quote3)
			{
				symbolsMap3.Add(character, 1);
			}

			Map<char, List<bool>*> haffmanCode3 = EncodeByHaffman(symbolsMap3);

			string encodedString;
			

			int encodedSize3 = 0;

			auto map_itr3 = haffmanCode3.create_iterator();
			auto sym_itr3 = symbolsMap3.create_iterator();

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
		}
	};
}
