#include <iostream>
#include <locale.h>
#include <cmath>

using namespace std;

void geo32(); //Декларування функції типу void(задача geo32)

void SumOfSeries24();//Декларування функції типу void(задача Solve24)
double factorial(int temp);

void SumOfSeries34();//Декларування функції типу void(задача Solve32)

int main()
{
	int choice = 0; //Декларування змінної задля choice

	while (choice != 4) {
		setlocale(LC_ALL, "ukrainian");
		cout.clear();
		cout << "Виберiть яку з цих задач будете вирiшувати: "
			"\n1. Geometry#32"
			"\n2. Solve26.1"
			"\n3. Solve34.2"
			"\n4. Вийти з програми" << endl;


		std::cin >> choice;

		switch (choice)
		{
		case 1:
		{
			// Geo32
			geo32();
			break;
		}
		case 2:
		{
			// Solve24
			SumOfSeries24();
			break;
		}
		case 3:
		{
			// Solve32
			SumOfSeries34();
			break;
		}
		case 4:
		{
			cout << "Програма завершена";
			break;
		}
		default:
		{
			cout << "Такого варiанту немає\n";
			break;
		}
		}
	}
}

void geo32() { // Функція типу void, що не повертає значень
	float x, y, r; // Декларування змінних типу float
	bool ar1, ar2; // Декларування змінних типу bool
	int n, count = 0;

	cout << "Кількість разів: ";
	cin >> n;

	cout << "Уведiть радiус кола: ";
	std::cin >> r;

	for (int i = 1; i <= n; i++)
	{

		if (r > 0)
		{
			cout << "Уведiть точку за кординатою х : ";
			cin >> x;
			cout << "Уведiть точку за кординатою y : ";
			cin >> y;


			ar1 = pow((x - r * 3 / 4), 2) + pow((y - r * 2 / 3), 2) < pow(r, 2) && y < -x + 2 * r * 3 / 4 && y < x && y > 0; //Рівняння першої фігури(верхньої)
			ar2 = pow((x - r * (3.0 / 4)), 2) + pow((y - r * (2.0/ 3)), 2) > pow(r, 2) && y > 0 && x < 0 && y < 2 * r && y < x + 2 * r * 2 / 3; //Рівняння другої фігури(нижньої)

			if (ar1 || ar2) {
				count++;
				cout << "In" << endl;
			}
			else {

			}

		}
		else {
			cout << "Радіус не може бути від'ємним" << endl;
		}
	}
	cout << "Лічильник : " << count << " з " << n << endl;
}

void SumOfSeries24()
{
	int k = 0, n;
	const double pi = 3.14;
	double x;

	cout << "Введіть х: ";
	cin >> x;

	cout << "Обмеження n: ";
	cin >> n;


	double sum = 0;


	if (!cin || n < 0)
	{
		cout << "Неправильне введення даних" << endl;
	}
	else
	{
		for (k; k <= n; k++)
		{
			int temp = 1 + (2 * k);
			int count = 0;

			double part1 = pow(-1, k) * pow((-1 * pi / 2.0 + sqrt(x)), temp);
			double part2 = factorial(temp);

			double solving = pow((-1.0 * (part1 / part2)), x);

			sum += solving;
			solving = 0;

			count = k % 3;

			if (count == 2) {
				cout << "Сума ряду: " << sum << endl;
			}
		}
	}
}

double factorial(int temp)
{
	int equals = 1;
	for (int i = 1; i <= temp; i++)
	{
		equals *= i;
	}
	return equals;
}

void SumOfSeries34()
{
	int k = 0;
	const double pi = 3.14;
	double x, g = 1E+7;


	cout << "Введіть х: ";
	cin >> x;

	double sum = 0;

	do
	{
		k++;
		int count = 0;

		double part1 = pow(x, 3 * k);
		double part2 = factorial(2 * k + 1);

		double solving = part1 / part2;

		sum += solving;
		solving = 0;

		count = k % 3;

		if (count == 2) {
			cout << "Сума ряду: " << sum << endl;
		}
	} while (sum < g);
}
