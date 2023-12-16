#include <iostream>
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Ukrainian");
	float TF;	//Декларація змінної						// Begin 23
	cout << "Введіть температуру у Фаренгейтах: ";
	cin >> TF;

	cout << TF;

	float TC = ((TF - 32) * (5.0 / 9)); // Розрахунок
	cout << "Температура у Цельсіях = " << TC << endl; // Виведення

	int R1, R2;	//Декларація змінних					// Begin 10
	const float pi = 3.14; //Декларація сталої

	cout << "Введіть радіуси (Перший повинен бути більше за другий): ";
	cin >> R1 >> R2;

	float S1 = pi * (R1 * R1); // Розрахунок
	float S2 = pi * (R2 * R2); // Розрахунок

	float S3 = S1 - S2; // Розрахунок

	cout << "Площа першого кола = " << S1 << endl << "Площа другого кола = " << S2 << endl << "Площа третього кола = " << S3; // Виведення
}
