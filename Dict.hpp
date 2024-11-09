/*
 * Dict.hpp
 *
 *  Created on: Nov 9, 2024
 *      Author: jakesturges
 */

#ifndef DICT_HPP_
#define DICT_HPP_

#include <vector>
#include "BinarySearchTree.hpp"

template <typename K, typename V>
class Dict
{
public:
	Dict(){}
	void add(K key, V value);
	V operator[](K key);
private:
	BinarySearchTree<K,V> bt;
};

template <typename K, typename V>
void Dict<K,V>::add(K key, V value)
{
	bt.insert(key, value);
}

template <typename K, typename V>
V Dict<K, V>::operator [](K key)
{
	return bt.find(key);
}


#endif /* DICT_HPP_ */
