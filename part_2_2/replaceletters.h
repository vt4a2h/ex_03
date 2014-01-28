#pragma once

#include <string.h>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <stdio.h>

namespace replace_letters {

    using ReplacementDict = std::map<char, std::string>;
    using FrequencyDict   = std::map<char, size_t>;

    /*!
     * \brief Функция замены подстрок в строке.
     * \param text исходная строка.
     * \param from подстрока для замены.
     * \param to строка-замена.
     */
    inline void replace(std::string& text, const std::string& from, const std::string& to)
    {
        for (std::string::size_type index = text.find(from, 0);
             index != std::string::npos;
             index = text.find(from, index)) {

            text.replace(index, from.length(), to);
            index += to.length();
        }
    }

    /*!
     * \brief Функция подстрок в тексте.
     * \param text исходный текст.
     * \param dict словарь замен.
     * \param outText текст после замены.
     * \param srcDict частотный словарь символов в исходном тексте.
     * \param outDict частотный словарь символов в изменённом тексте.
     */
    void changeLetters(const std::string &text, const ReplacementDict &dict,
                       std::string &outText, FrequencyDict &srcDict, FrequencyDict &outDict)
    {
        for(auto &symbol : text) srcDict[symbol] += 1;

        outText.clear();
        outText.reserve(text.size());
        std::copy(begin(text), end(text), std::back_inserter(outText));
        outText.shrink_to_fit();

        for(auto &r      : dict   ) replace(outText, std::string(&r.first), r.second);
        for(auto &symbol : outText) outDict[symbol] += 1;
    }

}
