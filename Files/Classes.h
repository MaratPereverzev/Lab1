#pragma once

#include "Tree.h"
#include "Dictionary.h"
#include "EngToRusDictionary.h"
#include "WordTranslation.h"
#include <string>

using namespace std;

class WordTranslation
{
public:
	WordTranslation(string word, string translation);
	WordTranslation(const char* word, const char* translation);
	WordTranslation();

	string getWordKey();
	string getWordTranslation();

	void setWordKey(string key);
	void setWordTranslation(string translation);
private:
	string key;
	string translation;
};

class Tree
{
private:
	class Node {
	public:
		Node(WordTranslation word, Node* left = nullptr, Node* right = nullptr) {
			this->word = word;
			this->left = left;
			this->right = right;
		};

		Node* left;
		Node* right;
		WordTranslation word;
	};

	Node* root;
public:
	Tree();
	~Tree();

	void insert(Node* current, WordTranslation word);
	void clear(Node* current);

	string find(string key);

	void insert(WordTranslation word);
	void clear();
	void pop(string key);
};

class Dictionary
{
protected:

	virtual int getSize() = 0;
	int size = 0;
	Tree wordsList;
	string language;
};


class EngToRusDictionary : public Dictionary
{
public:
	EngToRusDictionary();
	EngToRusDictionary(string language);
	int getSize() override;

	string operator [] (string key);
	void operator -= (string key);
	void operator += (WordTranslation word);
};


class DictionaryManager {
public:
	static void pipeFromFile(EngToRusDictionary& dictionary, string filePath);
};


