#include "replaceletters.h"

#include <iostream>

template<class Dict>
void printDict(const Dict &dict, const std::string &sep = " ") {
    for(auto &pair : dict) std::cout << &pair.first << sep << pair.second << std::endl;
}

int main()
{
    std::string text("foobarbaz");
    replace_letters::ReplacementDict dict {{'o', "ay"}, {'f', "x"}, {'b', ""}};

    std::string output;
    replace_letters::FrequencyDict fdText, fdOutput;

    replace_letters::changeLetters(text, dict, output, fdText, fdOutput);

    std::cout << "Текст: \n" << text << "\n\nСловарь:" << std::endl;
    printDict(dict, " -> ");
    std::cout << "\nЧастотный словарь исходного текста: " << std::endl;
    printDict(fdText, " - ");

    std::cout << "\nТекст с заменами: \n" << output << std::endl;
    std::cout << "\nЧастотный словарь текста с заменами текста: " << std::endl;
    printDict(fdOutput, " - ");

    return 0;
}
