#include <iostream>
#include "utils.h"  // Включаем заголовочный файл с функцией Swap

int main() {
    int a = 3, b = 5;

    // Вывод значений до обмена
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;

    // Вызов функции Swap с передачей указателей
    Swap(&a, &b);

    // Вывод значений после обмена
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    return 0;
}
