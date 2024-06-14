// Задание 21.5.4. Пошаговая ролевая игра (дополнительная задача)
#include "21.5-4.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::srand(std::time(nullptr));

    bool itWin = false, resMove = true;
    int kodMove = 0;
    inicMassiv();

    std::wcout << L"   * Пошаговая ролевая игра *" << std::endl << std::endl;
    std::wcout << L"Для начала игры создадим игроков, одного пользовательского и несколько противников." << std::endl;
    createPlayer(); // пользовательский игрок
    createCharacter(5);

    std::string doMove = "";
    printField();

    do {
        resMove = true;
        itWin = false;

        // Ход игрока
        doMove = requestMove();
        resMove &= executeMove(characters[0], doMove);

        if (resMove) {
            int pe = 1;

            // Ход врагов
            do {
                resMove = true;
                kodMove = randNum(1, 100) % 4;

                switch (kodMove) {
                    case 0:
                        doMove = "U";
                        break;
                    case 1:
                        doMove = "R";
                        break;
                    case 2:
                        doMove = "D";
                        break;
                    case 3:
                        doMove = "L";
                        break;
                }

                resMove &= executeMove(characters[pe], doMove);
                pe += (resMove) ? 1 : 0;

            } while (pe < characters.size());

            // Определяем победителя
            if (characters[0].life == 0) {
                itWin = true;
                std::wcout << L"Ваш игрок проиграл в этой игре! Враги одолели его." << std::endl;
            } else {
                int numVin = 0;

                for (int i = 1; i < characters.size(); i++) {
                    numVin += (characters[i].life > 0) ? 1 : 0;
                }

                if (numVin == 0) {
                    itWin = true;
                    std::wcout << L"Поздравляем, Ваш игрок выиграл эту битву!" << std::endl;
                }
            }
        }

        printField();

    } while (!itWin);

    std::wcout << L"Надеемся увидеть Вас снова. Всего доброго." << std::endl;
    system("pause");
    return 0;
}

// ********************

// Проинициализируем массив поля
void inicMassiv() {
    for (int i = 0; i < 20; i++) {
        for (int k = 0; k < 20; k++) {
            field[i][k] = '.';
        }
    }
}

// Вывод поля на экран
void printField() {
    system("cls");

    for (int i = 0; i < 20; i++) {              // y
        for (int k = 0; k < 20; k++) {          // x
            std::wcout << convWStr.from_bytes(field[i][k]) << L"  ";
        }

        if (i < characters.size()) {
            std::wcout << L"\tИгрок: " << convWStr.from_bytes(characters[i].name) << L". Уровень жизни: "
                       << characters[i].life << L", брони: " << characters[i].armor << std::endl;
        } else {
            std::cout << std::endl;
        }

    }
    std::cout << std::endl;
}

// Отсечение пробелов в строке с двух сторон
std::string truncSpaces(std::string &inTxt) {
    inTxt = std::regex_replace(inTxt, std::regex("^\\s+"), "");
    inTxt = std::regex_replace(inTxt, std::regex("\\s+$"), "");
    return inTxt;
}

// Генерируем случайное число в диапазоне
int randNum(int inStart, int inStop) {
    return inStart + std::rand() % (inStart - inStop + 1);
}

// Ввод текста и проверка на пустую строку
std::string inputText(std::wstring inTxt) {
    std::string resTxt = "";
    bool valid = true;

    do {
        valid = true;
        std::wcout << inTxt;
        std::getline(std::cin, resTxt);
        resTxt = truncSpaces(resTxt);

        if (resTxt.empty()) {
            std::wcerr << L"Забыли ввести данные. Попробуйте снова." << std::endl;
            valid = false;
        }
    } while (!valid);

    return truncSpaces(resTxt);
}

// Проверка целого числа
bool validNum(std::string &inTxt) {
    bool res = true;

    for (char ch: inTxt) {
        res &= (ch >= '0' && ch <= '9') ? true : false;
    }
    return res;
}

// Запрос целого числа из диапазона
int inValidInNumber(std::wstring inWTxt, int inMin, int inMax) {
    bool valid = true;
    std::string tmpTxt = "";
    int value = 0;

    do {
        valid = true;
        tmpTxt = inputText(inWTxt);
        value = (validNum(tmpTxt)) ? std::stoi(tmpTxt) : -1;
        valid &= (value >= inMin && value <= inMax) ? true : false;

        if (!valid) {
            std::wcout << L"Значение должно быть в указанных рамках (" << inMin << L" - " << inMax << L")!"
                       << std::endl;
        }

    } while (!valid);

    return value;
}

// Создаём пользовательского игрока
void createPlayer() {
    player tmpPlayer;

    std::string tmpTxt = inputText(L"Укажите имя Вашего игрока: ");
    tmpPlayer.name = tmpTxt;
    tmpPlayer.life = inValidInNumber(L"Укажите уровень \"жизни\" игрока (50 - 150): ", 50, 150);
    tmpPlayer.armor = inValidInNumber(L"Укажите уровень \"защиты\" персонажа (0 - 50): ", 0, 50);
    tmpPlayer.damage = inValidInNumber(L"Укажите уровень \"урона\" игрокаа (15 - 30): ", 15, 30);
    tmpPlayer.coordField.x = randNum(0, 20);
    tmpPlayer.coordField.y = randNum(0, 20);
    tmpPlayer.mark = 'P';
    field[tmpPlayer.coordField.y][tmpPlayer.coordField.x] = 'P';
    characters.push_back(tmpPlayer);
}

// Создаем игроков противника
void createCharacter(int inNum) {
    player tmpPlayer;

    for (int i = 1; i <= inNum; i++) {
        tmpPlayer.name = "Enemy#" + std::to_string(i);
        tmpPlayer.life = randNum(50, 150);
        tmpPlayer.armor = randNum(0, 50);
        tmpPlayer.damage = randNum(15, 30);
        tmpPlayer.coordField.x = randNum(0, 20);
        tmpPlayer.coordField.y = randNum(0, 20);
        tmpPlayer.mark = 'E';
        field[tmpPlayer.coordField.y][tmpPlayer.coordField.x] = 'E';
        characters.push_back(tmpPlayer);
    }
}

// Запрос хода игрока
std::string requestMove() {
    std::string doMove = "";
    std::string variant[]{"L", "R", "U", "D"};
    bool valid = true;

    do {
        valid = true;
        doMove = inputText(L"Укажите направление хода игрока (\"L\", \"R\", \"U\", \"D\"): ");
        valid &= (std::find(begin(variant), end(variant), doMove) != end(variant)) ? true : false;

        if (!valid) {
            std::wcout << L"Укажите значение из указанных ранее!" << std::endl;
        }

    } while (!valid);

    return doMove;
}

// Ход персонажей (код хода)
bool executeMove(player &inPlayer, std::string &inToMove) {
    bool res = true;
    int opp;
    int x = inPlayer.coordField.x;
    int y = inPlayer.coordField.y;
    char markOpponent = (inPlayer.mark == 'P') ? 'E' : 'P';

    if (inToMove == "L" && (x - 1) >= 0) {

        if (field[y][x - 1] == '.') {
            inPlayer.coordField.x -= 1;
            field[y][x - 1] = inPlayer.mark;
            field[y][x] = '.';

        } else if (field[y][x - 1] == markOpponent) {
            opp = searchOpponent(x - 1, y);
            attackOpp(inPlayer, characters[opp]);

        } else {
            res = false;
        }

    } else if (inToMove == "R" && (x + 1) < 20) {

        if (field[y][x + 1] == '.') {
            inPlayer.coordField.x += 1;
            field[y][x + 1] = inPlayer.mark;
            field[y][x] = '.';

        } else if (field[y][x + 1] == markOpponent) {
            opp = searchOpponent(x + 1, y);
            attackOpp(inPlayer, characters[opp]);

        } else {
            res = false;
        }

    } else if (inToMove == "U" && (y - 1) < 20) {

        if (field[y - 1][x] == '.') {
            inPlayer.coordField.y -= 1;
            field[y - 1][x] = inPlayer.mark;
            field[y][x] = '.';

        } else if (field[y - 1][x] == markOpponent) {
            opp = searchOpponent(x, y - 1);
            attackOpp(inPlayer, characters[opp]);

        } else {
            res = false;
        }

    } else if (inToMove == "D" && (y + 1) >= 0) {

        if (field[y + 1][x] == '.') {
            inPlayer.coordField.y += 1;
            field[y + 1][x] = inPlayer.mark;
            field[y][x] = '.';

        } else if (field[y + 1][x] == markOpponent) {
            opp = searchOpponent(x, y + 1);
            attackOpp(inPlayer, characters[opp]);

        } else {
            res = false;
        }
    }

    return res;
}

// Ищем оппонента в заданной точке поля
int searchOpponent(int inX, int inY) {
    int res = 0;
    for (player tp: characters) {
        if (tp.coordField.x == inX && tp.coordField.y == inY) {
            return res;
        }
        res++;
    }
}

// Отработки атаки
void attackOpp(player &inHero, player &inOpp) {
    int att = inOpp.armor - inHero.damage;      // отрицательное значение att -> броня пробита

    std::wcout << L"\t" << convWStr.from_bytes(inHero.name) << L" атаковал  " << convWStr.from_bytes(inOpp.name)
               << std::endl;


    inOpp.armor = (att > 0) ? att : 0;
    att = (inOpp.armor > 0) ? 0 : att;
    inOpp.life += (att < 0) ? att : 0;
    inOpp.life = (inOpp.life > 0) ? inOpp.life : 0;

    if (inOpp.life == 0) {
        field[inOpp.coordField.y][inOpp.coordField.x] = '.';
    }

    system("pause");
}
