//#include "DictionaryManager.h"
#include "Classes.h"
#include <fstream>;
#include <regex>
#include <vector>
#include <iostream>
#include <Windows.h>

using namespace std;

string convertToWindows1251(const string& utf8Str) {
    int wideSize = MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, nullptr, 0);
    wstring wideStr(wideSize, L'\0');
    MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, &wideStr[0], wideSize);

    int ansiSize = WideCharToMultiByte(1251, 0, wideStr.c_str(), -1, nullptr, 0, nullptr, nullptr);
    string ansiStr(ansiSize, '\0');
    WideCharToMultiByte(1251, 0, wideStr.c_str(), -1, &ansiStr[0], ansiSize, nullptr, nullptr);

    return ansiStr;
}


std::vector<std::string> split(const std::string& str, const std::string& delimiter) {
    std::regex regex(delimiter);
    std::sregex_token_iterator iter(str.begin(), str.end(), regex, -1);
    std::sregex_token_iterator end;

    return { iter, end };
};

void DictionaryManager::pipeFromFile(EngToRusDictionary& dictionary, string filePath)
{
    ifstream fin(filePath);

    while (!fin.eof()) {
        string line;
        getline(fin, line);
        vector<string> result = split(line, ", ");

        string translation = convertToWindows1251(result[1]);
        dictionary += WordTranslation(result[0], translation.substr(0, translation.size() - 1));
    }
};