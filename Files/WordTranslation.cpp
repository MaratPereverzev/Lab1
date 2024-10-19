#include "Classes.h"
#include <iostream>

WordTranslation::WordTranslation(string key,string translation) {
	this->key = string(key);
	this->translation = string(translation);
};

WordTranslation::WordTranslation(const char* key, const char* translation) {
	this->key = string(key);
	this->translation = string(translation);
};


WordTranslation::WordTranslation() {
	this->key = "";
	this->translation = "";
};

string WordTranslation::getWordKey()
{
	return this->key;
};

string WordTranslation::getWordTranslation()
{
	return this->translation;
};

void WordTranslation::setWordKey(string key)
{
	this->key = key;
};

void WordTranslation::setWordTranslation(string translation)
{
	this->translation = translation;
};
