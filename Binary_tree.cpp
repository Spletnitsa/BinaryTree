#include "Binary_tree.h"

void PostfixPrint(struct Node* ptr)
{
	if (ptr != NULL) {
		cout << ptr->info << " ";
		PostfixPrint(ptr->left);
		PostfixPrint(ptr->right);
	}
}

void InfixPrint(struct Node* ptr)
{
	if (ptr != NULL) {
		InfixPrint(ptr->left);
		cout << ptr->info << " ";
		InfixPrint(ptr->right);
	}
}

struct Node* push(string x, struct Node* ptr) {
	if (ptr == NULL) { 
		ptr = new Node;
		ptr->info = x;
		ptr->left = NULL;
		ptr->right = NULL;
	}
	else  if (x < ptr->info)
		ptr->left = push(x, ptr->left);
	else   
		ptr->right = push(x, ptr->right);
	return ptr;
}

struct Node* search(string SearchElem, struct Node* ptr, int counter) {
	counter++;
	if (ptr == NULL) {
		return 0;
	}
	if (SearchElem == ptr->info) {
		cout << counter;
	}
	else if (SearchElem < ptr->info) {
		search(SearchElem, ptr->left, counter);
	}
	else {
		search(SearchElem, ptr->right, counter);
	}
	return ptr;
}

int Height(struct Node* ptr) {
	if (ptr == NULL)
		return 0;
	int left = 0, right = 0;
	if (ptr->left != NULL) {
		left = Height(ptr->left);
	}
	else {
		left = 0;
	}
	if (ptr->right != NULL) {
		right = Height(ptr->right);
	}
	else {
		right = 0;
	}
	int max;
	if (left >= right)
	{
		max = left;
	}
	else
	{
		max = right;
	}
	return max + 1;
}