#pragma once

#include <string>
#include <unordered_map>

class FMorseTranslator
{
public:
    FMorseTranslator();

    std::string TranslateToMorse(const std::string& Text) const;
    bool HasInvalidCharacters(const std::string& Text) const;

private:
    std::unordered_map<char, std::string> MorseMap;

    void InitializeMap();
};