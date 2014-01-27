#include "func.h"

#include <iostream>

int main()
{
    // 1. Функция принимает на вход вектор строк и возвращает их сумарную длину.
    std::vector<std::string> v_1 = {"foo", "bar", "baz"};
    std::cout << fortyTwo::lenghtOfVectorString(v_1) << std::endl;

    // 2. Функция находит одно не повторяющееся число в диапазоне.
    std::vector<int> v_2 = {40, 10, 20, 10, 40, 20, 42};
    std::sort(begin(v_2), end(v_2));
    std::cout << fortyTwo::findUnique(v_2) << std::endl;

    // 3. Функция возвращает ряд квадратов числе от 1 до N.
    const int N = 10;
    std::vector<int> v_3(std::move(fortyTwo::squaresOfRange(N)));
    std::copy(begin(v_3), end(v_3), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
