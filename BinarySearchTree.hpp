/*
 * BinarySearchTree.hpp
 *
 *  Created on: Nov 9, 2024
 *      Author: jakesturges
 */

#ifndef BINARYSEARCHTREE_HPP_
#define BINARYSEARCHTREE_HPP_

#include <stdlib.h>
#include <iostream>

template <typename K, typename V>
class BinarySearchTree
{
public:
	BinarySearchTree() {root = NULL;};
	void insert(K key, V value);
	V find(K key);
private:
	struct node
	{
		K key;
		V value;
		struct node* left;
		struct node* right;
		node(K key, V value) : key(key), value(value), left(NULL), right(NULL) {};
	};

	node* root;
};

template <typename K, typename V>
void BinarySearchTree<K, V>::insert(K key, V value)
{
	node* newNode = new node(key, value);

	if (root == NULL)
		root = newNode;
	else
	{
		node* current = root;
		node* parent = root;
		while (current)
		{
			parent = current;
			if (key > current->key)
				current = current->right;
			else
				current = current->left;
		}

		if (key < parent->key)
			parent->left = newNode;
		else
			parent->right = newNode;
	}
}

template <typename K, typename V>
V BinarySearchTree<K, V>::find(K key)
{
	node* current = root;

	while (current)
	{
		if (key == current->key)
			return current->value;
		else if (key < current->key)
			current = current->left;
		else
			current = current->right;
	}
}

#endif /* BINARYSEARCHTREE_HPP_ */
