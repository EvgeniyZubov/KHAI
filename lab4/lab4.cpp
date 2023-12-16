#include <iostream>
#include <locale.h>
#include <cmath>

using namespace std;

//Proc30 Boolean13 Integers27

void IsPalindrome();
int EnterValue(int& K);
void CheckPalindrome(int& K);

void Boolean13();
int EnterBool(int& A, int& B, int& C);
bool AOPositive(int A, int B, int C);

void Integers27();
int EnterInteger();
int Solving(int K);
void OutInteger(int week);


int main() {
	setlocale(LC_ALL, "Ukrainian");
	int choice = 0; //Декларування змінної задля choice

	cout << "Виберiть яку з цих задач будете вирiшувати: " << endl << 
		"1. IsPalindrome" << endl << 
		"2. Boolean13" << endl << 
		"3. Integers27" << endl;

	cin >> choice;

	switch (choice)
	{
		case 1:
		{
			// Proc 30
			IsPalindrome();
			break;
		}
		case 2:
		{
			// Boolean13
			Boolean13();
			break;
		}
		case 3:
		{
			// Integers27
			Integers27();
			break;
		}
		default:
		{
			cout << "Такого варiанту немає\n";
			break;
		}
	}
}

void IsPalindrome()
{
	int K1, K2, K3, K4, K5;

	if (EnterValue(K1))
	{
		CheckPalindrome(K1);
	}
	if (EnterValue(K2))
	{
		CheckPalindrome(K2);
	}
	if (EnterValue(K3))
	{
		CheckPalindrome(K3);
	}
	if (EnterValue(K4))
	{
		CheckPalindrome(K4);
	}
	if (EnterValue(K5))
	{
		CheckPalindrome(K5);
	}
}

int EnterValue(int& K) {
	cout << "Введіть К: ";
	cin >> K;
	if (cin && K > 0 && K < 1000) {
		return K;
	}
	else {
		cout << "K не є числом/більше за 1000/менше за 0, повернення 323 за змовчуванням" << endl;
		return K = 323;
	}
}

void CheckPalindrome(int& K) {
	int hundreds = K / 100;
	int tens = K % 100 / 10;
	int digits = K % 100 % 10;

	cout << "Сотни: " << hundreds << endl << "Десятки: " << tens << endl << "Единицы: " << digits << endl;

	bool IsPalindrome = hundreds == digits;
	
	cout << "Чи є число " << K << " паліндромом?: " << boolalpha << IsPalindrome << endl;
}

void Boolean13() 
{
	int A, B, C;

	if (EnterBool(A, B, C))
	{
		cout << "A = " << A << endl << "B = " << B << endl << "C = " << C << endl;
		cout << "Хоча б одне число є додатним: " << boolalpha << AOPositive(A,B,C);
	}

}

int EnterBool(int &A, int &B, int &C) {
	cout << "Введіть A: ";
	cin >> A;
	if (!cin) {
		A = 5;
	}
	else {
		A = A;
	}

	cout << "Введіть B: ";
	cin >> B;
	if (!cin) {
		B = 4;
	}
	else {
		B = B;
	}

	cout << "Введіть C: ";
	cin >> C;
	if (!cin) {
		C = 3;
	}
	else {
		C = C;
	}
	return 1;
}

bool AOPositive(int A, int B, int C) {
	return A > 0 || B > 0 || C > 0;
}

void Integers27() 
{
	int K = EnterInteger();
	int week = Solving(K);
	OutInteger(week);
}

int EnterInteger() {
	int K = 0;
	cout << "Введіть К: ";
	cin >> K;
	if (cin) {
		if (K > 0 && K < 366) {
			return K;
		}
	}
	else {
		cout << "Неправильно введено К, повернено 0 за замовчуванням";
		return K = 5;
	}
}

int Solving(int K) {
	int week = (K + 5)%7;
	return week;
}

void OutInteger(int week) {
	cout << "День тижня: " << week;
}
