// Задание 22.6.1. Телефонный справочник
#include "22.6-1.h"

int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    std::wstring ask;
    inValueToMap();        // Предварительное заполнение справочника

    do {
        ask = choosingAnAction();

        std::cout << std::endl;

        if (ask == L"Exit" || ask == L"exit") {
            std::wcout << L"Спасибо, что воспользовались справочником. Всего хорошего." << std::endl;
            break;
        }

        int indSpace = ask.find(L" ");
        if (indSpace == std::string::npos) {                        // введено одно слово

            if (validNum(ask)) {                                // вводимая строка - номер телефона
                std::wcout << L"Найден владелец номера " << ask << L" - " << phDirectory.find(ask)->second << std::endl;

            } else {                                                // вводимая строка - не номер телефона
                if (surnameToNumber.find(ask) != end(surnameToNumber)) {
                    std::wcout << L"Телефоны пользователя " << ask << L": ";

                    for (std::wstring &rr: surnameToNumber.find(ask)->second) {
                        std::wcout << rr << L"; ";
                    }

                } else {
                    std::wcout << L"Такого пользователя в Справочнике не обнаружено!" << std::endl;
                }

                std::cout << std::endl;
            }

        } else {                                                    // введено два и более слова
            std::wstring numTelephone = ask.substr(0, indSpace);
            std::wstring inFamily = ask.substr(indSpace + 1, ask.length() - indSpace - 1);
//            std::vector<std::wstring> tmpVec;

            if (validNum(numTelephone)) {                                     // первое слово действительно телефон
//
                if (phDirectory.find(numTelephone) == phDirectory.end()) {    // если номера не существовало
                    phDirectory.insert(std::pair<std::wstring, std::wstring>(numTelephone, inFamily));
                    surnameToNumber.insert({inFamily, std::vector<std::wstring>{numTelephone}});
                    std::wcout << L"Вы успешно добавили в справочник нового абонента." << std::endl;
//
                } else {                                                        // номер имеется в справочнике
                    std::wstring tmpName = phDirectory.find(numTelephone)->second;

                    if (tmpName != inFamily) {                                  // смена владельца
                        phDirectory.find(numTelephone)->second = inFamily;
                        deleteNum(surnameToNumber.find(tmpName)->second, numTelephone); // Удаление элемента из вектора

                        if (surnameToNumber.find(inFamily) != surnameToNumber.end()) {
                            surnameToNumber.find(inFamily)->second.push_back(numTelephone);

                        } else {
                            surnameToNumber.insert({inFamily, std::vector<std::wstring>{numTelephone}});

                        }
                    }
                }

            } else {
                std::wcout << L"Неверно указан номер телефона! Попробуйте снова." << std::endl;
            }
        }

        std::cout << std::endl;
        system("pause");
    } while (ask != L"Exit");


    system("pause");
    return 0;
}

// *************************************

// Ввод текста и проверка на пустую строку
std::wstring inputText(const std::wstring &inTxt) {
    std::wstring resTxt;
    bool valid;

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

// Проверка целого числа
bool validNum(std::wstring &inTxt) {
    bool res = inTxt.length() == 8;

    for (int ch = 0; ch < inTxt.length(); ch++) {

        if (ch == 2 || ch == 5) {
            res &= inTxt[ch] == '-';
        } else {
            res &= inTxt[ch] >= '0' && inTxt[ch] <= '9';
        }

    }
    return res;
}

// Выбор действия
std::wstring choosingAnAction() {

    system("cls");
    std::wcout << L"Программа «Телефонный справочник»" << std::endl << std::endl;
    std::wcout << L"Введите запрос (одну из следующих комбинаций, например):»" << std::endl;
    std::wcout << L"\"69-70-30 Ivanov\" - добавить телефон и фамилию абонента в справочник;" << std::endl;
    std::wcout << L"\"69-70-30\"        - узнать фамилию абонента по номеру телефона;" << std::endl;
    std::wcout << L"\"Ivanov\"          - узнать телефон абонента по фамилии;" << std::endl;
    std::wcout << L"\"Exit\"            - для выхода из справочника." << std::endl << std::endl;
    return inputText(L"Что Вас интересует: ");

}

// Удаление элемента из вектора
void deleteNum(std::vector<std::wstring> &inVec, std::wstring &inNum) {
    std::vector<std::wstring> tmp;

    for (std::wstring ttr: inVec) {
        if (ttr != inNum) {
            tmp.push_back(ttr);
        }
    }
    inVec = tmp;
}

// Предварительное заполнение справочника
void inValueToMap() {
    phDirectory.insert({L"13-45-67", L"Ivanov"});
    phDirectory.insert({L"13-46-01", L"Tihonov"});
    phDirectory.insert({L"13-46-77", L"Ivanov"});
    phDirectory.insert({L"13-45-68", L"Gukov"});
    phDirectory.insert({L"13-45-69", L"Nikolayev"});
    phDirectory.insert({L"13-43-78", L"Trinog"});
    phDirectory.insert({L"13-45-66", L"Tihonov"});
    phDirectory.insert({L"13-43-01", L"Titov"});

    surnameToNumber.insert({L"Ivanov", {L"13-45-67", L"13-46-77"}});
    surnameToNumber.insert({L"Tihonov", {L"13-46-01", L"13-45-66"}});
    surnameToNumber.insert({L"Gukov", {L"13-45-68"}});
    surnameToNumber.insert({L"Nikolayev", {L"13-45-69"}});
    surnameToNumber.insert({L"Trinog", {L"13-43-78"}});
    surnameToNumber.insert({L"Titov", {L"13-43-01"}});
}