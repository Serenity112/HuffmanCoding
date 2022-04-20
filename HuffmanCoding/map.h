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
	Map()
	{
		rbtree = new RBTree<T1, T2>();
	}

	~Map()
	{
		delete rbtree;
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
		return rbtree->FindData(key);
	}

	void Clear()
	{
		delete rbtree;
		rbtree = new RBTree<T1, T2>();
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
				pairs.push_back(treeiter->next());
			}

			listiter = pairs.create_iterator();

			delete treeiter;
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
			return listiter->next();
		}
	};	

	MapIterator* create_iterator()
	{
		return new MapIterator(rbtree);
	}
};

#endif