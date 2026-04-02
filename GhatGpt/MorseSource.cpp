#include "MorseTranslator.h"
#include <cctype>

FMorseTranslator::FMorseTranslator()
{
    InitializeMap();
}

void FMorseTranslator::InitializeMap()
{
    MorseMap = {
        {'А', ".-"},   {'Б', "-..."}, {'В', ".--"},  {'Г', "--."},
        {'Д', "-.."},  {'Е', "."},    {'Ж', "...-"}, {'З', "--.."},
        {'И', ".."},   {'Й', ".---"}, {'К', "-.-"},  {'Л', ".-.."},
        {'М', "--"},   {'Н', "-."},   {'О', "---"},  {'П', ".--."},
        {'Р', ".-."},  {'С', "..."},  {'Т', "-"},    {'У', "..-"},
        {'Ф', "..-."}, {'Х', "...."}, {'Ц', "-.-."}, {'Ч', "---."},
        {'Ш', "----"}, {'Щ', "--.-"}, {'Ъ', ".--.-."},
        {'Ы', "-.--"}, {'Ь', "-..-"}, {'Э', "..-.."},
        {'Ю', "..--"}, {'Я', ".-.-"}
    };
}

bool FMorseTranslator::HasInvalidCharacters(const std::string& Text) const
{
    for (char Ch : Text)
    {
        if (Ch == ' ')
            continue;

        // Функция для преобразования русских букв в верхний регистр
        char UpperChar = Ch;
        // Русские буквы в Windows-1251: а-я = 224-255, А-Я = 192-223
        if (static_cast<unsigned char>(Ch) >= 224 && static_cast<unsigned char>(Ch) <= 255)
        {
            UpperChar = static_cast<char>(static_cast<unsigned char>(Ch) - 32);
        }

        if (MorseMap.find(UpperChar) == MorseMap.end())
        {
            return true; // Найден недопустимый символ
        }
    }
    return false;
}

std::string FMorseTranslator::TranslateToMorse(const std::string& Text) const
{
    std::string Result;
    bool lastWasSpace = false;

    for (char Ch : Text)
    {
        if (Ch == ' ')
        {
            if (!lastWasSpace)
            {
                Result += "   "; // разделитель слов
                lastWasSpace = true;
            }
            continue;
        }

        lastWasSpace = false;

        // Преобразуем русскую букву в верхний регистр
        char UpperChar = Ch;
        // Русские буквы в Windows-1251: а-я = 224-255, А-Я = 192-223
        if (static_cast<unsigned char>(Ch) >= 224 && static_cast<unsigned char>(Ch) <= 255)
        {
            UpperChar = static_cast<char>(static_cast<unsigned char>(Ch) - 32);
        }

        auto It = MorseMap.find(UpperChar);
        if (It != MorseMap.end())
        {
            Result += It->second + " ";
        }
    }

    // Удаляем лишний пробел в конце
    if (!Result.empty() && Result.back() == ' ')
    {
        Result.pop_back();
    }

    return Result;
}