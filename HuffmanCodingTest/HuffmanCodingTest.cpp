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

			Map<char, int>* symbolsMap3 = new Map<char, int>();

			for (char character : quote3)
			{
				symbolsMap3->Add(character, 1);
			}

			Map<char, List<bool>*>* haffmanCode3 = EncodeByHaffman(symbolsMap3);

			string EncodedString = "";
			cout << "Encoded string: " << endl;
			for (char character : quote3)
			{
				List<bool>* code = haffmanCode3->Find(character);
				auto list_itr = code->create_iterator();
				while (list_itr->has_next())
				{
					EncodedString += BoolToString(list_itr->next());
				}
			}

			string ExpectedCode = "1111100011001000110010001011010000111001101100110111100101001110111000101110111010111010010010";

			Assert::AreEqual(ExpectedCode, EncodedString);
		}

		TEST_METHOD(HaffmanCode2)
		{
			string quote3 = "The Darksign is the sign of an accursed Undead";
			cout << quote3 << ":" << endl;

			Map<char, int>* symbolsMap3 = new Map<char, int>();

			for (char character : quote3)
			{
				symbolsMap3->Add(character, 1);
			}

			Map<char, List<bool>*>* haffmanCode3 = EncodeByHaffman(symbolsMap3);

			string EncodedString = "";
			cout << "Encoded string: " << endl;
			for (char character : quote3)
			{
				List<bool>* code = haffmanCode3->Find(character);
				auto list_itr = code->create_iterator();
				while (list_itr->has_next())
				{
					EncodedString += BoolToString(list_itr->next());
				}
			}

			string ExpectedCode = "1101111111011000111010010110011111011101010011111100001100110100111101011110110001101010011111100001111001110110011011000011011001000101110000011101011001000011101010001000110010111000";

			Assert::AreEqual(ExpectedCode, EncodedString);
		}
	};
}
