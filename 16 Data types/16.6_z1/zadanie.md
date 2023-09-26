# Задание 16.6.1. Спидометр
`Что нужно сделать`
>Реализуйте цифровой спидометр автомобиля.<br>Сама модель автомобиля, которую нужно будет воссоздать, весьма проста.<br>Начальная скорость — 0 км/ч.<br>Пользователь вводит в стандартный ввод разницу (дельту) в скорости, и результирующая скорость показывается на спидометре в стандартный вывод.<br>Так происходит до той поры, пока машина снова не остановится, то есть пока скорость не станет меньше или равна нулю (сравнение должно происходить с дельтой в 0,01).<br>Диапазон возможных значений скорости машины от 0 до 150 км/ч.<br>Сам показатель спидометра вместе с единицами измерения требуется записывать в отдельную строку-буфер, которая потом и будет показываться на экране.<br>Точность отображения скорости — до 0,1 км/ч.

`Пример работы программы:`

```C++
Speed delta: 30

Speed: 30.0

Speed delta: 20.2

Speed: 50.2

Speed delta: 100

Speed: 150.0

Speed delta: -22.24

Speed: 127.8
```
`Рекомендации`

* Используйте цикл do … while для организации постоянного опроса пользователя.
* Для отображения числа с нужной точностью воспользуйтесь функцией `std::sprintf(speed_str, "%.1f", speed_value);`<br>где `speed_str` — строка, в которую функция `sprintf` «печатает» значение скорости (`speed_value`) с одним знаком после десятичной точки (`%.1f`). 