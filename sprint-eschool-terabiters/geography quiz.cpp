#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
#include <algorithm> // For std::transform

using namespace std;

// Structure to hold a question and its answer
struct Question {
    string question;
    string answer;
};

// Function to calculate grade based on percentage
char calculateGrade(double percentage) {
    if (percentage >= 86) return '6';
    else if (percentage >= 85) return '5';
    else if (percentage >= 70) return '4';
    else if (percentage >= 60) return '3';
    else if (percentage >= 50) return '2';
    else return '1'; // Fail
}

// Function to convert string to lowercase
string toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

int main() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(0)));

    // List of 50 geography questions
    vector<Question> questions = {
        {"What is the capital of France?", "Paris"},
        {"What is the largest desert in the world?", "Sahara"},
        {"Which river is the longest in the world?", "Nile"},
        {"What is the capital of Japan?", "Tokyo"},
        {"Which country has the most population?", "China"},
        {"What is the smallest country in the world?", "Vatican"},
        {"Which continent is the largest?", "Asia"},
        {"What is the capital of Australia?", "Canberra"},
        {"Which ocean is the largest?", "Pacific"},
        {"What is the capital of Canada?", "Ottawa"},
        {"Which country is known as the Land of the Rising Sun?", "Japan"},
        {"What is the capital of Germany?", "Berlin"},
        {"Which mountain is the tallest in the world?", "Everest"},
        {"What is the capital of Italy?", "Rome"},
        {"Which country is famous for its pyramids?", "Egypt"},
        {"What is the capital of Brazil?", "Brasilia"},
        {"Which country is known for the Great Wall?", "China"},
        {"What is the capital of Russia?", "Moscow"},
        {"Which country is known for its maple syrup?", "Canada"},
        {"What is the capital of India?", "New Delhi"},
        {"Which country is known for its kangaroos?", "Australia"},
        {"What is the capital of Spain?", "Madrid"},
        {"Which country is known for its tulips?", "Netherlands"},
        {"What is the capital of South Korea?", "Seoul"},
        {"Which country is known for its fjords?", "Norway"},
        {"What is the capital of Mexico?", "Mexico City"},
        {"Which country is known for its sushi?", "Japan"},
        {"What is the capital of Argentina?", "Buenos Aires"},
        {"Which country is known for its Alps?", "Switzerland"},
        {"What is the capital of Egypt?", "Cairo"},
        {"Which country is known for its tea?", "India"},
        {"What is the capital of Greece?", "Athens"},
        {"Which country is known for its chocolate?", "Belgium"},
        {"What is the capital of Portugal?", "Lisbon"},
        {"Which country is known for its castles?", "Scotland"},
        {"What is the capital of Turkey?", "Ankara"},
        {"Which country is known for its samba dance?", "Brazil"},
        {"What is the capital of Sweden?", "Stockholm"},
        {"Which country is known for its wine?", "France"},
        {"What is the capital of South Africa?", "Pretoria"},
        {"Which country is known for its volcanoes?", "Iceland"},
        {"What is the capital of Thailand?", "Bangkok"},
        {"Which country is known for its beer?", "Germany"},
        {"What is the capital of Kenya?", "Nairobi"},
        {"Which country is known for its diamonds?", "South Africa"},
        {"What is the capital of Saudi Arabia?", "Riyadh"},
        {"Which country is known for its olive oil?", "Italy"},
        {"What is the capital of New Zealand?", "Wellington"},
        {"Which country is known for its rugby?", "New Zealand"}
    };

    // Shuffle and select 20 random questions
    vector<Question> selectedQuestions;
    map<int, bool> usedIndexes;
    while (selectedQuestions.size() < 20) {
        int index = rand() % 50;
        if (usedIndexes.find(index) == usedIndexes.end()) {
            selectedQuestions.push_back(questions[index]);
            usedIndexes[index] = true;
        }
    }

    // Quiz logic
    int correctAnswers = 0;
    string userAnswer;

    cout << "Welcome to the Geography Quiz! Answer the following questions:\n\n";

    for (int i = 0; i < selectedQuestions.size(); i++) {
        cout << "Q" << i + 1 << ": " << selectedQuestions[i].question << endl;
        cout << "Your answer: ";
        cin >> userAnswer;

        // Check if the answer is correct (case insensitive)
        if (toLower(userAnswer) == toLower(selectedQuestions[i].answer)) {
            correctAnswers++;
        }
        cout << endl; // Add a new line for better readability
    }

    // Calculate percentage and gradec

    double percentage = (correctAnswers / 20.0) * 100;
    char grade = calculateGrade(percentage);

    // Display results
    cout << "\nQuiz Completed!\n";
    cout << "You answered " << correctAnswers << " out of 20 questions correctly.\n";
    cout << "Your score: " << percentage << "%\n";
    cout << "Your grade: " << grade << endl;

}
