#include <iostream>
#include <cstdarg>
using namespace std;

int maxWordLength(const char* sentence, ...) { //функция для вычисления количества букв в длинном слове
    va_list args; //создание списка аргументов переменной длины
    va_start(args, sentence); //инициализация va_list, начальное положение для доступа к аргументам

    int max_length = 0;
    const char* word;

    while ((word = va_arg(args, const char*)) != NULL) { //получение аргумента для условия проверки
        int length = strlen(word);
        if (length > max_length) { //нахождение максимальной длины слова
            max_length = length;
        }
    }

    va_end(args); //завершение работы со списком аргументов

    return max_length;
}

int main() {

    setlocale(LC_ALL, "rus");

    const char* sentence1 = "привет как у тебя дела";
    const char* sentence2 = "очень короткое предложение";
    const char* sentence3 = "сегодня вторник";

    cout << "1 предложение: привет как у тебя дела" << endl;
    cout << "2 предложение: очень короткое предложение" << endl;
    cout << "3 предложение: сегодня вторник" << endl;

    cout << "Самое длинное слово в первом предложении: " << maxWordLength("привет", "как", "у", "тебя", "дела", NULL) << std::endl; //первый вызов функции
    cout << "Самое длинное слово во втором предложении: " << maxWordLength("очень", "короткое", "предложение", NULL) << std::endl; //второй вызов функции
    cout << "Самое длинное слово в третьем предложении: " << maxWordLength("сегодня", "вторник", NULL) << std::endl; //третий вызов функции

    return 0;
}
