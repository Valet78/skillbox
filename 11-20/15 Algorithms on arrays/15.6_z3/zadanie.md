# Задача 15.6.3
`Что нужно сделать`
>С клавиатуры вводятся числа. <br> Когда пользователь вводит «-1»,  необходимо выводить на экран пятое по возрастанию число среди введённых. <br> Когда пользователь вводит «-2», программа завершает работу.

`Пример:`
```C++
ввод: 7 5 3 1 2 4 6 -1
вывод: 5 // в отсортированном виде массив выглядит так: {1,2,3,4,5,6,7}
ввод: 1 1 1 -1
вывод: 2 // в отсортированном виде массив выглядит так: {1,1,1,1,2,3,4,5,6,7}
ввод -2
// завершение программы
```
`Советы и рекомендации`

Нужно удостовериться, что можно вывести требуемое число (может быть меньше пяти чисел).

`Критерии оценки`
* В циклах нет выхода за границы массивов.
* Вывод ошибок должен производиться в поток вывода ошибок std::cerr.
* Действия должны быть вынесены в функции.
* Программы запускаются и корректно работают, нет синтаксических ошибок.
* Имена переменных корректные, отражают суть хранимых данных.
* Создан текстовый интерфейс для всех программ.
* Для всех задач обеспечен контроль ввода.
* Использован оптимальный алгоритм поиска или сортировки.
* Выполнены все четыре задания.