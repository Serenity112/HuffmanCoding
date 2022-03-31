#include <iostream>


#include "haffmanalgorithm.h"
#include "binaryheap.h"
#include "pair.h"
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





void printtree(HaffmanNode* node)
{
	if (node == nullptr)
		cout << "null\n";
	else
	{
		cout << "Sym: " << node->symbols << " Cnt: " << node->count << endl;
		printtree(node->left);
		printtree(node->right);
	}
}





inline string const BoolToString(bool b)
{
	return b ? "1" : "0";
}

void EncodeByHaffman(Map<char, int> symbolsMap)
{
	BinaryHeap<HaffmanNode>* heap = new BinaryHeap<HaffmanNode>();

	//cout << &node << endl;

	//cout << "before: " << node.symbols << endl;

	
	auto itr = symbolsMap.create_iterator();
	while (itr->has_next())
	{
		Pair<char, int> newPair = itr->next();
		HaffmanNode newNode(string(1, newPair.first), newPair.second);
		heap->insert(newNode);
		//bufferList->push_back(newNode);
	}

	cout << "Heap\n";
	auto heapiter = heap->create_iterator();
	while (heapiter->has_next())
	{
		HaffmanNode newNode = heapiter->next()->data;

		cout << "Symbol: " << newNode.symbols << " Count: " << newNode.count << endl;
	}

	HaffmanNode newNode = heap->root->data;
	newNode.symbols = "after";

	cout << "\nafter: "<< endl;
	cout << "Heap\n";
	auto heapiter2 = heap->create_iterator();
	while (heapiter2->has_next())
	{
		HaffmanNode newNode = heapiter2->next()->data;

		cout << "Symbol: " << newNode.symbols << " Count: " << newNode.count << endl;
	}
	//cout << heap->root->data.symbols << endl;



	//cout << node.symbols << endl;

	//BinaryHeap<HaffmanNode>* heap = new BinaryHeap<HaffmanNode>();
	//List<HaffmanNode*>* bufferList = new List<HaffmanNode*>();

	//

	
	//
	

	//while (heap->height != 1)
	//{
	//	HaffmanNode minNode1 = heap->pop();
	//	HaffmanNode minNode2 = heap->pop();

	//	//Creating actual leaf nodes cause in heap we have copies
	//	if (minNode1.symbols.length() == 1 || minNode1.symbols.empty())
	//	{
	//		HaffmanNode* newLeaf = new HaffmanNode(minNode1.symbols, minNode1.count);
	//		bufferList->push_back(newLeaf);
	//	}
	//	if (minNode2.symbols.length() == 1 || minNode2.symbols.empty())
	//	{
	//		HaffmanNode* newLeaf = new HaffmanNode(minNode2.symbols, minNode2.count);
	//		bufferList->push_back(newLeaf);
	//	}

	//	string combinedSymbols = minNode1.symbols + minNode2.symbols;
	//	int combinedCount = minNode1.count + minNode2.count;

	//	HaffmanNode* newNode = new HaffmanNode(combinedSymbols, combinedCount);

	//	minNode1.code = 1;
	//	minNode2.code = 0;

	//	newNode.left = &minNode1;
	//	newNode.right = &minNode2;

	//	minNode1.parent = &newNode;
	//	minNode2.parent = &newNode;

	//	heap->insert(newNode);
	//}


	//cout << "symbols " << bufferlist->head->value.symbols << endl;
	////cout << "symbols " << bufferlist.head->value->left->symbols << endl;


	////printtree);

	//auto bufferItr = bufferList->create_iterator();

	//while (bufferItr->has_next())
	//{
	//	HaffmanNode current = bufferItr->next();
	//	cout << "Code for " << current.symbols << ": ";

	//	string code = "";

	//	while (current.parent != nullptr)
	//	{
	//		code += BoolToString(current.code);
	//		current = *current.parent;
	//	}

	//	reverse(code.begin(), code.end());

	//	cout << code << endl;
	//}
}
