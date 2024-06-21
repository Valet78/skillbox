// Задание 22.6.1. Телефонный справочник
#include "22.6-1.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::string ask = "";
    inValueToMap();        // Предварительное заполнение справочника

    do {
        system("cls");
        std::wcout << L"Программа «Телефонный справочник»" << std::endl << std::endl;
        std::wcout << L"Введите запрос (одну из следующих комбинаций, например):»" << std::endl;
        std::wcout << L"\"69-70-30 Ivanov\" - добавить телефон и фамилию абонента в справочник;" << std::endl;
        std::wcout << L"\"69-70-30\"        - узнать фамилию абонента по номеру телефона;" << std::endl;
        std::wcout << L"\"Ivanov\"          - узнать телефон абонента по фамилии;" << std::endl;
        std::wcout << L"\"Exit\"            - для выхода из справочника." << std::endl << std::endl;
        ask = inputText(L"Что Вас интересует: ");

        std::cout << std::endl;

        if (ask == "Exit" || ask == "exit") {
            std::wcout << L"Спасибо, что воспользовались справочником. Всего хорошего." << std::endl;
            break;
        }

        int indSpace = ask.find(" ");
        if (indSpace == std::string::npos) {

            if (validNum(ask)) {
                std::wcout << L"Найден владелец номера ";
                std::cout << ask << " - " << phDirectory[ask] << std::endl;

            } else {
                int num = 0;

                for (auto &it: phDirectory) {
                    if (it.second == ask) {

                        if (num == 0) {
                            std::wcout << L"Обнаружены следующие номера: " << std::endl;
                        }

                        std::cout << "\t" << it.second << ": " << it.first << std::endl;
                        num++;
                    }
                }

                if (num == 0) {
                    std::wcout << L"У пользователя ";
                    std::cout << ask;
                    std::wcout << L" в справочнике номера не обнаружены!" << std::endl;
                }
            }


        } else {
            std::string numTelephone = ask.substr(0, indSpace);
            std::string inFamily = ask.substr(indSpace + 1, ask.length() - indSpace - 1);

            if (validNum(numTelephone)) {
                std::pair<std::string, std::string> abonent(numTelephone, inFamily);
                phDirectory.insert(abonent);
                std::wcout << L"Вы успешно добавили в справочник нового абонента." << std::endl;

            } else {
                std::wcout << L"Неверно указан номер телефона! Попробуйте снова." << std::endl;
            }
        }

        std::cout << std::endl;
        system("pause");
    } while (ask != "Exit");


    system("pause");
    return 0;
}

// *************************************

// Ввод текста и проверка на пустую строку
std::string inputText(std::wstring inTxt) {
    std::string resTxt = "";
    bool valid = true;

    do {
        valid = true;
        std::wcout << inTxt;
        std::getline(std::cin, resTxt);

        if (resTxt.empty()) {
            std::wcerr << L"Забыли ввести данные. Попробуйте снова." << std::endl;
            valid = false;
        }
    } while (!valid);

    return resTxt;
}

// Проверка целого числа
bool validNum(std::string &inTxt) {
    bool res = (inTxt.length() == 8) ? true : false;

    for (int ch = 0; ch < inTxt.length(); ch++) {

        if (ch == 2 || ch == 5) {
            res &= (inTxt[ch] == '-') ? true : false;
        } else {
            res &= (inTxt[ch] >= '0' && inTxt[ch] <= '9') ? true : false;
        }

    }
    return res;
}

// Предварительное заполнение справочника
void inValueToMap() {
    phDirectory.insert({"13-45-67", "Ivanov"});
    phDirectory.insert({"13-46-01", "Tihonov"});
    phDirectory.insert({"13-46-77", "Ivanov"});
    phDirectory.insert({"13-45-68", "Gukov"});
    phDirectory.insert({"13-45-69", "Nikolayev"});
    phDirectory.insert({"13-43-78", "Trinog"});
    phDirectory.insert({"13-45-66", "Tihonov"});
    phDirectory.insert({"13-43-01", "Titov"});

}