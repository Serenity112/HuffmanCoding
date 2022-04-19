#ifndef HAFFMANALGORITHM_H
#define HAFFMANALGORITHM_H

#include "map.h"

class HaffmanNode
{
public:
	string symbols;
	int count;
	bool code;

	HaffmanNode* parent;
	HaffmanNode* left;
	HaffmanNode* right;

	HaffmanNode(string, int);

	HaffmanNode();
};



Map<char, List<bool>*	> EncodeByHaffman(Map<char, int>);

#endif