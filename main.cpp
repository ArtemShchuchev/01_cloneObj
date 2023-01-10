#include <iostream>
#include <vector>
#include <memory>

#include "SecondFunk/SecondaryFunction.h"

/*
Задача 1. Клонирование объекта класса
Описание
Бывает полезно быстро создать копию объекта, которая самостоятельно
управляет своей памятью. Если объект класса тяжёлый и имеет много данных
на стеке, то целесообразнее возвращать unique_ptr.

В этом задании нужно написать функцию clone для класса трёхдиагональной матрицы,
которая возвращает std::unique_ptr. Код класса трёхдиагональной матрицы ниже:
*/

class tridiagonal_matrix
{
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;
    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) :
        m_down{ down }, m_upper{ upper }, m_middle{ middle }
    {};
    ~tridiagonal_matrix() { std::cout << "destructor called\n"; }

    void printMatrix(std::string_view);

    std::unique_ptr<tridiagonal_matrix> clone();
};

int main()
{
    printHeader("Задача 1. Клонирование объекта класса");   // заголовок

    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
        );

    auto matrix_clone = matrix->clone();

    matrix->printMatrix("matrix");
    std::cout << "\n";
    matrix_clone->printMatrix("matrix_clone");
    std::cout << "\n";

    return 0;
}

// написал чтоб самому было нагляднее понять
void tridiagonal_matrix::printMatrix(std::string_view str)
{
    std::cout << str << ":\n";

    std::cout << "m_down: ";
    for (const auto& elem : m_down) std::cout << elem << " ";
    std::cout << "\n";

    std::cout << "m_upper: ";
    for (const auto& elem : m_upper) std::cout << elem << " ";
    std::cout << "\n";

    std::cout << "m_middle: ";
    for (const auto& elem : m_middle) std::cout << elem << " ";
    std::cout << "\n";
}

// супер код из одной строчки ))
// вот так правильней
std::unique_ptr<tridiagonal_matrix> tridiagonal_matrix::clone()
{
    return std::make_unique<tridiagonal_matrix>
        (this->m_down, this->m_upper, this->m_middle);
}
