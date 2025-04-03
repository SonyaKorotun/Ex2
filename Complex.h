#pragma once
#include <iostream>
#include <cmath>

class Complex {
public:
    // Поля для хранения действительной и мнимой частей числа
    double Re = 0.0; // Действительная часть
    double Im = 0.0; // Мнимая часть

    // Конструктор с параметрами по умолчанию
    Complex(double re = 0.0, double im = 0.0) : Re(re), Im(im) {}

    // Инлайн-методы для работы с комплексными числами
    void Set(double re, double im) { Re = re; Im = im; }
    double GetRe() const { return Re; }
    double GetIm() const { return Im; }
    void Print() const { std::cout << Re << " + " << Im << "i\n"; }

    // Перегрузка оператора +
    Complex operator+(const Complex& c) const {
        return Complex(Re + c.Re, Im + c.Im);
    }

    // Перегрузка оператора -
    Complex operator-(const Complex& c) const {
        return Complex(Re - c.Re, Im - c.Im);
    }

    // Перегрузка оператора *
    Complex operator*(const Complex& c) const {
        return Complex(
            Re * c.Re - Im * c.Im,
            Re * c.Im + Im * c.Re
        );
    }

    // Перегрузка оператора /
    Complex operator/(const Complex& c) const {
        double denominator = c.Re * c.Re + c.Im * c.Im;
        return Complex(
            (Re * c.Re + Im * c.Im) / denominator,
            (Im * c.Re - Re * c.Im) / denominator
        );
    }

    // Метод для получения сопряжённого числа
    Complex Conjugate() const {
        return Complex(Re, -Im);
    }

    // Метод для вычисления модуля комплексного числа
    double Mod() const {
        return std::sqrt(Re * Re + Im * Im);  // Используется функция sqrt из cmath
    }

    // Метод для вычисления аргумента комплексного числа
    double Arg() const {
        return std::atan2(Im, Re);  // Uses atan2 to handle all quadrants correctly
    }

    // Перегрузка оператора вывода в поток
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.Re;
        if (c.Im >= 0) {
            os << " + " << c.Im << "i";
        }
        else {
            os << " - " << -c.Im << "i";
        }
        return os;
    }
};