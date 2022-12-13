#pragma once
#include "BSTNode.h"
#include <iostream>

class BST {
private:
	BSTNode* root;

public:
	BST() { root = NULL; }
	~BST() {}
	bool find(int key);
	int min();
	int max();
	void add(int key);
	void remove(int key);
	void print();
};

