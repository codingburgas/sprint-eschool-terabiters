/*#include <iostream>
#include <string>


using namespace std;


string Question() {



	string addQurstion;
	string addQurstionAnswer[100];
	string YESorNO;
	int CorrectAnswersQuantity;


	cout << "First enter your question :" << endl;
	getline(cin, addQurstion);

	cout << "Do you want it to have multiple answers? Yes or No?" << endl;
	cin >> YESorNO;



	if (YESorNO == "Yes" || YESorNO == "yes" || YESorNO == "Y" || YESorNO == "y") {

		cout << "How many correct answers do you want it to have?" << "\n";
		cin >> CorrectAnswersQuantity;


		for (size_t i = 1; i <= CorrectAnswersQuantity; i++) {

			getline(cin, addQurstionAnswer[i]);
			cout << "Correct answer number " << i << " is:";
			cout << endl;
		}


	}
	else if (YESorNO == "No" || YESorNO == "no" || YESorNO == "N" || YESorNO == "n") {

		cout << "Ok, now enter you answer to the question:" << endl;
		getline(cin, addQurstionAnswer[1]);
		getline(cin, addQurstionAnswer[0]);

	}
	else { cout << "It seems you didn't typed that right" << "\n"; }






}*/
