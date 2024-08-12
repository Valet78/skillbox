// Задание 24.5.1. Реализация программы учёта времени
#include "24.5-1.h"

int main() {
//  std::setlocale(LC_ALL, "Russian_Russia.1251");
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    std::wstring commTxt;

    do {
        HEADING
        commTxt = inputText(L"Укажите Ваш вариант: ");
        std::cout << std::endl;

        if (commTxt == L"exit" || commTxt == L"выход") {
            std::wcout << L"Жаль, что Вы уже уходите! До свидания." << std::endl;
            system("pause");
            return 0;

        } else if (commTxt == L"begin" || commTxt == L"начать") {
            if (startTask == 0) {
                startTask = std::time(nullptr);
                stopTask = 0;
                numTask++;
                wStart = convWStr.from_bytes(std::asctime(std::localtime(&startTask)));
                wTask = L"Task_" + std::to_wstring(numTask);
                std::wcout << L"Начинаем новую задачу: " << wTask << std::endl;
                std::wcout << L"Время старта: " << wStart << std::endl;

            } else {
                stopTaskFun();
                startTask = std::time(nullptr);
                numTask++;
                wStart = convWStr.from_bytes(std::asctime(std::localtime(&startTask)));
                wTask = L"Task_" + std::to_wstring(numTask);
                std::wcout << L"Начинаем новую задачу: " << wTask << std::endl;
                std::wcout << L"Время старта: " << wStart << std::endl;
            }

        } else if (commTxt == L"end" || commTxt == L"стоп") {
            if (startTask == 0) {
                std::wcout << std::endl << L"Активных задач не обнаружено!" << std::endl;
                std::wcout << L"Для запуска новой задачи выберите соответствующий пункт." << std::endl << std::endl;
            } else {
                stopTaskFun();
                std::wcout << L"Для запуска новой задачи выберите соответствующий пункт." << std::endl << std::endl;
            }

        } else if (commTxt == L"status" || commTxt == L"статус") {
            if (listTask.empty()) {
                std::wcout << std::endl << L"Ранее созданных задач не обнаружено!" << std::endl;
            } else {
                std::wcout << L"Были выполнены следующие задачи: " << std::endl;
                for (auto task: listTask) {
                    std::wcout << task[0] << std::endl;
                    std::wcout << L"\tначало: " << task[1];
                    std::wcout << L"\tокончена: " << task[2];
                    std::wcout << L"\tдлительность: " << task[3] << std::endl;
                }
            }

            if (startTask != 0) {
                std::wcout << L"Имеется незавершённая задача: " << wTask << std::endl;
                std::wcout << L"Задача запущена: " << wStart << std::endl;
            }

        } else {
            std::wcerr << std::endl << L"Выбирайте команды из списка!" << std::endl << std::endl;
        }

        system("pause");
    } while (!(commTxt == L"exit" || commTxt == L"выход"));


    system("pause");
    return 0;
}

// *************************************

// Ввод текста и проверка на пустую строку
std::wstring inputText(std::wstring &&inTxt) {
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

// Вычисление длительности задачи
std::wstring calcTime(std::time_t inTime) {
    std::wstring temp{};
    long long day = 0;
    long long hour = inTime / 3600;
    long long minutes = (inTime % 3600) / 60;
    long long seconds = (inTime % 3600) % 60;

    if (hour >= 24) {
        day = hour / 24;
        hour = hour % 24;
    }

    if (day > 0) {
        temp += std::to_wstring(day) + L" дней(дня, дня) ";
    }
    if (hour > 0) {
        temp += std::to_wstring(hour) + L" часов(а) ";
    }
    if (minutes > 0) {
        temp += std::to_wstring(minutes) + L" минут(ы) ";
    }
    if (seconds > 0) {
        temp += std::to_wstring(seconds) + L" секунд(ы) ";
    }

    return temp;
}

// Останавливаем задачу
void stopTaskFun() {
    stopTask = std::time(nullptr);
    wStop = convWStr.from_bytes(std::asctime(std::localtime(&stopTask)));
    timeTask = stopTask - startTask;
    wTime = calcTime(timeTask);

    listTask.push_back({wTask, wStart, wStop, wTime});
    std::wcout << std::endl;
    std::wcout << L"Ранее запущенная задача " << wTask << L" будет остановлена." << std::endl;
    std::wcout << L"\tзапущена: " << wStart;
    std::wcout << L"\tостановлена: " << wStop;
    std::wcout << L"\tдлилась: " << wTime << std::endl << std::endl;
    startTask = 0;
    stopTask = 0;
}