// Задание 21.5.2. Модель данных для посёлка
#include "21.5-2.h"

int main() {
    setlocale(LC_ALL, "Russian");
    bool valid = true;

    std::wcout << L"* Программа \"Модель посёлка\" *" << std::endl;
    int askNumGround = askIntNum(L"Укажите количество участков в поселке: ");
    std::cout << std::endl;


    for (int ngr = 0; ngr < askNumGround; ngr++) {
        ground gr;
        std::wcout << L"  Заполните данные " << convWStr.from_bytes(std::to_string(ngr + 1)) << L" участка:"
                   << std::endl;
        gr.groundName = "ground_" + std::to_string(ngr + 1);
        gr.groundNum = askIntNum(L"\tУкажите номер участка в поселке (целое): ");
        gr.groundArea = askFloatNum(L"\tКакую площадь занимает участок (м.кв.): ");
        gr.buildsNum = askIntNum(L"\tУкажите количество строений на участке: ");
        std::cout << std::endl;

        for (int nbd = 0; nbd < gr.buildsNum; nbd++) {
            build bd;
            do {
                valid = true;
                std::wcout << L"   Заполним данные " << convWStr.from_bytes(std::to_string(nbd + 1))
                           << L" строения на участке:" << std::endl;
                bd.buildName = "build_" + std::to_string(nbd + 1);
                bd.buildArea = askFloatNum(L"\tКакую площадь занимает строение на участке (м.кв.): ");
                bd.buildType = askTypeBuild(L"\tК какому типу относится строение?");
                bd.floorHave = askIntNum(L"\tУкажите количество этажей строения: ");
                valid &= (bd.floorHave > 0 && bd.floorHave <= 3) ? true : false;
                bd.stove = askStove(L"\tУстановлена ли печь в здании (yes/no): ");
                bd.roomsHave = askIntNum(L"\tУкажите количество комнат в строении: ");
                valid &= (bd.roomsHave > 1 && bd.roomsHave <= (bd.floorHave * 4)) ? true : false;

                if (!valid) {
                    std::cout << std::endl;
                    std::wcerr << L"\tКоличество этажей в здании может быть в пределах 1 - 3, а" << std::endl;
                    std::wcerr << L"\tколичество комнат в рамках 2 - 4 комнаты на этаж!" << std::endl;
                    std::wcerr << L"\tЗаполните поля снова и будьте внимательны." << std::endl << std::endl;
                }

            } while (!valid);
            std::cout << std::endl;

            for (int nrm = 0; nrm < bd.roomsHave; nrm++) {
                room rm;
                do {
                    valid = true;
                    std::wcout << L"\tЗаполним данные " << convWStr.from_bytes(std::to_string(nrm + 1))
                               << L" комнаты:" << std::endl;
                    rm.roomName = "room_" + std::to_string(nrm + 1);
                    rm.roomArea = askFloatNum(L"\t\tКакую площадь занимает комната (м.кв.): ");
                    rm.roomToFloor = askIntNum(L"\t\tНа каком этаже располагается комната: ");
                    valid &= (rm.roomToFloor > 0 && rm.roomToFloor <= bd.floorHave) ? true : false;
                    rm.roomType = askTypeRoom(L"\t\tК какому типу относится комната?");
                    rm.roomHeight = askIntNum(L"\t\tУкажите высоту потолка в комнате (см): ");

                    if (!valid) {
                        std::cout << std::endl;
                        std::wcerr << L"\tВ здании" << convWStr.from_bytes(std::to_string(bd.floorHave))
                                   << L" этажей." << std::endl;
                        std::wcerr << L"\tУказанное Вами значение отлично от допустимого!" << std::endl;
                        std::wcerr << L"\tЗаполните поля снова и будьте внимательны." << std::endl << std::endl;
                    }

                } while (!valid);
                bd.summArea += rm.roomArea;     // находим общую площадь комнат в здании
                bd.roomsInBuild.push_back(rm);  // добавляем комнату в здание
            }

            gr.occupiedArea += bd.buildArea;
            gr.buildsInGround.push_back(bd);    // добавляем строение к участку
        }

        village.push_back(gr);  // добавляем участок к посёлку
    }
    printVillage();
    system("pause");
    return 0;
}

// *********************************

// Проверка валидности целых чисел
bool validDigit(std::string &inTxt) {
    bool res = true;

    for (char ch: inTxt) {
        res &= (ch >= '0' && ch <= '9') ? true : false;
    }

    return res;
}

// Проверка валидности чисел
bool validFloat(std::string &inTxt) {
    bool res = true;
    int num = 0;

    inTxt = (inTxt[0] == ',' || inTxt[0] == '.') ? '0' + inTxt : inTxt;

    for (int i = 0; i < inTxt.length(); i++) {

        if (inTxt[i] == ',' || inTxt[i] == '.') {
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

// запрос наличия печки в здании
bool askStove(std::wstring inTxt) {
    std::string resTxt = "";

    do {
        resTxt = inputText(inTxt);
    } while (!(resTxt == "yes" || resTxt == "no"));

    return (resTxt == "yes") ? true : false;
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

// Запрос целочисленного значения
int askIntNum(std::wstring inTxt) {
    bool valid = true;
    std::string numTxt = "";

    do {
        valid = true;
        numTxt = inputText(inTxt);
        if (!validDigit(numTxt)) {
            std::wcerr << L"Введённое значение не является целым числом! Попробуйте снова." << std::endl;
            valid = false;
        }

    } while (!valid);

    return std::stoi(numTxt);
}

// запрос площадей
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

// Запрос типа строения
std::string askTypeBuild(std::wstring inTxt) {
    std::string selType[]{"1", "2", "3", "4", "5", "6"};
    std::string type[]{"Residential building", "Garage", "Barn (cabin)", "Bathhouse",
                       "Household building (for livestock or poultry)", "Toilet"};
    std::string typeTxt = "";

    do {
        std::wcout << std::endl << inTxt << std::endl;
        std::wcout << L"\tУкажите из нижеперечисленных:" << std::endl;
        std::wcout << L"\t  1. Жилой дом." << std::endl;
        std::wcout << L"\t  2. Гараж." << std::endl;
        std::wcout << L"\t  3. Сарай (бытовка)." << std::endl;
        std::wcout << L"\t  4. Баня." << std::endl;
        std::wcout << L"\t  5. Хозпостройка (для скота или птицы)." << std::endl;
        std::wcout << L"\t  6. Уборная." << std::endl;
        std::cout << "\t---------------------------------------" << std::endl;
        std::wcout << L"\tВаш выбор: ";
        std::getline(std::cin, typeTxt);
        typeTxt = truncSpaces(typeTxt);

    } while (!(std::find(begin(selType), end(selType), typeTxt) != end(selType)));

    return type[std::stoi(typeTxt) - 1];
}

// Запрос типа комнаты
std::string askTypeRoom(std::wstring inTxt) {
    std::string selType[]{"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    std::string type[]{"Living room", "Hall", "Kitchen", "Bedroom", "Toilet is separate",
                       "Restroom", "Storage", "Dressing room", "Loggia"};
    std::string typeTxt = "";

    do {
        std::wcout << std::endl << inTxt << std::endl;
        std::wcout << L"\t\tУкажите из нижеперечисленных:" << std::endl;
        std::wcout << L"\t\t  1. Гостиная." << std::endl;
        std::wcout << L"\t\t  2. Холл." << std::endl;
        std::wcout << L"\t\t  3. Кухня." << std::endl;
        std::wcout << L"\t\t  4. Спальная комната." << std::endl;
        std::wcout << L"\t\t  5. Туалет отдельный." << std::endl;
        std::wcout << L"\t\t  6. Уборная." << std::endl;
        std::wcout << L"\t\t  7. Кладовка." << std::endl;
        std::wcout << L"\t\t  8. Гардеробная." << std::endl;
        std::wcout << L"\t\t  9. Лоджия." << std::endl;
        std::cout << "\t\t---------------------------------------" << std::endl;
        std::wcout << L"\t\tВаш выбор: ";
        std::getline(std::cin, typeTxt);
        typeTxt = truncSpaces(typeTxt);

    } while (!(std::find(begin(selType), end(selType), typeTxt) != end(selType)));

    return type[std::stoi(typeTxt) - 1];
}

// Вывод карточек участков
void printVillage() {
    std::wcout << std::endl << L"Наше поселение имеет следующие участки:" << std::endl;
    for (ground igr: village) {
        std::wcout << L"--------------- карточка участка \"" << convWStr.from_bytes(igr.groundName)
                   << L"\" ---------------" << std::endl;
        std::wcout << L"Номер участка:\t" << convWStr.from_bytes(std::to_string(igr.groundNum)) << std::endl;
        std::wcout << L"Площадь участка (м.кв.):\t" << convWStr.from_bytes(std::to_string(igr.groundArea)) << std::endl;
        std::wcout << L"Строений на участке:\t" << convWStr.from_bytes(std::to_string(igr.buildsNum)) << std::endl;
        std::wcout << L"Занимают площадь (м.кв.):\t" << convWStr.from_bytes(std::to_string(igr.occupiedArea))
                   << std::endl;
        std::cout << std::endl;

        for (build ibd: igr.buildsInGround) {
            std::wcout << L" * Строение \"" << convWStr.from_bytes(ibd.buildName) << L"\" * " << std::endl;
            std::wcout << L"   Занимает на участке (м.кв.):\t" << convWStr.from_bytes(std::to_string(ibd.buildArea))
                       << std::endl;
            std::wcout << L"   Тип строения:\t" << convWStr.from_bytes(ibd.buildType) << std::endl;
            std::wcout << L"   Этажность дома:\t" << convWStr.from_bytes(std::to_string(ibd.floorHave)) << std::endl;
            std::wcout << L"   Наличие печки:\t" << ((ibd.stove) ? L"да" : L"нет") << std::endl;
            std::wcout << L"   Количество комнат:\t" << convWStr.from_bytes(std::to_string(ibd.roomsHave)) << std::endl;
            std::wcout << L"   Площадь всех комнат (м.кв.):\t" << convWStr.from_bytes(std::to_string(ibd.summArea))
                       << std::endl;
            std::cout << std::endl;

            for (room irm: ibd.roomsInBuild) {
                std::wcout << L"   > Комната \"" << convWStr.from_bytes(irm.roomName) << L"\" * " << std::endl;
                std::wcout << L"     Площадь комнаты (м.кв.):\t" << convWStr.from_bytes(std::to_string(irm.roomArea))
                           << std::endl;
                std::wcout << L"     Тип комнаты:\t" << convWStr.from_bytes(irm.roomType) << std::endl;
                std::wcout << L"     Этаж:\t" << convWStr.from_bytes(std::to_string(irm.roomToFloor)) << std::endl;
                std::wcout << L"     Высота потолка (см):\t" << convWStr.from_bytes(std::to_string(irm.roomHeight))
                           << std::endl;
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
}