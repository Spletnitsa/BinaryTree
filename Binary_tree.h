#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Node {
	string info;
	struct Node* left;
	struct Node* right;
};

void PostfixPrint(struct Node* ptr);
void InfixPrint(struct Node* ptr);
struct Node* push(string x, struct Node* ptr);
struct Node* search(string SearchElem, struct Node* ptr, int counter);
int Height(struct Node* ptr);