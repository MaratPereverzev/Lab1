//#include "Tree.h"
#include "Classes.h"
#include <iostream>

using namespace std;

char asciitolower(char in) {
	if (in <= 'Z' && in >= 'A')
		return in - ('Z' - 'z');
	return in;
}

int compareStrings(string first, string second) {
	int result = 0;
	string shortest = first.size() < second.size() ? first : second;
	for (int i = 0; i < shortest.size(); i++) {
		if (asciitolower(first[i]) < asciitolower(second[i])) {
			result = -1;
			break;
		}
		else if (asciitolower(first[i]) > asciitolower(second[i])) {
			result = 1;
			break;
		}
	}

	return result;
}

Tree::Tree()
{
	this->root = nullptr;
};

Tree::~Tree()
{
	this->clear();
};

void Tree::insert(Node* current, WordTranslation newWord)
{
	if (current->right == nullptr && compareStrings(current->word.getWordKey(), newWord.getWordKey()) == -1) {
		current->right = new Node(newWord);
	}
	else if (current->left == nullptr && compareStrings(current->word.getWordKey(), newWord.getWordKey()) == 1) {
		current->left = new Node(newWord);
	}
	else {
		Node* next = compareStrings(current->word.getWordKey(), newWord.getWordKey()) == 1 ? current->left : current->right;
		insert(next, newWord);
	}
};

void Tree::insert(WordTranslation newWord)
{
	if (this->root == nullptr) {
		this->root = new Node(newWord);
	}
	else {
		insert(this->root, newWord);
	}
};

void Tree::clear(Node* current) {
	if (current == nullptr)
		return;
	else
	{
		if(current->left != nullptr) clear(current->left);
		if (current->right != nullptr) clear(current->right);

		delete current;
		current = nullptr;
	}
};

string Tree::find(string key)
{
	string value = string();
	bool isFound = false;

	Node* find = root;

	while (find != nullptr) {
		if (compareStrings(find->word.getWordKey(),key) == 0) {
			isFound = true;
			value = find->word.getWordTranslation();
			break;
		}
		else if (compareStrings(find->word.getWordKey(), key) == -1) {
			find = find->right;
		}
		else if (compareStrings(find->word.getWordKey(),key) == 1) {
			find = find->left;
		}
	}

	if (isFound) return value;

	return "";
};

void Tree::clear()
{
	clear(this->root);
};

void Tree::pop(string key) {
	Node* current = root;
	Node* parent = nullptr;
	Node* find = nullptr;

	while (current != nullptr) {
		if (compareStrings(current->word.getWordKey(), key) == 0) {
			find = current;
			break;
		}
		else if (compareStrings(current->word.getWordKey(), key) == 1) {
			parent = current;
			current = current->left;
		}
		else {
			parent = current;
			current = current->right;
		}
	}

	if (find == nullptr) return;

	if (find->left == nullptr && find->right == nullptr) {
		if (parent == nullptr) {
			root = nullptr;
		}
		else if (parent->left == find) {
			parent->left = nullptr;
		}
		else {
			parent->right = nullptr;
		}
		delete find;

	}
	else if (find->left == nullptr) {
		
		if (parent == nullptr) {
			root = find->right;
		}
		else if (parent->left == find) {
			parent->left = find->right;
		}
		else {
			parent->right = find->right;
		}
		delete find;

	}
	else if (find->right == nullptr) {
		if (parent == nullptr) {
			root = find->left;
		}
		else if (parent->left == find) {
			parent->left = find->left;
		}
		else {
			parent->right = find->left;
		}
		delete find;

	}
	else {
		Node* successor = find->right;
		Node* successorParent = find;

		while (successor->left != nullptr) {
			successorParent = successor;
			successor = successor->left;
		}

		find->word = successor->word;
		if (successorParent->left == successor) {
			successorParent->left = successor->right;
		}
		else {
			successorParent->right = successor->right;
		}
		delete successor;
	}
}

/*
void Tree::pop(string key)
{
	Node* current = root;
	Node* find = nullptr;


	while (current != nullptr) {
		if (compareStrings(current->word.getWordKey(), key) == 0) {
			find = current;
			break;
		}
		else if (compareStrings(current->word.getWordKey(), key) == 1) current = current->left;
		else current = current->right;
	}


	if (find == nullptr) return;
	if (find->left == nullptr && find->right == nullptr) {
		delete find;
		find = nullptr;
	}
	else if (find->left == nullptr) {
		Node* temp = find;

		find = temp->right;
		delete temp;
	}
	else {
		Node* temp = find;

		find = temp->left;
		delete temp;
	}
};
*/