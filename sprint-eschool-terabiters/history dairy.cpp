#include <iostream>
#include <string>

using namespace std;

const int MAX_EVENTS = 10; // Максимален брой събития

struct HistoricalEvent {
    string title, date, description;
};

class HistorySchool {
    HistoricalEvent events[MAX_EVENTS];
    int count = 0;

public://public позволява на членовете на клас (като функции и променливи) да бъдат достъпвани от външната страна на класа, което ги прави налични за използване от други части на програмата.
    void addEvent() {
        if (count < MAX_EVENTS) {
            cout << "Заглавие: "; getline(cin, events[count].title);
            cout << "Дата: "; getline(cin, events[count].date);
            cout << "Описание: "; getline(cin, events[count].description);
            count++;
            cout << "Събитието е добавено!" << endl;
        }
        else {
            cout << "Достигнат е максималният брой събития!" << endl;
        }
    }

    void displayEvents() {
        for (int i = 0; i < count; i++) {
            cout << "Заглавие: " << events[i].title << ", Дата: " << events[i].date << ", Описание: " << events[i].description << endl;
        }
    }

    void searchEvent(const string& title) {
        for (int i = 0; i < count; i++) {
            if (events[i].title == title) {
                cout << "Намерено: " << events[i].title << ", " << events[i].date << ", " << events[i].description << endl;
                return;
            }
        }
        cout << "Не е намерено събитие с такова заглавие." << endl;
    }
};

int main() {
    HistorySchool school;
    int choice;
    do {
        cout << "1. Добави събитие\n2. Покажи събития\n3. Търси събитие\n4. Изход\nИзберете опция: ";
        cin >> choice; cin.ignore();
        if (choice == 1) school.addEvent();
        else if (choice == 2) school.displayEvents();
        else if (choice == 3) {
            string title; cout << "Въведете заглавие: "; getline(cin, title);
            school.searchEvent(title);
        }
    } while (choice != 4);
    return 0;
}

