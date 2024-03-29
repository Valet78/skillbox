# Задание 12.5.2. Сортировка
## Что нужно сделать
```
Пользователь вводит в консоль 15 дробных чисел. Необходимо прочитать их и вывести в консоль в порядке от большего к меньшему. По возможности используйте минимум дополнительной памяти и проходов по массиву.
```

`Пример`
```
Ввод: 1.2 2.3 1.11 3.4 5.5 5.4 5.3 5.1 1.5 1.25 5.41 5.31 5.11 1.51 1.251 
Вывод: 5.5 5.41 5.4 5.31 5.3 5.11 5.1 3.4 2.3 1.51 1.5 1.251 1.25 1.2 1.11
```
`Рекомендации по выполнению`

Воспользуйтесь дополнительными материалами.

`Об алгоритмах:`

* <a href = "https://habr.com/ru/post/335920/"> 
  Описание алгоритмов сортировки и сравнение их производительности
  </a>
* <a href = "https://habr.com/ru/post/112222/"> 
  Структуры данных: двоичная куча (binary heap)
  </a>

`Подробнее о сложности и нотации большого O:`

* <a href = "https://tproger.ru/articles/computational-complexity-explained/"> 
  Оценка сложности алгоритмов, или Что такое О(log n) 
  </a>
* <a href = "https://skillbox.ru/media/code/big-o-notation-chto-eto-takoe-i-kak-eye-poschitat/"> 
  Big O Notation: что это такое и как её посчитать 
  </a>
* <a href = "https://youtu.be/EeP-KHoEHVg"> 
  Big O. Оценка сложности алгоритмов 
  </a>

`Об алгоритмах сортировок, у которых сложность меньше O(n^2).`

HeapSort имеет сложность n*log(n):

* <a href = "https://habr.com/ru/company/otus/blog/460087/">
  Пирамидальная сортировка (HeapSort)
  </a>
* <a href = "https://www.geeksforgeeks.org/heap-sort/"> 
  HeapSort
  </a>

MergeSort имеет сложность n*log(n):

* <a href = "https://habr.com/ru/post/335920/">
  Описание алгоритмов сортировки и сравнение их производительности
  </a>
* <a href = "https://www.geeksforgeeks.org/merge-sort/">
  MergeSort
  </a>

`Что оценивается`

* Используется массив чисел с плавающей точкой для хранения данных.
* В коде не используются библиотеки, кроме `<iostream>`.
* Программа корректно использует обращения по индексам и выдаёт правильный ответ.
* Асимптотическая сложность алгоритма не более O(n^2).
* Числа выводятся от большего к меньшему.