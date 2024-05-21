#pragma once

#include <iostream>
#include <vector>
#include <regex>
#include <codecvt>

// Глобальные переменные
std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convWStr; // Для конвертации строк в wstring
struct room {
    std::string roomName = "";
    std::string roomType = "";           // тип помещения
    float roomArea = 0.0;                // занимаемая площадь
    int roomToFloor = 0;                 // на каком этаже помещение
    int roomHeight = 0;                  // высота потолка в помещении в см
};
struct build {
    std::string buildName = "";
    std::string buildType = "";         // тип строения
    float buildArea = 0.0;              // площадь строения на участке
    float summArea = 0.0;               // суммарная площадь помещений в доме
    int floorHave = 0;                  // количество этажей
    int roomsHave = 0;                  // количество комнат
    bool stove = false;                 // печка
    std::vector<room> roomsInBuild;
};
struct ground {
    std::string groundName = "noname";
    int groundNum = 0;                  // номер участка
    float groundArea = 0.0;             // площадь участка
    int buildsNum = 0;                  // количество строений на участке
    float occupiedArea = 0;             // занято строениями
    std::vector<build> buildsInGround;  // вектор строений
};

std::vector<ground> village;

// Функции
bool validDigit(std::string &);                 // Проверка валидности целых чисел
bool validFloat(std::string &);                 // Проверка валидности чисел
std::string truncSpaces(std::string &);         // Отсечение пробелов в строке с двух сторон
std::string inputText(std::wstring);            // Ввод текста и проверка на пустую строку
std::string askTypeBuild(std::wstring);         // Запрос типа строения
std::string askTypeRoom(std::wstring);          // Запрос типа комнаты
int askIntNum(std::wstring);                    // Запрос целочисленного значения
float askFloatNum(std::wstring);                // запрос площадей
bool askStove(std::wstring);                    // запрос наличия печки в здании
void printVillage();                            // Вывод карточек участков
