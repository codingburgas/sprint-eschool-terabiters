#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // За std::random_shuffle

using namespace std;

struct Question {
    string text;
    vector<string> options;
    int correctAnswer; // Индекс на верния отговор
    int weight; // Тегло на въпроса
};

class GeographyTest {
private:
    vector<Question> questions;

public:
    void addQuestion(const string& text, const vector<string>& options, int correctAnswer, int weight) {
        questions.push_back({ text, options, correctAnswer, weight });
    }

    void takeTest() {
        // Разбъркване на въпросите
        random_shuffle(questions.begin(), questions.end());

        int totalScore = 0;
        int totalWeight = 0;

        // Избиране на първите 20 въпроса
        for (int i = 0; i < 20 && i < questions.size(); i++) {
            const auto& question = questions[i];
            cout << question.text << endl;
            for (int j = 0; j < question.options.size(); j++) {
                cout << j + 1 << ". " << question.options[j] << endl;
            }
            int answer;
            cout << "Вашият отговор (номер): ";
            cin >> answer;

            if (answer - 1 == question.correctAnswer) {
                totalScore += question.weight;
            }
            totalWeight += question.weight;
        }

        double grade = (static_cast<double>(totalScore) / totalWeight) * 6; // Оценка по шестобалната система
        cout << "Вашата оценка: " << grade << endl;
    }
};

int main() {
    GeographyTest test;

    // Добавяне на въпроси по география
    test.addQuestion("Коя е най-голямата страна в света?", { "Русия", "Канада", "САЩ" }, 0, 2);
    test.addQuestion("Коя е столицата на Франция?", { "Берлин", "Париж", "Мадрид" }, 1, 1);
    test.addQuestion("Кой е най-високият връх в света?", { "Килиманджаро", "Еверест", "Аконкагуа" }, 1, 2);
    test.addQuestion("Коя река е най-дълга в света?", { "Нил", "Амазонка", "Мисисипи" }, 0, 2);
    test.addQuestion("Коя е столицата на България?", { "София", "Пловдив", "Варна" }, 0, 1);
    test.addQuestion("Коя е най-голямата пустиня в света?", { "Сахара", "Гоби", "Калахари" }, 0, 2);
    test.addQuestion("Коя страна е известна с кленовия си лист?", { "САЩ", "Канада", "Австралия" }, 1, 1);
    test.addQuestion("Коя е най-голямата океанска площ?", { "Тихи океан", "Атлантически океан", "Индийски океан" }, 0, 2);
    test.addQuestion("Коя е столицата на Япония?", { "Токио", "Сеул", "Пекин" }, 0, 1);
    test.addQuestion("Коя е най-високата сграда в света?", { "Бурж Халифа", "Емпайър Стейт Билдинг", "Шанхай Тауър" }, 0, 2);
    // Добавяне на още въпроси, за да достигнем минимум 50
    for (int i = 0; i < 40; i++) {
        test.addQuestion("Примерен въпрос " + to_string(i + 1), { "Отговор 1", "Отговор 2", "Отговор 3" }, 0, 1);
    }

    // Провеждане на теста
    test.takeTest();

}