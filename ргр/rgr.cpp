#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void task1();
string Dec_To_S(int);

void task2();
void Dec_To_Six(int);

void task3();
void DecTo_N_(int);

void task4();
string AddBinary(string, string);


int main() {


	int choice = 0;

	while (choice != 5) {

		cout << "Choose task: "
			"\n1.Task1"
			"\n2.Task2"
			"\n3.Task3"
			"\n4.Task4"
			"\n5.Exit" << endl;

		cin >> choice;

		switch (choice) {
			case 1: {
				task1();		// Task of converting the number 131 from decimal to binary and hexadecimal
				break;
			}
			case 2: {
				task2();		// The task of converting the number 2358 from decimal to hexadecimal and binary
				break;
			}
			case 3: {
				task3();		// Conversion task from decimal to fourteen
				break;
			}
			case 4: {
				task4();		// Adding two numbers 131 and 2358 in binary
				break;
			}
			case 5: {
				cout << "Program is over!";
				break;
			}
			default: {
				cout << "Wrong one, try again";
			}
		}
	}
}

void task1() {
	int number = 131;
	cout << "number = " << number << endl;

	cout << "In decimal = " << number << " to binary = " << Dec_To_S(number) << endl;
	cout << "In decimal = " << number << " to hexadecimal = "; Dec_To_Six(number);
	
	cout << "\n";
}

string Dec_To_S(int n) {
	string binary;

	while (n > 0) {

		binary.push_back('0' + n % 2);
		n /= 2;
	}

	reverse(binary.begin(), binary.end());

	return binary;
}

void task2() {
	int number = 2358;

	cout << "Число = " << number << endl;

	cout << "In decimal =  " << number << " to binary = " << Dec_To_S(number) << endl;
	cout << "In decimal =  " << number << " to hexadecimal = ";Dec_To_Six(number);

	cout << "\n";
}
void Dec_To_Six(int n) {
	string binary;

	while (n > 0) {

		if (n % 16 < 10) {
			binary.push_back('0' + n % 16);
			n /= 16;
		}
		else if (n % 16 == 10) {
			binary.push_back('A' + n % 16 - 10);
			n /= 16;

		}
		else if (n % 16 == 11) {
			binary.push_back('B' + n % 16 - 11);
			n /= 16;
		}
		else if (n % 16 == 12) {
			binary.push_back('C' + n % 16 - 12);
			n /= 16;
		}
		else if (n % 16 == 13) {
			binary.push_back('D' + n % 16 - 13);
			n /= 16;
		}
		else if (n % 16 == 14) {
			binary.push_back('E' + n % 16 - 14);
			n /= 16;
		}
		else if (n % 16 == 15) {
			binary.push_back('F' + n % 16 - 15);
			n /= 16;
		}

	}

	reverse(binary.begin(), binary.end());

	cout << binary;
}

void task3() {
	int in;
	cout << "Enter a number: ";
	cin >> in;
	cout << "Changed number into binary: ";

	DecTo_N_(in);

	cout << endl;
}

void DecTo_N_(int n) {
	string binary;

while (n > 0) {

	if (n % 14 < 10) {
		binary.push_back('0' + n % 14);
		n /= 14;
	}
	else if (n % 14 == 10) {
		binary.push_back('A' + n % 14 - 10);
		n /= 12;

	}
	else if (n % 14 == 11) {
		binary.push_back('B' + n % 14 - 11);
		n /= 12;
	}
	else if (n % 14 == 12) {
		binary.push_back('C' + n % 14 - 12);
		n /= 16;
	}
	else if (n % 14 == 13) {
		binary.push_back('D' + n % 14 - 13);
		n /= 14;
	}

}

	reverse(binary.begin(), binary.end());

	cout << binary;
}

void task4() {
	int number1 = 131;
	int number2 = 2358;
	string sum = AddBinary(Dec_To_S(number1), Dec_To_S(number2));

	cout << "Sum of numbers: " << number1 << " and " << number2 << " to binary system " << sum << std::endl;
	
}

string AddBinary(string n, string m) {
	string result = ("");

	int i = n.length() - 1;
	int j = m.length() - 1;

	int save = 0;

	while (i >= 0 || j >= 0 || save == 1) {
		int sum = save;
		if (i >= 0)
			sum += n[i--] - '0';
		if (j >= 0)
			sum += m[j--] - '0';

		result = char(sum % 2 + '0') + result;
		save = sum / 2;
	}

	return result;
}
