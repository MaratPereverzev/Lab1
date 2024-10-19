#include "pch.h"

#include "C:\Users\marat\Desktop\c++\Lab1Test\Lab1Test\Classes.h"
#include "C:\Users\marat\Desktop\c++\Lab1Test\Lab1Test\Tree.cpp"
#include "C:\Users\marat\Desktop\c++\Lab1Test\Lab1Test\WordTranslation.cpp"

TEST(TestTree, Trr) {
	Tree test;
	WordTranslation word("hello", "������");
	test.insert(word);
	EXPECT_EQ(test.find("hello"), "������");
	test.pop("hello");
	EXPECT_EQ(test.find("hello"), "");
}