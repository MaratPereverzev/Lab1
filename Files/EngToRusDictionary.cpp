#include "Classes.h"
//#include "EngToRusDictionary.h"
#include <iostream>

EngToRusDictionary::EngToRusDictionary()
{
	this->size = 0;
};

EngToRusDictionary::EngToRusDictionary(string language)
{
	this->size = 0;
	this->language = language;
};

int EngToRusDictionary::getSize()
{
	return this->size;
};

string EngToRusDictionary::operator[](string key)
{
	string foundWord = this->wordsList.find(key);
	return foundWord;
};

void EngToRusDictionary::operator-=(string key)
{
	this->wordsList.pop(key);
	this->size--;
};

void EngToRusDictionary::operator+=(WordTranslation word)
{
	this->wordsList.insert(word);
	this->size++;
};
