#include <iostream>
#include <string>
#include "MorseTranslator.h"
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FMorseTranslator Translator;
    std::string InputText;
    bool isValid = false;

    std::cout << "Внимание: разрешены только РУССКИЕ буквы и пробелы!\n";
    std::cout << "Английские буквы и цифры ЗАПРЕЩЕНЫ!\n\n";

    while (!isValid)
    {
        std::cout << "Введите текст: ";
        std::getline(std::cin, InputText);

        if (InputText.empty())
        {
            std::cout << "ОШИБКА: Введите текст!\n\n";
            continue;
        }

        if (Translator.HasInvalidCharacters(InputText))
        {
            std::cout << "ОШИБКА: Обнаружены недопустимые символы!\n";
            std::cout << "Используйте только РУССКИЕ буквы и пробелы.\n";
            std::cout << "Английские буквы и цифры запрещены.\n";
            std::cout << "Попробуйте снова.\n\n";
        }
        else
        {
            isValid = true;
        }
    }

    std::string Morse = Translator.TranslateToMorse(InputText);

    std::cout << "\nАзбука Морзе:\n" << Morse << std::endl;

    return 0;
}