#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>
#include <ctime>
#include <regex>
#include <vector>
#include <codecvt>  // Для конвертации строк в wstring


// Глобальные переменные
std::string fileDataName = "data.bin";
char field[20][20];
std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convWStr; // Для конвертации строк в wstring
struct coord {
    int x = 0, y = 0;
};
struct player {
    std::string name = "";
    int life = 0, armor = 0, damage = 0;
    char mark = ' ';
    coord coordField{0, 0};
};
std::vector<player> characters{0};


// Функции
void printField();                              // Вывод поля на экран
void inicMassiv();                              // Проинициализируем массив поля
int randNum(int, int);                          // Генерируем случайное число в диапазоне
bool validNum(std::string &);                   // Проверка целого числа
int inValidInNumber(std::wstring, int, int);    // Запрос целого числа из диапазона
std::string truncSpaces(std::string &);         // Отсечение пробелов в строке с двух сторон
std::string inputText(std::wstring);            // Ввод текста и проверка на пустую строку
void createPlayer();                            // Создаём пользовательского игрока
void createCharacter(int);                      // Создаем игроков противника
bool saveDataToFile();                          // Запись в файл данных вектора
int loadDataFromFile();                         // Загружаем данные из файла с данными
std::string requestMove();                      // Запрос хода игрока
int searchOpponent(int, int);                   // Ищем оппонента в заданной точке поля
void attackOpp(player &, player &);             // Отработки атаки
bool executeMove(player &, std::string &);      // Ход персонажей (код хода)
bool askLoadGame(std::wstring);                 // Запрос на загрузку ранее сохранённой игры


