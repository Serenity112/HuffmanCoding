#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "iterator.h"
using namespace std;

template <class T>
class List
{
public:
	class Node
	{
	public:
		friend class ListIterator;

		Node(T value, Node* next, Node* prev)
		{
			this->next = next;
			this->prev = prev;
			this->value = value;
		}

		Node(T value) : Node(value, nullptr, nullptr) {}

		~Node() {};

		Node* next;

		Node* prev;

		T value;

	};

	

	Node* last;

public:
	Node* head;

	List()
	{
		head = nullptr;
		last = nullptr;
	}

	~List()
	{
		Node* currNode = head;

		while (currNode != nullptr)
		{
			currNode = currNode->next;
			delete head;
			head = currNode;
		}
	}

	void push_back(T elem)
	{
		Node* newElem = new Node(elem, nullptr, last);
		if (isEmpty())
		{
			head = newElem;
		}
		else
		{
			last->next = newElem;
		}
		last = newElem;
	}

	void push_front(T elem)
	{
		Node* newElem = new Node(elem, head, nullptr);;
		if (isEmpty())
		{
			last = newElem;
		}
		else
		{
			head->prev = newElem;
		}
		head = newElem;
	}

	void pop_back()
	{
		if (isEmpty())
		{
			throw invalid_argument("Nothin to pop");
		}
		else if (head->next == nullptr)
		{
			pop_only();
		}
		else
		{
			Node* currNode = last->prev;
			delete last;
			last = currNode;
			currNode->next = nullptr;
		}
	}

	void pop_front()
	{
		if (isEmpty())
		{
			throw invalid_argument("Nothin to pop");
		}
		else if (head->next == nullptr)
		{
			pop_only();
		}
		else
		{
			Node* currNode = head->next;
			delete head;
			head = currNode;
			currNode->prev = nullptr;
		}
	}

	void clear()
	{
		this->~List();
		return;
	}

	bool isEmpty()
	{
		return head == nullptr;
	}

	Iterator<T>* create_iterator()
	{
		return new ListIterator(this);
	}

	class ListIterator : public Iterator<T>
	{
	public:
		friend class List;

		Node* current;

		ListIterator(List<T>* list)
		{
			current = list->head;
		}

		~ListIterator()
		{
		}

		bool has_next()
		{
			return current != nullptr;
		}

		T next()
		{
			T temp = current->value;
			current = current->next;
			return temp;
		}
	};
private:
	void pop_only()
	{
		delete head;
		head = nullptr;
		last = nullptr;
	}

};
#endif