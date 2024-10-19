#include "pch.h"

#include "C:\Users\marat\Desktop\c++\Lab1Test\Lab1Test\Classes.h"
#include "C:\Users\marat\Desktop\c++\Lab1Test\Lab1Test\Tree.cpp"
#include "C:\Users\marat\Desktop\c++\Lab1Test\Lab1Test\EngToRusDictionary.cpp"
#include "C:\Users\marat\Desktop\c++\Lab1Test\Lab1Test\DictionaryManager.cpp"
#include "C:\Users\marat\Desktop\c++\Lab1Test\Lab1Test\WordTranslation.cpp"

#include <string>

TEST(TestEngToRusDitionary, EngToRusDictionar) {
	EngToRusDictionary test;
	int size = test.getSize();
	EXPECT_EQ(size, 0);

	WordTranslation word1("hello", "привет");
	test += word1;
	EXPECT_EQ(test["hello"], "привет");

	WordTranslation word2("car", "машина");
	test += word2;
	EXPECT_EQ(test.getSize(), 2);

	test -= "car";
	EXPECT_EQ(test.getSize(), 1);
}

TEST(TestTree, Trr) {
	Tree test;
	WordTranslation word("hello", "привет");
	test.insert(word);
	EXPECT_EQ(test.find("hello"), "привет");
	test.pop("hello");
	EXPECT_EQ(test.find("hello"), "");
}

TEST(TestWordTranslation, WordTrans) {
	WordTranslation word("hello", "привет");
	EXPECT_EQ(word.getWordKey(), "hello");
	EXPECT_EQ(word.getWordTranslation(), "привет");

	word.setWordKey("hi");
	word.setWordTranslation("салам");
	EXPECT_EQ(word.getWordKey(), "hi");
	EXPECT_EQ(word.getWordTranslation(), "салам");
}

TEST(TestDictionaryManager, DictMan) {
	EngToRusDictionary test;

	DictionaryManager::pipeFromFile(test, "C:\\Users\\marat\\Desktop\\Words.txt");
	EXPECT_EQ(test["nice"], "красивый");
}
