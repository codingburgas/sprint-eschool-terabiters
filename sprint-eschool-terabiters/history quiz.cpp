#include <iostream>
#include <vector>
#include <string>
#include <algorithm> //  std::random_shuffle

using namespace std;

struct Question {
    string text;
    vector<string> options;
    int correctAnswer; // Индекс на верния отговор
    int weight; // Тегло на въпроса
};

class GeographyTest {
private:// ограничава достъпа само до методите на същия клас
    vector<Question> questions;

public:// позволява достъп до променливи от всяка друга част на програмата
    void addQuestion(const string& text, const vector<string>& options, int correctAnswer, int weight) {
        questions.push_back({ text, options, correctAnswer, weight });
    }

    void takeTest() {
        random_shuffle(questions.begin(), questions.end());

        int totalScore = 0;
        int totalWeight = 0;

        for (int i = 0; i < 20 && i < questions.size(); i++) {
            const auto& question = questions[i];
            cout << question.text << endl;
            for (int j = 0; j < question.options.size(); j++) {
                cout << j + 1 << ". " << question.options[j] << endl;
            }
            int answer;
            cout << "Вашият отговор (номер): ";
            cin >> answer;
            
            
            if (answer < 1 || answer > 5) {
                cout << "Невалиден номер." << endl;
                continue; 
            }


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

   
    test.addQuestion("Кой е основателят на Рим?", { "Ромул", "Нумитор", "Титус" }, 0, 2);
    test.addQuestion("Коя година е започнала Втората световна война?", { "1939", "1941", "1945" }, 0, 2);
    test.addQuestion("Кой е известен с фразата 'Дайте ми свобода или дайте ми смърт'?", { "Джордж Вашингтон", "Патрик Хенри", "Томас Джеферсън" }, 1, 2);
    test.addQuestion("Кой е бил първият президент на САЩ?", { "Джордж Вашингтон", "Томас Джеферсън", "Авраам Линкълн" }, 0, 2);
    test.addQuestion("Коя е известната битка, проведена през 1066 г.?", { "Битката при Хастингс", "Битката при Тевтобург", "Битката при Ватерло" }, 0, 2);
    test.addQuestion("Кой е написал 'Декларацията за независимост'?", { "Джордж Вашингтон", "Томас Джеферсън", "Бенджамин Франклин" }, 1, 2);
    test.addQuestion("Коя империя е известна с 'Пътя на коприната'?", { "Римската империя", "Османската империя", "Монголската империя" }, 2, 2);
    test.addQuestion("Кой е известният фараон, построил пирамидите в Гиза?", { "Рамзес II", "Хеопс", "Тутанкамон" }, 1, 2);
    test.addQuestion("Коя е годината на падането на Берлинската стена?", { "1987", "1989", "1991" }, 1, 2);
    test.addQuestion("Кой е основателят на Османската империя?", { "Осман I", "Сулейман I", "Мехмед II" }, 0, 2);
    

    test.takeTest();

}