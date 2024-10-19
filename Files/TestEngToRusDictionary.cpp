#include "pch.h"

#include "C:\Users\marat\Desktop\c++\Lab1Test\Lab1Test\Classes.h"
#include "C:\Users\marat\Desktop\c++\Lab1Test\Lab1Test\EngToRusDictionary.cpp"
#include "C:\Users\marat\Desktop\c++\Lab1Test\Lab1Test\WordTranslation.cpp"

TEST(TestEngToRusDitionary, EngToRusDictionar) {
	EngToRusDictionary test;
	int size = test.getSize();
	EXPECT_EQ(size, 0);

	WordTranslation word1("hello", "������");
	test += word1;
	EXPECT_EQ(test["hello"], "������");

	WordTranslation word2("car", "������");
	test += word2;
	EXPECT_EQ(test.getSize(), 2);

	test -= "car";
	EXPECT_EQ(test.getSize(), 1);
}