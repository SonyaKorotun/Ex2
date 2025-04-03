#include <iostream>
#include "Str.h"

void Test(Str s) {} // Функция принимает объект Str, но ничего не делает

int main() {
    // Объявляем объект класса Str
    Str s = "123";

    // Вывод объекта на консоль
    std::cout << s << std::endl;

    // Вызываем функцию Test
    Test(s);

    // Повторяем вывод после вызова функции
    std::cout << s << std::endl;

    // Пробуем присваивание
    {
        Str t;
        t = s;

        // Повторяем вывод после присваивания
        std::cout << t << std::endl;
    }

    // Проверка оператора сложения
    s += "456";
    std::cout << s << std::endl;

    // Проверка цепочки присваиваний
    Str u = s = "789"; // changed to a valid Str constructor call
    std::cout << u << std::endl;

    return 0;
}