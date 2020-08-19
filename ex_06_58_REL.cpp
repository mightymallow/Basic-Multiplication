/*
Gergely Sajdik A00976672
Assignment #3
Version 1.0
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class ex_06_58_REL {

public:
	// function implementation using loops to run correctly for multiplication solution
	void multiplication() { 
		srand(time(0)); // seeds rand() using the computer clock
		while (userAnswer != -1) { // runs while user doesn't input -1
			isAnswerCorrect = false;
			number1 = rand() % 10; // generates the value for the first number randomly from 0 to 9
			number2 = rand() % 10; // generates the value for the second number randomly from 0 to 9
			cout << "How much is " << number1 << " times " << number2 << " (-1 to End)? "; // asks user the question
			cin >> userAnswer;
			if (userAnswer != -1) { // checks for -1 input
				while (isAnswerCorrect == false) 
				if (userAnswer == (number1 * number2)) { // if user is correct then calls appropriate function
					correctMessage();
				}
				else if ((userAnswer != (number1 * number2)) && userAnswer != -1){
					incorrectMessage(); // if user is incorrect and does not enter -1 then calls appropriate function
				}
				else { // if user enters -1 after being incorrect
					isAnswerCorrect = true;
				}
			}
		}
		cout << "\nThat's all for now. Bye." << endl;
	}

	// takes random int and uses it to apply switch to randomly pick which message should be shown for correct answer
	void correctMessage() {
		isAnswerCorrect = true;
		unsigned int number3 = 1 + rand() % 4; // creates random int from 1 to 4
		switch (number3) {
		case 1: 
			cout << "Very good!" << endl << "\n";
			break;
		case 2:
			cout << "Excellent!" << endl << "\n";
			break;
		case 3:
			cout << "Nice work!" << endl << "\n";
			break;
		case 4:
			cout << "Keep up the good work!" << endl << "\n";
			break;
		}
	}

	// takes random int and uses it to apply switch to randomly pick which message should be shown for incorrect answer
	void incorrectMessage() {
		unsigned int number4 = 1 + rand() % 4; // creates random int from 1 to 4
		switch (number4) {
		case 1:
			cout << "No. Please try again." << endl;
			break;
		case 2:
			cout << "Wrong. Try once more." << endl;
			break;
		case 3:
			cout << "Don't give up!" << endl;
			break;
		case 4:
			cout << "No. Keep trying." << endl;
			break;
		}
		cout << "? ";
		cin >> userAnswer; // takes users next answer
	}

private:
	int number1 = 0; // field for first number to be multiplied
	int number2 = 0; // field for second number to be multiplied
	int total = 0; // total value of multiplication
	int userAnswer = 0; // user input answer
	bool isAnswerCorrect = false; // keeps track if answer has been found yet or not
};

// driver function
int main() {
	ex_06_58_REL starter; // create object to start
	cout << "Enter -1 to End." << endl; // intro message
	starter.multiplication(); // call multiplication function to start the loop
	system("pause");
}