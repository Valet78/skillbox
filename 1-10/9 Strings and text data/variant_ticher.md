# Варианты решения задач от куратора

## Задача 1. Время в пути

### Задача

Поезд отправляется в AA часов BB минут и прибывает в пункт назначения в CC часов DD минут. Сколько часов и минут он находится в пути?

Напишите программу, которая принимает от пользователя две строки: время отправления и время прибытия поезда. Время задаёт строка из пяти символов в формате HH:MM. Обеспечьте контроль ввода и проверьте, что время корректно.

Программа должна ответить, сколько часов и минут поезд находится в пути. Если время отправления больше времени прибытия, считайте, что поезд прибывает в пункт назначения на следующий день.

### Решение

Для проверки формата используем цикл while(true), который прекращается, только если введено корректное время.

Затем часы переводим в минуты, чтобы упростить расчёт времени поездки. 

Это также позволяет учитывать прибытие поезда на следующие сутки, когда время прибытия будет стоять раньше времени отправления. Например, отправление в 09:40, а прибытие в 08:20.

```C++
#include <iostream>
#include <string>

int main() {
   std::string departure;
   std::string arrival;

   int departureHours;
   int departureMinutes;

   int arrivalHours;
   int arrivalMinutes;

   while(true) {
       std::cout << "Input departure and arrival time:\n";
       std::cin >> departure >> arrival;


       if(departure.length() != 5 || arrival.length() != 5) {
           std::cout << "Incorrect length try again!\n";
           continue;
       }

       if(arrival[0] < '0' || arrival[0] > '2' || arrival[1] < '0' || arrival[1] > '9'
       || departure[0] < '0' || departure[0] > '2' || departure[1] < '0' || departure[1] > '9') {
           std::cout << "Incorrect hour format!\n";
           continue;
       }

       if(arrival[3] < '0' || arrival[3] > '5' || arrival[4] < '0' || arrival[4] > '9'
          || departure[3] < '0' || departure[3] > '5' || departure[4] < '0' || departure[4] > '9') {
           std::cout << "Incorrect minute format!\n";
           continue;
       }

       if(arrival[2] != ':' || arrival[2] != ':') {
           std::cout << "Incorrect delimiter!\n";
           continue;
       }

       departureHours = (departure[0] - '0') * 10 + (departure[1] - '0');
       departureMinutes = (departure[3] - '0') * 10 + (departure[4] - '0');

       arrivalHours = (arrival[0] - '0') * 10 + (arrival[1] - '0');
       arrivalMinutes = (arrival[3] - '0') * 10 + (arrival[4] - '0');

       if(departureHours >= 24 || departureMinutes > 59
       || arrivalHours >= 24 || arrivalMinutes > 59) {
           std::cout << "Incorrect time!\n";
           continue;
       }

       break;
   }

   int departureTime = departureHours * 60 + departureMinutes;
   int arrivalTime = arrivalHours * 60 + arrivalMinutes;

   int travelTime = 0;
   if(departureTime >= arrivalTime)
       travelTime = 24*60 - departureTime + arrivalTime;
   else
       travelTime = arrivalTime - departureTime;

   std::cout << "The journey takes: " << travelTime/60 << ", minutes: " << travelTime%60 << std::endl;
}
```

## Задача 2. Длинное вещественное число

### Задача

Вы решили разработать программу-калькулятор, которая складывает числа любой длины. Для этого вы планируете работать с ними, как со строками. Первая проблема, с которой вы столкнулись, — нужно понять, является ли данная строка корректной записью вещественного числа или нет.

Корректной записью считается запись, которая удовлетворяет следующим условиям:

Первым символом должна быть либо цифра, либо знак минус.
После этого может идти ещё несколько цифр (возможно, ни одной).
Затем может идти точка, которая отделяет целую часть от дробной. До точки может и не быть цифр: в таком случае считается, что до точки стоит 0.
После точки идёт ещё несколько цифр (возможно, ни одной). В записи числа должна присутствовать хотя бы одна цифра. (Для простоты в этом задании мы не будем рассматривать числа в экспоненциальной записи, например 1.2e-3.)
Напишите программу, которая получает от пользователя строку и выводит ответ Yes, если корректно задаёт вещественное число. В противном случае строка должна выводить No.

### Решение
Сначала проверим первый символ в строке. Если это минус, то дальнейшие проверки строки можно начинать со второго символа. Далее в цикле подсчитываем количество чисел и точек, а также смотрим, что в строке нет других символов. В конце проверяем, что в строке все символы допустимы, а также есть минимум одна цифра и максимум одна точка.

```C++
#include <iostream>
#include <string>

int main() {
   std::string number;
   std::cin >> number;

   /* Если строка не пустая, а первый символ — минус */
   bool minus = number.length() > 0 && number[0] == '-';

   int dot_count = 0; /* Количество точек в числовой строке */
   int number_count = 0; /* Количество цифр в числовой строке */
   bool is_all_chars_correct = true; /* Числовая строка состоит только из допустимых символов */
   /* Цикл начинаем, учитывая минусовый символ в начале строки*/
   for(int i = minus ? 1 : 0; i < number.length(); ++i) {
       if(number[i] >= '0' && number[i] <= '9') {
           number_count++;
           continue; /* Если нашли число, остальную часть цикла пропускаем */
       }

       if(number[i] == '.') {
           dot_count++;
           continue; /* Если нашли точку, остальную часть цикла пропускаем */
       }
       /* Мы попадём в эту часть кода, только если символ number[i] — это не цифра и не символ точки*/
       is_all_chars_correct = false;
       break;
   }
   /* Проверяем, что все числа корректны, в строке есть хотя бы одно число и максимум одна точка */
   std::cout << (is_all_chars_correct && (number_count > 0) && (dot_count <= 1) ?
                   "Yes" :
                   "No"
               ) << '\n';
}
```

## Задача 3. Подсчёт количества слов

### Задача 

Напишите программу, которая считает количество слов в тексте, который вводит пользователь. Словом нужно считать любую последовательность символов (необязательно букв) без пробелов.

Пользователь вводит строку из произвольных символов и пробелов. Программа должна вывести одно число — количество слов во введённой строке.

### Решение

Проще всего обнаружить слово, сравнивая два символа, которые идут подряд. Если один из них пробел, а другой нет, значит, вы нашли слово. Решить эту задачу можно разными способами, но важно не выходить за пределы строки. Для этого мы будем сравнивать текущий символ с предыдущим. 

```C++
#include <iostream>
#include <string>

int main() {

   std::string str;
   std::getline(std::cin, str);

   int count = 0;

   if (str.length() > 0 && str[0] != ' ')
       count++;

   /* Пропускаем первый символ, так как в цикле проверяем символ, который идёт перед текущим */
   for (int i = 1; i < str.length(); ++i) {
       /* Если предыдущий символ равен пробелу, а текущий нет */
       if (str[i-1] == ' ' && str[i] != ' ')
           count++;
   }

   std::cout << count << '\n';
}
```

## Задача 4. «Быки и коровы»

### Задача

В логической игре «Быки и коровы» первый игрок загадывает четырёхзначное число (оно может начинаться с нулей), а второй игрок должен его отгадать. Отгадывание происходит так: второй игрок называет любое четырёхзначное число, а первый отвечает ему, сколько «быков» и «коров» в этом числе. Корова — это цифра, значение которой совпадает с цифрой задуманного числа, но стоит на другом месте. Бык — это цифра, которая совпадает с цифрой в задуманном числе и по значению, и по расположению.

Напишите программу, которая определяет число «быков» и «коров» по загаданному и по названному вторым игроком числу. Не забудьте, что числа могут начинаться с нулей!

### Решение

Существует два способа решения этой задачи.

В цикле проверить все символы, которые могут быть «быками». Если они не являются «быками», нужно в цикле проверить «коров»:

```C++
#include <iostream>
#include <string>


int main() {

   std::string first;
   std::string second;
   std::cin >> first >> second;

   bool ok = true;
   do {
       ok = first.length() == 4 && second.length() == 4;
       if (ok) {
           for (int i = 0; i < 4; ++i) {
               if (first[i] < '0' || first[i] > '9') ok = false;
               if (second[i] < '0' || second[i] > '9') ok = false;
           }
       }
       if (!ok) {
           std::cout << "Incorrect input! Try again!\n";
           std::cin >> first >> second;
       }
   } while (!ok);

   int bulls = 0;
   int cows = 0;
   for(int i = 0  ; i  < 4; i++) {
       if (second[i] == first[i]) {
           bulls++;
           first[i] = 'b';
           second[i] = 'b';
       }
   }

   for(int i = 0  ; i  < 4; i++) {
       for(int j = 0; j < 4; j++) {
           if (i != j && first[i] == second[j] && first[i] != 'b' && first[i] != 'c' ) {
               cows++;
               first[i] = 'c';
               second[j] = 'c';
           }
       }
   }

   std::cout << "Bulls: " << bulls << ", cows: " << cows << '\n';
}
```

Проверенные символы заменить на условные обозначения. Например, если число является «быком», его нужно заменить на символ ‘b’ (bull), а если «коровой» — на ‘c’ (cow):

```C++
#include <iostream>
#include <string>

int main() {
   std::string first;
   std::string second;
   std::cin >> first >> second;

   bool ok = true;
   do {
       ok = first.length() == 4 && second.length() == 4;
       if (ok) {
           for (int i = 0; i < 4; ++i) {
               if (first[i] < '0' || first[i] > '9') ok = false;
               if (second[i] < '0' || second[i] > '9') ok = false;
           }
       }
       if (!ok) {
           std::cout << "Incorrect input! Try again!\n";
           std::cin >> first >> second;
       }
   } while (!ok);


   int bulls = 0;
   int cows = 0;

   for (int i = 0; i < 4; i++) {
       if (first[i] == second[i]) {
           bulls++;
           first[i] = 'b'; /* «Быков» меняем на знак 'b' */
           second[i] = 'b'; /* «Быков» меняем на знак 'b' */
       }
   }

   for (int i = 0; i < 4; i++) {
       if(first[i] == 'b')
           continue;


       for (int j = 0; j < 4; j++)
       {
           if (i != j && first[i] == second[j])
           {
               cows++;
               first[i] = 'c'; /* «Коров» меняем на знак 'c' */
           }
       }
   }


   std::cout << "Bulls: " << bulls << ", cows: " << cows << '\n';
}
```

## Задача 5. Из обычных чисел — в римские

### Задача

Напишите программу, которая переводит данное пользователем число в римскую запись. Например, 19 представляется как XIX.

### Решение

Существует два способа решения этой задачи.

Разбить десятичное число на разряды: тысячи, сотни, десятки, единицы. Римские числа 4 и 9 пишутся в другом порядке, поэтому их обработку нужно вынести в отдельные условия.

```C++
#include <iostream>
#include <string>

int main() {

   int number;
   std::cin >> number;

   int thousands = number / 1000;
   int hundreds = number % 1000 / 100;
   int tens = number % 100 / 10;
   int units = number % 10;

   std::string result;
   for (int i = 0; i < thousands; ++i) {
       result += 'M';
   }

   if (hundreds == 4 || hundreds == 9) result += 'C';
   if (hundreds == 4) result += 'D';
   if (hundreds == 9) result += 'M';
   if (hundreds / 5 != 0) result += 'D';
   if (hundreds % 5 < 4) {
       for (int i = 0; i < hundreds % 5; ++i) {
           result += 'C';
       }
   }

   if (tens == 4 || tens == 9) result += 'X';
   if (tens == 4) result += 'L';
   if (tens == 9) result += 'C';
   if (tens / 5 != 0) result += 'L';
   if (tens % 5 < 4) {
       for (int i = 0; i < tens % 5; ++i) {
           result += 'X';
       }
   }

   if (units == 4 || units == 9) result += 'I';
   if (units == 4 ) result += 'V';
   if (units == 9) result += 'X';
   if (units / 5 != 0) result += 'V';
   if (units % 5 < 4) {
       for (int i = 0; i < units % 5; ++i) {
           result += 'I';
       }
   }

   std::cout << result << '\n';
}
```

Представить десятичное число как результат суммы римских цифр. Чтобы узнать, какие именно числа нужно сложить, необходимо отнять от исходного числа десятичный эквивалент римской цифры. Важно начать вычитание с самого большого римского числа, с тысячи (‘M’), и продолжать, пока исходное число не станет равным нулю.

```C++
#include <iostream>

int main() {
   int num;
   std::cout << "Insert the number: ";
   std::cin >> num;


   while (num <= 0 || num >= 4000) {
       std::cout << "Incorrect input!!!\n";
       std::cin >> num;
   }


   std::string result;
   while (num) {
       if (num >= 1000) {
           num -= 1000;
           result += 'M';
       }
       else if (num >= 900) {
           num -= 900;
           result += "CM";
       }
       else if (num >= 500) {
           num -= 500;
           result += 'D';
       }
       else if (num >= 400) {
           num -= 400;
           result += "CD";
       }
       else if (num >= 100) {
           num -= 100;
           result += 'C';
       }
       else if (num >= 90) {
           num -= 90;
           result += "XC";
       }
       else if (num >= 50) {
           num -= 50;
           result += 'L';
       }
       else if (num >= 40) {
           num -= 40;
           result += "XL";
       }
       else if (num >= 10) {
           num -= 10;
           result += 'X';
       }
       else if (num == 9) {
           num -= 9;
           result += "IX";
       }
       else if (num >= 5) {
           num -= 5;
           result += 'V';
       }
       else if (num == 4){
           num -= 4;
           result += "IV";
       }
       else {
           for (int i = 0; i < num; i++) {
               result += 'I';
           }
           num = 0;
       }
   }


   std::cout << result << std::endl;
}
```

