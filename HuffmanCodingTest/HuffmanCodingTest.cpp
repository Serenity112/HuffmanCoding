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
			string quote = "this is where it all begins";

			Map<char, int> symbolsMap;
			for (char character : quote)
				symbolsMap.Add(character, 1);

			HuffmanTree huffmantree;
			huffmantree = buildHuffmanTree(symbolsMap);

			Map<char, List<bool>*> haffmanCode = CreateHuffmanCode(huffmantree);

			List<bool> encodedLine = EncodeByHuffman(quote, haffmanCode);

			string EncodedString = bitSequanceToString(encodedLine);
			string ExpectedCode = "1111100011001000110010001011010000111001101100110111100101001110111000101110111010111010010010";
			Assert::AreEqual(ExpectedCode, EncodedString);
		}

		TEST_METHOD(HaffmanCode2)
		{
			string quote = "it is test string";

			Map<char, int> symbolsMap;
			for (char character : quote)
				symbolsMap.Add(character, 1);

			HuffmanTree huffmantree;
			huffmantree = buildHuffmanTree(symbolsMap);

			Map<char, List<bool>*> haffmanCode = CreateHuffmanCode(huffmantree);

			List<bool> encodedLine = EncodeByHuffman(quote, haffmanCode);

			string EncodedString = bitSequanceToString(encodedLine);
			string ExpectedCode = "000111100110111011000110011111100110010010101011";
			Assert::AreEqual(ExpectedCode, EncodedString);
		}
	};
}
