#include <iostream>
#include <locale.h>
#include <cmath>

using namespace std;

//integer 7 Boolean 13 Solve21

int main() {
	setlocale(LC_ALL, "Ukrainian");
	// Integer 7
	int A1; // Декларація змінної
	cout << "Введіть двозначне число: ";
	cin >> A1; // Введення значення
	int temp2 = A1 % 10; // Розрахунок
	int temp = A1 / 10; // Розрахунок

	int sum = temp + temp2; // Розрахунок
	int mlt = temp * temp2; // Розрахунок

	cout << "Сума двох чисел = " << sum << endl; // Виведення відповіді
	cout << "Добуток двох чисел = " << mlt << endl; // Виведення відповіді 

	//Boolean 13
	int A, B, C; // Декларація змінних
	bool Positive; // Декларація змінної типу bool
	cout << "Введіть числа А, B, C: ";
	cin >> A >> B >> C; // Введення значення

	Positive = A > 0 || B > 0 || C > 0; // Розрахунок

	cout << "Хоча б одне з чисел додатнє: " << boolalpha << Positive << endl; // Виведення відповіді

	// Solve 21

	int x; // Декларація змінної
	const float pi = 3.14; // Декларація сталої

	cout << "Введіть х: ";
	cin >> x; // Введення значення
	 
	float rtod = (x * 180) / pi; // Розрахунок

	float up = pow(fabs(pow(x, 2) - 2) * sin(rtod) * fabs(3 * tan(rtod)) * pow(5, cos(rtod - 12)), 1.0 / 3); // Розрахунок
	float down = 0.6 + 4 * (log(x+15) / log(2)); // Розрахунок
	float y = up / down; // Розрахунок
	
	cout << "y = " << y; // Виведення відповіді
}
