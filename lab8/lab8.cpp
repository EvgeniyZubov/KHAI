#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>

/*Array104.Дан масив розміру N і два цілих числа K і M(1 ≤ K ≤ N, 1 ≤ M ≤ 10).
Перед елементом масиву з номером K вставити M нових елементів з нульовими
значеннями.*/

/*Matrix27. Дана матриця розміру M × N. Знайти максимальний серед мінімальних
елементів її рядків.*/

/*Sort#8 Вибір Зменшення Дійсний*/

#define N 20
#define F 100

using namespace std;

void array104();
void fillArr(int*& arr, int lenght);
void get_nums(int size, int array[N]);
bool checkfiles(string in, string out);
void addNewInt(int*& arr, int n, string output, int K, int M);


void matrix27();
bool checkfile(string in);
void fillArray(string f_in, int**& arr, const int rows, const int cols);
void searchLowest(int** arr, const int rows, const int columns, string f_out);

void sort8();
void choiceSort(float arr[N], int n, string in);

int main() {
	srand(time(NULL));

	int choice = 0;

	while (choice != 4) {

		cout << "Choose the task! : "
			"\n1.Array#104"
			"\n2.Matrix#27"
			"\n3.Sort#8"
			"\n4.Exit" << endl;

		cin >> choice;

		switch (choice) {
		case 1: {
			array104();		//Задание array104
			break;
		}
		case 2: {
			matrix27();		// Задание matrix27
			break;
		}
		case 3: {
			sort8();		// Задание sort8
			break;
		}
		case 4: {
			cout << "Program is end!";
			break;
		}
		default: {
			cout << "Wrong one, try again";
		}
		}
	}
}

// Задание Array104

void array104() {

	int n = 0, startPos = 0, size = 0;
	int mas[N];

	get_nums(size, mas);
}


void get_nums(int size, int array[N]) {

	string filename_in = "array_in_104.txt";
	string filename_out = "array_out_104.txt";

	int startPos = 0;

	ifstream f;

	if (checkfiles(filename_in, filename_out)) {
		
		f.open(filename_in);

		string lenght;

		getline(f, lenght);
		int size = stoi(lenght);

		int* arr = new int(size);

		fillArr(arr, size);

		getline(f, lenght);

		int index = stoi(lenght);

		getline(f, lenght);

		int amountOfM = stoi(lenght);

		cout << "Index = " << index << "\n M = " << amountOfM;

		for (int i = 0; i < size; i++) {
			cout << "arr[" << i << "] = " << arr[i] << endl;
		}

		addNewInt(arr, size, filename_out, index, amountOfM);

	}
	else {
		cout << "Помилка, файл не знайдено";
	}
}

void fillArr(int*& arr, int lenght) {
	for (int i = 0; i < lenght; i++) {
		arr[i] = rand() % 20;
	}
}

bool checkfiles(string in, string out) {

	ifstream f_in;
	ifstream f_out;

	f_in.open(in);
	f_out.open(out);

	if (!f_in.is_open() || !f_out.is_open()) {
		f_in.close();
		f_out.close();
		return 0;
	}
	else if (f_in.is_open() && f_out.is_open()) {
		return 1;
	}
	else {
		return 0;
	}
}

void addNewInt(int*& arr, int n, string filename_out, int K, int M) {

	cout << "loh";

	int save = n + M;

	int* temp = new int(save);

	for (int i = 0; i < K; i++) {
		temp[i] = arr[i];
	}

	for (int i = K; i < K + M+1; i++) {
		temp[i] = 0;
	}

	for (int i = K+M; i < M+n; i++) {
		temp[i] = arr[i-M];
		K++;
	}

	cout << "New Array\n";

	for (int i = 0; i < save; i++) {
		cout << "Arr[" << i << "] = " << temp[i] << endl;
	}

	ofstream outp(filename_out);
	if (!outp)
	{
		cerr << "Неможливо вiдкрити файл!" << endl;
		exit(1);
	}
	else {
		outp << "Новий масив: " << endl;
		for (int i = 0; i < save; i++) {
			outp << temp[i] << " ";
		}
	}
}
// Конец Array104

// Задание Matrix27

void matrix27() {
	int n = 0, startPos = 0, rows = 0, cols = 0, skip = 0;
	string filename;

	string filename_in = "matrix_in_27.txt";


	ifstream f;

	if (checkfile(filename_in)) {
		f.open(filename_in);

		string size;

		getline(f, size);

		for (int i = 0; i < size.size(); i++) {
			if (size[i] == ' ') {
				skip = i;
			}
		}
		rows = stoi(size);
		if (rows > 20) {
			cout << "Рядків не може бути більше за 20" << endl;
			exit(0);
		}
		else {
			for (int i = 0; i < size.size() - skip; i++) {
				size[i] = size[skip + i];
				size[skip + i] = 0;
			}

			cols = stoi(size);
			if (cols > 20) {
				cout << "Колон не може бути більше за 20" << endl;
				exit(0);
			}
			else {
				cout << "ROWS = " << rows << endl << "COLS = " << cols << endl;
				int** arr = new int* [rows];
				for (int i = 0; i < rows; i++) {
					arr[i] = new int[cols];
				}
				fillArray(filename_in, arr, rows, cols);
				searchLowest(arr, rows, cols, filename_in);
			}
		}
	}
	else {
		cout << "Помилка, файл не знайдено";
	}
}

void fillArray(string f_in, int**& arr, const int rows, const int cols) {
	string out;
	float num = 0;
	int numRows = 0, numCols = 0;

	ifstream f;

	istringstream iss(out);
	f.open(f_in);

	std::getline(f, out);

	while (getline(f, out) && numRows < rows) {
		istringstream iss(out);
		numCols = 0;

		while (iss >> num && numCols < cols) {
			arr[numRows][numCols] = num;
			numCols++;
		}
		numRows++;
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

bool checkfile(string in) {

	ifstream f_in;
	f_in.open(in);

	if (f_in.is_open()) {
		return 1;
	}
	else {
		return 0;
	}
}

void searchLowest(int** arr, const int rows, const int columns, string f_out) {
	int* lowest = new int[rows];
	int min = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (arr[i][j] > min) {
				lowest[i] = arr[i][j];
			}
		}
	}

	ofstream outp;
	outp.open(f_out, ios::app);

	if (!outp)
	{
		cerr << "Неможливо вiдкрити файл!" << std::endl;
		exit(1);
	}
	else {
		for (int i = 0; i < rows; i++) {
			outp << "\nRow #" << i << " equals " << lowest[i] << " ";
		}
	}
}

// Задание Sort8

void sort8() {
	const int M = 20;

	float arr[M];
	string filename;

	string filename_in = "sort_in_8.txt";

	ifstream f;
	istringstream iss(filename_in);

	int count = 0;

	if (checkfile(filename_in)) {
		f.open(filename_in);

		while (count < M && f >> arr[count]) {
			count++;
		}

		for (int i = 0; i < count; i++) {
			cout << arr[i] << " ";
		}

		choiceSort(arr, count, filename_in);
	}
	else {
		cout << "Помилка, файл не знайдено";
	}
}

void choiceSort(float arr[N], int n, string f_in)
{

	for (int i = 0; i < n - 1; ++i) {
		int minIndex = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] > arr[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			std::swap(arr[i], arr[minIndex]);
		}
	}

	ofstream outp;
	outp.open(f_in, ios::app);

	if (!outp)
	{
		cerr << "Неможливо вiдкрити файл!" << std::endl;
		exit(1);
	}
	else {
		outp << "\n";
		for (int i = 0; i < n; i++) {
			outp << arr[i] << " ";
		}
	}
}

// Конец Sort8

// Конец
