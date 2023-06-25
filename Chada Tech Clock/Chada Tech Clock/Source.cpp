//Written by Nick Bernier 5/21/23

#include <iostream>
#include <string>
#include <stdlib.h>
//included <string> so that I could use the function to_string

using namespace std;

//declaration of main function
int main() {

	//integer used to exit while loop and end program
	int exitInt = 0;

	//declaration of time integers. integer values are not displayed string values are. integers are used for time calculations.
	int timeHours;
	string hoursMil;
	int timeMinutes;
	int timeSeconds;
	
	//declaration of string values for display on clock
	string hours;
	string minutes;
	string seconds;

	//declaration of the integer value that will control the clock functions
	int clockFunction;

	//asks user to enter an initial amount of hours and does not accept a value over 23 and under 0
	cout << "Please enter initial time hours." << endl;
	cin >> timeHours; 
	while (timeHours > 23 || timeHours < 0) {
		cout << "Invalid input. Please enter an integer between 0-23 for total hours." << endl;
		cin >> timeHours;
	}

	//asks user to enter an initial amount of minutes and does not accept a value over 59 and under 0
	cout << "Please enter initial time Minutes." << endl;
	cin >> timeMinutes;
	while (timeMinutes > 59 || timeMinutes < 0) {
		cout << "Invalid input. Please enter an integer between 0-59 for total minutes." << endl;
		cin >> timeMinutes;
	}

	//asks user to enter an initial amount of seconds and does not accept a value over 59 and under 0
	cout << "Please enter initial time Seconds." << endl;
	cin >> timeSeconds;
	while (timeSeconds > 59 || timeSeconds < 0) {
		cout << "Invalid input. Please enter an integer between 0-59 for total Seconds." << endl;
		cin >> timeSeconds;
	}

	//spacing
	cout << endl << endl;

	//while loop for clock begins
	while (exitInt == 0) {
		//sets string values for display equal to the integer time values
		hoursMil = to_string(timeHours);
		hours = to_string(timeHours);
		minutes = to_string(timeMinutes);
		seconds = to_string(timeSeconds);
		system("cls");
		
		//these if statements add a '0' to the string values if they are less than 10 
		if (timeHours < 10) {
			hours = "0" + to_string(timeHours);
			hoursMil = "0" + to_string(timeHours);
		}
		if (timeMinutes < 10) {
			minutes = "0" + to_string(timeMinutes);
			cout << minutes << endl;
		}
		if (timeSeconds < 10) {
			seconds = "0" + to_string(timeSeconds);
			cout << seconds << endl;
		}

		//displays clocks for when the hour value is exactly 12. This is here to switch the A M in the 12 hour clock to P M
		if (timeHours == 12) {
			cout << "**************************    **************************" << endl;
			cout << "*      12-Hour Clock     *    *      24-Hour Clock     *" << endl;
			cout << "*      " << hours << ":" << minutes << ":" << seconds << " P M      *    *        " << hoursMil << ":" << minutes << ":" << seconds << "        *" << endl;
			cout << "**************************    **************************" << endl;
		}
		//displays clocks for when the hour value is above 12 (P M)
		else if (timeHours > 12) {
			timeHours = timeHours - 12;
			hours = to_string(timeHours);
			if (timeHours < 10) {
				hours = "0" + to_string(timeHours);
			}
			cout << "**************************    **************************" << endl;
			cout << "*      12-Hour Clock     *    *      24-Hour Clock     *" << endl;
			cout << "*      " << hours << ":" << minutes << ":" << seconds << " P M      *    *        " << hoursMil << ":" << minutes << ":" << seconds << "        *" << endl;
			cout << "**************************    **************************" << endl;
			timeHours = timeHours + 12;
		}
		//displays clocks for when the hour value is exactly 0. This is here to switch the P M in the 12 hour clock to A M
		else if (timeHours == 0) {
			hours = to_string(timeHours);
			hours = "0" + to_string(timeHours);
			cout << "**************************    **************************" << endl;
			cout << "*      12-Hour Clock     *    *      24-Hour Clock     *" << endl;
			cout << "*      " << 12 << ":" << minutes << ":" << seconds << " A M      *    *        " << hoursMil << ":" << minutes << ":" << seconds << "        *" << endl;
			cout << "**************************    **************************" << endl;
		}
		//displays clocks for when the hour value is below 12 (A M)
		else {
			cout << "**************************    **************************" << endl;
			cout << "*      12-Hour Clock     *    *      24-Hour Clock     *" << endl;
			cout << "*      " << hours << ":" << minutes << ":" << seconds << " A M      *    *        " << hoursMil << ":" << minutes << ":" << seconds << "        *" << endl;
			cout << "**************************    **************************" << endl;
		}

		//spacing
		cout << endl << endl;

		//displays the functions of the program for the user.
		cout << "What would you like to do?" << endl << endl;;
		cout << "Options:" << endl;
		cout << "**************************" << endl;
		cout << "* 1 - Add One Hour       *" << endl;
		cout << "* 2 - Add One Minute     *" << endl;
		cout << "* 3 - Add One Second     *" << endl;
		cout << "* 4 - Exit Program       *" << endl;
		cout << "**************************" << endl;
		cin >> clockFunction;

		//will prompt the user to re enter a value if they do not selct 1, 2, 3, or 4.
		while (clockFunction != 1 && clockFunction != 2 && clockFunction != 3 && clockFunction != 4) {
			cout << "Invalid input. Please enter 1, 2, 3, or 4." << endl;
			cin >> clockFunction;
		}

		//If the user inputs 1 to add an hour. Rolls the hour value back to 0 if the value goes over 23
		if (clockFunction == 1) {
			timeHours = timeHours + 1;
			if (timeHours > 23) {
				timeHours = 0;
			}
		}

		//If the user inputs 2 to add a minute. Rolls the minute value back to 0 if the value goes over 59, and the hour value back to 0 if the value goes over 23.
		if (clockFunction == 2) {
			timeMinutes = timeMinutes + 1;
			if (timeMinutes > 59) {
				timeMinutes = 0;
				timeHours = timeHours + 1;
			}
		}

		//If the user inputs 3 to add a second. Rolls the second value back to 0 if the value goes over 59, then the minute value to 0 if it goes over 59, and then hour value back to 0 if the value goes over 23.
		if (clockFunction == 3) {
			timeSeconds = timeSeconds + 1;
			if (timeSeconds > 59) {
				timeSeconds = 0;
				timeMinutes = timeMinutes + 1;
			}
			if (timeMinutes > 59) {
				timeMinutes = 0;
				timeHours = timeHours + 1;
			}
			if (timeHours > 23) {
				timeHours = 0;
			}

		}

		//If the user inputs 4 the integer controlling the while loop is turned to 1. This exits the while loop and gives a goodbye message then ends the program.
		if (clockFunction == 4) {
			exitInt = 1;
			cout << "You have exited the program. Goodbye." << endl;
		}

	}
	return 0;
}