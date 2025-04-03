#include <iostream>
#include "Complex.h"

int main() {
    // Задание 7: Объявление массива комплексных чисел
    Complex v[4]{ 1, 2, Complex(2, 3) };  // Массив из четырех элементов

    // Вывод массива в одну строку
    for (size_t i = 0; i < sizeof(v) / sizeof(v[0]); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    // Задание 8: Работа с динамическими блоками памяти
    // Объявление указателя на Complex
    Complex* pc;

    // Создание объекта Complex с помощью оператора new
    pc = new Complex(1, 2);

    // Вывод комплексного числа на консоль
    std::cout << *pc << std::endl;

    // Вывод мнимой и действительной части с использованием оператора ->
    std::cout << "Действительная часть: " << pc->Re << std::endl;
    std::cout << "Мнимая часть: " << pc->Im << std::endl;

    // Освобождаем память
    delete pc;

    // Создание массива комплексных чисел с помощью new
    pc = new Complex[3];

    // Присваивание значений элементам массива
    pc[0].Set(1, 2);
    pc[1].Set(3, 4);
    pc[2].Set(5, 6);

    // Вывод элементов массива
    for (size_t i = 0; i < 3; ++i) {
        std::cout << pc[i] << " ";
    }
    std::cout << std::endl;

    // Освобождаем память
    delete[] pc;

    return 0;
}