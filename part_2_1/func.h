#pragma once

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

// I really don't know what is common between these functions...
namespace fortyTwo {

    /*!
     * \brief Функция нахождения длины вектора строк.
     * \param v ссылка на вектор строк.
     * \return длину вектора строк.
     */
    size_t lenghtOfVectorString(const std::vector<std::string> &v)
    {
        size_t result(0);
        std::for_each(begin(v), end(v), [&result](const std::string& s){ result += s.size(); });

        return result;
    }

    /*!
     * \brief Функция для генерации последовательности квадратов чисел от 0 до n.
     * \param n длина поледовательности.
     * \return последовательность квадратов чисел от 1 до n.
     *         Возвращает по значению, используйте std::move().
     */
    std::vector<int> squaresOfRange(size_t n)
    {
        std::vector<int> result;
        result.reserve(n);

        int current(1);
        std::generate_n(std::back_inserter(result), n, [&current](){ return pow(current++, 2.0); });

        return result;
    }

    /*!
     * \brief Функция для нахождения числа без пары в отсортированной последовательности чисел.
     * \param v последовательность целых чисел. Состоит из пар чисел и одного числа без пары.
     * \return число без пары.
     */
    int findUnique(const std::vector<int>& v)
    {
        // I think, all standard algorithms (find(_if), unique, transform etc.) looks like ugly in this case.
        // If we have unsorted array, searching will take more time (about O(N^2) in worst case) and requires the another algorithm.
        auto f = v.begin();
        auto s = f + 1;

        while (f != v.end()) {
            if (*f == *s) {
                std::advance(f, 2);
                std::advance(s, 2);
                continue;
            } else {
                break;
            }
        }

        return *f;
    }


}
