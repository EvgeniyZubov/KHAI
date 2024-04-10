#include <iostream>
#define M 20 
#define N 20

using namespace std;

void matrix27();
void expandSize(const int rows, const int columns, int**& arr);
void enterNums(int**&, const int, const int);
void searchLowest(int**, const int, const int);
void printm(int rows, int cols, int** a);


void matrix63();
void deleteRow(int**& arr, int& rows, int& cols, const int temp);
int findLowest(int**&, const int, const int);

int main() {
	int choice = 0;

	while (choice != 3) {

		cout << "Choose the task: "
			"\n1.Matrix#27"
			"\n2.Matrix#63"
			"\n3.Exit" << endl;

		cin >> choice;

		switch (choice) {
		case 1: {
			matrix27();
			break;
		}
		case 2: {
			matrix63();
			break;
		}
		case 3: {
			cout << "Program is over!";
			break;
		}
		default: {
			cout << "Wrong one, try again!";
		}
		}
	}
}

void matrix27() { /*Дана матриця розміру M × N. Знайти максимальний серед мінімальних
					елементів її рядків. MATRIX #27*/
	int rows, columns;

	int** arr;

	cout << "Enter rows: ";
	cin >> rows;

	cout << "Enter a columns: ";
	cin >> columns;


	expandSize(rows, columns,arr);
	enterNums(arr, rows, columns);
	printm(rows, columns, arr);

	searchLowest(arr, rows, columns);
}

void expandSize(const int rows, const int columns, int**&arr) {
	arr = new int* [rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[columns];
	}
}

void enterNums(int** &arr, const int rows, const int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "Enter num for arr[" << i << "][" << j << "]: ";
			cin >> arr[i][j];
		}
	}
}

void printm(int rows, int cols, int** a)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			std::cout << a[i][j] << " ";
		std::cout << std::endl;
	}
}

void searchLowest(int** arr, const int rows, const int columns) {
	int* lowest = new int[rows];
	int min = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (arr[i][j] > min) {
				lowest[i] = arr[i][j];
			}
		}
	}

	for (int i = 0; i < rows; i++) {
		cout <<"Row #" << i << " equals " << lowest[i] << "\n";
	}
}


void matrix63() { /*Matrix63. Дана матриця розміру M × N. Видалити рядок, що містить мінімальний
елемент матриці.*/
	int** arr;
	int rows, cols;

	cout << "Enter rows: ";
	cin >> rows;
	cout << "Enter columns: ";
	cin >> cols;

	expandSize(rows, cols, arr);
	enterNums(arr, rows, cols);
	printm(rows, cols, arr);


	int temp = findLowest(arr, rows, cols);
	deleteRow(arr, rows, cols, temp);

	printm(rows, cols, arr);

}

int findLowest(int**& arr, const int rows, const int cols) {
	int MAX = 3E+5;
	int temp = 0;
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (arr[i][j] < MAX) {
				MAX = arr[i][j];
				temp = i;
			}
		}
	}

	cout << "Min num = " << MAX << endl;

	return temp;
}

void deleteRow(int**& arr, int& rows, int& cols, const int bump) {
	int** temp = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++) {
		temp[i] = new int[cols];
	}
	
	for (int i = bump; i < rows-1; i++) {
		for (int j = 0; j < cols; j++){
			arr[i][j] = arr[i + 1][j];
		}
	}

	for (int i = 0; i < rows - 1; i++) {
		for (int j = 0; j < cols; j++) {
			temp[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}

	delete[] arr;
	rows--;
	arr = temp;


}
