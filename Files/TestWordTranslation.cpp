#include "pch.h"

#include "C:\Users\marat\Desktop\c++\Lab1Test\Lab1Test\Classes.h"
#include "C:\Users\marat\Desktop\c++\Lab1Test\Lab1Test\WordTranslation.cpp"

TEST(TestWordTranslation, WordTrans) {
	WordTranslation word("hello", "������");
	EXPECT_EQ(word.getWordKey(), "hello");
	EXPECT_EQ(word.getWordTranslation(), "������");

	word.setWordKey("hi");
	word.setWordTranslation("�����");
	EXPECT_EQ(word.getWordKey(), "hi");
	EXPECT_EQ(word.getWordTranslation(), "�����");
}