#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
	class Node
	{
	public:
		Node(T node, Node* prev)
		{
			_node = node;
			_prev = prev;
		}

		Node(T node) : Node(node, nullptr) {}

		T _node;
		Node* _prev;
	};

	Node* _head;
public:
	Stack()
	{
		_head = nullptr;
	}

	~Stack()
	{
		while (!empty())
		{
			pop();
		}
	}

	void pop()
	{
		if (empty())
		{
			throw out_of_range("No more elements");
		}
		else
		{
			Node* temp = _head;
			_head = _head->_prev;
			delete temp;
		}
	}

	void push(T node)
	{
		Node* newNode = new Node(node, _head);
		_head = newNode;
	}

	bool empty()
	{
		return _head == nullptr;
	}

	T top()
	{
		if (empty())
		{
			throw out_of_range("Empty");
		}
		else
		{
			return _head->_node;
		}
	}
};

#endif