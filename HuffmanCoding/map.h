#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "string"
#include "rbtree.h"
#include "list.h"
#include "pair.h"



template <class T1, class T2>
class Map
{
private:
	RBTree<T1, T2>* rbtree;
public:

	T2 operator [](T1& key)
	{
		return rbtree[key];
	}

	///*T2& operator [](T1 const key)
	//{
	//	return rbtree[key];
	//}*/

	Map()
	{
		rbtree = new RBTree<T1, T2>();
	}

	void Insert(T1 key, T2 data)
	{
		rbtree->Insert(key, data);
	}

	void Add(T1 key, T2 data)
	{
		rbtree->Add(key, data);
	}

	void Delete(T1 key)
	{
		rbtree->Delete(key);
	}

	T2 Find(T1 key)
	{
		return rbtree->GetData(key);
	}

	void Clear()
	{
		delete rbtree;
		rbtree = new RBTree<T1, T2>();
	}


	void Print()
	{
		auto itr = create_iterator();

		while (itr->has_next())
		{
			Pair<T1, T2> newPair = itr->next();
			cout << newPair.first << " " << newPair.second << endl;
		}
	}

	Iterator<Pair<T1, T2>>* create_iterator()
	{
		return new MapIterator(rbtree);
	}

	class MapIterator : public Iterator<Pair<T1, T2>>
	{
	public:
		friend class Map;

		List<Pair<T1, T2>> pairs;

		Iterator<Pair<T1, T2>>* listiter;

		MapIterator(RBTree<T1, T2>* rbtree)
		{
			auto treeiter = rbtree->create_iterator();

			while (treeiter->has_next())
			{
				Pair<T1, T2> newPair = rbtree->GetPair(treeiter->next());
				pairs.push_back(newPair);
			}

			listiter = pairs.create_iterator();
		}

		~MapIterator()
		{
			delete listiter;
		}

		bool has_next()
		{
			return listiter->has_next();
		}

		Pair<T1, T2> next()
		{
			Pair<T1, T2> currPair = listiter->next();
			return currPair;
		}
	};	
};

#endif