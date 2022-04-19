#include <iostream>


#include "huffmanalgorithm.h"
#include "binaryheap.h"
#include "pair.h"
#include "list.h"
#include "string"


using namespace std;

HaffmanNode::HaffmanNode()
{
	this->symbols = "NaN";
	this->count = -1;

	code = false;
	parent = nullptr;
	left = nullptr;
	right = nullptr;
}

HaffmanNode::HaffmanNode(string symbols, int count) : HaffmanNode()
{
	this->symbols = symbols;
	this->count = count;
}


Map<char, List<bool>*> EncodeByHaffman(Map<char, int> symbolsMap)
{
	BinaryHeap<HaffmanNode>* heap = new BinaryHeap<HaffmanNode>();

	auto itr = symbolsMap.create_iterator();
	while (itr->has_next())
	{
		Pair<char, int> newPair = itr->next();
		HaffmanNode newNode(string(1, newPair.first), newPair.second);
		heap->insert(newNode);
	}

	/*cout << "BinaryHeap:" << endl;
	auto heapitr = heap->create_iterator();
	while (heapitr->has_next())
	{
		HaffmanNode node = heapitr->next()->data;
		cout << node.symbols << " " << node.count << endl;
	}*/

	List<HaffmanNode*>* bufferList = new List<HaffmanNode*>();

	while (heap->height != 1)
	{
		HaffmanNode n1 = heap->pop();
		HaffmanNode n2 = heap->pop();
	
		HaffmanNode* minNode1 = &n1;
		HaffmanNode * minNode2 = &n2;

		if (minNode1->left == nullptr)
		{
			HaffmanNode* realminNode1 = new HaffmanNode(minNode1->symbols, minNode1->count);
			bufferList->push_front(realminNode1);
			minNode1 = realminNode1;
		}
		else
		{
			minNode1 = minNode1->left->parent;
		}

		if (minNode2->left == nullptr)
		{
			HaffmanNode* realminNode2 = new HaffmanNode(minNode2->symbols, minNode2->count);
			bufferList->push_front(realminNode2);
			minNode2 = realminNode2;
		}
		else
		{
			minNode2 = minNode2->left->parent;
		}

		string combinedSymbols = minNode1->symbols + minNode2->symbols;
		int combinedCount = minNode1->count + minNode2->count;

		HaffmanNode* newNode = new HaffmanNode(combinedSymbols, combinedCount);

		/*cout << "Making node " << newNode->symbols << " : " << newNode->count;
		cout << " from nodes " << minNode1->symbols << " : " << minNode1->count;
		cout << " and node " << minNode2->symbols << " : " << minNode2->count << endl;*/

		minNode1->code = 0;
		minNode2->code = 1;

		newNode->right = minNode1;
		newNode->left = minNode2;
		

		minNode1->parent = newNode;
		minNode2->parent = newNode;

		heap->insert(*newNode);
	}	

	auto bufferItr = bufferList->create_iterator();

	Map<char, List<bool>*> haffcode;

	while (bufferItr->has_next())
	{
		HaffmanNode* current = bufferItr->next();

		List<bool>* symbolCode = new List<bool>;

		char currSymbol = (current->symbols)[0];

		while (current->parent != nullptr)
		{
			symbolCode->push_front(current->code);

			current = current->parent;
		}
	
		haffcode.Insert(currSymbol, symbolCode);
	}

	return haffcode;
}
