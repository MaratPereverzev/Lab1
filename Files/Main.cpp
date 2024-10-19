#include <iostream>
#include "Classes.h"
#include <locale>
#include <windows.h>

int main()
{
    setlocale(LC_ALL, "ru");

    EngToRusDictionary withoutLanguage;
    cout << withoutLanguage.getSize() << '\n';
    EngToRusDictionary dictionary("english");

    WordTranslation plane("plane", "самолёт");

    cout << plane.getWordKey() << ' ' << plane.getWordTranslation() << '\n';
    dictionary += plane;

    cout << dictionary["plane"] << '\n';
    cout << dictionary.getSize() << '\n';

    plane.setWordKey("Plane");
    plane.setWordTranslation("Самолётик");

    dictionary += WordTranslation("hello", "привет");
    dictionary += WordTranslation("apricot", "абрикос");
    dictionary += WordTranslation("yo", "здаров");
    dictionary += WordTranslation(string("building"), string("здание"));

    dictionary -= "apricot";
    dictionary -= "yo";
    dictionary -= "building";
    dictionary -= "hello";

    DictionaryManager::pipeFromFile(withoutLanguage, "C:\\Users\\marat\\Desktop\\Words.txt");

    cout << withoutLanguage["dick"] << '\n';
}