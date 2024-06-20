// Задание 21.5.4. Пошаговая ролевая игра (дополнительная задача)
#include "21.5-4.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::srand(std::time(nullptr));

    bool itWin = false, resMove = true;
    int kodMove = 0;
    std::string askDoMove = "";
    inicMassiv();

    std::wcout << L"   * Пошаговая ролевая игра *" << std::endl << std::endl;

    if (!askLoadGame(L"Желаете ли вы загрузить ранее сохранённую игру (yes/no)?: ")) {
        std::wcout << L"Вследствие ошибки игра будет завершена." << std::endl;
        system("pause");
        return -1;
    }

    printField();

    do {
        resMove = true;
        itWin = false;

        // Ход игрока
        askDoMove = requestMove();

        if (askDoMove == "LOAD") {
            std::string comm = "";

            do {
                comm = inputText(L"Вы уверены, что хотите загрузить данные предыдущей игры (\"yes\" или \"no\")?");
                comm = truncSpaces(comm);

                if (!(comm == "yes" || comm == "no")) {
                    std::wcout << L"Укажите \"yes\" или \"no\"!" << std::endl;
                }

            } while (!(comm == "yes" || comm == "no"));

            if (comm == "yes") {
                int resLoad = loadDataFromFile();

                if (resLoad == -1) {
                    std::wcout << L"Вследствие ошибки игра будет завершена." << std::endl;
                    system("pause");
                    return -1;

                } else if (resLoad == 0) {
                    std::wcout << L"Игра будет продолжена." << std::endl;
                    system("pause");

                } else {
                    resMove = true;
                    itWin = false;

                    std::wcout << L"Загрузка данных прошла успешно.Продолжаем предыдущую игру." << std::endl;
                    system("pause");
                    printField();

                    // Ход игрока
                    askDoMove = requestMove();
                }
            }

        } else if (askDoMove == "SAVE") {
            if (saveDataToFile()) {
                std::wcout << L"Данные успешно сохранены в файл." << std::endl;
                system("pause");
            } else {
                return false;
            }

        } else if (askDoMove == "EXIT") {
            std::wcout << L"Уже уходите? Надеемся увидеть Вас снова. Всего доброго." << std::endl;
            system("pause");
            return 0;
        }

        resMove &= executeMove(characters[0], askDoMove);

        if (resMove) {
            int pe = 1;

            // Ход врагов
            do {
                resMove = true;
                kodMove = randNum(1, 100) % 4;

                switch (kodMove) {
                    case 0:
                        askDoMove = "U";
                        break;
                    case 1:
                        askDoMove = "R";
                        break;
                    case 2:
                        askDoMove = "D";
                        break;
                    case 3:
                        askDoMove = "L";
                        break;
                }

                resMove &= executeMove(characters[pe], askDoMove);
                pe += (resMove) ? 1 : 0;

            } while (pe < characters.size());

            // Определяем победителя
            if (characters[0].life == 0) {
                itWin = true;
                std::wcout << L"Ваш игрок проиграл в этой игре! Враги одолели его." << std::endl;
                system("pause");

            } else {
                int numVin = 0;

                for (int i = 1; i < characters.size(); i++) {
                    numVin += (characters[i].life > 0) ? 1 : 0;
                }

                if (numVin == 0) {
                    itWin = true;
                    std::wcout << L"Поздравляем, Ваш игрок выиграл эту битву!" << std::endl;
                    system("pause");
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
    int sizeChar = characters.size();

    for (int i = 0; i < 20; i++) {              // y
        for (int k = 0; k < 20; k++) {          // x
            std::wcout << convWStr.from_bytes(field[i][k]) << L"  ";
        }

        if (i < sizeChar) {
            std::wcout << L"\tИгрок: " << convWStr.from_bytes(characters[i].name) << L". Уровень жизни: "
                       << characters[i].life << L", брони: " << characters[i].armor << std::endl;
        } else if (i == sizeChar + 1) {
            std::wcout << L"\tPS: Используйте следующие значения:" << std::endl;

        } else if (i == sizeChar + 2) {
            std::wcout << L"\t    \"L\" - движение влево, \"R\" - движение вправо," << std::endl;

        } else if (i == sizeChar + 3) {
            std::wcout << L"\t    \"U\" - движение вверх, \"D\" - движение вниз," << std::endl;

        } else if (i == sizeChar + 4) {
            std::wcout << L"\t    \"SAVE\" - для сохранения, \"LOAD\" - для загрузки," << std::endl;

        } else if (i == sizeChar + 5) {
            std::wcout << L"\t    \"EXIT\" - выход из игры (не забудьте сохраниться)." << std::endl;

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
    std::string variant[]{"L", "R", "U", "D", "LOAD", "SAVE", "EXIT"};
    bool valid = true;

    do {
        valid = true;
        doMove = inputText(L"Укажите направление хода игрока: ");
        valid &= (std::find(begin(variant), end(variant), doMove) != end(variant)) ? true : false;

        if (!valid) {
            std::wcout << L"Укажите значение из указанных ранее!" << std::endl;
        }

    } while (!valid);

    return doMove;
}

// Ход персонажей (код хода)
bool executeMove(player &inPlayer, std::string &inToMove) {
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
            return false;
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
            return false;
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
            return false;
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
            return false;
        }

    } else {
        return false;
    }

    return true;
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

// Запись в файл данных вектора
bool saveDataToFile() {
    std::ofstream file;

    file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    try {
        file.open(fileDataName, std::ios::out | std::ios::binary | std::ios::trunc);

        for (player &e: characters) {
            size_t nameSize = e.name.length();
            file.write(reinterpret_cast<const char *> (&nameSize), sizeof nameSize);
            file.write(e.name.data(), nameSize);
            file.write(reinterpret_cast<const char *> (&e.life), sizeof e.life);
            file.write(reinterpret_cast<const char *> (&e.armor), sizeof e.armor);
            file.write(reinterpret_cast<const char *> (&e.damage), sizeof e.damage);
            file.write((const char *) (&e.mark), sizeof e.mark);
            file.write(reinterpret_cast<const char *> (&e.coordField.x), sizeof e.coordField.x);
            file.write(reinterpret_cast<const char *> (&e.coordField.y), sizeof e.coordField.y);
        }

        file.close();

    } catch (const std::ofstream::failure &e) {
        file.close();
        std::wcout << L"Не удалось создать/записать файл! Программа будет закрыта." << std::endl;
        return false;
    }

    return true;
}

// Загружаем данные из файла с данными
int loadDataFromFile() {
    std::ifstream file;


    if (std::filesystem::exists(fileDataName)) {
        characters.clear();

        file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
        try {
            file.open(fileDataName, std::ios::in | std::ios::binary);

//            while ((char) file.peek() != '\r') {
            for (int k = 0; k < 6; k++) {

                player inPl;
                size_t nameSize(0);
                file.read(reinterpret_cast<char *> (&nameSize), sizeof nameSize);
                char *tmp = new char[nameSize + 1];
                file.read(tmp, nameSize);
                tmp[nameSize] = '\0';
                inPl.name = tmp;
                delete[] tmp;
                file.read(reinterpret_cast<char *> (&inPl.life), sizeof inPl.life);
                file.read(reinterpret_cast<char *> (&inPl.armor), sizeof inPl.armor);
                file.read(reinterpret_cast<char *> (&inPl.damage), sizeof inPl.damage);
                file.read((char *) (&inPl.mark), sizeof inPl.mark);
                file.read(reinterpret_cast<char *> (&inPl.coordField.x), sizeof inPl.coordField.x);
                file.read(reinterpret_cast<char *> (&inPl.coordField.y), sizeof inPl.coordField.y);
                field[inPl.coordField.y][inPl.coordField.x] = inPl.mark;
                characters.push_back(inPl);
            }
            file.close();

        } catch (const std::ifstream::failure &e) {
            file.close();
            std::wcout << L"Ошибка чтения данных из файла! Программа будет закрыта." << std::endl;
            std::cout << "code = " << e.what() << " - " << e.code() << std::endl;
            return -1;
        }

    } else {
        std::wcout << L"Видимо ранее игра не сохранялась!" << std::endl;
        return 0;
    }

    return 1;
}

// Запрос на загрузку ранее сохранённой игры
bool askLoadGame(std::wstring inWTxt) {
    std::string comm = "";

    do {
        comm = inputText(inWTxt);
        comm = truncSpaces(comm);

        if (!(comm == "yes" || comm == "no")) {
            std::wcout << L"Укажите \"yes\" или \"no\"!" << std::endl;
        }

    } while (!(comm == "yes" || comm == "no"));

    if (comm == "yes") {
        int resLoad = loadDataFromFile();

        if (resLoad == -1) {
            system("pause");
            return false;
        } else if (resLoad == 0) {
            system("pause");
        } else {
            std::wcout << L"Загрузка данных прошла успешно.Продолжаем предыдущую игру." << std::endl;
            system("pause");
        }

    } else {
        std::wcout << L"Для начала игры создадим игроков, одного пользовательского и несколько противников."
                   << std::endl;
        createPlayer();                 // пользовательский игрок
        createCharacter(5);      // 5 игроков врага
    }

    return true;
}


