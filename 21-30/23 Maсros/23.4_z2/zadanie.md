# Задание 23.4.2. Вывод времени года

`Что нужно сделать`

> Используя макросы вместе с условными директивами прекомпиляции (`#if / #endif`), <br>
> реализуйте простую программу по выводу названия времени года в консоль.
>
> Пользователь программы, который будет иметь дело с вашим кодом, в этом случае  <br>
> тоже программист. С помощью определения одного из макросов (в самом коде):  <br>
> SPRING, SUMMER, AUTUMN или WINTER он задаёт сезон, название, которое хочет увидеть  <br>
> на экране. При компиляции и запуске программы на экране должно появиться название  <br>
> именно этого сезона и только его.

`Советы и рекомендации`

* Так как препроцессор работает до компиляции, то в `#if/#endif`-директивы вы можете  <br>
  обернуть всю функцию main сразу.

`Что оценивается`

* Корректность работы программы при разных заданных дефинициях макросов.
