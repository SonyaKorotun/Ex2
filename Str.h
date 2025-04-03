#ifndef STR_H
#define STR_H

#include <iostream>
#include <cstring> // Для работы с функциями strcpy и strlen

class Str {
public:
    // Конструктор по умолчанию
    Str() : m_pszText(nullptr), m_nLength(0) {}

    // Конструктор копирования
    Str(const Str& other);

    // Деструктор
    ~Str();

    // Конструктор инициализации z-строкой
    Str(const char* pszText);

    // Оператор присваивания
    Str& operator=(const Str& rhs);

    // Оператор преобразования типа
    operator const char* () const { return m_pszText; }

    // Оператор сложения (+=)
    Str& operator+=(const char* sz);

    friend std::ostream& operator<<(std::ostream& os, const Str& str);  // Overload << operator

private:
    char* m_pszText;
    size_t m_nLength;
};

// Определение конструктора копирования вне класса
Str::Str(const Str& other) {
    if (other.m_pszText == nullptr) {
        m_pszText = nullptr;
        m_nLength = 0;
    }
    else {
        m_nLength = other.m_nLength;
        m_pszText = new char[m_nLength + 1];
        strcpy(m_pszText, other.m_pszText);
    }
}

// Определение деструктора вне класса
Str::~Str() {
    delete[] m_pszText;
}

// Определение конструктора инициализации z-строкой вне класса
Str::Str(const char* pszText) {
    if (pszText == nullptr) {
        m_pszText = nullptr;
        m_nLength = 0;
    }
    else {
        m_nLength = strlen(pszText);
        m_pszText = new char[m_nLength + 1];
        strcpy(m_pszText, pszText);
    }
}

// Определение оператора присваивания вне класса
Str& Str::operator=(const Str& rhs) {
    if (this != &rhs) {
        delete[] m_pszText;
        if (rhs.m_pszText == nullptr) {
            m_pszText = nullptr;
            m_nLength = 0;
        }
        else {
            m_nLength = rhs.m_nLength;
            m_pszText = new char[m_nLength + 1];
            strcpy(m_pszText, rhs.m_pszText);
        }
    }
    return *this;
}

// Определение оператора сложения (+=) вне класса
Str& Str::operator+=(const char* sz) {
    if (sz == nullptr || sz[0] == '\0') {
        return *this;
    }
    size_t lenSz = strlen(sz);
    size_t newLength = m_nLength + lenSz;

    char* newText = new char[newLength + 1];

    if (m_pszText != nullptr) {
        strcpy(newText, m_pszText);
        delete[] m_pszText; // Free existing memory
    }
    else {
        newText[0] = '\0'; // Initialize empty string
    }
    strcat(newText, sz);

    m_pszText = newText;
    m_nLength = newLength;

    return *this;
}

// Overload << operator
std::ostream& operator<<(std::ostream& os, const Str& str) {
    if (str.m_pszText != nullptr) {
        os << str.m_pszText;
    }
    return os;
}

#endif