// Задание 22.6.3. Анаграммы
#include "22.6-3.h"

int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    std::wcout << std::endl << L"Программа проверки, явлется ли слово анаграммой другого." << std::endl << std::endl;
    std::wstring wordOne = inputText(L"Введите первое слово: ");
    std::wstring wordTwo = inputText(L"Введите второе слово: ");

    if (checkStrings(wordOne, wordTwo)) {
        std::wcout << std::endl << L"Слово \"" << wordTwo << L"\" является анаграммой слова \"" << wordOne << L"\".";

    } else {
        std::wcout << std::endl << L"Слово \"" << wordTwo << L"\" не является анаграммой слова \"" << wordOne << L"\".";
    }
    std::cout << std::endl << std::endl;
    system("pause");
    return 0;
}

// *************************************


// Проверка слов
bool checkStrings(std::wstring &word1, std::wstring &word2) {
    std::map<char, int> mapOne;
    std::map<char, int> mapTwo;

    for (auto &ch: word1) {
        if (!mapOne.count(ch)) {
            mapOne[ch] = 1;
        } else {
            mapOne[ch]++;
        }
    }
    for (auto &ch: word2) {
        if (!mapTwo.count(ch)) {
            mapTwo[ch] = 1;
        } else {
            mapTwo[ch]++;
        }
    }

    return mapOne == mapTwo;
}

// Ввод текста и проверка на пустую строку
std::wstring inputText(std::wstring inTxt) {
    std::wstring resTxt = L"";
    bool valid = true;

    do {
        valid = true;
        std::wcout << inTxt;
        std::getline(std::wcin, resTxt);

        if (resTxt.empty()) {
            std::wcerr << L"Забыли ввести данные. Попробуйте снова." << std::endl;
            valid = false;
        }
    } while (!valid);

    return resTxt;
}