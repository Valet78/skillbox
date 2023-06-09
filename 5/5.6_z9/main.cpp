/*
Задание 5.6.9. Треугольник на координатной плоскости

Проверьте, образуют ли треугольник три данные точки на координатной плоскости. Каждая точка задается
двумя координатами. Таким образом, на вход программе даётся шесть чисел: координаты первой точки, 
затем координаты второй точки и координаты третьей точки. 
Программа должна ответить Yes, если три данные точки задают треугольник, или No.

Например, если хотя бы две из данных точек совпадают, то треугольника данные три точки не образуют.
Другой пример: точки с координатами (1; 2), (3; 6) и (-2; −4) не образуют треугольника, поскольку 
они лежат на одной прямой, хоть и не совпадают.

Подсказка: 
1.Три точки А, B и С будут лежать на одной прямой, если совпадают углы наклона прямых,
проведённых через любые две пары точек (например, совпадают прямые АВ и ВС).
2. Угол можно проверить с помощью формулы (a-x)/(b-y) = k, где a и b — координаты первой точки, 
а x и y — координаты второ, k - угловой коэффициент. Если угловые коэффициенты двух прямых равны -
то эти прямые параллельны.
Советы и рекомендации
Помните про особенности целочисленного деления. Эту задачу требуется решить в целых числах.
Что оценивается
Правильность определения углов прямых. Отсутствие ошибки целочисленного деления.
*/


#include <iostream>
using namespace std;

// Проверка ввода числа
float ValidInt (string inTxt){
  float result = 0;
  cout << inTxt;
  while(!(cin >> result)){    // Ввод с валидацией
    cin.clear();
    cin.ignore(123, '\n');    
    cout << "Программа ожидает ввода числа!" << endl;
    cout << inTxt; 
  }    
  return result;
}

int main() {
  cout << "Программа проверит возможность получения треугольника \nна плоскости по трём заданным точкам"
    << endl;
  cout << "Введите координаты первой точки" << endl;
  float point_x1 = ValidInt("\tx1 = ");
  float point_y1 = ValidInt("\ty1 = ");
  cout << "--------------------------------" << endl;
  cout << "Введите координаты второй точки" << endl;
  float point_x2 = ValidInt("\tx2 = ");
  float point_y2 = ValidInt("\ty2 = ");
  cout << "--------------------------------" << endl;
  cout << "Введите координаты третьей точки" << endl;
  float point_x3 = ValidInt("\tx3 = ");
  float point_y3 = ValidInt("\ty3 = ");
  cout << "--------------------------------" << endl;
  
  if (((point_y1 - point_y2) * (point_x3 - point_x2) != (point_x1 - point_x2) * (point_y3 - point_y2))
    && ((point_y2 - point_y3) * (point_x1 - point_x3) != (point_x2 - point_x3) * (point_y1 - point_y3))
    && ((point_y3 - point_y1) * (point_x2 - point_x1) != (point_x3 - point_x1) * (point_y2 - point_y1)))
    {
      cout << "Данные три точки задают треугольник." << endl;
    } else {
      cout << "Данные три точки не задают треугольник." << endl;  
    }
   
  return 0;
}