# Задача 13.6.1
>Что нужно сделать
>
>Необходимо из заданного пользователем вектора удалить число X.
>
`Как работает программа`

>Пользователь вводит с клавиатуры число n — размер вектора, который надо заполнять.
>Пользователь вводит n целых чисел, которые заполняют вектор.
>Пользователь вводит значение — X. X — удаляемое из вектора значение. Необходимо удалить из вектора все элементы, которые равны >заданному значению.
>В конце программы необходимо вывести итоговое состояние вектора.

`Пример выполнения`
```C++
Input vector size: 5 
Input numbers: 1 3 3 5 1 
Input number to delete: 3 
Result: 1 5 1
```
`Пояснение`

Пользователь ввёл 5, потом числа 1, 3, 3, 5, 1 и потом число 3. 
В векторе должны остаться числа 1, 5, 1, которые надо вывести на экран.

`Что оценивается`
* Не удалено лишних элементов.
* Все элементы, которые необходимо удалить, удалены.
* Для удаления элементов из вектора использована функция `pop_back()`
* Удаления из вектора совершены `in-place`, т.е. при удалении из вектора не используются дополнительные структуры данных или переменные.
* Решение использует только один вектор.