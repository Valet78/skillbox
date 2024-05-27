// Задание 21.5.3. Математический вектор
#include "21.5-3.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::string askAction = "";
    std::cout << std::fixed << std::setprecision(2);
    std::wcout << std::fixed << std::setprecision(2);

    do {
        askAction = selectAction();
        float tmpFloat = 0.0f;
        coord vecA, vecB, vecC;

        if (askAction == "add") {
            std::wcout << L"Вы выбрали сложение двух векторов." << std::endl;
            vecA = askCoordinate(L"Ведите значения координат первого вектора: ");
            vecB = askCoordinate(L"Ведите значения координат второго вектора: ");
            vecC = sumVector(vecA, vecB);

            std::wcout << L"Результат сложения двух векторов: (" << vecC.x << L", " << vecC.y << L", "
                       << vecC.z << L")" << std::endl;

        } else if (askAction == "subtract") {
            std::wcout << L"Вы выбрали вычитание двух векторов." << std::endl;
            vecA = askCoordinate(L"Ведите значения координат первого вектора: ");
            vecB = askCoordinate(L"Ведите значения координат второго вектора: ");
            vecC = subtractVector(vecA, vecB);

            std::wcout << L"Результат вычитания двух векторов: (" << vecC.x << L", " << vecC.y << L", "
                       << vecC.z << L")" << std::endl;

        } else if (askAction == "scale") {
            std::wcout << L"Вы выбрали произведение вектора на скаляр." << std::endl;
            vecA = askCoordinate(L"Ведите значения координат вектора: ");
            tmpFloat = askFloatNum(L"Введите величину скаляра: ");
            vecC = scaleVector(vecA, tmpFloat);

            std::wcout << L"Результат произведения вектора на скаляр: (" << vecC.x << L", " << vecC.y << L", "
                       << vecC.z << L")" << std::endl;

        } else if (askAction == "length") {
            std::wcout << L"Нахождение длины вектора." << std::endl;
            vecA = askCoordinate(L"Ведите значения координат вектора: ");
            tmpFloat = lengthVector(vecA);

            std::wcout << L"Длина вектора (" << vecA.x << L", " << vecA.y << L", "
                       << vecA.z << L") равна " << tmpFloat << std::endl;

        } else if (askAction == "normalize") {
            std::wcout << L"Нормализация вектора." << std::endl;
            vecA = askCoordinate(L"Ведите значения координат вектора: ");
            tmpFloat = lengthVector(vecA);
            vecC = normVector(vecA, tmpFloat);
            std::cout << "len = " << tmpFloat << std::endl;
            std::wcout << L"Нормализованный вектор: (" << vecC.x << L", " << vecC.y << L", "
                       << vecC.z << L")" << std::endl;

        } else if (askAction == "exit") {
            std::wcout << L"Программа будет закрыта. До новых встреч." << std::endl;
        }

        system("pause");

    } while (askAction != "exit");


//    system("pause");
    return 0;
}

// ******************************

// Проверка валидности чисел
bool validFloat(std::string &inTxt) {
    bool res = true;
    int num = 0;

    inTxt = (inTxt[0] == ',' || inTxt[0] == '.') ? '0' + inTxt : inTxt;

    for (int i = 0; i < inTxt.length(); i++) {

        if (i == 0 && inTxt[i] == '-') {
            res &= true;
            continue;
        } else if (inTxt[i] == ',' || inTxt[i] == '.') {
            inTxt[i] = ',';
            num++;
            res &= true;
            continue;
        }
        res &= (inTxt[i] >= '0' && inTxt[i] <= '9') ? true : false;
    }

    res &= (num > 1) ? false : true;

    return res;
}

// Отсечение пробелов в строке с двух сторон
std::string truncSpaces(std::string &inTxt) {
    inTxt = std::regex_replace(inTxt, std::regex("^\\s+"), "");
    inTxt = std::regex_replace(inTxt, std::regex("\\s+$"), "");
    return inTxt;
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

    return resTxt;
}

// запрос координат точки
float askFloatNum(std::wstring inTxt) {
    bool valid = true;
    std::string numTxt = "";

    do {
        valid = true;
        numTxt = inputText(inTxt);
        if (!validFloat(numTxt)) {
            std::wcerr << L"Введённое значение не является вещественным числом! Попробуйте снова." << std::endl;
            valid = false;
        }
    } while (!valid);

    return std::stof(numTxt);
}

// Запрос координат вектора
coord askCoordinate(std::wstring inTxt) {
    std::wcout << inTxt << std::endl;
    float resX = askFloatNum(L"X = ");
    float resY = askFloatNum(L"Y = ");
    float resZ = askFloatNum(L"Z = ");

    return {resX, resY, resZ};
}

// Меню выбора
std::string selectAction() {
    std::string resTxt = "";
    std::string valTxtList[]{"add", "subtract", "scale", "length", "normalize", "exit"};
    bool valid = true;

    do {
        system("cls");
        std::wcout << L"* Программа \"Математический вектор\" *" << std::endl;
        std::wcout << L"Выберите действие из нижеперечисленных:" << std::endl;
        std::wcout << L" \"add\"\t - сложение двух векторов;" << std::endl;
        std::wcout << L" \"subtract\"\t - вычитание двух векторов;" << std::endl;
        std::wcout << L" \"scale\"\t - умножение вектора на скаляр;" << std::endl;
        std::wcout << L" \"length\"\t - нахождение длины вектора;" << std::endl;
        std::wcout << L" \"normalize\"\t - нормализация вектора;" << std::endl;
        std::wcout << L" \"exit\"\t - выход из программы." << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
        resTxt = inputText(L"Ваш выбор: ");

        valid = (std::find(begin(valTxtList), end(valTxtList), resTxt) != end(valTxtList)) ? true : false;
        if (!valid) {
            std::wcout << L"Введите значения из указанных выше!" << std::endl;
            system("pause");
        }

    } while (!valid);


    return resTxt;
}

// Сумма двух векторов
coord sumVector(coord &inVecA, coord &inVecB) {
    return {inVecA.x + inVecB.x, inVecA.y + inVecB.y, inVecA.z + inVecB.z};
}

// Разность двух векторов
coord subtractVector(coord &inVecA, coord &inVecB) {
    return {inVecA.x - inVecB.x, inVecA.y - inVecB.y, inVecA.z - inVecB.z};
}

// Произведение вектора на скаляр
coord scaleVector(coord &inVecA, float &inScal) {
    return {inVecA.x * inScal, inVecA.y * inScal, inVecA.z * inScal};
}

// Вычисление длины вектора
float lengthVector(coord &inVecA) {
    return sqrt(pow(inVecA.x, 2) + pow(inVecA.y, 2) + pow(inVecA.z, 2));
}

// Нормализация вектора
coord normVector(coord &inVacA, float &inLength) {
    return {inVacA.x / inLength, inVacA.y / inLength, inVacA.z / inLength};
}