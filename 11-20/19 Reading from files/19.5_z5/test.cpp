#include <iostream>
#include <windows.h>
#include <string.h>
#include <fstream>
 
using namespace std;
 
int main()
{
    char line[256], tmp[256];
    char *buf = NULL;
    ifstream file;
    setlocale(LC_ALL, "ru_RU.utf8");
    // cout << "слово для поиска: ";
    // cin.get(word, 256, '\n');
    char word[] {'Q', 'u', 'u', 'e', 's', 't', 'i', 'o', 'n'};
    
    file.open("questions.txt", ios::in);
    if(!file)
          {
          cout<<"нет такого файла!!!!"<<endl;
                       exit(1);
 }
    while (!file.eof())
    {
        file.getline(line, 256, '\n');
        strcpy(tmp, line);
        buf = strtok(tmp, " ");
 
        if (buf == NULL)
        {
            cout << "Ошибка" << endl;
                       file.close();
                       system("pause");
            exit(1);
          }
        if (strcmp(buf, word) == 0)
        {
            cout << line <<" : найдено совпадение" << endl;
 
            system("pause");
            exit(0);
 
        }
 
    }
    cout << "нет подобных значений" << endl;
    file.close();
    system("pause");
    return 0;
}