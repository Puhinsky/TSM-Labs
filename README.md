# Выполнение лабораторных работ по дисциплине "Теория Автоматов"
1. Минимизация СДНФ методом Квайна-Мак-Класки (Quine-McCluskey Optimization Executor Legacy).
2. Выполнение структурного синтеза конечного автомата (по варианту – Мили) (Melee Struct Synthesis Executor Legacy).
3. Минимизация конечного автомата Мили алгоритмом Пола-Ангера (Paull-Unger Minimization Executor Legacy).
4. Вычисление арифметического выражения с использованием одностековой целочисленной вычислительной машины (Polish Inverse Notation Executor Legacy).

### Getting Started:
Стандарт языка C++: **"ISO C++ 14"**. \
Структура решения предполагает разделение кода на проект библиотеки (**Library**) и вызываемого проекта (**Executor**) для каждой работы. Library имеет зависимости на другие библиотеки при необходимости и содержит уникальный функционал, Executor зависим от соотвествующей Library и является точкой входа (main.cpp). \
Для запуска лабораторной работы нужно назначить соответсвующий Executor как запускаемый проект для решения: **ПКМ по проекту->"Назначить в качестве запускаемого проекта"**. Также может потребоваться изменить пункт **"Версия пакета SDK для Windows"** в свойствах каждого проекта при использовании более старой версии Visual Studio.