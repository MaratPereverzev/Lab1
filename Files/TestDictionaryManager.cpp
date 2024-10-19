#include "pch.h"

#include "C:\Users\marat\Desktop\c++\Lab1Test\Lab1Test\Classes.h"
#include "C:\Users\marat\Desktop\c++\Lab1Test\Lab1Test\EngToRusDictionary.cpp"
#include "C:\Users\marat\Desktop\c++\Lab1Test\Lab1Test\DictionaryManager.cpp"

TEST(TestDictionaryManager, DictMan) {
	EngToRusDictionary test;

	DictionaryManager::pipeFromFile(test, "C:\\Users\\marat\\Desktop\\Words.txt");
	EXPECT_EQ(test["nice"], "��������");
}
