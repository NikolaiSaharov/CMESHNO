#include <iostream> 
#include <string> 
#include <algorithm> 
#include <random> 
#include <locale> 
#include <Windows.h>

using namespace std;

// Функция для переворачивания строки 
wstring reverse(wstring word) {
    reverse(word.begin(), word.end());
    return word;
}

// Функция для удаления гласных букв из строки 
wstring removeVowels(wstring word) {
    wstring vowels = L"аеёиоуыэюяАЕЁИОУЫЭЮЯaeiouyAEIOUY";
    wstring result;
    for (wchar_t c : word) {
        if (vowels.find(c) == wstring::npos) {
            result += c;
        }
    }
    return result;
}

// Функция для удаления согласных букв из строки 
wstring removeConsonants(wstring word) {
    wstring consonants = L"бвгджзйклмнпрстфхцчшщБВГДЖЗЙКЛМНПРСТФХЦЧШЩbcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    wstring result;
    for (wchar_t c : word) {
        if (consonants.find(c) != wstring::npos) {
            result += c;
        }
    }
    return result;
}

// Функция для перемешивания букв в строке 
wstring shuffle(wstring word) {
    random_device rd;
    mt19937 g(rd());
    shuffle(word.begin(), word.end(), g);
    return word;
}

int main() {
    // Устанавливаем локаль для поддержки русского языка в консоли 
   //  SetConsoleCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Rus");

    wstring word;
    int choice;

    wcout << L"Введите слово: ";
    getline(wcin, word);

    // Выводим меню 
    wcout << L"Выберите действие:\n";
    wcout << L"1. Перевернуть слово\n";
    wcout << L"2. Удалить гласные буквы\n";
    wcout << L"3. Удалить согласные буквы\n";
    wcout << L"4. Перемешать буквы в слове\n";
    wcin >> choice;
    wcin.ignore(); // Очищаем буфер ввода после ввода числа 

    // Выполняем выбранное действие 
    switch (choice) {
    case 1:
        wcout << L"Перевернутое слово: " << reverse(word) << endl;
        break;
    case 2:
        wcout << L"Слово без гласных: " << removeVowels(word) << endl;
        break;
    case 3:
        wcout << L"Слово без согласных: " << removeConsonants(word) << endl;
        break;
    case 4:
        wcout << L"Перемешанное слово: " << shuffle(word) << endl;
        break;
    default:
        wcout << L"Неверный выбор\n";
        break;
    }

    return 0;
}
